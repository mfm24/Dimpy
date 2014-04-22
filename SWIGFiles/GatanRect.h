
#ifndef __GATAN_RECTTEMPLATES__
#define __GATAN_RECTTEMPLATES__

#include "GatanDefines.h"
#include "GatanTypeConversion.h"
#include "GatanPoint.h"

/* Bounds
 *
 *    assertions: 1) A.bounds.A.x.( bounds.has_content() ==> bounds.contains( bounds.nearest( x ) ) );
 *
 */

class GFLongBound
{
public:
	static bool in_below( long bound, long val ) { return ( val >= bound ); }
	static bool in_above( long bound, long val ) { return ( val < bound ); }
	static long next_below( long bound ) { return bound; }
	static long prev_above( long bound ) { return bound - 1; }
};
class GFShortBound
{
public:
	static bool in_below( short bound, short val ) { return ( val >= bound ); }
	static bool in_above( short bound, short val ) { return ( val < bound ); }
	static short next_below( short bound ) { return bound; }
	static short prev_above( short bound ) { return bound - 1; }
};
class GFDoubleBound
{
public:
	static bool   in_below( double bound, double val ) { return ( val >= bound ); }
	static bool   in_above( double bound, double val ) { return ( val <= bound ); }
	static double next_below( double bound ) { return bound; }
	static double prev_above( double bound ) { return bound; }
};

template <class Units,class Bound> class GenBoundsT
{
public:
    typedef Units component_type;
	typedef GenBoundsT Bounds;
private:
	Units min_;
	Units max_;
public:
	GenBoundsT( const Units &min, const Units &max ) : min_(min), max_(max) {}
	
	Units low() const  { return min_; }
	Units high() const  { return max_; }
	Units &low()       { return min_; }
	Units &migh()       { return max_; }
	
	static void  swap( Units &u1, Units &u2 ) { Units tmp = u2; u2 = u1; u1 = tmp; }

	Bounds &intersection_assign( const Bounds &b2 )
			{ min_ = std::max( min_, b2.min_ ); max_ = std::min( max_, b2.max_ ); return *this; }
	Bounds &union_assign( const Bounds &b2 )
			{ min_ = std::min( min_, b2.min_ ); max_ = std::max( max_, b2.max_ ); return *this; }

	bool has_content() const   { return max_ > min_; }
	bool is_normalized() const { return max_ >= min_; }
	Bounds &make_normalized()     { if ( max_ < min_ ) { swap( max_, min_ ); } return *this; }

	bool contains( const Units &u )       { return Bound::in_below( min_, u ) && Bound::in_above( max_, u ); }
	bool contains( const Bounds &inner )  { return ( inner.min_ >= min_ ) && ( inner.max_ <= max_ ); }
	Units nearest( const Units &u )
		{ return Bound::in_below( min_, u )?( Bound::in_above( max_, u )? u: Bound::prev_above( max_ ) ):Bound::next_below( min_ ); }
	
	friend Bounds intersection( const Bounds &b1, const Bounds &b2 ) { Bounds tmp(b1); return tmp.intersection_assign(b2); }
	friend Bounds union_( const Bounds &b1, const Bounds &b2 )       { Bounds tmp(b1); return tmp.union_assign(b2); }
};

enum Rect_PT    { rect_PT };
enum Rect_TL_BR { rect_TL_BR };		// top-left and bottom-right
enum Rect_TL_SZ { rect_TL_SZ };		// top-left and size
enum Rect_MD_SZ { rect_MD_SZ };		// midpoint and size
enum Rect_TLBR  { rect_TLBR };		// top-left-bottom-right
enum Rect_LTWH  { rect_LTWH };		// left-top-width-height

template <class Units,class Bounds, class BasePoint, class BaseRect> class GenericRectT : public BaseRect
{
public:
    typedef Units component_type;
	typedef GenericRectT RectT;
	typedef GenericPointT<Units,BasePoint> PointT;
private:
          BaseRect &base()       { return *this; }
	const BaseRect &base() const { return *this; }

public:
	void construct( const PointT &tl, const PointT &sz, Rect_TL_SZ ) { base().construct( tl.x(), tl.y(), tl.x() + sz.x(), tl.y() + sz.y() ); }
	void construct( const PointT &tl, const PointT &br, Rect_TL_BR ) { base().construct( tl.x(), tl.y(), br.x(), br.y() ); }
	void construct( const Units &t,const Units &l,const Units &b,const Units &r)             { base().construct(l,t,r,b); }
	void construct( const Units &t,const Units &l,const Units &b,const Units &r, Rect_TLBR)  { base().construct(l,t,r,b); }
	void construct( const Units &l,const Units &t,const Units &w,const Units &h, Rect_LTWH ) { base().construct(l,t,l+w,t+h); }

	GenericRectT()                                                                        { base().construct(0,0,0,0); }
	GenericRectT(const Units &t,const Units &l,const Units &b,const Units &r )            { construct(t,l,b,r,rect_TLBR); }
	GenericRectT(const Units &t,const Units &l,const Units &b,const Units &r, Rect_TLBR ) { construct(t,l,b,r,rect_TLBR); }
	GenericRectT(const Units &l,const Units &t,const Units &w,const Units &h, Rect_LTWH ) { construct(l,t,w,h,rect_LTWH); }
	GenericRectT( const BaseRect &br) : BaseRect(br) {}
	GenericRectT( const Bounds &vb, const Bounds &hb )             { base().construct( hb.low(), vb.low(),hb.high(), vb.high() ); }
	GenericRectT( const PointT &tl, const PointT &br, Rect_TL_BR ) { construct(tl,br,rect_TL_BR); }
	GenericRectT( const PointT &pt , Rect_PT )                     { construct(pt,pt,rect_TL_BR); }
	GenericRectT( const PointT &tl, const PointT &sz, Rect_TL_SZ ) { construct(tl,sz,rect_TL_SZ ); }
	GenericRectT( const PointT &md, const PointT &sz, Rect_MD_SZ ) { construct( md - sz/2, sz, rect_TL_SZ ); }
	
	void assign( const BaseRect &br ) { base() = br; }
	void assign( const Units &top, const Units &left, const Units &bottom, const Units &right )
		{ construct(top, left, bottom, right, rect_TLBR ); }
	void assign( const Bounds &vb, const Bounds &hb ) { assign( vb.low(), hb.low(), vb.high(), hb.high() ); }

//  GenericRectT(const GenericRectT &);
//  GenericRectT &operator =(const GenericRectT &);
	GenericRectT &operator =( const BaseRect &br) { assign(br); return *this; }


	Units top() const		{ return base().top(); }
	Units left() const		{ return base().left(); }
	Units bottom() const	{ return base().bottom(); }
	Units right() const		{ return base().right(); }
	Units &top()			{ return base().top(); }
	Units &left()			{ return base().left(); }
	Units &bottom()			{ return base().bottom(); }
	Units &right()			{ return base().right(); }

	Units height() const				{ return (bottom() - top()); }
	Units width() const					{ return (right() - left()); }
	PointT size() const					{ return PointT(width(),height()); }
	Bounds vertical_bounds() const		{ return Bounds( top(), bottom() ); }
	Bounds horizontal_bounds() const	{ return Bounds( left(), right() ); }

	PointT top_left() const				{ return PointT(left(),top()); }
	PointT top_right() const			{ return PointT(right(),top()); }
	PointT bottom_left() const			{ return PointT(left(),bottom()); }
	PointT bottom_right() const			{ return PointT(right(),bottom()); }
	PointT mid() const					{ return PointT( left() + width() / 2, top() + height() / 2 ); }
	
	RectT &top(const Units &t)			{ top() = t; return *this; }
	RectT &left(const Units &l)			{ left() = l; return *this; }
	RectT &bottom(const Units &b)		{ bottom() = b; return *this; }
	RectT &right(const Units &r)		{ right() = r; return *this; }
	
	RectT &top_left(const PointT &tl)	{ top() = tl.y(); left() = tl.x(); return *this; }
	RectT &top_right(const PointT &tr)	{ top() = tr.y(); right() = tr.x(); return *this; }
	RectT &bottom_left(const PointT &bl)	{ bottom() = bl.y(); left() = bl.x(); return *this; }
	RectT &bottom_right(const PointT &br){ bottom() = br.y(); right() = br.x(); return *this; }

#if !defined( _GATAN_COMPILER_VISUAL_CPP )
	RectT &top_left_move( const PointT &tl)		{ operator += ( tl - top_left() ); return *this; }
	RectT &top_right_move( const PointT &tr)	{ operator += ( tr - top_right() ); return *this; }
	RectT &bottom_left_move( const PointT &bl)	{ operator += ( bl - bottom_left() ); return *this; }
	RectT &bottom_right_move( const PointT &br)	{ operator += ( br - bottom_right() ); return *this; }
	RectT &mid_move(const PointT &m)			{ operator += ( m - mid() ); return *this; }
#else
	RectT &top_left_move( const PointT &tl)		{ operator += ( PointT( tl.x() - left(), tl.y() - top() ) ); return *this; }
	RectT &top_right_move( const PointT &tr)	{ operator += ( PointT( tr.x() - right(), tr.y() - top() ) ); return *this; }
	RectT &bottom_left_move( const PointT &bl)	{ operator += ( PointT( bl.x() - left(), bl.y() - bottom() ) ); return *this; }
	RectT &bottom_right_move( const PointT &br)	{ operator += ( PointT( br.x() - right(), br.y() - bottom() ) ); return *this; }
	RectT &mid_move(const PointT &m)			{ operator += ( PointT( m.x() - mid().x(), m.y() - mid().y() ) ); return *this; }
#endif

	RectT &height(const Units &h)				{ bottom() = top() + h; return *this; }
	RectT &width(const Units &w)				{ right() = left() + w; return *this; }
	RectT &size(const PointT &s)				{ height(s.y()); width(s.x());  return *this; }
	RectT &vertical_bounds( const Bounds &vb )	{ top() = vb.low(); bottom() = vb.high(); return *this; }
	RectT &horizontal_bounds( const Bounds &hb ){ left() = hb.low(); right() = hb.high(); return *this; }

	RectT  top(const Units &t) const 			{ RectT tmp(*this); return tmp.top(t); }
	RectT  left(const Units &l) const			{ RectT tmp(*this); return tmp.left(l); }
	RectT  bottom(const Units &b) const			{ RectT tmp(*this); return tmp.bottom(b); }
	RectT  right(const Units &r) const			{ RectT tmp(*this); return tmp.right(r); }
	
	RectT  top_left(const PointT &tl) const		{ RectT tmp(*this); return tmp.top_left(tl); }
	RectT  top_right(const PointT &tr) const	{ RectT tmp(*this); return tmp.top_right(tr); }
	RectT  bottom_left(const PointT &bl) const	{ RectT tmp(*this); return tmp.bottom_left(bl); }
	RectT  bottom_right(const PointT &br) const	{ RectT tmp(*this); return tmp.bottom_right(br); }

	RectT  top_left_move(const PointT &tl) const	{ RectT tmp(*this); return tmp.top_left_move(tl); }
	RectT  top_right_move(const PointT &tr) const	{ RectT tmp(*this); return tmp.top_right_move(tr); }
	RectT  bottom_left_move(const PointT &bl) const	{ RectT tmp(*this); return tmp.bottom_left_move(bl); }
	RectT  bottom_right_move(const PointT &br) const{ RectT tmp(*this); return tmp.bottom_right_move(br); }
	RectT  mid_move(const PointT &m) const			{ RectT tmp(*this); return tmp.mid_move(m); }
	
	RectT  height(const Units &h) const	{ RectT tmp(*this); return tmp.height(h); }
	RectT  width(const Units &w) const	{ RectT tmp(*this); return tmp.width(w); }
	RectT  size(const PointT &s) const	{ RectT tmp(*this); return tmp.size(s); }
	RectT  vertical_bounds( const Bounds &vb ) const { RectT tmp(*this); return tmp.vertical_bounds(vb); }
	RectT  horizontal_bounds( const Bounds &hb ) const { RectT tmp(*this); return tmp.horizontal_bounds(hb); }


	bool has_content() const			{ return vertical_bounds().has_content()   && horizontal_bounds().has_content(); }
	bool is_normalized() const          { return vertical_bounds().is_normalized() && horizontal_bounds().is_normalized(); }

	bool eql(const RectT &r2) const
	{
#if !defined( _GATAN_COMPILER_VISUAL_CPP )
		return ( (top_left() == r2.top_left()) && (bottom_right() == r2.bottom_right()));
#else
		return ( (top() == r2.top()) && (left() == r2.left()) && (bottom() == r2.bottom()) && (right() == r2.right()) );
#endif
	}
	bool contains(const RectT &r2) const
	{
		return vertical_bounds().contains( r2.vertical_bounds() ) && horizontal_bounds().contains( r2.horizontal_bounds() );
	}
	bool contains(const PointT &p) const
	{
		return vertical_bounds().contains( p.y() ) && horizontal_bounds().contains( p.x() );
	}
	
	RectT &operator +=(const PointT &p)	{ top() += p.y(); bottom() += p.y(); left() += p.x(); right() += p.x(); return *this; }
	RectT &operator -=(const PointT &p)	{ top() -= p.y(); bottom() -= p.y(); left() -= p.x(); right() -= p.x(); return *this; }
	RectT &negate()						{ top() = -top(); bottom() = -bottom(); left() = -left(); right() = -right(); return *this; }
	RectT &operator +=(const RectT &r)	{ top() += r.top(); bottom() += r.bottom(); left() += r.left(); right() += r.right(); return *this; }
	RectT &operator -=(const RectT &r)	{ top() -= r.top(); bottom() -= r.bottom(); left() -= r.left(); right() -= r.right(); return *this; }
	RectT &operator *=(const Units &u)  { top() *= u;   bottom() *= u;   left() *= u;   right() *= u;   return *this; }
	RectT &operator *=(const PointT &p)	{ top() *= p.y(); bottom() *= p.y(); left() *= p.x(); right() *= p.x(); return *this; }
	RectT &operator *=( double s)       { top() *= s; bottom() *= s; left() *= s; right() *= s; return *this; }
	RectT &operator *=( int s)	        { top() *= s; bottom() *= s; left() *= s; right() *= s; return *this; }
	RectT &operator /=( double s )	    { top() /= s;   bottom() /= s;   left() /= s;   right() /= s;   return *this; }
	RectT &operator /=( int s)	        { top() /= s;   bottom() /= s;   left() /= s;   right() /= s;   return *this; }
	RectT &operator /=(const PointT &p)	{ top() /= p.y(); bottom() /= p.y(); left() /= p.x(); right() /= p.x(); return *this; }
	RectT &operator %=(const Units &u)	{ mod_assign( top(), u );   mod_assign( bottom(), u ); mod_assign( left(), u ); mod_assign( right(), u );   return *this; }
	RectT &operator %=(const PointT &p)	{ mod_assign( top(), p.y() ); mod_assign( bottom(), p.y() ); mod_assign( left(), p.x() ); mod_assign( right(), p.x() ); return *this; }
	RectT &inset(const PointT &amount )	{ top() += amount.y(); left() += amount.x(); bottom() -= amount.y(); right() -= amount.x(); return *this; }
	RectT &inset(const Units &h, const Units &v)	{ return inset( PointT( h, v ) ); }
	RectT &inset(const Units &u)		         	{ return inset( PointT( u, u ) ); }

	RectT &intersection_assign(const RectT &r)
	{
		Bounds vb = vertical_bounds();
		Bounds hb = horizontal_bounds();
		assign( vb.intersection_assign( r.vertical_bounds() )
		      , hb.intersection_assign( r.horizontal_bounds() ) );
		return *this;
	}
	bool intersects(const RectT &r2) const
	{
		RectT tmp(*this); return tmp.intersection_assign(r2).has_content();
	}
	
	RectT &union_assign(const RectT &r)
	{
		Bounds vb = vertical_bounds();
		Bounds hb = horizontal_bounds();
		assign( vb.union_assign( r.vertical_bounds() )
		      , hb.union_assign( r.horizontal_bounds() ) );
		return *this;
	}
	
	PointT nearest_point( const PointT &p) const
	{
		return PointT( horizontal_bounds().nearest( p.x() ), vertical_bounds().nearest( p.y() ) );
	}

	bool operator ==(const RectT &r2) const { return eql(r2); }
	bool operator !=(const RectT &r2) const { return !eql(r2); }		// Use template definition in <utility>

};

template <class U, class B, class P, class R>
	inline GenericRectT<U,B,P,R> inset( const GenericRectT<U,B,P,R> &r1, const GenericPointT<U,P> &p )
		{ return GenericRectT<U,B,P,R>( r1.top() + p.y(), r1.left() + p.x(), r1.bottom() - p.y(), r1.right() - p.x() ); }
		
template <class U, class B, class P, class R>
	inline GenericRectT<U,B,P,R> inset( const GenericRectT<U,B,P,R> &r1, double u )
		{ return GenericRectT<U,B,P,R>( r1.top() + u, r1.left() + u, r1.bottom() - u, r1.right() - u ); }

template <class U, class B, class P, class R>
	inline GenericRectT<U,B,P,R> inset( const GenericRectT<U,B,P,R> &r1, int u )
		{ return GenericRectT<U,B,P,R>( r1.top() + u, r1.left() + u, r1.bottom() - u, r1.right() - u ); }

template <class U, class B, class P, class R>
	bool intersects( const GenericRectT<U,B,P,R> &r1, const GenericRectT<U,B,P,R> &r2 )
		{ return r1.intersects(r2); }
		
template <class U, class B, class P, class R>
	GenericRectT<U,B,P,R> intersection( const GenericRectT<U,B,P,R> &r1, const GenericRectT<U,B,P,R> &r2 )
		{ GenericRectT<U,B,P,R> tmp(r1); return tmp.intersection_assign(r2); }
		
template <class U, class B, class P, class R>
	GenericRectT<U,B,P,R> union_( const GenericRectT<U,B,P,R> &r1, const GenericRectT<U,B,P,R> &r2 )
		{ GenericRectT<U,B,P,R> tmp(r1); return tmp.union_assign(r2); }
		
template <class U, class B, class P, class R>
	GenericRectT<U,B,P,R> operator +( const GenericRectT<U,B,P,R> &r1, const GenericRectT<U,B,P,R> &r2 )
		{ return GenericRectT<U,B,P,R>( r1.top() + r2.top(), r1.left() + r2.left(), r1.bottom() + r2.bottom(), r1.right() + r2.right() ); }

template <class U, class B, class P, class R>
	GenericRectT<U,B,P,R> operator -( const GenericRectT<U,B,P,R> &r1, const GenericRectT<U,B,P,R> &r2 )
		{ return GenericRectT<U,B,P,R>( r1.top() - r2.top(), r1.left() - r2.left(), r1.bottom() - r2.bottom(), r1.right() - r2.right() ); }

template <class U, class B, class P, class R>
	GenericRectT<U,B,P,R> operator +( const GenericRectT<U,B,P,R> &r, const GenericPointT<U,P> &p )
		{ return GenericRectT<U,B,P,R>( r.top() + p.y(), r.left() + p.x(), r.bottom() + p.y(), r.right() + p.x() ); }

template <class U, class B, class P, class R>
	GenericRectT<U,B,P,R> operator +( const GenericPointT<U,P> &p, const GenericRectT<U,B,P,R> &r )
		{ return GenericRectT<U,B,P,R>( r.top() + p.y(), r.left() + p.x(), r.bottom() + p.y(), r.right() + p.x() ); }

template <class U, class B, class P, class R>
	GenericRectT<U,B,P,R> operator -( const GenericRectT<U,B,P,R> &r, const GenericPointT<U,P> &p )
		{ return GenericRectT<U,B,P,R>( r.top() - p.y(), r.left() - p.x(), r.bottom() - p.y(), r.right() - p.x() ); }

template <class U, class B, class P, class R>
	GenericRectT<U,B,P,R> operator -( const GenericPointT<U,P> &p, const GenericRectT<U,B,P,R> &r )
		{ return GenericRectT<U,B,P,R>( r.top() - p.y(), r.left() - p.x(), r.bottom() - p.y(), r.right() - p.x() ); }

template <class U, class B, class P, class R>
	GenericRectT<U,B,P,R> operator *( const GenericRectT<U,B,P,R> &r, int u )
		{ return GenericRectT<U,B,P,R>( r.top() * u, r.left() * u, r.bottom() * u , r.right() * u ); }

template <class U, class B, class P, class R>
	GenericRectT<U,B,P,R> operator *( const GenericRectT<U,B,P,R> &r, double u )
		{ return GenericRectT<U,B,P,R>( r.top() * u, r.left() * u, r.bottom() * u , r.right() * u ); }

template <class U, class B, class P, class R>
	GenericRectT<U,B,P,R> operator *( int u, const GenericRectT<U,B,P,R> &r )
		{ return GenericRectT<U,B,P,R>( r.top() * u, r.left() * u, r.bottom() * u , r.right() * u ); }

template <class U, class B, class P, class R>
	GenericRectT<U,B,P,R> operator *( double u, const GenericRectT<U,B,P,R> &r )
		{ return GenericRectT<U,B,P,R>( r.top() * u, r.left() * u, r.bottom() * u , r.right() * u ); }

template <class U, class B, class P, class R, class U2, class P2>
	GenericRectT<U,B,P,R> operator *( const GenericRectT<U,B,P,R> &r, const GenericPointT<U2,P2> &p )
		{ return GenericRectT<U,B,P,R>( r.top() * p.y(), r.left() * p.x(), r.bottom() * p.y(), r.right() * p.x() ); }

template <class U, class B, class P, class R, class U2, class P2>
	GenericRectT<U,B,P,R> operator *( const GenericPointT<U2,P2> &p, const GenericRectT<U,B,P,R> &r )
		{ return GenericRectT<U,B,P,R>( r.top() * p.y(), r.left() * p.x(), r.bottom() * p.y(), r.right() * p.x() ); }

template <class U, class B, class P, class R>
	GenericRectT<U,B,P,R> operator /( const GenericRectT<U,B,P,R> &r, int u )
		{ return GenericRectT<U,B,P,R>( r.top() / u, r.left() / u, r.bottom() / u , r.right() / u ); }

template <class U, class B, class P, class R>
	GenericRectT<U,B,P,R> operator /( const GenericRectT<U,B,P,R> &r, double u )
		{ return GenericRectT<U,B,P,R>( r.top() / u, r.left() / u, r.bottom() / u , r.right() / u ); }

template <class U, class B, class P, class R>
	GenericRectT<U,B,P,R> operator /( const GenericRectT<U,B,P,R> &r, const GenericPointT<U,P> &p )
		{ return GenericRectT<U,B,P,R>( r.top() / p.y(), r.left() / p.x(), r.bottom() / p.y(), r.right() / p.x() ); }

template <class U, class B, class P, class R>
	GenericRectT<U,B,P,R> operator %( const GenericRectT<U,B,P,R> &r, int u )
		{ return GenericRectT<U,B,P,R>( mod( r.top() , u ), mod( r.left() , u ), mod( r.bottom() , u ), mod( r.right() , u ) ); }

template <class U, class B, class P, class R>
	GenericRectT<U,B,P,R> operator %( const GenericRectT<U,B,P,R> &r, double u )
		{ return GenericRectT<U,B,P,R>( mod( r.top() , u ), mod( r.left() , u ), mod( r.bottom() , u ), mod( r.right() , u ) ); }

template <class U, class B, class P, class R>
	GenericRectT<U,B,P,R> operator %( const GenericRectT<U,B,P,R> &r, const GenericPointT<U,P> &p )
		{ return GenericRectT<U,B,P,R>( mod( r.top() , p.y() ), mod( r.left() , p.x() ), mod( r.bottom() , p.y() ), mod( r.right() , p.x() ) ); }

template <class U, class B, class P, class R>
	GenericRectT<U,B,P,R> operator -( const GenericRectT<U,B,P,R> &r )
		{ return GenericRectT<U,B,P,R>( -r.top(), -r.left(), -r.bottom(), -r.right() ); }

template <class U, class B, class P, class R>
	GenericRectT<U,B,P,R> operator +( const GenericRectT<U,B,P,R> &r )
		{ return r; }

template <class U, class B, class P, class R>
	GenericRectT<U,B,P,R> give_content( const GenericRectT<U,B,P,R> &r )
		{ return GenericRectT<U,B,P,R>( r.vertical_bounds().make_normalized(), r.horizontal_bounds().make_normalized() ); }

template <class U, class B, class P, class R>
	GenericRectT<U,B,P,R> normalize( const GenericRectT<U,B,P,R> &r )
		{ return r.has_content()?r:GenericRectT<U,B,P,R>(0,0,0,0); }



template <class U, class B, class P, class R>
	GenericRectT<U,B,P,R> rect_on_top( const GenericRectT<U,B,P,R> &r, const U &u )
		{ GenericRectT<U,B,P,R> tmp(r); tmp.bottom() = r.top(); tmp.top() = r.top() - u; return tmp; }
template <class U, class B, class P, class R>
	GenericRectT<U,B,P,R> rect_on_left( const GenericRectT<U,B,P,R> &r, const U &u )
		{ GenericRectT<U,B,P,R> tmp(r); tmp.right() = r.left(); tmp.left() = r.left() - u; return tmp; }
template <class U, class B, class P, class R>
	GenericRectT<U,B,P,R> rect_on_bottom( const GenericRectT<U,B,P,R> &r, const U &u )
		{ GenericRectT<U,B,P,R> tmp(r); tmp.top() = r.bottom(); tmp.bottom() = r.bottom() + u; return tmp; }
template <class U, class B, class P, class R>
	GenericRectT<U,B,P,R> rect_on_right( const GenericRectT<U,B,P,R> &r, const U &u )
		{ GenericRectT<U,B,P,R> tmp(r); tmp.left() = r.right(); tmp.right() = r.right() + u; return tmp; }
			
template <class U, class B, class P, class R>
	GenericRectT<U,B,P,R> flip_x( const GenericRectT<U,B,P,R> &r )
		{ return GenericRectT<U,B,P,R>( r.top(), r.right(), r.bottom(), r.left(), rect_TLBR ); }
template <class U, class B, class P, class R>
	GenericRectT<U,B,P,R> flip_y( const GenericRectT<U,B,P,R> &r )
		{ return GenericRectT<U,B,P,R>( r.bottom(), r.left(), r.top(), r.right(), rect_TLBR ); }
template <class U, class B, class P, class R>
	GenericRectT<U,B,P,R> flip_xy( const GenericRectT<U,B,P,R> &r )
		{ return GenericRectT<U,B,P,R>( r.bottom(), r.right(), r.top(), r.left(), rect_TLBR ); }
	
namespace Gatan
{
	template <class Arg1, class Arg2> struct Convert;

    template <class Arg1, class Arg2> struct ConvertRectToRect
    {
        inline void operator()( const Arg1 &a1, Arg2 &a2 ) const
        {
            Convert<typename Arg1::component_type,typename Arg2::component_type> conv;
            conv( a1.top(), a2.top() );
            conv( a1.left(), a2.left() );
            conv( a1.bottom(), a2.bottom() );
            conv( a1.right(), a2.right() );
        }
    };
}

#ifndef __GATAN_BASETYPES__
#define __GATAN_BASETYPES__

namespace Gatan
{
	typedef GenericPointT< sint32, point2_sint32_0_t > LongPoint;
	typedef GenericRectT< sint32, GenBoundsT<long,GFLongBound>, point2_sint32_0_t, rect_sint32_1_t > LongRect;

} // namespace Gatan

typedef Gatan::LongRect GFLongRect;
typedef Gatan::LongPoint GFLongPoint;

// 'ShortPoint' must match the storage order on the mac, so we need 'x' first ( use variant '1' of point )

typedef GenericRectT< Gatan::sint16, GenBoundsT<Gatan::sint16,GFShortBound>, Gatan::point2_sint16_1_t, Gatan::rect_sint16_1_t > GFShortRect;
typedef GenericPointT< Gatan::sint16, Gatan::point2_sint16_1_t > GFShortPoint;

#endif // __GATAN_BASETYPES__

#endif // __GATAN_RECTTEMPLATES__
