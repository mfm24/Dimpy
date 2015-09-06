
///
/// This plugin will install two simple script functions, 'Hello' and 'World'
///
//

/*
Notes:
see DimpyNotes.txt

*/
//mfm 2014-10-26 We need the DM libraries to get the exposed functions,
// But they in turn need a plugin to link to(?). So we can't not
// be a plugin to be able to access the library functions.
// (just to get to compile, even though our start/run
// /etc functions will never get called)
#define _GATANPLUGIN_USES_LIBRARY_VERSION 2
#include "DMPlugInBasic.h"

#define _GATANPLUGIN_USE_CLASS_PLUGINMAIN
#include "DMPlugInMain.h"
using namespace Gatan;

#include <python.h>
#include <process.h> //for thread creation


#if _MSC_VER>=1600
	#pragma error Use v90 toolset to compile this file!
#endif

long Dimpy_PyRun_SimpleString(const char*s);

//MFM 2014-02-14
//can't get DMSDK 3.8.2 without implementing this...
namespace Gatan
{
	namespace PlugIn
	{
		void DMScript_HandleException(struct Gatan::PlugIn::DM_Env *env,class std::exception const & ex)
		{
			DM::Result(ex.what());
			DMScript_HandleException(env);
		}
	}
}


#pragma comment(lib, "DMPlugInBasic.lib")
#pragma comment(lib, "Foundation.lib")


using namespace Gatan;
// this is the swig generated SWIG_INIT function. Return PyObject under 3.x
// NB  SWIG_INIT is defined as PyInit__DimPy also for 3.x
extern "C" PyObject* PyInit__DimPy();

FILE* getMsvcr100StdIn() 
{
	PyObject* pGlobal = PyDict_New();
    PyObject* pLocal = PyDict_New();
	PyObject* err;
	// NB PyEval_GetGlobals, PyEval_GetLocals are only valid during a Python call (eg if calling an extension from python)
	// when embedding wemost likely aren't in a python call. So we have to create a globals dict with
	// builtins included...
	PyDict_SetItemString(pGlobal, "__builtins__", PyEval_GetBuiltins());
	PyObject* pValue2 = PyRun_String("import ctypes", Py_file_input, pGlobal, pLocal);
	err = PyErr_Occurred(); PyErr_Print();
    PyObject* pValue4 = PyRun_String("ctypes.cdll.msvcr100.__iob_func()", Py_eval_input, pGlobal, pLocal);
    err = PyErr_Occurred(); PyErr_Print();
    
    PY_LONG_LONG ret = PyLong_AsLongLong(pValue4);
	//Py_DECREF(pValue);
	Py_XDECREF(pGlobal);
	Py_XDECREF(pLocal);
	return (FILE*) ret;
}

void changeStdinFromPython() 
{
	// NB size of FILE is 48. honest.
	// This is a bit odd. We use python as a way to reassign stdin, out in msvcr100
	// but this means we start python without a valid stdin/out/err. So we have to use python
	// to reassign, AND then we need to set sys.stdout/err/in also
	Dimpy_PyRun_SimpleString(
		"import ctypes\n"
		"import sys\n"
		"m = ctypes.cdll.msvcr100\n"
		"k = ctypes.windll.kernel32\n"
		"k.AllocConsole()\n"
		"m.freopen(b'CONIN$', b'rt', m.__iob_func())\n"
		"m.freopen(b'CONOUT$', b'wt', m.__iob_func() + 48)\n"
		"m.freopen(b'CONOUT$', b'wt', m.__iob_func() + 48 * 2)\n"
		"sys.stdin = open('CONIN$', 'rt')\n"
		"sys.stdout = open('CONOUT$', 'wt')\n"
		"sys.stderr = open('CONOUT$', 'wt')\n"
		);
}
unsigned int __stdcall StartPyThread(VOID* args)
{
	changeStdinFromPython();
	Dimpy_PyRun_SimpleString("import sys; print('Python (DimPy) %s on %s' % (sys.version, sys.platform)); del sys");
	PyRun_InteractiveLoop(getMsvcr100StdIn(), "<stdin>");
    PyErr_Print();
	FreeConsole();
	//GatanPlugIn::ImageDataLocker idl = new GatanPlugIn::ImageDataLocker(self);
	return 0;
}

// exported functions
extern "C" {
	// NB THESE ARE NOT DM functions! 0_DimpyLoader calls this!
	__declspec(dllexport) long Dimpy_Init(const char*);
}

// this has to persist as we're going
wchar_t* wcstring;
long Dimpy_Init(const char *pythonloc)
{
	if(pythonloc)
	{
		printf("Setting python home to %s\n", pythonloc);
		//Py_SetProgramName doesn't work here, but Py_SetPythonHome does...
		// need to convert to wchar_t for python 3

		//from http://stackoverflow.com/questions/3074776/how-to-convert-char-array-to-wchar-t-array
		// Convert to a wchar_t*
		size_t origsize = strlen(pythonloc) + 1;
		size_t convertedChars = 0;
		wcstring = new wchar_t[origsize];
		mbstowcs_s(&convertedChars, wcstring, origsize, pythonloc, _TRUNCATE);

		Py_SetPythonHome(wcstring);
		// can'e delete this til we;ve uninitialized Python
		// delete[] wcstring;
	}
	else {
		printf("No python home specified", pythonloc);
	}
	// With Python3 we need to tell it to automatically add a module, before
	// Py_Init, I think. (see https://docs.python.org/3.6/extending/extending.html#the-module-s-method-table-and-initialization-function)

	/* Add a built-in module, before Py_Initialize */
    PyImport_AppendInittab("_DimPy", PyInit__DimPy);
	Py_Initialize();
	//PyInit__DimPy();
	// we can import automatically too:
	PyImport_ImportModule("_DimPy");

	return 0;
}

long Dimpy_PyRun_SimpleString(const char*s)
{
	return PyRun_SimpleString(s);
}

bool hasStartedPython = false;
long Dimpy_StartREPL(bool bUseThread)
{
	if(hasStartedPython)
		return -1;
	hasStartedPython = true;
	if (bUseThread)
	{
		unsigned int threadid;
		_beginthreadex(NULL, 0, StartPyThread, NULL,  0, &threadid);
	}
	else
	{
		//PyRun_SimpleString("import DigitalMicrograph as DM");
		StartPyThread(NULL);
	}
	return 0;
}
 

void Dimpy_open_console()
{
	// Calls DimpyLoader_alloc_console_and_reassign_std after initialising
	// python, and the prints out sys.version, like a grown-up shell would.
	// We then start the REPL in a new thread.
	//Dimpy_alloc_console_and_reassign_std();
	Dimpy_StartREPL(true);
}

class LibraryExample : public GatanPlugIn::PlugInMain
{
	virtual void Start() 
	{
		//Dimpy_alloc_console_and_reassign_std();
		// add our functions to the script library
		AddFunction("long Dimpy_PyRun_SimpleString(string)", (void *) Dimpy_PyRun_SimpleString);
		//Setting stdout can be useful for getting results from SimpleString without
		// the full REPL experience
		AddFunction("void Dimpy_open_console(void)", (void *) Dimpy_open_console);
		DM::AddScriptToMenu("Dimpy_open_console();", "Open Console", "DimPy", NULL, 0);
	}
	virtual void Run() {}
	virtual void Cleanup() {}
	virtual void End() {}
};
LibraryExample gTemplatePlugIn;