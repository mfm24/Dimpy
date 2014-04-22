//
// Copyright (c) 1995 Gatan Inc.
// All rights reserved.
//

#ifndef __CHECK_PLUGINFRAMEWORK__
#define __CHECK_PLUGINFRAMEWORK__

//
// This implements a methodology for making sure that the clients of this
// library are compatible with the version of this library.
//
// By careful definition, you can make this library compatible with previous
// versions (after you've added a function, for instance).
//
// You can also make this library incompatible with previous versions by
// giving an error for older "__USES" definitions.
//

#ifndef _GATANPLUGIN_USES_LIBRARY_VERSION_MIN
	#if defined( _GATANPLUGIN_USES_LIBRARY_VERSION )
		#define _GATANPLUGIN_USES_LIBRARY_VERSION_MIN _GATANPLUGIN_USES_LIBRARY_VERSION
	#elif defined( __USES_PLUGINLIBRARY_VERSION_0002 )
		#define _GATANPLUGIN_USES_LIBRARY_VERSION_MIN 2
	#elif defined( __USES_PLUGINLIBRARY_VERSION_0001 )
		#define _GATANPLUGIN_USES_LIBRARY_VERSION_MIN 1
	#else
		#define _GATANPLUGIN_USES_LIBRARY_VERSION_MIN 0
	#endif
#endif // _GATANPLUGIN_USES_LIBRARY_VERSION_MIN

#ifndef _GATANPLUGIN_USES_LIBRARY_VERSION_MAX
	#if defined( _GATANPLUGIN_USES_LIBRARY_VERSION )
		#define _GATANPLUGIN_USES_LIBRARY_VERSION_MAX _GATANPLUGIN_USES_LIBRARY_VERSION
	#elif defined( __USES_PLUGINLIBRARY_VERSION_0002 )
		#define _GATANPLUGIN_USES_LIBRARY_VERSION_MAX 2
	#elif defined( __USES_PLUGINLIBRARY_VERSION_0001 )
		#define _GATANPLUGIN_USES_LIBRARY_VERSION_MAX 1
	#else
		#define _GATANPLUGIN_USES_LIBRARY_VERSION_MAX 0
	#endif
#endif // _GATANPLUGIN_USES_LIBRARY_VERSION_MAX

#define _GATANPLUGIN_LIBRARY_VERSION 2
#define _GATANPLUGIN_LIBRARY_VERSION_VARIANT 2

#if ( ( _GATANPLUGIN_LIBRARY_VERSION < _GATANPLUGIN_USES_LIBRARY_VERSION_MIN ) || ( _GATANPLUGIN_LIBRARY_VERSION > _GATANPLUGIN_USES_LIBRARY_VERSION_MAX ) )
#error "Client not compatible with this library version."
#endif

#define DM_HEADER_VERSION 0x03060000
#define _GATANPLUGIN_DMHEADER_VERSION 0x03060000

#ifdef _GATAN_COMPILER_VISUAL_CPP

#if !_MT
#error "Set the C++ compiler options to generate Multithreaded code."
#endif

//#if _DLL
//#error "Set the C++ compiler options to generate non-DLL (statically linked) code."
//#endif

#endif	//_GATAN_COMPILER_VISUAL_CPP

#endif
