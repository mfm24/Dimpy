/**************************************************************************\
*
* GatanRefPointer.h
*    Smart pointer classes.
*
* Douglas S. Hauge
*
* $Id: GatanRefPointer.h,v 1.1 2007/06/25 23:28:32 Matt Exp $
*
\**************************************************************************/

    
#ifndef __GATAN_REFPOINTER__
#define __GATAN_REFPOINTER__

namespace Gatan
{
/* class RC_NumRef<UInt,NumType>
 *
 *    Builds a reference count object whose reference count
 *    is incremented as UInt, and whose value can fit in
 *    a `NumType'.  This class can be derived from to put
 *    a reference count inside an object (and thus make
 *    it usable as the `value_type' of `StdPtrRCData;),
 *    or it can be used as a standalone reference count
 *    and passed as the second parameter to `StdAssocRCData'.
 */
template <typename UInt,typename NumType> class RC_NumRef
{
private:
   UInt num_refs;
public:
   typedef NumType count_type;
   gtn_force_inline RC_NumRef()                    : num_refs(0)    { }
   gtn_force_inline RC_NumRef(const RC_NumRef &)   : num_refs(0)    { }       // If new copy, new reference count
   gtn_force_inline void operator =(const RC_NumRef &)              { }       // Don't copy over reference counter
   gtn_force_inline ~RC_NumRef()                                    { }

   gtn_force_inline count_type addRef() const  { return (const_cast<RC_NumRef &>(*this).num_refs)++; }
   gtn_force_inline count_type remRef() const  { return --(const_cast<RC_NumRef &>(*this).num_refs); }
   gtn_force_inline count_type numRef() const  { return num_refs; }
};

// Reference Count object that does not do bounds checking, and
// which is the size of and unsigned ing.
typedef RC_NumRef<unsigned long,unsigned long> StdNumRef;

template <typename V> class OneRef {};
enum NullPtrType { null_ptr = 1 };

/*
** 'numref_ptr' should return whatever type 'ref_ptr_num_ref' returns, and should only reference
** that type if 'numref_ptr' is used ( 'V' may not support 'ref_ptr_num_ref' ), but I don't know how
** to get at that information at the moment, so I will return 'ulong'.
*/
template <typename V> class base_ref_ptr
{
public:
	typedef          V             element_type;

	static gtn_force_inline void assign_ptr( V *&lval, V *rval )
	{
		if ( lval != rval )
		{
			if ( rval != NULL ) { ref_ptr_add_ref( rval ); } 
			if ( lval != NULL ) { if ( ref_ptr_rem_ref( lval ) == 0 ) { ref_ptr_delete( lval ); } }
			lval = rval;
		}
	}
	static gtn_force_inline void assign_ptr( V *&lval, OneRef<V> *rval )
	{
		if ( lval != NULL ) { if ( ref_ptr_rem_ref( lval ) == 0 ) { ref_ptr_delete( lval ); } }
		lval = (V *) rval;
	}
	static gtn_force_inline void addref_ptr( V *val )  { if ( val != NULL ) { ref_ptr_add_ref(val); } }
	static gtn_force_inline void remref_ptr( V *val )  { if ( val != NULL ) { if ( ref_ptr_rem_ref(val) == 0 ) { ref_ptr_delete( val ); } } }
	static gtn_force_inline ulong numref_ptr( V *val ) { return ( val == NULL ) ? 0 : ref_ptr_num_ref(val); }

	gtn_force_inline void   addRef( ) const { addref_ptr( ptr ); }
	       void   remRef( ) const { remref_ptr( ptr ); }
	gtn_force_inline ulong numRef( ) const { return ( ptr == NULL ) ? 0 : ref_ptr_num_ref(ptr); }

	gtn_force_inline base_ref_ptr( const base_ref_ptr &ptr );				// Undefined
protected:
	V *ptr;
	
	gtn_force_inline void assign_base( V *v )                { if ( ptr != v ) { assign_ptr( ptr, v ); } }
	gtn_force_inline void assign_base( OneRef<V> *v_ )       { remref_ptr( ptr ); V *v = reinterpret_cast<V *>( v_ ); if ( ptr != v ) { ptr = v; } }
	gtn_force_inline void assign_base( const V *v )          { if ( ptr != v ) { assign_ptr( ptr, const_cast<V *>(v) ); } }
	gtn_force_inline void assign_base( const OneRef<V> *v_ ) { remref_ptr( ptr ); V *v = const_cast<V *>( reinterpret_cast<const V *>( v_ ));  if ( ptr != v ) { ptr = const_cast<V *>(v); } }
	
	gtn_force_inline base_ref_ptr( V *v  )              : ptr( v )                             { addref_ptr( v ); }
	gtn_force_inline base_ref_ptr( OneRef<V> *v )       : ptr( reinterpret_cast<V *>(v) )      { }
	gtn_force_inline base_ref_ptr( const V *v )         : ptr( const_cast<V *>( v ) )          { addref_ptr( const_cast<V *>( v ) ); }
	gtn_force_inline base_ref_ptr( const OneRef<V> *v ) : ptr( const_cast<V *>( reinterpret_cast<const V *>( v ) ) )    { }
	gtn_force_inline ~base_ref_ptr() { remref_ptr( ptr ); }

	gtn_force_inline bool eql( const V *ptr2 )           const { return ( ptr == ptr2 ); }
	gtn_force_inline bool eql( const base_ref_ptr &rp2 ) const { return ( ptr == rp2.ptr ); }

	gtn_force_inline V *base_get() const     { return ptr; }
	gtn_force_inline V *&base_get()          { return ptr; }
	gtn_force_inline V         *base_release_0ref()  { V *ptr_ = ptr; ptr = NULL; if ( ptr_ != NULL ) { ref_ptr_rem_ref(ptr_); } return ptr_; }
	gtn_force_inline OneRef<V> *base_release_1ref()  { V *ptr_ = ptr; ptr = NULL; return reinterpret_cast<OneRef<V> *>( ptr_ ); }			// Keeps 1 reference
public:	
   gtn_force_inline bool operator ==( const base_ref_ptr &p2) const { return ( ptr == p2.ptr ); }
   gtn_force_inline bool operator ==( const V *p2           ) const { return ( ptr == p2 ); }
   friend gtn_force_inline bool operator ==( const V *p1           , const base_ref_ptr &p2)  { return ( p1 == p2.ptr ); }
   gtn_force_inline bool operator !=( const base_ref_ptr &p2) const { return ( ptr != p2.ptr ); }
   gtn_force_inline bool operator !=( const V *p2           ) const { return ( ptr != p2 ); }
   friend gtn_force_inline bool operator !=( const V *p1           , const base_ref_ptr &p2 )  { return ( p1 != p2.ptr ); }
};

template <typename V> class ref_ptr : public base_ref_ptr<V>
{
public:
	typedef V                element_type;
	typedef V               *raw_ptr_type;
	typedef OneRef<V>       *raw_1ref_ptr_type;
	typedef base_ref_ptr<V>  base_type;
public:
	gtn_force_inline ref_ptr( NullPtrType n = null_ptr )         : base_type( (V *) 0 )  {}
	gtn_force_inline ref_ptr( raw_ptr_type v )                   : base_type( v )        {}
	gtn_force_inline ref_ptr( raw_1ref_ptr_type v )              : base_type( v )        {}
	gtn_force_inline ref_ptr( const ref_ptr &rp )                : base_type( rp.base_get() ) {}
	gtn_force_inline ref_ptr &operator =( NullPtrType )          { assign_base( (V *) 0 ); return *this; }
	gtn_force_inline ref_ptr &operator =( V *v )                 { assign_base(v); return *this; }
	gtn_force_inline ref_ptr &operator =( OneRef<V> *v )         { assign_base(v); return *this; }
	gtn_force_inline ref_ptr &operator =( const ref_ptr &rp )    { assign_base( rp.base_get()); return *this; }

	void reset( NullPtrType n = null_ptr )   { assign_base( (V *) 0 ); }
	void reset( raw_ptr_type v )             { assign_base( v ); }
	void reset( raw_1ref_ptr_type v )        { assign_base( v ); }

	gtn_force_inline V *get() const          { return  base_get(); }
	gtn_force_inline V **get_ptr()           { return &base_get(); }
	gtn_force_inline V *operator->() const   { return  base_get(); }
	gtn_force_inline V &operator *() const   { return *base_get(); }
	
	gtn_force_inline V         *release_0ref()    { return base_release_0ref(); }
	gtn_force_inline OneRef<V> *release_1ref()    { return base_release_1ref(); }
	gtn_force_inline ref_ptr<V> release_ref_ptr() { return base_release_1ref(); }
};

template <typename V> class const_ref_ptr : public base_ref_ptr<V>
{
public:
	typedef V                element_type;
	typedef const V         *raw_ptr_type;
	typedef const OneRef<V> *raw_1ref_ptr_type;
	typedef base_ref_ptr<V>  base_type;
public:
	gtn_force_inline const_ref_ptr( NullPtrType n = null_ptr )            : base_type( (V *) 0 )  {}
	gtn_force_inline const_ref_ptr( raw_ptr_type v  )                     : base_type( v )        {}
	gtn_force_inline const_ref_ptr( raw_1ref_ptr_type v  )                : base_type( v )        {}
	gtn_force_inline const_ref_ptr( const const_ref_ptr &rp )             : base_type( rp.base_get() ) {}
	gtn_force_inline const_ref_ptr( const ref_ptr<V> &rp )                : base_type( rp.get() ) {}
	gtn_force_inline const_ref_ptr &operator =( NullPtrType )             { assign_base( (V *) 0 ); return *this; }
	gtn_force_inline const_ref_ptr &operator =( const V *v )              { assign_base(v); return *this; }
	gtn_force_inline const_ref_ptr &operator =( const OneRef<V> *v )      { assign_base(v); return *this; }
	gtn_force_inline const_ref_ptr &operator =( const const_ref_ptr &rp ) { assign_base( rp.base_get()); return *this; }
	gtn_force_inline const_ref_ptr &operator =( const ref_ptr<V> &rp )    { assign_base( rp.get()); return *this; }

	void reset( NullPtrType n = null_ptr )        { assign_base( (V *) 0 ); }
	void reset( raw_ptr_type v )                  { assign_base( v ); }
	void reset( raw_1ref_ptr_type v )             { assign_base( v ); }
	
	gtn_force_inline const V *get() const         { return base_get(); }
	gtn_force_inline const V **get_ptr()          { return &base_get(); }
	gtn_force_inline const V *operator->() const  { return base_get(); }
	gtn_force_inline const V &operator *() const  { return *base_get(); }
	
	gtn_force_inline const V         *release_0ref()    { return base_release_0ref(); }
	gtn_force_inline const OneRef<V> *release_1ref()    { return base_release_1ref(); }
	gtn_force_inline const_ref_ptr<V> release_ref_ptr() { return base_release_1ref(); }
};

// a class to provide a comparison operator for ref_ptr<T> so as to be able to put 
// ref_ptr<T> as the key in a map<> object.
template <typename T>
struct ref_ptr_compare
{
public:
	bool operator()( const ref_ptr<T> &first, const ref_ptr<T> &second ) const { return first.get() < second.get(); }
};

	template <typename FullType, typename CountType> struct ref_ptr_std_base : public CountType
	{
	};
	
	template <typename FullType, typename CountType>
		gtn_force_inline void ref_ptr_delete( ref_ptr_std_base<FullType,CountType> *ptr )
		{
			if ( ptr != NULL )
			{
				delete static_cast<FullType *>(ptr);
			}
		}

	gtn_force_inline void ref_ptr_add_ref( StdNumRef *ptr )
	{
		if ( ptr != NULL ) { ptr->addRef(); }
	}
	gtn_force_inline uint32 ref_ptr_rem_ref( StdNumRef *ptr )
	{
		return ( ptr == NULL ) ? 1 : ptr->remRef();
	}
	gtn_force_inline uint32 ref_ptr_num_ref( StdNumRef *ptr )
	{
		return ( ptr == NULL ) ? 0 : ptr->numRef();
	}
} // namespace Gatan

/*
** Boost support
**
**    The following allows boost templates like 'mem_fn' to be used for methods dispatched
** off pointer contained by 'Gatan::ref_ptr'. 
**    - We should be able to put the templates in the 'Gatan' namespace and resolve against
** 'boost::get_pointer' via inclusion of argument's namespace.  However, VisualC++6 chokes
** on this, so for now we insert it into 'boost'
**
*/
namespace boost
{
	template<typename T> inline T * get_pointer(::Gatan::ref_ptr<T> const & p)
	{
		return p.get();
	}
	template<typename T> inline const T * get_pointer(::Gatan::const_ref_ptr<T> const & p)
	{
		return p.get();
	}
}

#endif __GATAN_REFPOINTER__

