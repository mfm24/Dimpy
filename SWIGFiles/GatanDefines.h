
#ifndef __GATANDEFINES__
#define __GATANDEFINES__

/* Options
 *
 * _GATAN_OS
 *    _GATAN_OS_MACOS
 *    _GATAN_OS_WIN32			-- compiling for both Windows95 and WindowsNT
 *       _GATAN_OS_WIN95		-- defined if compiling only for Windows95
 *       _GATAN_OS_WINNT		-- defined if compiling only for WindowsNT
 *
 * _GATAN_COMPILER
 *    _GATAN_COMPILER_VISUAL_CPP
 *    _GATAN_COMPILER_METROWERKS
 *    _GATAN_COMPILER_IBM
 *    _GATAN_COMPILER_INTEL
 *    _GATAN_COMPILER_GCC
 *
 * _GATAN_ARCHITECTURE
 *    _GATAN_ARCHITECTURE_POWERPC
 *    _GATAN_ARCHITECTURE_X86
 *
 *
 *
 * _GATAN_USE_MFC							-- this must be defined by the project
 *
 * _GATAN_MACROS_DEFINED					-- defined if above macros are defined properly
 *
 */
 
 /* Compilation notes
  *
  * Compiler:
  *
  *    Intel:
  *
  *       -- The 'Visual C++' libraries are used, and the Intel compiler seems to see a bug: in '...\VC\include\Utility', 
  *          the 'istreambuf_iterator' and 'ostreambuf_iterator' definitions contain default template arguments, but so
  *          do the forward declarations of these templates in '...\VC\include\iosfwd', so we comment out those in 'Utility'
  *          Same for:
  *             -- 'basic_streambuf' in 'streambuf'
  *             -- 'basic_ios' in 'ios'
  *             -- 'basic_istream', 'basic_iostream' in 'istream'
  *             -- 'basic_ostream' in 'ostream'
  *       -- Add '-Qwd654,111,68 -GR' to 'icl.cfg' file in same directory as 'icl.exe'
  *             654 -- overload virtual function "%1" is only partially overridden in class "%2"
  *             111 -- statement is unreachable
  *             68  -- integer conversion resulted in a change of sign			( when 'tmed_ALL' is converted to 'uint32' )
  *          -GR    -- enable RTTI
  *
  */

#ifndef _GATAN_USE_BOOST
	#define _GATAN_USE_BOOST		// BOOST is now required for FOUNDATION to build
#endif // _GATAN_USE_BOOST

#ifdef _GATAN_USE_BOOST

	#include <boost/config.hpp>

#endif // _GATAN_USE_BOOST

#ifndef _GATAN_MACROS_DEFINED

#if defined( __IBMCPP__ )

	#define _GATAN_COMPILER_IBM
	#define _GATAN_COMPILER_VERSION     __IBMCPP__
	#define _GATAN_ARCHITECTURE_X86
	#define _GATAN_ARCHITECTURE_VERSION _M_IX86

	#define _GATAN_OS_WIN32
	
	#ifdef __cplusplus
		#define _GATAN_LANGUAGE_CPP
	#else
		#define _GATAN_LANGUAGE_C
	#endif

#elif defined( __ICL ) || defined(__INTEL_COMPILER)

	/*
	**
	** BOOST
	**    - For 1.29.0, must modify 'boost/config/compiler/intel.hpp' to avoid warning.
	*/
	#define _GATAN_STL_VISUAL_CPP
	#define _GATAN_STL_VERSION _MSC_VER
	
	#define _GATAN_COMPILER_INTEL
	#define _GATAN_COMPILER_VERSION BOOST_INTEL_CXX_VERSION
	#define _GATAN_ARCHITECTURE_X86
	#define _GATAN_ARCHITECTURE_VERSION _M_IX86
	
	#define _GATAN_OS_WIN32
	
	#ifdef __cplusplus
		#define _GATAN_LANGUAGE_CPP
	#else
		#define _GATAN_LANGUAGE_C
	#endif

	// Hack for now because argument lookup does not seem to work for templates
	// like 'get_string_char_type' ( for std::basic_string or std::vector )
	#define BOOST_NO_ARGUMENT_DEPENDENT_LOOKUP

#elif defined( _MSC_VER ) && !defined( __MWERKS__ )

	#define _GATAN_STL_VISUAL_CPP
	#define _GATAN_STL_VERSION _MSC_VER
	
	#define _GATAN_COMPILER_VISUAL_CPP
	#define _GATAN_COMPILER_VERSION    _MSC_VER
	#define _GATAN_ARCHITECTURE_X86
	#define _GATAN_ARCHITECTURE_VERSION _M_IX86

	#define _GATAN_OS_WIN32
	
	#ifdef __cplusplus
		#define _GATAN_LANGUAGE_CPP
	#else
		#define _GATAN_LANGUAGE_C
	#endif

#elif defined( __MWERKS__ )

	#define _GATAN_STL_METROWERKS
	#define _GATAN_STL_VERSION __MSL__
	
	#define _GATAN_COMPILER_METROWERKS
	#define _GATAN_COMPILER_VERSION    __MWERKS__

	#if defined(__INTEL__)
		#define _GATAN_ARCHITECTURE_X86
		#define _GATAN_OS_WIN32
	#else
		#if defined(__POWERPC__) || defined(powerc) || defined(__powerc) || defined( GENERATINGPOWERPC )
			#define _GATAN_ARCHITECTURE_POWERPC
		#else
			#error 68K architecture not supported.
		#endif
		#define _GATAN_OS_MACOS
	#endif

	#ifdef __cplusplus
		#define _GATAN_LANGUAGE_CPP
	#else
		#define _GATAN_LANGUAGE_C
	#endif

#elif defined( __MRC__ )

	#define _GATAN_STL_METROWERKS
	#define _GATAN_STL_VERSION __MSL__

	#define _GATAN_COMPILER_MRCPP
	#define _GATAN_COMPILER_VERSION    __MRC__
	
	#if defined( __POWERPC ) || defined( powerpc ) || defined( __powerpc )
		#define _GATAN_ARCHITECTURE_POWERPC
	#else
		#error 68K architecture not supported.
	#endif

	#ifdef __cplusplus
		#define _GATAN_LANGUAGE_CPP
	#else
		#define _GATAN_LANGUAGE_C
	#endif

#elif defined( __GNUG__ )

#if defined(__i386__)
	#define _GATAN_ARCHITECTURE_X86
	#define _GATAN_OS_WIN32
//	#define _GATAN_ARCHITECTURE_VERSION _M_IX86
#elif defined( __powerpc__ ) || defined( __powerpc ) || defined( __POWERPC__ ) || defined( __ppc__ )
	#define _GATAN_ARCHITECTURE_POWERPC
	#define _GATAN_OS_MACOS
#else
    #warning "Unknown platform system"
#endif

	#define _GATAN_COMPILER_GCC
	#define _GATAN_COMPILER_VERSION __GNUC_MINOR__

    #ifdef _GATAN_OS_MACOS
        #define _GATAN_STL_GLIBCPP
    #else
        #define _GATAN_STL_STLPORT
    #endif

	#ifdef __cplusplus
		#define _GATAN_LANGUAGE_CPP
	#else
		#define _GATAN_LANGUAGE_C
	#endif

#else

	#define _GATAN_ARCHITECTURE_POWERPC
	#define _GATAN_OS_MACOS

	#ifdef __cplusplus
		#define _GATAN_LANGUAGE_CPP
	#else
		#define _GATAN_LANGUAGE_C
	#endif

#endif

// Define macro indicating byte ordering
#if defined( _GATAN_ARCHITECTURE_POWERPC )
	#define _GATAN_BIG_ENDIAN
#elif defined( _GATAN_ARCHITECTURE_X86 )
	#define _GATAN_LITTLE_ENDIAN
#endif // defined( _GATAN_ARCHITECTURE )

#define _GATAN_MACROS_DEFINED

#endif // _GATAN_MACROS_DEFINED

// The following avoids a visual-C++ compiler bug that doesn't allow
// 'OS::X::' to be used inside a class derived from 'OX::X'
#if defined( _GATAN_COMPILER_VISUAL_CPP )
	#define _GATAN_COMPILER_BASECLASS_QUALIFY( BASE )
#else
	#define _GATAN_COMPILER_BASECLASS_QUALIFY( BASE ) BASE::
#endif // defined( _GATAN_COMPILER )

#if    defined( _GATAN_COMPILER_VISUAL_CPP ) || defined( _GATAN_COMPILER_INTEL ) \
    || defined( _GATAN_COMPILER_GCC ) || ( defined( _GATAN_COMPILER_METROWERKS ) && ( _GATAN_COMPILER_VERSION >= 0x2100 ) )
	#define _GATAN_COMPILER_DONT_USE_TEMPLATE_COMPARISON_OPERATORS
#endif

#if defined( _GATAN_COMPILER_VISUAL_CPP ) || defined( _GATAN_COMPILER_INTEL )
	#define _GATAN_COMPILER_SUPPORTS_NAMESPACE
#elif defined( _GATAN_COMPILER_METROWERKS ) && ( _GATAN_COMPILER_VERSION >= 0x2100 )
	#define _GATAN_COMPILER_SUPPORTS_NAMESPACE
#elif defined( _GATAN_COMPILER_MRCPP ) && ( _GATAN_COMPILER_VERSION >= 0x0400 )
	#define _GATAN_COMPILER_SUPPORTS_NAMESPACE
#endif

#if defined( _GATAN_COMPILER_VISUAL_CPP ) || defined( _GATAN_COMPILER_INTEL )
	#define _GATAN_STL_ALLOCATOR_HAS_TWO_ARGS
#endif

// Microsoft's new handler differs from the C++ standard
#ifdef _GATAN_STL_VISUAL_CPP
#define _GATAN_USE_MICROSOFT_NEW_HANDLER
#endif // _GATAN_STL_VISUAL_CPP

/*
**
** _GATAN_COMPILER_REQUIRE_TEMPLATE_ARGUMENTS_IN_BASE_SPECIFIER
**
**    - In a template class, if the template class name appears in the base class declarations
**      ( e.g. as a template argument ), define this if the template arguments must be specified.
*/

// Disable certain warnings
#if defined( _GATAN_COMPILER_METROWERKS )
	#pragma showmessagenumber on
	#pragma warning off (10439)
	#if ( _GATAN_COMPILER_VERSION >= 0x2100 )
		#pragma warn_implicitconv off				// This warns on many places in standard libraries
		#pragma warn_notinlined   off
	#endif // _GATAN_COMPILER_VERSION
	#if ( _GATAN_COMPILER_VERSION >= 0x2300 )
		#define _GATAN_COMPILER_REQUIRES_TYPENAMES
	#endif // _GATAN_COMPILER_VERSION
	
	#define _GATAN_COMPILER_REQUIRE_TEMPLATE_ARGUMENTS_IN_BASE_SPECIFIER
#endif // defined( _GATAN_COMPILER_METROWERKS )

#if defined( _GATAN_COMPILER_VISUAL_CPP )
	#if ( _GATAN_COMPILER_VERSION >= 1300)
		#define _GATAN_THROW_0 throw()
	#else
		#define _GATAN_THROW_0
	#endif // _GATAN_COMPILER_VERSION
#elif defined( _GATAN_COMPILER_METROWERKS ) || defined( _GATAN_COMPILER_INTEL )
	#define _GATAN_THROW_0 throw()
#elif defined( _GATAN_COMPILER_GCC )
	#define _GATAN_THROW_0 throw()
#elif defined( _GATAN_COMPILER_MRCPP )
	#define _GATAN_THROW_0 throw()
#endif

#if defined( _GATAN_COMPILER_GCC )
	#define _GATAN_COMPILER_REQUIRES_TYPENAMES
	#define _GATAN_COMPILER_REQUIRE_TEMPLATE_ARGUMENTS_IN_BASE_SPECIFIER
#endif

#if defined(_GATAN_STL_GLIBCPP)
    // Place C99 numeric functions in std namespace
    #define _GLIBCPP_USE_C99    1
    // Tell the STL to support wide characters
//   #define _GLIBCPP_HAVE_WCHAR_H 1
//   #define _GLIBCPP_USE_WCHAR_T 1
#endif

// Enable wide character support
#if defined( _GATAN_COMPILER_METROWERKS ) && ( _GATAN_COMPILER_VERSION >= 0x2100 )
	#define MSIPL_WCHART
#endif // defined( _GATAN_COMPILER_METROWERKS )

#ifndef _GATAN_DONT_DISABLE_WARNINGS

	#if defined( _GATAN_COMPILER_VISUAL_CPP )

		#pragma warning( disable: 4068 )	// unknown pragmas
		#pragma warning( disable: 4100 )	// unused variables
		#pragma warning( disable: 4101 )	// unreferenced local variables
		#pragma warning( disable: 4190 )	// return C++ object from C-linked function
		#pragma warning( disable: 4244 )	// conversions between int's
		#pragma warning( disable: 4305 )	// truncation from 'const int' to 'char'
		#pragma warning( disable: 4309 )	// truncation of constant value
		#pragma warning( disable: 4065 )	// switch statement contains 'default' but no 'case' labels
		#pragma warning( disable: 4355 )	// 'this' : used in base member initializer list
		#pragma warning( disable: 4800 )	//  'unsigned char' : forcing value to bool 'true' or 'false' ( performance warning )
		#pragma warning( disable: 4786 )	//  '...' : identifier was truncated to '255' characters in the debug information
		#pragma warning( disable: 4503 )	//  '...' : 

	#endif
	
	#if defined( _GATAN_COMPILER_METROWERKS )
	
		#if ( _GATAN_COMPILER_VERSION >= 0x2100 )
			#pragma warn_implicitconv off
			#pragma warn_notinlined   off
		#endif // _GATAN_COMPILER_VERSION
		
	#endif // defined( _GATAN_COMPILER_METROWERKS )

#endif // _GATAN_DONT_DISABLE_WARNINGS

#if defined( _GATAN_COMPILER_REQUIRES_TYPENAMES )
#define _GATAN_COMPILER_TYPENAME typename
#else
#define _GATAN_COMPILER_TYPENAME
#endif // _GATAN_COMPILER_REQUIRES_TYPENAMES

#endif // __GATANDEFINES__

#ifndef _GATAN_COMPILER_BUG_FIXUPS
#define _GATAN_COMPILER_BUG_FIXUPS

#if defined( _GATAN_COMPILER_METROWERKS ) && !defined( _MSL_NO_MEMBER_TEMPLATE )
	#define _GATAN_STL_MAP_ALLOWS_TEMPLATE_ALLOCATOR
#endif	// ! _MSL_NO_MEMBER_TEMPLATE
#if    ( defined( _GATAN_COMPILER_VISUAL_CPP ) && ( _GATAN_COMPILER_VERSION >= 1300 ) )\
      || defined( _GATAN_COMPILER_GCC )
	#define _GATAN_STL_MAP_ALLOWS_TEMPLATE_ALLOCATOR
#endif //_GATAN_COMPILER_VISUAL_CPP

// Even if this header has been included once, ensure the macros haven't been redefined in the interim.

#if defined( _GATAN_COMPILER_VISUAL_CPP ) || defined( _GATAN_COMPILER_INTEL )
	#ifdef min
	#undef min
	#endif
	#ifdef max
	#undef max
	#endif
#endif // _GATAN_COMPILER

#if defined( _GATAN_COMPILER_VISUAL_CPP ) || defined( _GATAN_COMPILER_INTEL )
	#if ( defined( _GATAN_STL_VISUAL_CPP ) && ( _GATAN_STL_VERSION < 1300 ) )

		// VisualC++ does not define templates 'min' and 'max', instead calling them '_cpp_min' and '_cpp_max'.
		// Thus, to add some platform independence, we define the appropriate templates here. However, BOOST
		// also defines these, so don't redefine them if BOOST has already done so.
		#ifndef BOOST_NO_STD_MIN_MAX
			#include <algorithm>

			namespace std
			{
				template <class T> inline const T &min( const T &x, const T &y ) { return std::_cpp_min(x,y); }
				template <class T> inline const T &max( const T &x, const T &y ) { return std::_cpp_max(x,y); }
			}
		#endif // BOOST_NO_STD_MIN_MAX
	
		// VisualC++ 5.0 does not place some standard c routines or other objects in 'std' as it should, so compensate
		#include <cstdlib>
		#include <cstring>
		#include <cmath>
		namespace std
		{
			using ::memset;
			using ::strlen;

			using ::calloc;
			using ::free;

			using ::fmod;
			using ::sqrt;
			using ::log;
			using ::log10;
			using ::exp;
			using ::pow;
			using ::floor;
			using ::ceil;
			using ::fabs;
			using ::labs;
			using ::abs;

			using ::vsprintf;
		}
		#define _GATAN_C_STL
	#else
		#define _GATAN_C_STL std::
	#endif // _GATAN_STL_*
#else
	#define _GATAN_C_STL std::
#endif // _GATAN_COMPILER

#if defined( _GATAN_COMPILER_VISUAL_CPP )
	#define gtn_force_inline __forceinline
#else // defined( _GATAN_COMPILER )
	#define gtn_force_inline inline
#endif

#endif // _GATAN_COMPILER_BUG_FIXUPS
