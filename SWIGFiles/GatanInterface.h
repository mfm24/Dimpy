
#ifndef __GATANINTERFACE__
#define __GATANINTERFACE__

#include "GatanRefPointer.h"

namespace Gatan
{

class GFRefCountableInterface
{
public:
	typedef ulong count_type;
public:
	virtual ~GFRefCountableInterface();
	
	virtual void       AddRef() const = 0;
	virtual count_type RemRef() const = 0;
	virtual void       DeleteSelf() const = 0;
};

/* GFRefCountableInterface_PureInt
**
**    -- Unless overriden, objects derived from this class are not deleted
**       at end of reference count
*/

class GFRefCountableInterface_PureInt : public GFRefCountableInterface
{
public:
	typedef GFRefCountableInterface::count_type count_type;

	virtual ~GFRefCountableInterface_PureInt();
	
	virtual void        AddRef() const;
	virtual count_type  RemRef() const;
	virtual void        DeleteSelf() const;
};

gtn_force_inline void ref_ptr_delete( GFRefCountableInterface *ptr )
{
	if ( ptr != NULL ) { ptr->DeleteSelf(); }
};
gtn_force_inline void ref_ptr_add_ref( GFRefCountableInterface *ptr )
{
	if ( ptr != NULL ) { ptr->AddRef(); }
}
gtn_force_inline uint32 ref_ptr_rem_ref( GFRefCountableInterface *ptr )
{
	return ( ptr == NULL ) ? 0 : ptr->RemRef();
}

template <typename RefCount> class interface_base : public GFRefCountableInterface
{
public:
	typedef GFRefCountableInterface::count_type count_type;
private:
	RefCount ref_count;
public:
	virtual ~interface_base()           {}
	virtual void       AddRef() const		{ ref_count.addRef(); }
	virtual count_type RemRef() const		{ return ref_count.remRef(); }
	virtual void       DeleteSelf() const   { delete this; }
};

template <typename Intrf,typename RefCount> class interface_object : public Intrf
{
public:
	typedef typename Intrf::count_type count_type;
private:
	RefCount ref_count;
public:
	interface_object()                 : Intrf()     {}
	interface_object( const Intrf &i ) : Intrf(i)    {}
	virtual ~interface_object()         {}
	virtual void       AddRef() const		{ ref_count.addRef(); }
	virtual count_type RemRef() const		{ return ref_count.remRef(); }
	virtual void       DeleteSelf() const   { delete this; }
};

template <typename Intrf_1, typename Intrf_2, typename RefCount> class interface_object_2 : public Intrf_1, public Intrf_2
{
public:
	typedef typename Intrf_1::count_type count_type;
private:
	RefCount ref_count;
public:
	interface_object_2()                 : Intrf_1(), Intrf_2()     {}
	interface_object_2( const Intrf_1 &i_1, const Intrf_2 &i_2 ) : Intrf_1(i_1), Intrf_2(i_2)         {}
	virtual ~interface_object_2()         {}
	virtual void       AddRef() const		{ ref_count.addRef(); }
	virtual count_type RemRef() const		{ return ref_count.remRef(); }
	virtual void       DeleteSelf() const   { delete this; }
};

template <typename Intrf> class add_interface_methods : public Intrf
{
public:
	typedef typename Intrf::count_type count_type;
public:
	add_interface_methods()                 : Intrf()     {}
	add_interface_methods( const Intrf &i ) : Intrf(i)    {}
	virtual void       AddRef() const		{ Intrf::AddRef(); }
	virtual count_type RemRef() const		{ return Intrf::RemRef(); }
	virtual void       DeleteSelf() const   { Intrf::Delete(); }
};

} // namespace Gatan


#endif // __GATANINTERFACE__


