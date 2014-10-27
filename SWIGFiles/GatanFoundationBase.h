
#ifndef __GATAN_FOUNDATIONBASE__
#define __GATAN_FOUNDATIONBASE__

#include "GatanDefines.h"
#include "GatanStringUtility.h"
#include "GatanTypes.h"

// GF stands for "Gatan Framework"

// Base exception class

#include <cstddef>		// For windows, make sure 'NULL' is define correctly ( as '0', not '((void *) 0)' )
#include <exception>
#include <new>			// for 'new_handler'

#if defined( _GATAN_COMPILER_VISUAL_CPP ) || defined( _GATAN_COMPILER_INTEL )
	// VisualC++ 5.0 does not place some standard c routines or other objects in 'std' as it should, so compensate
	namespace std
	{
		using ::new_handler;
	}
#endif // _GATAN_COMPILER

/*
** Include 'windows.h' here
**
*/
#ifdef _GATAN_OS_WIN32

	#ifndef _WIN32_WINNT
	#define _WIN32_WINNT 0x0500			// We are building for Windows2000
	#endif

	#ifndef WINVER
	#define WINVER 0x0500				// We are building for Windows2000
	#endif

	#ifdef _GATAN_USE_MFC

		#include "stdafx.h"					// this is a local file generated by VC++

		#ifdef USE_MT
		#include <afxmt.h>
		#endif

		#ifdef USE_STL
		#include <afxtempl.h>
		#endif

	#else

		#ifdef _GATAN_OS_WIN32 
	
			#if defined( _GATAN_COMPILER_VISUAL_CPP ) || defined( _GATAN_COMPILER_INTEL )

				#include <stdexcpt.h>

			#endif // defined( _GATAN_COMPILER_VISUAL_CPP )

			#include <windows.h>

		#endif	// _GATAN_OS_WIN32 

	#endif // _GATAN_USE_MFC

// Get rid of Godawful defines in 'windows.h'

	#ifdef min
	#undef min
	#endif
	#ifdef max
	#undef max
	#endif

	#ifdef _GATAN_USE_MFC
	#ifdef new
	#undef new
	#endif	// new
	#endif	// _GATAN_USE_MFC

#endif // _GATAN_OS_WIN32

/*
** Make sure these are defined before any system files are included.
**
*/
#ifdef _GATAN_OS_MACOS

//	#define TARGET_CARBON 1
	
    #ifndef __CARBON__
	#include <Carbon/Carbon.h>
    #endif

#endif // _GATAN_OS_MACOS

namespace Gatan
{
	typedef long ErrorId;
	typedef long ErrorDesc;

	typedef unsigned long ulong;
	typedef unsigned int  uint;
	typedef unsigned char octet;
	
	enum
	{
		  kError_General_None = 0
	 	, kError_UserAbort               = -128				// == 'userCanceledErr' on Mac

		, kError_Internal                = 28801
		, kError_PrintMessage            = 28802
		, kError_InternalMessage         = 28803
	  	, kError_OS                      = 28810
		, kError_COM                     = 28811
		, kError_MFC					 = 28812

		, kError_Internal_Unknown        = 0
	};

	enum AlertStyle
	{
		    kAlert_Stop
		  , kAlert_Caution
		  , kAlert_Note
		  , kAlert_Plain
	};
	enum AssertionQualification
	{
		  assertion_FATAL
		, assertion_EXCEPTION
		, assertion_CONTINUE
		, assertion_IGNORE
	};

	enum ByteOrder
	{
		  kByteOrderBigEndian       = 0
		, kByteOrderLittleEndian    = 1
#if defined( _GATAN_BIG_ENDIAN )
		, kByteOrderPlatform = kByteOrderBigEndian
#elif defined( _GATAN_LITTLE_ENDIAN )
		, kByteOrderPlatform = kByteOrderLittleEndian
#endif // _GATAN_*_ENDIAN
	};

	enum OperatingSystem
	{
		  os_UNKNOWN                = 0
		, os_MacOS                  = 1
		, os_Win32                  = 2
#if defined( _GATAN_OS_MACOS )
		, os_Platform               = os_MacOS
#elif defined( _GATAN_OS_WIN32 )
		, os_Platform               = os_Win32
#endif // _GATAN_*_ENDIAN
	};

	class gatan_exception : public std::exception
	{
	public:		
		virtual const char *what() const _GATAN_THROW_0 = 0;
		virtual void get_info( ErrorId &err_id, ErrorDesc &err_desc ) const = 0;
	public:
        gatan_exception() _GATAN_THROW_0 {}
        ~gatan_exception() _GATAN_THROW_0 {}
		static void get_exception_info( const std::exception &e, ErrorId &err_id, ErrorDesc &err_desc );
		static bool is_user_abort( const std::exception &e );
		static bool is_exception( const std::exception &e, ErrorId des_err_id );
		static bool is_exception( const std::exception &e, ErrorId des_err_id, ErrorDesc des_err_desc );
	};

	class std_gatan_exception : public gatan_exception
	{
	private:
		ErrorId   error;
		ErrorDesc context;
	public:
		std_gatan_exception( ErrorId error, ErrorDesc context = 0 ) _GATAN_THROW_0 : error( error ), context( context ) { }
        ~std_gatan_exception() _GATAN_THROW_0 {}

		virtual const char *what() const _GATAN_THROW_0;
		virtual void get_info( ErrorId &err_id, ErrorDesc &err_desc ) const;
	};
	
	class ErrorManager
	{
	public:
        virtual ~ErrorManager();
		virtual void  HandleExceptionError( ErrorId error, ErrorDesc desc );
		virtual void  HandleContinuableError( const std::exception &ex );
		virtual void  ShowAlert( ErrorId error, ErrorDesc desc, AlertStyle alertStyle ) const;
		virtual void  ReportError( const std::exception &ex );
		virtual bool  GetErrorString( ErrorId error, ErrorDesc desc, const char_string_proxy &err_str ) const;
		
		void HandleError( ErrorId error, ErrorDesc desc, AssertionQualification qual );
	};

	typedef ErrorManager *ErrorManagerToken;
	
	ErrorManagerToken RegisterErrorManager( ErrorManager *newManager );
	void              UnregisterErrorManager( ErrorManagerToken oldManagerToken );

	class NewHandlerInstaller
	{
	private:
		std::new_handler fOldNewHandler;
	public:
		NewHandlerInstaller();
		~NewHandlerInstaller();
		static void NewHandler();
	};

	void Throw( ErrorId errorId, ErrorDesc errorDesc = 0);			// pop a handler and return to it.
	void ThrowString( const char_range &message );
	void ThrowNotEnoughMemoryError();
	void ThrowInternalFailure();

	void HandleError( ErrorId errorId, ErrorDesc errorDesc, AssertionQualification qual );
	void PostError( const std::exception &ex );
	void ReportError( const std::exception &ex );
	void ShowAlert( ErrorId errorId, ErrorDesc errorDesc, AlertStyle alertStyle );
	bool GetErrorString( ErrorId error, ErrorDesc desc, const char_string_proxy &err_str );
	bool AssertionFailure(char *file, long line, char *expr, AssertionQualification qualification);
	void InternalFailure(const char_range &message);				// Throw an 'kError_InternalMessage' exception.

	inline void ThrowUnless( bool succeed, ErrorId error, ErrorDesc message = 0)
		{ if ( !succeed ) { Throw( error, message ); } }
	inline void ThrowStringUnless( bool succeed, const char_range &message )
		{ if ( !succeed ) { ThrowString( message ); } }
	inline void InternalFailureUnless( bool succeed, const char_range &message )
		{ if ( !succeed ) { InternalFailure( message ); } }
	inline void InternalFailureUnless( bool succeed, ErrorId error = kError_Internal, ErrorDesc message = 0 )
		{ if ( !succeed ) { Throw( error, message ); } }
	
	void ShowAlert( const char *message, AlertStyle alertStyle = kAlert_Note );

#if defined( _GATAN_OS_MACOS )
	namespace Macintosh {}
	namespace OS = Macintosh;
	namespace Mac = Macintosh;

	#define _GATAN_OS_NAMESPACE Macintosh

#elif defined( _GATAN_OS_WIN32 )
	namespace Win32 {}
	namespace OS = Win32;

	#define _GATAN_OS_NAMESPACE Win32
#endif // _GATAN_OS

}

#ifdef _GATAN_OS_WIN32

namespace Gatan
{
	namespace Win32
	{
		void ReportFailure_OS( DWORD errorId, Gatan::AssertionQualification qual  );

		inline void FailUnless_OS( bool succeed, Gatan::AssertionQualification qual = assertion_EXCEPTION )
			{ if ( !succeed ) { ReportFailure_OS( ::GetLastError(), qual ); } }
		inline void CheckFailure_OS( DWORD errorId, Gatan::AssertionQualification qual = assertion_EXCEPTION )
			{ if ( errorId != ERROR_SUCCESS ) { ReportFailure_OS( errorId, qual ); } }

		void ReportFailure_COM( HRESULT result, AssertionQualification qual = assertion_EXCEPTION );

		inline void CheckFailure_COM( HRESULT result, AssertionQualification qual = assertion_EXCEPTION )
			{ if ( !SUCCEEDED(result) ) { ReportFailure_COM( result, qual ); } }
	}
}

#endif // _GATAN_OS_WIN32

#ifdef _GATAN_OS_MACOS

namespace Gatan
{
	namespace Macintosh
	{
		void FailIfError_OSErr( OSErr error, Gatan::AssertionQualification qual );
		void FailIfError_OSStatus( OSStatus status, Gatan::AssertionQualification qual );
	}
}

#endif // _GATAN_OS_MACOS

//
// "Assertion" is a macro that throws an 'kError_InternalMessage' exception if it's argument is false.
//

#ifndef Assertion

#define Assertion(expression) \
	( (expression) ? true : (Gatan::AssertionFailure(__FILE__, __LINE__, #expression,Gatan::assertion_EXCEPTION)) )
	
#define QualifiedAssertion(expression,qualification) \
	( (expression) ? true : (Gatan::AssertionFailure(__FILE__, __LINE__, #expression,qualification)) )
	
#endif // Assertion

#endif // __GATAN_FOUNDATIONBASE__

