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
typedef long (*f_longb)(bool);

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
			sprintf(newpath, "%s;%s", pathp, python_module_path);
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

	// MFM 2015-08-30
	// But we have problem that this has no dependance on pythondll, but in order to find
	// the python version we're compiled against, we need to load DimpyMain.dll. But we can't do this
	// until we've found the python dll! How about if we search in the current path for 
	// DimPyxx.dll, which we name the same as the python dll (eg DimPy27.dll for python 27
	// and DimPy34.dll for python 34.dll) and use the name of the DLL to determine which key to
	// search for. This way this should work with any DimPyxx.dll and we can do this without loading it!

	// Step 1.
	// search for DimPyxy.dll
	// Step 2:
	// we look for Pythonxy.dll in the following locations, in order:
	//    1. HKCU/Software/Dimpy/PythonPath
	//    2. HKLM/Software/Dimpy/PythonPath
	//    2. HKCU/Software/Python/PythonCore/x.y/InstallPath/""
	//    3. HKLM/Software/Python/PythonCore/x.y/InstallPath/""
	// If none found, we just try LoadLibrary("pythonxy.dll") instead...
	HMODULE h = NULL;
	HANDLE hand = NULL;
	char t[256];
	WIN32_FIND_DATA finddata;
	hand = FindFirstFile("DimPy??.dll", &finddata);
	if (hand == INVALID_HANDLE_VALUE) {
		DM::Result("0_DimpyLoader: No DimPy dll found! DimPy unavailable!\n");
	}
	else {
		FindClose(hand);
		sscanf(finddata.cFileName, "DimPy%c%c.dll", &pythonver[0], &pythonver[1]);
	}

	sprintf(t, "0_DimpyLoader: searching for Python%c.%c environment...", pythonver[0], pythonver[1]); 
	DM::Result(t);
	// t is key here. We use PythonxyPath where xy is version number
	sprintf(t, "Python%c%cPath", pythonver[0], pythonver[1]);
	h = try_from_registry(HKEY_CURRENT_USER, "Software\\DimPy", t);
	if(h==NULL)
		h = try_from_registry(HKEY_LOCAL_MACHINE, "Software\\DimPy", t);
	if(h==NULL)
	{
		//char *t = new char[256];
		sprintf_s(t, 256, "Software\\Python\\PythonCore\\%c.%c\\InstallPath", pythonver[0], pythonver[1]);
		h = try_from_registry(HKEY_CURRENT_USER, t, "");
		if(h==NULL)
			h = try_from_registry(HKEY_LOCAL_MACHINE, t, "");
		//delete[] t;
	}

	if(h==NULL)
	{
		//try a regular load...
		//char *t = new char[256];
		sprintf_s(t, 32, "Python%c%c.dll", pythonver[0], pythonver[1]);
		h = LoadLibrary(t);
		//delete[] t;
	}

	if(h==NULL)
		DM::Result("Can't find Python library!\n");
	else
	{
		DM::Result("found!\n");
		//and we finally load our dll
		sprintf(t, "Plugins\\DimpyMain.dll");
		// MFM 2104-10-26 DimPy has to be a plugin, so we don't
		// need a dimpy path, should always be this:
		h_dimpy = LoadLibrary(t);
		if(h_dimpy)
		{
			f_longsz to_call = (f_longsz) GetProcAddress(h_dimpy, "Dimpy_Init");
			if(to_call)
				to_call((char*) python_module_path);
			else
				DM::Result("Found DimpyMain.dll but procedure 'Dimpy_Init' not found!");
		}
		else
			DM::Result("Can't find DimpyMain.dll!");
	}
}

void LibraryExample::Start()
{
	// MFM 2014-10-26 for DimPy to have access to functions, it needs to be a real plugin
	// Which means we need to load Python before DimPy gets loaded. So we
	// do as soon as possible:
	DimpyLoader_Init();
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
