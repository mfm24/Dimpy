
///
/// This plugin will install two simple script functions, 'Hello' and 'World'
///
//

/*
Notes:
see DimpyNotes.txt

*/
//#include <afx.h>
#if defined MAKE_PYD //if this is defined we never need NO_DIMPY
#else
//tried the pyd approach but it doesn't work. Looks like DM needs an initialized plugin in order to be able to call
//any functions. We'll stick with the DM only plugin
//#define NO_DIMPY
#endif

#define _GATANPLUGIN_USES_LIBRARY_VERSION 2
#include "DMPlugInBasic.h"

#define _GATANPLUGIN_USE_CLASS_PLUGINMAIN
#include "DMPlugInMain.h"

#include <python.h>
#include <process.h> //for thread creation


#if _MSC_VER>=1600
	#pragma error Use v90 toolset to compile this file!
#endif

#if _DEBUG
	#pragma comment(lib, "DM2008HelperStaticEdit_debug.lib")
#else
	//This was built with 
	//cl /c DMHelper.cpp
	//lib DMHelper.obj    # makes DMHelper.lib
	//python EditDM2008HelperStatic.py DMHelper.lib
	//to make DMHelper_edit.lib
	#pragma comment(lib, "DMHelper_edit.lib")
#endif

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
//mfm 20Feb12 this is odd, we need this here so that it loads the static lib and finds the
//functions. Without it, it doesn't bother looking...
double teststaticlib();

#if _DLL 
	#if _DEBUG
	#pragma comment(lib, "DMPlugInBasic_dll-Dbg.lib")
	#else
	#pragma comment(lib, "DMPlugInBasic_dll.lib")
	#endif
#else
	#if _DEBUG
	#pragma comment(lib, "DMPlugInBasic-Dbg.lib")
	#else
	#pragma comment(lib, "DMPlugInBasic.lib")
	#endif
#endif

using namespace Gatan;
#ifdef NO_DIMPY
#else
extern "C" {  // I'm writing a C++ app, but initswig() is C.
    void init_DimPy(void); // we get this from the swig-generated file.
	void initDimpyDynamic(void); //from DimpyDynamic.cpp
}
#endif
class LibraryExample : public GatanPlugIn::PlugInMain
{
	virtual void Start();
	virtual void Run();
	virtual void Cleanup();
	virtual void End();
};

#define USE_PYTHREAD
unsigned int __stdcall StartPyThread(VOID* args)
{
#ifdef NO_DIMPY
#else
	PyRun_SimpleString("import DimPy as dp");
#endif
	PyRun_InteractiveLoop(stdin, "<stdin>");
	FreeConsole();
	//GatanPlugIn::ImageDataLocker idl = new GatanPlugIn::ImageDataLocker(self);
	double d= teststaticlib();

	return 0;
}
/// 
/// This is the first of two functions which will be available to the script 
/// language. Once the library plug-in is installed this function can be 
/// invoked from a script with the following line:
///		hello()
/// Note that this function is NOT declared pascal.
///
void Hello(void)
{
	/*To create the wrapper file and build:
	1.Download SWIG
	2. Create a SWIG interface file, DigitalMicrograph.i, like (note we only import the stubs here):
//mfm 24Jan12 SWIG interface module for DigitalMicrograph
%module DigitalMicrograph
%{
#define _GATANPLUGIN_USES_LIBRARY_VERSION 2
#include "DMPlugInBasic.h"
%}
%include "DMPlugInStubs.h"
	[Actually, the above doesn't work. There are problems with the token_types that DM uses as typedefs from templates
	So to get it working before, I c&p the DMPlugInStubsFile, removing a lot of the token constructors and leaving the 
	main classes]
	3. Run 
	>swig -python -c++ DigitalMicrograph.i
	creates two files, DigitalMicrograph_wrap.cxx (~3MB !) and DigitalMicrograph.py
	4.Insert DigitalMicrograph_wrap.cxx into here and copy DigitalMicrograph.py to 
	the \Lib\site-packages in the path specified n the 
	HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\App Paths\Python.exe\ 
	(Default) Key
	5.Compile and copy DLL into plugins dir of DM
	/*To get this to run from a virgin DM installation:
	1. Copy DM2008Helper.dll to DM folder
	2. Run DM. Call Hello(), open python prompt.
>>> import _DMPluginBasic as DM
>>> DM.Result(DM.new_String("Hello"))
swig/python detected a memory leak of type 'Gatan::DM::String *', no destructor
found.
>>>
	*/
	AllocConsole();
	// Redirect Standard IO Streams to the new console
	//Note that it is critical that the python lib we're linking to uses the same C runtime. If not, setting stdout/in/err here
	//won't affect the values in the runtime for the dll. 
    freopen("CONOUT$","wt",stdout);
    freopen("CONOUT$","wt",stderr);
    freopen("CONIN$","rt",stdin);
	char*b = "PyDM Starting...\n";
	printf(b);

	Py_Initialize();
#ifdef NO_DIMPY
#else
	init_DimPy();
	initDimpyDynamic();
#endif
	unsigned int threadid;
#if defined USE_PYTHREAD
	_beginthreadex(NULL, 0, StartPyThread, NULL,  0, &threadid);
#else
	//PyRun_SimpleString("import DigitalMicrograph as DM");
	PyRun_InteractiveLoop(stdin, "<stdin>");
	FreeConsole();
#endif
	DM::Result("hello, ");
}

extern "C" {
	__declspec(dllexport) long Dimpy_Init(const char*);
	__declspec(dllexport) long Dimpy_PyRun_SimpleString(const char*);
}

long Dimpy_Init(const char *pythonloc)
{
	if(pythonloc)
	{
		printf("Setting python home to %s\n", pythonloc);
		//Py_SetProgramName doesn't work here, but Py_SetPythonHome does...
		Py_SetPythonHome((char*)pythonloc);
	}
	Py_Initialize();
	init_DimPy();
	initDimpyDynamic();
	return 0;
}

long Dimpy_PyRun_SimpleString(const char*s)
{
	return PyRun_SimpleString(s);
}
///
/// This is second of two functions which will be available to the script 
/// language. Once the library plugin is installed this function can be 
/// invoked from a script with the following line:
///		world()
/// Note that this function is NOT declared pascal.
///2DA0A0 0x04F73390
void World(long id, char* string)
{
	
		Gatan::PlugIn::DigitalMicrographInterface& dmi=Gatan::PlugIn::gDigitalMicrographInterface;
		int v=dmi->get_version();
		DM::Function d=dmi->lookup_function( string);
		if(d!=NULL)
		{
			char c[32];
			sprintf(c, "token:%d\n", d.get());
			DM::Result(c);
			DM::Result(d.GenerateStub(true, 1));
		}
		else
		{
			DM::Result("Couldn't find ");
			DM::Result(string);
			DM::Result("\n");
		}
	
	if(id==1)
	{
		static DM::Function __sFunction = (DM_FunctionToken) NULL;
		static const char *__sSignature = "void ControlDown()";

	//Gatan::PlugIn::DM_Variant params[0];

		GatanPlugIn::gDigitalMicrographInterface.CallFunction( __sFunction.get_ptr(), 0, NULL, __sSignature );
		char c[32];
		sprintf(c, "token:%d\n", __sFunction.get());
		DM::Result(c);
	}
	//DM::Result("world...\n");
}

///
/// This is called when the plugin is loaded.  Whenever DM is
/// launched, it calls 'Start' for each installed plug-in.
/// When it is called, there is no guarantee that any given
/// plugin has already been loaded, so the code should not
/// rely on scripts installed from other plugins.  The primary
/// use is to install script functions.
///
void LibraryExample::Start()
{
	// add our functions to the script library
	AddFunction("void Hello(void)", (void *) Hello);
	AddFunction("void World(long id, char* name)", (void *) World);
}

///
/// This is called when the plugin is loaded, after the 'Start' method.
/// Whenever DM is launched, it calls the 'Run' method for
/// each installed plugin after the 'Start' method has been called
/// for all such plugins and all script packages have been installed.
/// Thus it is ok to use script functions provided by other plugins.
///
void LibraryExample::Run()
{
}

///
/// This is called when the plugin is unloaded.  Whenever DM is
/// shut down, the 'Cleanup' method is called for all installed plugins
/// before script packages are uninstalled and before the 'End'
/// method is called for any plugin.  Thus, script functions provided
/// by other plugins are still available.  This method should release
/// resources allocated by 'Run'.
///
void LibraryExample::Cleanup()
{
}

///
/// This is called when the plugin is unloaded.  Whenever DM is shut
/// down, the 'End' method is called for all installed plugins after
/// all script packages have been unloaded, and other installed plugins
/// may have already been completely unloaded, so the code should not
/// rely on scripts installed from other plugins.  This method should
/// release resources allocated by 'Start', and in particular should
/// uninstall all installed script functions.
///
void LibraryExample::End()
{
}

LibraryExample gTemplatePlugIn;
