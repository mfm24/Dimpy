

//
// HAND MODIFICATIONS, CHRIS MEYER, SEP 09, 1995
//
// 1. Replace External32Bit crap with ""
// 2. Replace "ImageRef *image2" with "ImageRef *"
// 3. Replace "ImageRef *image1" with "ImageRef *"
// 4. Replace "ImageRef *image" with "ImageRef *"
// 5. Replace "FailLinkPtr" with "long"
// 6. Replace rest of argument problems by hand.
// 7. Remove printf from file.
//

#ifndef _GATAN_PLUGIN_BASE
#define _GATAN_PLUGIN_BASE

#define _GATAN_DIGITALMICROGRAPH_INTERFACE

/*------------------------------------------------------------------------------
#
# DMPluginLibraryDefs.h: Typedefs for function prototypes for callbacks to DM.
#
# 1/20/94 MLL
#
# Internal Version
#
------------------------------------------------------------------------------*/

typedef unsigned char   DM_Boolean;
typedef long            External32BitType;
typedef void            (*SystemIdleProc)();

#ifdef _GATAN_OS_MACOS
	
	typedef short           DM_FileReference;
	typedef char          **DM_Handle;

#endif // _GATAN_OS_MACOS

#ifdef _GATAN_OS_WIN32

	#include "wtypes.h"

	typedef HANDLE DM_Handle;
	typedef HANDLE DM_FileReference;

#endif // _GATAN_OS_WIN32
		

#if defined( _GATAN_LANGUAGE_CPP )

	#include <exception>

	#ifdef _GATAN_OS_MACOS
		#define _GATAN_C_LIBRARY_NAMESPACE std::
	#endif // _GATAN_OS_MACOS
	#ifdef _GATAN_OS_WIN32
		#define _GATAN_C_LIBRARY_NAMESPACE
	#endif // _GATAN_OS_WIN32

#elif defined( _GATAN_LANGUAGE_C )


#endif // defined( _GATAN_LANGUAGE_* )

#if defined( _GATAN_LANGUAGE_CPP )

class Gatan_Object;
class Gatan_Image;
class Gatan_Component;
class Gatan_ImageDisplay;
class Gatan_LinePlotImageDisplay;
class Gatan_RasterImageDisplay;
class Gatan_SurfacePlotImageDisplay;
class Gatan_TagGroup;
class Gatan_Window;
class Gatan_RegionOfInterest;
class Gatan_ImageDocument;
class Gatan_ScriptObject;
class Gatan_String;
class Gatan_Throwable;
class Gatan_Function;
class Gatan_ScriptClass;

#ifdef __GATAN_REFPOINTER__

typedef Gatan::OneRef<Gatan_Object>                      Gatan_Object_1Ref;
typedef Gatan::OneRef<Gatan_Image>                       Gatan_Image_1Ref;
typedef Gatan::OneRef<Gatan_Component>                   Gatan_Component_1Ref;
typedef Gatan::OneRef<Gatan_ImageDisplay>                Gatan_ImageDisplay_1Ref;
typedef Gatan::OneRef<Gatan_LinePlotImageDisplay>        Gatan_LinePlotImageDisplay_1Ref;
typedef Gatan::OneRef<Gatan_RasterImageDisplay>          Gatan_RasterImageDisplay_1Ref;
typedef Gatan::OneRef<Gatan_SurfacePlotImageDisplay>     Gatan_SurfacePlotImageDisplay_1Ref;
typedef Gatan::OneRef<Gatan_TagGroup>                    Gatan_TagGroup_1Ref;
typedef Gatan::OneRef<Gatan_Window>                      Gatan_Window_1Ref;
typedef Gatan::OneRef<Gatan_RegionOfInterest>            Gatan_RegionOfInterest_1Ref;
typedef Gatan::OneRef<Gatan_ImageDocument>               Gatan_ImageDocument_1Ref;
typedef Gatan::OneRef<Gatan_ScriptObject>                Gatan_ScriptObject_1Ref;
typedef Gatan::OneRef<Gatan_String>                      Gatan_String_1Ref;
typedef Gatan::OneRef<Gatan_Throwable>                   Gatan_Throwable_1Ref;
typedef Gatan::OneRef<Gatan_Function>                    Gatan_Function_1Ref;
typedef Gatan::OneRef<Gatan_ScriptClass>                 Gatan_ScriptClass_1Ref;

#else

class Gatan_Object_1Ref;
class Gatan_Image_1Ref;
class Gatan_Component_1Ref;
class Gatan_ImageDisplay_1Ref;
class Gatan_LinePlotImageDisplay_1Ref;
class Gatan_RasterImageDisplay_1Ref;
class Gatan_SurfacePlotImageDisplay_1Ref;
class Gatan_TagGroup_1Ref;
class Gatan_Window_1Ref;
class Gatan_RegionOfInterest_1Ref;
class Gatan_ImageDocument_1Ref;
class Gatan_ScriptObject_1Ref;
class Gatan_String_1Ref;
class Gatan_Throwable_1Ref;
class Gatan_Function_1Ref;
class Gatan_ScriptClass_1Ref;

#endif // __GATAN_REFPOINTER__

typedef Gatan_Object                  *DM_ObjectToken;
typedef Gatan_Image                   *DM_ImageToken;
typedef Gatan_Component               *DM_ComponentToken;
typedef Gatan_ImageDisplay            *DM_ImageDisplayToken;
typedef Gatan_LinePlotImageDisplay    *DM_LinePlotImageDisplayToken;
typedef Gatan_RasterImageDisplay      *DM_RasterImageDisplayToken;
typedef Gatan_SurfacePlotImageDisplay *DM_SurfacePlotImageDisplayToken;
typedef Gatan_TagGroup                *DM_TagGroupToken;
typedef Gatan_Window                  *DM_WindowToken;
typedef Gatan_RegionOfInterest        *DM_RegionOfInterestToken;
typedef Gatan_ImageDocument           *DM_ImageDocumentToken;
typedef Gatan_ScriptObject            *DM_ScriptObjectToken;
typedef Gatan_String                  *DM_StringToken;
typedef Gatan_Throwable               *DM_ThrowableToken;
typedef Gatan_Function                *DM_FunctionToken;
typedef Gatan_ScriptClass             *DM_ScriptClassToken;

typedef Gatan_Object_1Ref                  *DM_ObjectToken_1Ref;
typedef Gatan_Image_1Ref                   *DM_ImageToken_1Ref;
typedef Gatan_Component_1Ref               *DM_ComponentToken_1Ref;
typedef Gatan_ImageDisplay_1Ref            *DM_ImageDisplayToken_1Ref;
typedef Gatan_LinePlotImageDisplay_1Ref    *DM_LinePlotImageDisplayToken_1Ref;
typedef Gatan_RasterImageDisplay_1Ref      *DM_RasterImageDisplayToken_1Ref;
typedef Gatan_SurfacePlotImageDisplay_1Ref *DM_SurfacePlotImageDisplayToken_1Ref;
typedef Gatan_TagGroup_1Ref                *DM_TagGroupToken_1Ref;
typedef Gatan_Window_1Ref                  *DM_WindowToken_1Ref;
typedef Gatan_RegionOfInterest_1Ref        *DM_RegionOfInterestToken_1Ref;
typedef Gatan_ImageDocument_1Ref           *DM_ImageDocumentToken_1Ref;
typedef Gatan_ScriptObject_1Ref            *DM_ScriptObjectToken_1Ref;
typedef Gatan_String_1Ref                  *DM_StringToken_1Ref;
typedef Gatan_Throwable_1Ref               *DM_ThrowableToken_1Ref;
typedef Gatan_Function_1Ref                *DM_FunctionToken_1Ref;
typedef Gatan_ScriptClass_1Ref             *DM_ScriptClassToken_1Ref;

#define _GATANPLUGIN_USINGNAMESPACE
#define _GATANPLUGIN_NAMESPACE Gatan::PlugIn::

#elif defined( _GATAN_LANGUAGE_C )

struct Gatan_Object;
struct Gatan_Image;
struct Gatan_Component;
struct Gatan_ImageDisplay;
struct Gatan_LinePlotImageDisplay;
struct Gatan_RasterImageDisplay;
struct Gatan_SurfacePlotImageDisplay;
struct Gatan_TagGroup;
struct Gatan_Window;
struct Gatan_RegionOfInterest;
struct Gatan_ImageDocument;
struct Gatan_ScriptObject;
struct Gatan_String;
struct Gatan_Throwable;
struct Gatan_Function;
struct Gatan_ScriptClass;

typedef struct Gatan_Object                  *DM_ObjectToken;
typedef struct Gatan_Image                   *DM_ImageToken;
typedef struct Gatan_Component               *DM_ComponentToken;
typedef struct Gatan_ImageDisplay            *DM_ImageDisplayToken;
typedef struct Gatan_LinePlotImageDisplay    *DM_LinePlotImageDisplayToken;
typedef struct Gatan_RasterImageDisplay      *DM_RasterImageDisplayToken;
typedef struct Gatan_SurfacePlotImageDisplay *DM_SurfacePlotImageDisplayToken;
typedef struct Gatan_TagGroup                *DM_TagGroupToken;
typedef struct Gatan_Window                  *DM_WindowToken;
typedef struct Gatan_RegionOfInterest        *DM_RegionOfInterestToken;
typedef struct Gatan_ImageDocument           *DM_ImageDocumentToken;
typedef struct Gatan_ScriptObject            *DM_ScriptObjectToken;
typedef struct Gatan_String                  *DM_StringToken;
typedef struct Gatan_Throwable               *DM_ThrowableToken;
typedef struct Gatan_Function                *DM_FunctionToken;
typedef struct Gatan_ScriptClass             *DM_ScriptClassToken;

typedef struct Gatan_Object                  *DM_ObjectToken_1Ref;
typedef struct Gatan_Image                   *DM_ImageToken_1Ref;
typedef struct Gatan_Component               *DM_ComponentToken_1Ref;
typedef struct Gatan_ImageDisplay            *DM_ImageDisplayToken_1Ref;
typedef struct Gatan_LinePlotImageDisplay    *DM_LinePlotImageDisplayToken_1Ref;
typedef struct Gatan_RasterImageDisplay      *DM_RasterImageDisplayToken_1Ref;
typedef struct Gatan_SurfacePlotImageDisplay *DM_SurfacePlotImageDisplayToken_1Ref;
typedef struct Gatan_TagGroup                *DM_TagGroupToken_1Ref;
typedef struct Gatan_Window                  *DM_WindowToken_1Ref;
typedef struct Gatan_RegionOfInterest        *DM_RegionOfInterestToken_1Ref;
typedef struct Gatan_ImageDocument           *DM_ImageDocumentToken_1Ref;
typedef struct Gatan_ScriptObject            *DM_ScriptObjectToken_1Ref;
typedef struct Gatan_String_1Ref             *DM_StringToken_1Ref;
typedef struct Gatan_Throwable_1Ref          *DM_ThrowableToken_1Ref;
typedef struct Gatan_Function_1Ref           *DM_FunctionToken_1Ref;
typedef struct Gatan_ScriptClass_1Ref        *DM_ScriptClassToken_1Ref;

#define _GATANPLUGIN_NAMESPACE

#endif // _GATAN_LANGUAGE_CPP

#if defined( _GATANPLUGIN_USINGNAMESPACE )


namespace Gatan
{
	template <typename DM_Obj> struct DM_ObjT
	{
	};

	template <typename DM_Obj>
		gtn_force_inline void ref_ptr_delete( DM_ObjT<DM_Obj> *ptr ) {}
	template <typename DM_Obj>
		gtn_force_inline void ref_ptr_add_ref( DM_ObjT<DM_Obj> *ptr )
		{
			if ( ptr != NULL ) { static_cast<DM_Obj *>(ptr)->add_ref(); }
		}
	template <typename DM_Obj>
		gtn_force_inline uint32 ref_ptr_rem_ref( DM_ObjT<DM_Obj> *ptr )
		{
			if ( ptr != NULL ) { static_cast<DM_Obj *>(ptr)->rem_ref(); }
			return 1;
		}

#ifdef _GATAN_COMPILER_VISUAL_CPP
	typedef char_range_t<uint16,std::char_traits<uint16> >         uint16_char_range;
	typedef string_proxy_t<uint16,std::char_traits<uint16> >     uint16_char_string_proxy;

	#if (_GATAN_COMPILER_VERSION >= 1300 )
	typedef char_range_t<__wchar_t,std::char_traits<__wchar_t> >   __wchar_t_char_range;
	typedef string_proxy_t<__wchar_t,std::char_traits<__wchar_t> >     __wchar_t_char_string_proxy;
	#endif // (_GATAN_COMPILER_VERSION >= 1300 )

#endif // _GATAN_COMPILER_VISUAL_CPP

	namespace PlugIn
	{

#endif // _GATANPLUGIN_USINGNAMESPACE

		enum DM_LinkageType
		{
			  dm_linkage_ABSTRACT			// no body, simply type information
			, dm_linkage_SCRIPT				// Script body
			, dm_linkage_C_v1				// C function, using old reference counting style
			, dm_linkage_C_v2				// C function, using new reference counting style
			, dm_linkage_C_variant			// C function, pass parameters as variant list
		};

		typedef void (*DM_PlugInProc)();

		struct DM_Env;
		struct DM_Interface;
		struct DM_ClassDesc;

		#ifdef __GATAN_REFPOINTER__
		
		typedef OneRef<DM_Interface> *DM_InterfacePtr_1Ref;
		typedef OneRef<DM_Env>       *DM_EnvPtr_1Ref;
		typedef OneRef<DM_ClassDesc> *DM_ClassDescPtr_1Ref;
		
		#else
		
		typedef DM_Interface *DM_InterfacePtr_1Ref;
		typedef DM_Env       *DM_EnvPtr_1Ref;
		typedef DM_ClassDesc *DM_ClassDescPtr_1Ref;

		#endif

		#ifdef __GATAN_IMAGETYPES__

		union DM_Variant
		{
			uint8             v_binary8;
			sint8             v_sint8;
			uint8             v_uint8;
			sint16            v_sint16;
			uint16            v_uint16;
			sint32            v_sint32;
			uint32            v_uint32;
			sint64            v_sint64;
			uint64            v_uint64;
			float32           v_float32;
			float64           v_float64;
			complex128_t      v_complex128;
			rgba_uint8_os_t   v_rgba_uint8_os;
			DM_ObjectToken    v_object;

			sint32            v_comp_sint32[4];
			uint32            v_comp_uint32[4];
			float32           v_comp_float32[4];

			uint8            *v_binary8_ref;
			sint8            *v_sint8_ref;
			uint8            *v_uint8_ref;
			sint16           *v_sint16_ref;
			uint16           *v_uint16_ref;
			sint32           *v_sint32_ref;
			uint32           *v_uint32_ref;
			sint64           *v_sint64_ref;
			uint64           *v_uint64_ref;
			float32          *v_float32_ref;
			float64          *v_float64_ref;
			complex128_t     *v_complex128_ref;
			rgba_uint8_os_t  *v_rgba_uint8_os_ref;
			DM_ObjectToken   *v_object_ref;

			const char       *v_c_string;
			const char      **v_c_string_ref;

			struct
			{
				char             *ptr;
				ulong             length;
			} v_charbuff;
		
			ulong_ptr_t       v_ptr_or_long;
			void             *v_ptr;
			DM_Handle         v_handle;
			long              v_external;

			ulong_ptr_t      *v_ptr_or_long_ref;
			void            **v_ptr_ref;
			DM_Handle        *v_handle_ref;
			long             *v_external_ref;
			
			uint32            pad_uint32[4];
			float64           pad_float64[2];
		};

		#else // __GATAN_IMAGETYPES__

		union DM_Variant;

		#endif // __GATAN_IMAGETYPES__

		struct DM_Interface_vtable
		{
			void                  (*add_ref_proc)( DM_Interface *desc );
			void                  (*rem_ref_proc)( DM_Interface *desc );
			unsigned long         (*get_version_proc)( const DM_Interface *desc );
			DM_EnvPtr_1Ref        (*get_env_proc)( DM_Interface *dm_int );
			DM_ClassDescPtr_1Ref  (*get_class_desc_proc)( const DM_Interface *desc, ulong encoding, const char *universal_name );
			DM_PlugInProc         (*get_link_proc_v1_proc)( const DM_Interface *desc, const char *name );

			DM_FunctionToken_1Ref (*add_function_proc)( DM_Interface *desc, ulong module, ulong encoding, const char *signature, ulong linkage, void *proc );
			void                  (*remove_function_proc)( DM_Interface *desc, DM_FunctionToken dm_function );

			DM_FunctionToken_1Ref (*lookup_function_proc)( DM_Interface *dm_int, ulong encoding, const char *signature );
			ulong                 (*get_function_info_proc)( DM_Interface *dm_int, DM_FunctionToken dm_func, ulong *linkage, ulong *flags );
					// Returns '1' if the function is callable, '0' otherwise
		};
		struct DM_Interface : public DM_ObjT<DM_Interface>
		{
			DM_Interface_vtable *vtable;
			
			void                  add_ref()                           { (*vtable->add_ref_proc)( this ); }
			void                  rem_ref()                           { (*vtable->rem_ref_proc)( this ); }
			unsigned long         get_version()                 const { return (*vtable->get_version_proc)( this ); }
			DM_EnvPtr_1Ref        get_env()                           { return (*vtable->get_env_proc)( this ); }
			DM_ClassDescPtr_1Ref  get_class_descriptor( const char *name ) const { return (*vtable->get_class_desc_proc)( this, 0, name ); }
			DM_PlugInProc         get_link_proc_v1( const char *name ) const { return (*vtable->get_link_proc_v1_proc)( this, name ); }

			DM_FunctionToken_1Ref add_function( ulong module, const char *signature, ulong linkage, void *proc )
													{ return (*vtable->add_function_proc)( this, module, 0, signature, linkage, proc ); }
			void                  remove_function( DM_FunctionToken dm_function )
													{ (*vtable->remove_function_proc)( this, dm_function ); }
			DM_FunctionToken_1Ref lookup_function( const char *signature )
													{ return (*vtable->lookup_function_proc)( this, 0, signature ); }
			ulong                 get_function_info( DM_FunctionToken dm_func, ulong *linkage, ulong *flags )
	                                          		{ return (*vtable->get_function_info_proc)( this, dm_func, linkage, flags ); }
		};
		
		/*
		**
		**
		** ulong                  (*call_function_proc)( DM_Env *dm_env, DM_FunctionToken func, ulong num_refs, DM_Variant *params );
		**    returns: 0 - if no error occurred
		**             1 - if generic error occured.  Use 'get_exception_proc' to get information about the exception
		**             2 - if 'func == NULL'
		**             3 - if 'func != NULL', but body has been unloaded.
		**
		*/
		struct DM_Env_vtable
		{
			void                   (*add_ref_proc)( DM_Env *dm_int );
			void                   (*rem_ref_proc)( DM_Env *dm_int );
			ulong                  (*get_version_proc)( const DM_Env *dm_int );
			ulong                  (*is_exception_proc)( const DM_Env *dm_int );
			void                   (*clear_exception_proc)( DM_Env *dm_int );
			DM_ThrowableToken_1Ref (*create_exception_by_id_proc)( DM_Env *dm_int, long error_id, long error_desc );
			DM_StringToken_1Ref    (*get_exception_string_proc)( const DM_Env *dm_int, DM_ThrowableToken dm_throwable );

			DM_ThrowableToken_1Ref (*get_exception_proc)( DM_Env *dm_env );
			void                   (*throw_exception_proc)( DM_Env *dm_env, DM_ThrowableToken dm_throwable );

			DM_StringToken_1Ref    (*create_string_proc)( DM_Env *dm_env, ulong encoding, const char *str, ulong length );
			const char            *(*get_string_chars_proc)( DM_Env *dm_env, DM_StringToken str, ulong encoding, ulong *size, DM_ObjectToken *string_lock );
			void                   (*release_string_chars_proc)( DM_Env *dm_env, DM_StringToken str, DM_ObjectToken string_lock );

			ulong                  (*call_function_proc)( DM_Env *dm_env, DM_FunctionToken func, ulong num_refs, DM_Variant *params );
			
			DM_ObjectToken_1Ref    (*convert_object_proc)( DM_Env *dm_env, DM_ObjectToken obj, const DM_ClassDesc *from, const DM_ClassDesc *to );

			// Version 2 methods
			octet                 *(*lock_image_data_proc)( DM_Env *dm_env, DM_ImageToken img, uint32 lock_flags, const uint32 *slice, uint32 *section, DM_ObjectToken *data_lock );

			void                   (*unlock_image_data_proc)( DM_Env *dm_env, uint32 unlock_flags, DM_ObjectToken data_lock );
			DM_ScriptObjectToken_1Ref (*new_object_from_class_proc)( DM_Env *dm_env, DM_ScriptClassToken class_desc );
			ulong                  (*get_obj_class_token_proc)( DM_Env *dm_env, DM_ScriptClassToken class_desc, DM_ScriptObjectToken obj, ulong_ptr_t *token_out );
			ulong                  (*replace_obj_class_token_proc)( DM_Env *dm_env, DM_ScriptClassToken class_desc, DM_ScriptObjectToken obj, ulong_ptr_t new_token, ulong_ptr_t *old_token_out );
		};
		struct DM_Env : public DM_ObjT<DM_Env>
		{
			DM_Env_vtable *vtable;
	
			void                   add_ref()            { (*vtable->add_ref_proc)( this ); }
			void                   rem_ref()            { (*vtable->rem_ref_proc)( this ); }
			ulong                  get_version() const  { return (*vtable->get_version_proc)( this ); }
			ulong                  is_exception() const { return (*vtable->is_exception_proc)( this ); }
			void                   clear_exception()    { (*vtable->clear_exception_proc)( this ); }
			DM_ThrowableToken_1Ref create_exception_by_id( long error_id, long error_desc ) { return (*vtable->create_exception_by_id_proc)( this, error_id, error_desc ); }
			DM_StringToken_1Ref    get_exception_string( DM_ThrowableToken dm_throwable ) { return (*vtable->get_exception_string_proc)( this, dm_throwable ); }

			DM_ThrowableToken_1Ref get_exception()
			                                    { return (*vtable->get_exception_proc)( this ); }
			void                   throw_exception( DM_ThrowableToken dm_throwable )
			                                    { (*vtable->throw_exception_proc)( this, dm_throwable ); }

			DM_StringToken_1Ref    create_string( ulong encoding, const char *str, ulong length )
												{ return (*vtable->create_string_proc)( this, encoding, str, length ); }
			const char            *get_string_chars( DM_StringToken str, ulong encoding, ulong *size, DM_ObjectToken *string_lock )
												{ return (*vtable->get_string_chars_proc)( this, str, encoding, size, string_lock ); }
			void                   release_string_chars( DM_StringToken str, DM_ObjectToken string_lock )
												{ (*vtable->release_string_chars_proc)( this, str, string_lock ); }

			ulong                  call_function( DM_FunctionToken func, ulong num_refs, DM_Variant *params )
			                                    { return (*vtable->call_function_proc)( this, func, num_refs, params ); }

			DM_ObjectToken_1Ref    convert_object( DM_ObjectToken obj, const DM_ClassDesc *from, const DM_ClassDesc *to )
			                                    { return (*vtable->convert_object_proc)( this, obj, from, to ); }
	
			// Version 2 methods
	
	// Version 2 methods
			octet         *lock_image_data( DM_ImageToken img, uint32 lock_flags, const uint32 *slice, uint32 *section, DM_ObjectToken *data_lock )
												{ return (*vtable->lock_image_data_proc)( this, img, lock_flags, slice, section, data_lock ); }
										
			void           unlock_image_data( uint32 unlock_flags, DM_ObjectToken data_lock )
												{ (*vtable->unlock_image_data_proc)( this, unlock_flags, data_lock ); }
			DM_ScriptObjectToken_1Ref new_object_from_class( DM_ScriptClassToken class_desc )
												{ return (*vtable->new_object_from_class_proc)( this, class_desc ); }
			ulong          get_obj_class_token( DM_ScriptClassToken class_desc, DM_ScriptObjectToken obj, ulong_ptr_t *token_out )
			                                   { return (*vtable->get_obj_class_token_proc)( this, class_desc, obj, token_out ); }
			ulong          replace_obj_class_token( DM_ScriptClassToken class_desc, DM_ScriptObjectToken obj, ulong_ptr_t new_token, ulong_ptr_t *old_token_out )
			                                   { return (*vtable->replace_obj_class_token_proc)( this, class_desc, obj, new_token, old_token_out ); }
		};

		struct DM_ClassDesc_vtable
		{
			void           (*add_ref_proc)( DM_ClassDesc *desc );
			void           (*rem_ref_proc)( DM_ClassDesc *desc );
			unsigned long  (*get_version_proc)( const DM_ClassDesc *desc );
			const char    *(*get_universal_name_proc)( const DM_ClassDesc *desc );
			const char    *(*get_short_name_proc)( const DM_ClassDesc *desc );
			unsigned long  (*get_id_proc)( const DM_ClassDesc *desc );
			void           (*add_obj_ref_proc)( const DM_ClassDesc *desc , DM_ObjectToken tok );
			void           (*rem_obj_ref_proc)( const DM_ClassDesc *desc , DM_ObjectToken tok );
			DM_ClassDesc  *(*get_base_class_desc_proc)( const DM_ClassDesc *desc );
	
			// Version 2 methods
			bool                 (*is_obj_valid_proc)( const DM_ClassDesc *desc, DM_ObjectToken tok );
			bool                 (*is_obj_same_as_proc)( const DM_ClassDesc *desc, DM_ObjectToken tok_1, DM_ObjectToken tok_2 );
			bool                 (*is_obj_equal_to_proc)( const DM_ClassDesc *desc, DM_ObjectToken tok_1, DM_ObjectToken tok_2 );
		};
		
		struct DM_ClassDesc : public DM_ObjT<DM_ClassDesc>
		{
			DM_ClassDesc_vtable *vtable;

			void             add_ref()                                  { (*vtable->add_ref_proc)( this ); }
			void             rem_ref()                                  { (*vtable->rem_ref_proc)( this ); }
			unsigned long    get_version()                        const { return (*vtable->get_version_proc)( this ); }
			const char      *get_universal_name()                 const { return (*vtable->get_universal_name_proc)( this ); }
			const char      *get_short_name()                     const { return (*vtable->get_short_name_proc)( this ); }
			unsigned long    get_id()                             const { return (*vtable->get_id_proc)( this ); }
			void             add_obj_ref( DM_ObjectToken tok )    const { (*vtable->add_obj_ref_proc)( this, tok ); }
			void             rem_obj_ref( DM_ObjectToken tok )    const { (*vtable->rem_obj_ref_proc)( this, tok ); }			
			DM_ClassDesc *get_base_class_desc() const { return (*vtable->get_base_class_desc_proc)( this ); }
	
			// Version 2 methods
			bool        is_obj_valid( DM_ObjectToken tok )   const { return (*vtable->is_obj_valid_proc)( this, tok ); }
			bool        is_obj_same_as( DM_ObjectToken tok_1, DM_ObjectToken tok_2 ) const
			                                                       { return (*vtable->is_obj_same_as_proc)( this, tok_1, tok_2 ); }
			bool        is_obj_equal_to( DM_ObjectToken tok_1, DM_ObjectToken tok_2 ) const
			                                                       { return (*vtable->is_obj_equal_to_proc)( this, tok_1, tok_2 ); }
		};

#if defined( _GATANPLUGIN_USINGNAMESPACE )

	} // namespace PlugIn
} // namespace Gatan

#endif // _GATANPLUGIN_USINGNAMESPACE

#if defined( _GATAN_LANGUAGE_CPP )

namespace Gatan
{
	namespace PlugIn
	{
		class DigitalMicrographInterface
		{
		public:
			struct Init
			{
				Init *next;
				void (*init_proc)( DM_Interface *app_desc );
				
				Init() : next( NULL ), init_proc( NULL ) {}
				Init( void (*init_proc_)( DM_Interface *app_desc ) ) : next( NULL ), init_proc( init_proc_ ) {}
			};
		public:
			DigitalMicrographInterface();
			~DigitalMicrographInterface();
			
			void Initialize();
			void Uninitialize();
			
			static void AddInitializer( Init *init );

			DM_Interface          *GetInterface() const;
			DM_FunctionToken_1Ref  AddFunction( unsigned long module, const char *signature, unsigned long linkage, void *proc );
			void                   RemoveFunction( DM_FunctionToken dm_function );
			void                   CallFunction( DM_FunctionToken *func, ulong num_params, DM_Variant *params, const char *signature );
			
			DM_Interface          *operator->() const { return GetInterface(); }
		};
		static DigitalMicrographInterface gDigitalMicrographInterface;

		class DM_PlugInEnv
		{
		private:
			DigitalMicrographInterface dm_int;
			DM_Env                    *dm_env;
			
			DM_PlugInEnv( const DM_PlugInEnv & );
			void operator =( const DM_PlugInEnv & );
		public:
			DM_PlugInEnv()  { dm_env = reinterpret_cast<DM_Env *>( dm_int.GetInterface()->get_env() ); }
			DM_PlugInEnv( DM_Env *dm_env_ ) : dm_env( dm_env_ ) { if ( dm_env != NULL ) { dm_env->add_ref(); } }
			~DM_PlugInEnv() { if ( dm_env != NULL ) { dm_env->rem_ref(); } }
			
			bool is_valid() const { return ( dm_env != NULL ); }
			
			DM_Env *get() const { return dm_env; }
			DM_Env *operator->() const { return dm_env; }
			
			DM_Interface *get_interface() const { return dm_int.GetInterface(); }
		};
		
		class dmplugin_exception : public std::exception
		{
		private:
			DM_ThrowableToken dm_throwable;
		public:
			dmplugin_exception( DM_ThrowableToken_1Ref dm_throwable );
			dmplugin_exception( DM_ThrowableToken dm_throwable );
			~dmplugin_exception();
			
			virtual const char *what() const _GATAN_THROW_0;
		
			static DM_ThrowableToken_1Ref extract_throwable( const std::exception &ex );
			static void throw_exception( DM_Env *dm_env );
		};
		
		#ifdef __GATAN_REFPOINTER__
		
		template <class DMObj> class ref_dmobj_ptr : public base_ref_ptr<DMObj>
		{
		private:
			typedef base_ref_ptr<DMObj> base_type;
		public:
			inline ref_dmobj_ptr()                        : base_type( (DMObj *) NULL ) {}
			inline ref_dmobj_ptr( DMObj *dm_obj )         : base_type( dm_obj ) {}
			inline ref_dmobj_ptr( OneRef<DMObj> *dm_obj ) : base_type( dm_obj ) {}
			inline ref_dmobj_ptr( const ref_dmobj_ptr &p2 ) : base_type( p2.get() ) {}
			inline ref_dmobj_ptr &operator =( DMObj *dm_obj )         { assign_base(dm_obj); return *this; }
			inline ref_dmobj_ptr &operator =( OneRef<DMObj> *dm_obj ) { assign_base(dm_obj); return *this; }
			inline ref_dmobj_ptr &operator =( const ref_dmobj_ptr &p2 ) { assign_base(p2.base_get()); return *this; }

			inline DMObj *get() const         { return base_get(); }
			inline DMObj **get_ptr()          { return &base_get(); }
			inline DMObj *operator->() const  { return base_get(); }
			inline DMObj &operator *() const  { return *base_get(); }
	
			inline DMObj         *release()           { return base_release(); }
			inline OneRef<DMObj> *release_1ref()      { return base_release_1ref(); }
		};
		
		template <class From, class To> class DM_DynamicCast
		{
		private:
			DM_PlugInEnv   dm_env;
			DM_ClassDesc  *from_desc;
			DM_ClassDesc  *to_desc;
		public:
			DM_DynamicCast() : from_desc( From::get_class_descriptor() ), to_desc( To::get_class_descriptor() ) {}
		
			typename To::ret_token_type operator()( typename From::token_type tok )
				{ return reinterpret_cast<To::ret_token_type>( dm_env->convert_object( reinterpret_cast<DM_ObjectToken>(tok), from_desc, to_desc ) ); }
		
			To operator()( const From &fm )
				{ return reinterpret_cast<To::ret_token_type>( dm_env->convert_object( reinterpret_cast<DM_ObjectToken>(fm.get()), from_desc, to_desc ) ); }
		};
		
		#endif // __GATAN_REFPOINTER__

		#ifdef __GATAN_IMAGETYPES__
	// This will instantiate these templates, avoiding a VisualCPP 5 compiler bug where the size is
	// calculated incorrectly on the first instantiation.
		#ifdef _GATAN_OS_WIN32
		static void __DM_AvoidVisualCPPCompilerBug_0() { Gatan::LongPoint lp; }
		static void __DM_AvoidVisualCPPCompilerBug_1() { Gatan::LongRect  lr; }
		#endif // _GATAN_OS_WIN32
		#endif // __GATAN_IMAGETYPES__
	}
}

namespace GatanPlugIn = Gatan::PlugIn;

#endif // _GATAN_LANGUAGE_CPP

// On Windows, avoid problem where 'Yield' is defined as a macro in their headers.
#ifdef Yield
	#undef Yield
#endif // Yield

#endif // _GATAN_PLUGIN_BASE

/*
** DM Library routines (All of the following routines are preceded by an 'DM'
**	to indicate that they are intrinsically related to the DM application.).
*/



