
#ifndef __DM_PLUGIN_SCRIPT_CLASS__
#define __DM_PLUGIN_SCRIPT_CLASS__

#define _GATANPLUGIN_USES_LIBRARY_VERSION 2
#include "DMPlugInLibrary.h"
#include "DMPluginUtility.h"

namespace Gatan
{
	namespace DM
	{
		ScriptClass NewScriptClass( const String &class_name, const String &parent_class_name, void *alloc_proc, void *dealloc_proc, long refCon );
		ScriptClass NewScriptClassFromScript( const String &script, const String &class_name );
		void ScriptClassRegister( const ScriptClass &script_class );
		void ScriptClassUnregister( const ScriptClass &script_class );
		Function ScriptClassAddMethod( const ScriptClass &script_class, const Function &method );
		void ScriptClassRemoveMethod( const ScriptClass &script_class, const Function &method );
		String ScriptClassGetName( const ScriptClass &script_class );
		ScriptClass FindScriptClassByName( const String &class_name );
		ScriptObject ScriptClassNewObject( const ScriptClass &script_class );

		ulong ScriptObjectReplaceClassToken( DM_ScriptObjectToken scriptObject, const String &class_name, ulong new_token );
		bool ScriptObjectGetClassIndex( DM_ScriptObjectToken scriptObject, const String &class_name, bool exception_if_fail, ulong *class_index, ulong *class_id );
		bool ScriptObjectGetClassTokenByIndex( DM_ScriptObjectToken scriptObject, ulong class_index, ulong class_id, bool exception_if_fail, ulong *token );
		bool ScriptObjectReplaceClassTokenByIndex( DM_ScriptObjectToken scriptObject, ulong class_index, ulong class_id, ulong new_token, bool exception_if_fail, ulong *old_token );
		ScriptClass RegisterClass( const String &class_name, const String &parent_class_name, void *alloc_proc, void *dealloc_proc, long refCon );
		void UnregisterClass( const String &class_name );


		struct MethodDesc
		{
			char_range  signature;
			void       *function;
			ulong       linkage;

			MethodDesc() {}
			MethodDesc( const char_range &signature_, void *function_, ulong linkage_ )
				: signature( signature_ ), function( function_ ), linkage( linkage_ )
			{}
		};

		DM::ScriptObject NewAnonymousClassObject( ulong num_methods, const MethodDesc *method_descs );
		DM::ScriptObject NewAnonymousClassObject( ulong num_meth
		                                        , const char_range &meth_sig_0, void *func_proc_0, ulong proc_linkage_0
		                                        );
		DM::ScriptObject NewAnonymousClassObject( ulong num_meth
		                                        , const char_range &meth_sig_0, void *func_proc_0, ulong proc_linkage_0
		                                        , const char_range &meth_sig_1, void *func_proc_1, ulong proc_linkage_1
				                                );
		DM::ScriptObject NewAnonymousClassObject( ulong num_meth
		                                        , const char_range &meth_sig_0, void *func_proc_0, ulong proc_linkage_0
		                                        , const char_range &meth_sig_1, void *func_proc_1, ulong proc_linkage_1
		                                        , const char_range &meth_sig_2, void *func_proc_2, ulong proc_linkage_2
				                                );
		DM::ScriptObject NewAnonymousClassObject( ulong num_meth
		                                        , const char_range &meth_sig_0, void *func_proc_0, ulong proc_linkage_0
		                                        , const char_range &meth_sig_1, void *func_proc_1, ulong proc_linkage_1
		                                        , const char_range &meth_sig_2, void *func_proc_2, ulong proc_linkage_2
		                                        , const char_range &meth_sig_3, void *func_proc_3, ulong proc_linkage_3
				                                );
	}
}

namespace Gatan
{
	namespace PlugIn
	{
		class ScriptClass;

		class ScriptClass_Imp : public Gatan::std_base_class_ref_count<ScriptClass_Imp>
		{
		public:
			typedef ulong_ptr_t class_token_type;
			typedef ulong_ptr_t imp_token_type;
			typedef imp_token_type  (*alloc_proc_type)( PlugIn::DM_Env *dm_env, class_token_type class_token);
			typedef void            (*dealloc_proc_type)( PlugIn::DM_Env *dm_env, imp_token_type imp_token, class_token_type class_token );
		private:
			DM::String         fClassName;
			DM::String         fParentClassName;

			alloc_proc_type    fAllocProc;
			dealloc_proc_type  fDeallocProc;
			class_token_type   fClassToken;

			DM::ScriptClass    fRegClass;
		public:
			ScriptClass_Imp( const DM::String &class_name, const DM::String &parent_class_name
			               , alloc_proc_type alloc_proc, dealloc_proc_type dealloc_proc, class_token_type class_token );
			virtual ~ScriptClass_Imp();

			imp_token_type  GetClassToken( DM_ScriptObjectToken so ) const;
			bool            GetClassToken( DM_ScriptObjectToken so, imp_token_type &token ) const;
			imp_token_type  ReplaceToken( DM_ScriptObjectToken so, const imp_token_type &old_tok ) const;

			DM::ScriptObject NewScriptObject() const;

			DM::Function    AddMethod( const DM::Function &method_imp ) const;
			DM::Function    AddMethod( const char *signature, void *function, ulong linkage ) const;

			DM::String     GetClassName() const { return fClassName; }

			void           RegisterClass();
			void           UnregisterClass();
			virtual void RegisterMethods();
			virtual void UnregisterMethods();
		};

		class ScriptClass
		{
		public:
			typedef ulong_ptr_t class_token_type;
			typedef ulong_ptr_t imp_token_type;
		private:
			ref_ptr<ScriptClass_Imp>   fScriptClass;
		public:
			ScriptClass( const ref_ptr<ScriptClass_Imp> &script_class )
				: fScriptClass( script_class )
			{}

			ScriptClass_Imp *get() const { return fScriptClass.get(); }

			imp_token_type  GetClassToken( DM_ScriptObjectToken so ) const
				{ return get()->GetClassToken( so ); }

			bool            GetClassToken( DM_ScriptObjectToken so, imp_token_type &token ) const
				{ return get()->GetClassToken( so, token ); }

			imp_token_type  ReplaceToken( DM_ScriptObjectToken so, const imp_token_type &old_tok ) const
				{ return get()->ReplaceToken( so, old_tok ); }

			DM::ScriptObject   NewScriptObject() const
				{ return get()->NewScriptObject(); }

			DM::Function       AddMethod( const DM::Function &method_imp ) const
				{ return get()->AddMethod( method_imp ); }

			DM::Function       AddMethod( const char *signature, void *function, ulong linkage ) const
				{ return get()->AddMethod( signature, function, linkage ); }

			void           RegisterClass() const
				{ get()->RegisterClass(); }

			void           UnregisterClass() const
				{ get()->UnregisterClass(); }
		};

		static const char *rerrDispatchOffNullObject = "Attempt to dispatch off a null object.";


		/*
		** class DMScriptClassT<ClassDesc>
		**
		**    Utility providing useful functions for creating a DM script class based on a reference counted object.
		**
		**       -- ClassDesc should define the following:
		**           typedef <ImpType>        base_imp_type;
		**           typedef <RefType>        base_ref_type;
		**           static const char *class_name();
		**
		**          where
		**             'ImpType' is the DM class on which the script class is based
		**             'RefType' is a reference counted pointer to 'ImpType'
		**             'class_name' is the class name
		**             'allocate_initial' returns the initial value used by 'alloc'
		**
		*/

		typedef uint32 DMScript_ClassId;

		template <class ClassDesc> class DMScriptClassT
		{
		public:
			typedef typename ClassDesc::base_imp_type    imp_type;
			typedef typename ClassDesc::base_ref_type    ref_type;
			typedef uint32                               class_token_type;
			typedef uint32                               imp_token_type;
		public:
			static DM::String class_name()      { return ClassDesc::class_name(); }
			static DM::String base_class_name() { return ClassDesc::base_class_name(); }

			static imp_token_type GetClassToken( DM_ScriptObjectToken so );
			static bool   GetClassToken( DM_ScriptObjectToken so, imp_token_type &token );

			static ref_type                GetImplementation( DM_ScriptObjectToken so )
			{
				ref_type imp = reinterpret_cast<imp_type *>( GetClassToken( so ) );
				ThrowStringUnless( imp != NULL, rerrDispatchOffNullObject );
				return imp;
			}
			static ref_type                GetImplementationOrNull( DM_ScriptObjectToken so )
			{
				ref_type imp = reinterpret_cast<imp_type *>( GetClassToken( so ) );
				return imp;
			}
			static ref_type                GetImplementationIfThere( DM_ScriptObjectToken so )
			{
				ref_type imp;
				imp_token_type token;
				if ( GetClassToken( so, token ) )
				{
					imp = reinterpret_cast<imp_type *>( token );
				}
				return imp;
			}

			static DM::ScriptObject   NewScriptObject();
			static DM::ScriptObject   NewScriptObject( const ref_type &act_obj );
			static ref_type           ReplaceImplementation( DM_ScriptObjectToken so, const ref_type &new_imp );
			static void AddMethod( const char *signature, void *function, ulong linkage )
			{
				DM::ClassAddMethod( class_name(), DM::NewCallbackFunction( signature, function, linkage) );
			}

			static imp_token_type GetClassToken( const DM::ScriptObject &so ) { return GetClassToken( so.get() ); }
			static bool   GetClassToken( const DM::ScriptObject &so, imp_token_type &token ) { return GetClassToken( so.get(), token ); }

			static ref_type GetImplementation( const DM::ScriptObject & so )       { return GetImplementation( so.get() ); }
			static ref_type GetImplementationOrNull( const DM::ScriptObject &so )  { return GetImplementationOrNull( so.get() ); }
			static ref_type GetImplementationIfThere( const DM::ScriptObject &so ) { return GetImplementationIfThere( so.get() ); }
			static ref_type ReplaceImplementation( const DM::ScriptObject &so, const ref_type &new_imp )
				{ return ReplaceImplementation( so.get(), new_imp ); }

			static imp_token_type alloc( DM_Env *dm_env, class_token_type );
			static void dealloc( DM_Env *dm_env, imp_token_type token, class_token_type );

			static DM::ScriptClass RegisterClass();
			static void            UnregisterClass();
		};

		template <class ClassDesc> uint32 DMScriptClassT<ClassDesc>::alloc( DM_Env *dm_env, uint32 )
		{
			ref_type imp;

			PLUG_IN_ENTRY_ENV( dm_env )
	
			imp = ClassDesc::allocate_initial();
			imp.addRef();

			PLUG_IN_EXIT

			return reinterpret_cast<uint32>( imp.get() );
		}
		template <class ClassDesc> void DMScriptClassT<ClassDesc>::dealloc( DM_Env *dm_env, uint32 token, uint32 )
		{
			PLUG_IN_ENTRY_ENV( dm_env )

			ref_type imp = reinterpret_cast<imp_type *>(token);
			imp.remRef();
			ClassDesc::deinitialize( imp );

			PLUG_IN_EXIT
		}
		template <class ClassDesc> uint32 DMScriptClassT<ClassDesc>::GetClassToken( DM_ScriptObjectToken so )
		{
			uint32 token = 0;
			if ( so != NULL )
			{
				if ( !DM::ScriptObjectGetClassTokenByIndex( so, ClassDesc::class_index, ClassDesc::class_id, false, &token ) )
				{
					// If cached index and id do not work, look them up again
					uint32             new_class_index;
					DMScript_ClassId   new_class_id;
					DM::ScriptObjectGetClassIndex( so, class_name(), true, &new_class_index, &new_class_id );
					// Only replace cached index and id if the class descriptor described by 'new_class_index'
					// and 'new_class_id' is registered;
					DM::ScriptObjectGetClassTokenByIndex( so, new_class_index, new_class_id, true, &token );

					ClassDesc::class_index = new_class_index;
					ClassDesc::class_id    = new_class_id;
				}
			}
			return token;
		}
		template <class ClassDesc> bool DMScriptClassT<ClassDesc>::GetClassToken( DM_ScriptObjectToken so, uint32 &token_out )
		{
			bool found = false;
			uint32 token = 0;
			if ( so != NULL )
			{
				found = DM::ScriptObjectGetClassTokenByIndex( so, ClassDesc::class_index, ClassDesc::class_id, false, &token );
				if ( !found )
				{
					// If cached index and id do not work, look them up again
					uint32             new_class_index;
					DMScript_ClassId   new_class_id;
					found =    DM::ScriptObjectGetClassIndex( so, class_name(), false, &new_class_index, &new_class_id )
					        && DM::ScriptObjectGetClassTokenByIndex( so, new_class_index, new_class_id, false, &token );

					// Only replace cached index and id if the class descriptor described by 'new_class_index'
					// and 'new_class_id' is registered;
					if ( found )
					{
						ClassDesc::class_index = new_class_index;
						ClassDesc::class_id    = new_class_id;
					}
				}
			}

			if ( found )
			{
				token_out = token;
			}
			return found;
		}

		template <class ClassDesc> typename DMScriptClassT<ClassDesc>::ref_type DMScriptClassT<ClassDesc>::ReplaceImplementation( DM_ScriptObjectToken script_obj, const ref_type &new_imp )
		{
			ref_type old_imp;
			if ( script_obj != NULL )
			{
				uint32 old_imp_token = 0;
				if ( !DM::ScriptObjectReplaceClassTokenByIndex( script_obj, ClassDesc::class_index, ClassDesc::class_id
						                                      , reinterpret_cast<uint32>( new_imp.get() ), false, &old_imp_token ) )
				{
					// If cached index and id do not work, look them up again
					uint32             new_class_index;
					DMScript_ClassId   new_class_id;
					DM::ScriptObjectGetClassIndex( script_obj, class_name(), true, &new_class_index, &new_class_id );
					// Only replace cached index and id if the class descriptor described by 'new_class_index'
					// and 'new_class_id' is registered;
					DM::ScriptObjectReplaceClassTokenByIndex( script_obj, new_class_index, new_class_id
						                                    , reinterpret_cast<uint32>( new_imp.get() ), true, &old_imp_token );

					ClassDesc::class_index = new_class_index;
					ClassDesc::class_id    = new_class_id;
				}
				old_imp = reinterpret_cast<imp_type *>( old_imp_token );
				new_imp.addRef();
				old_imp.remRef();
			}
			return old_imp;
		}

		template <class ClassDesc> DM::ScriptObject         DMScriptClassT<ClassDesc>::NewScriptObject()
		{
			return DM::ClassNewObject( class_name() );
		}
		template <class ClassDesc> DM::ScriptObject         DMScriptClassT<ClassDesc>::NewScriptObject( const ref_type &new_implementation )
		{
			DM::ScriptObject script_obj;
			if ( new_implementation != NULL )
			{
				script_obj = DM::ClassNewObject( class_name() );
				ReplaceImplementation( script_obj.get(), new_implementation );
			}
			return script_obj;
		}

		template <class ClassDesc> DM::ScriptClass DMScriptClassT<ClassDesc>::RegisterClass()
		{
			ClassDesc::class_id = 0;
			ClassDesc::class_index = 0;
			return DM::RegisterClass( class_name(), base_class_name(), (void *) &alloc, (void *) &dealloc, 0 );
		}
		template <class ClassDesc> void DMScriptClassT<ClassDesc>::UnregisterClass()
		{
			DM::UnregisterClass( class_name() );
		}
	}
}

#endif // __DM_PLUGIN_SCRIPT_CLASS__

