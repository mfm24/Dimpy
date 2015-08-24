//mfm 29Sep08 - got this from http://social.msdn.microsoft.com/Forums/en-US/vcgeneral/thread/5ac28a31-3339-4db1-90f4-68edad360309/
//we basically need a new lib which explicity exports the imports that DMPlugin library needs.
//added 
/*
/export:?_Xran@_String_base@std@@QBEXXZ=?_Xran2003_2008@_String_base2003_2008@std2003_2008@@QBEXXZ 
/export:?_Xlen@_String_base@std@@QBEXXZ=?_Xlen2003_2008@_String_base2003_2008@std2003_2008@@QBEXXZ
to the command line for the linker to get names right!
then added
/export:?_Addstd@ios_base@std@@QAEXXZ=?_AddStd2003_2008@_String_base2003_2008@std2003_2008@@QAEXXZ
to fix AddStd problem too
//mfm 2014-02-15 With VS 2008 express edition, get
//error LNK2019: unresolved external symbol "public: void __thiscall std::ios_base::_Addstd(void)" (?_Addstd@ios_base@std@@QAEXXZ) referenced in function "protected: void __thiscall std::basic_ios<char,struct std::char_traits<char> >::init(class std::basic_streambuf<char,struct std::char_traits<char> > *,bool)" (?init@?$basic_ios@DU?$char_traits@D@std@@@std@@IAEXPAV?$basic_streambuf@DU?$char_traits@D@std@@@2@_N@Z)
//does ios::_AddStd() not exist? - trying without AddStd
//and we have a problem with the xclib, so added the enlargedunsigned multiply code too
//which needs
/export:_EnlargedUnsignedMultiply@8=?EnlargedUnsignedMultiply@@YG?AT_LARGE_INTEGER@@KK@Z
//mfm 20July11 we know have problem compiling against DMPlugInBasic_dll.lib, so trying to add
//things to fix:
1>DMPlugInBasic_dll.lib(GatanStringUtility.obj) : error LNK2019: unresolved external symbol "__declspec(dllimport) public: void __thiscall std::locale::facet::_Register(void)" (__imp_?_Register@facet@locale@std@@QAEXXZ) referenced in function "?use_facet@?$@V?$ctype@_W@std@@@std@@YAABV?$ctype@_W@1@ABVlocale@1@@Z" (?use_facet@?$@V?$ctype@_W@std@@@std@@YAABV?$ctype@_W@1@ABVlocale@1@@Z)
1>DMPlugInBasic_dll.lib(GatanStringUtility.obj) : error LNK2019: unresolved external symbol "__declspec(dllimport) public: static unsigned int __cdecl std::ctype<wchar_t>::_Getcat(class std::locale::facet const * *)" (__imp_?_Getcat@?$ctype@_W@std@@SAIPAPBVfacet@locale@2@@Z) referenced in function "?use_facet@?$@V?$ctype@_W@std@@@std@@YAABV?$ctype@_W@1@ABVlocale@1@@Z" (?use_facet@?$@V?$ctype@_W@std@@@std@@YAABV?$ctype@_W@1@ABVlocale@1@@Z)
//Also added dumpbin /ALL to the build step!
//so we need also:
/export:__imp_?_Getcat@?$ctype@_W@std@@SAIPAPBVfacet@locale@2@@Z=?_Getcat2003_2008@_stdctype_base2003_2008@std2003_2008@@SAIPAPBVfacet@locale@std@@@Z
/export:__imp_?_Register@facet@locale@std@@QAEXXZ=?_Register2003_2008@_facet_base2003_2008@std2003_2008@@QAEXXZ
*/
//mfm 6Sep11 - not sure the above helped - I couldn't compile AutoStem.dll nor SuperScan.dll with the above, CCD1010 seemed to go further but then gave me 
//error LNK2022: metadata operation failed (8013118D) : Inconsistent layout information in duplicated types (tagTOUCHINPUT): (0x020007b5)
//errors. Could be the compiler is stricter now and we'd have to do a lot of work getting a library built with a different C runtime with the latest version.


// Source libvisual2003_visual2008.cpp
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#include <string>
#include "windows.h" //for LARGE_INT
//mfm 20Feb12 TRying to get rid of dll. Lets make a static lib 
//can we rename these in the lib file, and if so, let's keep them the same length
//we'll replace last char with cap
//then run the following in python on the .lib file
/*EditDM2008HelperStatic.py
path="DM2008HelperStatic"
inf=open(path+".lib", "rb")
outf = open(path+"Edit.lib", "wb")
data=inf.read();
data=data.replace("?UUIMPUQ_RegisteR@_facet_basE@stD@@QAEXXZ", "__imp_?_Register@facet@locale@std@@QAEXXZ")
data=data.replace("?GetcaT@_stdctype_basE@stD@@SAIPAPBVfacet@locale@std@@@Z", "__imp_?_Getcat@?$ctype@_W@std@@SAIPAPBVfacet@locale@2@@Z")

for rep in ["std", "_base", "_Xlen", "_Xran", "_AddStd", "_Register", "_Getcat"]:
	data = data.replace(rep[0:-1]+rep[-1].upper(), rep)
outf.write(data)
outf.close()
inf.close()
*/
//and rename the DM2008HelperStatic.libedit file to DM2008HelperStaticEdit.lib
namespace stD
{
	class _String_basE : std::_String_base
{ 
   public:
      __declspec(dllexport) void _XleN(void) const; 
     __declspec(dllexport) void _XraN(void) const; 
	  __declspec(dllexport)  void _AddStD(void);
};

	class ios_basE : std::ios_base
{ 
   public:
	  __declspec(dllexport)  void _AddstD(void);
};

	class _facet_basE : std::locale::facet
	{
	public:
		//mfm 20Feb gives us, vs what we want:
		//	?UUIMPUQ_RegisteR@_facet_basE@stD@@QAEXXZ
		//	__imp_?_Register@facet@locale@std@@QAEXXZ
		//we'll decorate name (U=_, Q=? to give same length, then explicitly replace
		void __thiscall UUIMPUQ_RegisteR(void);
	};

	class _stdctype_basE : std::ctype<wchar_t>
	{
	public:
		//gives:		?GetcaT@_stdctype_basE@stD@@SAIPAPBVfacet@locale@std@@@Z
		//want:			__imp_?_Getcat@?$ctype@_W@std@@SAIPAPBVfacet@locale@2@@Z
		static unsigned int __cdecl GetcaT(std::locale::facet const * * x);
	};
};

void __thiscall stD::_facet_basE::UUIMPUQ_RegisteR(void)
{
	_Register();
}

unsigned int stD::_stdctype_basE::GetcaT(std::locale::facet const * * x)
{	
	return _Getcat(x);	
}
void stD::_String_basE::_XraN () const
{
  // std::_String_base::_Xran ();
}

void stD::_String_basE::_XleN () const
{
    //std::_String_base::_Xlen ();
}

void stD::_String_basE::_AddStD()
{
	std::ios_base::_Addstd((std::ios_base*)this);
}

void stD::ios_basE::_AddstD()
{
	std::ios_base::_Addstd((std::ios_base*)this);
}

__declspec(dllexport) LARGE_INTEGER
__stdcall
EnlargedUnsignedMultiply (
    ULONG Multiplicand,
    ULONG Multiplier
    )
{
	LARGE_INTEGER ret;
	__int64 i1 = Multiplicand;
	__int64 i2= Multiplier;
	ret.QuadPart=i1*i2;
	return ret;
}
#define NODLLMAIN
//mfm 30Sep08 - do we need a dllMain too???
#ifdef NODLLMAIN
#else
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
#endif
double teststaticlib()
{

	return 45.6;
}