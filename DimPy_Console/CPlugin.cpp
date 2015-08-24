
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

unsigned int __stdcall StartPyThread(VOID* args)
{
	PyRun_InteractiveLoop(stdin, "<stdin>");
	FreeConsole();
	//GatanPlugIn::ImageDataLocker idl = new GatanPlugIn::ImageDataLocker(self);
	double d= teststaticlib();
	return 0;
}

// exported functions
extern "C" {
	// NB THESE ARE NOT DM functions! Use DimpyLoader functions to call these!
	__declspec(dllexport) long Dimpy_Init(const char*);
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
		PyRun_InteractiveLoop(stdin, "<stdin>");
		FreeConsole();
	}
	return 0;
}
 
bool hasAllocedConsole=false;
void Dimpy_alloc_console_and_reassign_std()
{
	if(hasAllocedConsole)
		return;
	hasAllocedConsole = true;
	AllocConsole();
	// Redirect Standard IO Streams to the new console
	//Note that it is critical that the python lib we're linking to uses the same C runtime. If not, setting stdout/in/err here
	//won't affect the values in the runtime for the dll. 
    freopen("CONOUT$","wt",stdout);
    freopen("CONOUT$","wt",stderr);
    freopen("CONIN$","rt",stdin);
	printf("Welcome to the DimPy console!\n");
}

void Dimpy_open_console()
{
	// Calls DimpyLoader_alloc_console_and_reassign_std after initialising
	// python, and the prints out sys.version, like a grown-up shell would.
	// We then start the REPL in a new thread.
	Dimpy_alloc_console_and_reassign_std();
	Dimpy_PyRun_SimpleString("import sys; print(sys.version)");
	Dimpy_StartREPL(true);
}

class LibraryExample : public GatanPlugIn::PlugInMain
{
	virtual void Start() 
	{
		// add our functions to the script library
		AddFunction("long Dimpy_PyRun_SimpleString(string)", (void *) Dimpy_PyRun_SimpleString);
		//Setting stdout can be useful for getting results from SimpleString without
		// the full REPL experience
		AddFunction("void Dimpy_alloc_console_and_reassign_std(void)", (void *) Dimpy_alloc_console_and_reassign_std);
		AddFunction("void Dimpy_open_console(void)", (void *) Dimpy_open_console);
		DM::AddScriptToMenu("Dimpy_open_console();", "Open Console", "DimPy", NULL, 0);
	}
	virtual void Run() {}
	virtual void Cleanup() {}
	virtual void End() {}
};
LibraryExample gTemplatePlugIn;