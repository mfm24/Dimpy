
#ifndef __DMPLUGINCOMUTILITY__
#define __DMPLUGINCOMUTILITY__

#define _GATAN_USE_STL_STRING

#include "DMPlugInLibrary.h"
#include "DMPlugInUtility.h"

#ifdef _GATAN_OS_WIN32


/*
** BSTR
**
**    Converting BSTR to DM::String
**       Because 'DM::String' contains a constructor from 'wchar_t *', 'DM::String' can
**    be constructed directly frm a 'BSTR' using
**
**       BSTR       str_BSTR = ...
**       DM::String str_DM( str_BSTR );
**
**    However, that constructor will get the size of the string by looking for a NULL terminator.
**    If you want the size to come from 'SysStringLen', you can use
**
**       DM::String str_DM( str_BSTR, SysStringLen( str_BSTR ) );
**
**    ( The constructor cannot know to use 'SysStringLen' by default because 'BSTR' has the
**    same type as 'wchar_t *', so the constructor cannot know that the pointer is a 'BSTR' with
**    its length stored before the pointer ).
**
*/

#include "atlbase.h"

namespace Gatan
{

	/*
	** class bstr_string_proxy
	**
	**    Implements the functions needed to construct a 'string_proxy_t<CharType>' from a
	** 'std::basic_string<CharType,TraitsType,Allocator>'.
	**
	*/
	inline uncchar get_string_char_type( const CComBSTR &str );

	inline void construct_char_range( const CComBSTR &str, uncchar_range &dst_char_range )
	{
		const uncchar *str_beg = (const uncchar *) (const wchar_t *) str;
		dst_char_range.construct( str_beg, str_beg + str.Length() );
	}

	class CComBSTR_string_proxy
	{
	public:
		typedef CComBSTR                                base_string_type;
		typedef uncchar                                 char_type;
		typedef std::char_traits<char_type>             traits_type;
		typedef uncchar_string_proxy                    string_proxy_type;
		typedef string_proxy_type::size_type            size_type;
		typedef string_proxy_type::string_token_type    string_token_type;
		typedef string_proxy_type::range_buffer_type    range_buffer_type;
		typedef string_proxy_type::range_type           range_type;
	private:
		static void      *lock_char_range_proc(   string_token_type str_token, size_type des_str_size, range_buffer_type &locked_range )
		{
			CComBSTR *old_str_bstr  = static_cast<base_string_type *>( str_token );
			size_type old_str_size  = old_str_bstr->Length();

			BSTR lock_str_bstr      = old_str_bstr->Detach();
			size_type act_str_size  = old_str_size;
			size_type copy_size     = std::min( old_str_size, des_str_size );
			if ( des_str_size > old_str_size )
			{
				BSTR new_lock_str_bstr     = ( des_str_size == 0 ) ? NULL : SysAllocStringLen( NULL, des_str_size );
				if ( new_lock_str_bstr != NULL )
				{
					traits_type::copy( new_lock_str_bstr, lock_str_bstr, copy_size );
					if ( lock_str_bstr != NULL ) { SysFreeString( lock_str_bstr ); }
					lock_str_bstr = new_lock_str_bstr;
					act_str_size  = des_str_size;
				}
			}

			locked_range.construct( lock_str_bstr, lock_str_bstr + copy_size, lock_str_bstr + act_str_size );
			return static_cast<void *>( lock_str_bstr );
		}
		static void       unlock_char_range_proc( string_token_type str_token, void *lock_data, const range_buffer_type &locked_range )
		{
			BSTR lock_str_bstr = static_cast<BSTR>( lock_data );
			static_cast<base_string_type *>( str_token )->Attach( lock_str_bstr );
		}
		static size_type  assign_char_range_proc( string_token_type str_token, const range_type &range )
		{
			size_type act_size_assign = 0;
			static_cast<base_string_type *>( str_token )->Empty();
			static_cast<base_string_type *>( str_token )->Append( range.begin(), range.size() );
			return static_cast<base_string_type *>( str_token )->Length();;
		}
		static void       extract_char_range_proc( string_token_type str_token, range_type &range )
		{
			construct_char_range( *static_cast<base_string_type *>( str_token ), range );
		}
	public:
		static void construct_string_proxy( base_string_type &str, string_proxy_type &str_proxy )
		{
			str_proxy.construct( static_cast<void *>( &str ), &lock_char_range_proc
			                   , &unlock_char_range_proc, &assign_char_range_proc, &extract_char_range_proc );
		}
	};

	inline void construct_string_proxy( CComBSTR &str, uncchar_string_proxy &str_proxy )
	{
		CComBSTR_string_proxy::construct_string_proxy( str, str_proxy );
	}
}

#include "comdef.h"

namespace Gatan
{

	/*
	** class bstr_string_proxy
	**
	**    Implements the functions needed to construct a 'string_proxy_t<CharType>' from a
	** 'std::basic_string<CharType,TraitsType,Allocator>'.
	**
	*/
	inline uncchar get_string_char_type( const _bstr_t &str );

	inline void construct_char_range( const _bstr_t &str, uncchar_range &dst_char_range )
	{
		const uncchar *str_beg = (const uncchar *) (const wchar_t *) str;
		dst_char_range.construct( str_beg, str_beg + str.length() );
	}

	class bstr_string_proxy
	{
	public:
		typedef _bstr_t                                 base_string_type;
		typedef uncchar                                 char_type;
		typedef std::char_traits<char_type>             traits_type;
		typedef uncchar_string_proxy                    string_proxy_type;
		typedef string_proxy_type::size_type            size_type;
		typedef string_proxy_type::string_token_type    string_token_type;
		typedef string_proxy_type::range_buffer_type    range_buffer_type;
		typedef string_proxy_type::range_type           range_type;
	private:
		static void      *lock_char_range_proc(   string_token_type str_token, size_type des_str_size, range_buffer_type &locked_range )
		{
			_bstr_t *old_str_bstr  = static_cast<base_string_type *>( str_token );
			size_type copy_size    = std::min( des_str_size, (size_type) old_str_bstr->length() );
			BSTR lock_str_bstr     = SysAllocStringLen( NULL, des_str_size );
			if ( lock_str_bstr == NULL ) { _com_issue_error(E_OUTOFMEMORY); }

			if ( copy_size != 0 )
			{
				traits_type::copy( (char_type *) lock_str_bstr, (const char_type *) (const wchar_t *) *old_str_bstr, copy_size );
			}
			locked_range.construct( lock_str_bstr, lock_str_bstr + copy_size, lock_str_bstr + des_str_size );
			return static_cast<void *>( lock_str_bstr );
		}
		static void       unlock_char_range_proc( string_token_type str_token, void *lock_data, const range_buffer_type &locked_range )
		{
			BSTR lock_str_bstr = static_cast<BSTR>( lock_data );
			*static_cast<base_string_type *>( str_token ) = _bstr_t( lock_str_bstr, FALSE );
		}
		static size_type  assign_char_range_proc( string_token_type str_token, const range_type &range )
		{
			size_type act_size_assign = 0;
			BSTR new_str_bstr = SysAllocStringLen( (const wchar_t *) range.begin(), range.size() );
			if ( new_str_bstr != NULL )
			{
				// Technically, 
				*static_cast<base_string_type *>( str_token ) = _bstr_t( new_str_bstr, FALSE );
				act_size_assign = range.size();
			}
			else
			{
				*static_cast<base_string_type *>( str_token ) = _bstr_t();
				act_size_assign = 0;
			}
			return act_size_assign;
		}
		static void       extract_char_range_proc( string_token_type str_token, range_type &range )
		{
			construct_char_range( *static_cast<base_string_type *>( str_token ), range );
		}
	public:
		static void construct_string_proxy( base_string_type &str, string_proxy_type &str_proxy )
		{
			str_proxy.construct( static_cast<void *>( &str ), &lock_char_range_proc
			                   , &unlock_char_range_proc, &assign_char_range_proc, &extract_char_range_proc );
		}
	};

	inline void construct_string_proxy( _bstr_t &str, uncchar_string_proxy &str_proxy )
	{
		bstr_string_proxy::construct_string_proxy( str, str_proxy );
	}
}

/*
**
*/

namespace Gatan
{
	namespace PlugIn
	{
		class DMPlugInCOMUtilityLibrary
		{
		public:
			void Initialize( PlugInMain *plugin );
			void Deinitialize( PlugInMain *plugin );
		};

		extern void COM_HandleError( const DM::String &error_str, const GUID &guid );
		extern void COM_ThrowIfFailure( HRESULT hr );

		#define COM_ENTRY( COM_GUID ) \
			::Gatan::PlugIn::DM_PlugInEnv __dm_env;\
			HRESULT     __result = E_FAIL;\
			const GUID  &__guid = COM_GUID;\
			try {\
				__result = S_OK;\

		#define COM_EXIT \
			}\
			catch ( const exception &ex )\
			{\
				std::string error_str = ex.what();\
				::Gatan::PlugIn::COM_HandleError( DM::String( 0, error_str ), __guid );\
				__result = E_FAIL;\
			}\
			catch (...)\
			{\
				std::string error_str = "Unknown error";\
				::Gatan::PlugIn::COM_HandleError( DM::String( 0, error_str ), __guid );\
				__result = E_FAIL;\
			}\
			__dm_env->clear_exception();\
			return __result;\


		#if defined(_ATL) && ( _ATL_VER >= 0x0700 )
		namespace COM
		{
			/*
			** bool GetDigitalMicrographApplicationPath
			**
			**    - Look for a DigitalMicrograph application associated with this plugin.
			**      This can be called when the plugin is loaded by an application other
			**      than DigitalMicrograph, for example during registration, so it has to
			**      use hueristics. It looks first for an application in one directory up
			**      named 'DigitalMicrograph.exe', and if it does not find this it looks
			**      for registry entries set up by an installation of DigitalMicrograph.
			**      If it finds an application, it returns 'true' and places the path
			**      for that application in 'path', otherwise it returns 'false' and
			**      does not modify 'path'.
			**
			*/
			bool GetDigitalMicrographApplicationPath_Proxy( const __wchar_t_char_string_proxy &path );
			bool GetDigitalMicrographApplicationPath_Proxy( const uint16_char_string_proxy &path );
			template <typename string_type> inline bool GetDigitalMicrographApplicationPath( string_type &str )
			{
				char_range_traits<string_type>::string_proxy_type str_proxy;
				construct_string_proxy( str, str_proxy );
				return GetDigitalMicrographApplicationPath_Proxy( str_proxy );
			}

			/*
			** class CAtlDMPlugInModuleT<T>
			**
			**    This is a utility class that facilitates creating a plugin that
			** serves a COM object using ATL.  We cannot use the existing module
			** types because they assume that the module is either for a local
			** server in an executable or an in-process server in a DLL, not
			** what is in affect a local server in a DLL.
			** 
			**    AddCommonRGSReplacements - this is used to adjust the rgs script used
			**       to register the served COM objects by replacing instances of
			**       'DigitalMicrographApplication' with the path to the DigitalMicrograph
			**       executable.
			**
			**
			**
			*/
			template <class T> 
			class ATL_NO_VTABLE CAtlDMPlugInModuleT : public CAtlModuleT<T>
			{
			public:
				CAtlDMPlugInModuleT() throw()
				{
			#if !defined(_ATL_NO_COM_SUPPORT)
					_AtlComModule.ExecuteObjectMain(true);
			#endif	//  !defined(_ATL_NO_COM_SUPPORT)
				}

				~CAtlDMPlugInModuleT() throw()
				{
			#ifndef _ATL_NO_COM_SUPPORT
					_AtlComModule.ExecuteObjectMain(false);
			#endif //  !defined(_ATL_NO_COM_SUPPORT)
					Term();
				}
				HRESULT RegisterClassObjects(DWORD dwClsContext, DWORD dwFlags) throw()
				{
					return AtlComModuleRegisterClassObjects(&_AtlComModule, dwClsContext, dwFlags);
				}
				HRESULT RevokeClassObjects() throw()
				{
					return AtlComModuleRevokeClassObjects(&_AtlComModule);
				}

				virtual HRESULT AddCommonRGSReplacements(IRegistrarBase *pRegistrar) throw()
				{
					_bstr_t dm_path( L"C:\\Program Files\\Gatan\\DigitalMicrograph\\DigitalMicrograph.exe" );
					GetDigitalMicrographApplicationPath( dm_path );
					return pRegistrar->AddReplacement(L"DigitalMicrographApplication", dm_path );
				}

				HRESULT DllRegisterServer( BOOL bRegTypeLib = TRUE )
				{
					HRESULT hr = S_OK;

					T* pT = static_cast<T*>(this);

					if ( SUCCEEDED(hr) )
					{
						hr = pT->RegisterServer( bRegTypeLib );
					}

					if ( SUCCEEDED(hr) )
					{
						Term();
					}

					return hr;
				}

				/////////////////////////////////////////////////////////////////////////////
				// DllUnregisterServer - Removes entries from the system registry

				HRESULT DllUnregisterServer( BOOL bUnRegTypeLib = TRUE )
				{
 					HRESULT hr = S_OK;

					T* pT = static_cast<T*>(this);

					if ( SUCCEEDED(hr) )
					{
						hr = pT->UnregisterServer( bUnRegTypeLib );
					}

					if ( SUCCEEDED(hr) )
					{
						Term();
					}

					return hr;
				}
			};
		}

		#endif // defined(_ATL) && ( _ATL_VER >= 0x0700 )
	}
}

namespace Gatan
{
	namespace DM
	{
		namespace COM
		{
			bool ConvertVARTYPEToImageDataType( VARTYPE var_type, ulong &img_data_type_out );
			bool ConvertImageDataTypeToVARTYPE( ulong img_data_type, VARTYPE &var_type_out );

			Image NewImageFromSafeArray( const String &img_name, SAFEARRAY *safe_array, bool is_utility );
		}
	}
}

#endif // _GATAN_OS_WIN32

#endif // __GATANPLUGINCOMUTILITY__
