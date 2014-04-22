
#ifndef __GATAN_POINTTEMPLATES__
#define __GATAN_POINTTEMPLATES__

#include "GatanDefines.h"
#include "GatanTypeConversion.h"

#include <cmath>
#include <algorithm>

/* class Point<Units,Scalar>
 *
 *    Gives coordinates in units described by 'Units'
 */

template <class T> inline T& max_assign( T& a, T b) { a = std::max( a, b ); return a; }
template <class T> inline T& min_assign( T& a, T b) { a = std::min( a, b ); return a; }
template <class T> inline T& mod_assign( T& a, T b) { a %= b; return a; }

template <class T> inline T merge( const T &a, const T &b) { T tmp = a; return tmp.merge_assign(b); }
template <class T> inline T join( const T &a, const T &b)  { T tmp = a; return tmp.join_assign(b); }

inline long   mod( long v1, long v2 )      { return v1 % v2; }
inline int    mod( int v1, int v2 )        { return v1 % v2; }
inline short  mod( short v1, short v2 )    { return v1 % v2; }
inline float  mod( float v1, float v2 )    { return std::fmod( v1, v2 ); }
inline double mod( double v1, double v2 )  { return std::fmod( v1, v2 ); }

inline long   merge( long v1, long v2 )      { return std::max(v1,v2); }
inline int    merge( int v1, int v2 )        { return std::max(v1,v2); }
inline short  merge( short v1, short v2 )    { return std::max(v1,v2); }
inline float  merge( float v1, float v2 )    { return std::max(v1,v2); }
inline double merge( double v1, double v2 )  { return std::max(v1,v2); }

inline long    join( long v1, long v2 )      { return std::min(v1,v2); }
inline int     join( int v1, int v2 )        { return std::min(v1,v2); }
inline short   join( short v1, short v2 )    { return std::min(v1,v2); }
inline float   join( float v1, float v2 )    { return std::min(v1,v2); }
inline double  join( double v1, double v2 )  { return std::min(v1,v2); }

template < class Units, class BasePoint> class GenericPointT : public BasePoint
{
public:
    typedef Units component_type;

	typedef GenericPointT PointT;
	
	      BasePoint &base()       { return *this; }
	const BasePoint &base() const { return *this; }
	
public:
	GenericPointT()                                               { construct(0,0); }
	GenericPointT(const Units &h,const Units &v)                  { construct(h,v); }
	GenericPointT(BasePoint pc) : BasePoint(pc) {}
// GenericPointT(const GenericPointT &);
// PointT &operator =(const PointT &);
   PointT &operator =(BasePoint pc) { base() = pc; return *this; }

	Units    h() const { return base().x(); }
	Units    v() const { return base().y(); }
	Units   &h()       { return base().x(); }
	Units   &v()       { return base().y(); }

	PointT &h(const Units &u)               { x() = u; return *this; }
	PointT &v(const Units &u)               { y() = u; return *this; }
	
	bool eql(const PointT &p2) const        { return ( (x() == p2.x()) && (y() == p2.y()) ); }
	bool leq(const PointT &p2) const        { return ( (x() <= p2.x()) && (y() <= p2.y()) ); }
	bool lt(const PointT &p2) const         { return ( (x() <  p2.x()) && (y() <  p2.y()) ); }
	PointT &negate()                        { x() = -x(); y() = -y(); return *this; }
	
	PointT &operator +=(const PointT &p2)    { x() += p2.x(); y() += p2.y(); return *this; }
	PointT &operator -=(const PointT &p2)    { x() -= p2.x(); y() -= p2.y(); return *this; }
	PointT &operator *=( double s)           { Convert<double,Units> conv; conv( x() * s, x() ); conv( y() * s, y() ); return *this; }
	PointT &operator *=( int s)              { x() *= s; y() *= s; return *this; }
	PointT &operator *=(const PointT &d)     { x() *= d.x(); y() *= d.y(); return *this; }
	PointT &operator /=( double s )          { Convert<double,Units> conv; conv( x() / s, x() ); conv( y() / s, y() ); return *this; }
	PointT &operator /=( int s )             { x() /= s; y() /= s; return *this; }
	PointT &operator /=(const PointT &d)     { x() /= d.x(); y() /= d.y(); return *this; }
	PointT &operator %=( const PointT &p )   { mod_assign( x() , p.x() ); mod_assign( y() ,p.y() ); return *this; }
	
	PointT &merge_assign( const PointT &p )  { x() = merge( x(),p.x() ); y() = merge( y(), p.y() ); return *this; }
	PointT &join_assign( const PointT &p )   { x() = join( x(), p.x() ); y() = join( y(), p.y() ); return *this; }
	
	bool  operator ==(const PointT &p2) const { return eql(p2); }
	bool  operator  <(const PointT &p2) const { return lt(p2); }
#ifdef _GATAN_COMPILER_DONT_USE_TEMPLATE_COMPARISON_OPERATORS
	bool  operator !=(const PointT &p2) const { return !eql(p2); }			// Use template '!='
	bool  operator <=(const PointT &p2) const { return (leq(p2)); }
	bool  operator  >(const PointT &p2) const { return p2.lt(*this); }
	bool  operator >=(const PointT &p2) const { return (p2.leq(*this)); }
#endif // _GATAN_COMPILER_DONT_USE_TEMPLATE_COMPARISON_OPERATORS

};

template <class U, class B >
	inline GenericPointT<U,B> operator +( const GenericPointT<U,B> &p1, const GenericPointT<U,B> &p2 )
		{ return GenericPointT<U,B>( p1.x() + p2.x(), p1.y() + p2.y() ); }

template <class U, class B>
	inline GenericPointT<U,B> operator -( const GenericPointT<U,B> &p1, const GenericPointT<U,B> &p2 )
		{ return GenericPointT<U,B>( p1.x() - p2.x(), p1.y() - p2.y() ); }

template <class U, class B>
	inline GenericPointT<U,B> operator *( double s, const GenericPointT<U,B> &p1 )
		{ return GenericPointT<U,B>( Gatan::numeric_convert<double,U>( p1.x()*s )
                                   , Gatan::numeric_convert<double,U>( p1.y()*s ) ); }

template <class U, class B>
	inline GenericPointT<U,B> operator *( int s, const GenericPointT<U,B> &p1 )
		{ return GenericPointT<U,B>( (U) (p1.x() * s), (U) (p1.y() * s) ); }

template <class U, class B>
	inline GenericPointT<U,B> operator *( const GenericPointT<U,B> &p1, double s )
		{ return GenericPointT<U,B>( Gatan::numeric_convert<double,U>(p1.x() * s), Gatan::numeric_convert<double,U>(p1.y() * s) ); }

template <class U, class B>
	inline GenericPointT<U,B> operator *( const GenericPointT<U,B> &p1, int s )
		{ return GenericPointT<U,B>( (U) (p1.x() * s), (U) (p1.y() * s) ); }

template <class U, class B>
	inline GenericPointT<U,B> operator *( const GenericPointT<U,B> &p1, const GenericPointT<U,B> &p2 )
		{ return GenericPointT<U,B>( p1.x() * p2.x(), p1.y() * p2.y() ); }

template <class U, class B>
	inline GenericPointT<U,B> operator /( const GenericPointT<U,B> &p1, double s )
		{ return GenericPointT<U,B>( Gatan::numeric_convert<double,U>(p1.x() / s), Gatan::numeric_convert<double,U>(p1.y() / s) ); }

template <class U, class B>
	inline GenericPointT<U,B> operator /( const GenericPointT<U,B> &p1, int s )
		{ return GenericPointT<U,B>( p1.x() / s, p1.y() / s ); }

template <class U, class B>
	inline GenericPointT<U,B> operator /( const GenericPointT<U,B> &p1, const GenericPointT<U,B> &p2 )
		{ return GenericPointT<U,B>( p1.x() / p2.x(), p1.y() / p2.y() ); }

template <class U, class B>
	inline GenericPointT<U,B> operator %( const GenericPointT<U,B> &p1, int s )
		{ return GenericPointT<U,B>( mod(p1.x(),s), mod(p1.y(),s) ); }

template <class U, class B>
	inline GenericPointT<U,B> operator %( const GenericPointT<U,B> &p1, const GenericPointT<U,B> &p2 )
		{ return GenericPointT<U,B>( mod(p1.x(),p2.x()), mod(p1.y(),p2.y()) ); }

template <class U, class B>
	inline GenericPointT<U,B> operator -( const GenericPointT<U,B> &p1 )
		{ return GenericPointT<U,B>( -p1.x(), -p1.y() ); }

namespace Gatan
{
	template <class Arg1, class Arg2> struct Convert;

    template <class Arg1, class Arg2> struct ConvertPointToPoint
    {
        inline void operator()( const Arg1 &a1, Arg2 &a2 ) const
        {
            typedef typename Arg1::component_type comp_1_type;
            typedef typename Arg2::component_type comp_2_type;
            Convert<comp_1_type,comp_2_type> conv;
            conv( a1.x(), a2.x() );
            conv( a1.y(), a2.y() );
        }
    };
}

#endif // __GATAN_POINTTEMPLATES__

