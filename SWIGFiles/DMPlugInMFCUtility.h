#ifndef __MFCPLUGINUTILITY__
#define __MFCPLUGINUTILITY__

#define _GATAN_USE_MFC
#define _GATANPLUGIN_USES_LIBRARY_VERSION 2

#include "DMPlugInLibrary.h"

namespace Gatan { namespace PlugIn
{
	using namespace Gatan;
	class MFCPlugInUtility
	{
	protected:
		static uint32 RegisterMFCPalette(const char *name, uint32 argument_3, uint32 argument_4 );
		static void UnregisterMFCPalette( uint32 argument_1 );
		uint32 RegisterMFCPalette(const std::string& Name, HINSTANCE hInst, CRuntimeClass* const pDialogRuntime)const
		{
			return RegisterMFCPalette(Name.c_str(), reinterpret_cast<uint32>(hInst), reinterpret_cast<uint32>(pDialogRuntime));
		}
	};
}}

#endif //#ifndef __MFCPLUGINUTILITY__
