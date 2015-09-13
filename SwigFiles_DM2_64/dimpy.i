%module DimPy
%feature("autodoc", "1");
%include "typemaps.i"
%{
#define _GATANPLUGIN_USES_LIBRARY_VERSION 2
//we define _GATAN_USE_STL_STRING to add some functions for converting to std::string which we can then convert to char*
//doesn't seem to work though
#define _GATAN_USE_STL_STRING
#include "DMPlugInBasic.h"

using namespace Gatan;
//we make the default flags include the new buffer object flag:

#if PY_VERSION_HEX < 0x03000000
#undef Py_TPFLAGS_DEFAULT 
//mfm 19Mar12 The flags really indicate a field is present, there's no promise there's an implementation
//as such we can add flags globally and only implement the fields as appropriate (I think). So we
//annd Py_TPFLAGS_HAVE_NEWBUFFER, which images use, and Py_TPFLAGS_HAVE_ITER, so that taggroups can return 
//their keys (this is the default dictionary behaviour)
#define Py_TPFLAGS_DEFAULT (Py_TPFLAGS_DEFAULT_EXTERNAL|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_ITER) 
#endif
%}

//lets try adding some methods for accessing the image buffer
//changed to builtin. If we override the python slot for the methods in http://docs.python.org/c-api/typeobj.html
//then our object will act like it has that property. We want to specify a function returning PyBufferProcs 
//for the tp_as_buffer member
//eg from swig docs:
//%feature("python:slot", "tp_hash", functype="hashfunc") Cheese::cheeseHashFunc;
//note tp_hash is defined in the _typeobject struct, and hashfunc is defined in the same file (object.h)
//so the functions we're interested in are:
//PyBufferProcs *tp_as_buffer;
//although maybe we don't need to make the PyBufferProcs, as we must already have one, and we can
//just override the functions in PyBufferProcs that we need? So maybe this:
%feature("python:slot", "tp_hash", functype="hashfunc") Gatan::DM::Image::cheeseHashFunc;
//we need tp_flags too but we can't set this, see python.cxx in SWIG it's hardcoded
//let's edit the created file then...
//%feature("python:slot", "tp_flags") 27; 

%extend Gatan::DM::Image {
int dims() { return self->GetNumDimensions(); }
long cheeseHashFunc () const { return 3; }
}
//mfm 19Mar12 we create a new taggroup iterator class that holds a taggroup and int
//we need both c++ and python code for it, so we inline
//we need the features added first though
//we create a taggroup iterator C class and add special functions to it
%feature("python:tp_iter") TagGroupIterator "self_tp_iter";
%feature("python:tp_iternext") TagGroupIterator "TagGroupIterator_tp_iternext";

%inline %{
class TagGroupIterator
{
public:
	Gatan::DM::TagGroup tg;
	Py_ssize_t pos;
};
%}

//mfm 21Feb12 we have two ways to use %feature, and the static way looks nicer to me. 
//we need a static function that we call for a specific class:

%{
int PythonGatanDMImage_bf_getbuffer(PyObject *pyobj, Py_buffer *view, int flags)
{
  //need to convert obj into a Gatan::DM::Image pointer
  void *argp; 
  int res; 
   res = SWIG_ConvertPtr(pyobj, &argp, SWIGTYPE_p_Gatan__DM__Image, 0); 
  if (!SWIG_IsOK(res)) { 
    SWIG_Error(SWIG_ArgError(res), "in method 'Gatan__DM__Image::__getbuffer__', argument 1 of type 'Gatan__DM__Image *'"); 
    return SWIG_ERROR; 
    } 

  //GetDataType() returns an int, 
  //1=short, 10 = ushort, 
  //9=byte, 6=ubyte, 
  //7=long, 11=ulong
  //14=binary (byte)
  //2=float, 12=double
  //3=float,float 13 = double, double
  //23=RGB (byte, byte, byte)

  Gatan::DM::Image *self = reinterpret_cast<Gatan::DM::Image*>(argp); 
  GatanPlugIn::ImageDataLocker* idl = new GatanPlugIn::ImageDataLocker(*self);
  int dt = self->GetDataType();
  view->format = dt==1 ? "h" : dt==10 ? "H" ://short, ushort
                  dt==9 ? "b" : dt==6 ? "B" ://byte, ubyte
                  dt==7 ? "i" : dt==11 ? "I" ://long, ulong
                  dt==2 ? "f" : dt==12 ? "d" ://float, double
                  dt==14 ? "B" :  //binary
                  dt==23 ? "BBB" : //RGB
                  dt==3 ? "ff" : dt==13 ? "dd" ://complexf, complexd
		  NULL; //unknown
  view->obj = pyobj;
  Py_INCREF(pyobj);
  view->buf = idl->get();
  view->readonly = 0;
  view->itemsize = self->GetDataElementByteSize();
  view->ndim = self->GetNumDimensions();
  
  view->shape = new Py_ssize_t [view->ndim];
  view->strides = new Py_ssize_t [view->ndim];
  int px=1;
  // The last index is the fast one (ie stride=view->itemsize)

  for(int i=0; i<view->ndim; i++)
  {
	// i is the 'DM' index (0=x, 1=y, 2=z(? - check - how is nd data stored??))
	// py_index is python index (0=y, 1=x)
	int py_index = view->ndim - 1 - i;
    view->shape[py_index] = self->GetDimensionSize(i);
    view->strides[py_index] = px*view->itemsize;
	// for the next dimension, our stride is longer by the size of
	// the dimension we just added
    px*= view->shape[py_index];
  }
  view->len = px;
  view->suboffsets = NULL;
  view->internal = idl;
  return 0; //success(?) //0 is returned on success and -1 on error.
}

int PythonGatanDMImage_bf_releasebuffer(PyObject *pyobj, Py_buffer *view)
{
  //we must destroy what we made in get buffer
  if(view->shape)
    delete[] view->shape;
  if(view->strides)
    delete[] view->strides;
  //and we're done with our datalocker too
  if(view->internal)
  {
    GatanPlugIn::ImageDataLocker* idl = (GatanPlugIn::ImageDataLocker*) view->internal;
    if(!view->readonly)
      idl->MarkDataChanged(); //may have
    delete idl;
  }
  //I'm not sure we should DECREF here?
  //if(view->obj)
  //  Py_DECREF(pyobj);

  return 0;
}

Py_ssize_t PythonTagGroup_mp_length(PyObject *self)
{
  //need to convert obj into a Gatan::DM::TagGroup pointer
  void *argp; 
  int res; 
   res = SWIG_ConvertPtr(self, &argp, SWIGTYPE_p_Gatan__DM__TagGroup, 0); 
  if (!SWIG_IsOK(res)) { 
    SWIG_Error(SWIG_ArgError(res), "in method 'TagGroup::__length__', argument 1 of type 'TagGroup *'"); 
    return 0; 
    } 
  Gatan::DM::TagGroup *tg = reinterpret_cast<Gatan::DM::TagGroup*>(argp);
  return tg->CountTags();
}

PyObject* PythonTagGroup_mp_subscript(PyObject *self, PyObject *key)
{
	//note that some of the swig functions use self in a macro, so we need to be careful about naming if using them
	//might be easier to not use them?
	PyObject *resultobj = 0;
	Gatan::DM::TagGroup ret; 
	Gatan::DM::String str;
  //need to convert o into a Gatan::DM::Image pointer
  //and key should be a string
  void *argp; 
  int res; 
   res = SWIG_ConvertPtr(self, &argp, SWIGTYPE_p_Gatan__DM__TagGroup, 0); 
  if (!SWIG_IsOK(res)) { 
    SWIG_exception_fail(SWIG_ArgError(res), "in method 'TagGroup::__subscript__', argument 1 of type 'TagGroup *'"); 
  } 
   char* skey=NULL;
  char buffer[64];
	if(PyString_Check(key))
	{
		skey = PyString_AsString(key);
	}
	else if (PyInt_Check(key))
	{
		sprintf_s(buffer, 64, "[%d]", PyInt_AsLong(key));
		skey=buffer;
	}
	else if(PyUnicode_Check(key)) {
		if(PyUnicode_READY(key)==0 && PyUnicode_KIND(key)==PyUnicode_1BYTE_KIND) {
			skey=(char*)PyUnicode_DATA(key);
		}
		else {
			SWIG_exception_fail(SWIG_ValueError, "in method 'TagGroup::__subscript__', argument 2 must be 8-bit unicode");
		}
	}
    else { 
    SWIG_exception_fail(SWIG_ValueError, "in method 'TagGroup::__subscript__', argument 2 of type 'String' or 'int' or 'unicode'"); 
  } 
  Gatan::DM::TagGroup *tg = reinterpret_cast<Gatan::DM::TagGroup*>(argp);
  //if we're a list, we have indexed tags only. They can be set and got using "[3]" eg as key
  //but only if that element already exists using one of the inserttag commands
  //else we have tags that can be tagggroups, arrays, strings, lists, etc. There's a getseeds() function
  //that might give us the types we have, but we can also just try. lets' start with taggroup and strings

  if(tg->GetTagAsTagGroup(skey,ret))
  {
    //we return a taggroup
	  resultobj = SWIG_NewPointerObj((new Gatan::DM::TagGroup(static_cast< const Gatan::DM::TagGroup& >(ret))), SWIGTYPE_p_Gatan__DM__TagGroup, SWIG_POINTER_OWN |  0 );
  }
	else if(tg->GetTagAsString(skey,str))
	{
		resultobj = PyString_FromString( str.get_string().c_str());
	}
  return resultobj; //NULL on failure, else o[key]
  fail:
  return NULL;
}

int SetTagOrIndexedTag(Gatan::DM::TagGroup& tg, PyObject *pykey, int _index, PyObject *v)
{
	//we set key and index based on the pykey and _index parameters. If pykey is not null
	//we use that, else we use _index
	char* key=NULL;
	int kindex = _index;
	if(pykey!=NULL)
	{
		if(PyInt_Check(pykey))
			kindex = PyInt_AsLong(pykey);
		else if(PyString_Check(pykey))
			key = PyString_AsString(pykey);
		else if(PyUnicode_Check(pykey) && 
			PyUnicode_READY(pykey)==0 && 
			PyUnicode_KIND(pykey)==PyUnicode_1BYTE_KIND){
				key=(char*)PyUnicode_DATA(pykey);
			}
		else
		{
			PyErr_SetString(PyExc_TypeError,"SetTagOrIndexedTag: Expect 'int' or 'String' key");
			 return -1;
		}
	}
	
	if(key==NULL)
		while(kindex >= tg.CountTags())
			tg.InsertTagAsLong(tg.CountTags(), 0);
			
	//if key!=null, sets the tag key to the value v
	//if key==null sets the indexed tag at location kindex to v
	if(PyFloat_Check(v))
	{
		if(	key!=NULL)
			tg.SetTagAsDouble(key, PyFloat_AsDouble(v));
		else
			tg.SetIndexedTagAsDouble(kindex, PyFloat_AsDouble(v));
	}
	else if (PyInt_Check(v))
	{
		if(	key!=NULL)
			tg.SetTagAsLong(key, PyInt_AsLong(v));
		else
			tg.SetIndexedTagAsLong(kindex, PyInt_AsLong(v));
	}
	else if(PyDict_Check(v))
	{
		//mfm 6Mar11 note that a mapping is less than a dictionary, as a mapping has x=o[key] and o[key]=v
		//methods only, but no guarantee of iteration or enumeration of keys. A dict does have these extra properties
		//so we will can convert dicts to taggroups, but not general mappings (similarly a taggroup is dict like as well
		//as a mapping, as we can enumerate the keys)
		Gatan::DM::TagGroup newtg = Gatan::DM::NewTagGroup();
		PyObject *nkey, *nvalue;
		Py_ssize_t pos = 0;
		int res=0;
		while (PyDict_Next(v, &pos, &nkey, &nvalue)) 
		{
			if(SetTagOrIndexedTag(newtg, nkey, -1, nvalue)==-1)
				return -1;
		}
		if(	key!=NULL)
			tg.SetTagAsTagGroup(key, newtg);
		else
			tg.SetIndexedTagAsTagGroup(kindex, newtg);
	}
	else if(PyString_Check(v))
	{
		if(	key!=NULL)
			tg.SetTagAsText(key, PyString_AsString(v));
		else
			tg.SetIndexedTagAsText(kindex, PyString_AsString(v));
	}
	else if(PyUnicode_Check(v) && PyUnicode_READY(v)==0 && PyUnicode_KIND(v)==PyUnicode_1BYTE_KIND) {
		if(	key!=NULL)
			tg.SetTagAsText(key, (char*)PyUnicode_DATA(v));
		else
			tg.SetIndexedTagAsText(kindex, (char*)PyUnicode_DATA(v));
	}
	else if(PySequence_Check(v))
	{
		//note a string is a sequence, so we should check for strings first
		Gatan::DM::TagGroup newtg = Gatan::DM::NewTagList();
		Py_ssize_t len = PySequence_Length(v);
		for(Py_ssize_t i=0; i<len; i++)
		{
			if(SetTagOrIndexedTag(newtg, NULL, i, PySequence_GetItem(v, i))==-1)
				return -1;
		}
		
		if(	key!=NULL)
			tg.SetTagAsTagGroup(key, newtg);
		else
			tg.SetIndexedTagAsTagGroup(kindex, newtg);
	}
	else
	{
		PyErr_SetString(PyExc_TypeError,"SetTagOrIndexedTag: Unexpected type");
     return -1;
	}
	return 0;
}

int PythonTagGroup_mp_ass_subscript(PyObject *self, PyObject *key, PyObject *v)
{
  // sets self[key]=v. For taggroups, key should always be a string, and v can be lots of things, but strings are easiest
	Gatan::DM::TagGroup us; 
  //need to convert self into a Gatan::DM::Image pointer
  //and key should be a string
  void *argp; 
  int res; 
  res = SWIG_ConvertPtr(self, &argp, SWIGTYPE_p_Gatan__DM__TagGroup, 0);  
	if (!SWIG_IsOK(res)) { return -1; }
	Gatan::DM::TagGroup *tg = reinterpret_cast<Gatan::DM::TagGroup*>(argp);
	return SetTagOrIndexedTag(*tg, key, -1, v);
fail:
	return -1;
}

//we're our own iterator?
PyObject* self_tp_iter(PyObject *self) { return self; }

PyObject* PythonTagGroup_tp_iter(PyObject *self) 
{
	void *argp; 
  int res; 
  res = SWIG_ConvertPtr(self, &argp, SWIGTYPE_p_Gatan__DM__TagGroup, 0); 
	if (!SWIG_IsOK(res)) { return NULL; }	
	Gatan::DM::TagGroup *tg = reinterpret_cast<Gatan::DM::TagGroup*>(argp);
	
	TagGroupIterator *p = new TagGroupIterator;
	p->tg = *tg;
	p->pos = 0;
	return SWIG_NewPointerObj(p, SWIGTYPE_p_TagGroupIterator, SWIG_POINTER_OWN |  0 );	
}

PyObject* TagGroupIterator_tp_iternext(PyObject *self)
{
	void *argp; 
  int res; 
  res = SWIG_ConvertPtr(self, &argp, SWIGTYPE_p_TagGroupIterator, 0); 
	if (!SWIG_IsOK(res)) { return NULL; }	
	TagGroupIterator *p = reinterpret_cast<TagGroupIterator*>(argp);
	
	PyObject* ret= NULL;
	if(p->pos < p->tg.CountTags())
	{
		if(p->tg.IsList())
			ret= PyLong_FromSsize_t(p->pos); //we just return an int
		else
			ret= PyString_FromString(p->tg.GetTagLabel(p->pos).get_string().c_str());
		p->pos++;
	}
	
	return ret;
}

%}

//and then we add the features
//new buffer features for Images
%feature("python:bf_getbuffer") Gatan::DM::Image "PythonGatanDMImage_bf_getbuffer";
%feature("python:bf_releasebuffer") Gatan::DM::Image "PythonGatanDMImage_bf_releasebuffer";

//Dictionary and iterable methods for taggroups
%feature("python:mp_length") Gatan::DM::TagGroup "PythonTagGroup_mp_length";
%feature("python:mp_subscript") Gatan::DM::TagGroup "PythonTagGroup_mp_subscript";
%feature("python:mp_ass_subscript") Gatan::DM::TagGroup "PythonTagGroup_mp_ass_subscript";
%feature("python:tp_iter") Gatan::DM::TagGroup "PythonTagGroup_tp_iter";

namespace Gatan {
	namespace DM{
	    class Image {};
		
		class TagGroup {};
	}
}
%include "DMPluginStubs_modified.h"
