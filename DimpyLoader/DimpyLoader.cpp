///
/// This plugin will install two simple script functions, 'Hello' and 'World'
///
#define _GATAN_USE_STL_STRING
#define _GATANPLUGIN_USES_LIBRARY_VERSION 2
#include "DMPlugInBasic.h"

#define _GATANPLUGIN_USE_CLASS_PLUGINMAIN
#include "DMPlugInMain.h"

#if _MSC_VER>=1600
	#pragma error Use v90 toolset to compile this file!
#endif

#ifdef _DEBUG
#pragma comment(lib, "DMPlugInBasic_dll-Dbg.lib")
#pragma comment(lib, "..\\DM2008Helper\\DM2008HelperStaticEdit_debug.lib")
#else
#pragma comment(lib, "DMPlugInBasic_dll.lib")
#pragma comment(lib, "..\\DM2008Helper\\DM2008HelperStaticEdit_release.lib")
#endif
//MFM 2014-02-14
//can't get DMSDK 3.8.2 without implementing this...
//need to reference something in lib for it to load
double teststaticlib();
double d= teststaticlib();
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

using namespace Gatan;

class LibraryExample : public GatanPlugIn::PlugInMain
{
	virtual void Start();
	virtual void Run();
	virtual void Cleanup();
	virtual void End();
};

char pythonver[2] = {'2', '7'};

long get_reg_key(HKEY rt, char* path, char* valuename, BYTE** put_into)
{
	// Returns 0 on success, 2 if path can't be opened, 1 if path ok but valuename bad:
	long ret = 2;
	HKEY key;
	LONG err = RegOpenKeyEx(rt, path, 0, KEY_READ, &key);
	DWORD len;
	if(err==ERROR_SUCCESS)
	{
		if(RegQueryValueEx(key, valuename, NULL, NULL, NULL, &len)==ERROR_SUCCESS)
		{	
			*put_into = new BYTE[len+1];
			if(RegQueryValueEx(key, valuename, NULL, NULL, *put_into, &len)==ERROR_SUCCESS)
			{
				//ensure nil terminated
				if((*put_into)[len-1] != 0)
				{
					(*put_into)[len] = 0;
				}
				ret = 0;
			}
			else { ret = 1; }
		}
		RegCloseKey(key);
	}
	return ret;
}

typedef void (*f_voidvoid)(void);
typedef long (*f_longsz)(const char *);
HMODULE h_dimpy = NULL;
BYTE *python_module_path=NULL;

HMODULE try_from_registry(HKEY rt, char* path, char* valuename)
{
	long r = get_reg_key(rt, path, valuename, &python_module_path);
	HMODULE ret=NULL;
	if(r==0)
	{
		int l = strlen((char*)python_module_path)+100;
		char *p=new char[l];
		sprintf_s(p, l, "%s\\Python%c%c.dll", python_module_path, pythonver[0], pythonver[1]);
		ret = LoadLibrary(p);
		if(ret)
		{
			//we've loaded it, let's add to start of path
			DWORD len = GetEnvironmentVariable("PATH", NULL, 0);
			char *pathp=new char[len+3];
			GetEnvironmentVariable("PATH", pathp, len+3);
			char *newpath = new char[len+3+strlen((char*)python_module_path)+3];
			sprintf(newpath, "%s;%s", python_module_path, pathp);
			SetEnvironmentVariable("PATH", newpath);
			delete[] pathp;
			delete[] newpath;

		}
		delete[] p;
	}
	return ret;
}

void DimpyLoader_Init(void)
{
	//We try to dynamically load Python27.dll.
	//Then load Dimpy.dll to properly start things.
	//Using this double-dll approach so that we can
	//give sensible diagnostics if any libraries
	//are missing.

	//1st, do we have SimpyLocation in registry, (HKCU/Software/DimPy/Path) without this,
	//no point continuing
	BYTE *pDimpyPath = NULL;
	long r = get_reg_key(HKEY_CURRENT_USER, "Software\\DimPy", "Path", &pDimpyPath);
	if (r!=0)
		r = min(r, get_reg_key(HKEY_LOCAL_MACHINE, "Software\\DimPy", "Path", &pDimpyPath));
	if (r==2)  { DM::Result("Dimpy not installed!\n");  return; }
	if (r==1)  { DM::Result("Dimpy not installed! (no 'Path' key found)\n");  return; }
	char *t=new char[strlen((char*)pDimpyPath)+100];
	sprintf(t, "FoundKey %s\n", pDimpyPath);
	DM::Result(t);
	delete[] t;
	//we look for Python27.dll in the following locations, in order:
	//1. HKCU/Software/Dimpy/PythonPath
	//2. HKLM/Software/Dimpy/PythonPath
	//2. HKCU/Software/Python/PythonCore/2.7/InstallPath/""
	//3. HKLM/Software/Python/PythonCore/2.7/InstallPath/""
	// If none found, we just use LoadLibrary instead...
	HMODULE h = NULL;
	h = try_from_registry(HKEY_CURRENT_USER, "Software\\DimPy", "PythonPath");
	if(h==NULL)
		h = try_from_registry(HKEY_LOCAL_MACHINE, "Software\\DimPy", "PythonPath");
	if(h==NULL)
	{
		char *t = new char[256];
		sprintf_s(t, 256, "Software\\Python\\PythonCore\\%c.%c\\InstallPath", pythonver[0], pythonver[1]);
		h = try_from_registry(HKEY_CURRENT_USER, t, "");
		if(h==NULL)
			h = try_from_registry(HKEY_LOCAL_MACHINE, t, "");
		delete[] t;
	}

	if(h==NULL)
	{
		//try a regular load...
		char *t = new char[256];
		sprintf_s(t, 32, "Python%c%c.dll", pythonver[0], pythonver[1]);
		h = LoadLibrary(t);
		delete[] t;
	}

	if(h==NULL)
		DM::Result("DimpyLoader ERROR: Can't find Python library!\n");
	else
	{
		DM::Result("DimpyLoader: Loaded Python library!\n");
		//and we finally load our dll
		char *t=new char[strlen((char*)pDimpyPath)+100];
		sprintf(t, "%s\\DimPy.dll", pDimpyPath);
		h_dimpy = LoadLibrary(t);
		delete[] t;
		if(h_dimpy)
		{
			f_longsz to_call = (f_longsz) GetProcAddress(h_dimpy, "Dimpy_Init");
			if(to_call)
				to_call((char*) python_module_path);
			else
				DM::Result("Found DimPy.dll but procedure 'Dimpy_Init' not found!");
		}
		else
			DM::Result("Can't find DimPy.dll!");
	}

	delete[] pDimpyPath;
}

long DimpyLoader_PyRun_SimpleString(const char *s)
{
	if(h_dimpy == NULL)
		DimpyLoader_Init();
	if(h_dimpy == NULL)
		return -1;
	f_longsz to_call = (f_longsz) GetProcAddress(h_dimpy, "Dimpy_PyRun_SimpleString");
	if(to_call)
		return to_call(s);
	else
		DM::Result("Found DimPy.dll but procedure 'Dimpy_PyRun_SimpleString' not found!");
	return -1;
}
void DimpyLoader_alloc_console_and_reassign_std()
{
	AllocConsole();
	// Redirect Standard IO Streams to the new console
	//Note that it is critical that the python lib we're linking to uses the same C runtime. If not, setting stdout/in/err here
	//won't affect the values in the runtime for the dll. 
    freopen("CONOUT$","wt",stdout);
    freopen("CONOUT$","wt",stderr);
    freopen("CONIN$","rt",stdin);
	printf("DimPy Console\n");
}

void LibraryExample::Start()
{
	// add our functions to the script library
	AddFunction("long DimpyLoader_PyRun_SimpleString(string)", (void *) DimpyLoader_PyRun_SimpleString);
	AddFunction("void DimpyLoader_alloc_console_and_reassign_std(void)", (void *) DimpyLoader_alloc_console_and_reassign_std);
}

void LibraryExample::Run()
{
}

void LibraryExample::Cleanup()
{
}

void LibraryExample::End()
{
}

LibraryExample gTemplatePlugIn;
