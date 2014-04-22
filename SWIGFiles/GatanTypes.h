
#ifndef __GATAN_IMAGETYPES__
#define __GATAN_IMAGETYPES__

#include "GatanDefines.h"

#include <cmath>
#include <limits>

#if defined( _GATAN_COMPILER_METROWERKS )

	#if ( _GATAN_COMPILER_VERSION >= 0x2100 )
	#else
		typedef uint16 wchar_t;
	#endif // _GATAN_COMPILER_VERSION

#endif // defined( _GATAN_COMPILER_METROWERKS )

#if defined( _GATAN_COMPILER_VISUAL_CPP ) || defined( _GATAN_COMPILER_INTEL )
	#include <wchar.h>
#endif // defined( _GATAN_COMPILER_* )

namespace Gatan
{
enum Void {};
enum InvalidTypeEnum {};

typedef Void            void_t;
typedef InvalidTypeEnum invalid_t;

typedef unsigned short  ushort;
typedef unsigned long   ulong;
typedef unsigned int    uint;

typedef unsigned char    octet;

typedef          char    int8;
typedef   signed char	sint8;
typedef unsigned char	uint8;
typedef          short   int16;
typedef   signed short	sint16;
typedef unsigned short	uint16;
typedef          long    int32;
typedef   signed long 	sint32;
typedef unsigned long 	uint32;
#if defined( _GATAN_COMPILER_VISUAL_CPP )
	typedef   signed __int64 sint64;
	typedef unsigned __int64 uint64;
#else
	typedef   signed long long sint64;
	typedef unsigned long long uint64;
#endif // defined( _GATAN_COMPILER )
typedef float			float32;
typedef double			float64;

typedef wchar_t         uncchar;

typedef uint32            ulong_ptr_t;				// Type that can hold either a long or a ptr without loss

template <class SrcType, class DstType> struct conv_base
{
	typedef SrcType src_type;
	typedef DstType dst_type;
};

namespace numeric_data
{
	struct scalar_numeric_class_tag  {};
	struct complex_numeric_class_tag {};
	struct rgb_numeric_class_tag     {};
	struct rgba_numeric_class_tag    {};
	struct point2_numeric_class_tag  {};
	struct rect_numeric_class_tag    {};
}

struct binary8
{
	uint8 val;
	
	binary8() {}
	binary8( bool v )     { val = (uint8) (v?1:0); }
	operator bool() const { return ( val != 0 ); }
};

struct  complex64_t 
{
	struct IND { enum { REAL = 0, IMAG = 1 }; static ulong variant() { return 0; } };

	typedef float32 component_type;
	typedef numeric_data::complex_numeric_class_tag numeric_class;

	enum Img { IMG };
	
	component_type components[2];

	static ulong variant() { return IND::variant(); }

	gtn_force_inline const component_type *get_components() const { return &components[0]; }
	gtn_force_inline       component_type *get_components()       { return &components[0]; }

	gtn_force_inline void construct( float32 re_, float32 im_ ) { real() = re_; imag() = im_; }
	gtn_force_inline void construct_all( component_type comp_val ) { construct( comp_val, comp_val ); }
	
	gtn_force_inline  float32  real() const { return components[IND::REAL]; }
	gtn_force_inline  float32 &real()       { return components[IND::REAL]; }
	gtn_force_inline  float32  imag() const { return components[IND::IMAG]; }
	gtn_force_inline  float32 &imag()       { return components[IND::IMAG]; }
	
	gtn_force_inline  bool eql( const complex64_t &c2 ) const           { return ( real() == c2.real() ) && ( imag() == c2.imag() ); }
	
	gtn_force_inline  void mul_assign( float32 re_2, float32 im_2 )     { float32 re_ = ( real()*re_2 - imag()*im_2 ); imag() = real()*im_2 + imag()*re_2; real() = re_; }
	
	gtn_force_inline  complex64_t &conjugate_assign()                   { imag() = -imag(); return *this; }

	gtn_force_inline  complex64_t &operator +=( const complex64_t &c2 ) { real() += c2.real(); imag() += c2.imag(); return *this; }
	gtn_force_inline  complex64_t &operator -=( const complex64_t &c2 ) { real() -= c2.real(); imag() -= c2.imag(); return *this; }
	gtn_force_inline  complex64_t &operator *=( float32 s )             { real() *= s; imag() *= s; return *this; }
	gtn_force_inline  complex64_t &operator *=( const complex64_t &c2 ) { float32 re_ = ( real()*c2.real() - imag()*c2.imag() ); imag() = real()*c2.imag() + imag()*c2.real(); real() = re_; return *this; }
	gtn_force_inline  complex64_t &operator *=( Img )                   { float32 re_ = -imag(); imag() = real(); real() = re_; return *this; }
	gtn_force_inline  complex64_t &operator /=( float32 s )             { real() /= s; imag() /= s; return *this; }
	gtn_force_inline  complex64_t &operator /=( const complex64_t &c2 ) { float32 nrm = c2.real()*c2.real()+c2.imag()*c2.imag(); mul_assign(c2.real(),-c2.imag()); operator /=( nrm ); return *this; }
	gtn_force_inline  complex64_t &operator /=( Img )                   { float32 re_ = imag(); imag() = -real(); real() = re_; return *this; }

	static gtn_force_inline  ulong comp_index( ulong i_comp )
	{
		ulong act_index = 0;
		switch( i_comp )
		{
			case 0: act_index = 0; break;
			case 1: act_index = 1; break;
		}
		return act_index;
	}

	gtn_force_inline  bool      operator==( const complex64_t &c2 ) const { return eql(c2); }	
	gtn_force_inline  bool      operator!=( const complex64_t &c2 ) const { return !eql(c2); }	
};

struct complex64 : public complex64_t
{
	gtn_force_inline  complex64() {}
	gtn_force_inline  complex64( float32 re_, float32 im_ = 0.0f ) { construct( re_, im_ ); }
	gtn_force_inline  complex64( const complex64_t &c )            : complex64_t(c) {}
	gtn_force_inline  complex64( Img )                             { construct( 0.0f, 1.0 ); }
};

gtn_force_inline  complex64_t conjugate( const complex64_t &c )                         { return complex64( c.real(), -c.imag() ); }
gtn_force_inline  float32   norm_squared( const complex64_t &c )                        { return c.real()*c.real() + c.imag()*c.imag(); }
gtn_force_inline  float32   abs( const complex64_t &c )                                 { return (float32) std::sqrt(c.real()*c.real() + c.imag()*c.imag()); }
gtn_force_inline  complex64_t operator-( const complex64_t &c )                         { return complex64( -c.real(), -c.imag() ); }
gtn_force_inline  complex64_t operator+( const complex64_t &c1, const complex64_t &c2 ) { return complex64( c1.real()+c2.real(),c1.imag()+c2.imag() ); }
gtn_force_inline  complex64_t operator+( float32 r1, const complex64_t &c2 )            { return complex64( r1+c2.real(),c2.imag() ); }
gtn_force_inline  complex64_t operator+( const complex64_t &c1, float32 r2 )            { return complex64( r2+c1.real(),c1.imag() ); }
gtn_force_inline  complex64_t operator-( const complex64_t &c1, const complex64_t &c2 ) { return complex64( c1.real()-c2.real(),c1.imag()-c2.imag() ); }
gtn_force_inline  complex64_t operator-( float32 r1, const complex64_t &c2 )            { return complex64( r1-c2.real(),-c2.imag() ); }
gtn_force_inline  complex64_t operator-( const complex64_t &c1, float32 r2 )            { return complex64( c1.real()-r2,c1.imag() ); }
gtn_force_inline  complex64_t operator*( const complex64_t &c1, float32 s )             { return complex64( c1.real() * s, c1.imag() * s ); }
gtn_force_inline  complex64_t operator*( const complex64_t &c1, float64 s )             { return complex64( (float32)( c1.real() * s ), (float32) (c1.imag() * s) ); }
gtn_force_inline  complex64_t operator*( float32 s, const complex64_t &c1 )             { return complex64( c1.real() * s, c1.imag() * s ); }
gtn_force_inline  complex64_t operator*( float64 s, const complex64_t &c1 )             { return complex64( (float32) ( c1.real() * s ), (float32) ( c1.imag() * s ) ); }		// Needed becuse of *%*&(^%*&( VisualCPP operator overloading
gtn_force_inline  complex64_t operator*( const complex64_t &c1, complex64_t::Img )      { return complex64( -c1.imag(), c1.real() ); }
gtn_force_inline  complex64_t operator*( complex64_t::Img, const complex64_t &c2 )      { return complex64( -c2.imag(), c2.real() ); }
gtn_force_inline  complex64_t operator*( const complex64_t &c1, const complex64_t &c2 ) { complex64_t tmp( c1 ); return ( tmp *= c2 ); }
gtn_force_inline  complex64_t operator/( const complex64_t &c1, float32 s )             { return complex64( c1.real() / s, c1.imag() / s ); }
gtn_force_inline  complex64_t operator/( const complex64_t &c1, complex64_t::Img )      { return complex64( c1.imag(), -c1.real() ); }
gtn_force_inline  complex64_t operator/( complex64_t::Img, const complex64_t &c2 )      { return complex64( c2.imag(), -c2.real() ); }
gtn_force_inline  complex64_t operator/( const complex64_t &c1, const complex64_t &c2 ) { complex64_t tmp( c1 ); return ( tmp /= c2 ); }


struct  complex128_t
{
	struct IND { enum { REAL = 0, IMAG = 1 }; static ulong variant() { return 0; } };

	typedef float64 component_type;
	typedef numeric_data::complex_numeric_class_tag numeric_class;

	enum Img { IMG };

	component_type components[2];

	static ulong variant() { return IND::variant(); }

	gtn_force_inline const component_type *get_components() const { return &components[0]; }
	gtn_force_inline       component_type *get_components()       { return &components[0]; }

	gtn_force_inline  void construct( float64 re_, float64 im_ ) { real() = re_; imag() = im_; }
	gtn_force_inline void construct_all( component_type comp_val ) { construct( comp_val, comp_val ); }

	gtn_force_inline  bool eql( const complex128_t &c2 ) const { return ( real() == c2.real() ) && ( imag() == c2.imag() ); }

	gtn_force_inline  float64  real() const { return components[IND::REAL]; }
	gtn_force_inline  float64 &real()       { return components[IND::REAL]; }
	gtn_force_inline  float64  imag() const { return components[IND::IMAG]; }
	gtn_force_inline  float64 &imag()       { return components[IND::IMAG]; }
	
	gtn_force_inline  void mul_assign( float64 re_2, float64 im_2 )       { float64 re_ = ( real()*re_2 - imag()*im_2 ); imag() = real()*im_2 + imag()*re_2; real() = re_; }
	gtn_force_inline  complex128_t &conjugate_assign()                    { imag() = -imag(); return *this; }

	gtn_force_inline  complex128_t &operator +=( const complex128_t &c2 ) { real() += c2.real(); imag() += c2.imag(); return *this; }
	gtn_force_inline  complex128_t &operator -=( const complex128_t &c2 ) { real() -= c2.real(); imag() -= c2.imag(); return *this; }
	gtn_force_inline  complex128_t &operator *=( float64 s )              { real() *= s; imag() *= s; return *this; }
	gtn_force_inline  complex128_t &operator *=( const complex128_t &c2 ) { float64 re_ = ( real()*c2.real() - imag()*c2.imag() ); imag() = real()*c2.imag() + imag()*c2.real(); real() = re_; return *this; }
	gtn_force_inline  complex128_t &operator *=( Img )                    { float64 re_ = -imag(); imag() = real(); real() = re_; return *this; }
	gtn_force_inline  complex128_t &operator /=( float64 s )              { real() /= s; imag() /= s; return *this; }
	gtn_force_inline  complex128_t &operator /=( const complex128_t &c2 ) { float64 nrm = c2.real()*c2.real()+c2.imag()*c2.imag(); mul_assign(c2.real(),-c2.imag()); operator /=( nrm ); return *this; }
	gtn_force_inline  complex128_t &operator /=( Img )                    { float64 re_ = imag(); imag() = -real(); real() = re_; return *this; }
	
	gtn_force_inline  operator complex64_t() const { return complex64( (float32) real(), (float32) imag() ); }

	static gtn_force_inline  ulong comp_index( ulong i_comp )
	{
		ulong act_index = 0;
		switch( i_comp )
		{
			case 0: act_index = 0; break;
			case 1: act_index = 1; break;
		}
		return act_index;
	}

		
	gtn_force_inline  bool      operator==( const complex128_t &c2 ) const { return eql(c2); }	
	gtn_force_inline  bool      operator!=( const complex128_t &c2 ) const { return !eql(c2); }	
};

struct complex128 : public complex128_t
{
	gtn_force_inline  complex128() {}
	gtn_force_inline  complex128( float64 re_, float64 im_ = 0.0 ) { construct( re_, im_ ); }
	gtn_force_inline  complex128( const complex128_t &c )          : complex128_t(c) {}
	gtn_force_inline  complex128( const complex64_t &c )           { construct( c.real(), c.imag() ); }
	gtn_force_inline  complex128( Img )                            { construct( 0.0, 1.0 ); }
};


gtn_force_inline  complex128_t conjugate( const complex128_t &c )                          { return complex128( c.real(), -c.imag() ); }
gtn_force_inline  float64    norm_squared( const complex128_t &c )                         { return c.real()*c.real() + c.imag()*c.imag(); }
gtn_force_inline  float64    abs( const complex128_t &c )                                  { return (float64) std::sqrt(c.real()*c.real() + c.imag()*c.imag()); }
gtn_force_inline  complex128_t operator-( const complex128_t &c )                          { return complex128( -c.real(), -c.imag() ); }
gtn_force_inline  complex128_t operator+( const complex128_t &c1, const complex128_t &c2 ) { return complex128( c1.real()+c2.real(),c1.imag()+c2.imag() ); }
gtn_force_inline  complex128_t operator+( float64 r1, const complex128_t &c2 )             { return complex128( r1+c2.real(),c2.imag() ); }
gtn_force_inline  complex128_t operator+( const complex128_t &c1, float64 r2 )             { return complex128( c1.real()+r2,c1.imag() ); }
gtn_force_inline  complex128_t operator-( const complex128_t &c1, const complex128_t &c2 ) { return complex128( c1.real()-c2.real(),c1.imag()-c2.imag() ); }
gtn_force_inline  complex128_t operator-( float64 r1, const complex128_t &c2 )             { return complex128( r1-c2.real(),-c2.imag() ); }
gtn_force_inline  complex128_t operator-( const complex128_t &c1, float64 r2 )             { return complex128( c1.real()-r2,c1.imag() ); }
gtn_force_inline  complex128_t operator*( const complex128_t &c1, float64 s )              { return complex128( c1.real() * s, c1.imag() * s ); }
gtn_force_inline  complex128_t operator*( float64 s, const complex128_t &c1 )              { return complex128( c1.real() * s, c1.imag() * s ); }
gtn_force_inline  complex128_t operator*( const complex128_t &c1, complex128_t::Img )      { return complex128( -c1.imag(), c1.real() ); }
gtn_force_inline  complex128_t operator*( complex128_t::Img, const complex128_t &c2 )      { return complex128( -c2.imag(), c2.real() ); }
gtn_force_inline  complex128_t operator*( const complex128_t &c1, const complex128_t &c2 ) { complex128 tmp( c1 ); return ( tmp *= c2 ); }
gtn_force_inline  complex128_t operator/( const complex128_t &c1, float64 s )              { return complex128( c1.real() / s, c1.imag() / s ); }
gtn_force_inline  complex128_t operator/( const complex128_t &c1, complex128_t::Img )      { return complex128( c1.imag(), -c1.real() ); }
gtn_force_inline  complex128_t operator/( complex128_t::Img, const complex128_t &c2 )      { return complex128( c2.imag(), -c2.real() ); }
gtn_force_inline  complex128_t operator/( const complex128_t &c1, const complex128_t &c2 ) { complex128 tmp( c1 ); return ( tmp /= c2 ); }

struct rgb_indices_0  { enum { RED = 0, GREEN = 1, BLUE = 2 }; static ulong variant() { return 0; } };

struct rgb_indices_1  { enum { RED = 2, GREEN = 1, BLUE = 0 }; static ulong variant() { return 1; } };

template <class COMP, class IND> struct rgb_t
{
	typedef COMP component_type;
	typedef numeric_data::rgb_numeric_class_tag numeric_class;

	component_type components[3];
	
	static ulong variant() { return IND::variant(); }

	gtn_force_inline const COMP *get_components() const { return &components[0]; }
	gtn_force_inline       COMP *get_components()       { return &components[0]; }

	gtn_force_inline  const COMP &red() const   { return components[IND::RED];   }
	gtn_force_inline  const COMP &green() const { return components[IND::GREEN]; }
	gtn_force_inline  const COMP &blue() const  { return components[IND::BLUE];  }
	gtn_force_inline  const COMP &comp( ulong index ) const { return components[index]; }
	
	gtn_force_inline        COMP &red()         { return components[IND::RED];   }
	gtn_force_inline        COMP &green()       { return components[IND::GREEN]; }
	gtn_force_inline        COMP &blue()        { return components[IND::BLUE];  }
	gtn_force_inline        COMP &comp( ulong index )       { return components[index]; }
		  
	gtn_force_inline  rgb_t &red( COMP r )                { components[IND::RED]   = r; return *this; }
	gtn_force_inline  rgb_t &green( COMP g )              { components[IND::GREEN] = g; return *this; }
	gtn_force_inline  rgb_t &blue( COMP b )               { components[IND::BLUE]  = b; return *this; }
	gtn_force_inline  rgb_t &comp( ulong index, COMP c ) { components[index] = c; return *this; }
	
	static gtn_force_inline  ulong red_index()         { return IND::RED; }
	static gtn_force_inline  ulong green_index()       { return IND::GREEN; }
	static gtn_force_inline  ulong blue_index()        { return IND::BLUE; }
	static gtn_force_inline  ulong comp_index( ulong i_comp )
	{
		ulong act_index = 0;
		switch( i_comp )
		{
			case 0: act_index = IND::RED; break;
			case 1: act_index = IND::GREEN; break;
			case 2: act_index = IND::BLUE; break;
		}
		return act_index;
	}
	
	gtn_force_inline  bool eql( const rgb_t &c2 ) const { return ( red() == c2.red() ) && ( green() == c2.green() ) && ( blue() == c2.blue() ); }

	gtn_force_inline  void construct( COMP r, COMP g, COMP b ) { red() = r; green() = g; blue() = b; }
	gtn_force_inline void construct_all( component_type comp_val ) { construct( comp_val, comp_val, comp_val ); }

	static gtn_force_inline  COMP mul( COMP v, double s )   { return (COMP) ( v * s ); }
	static gtn_force_inline  COMP mul( COMP v, uint32 s )   { return (COMP) ( v * s ); }
	static gtn_force_inline  COMP div( COMP v, double s )   { return (COMP) ( ( v + s/2) / s ); }
	static gtn_force_inline  COMP div( COMP v, uint32 s )   { return (COMP) ( ( v + s/2) / s ); }

	gtn_force_inline  rgb_t &operator +=( const rgb_t &c2 ) { red() += c2.red(); green() += c2.green(); blue() += c2.blue(); return *this; }
	gtn_force_inline  rgb_t &operator -=( const rgb_t &c2 ) { red() -= c2.red(); green() -= c2.green(); blue() -= c2.blue(); return *this; }
	gtn_force_inline  rgb_t &operator *=( double s )        { red() = mul( red(), s ); blue() = mul( blue(), s ); green() = mul( green(), s ); return *this; }
	gtn_force_inline  rgb_t &operator *=( uint32 s )        { red() = mul( red(), s ); blue() = mul( blue(), s ); green() = mul( green(), s ); return *this; }
	gtn_force_inline  rgb_t &operator /=( double s )        { red() = div( red(), s ); blue() = div( blue(), s ); green() = div( green(), s ); return *this; }
	gtn_force_inline  rgb_t &operator /=( uint32 s )        { red() = div( red(), s ); blue() = div( blue(), s ); green() = div( green(), s ); return *this; }

	gtn_force_inline  bool operator ==(const rgb_t &c2) const { return  eql(c2); }
	gtn_force_inline  bool operator !=(const rgb_t &c2) const { return !eql(c2); }		// Use template definition in <utility>
};

template <class C,class I>
	gtn_force_inline  rgb_t<C,I> operator +( const rgb_t<C,I> &c1, const rgb_t<C,I> &c2 )    { rgb_t<C,I> ct(c1); ct += c2; return ct; }

template <class C,class I>
	gtn_force_inline  rgb_t<C,I> operator -( const rgb_t<C,I> &c1, const rgb_t<C,I> &c2 )    { rgb_t<C,I> ct(c1); ct -= c2; return ct; }

template <class C,class I>
	gtn_force_inline  rgb_t<C,I> operator *( const rgb_t<C,I> &c1, double s )                { rgb_t<C,I> ct(c1); ct *= s;  return ct; }

template <class C,class I>
	gtn_force_inline  rgb_t<C,I> operator *( const rgb_t<C,I> &c1, uint32 s )                { rgb_t<C,I> ct(c1); ct *= s;  return ct; }

template <class C,class I>
	gtn_force_inline  rgb_t<C,I> operator *( double s, const rgb_t<C,I> &c1 )                { rgb_t<C,I> ct(c1); ct *= s;  return ct; }

template <class C,class I>
	gtn_force_inline  rgb_t<C,I> operator *( uint32 s, const rgb_t<C,I> &c1 )                { rgb_t<C,I> ct(c1); ct *= s;  return ct; }

template <class C,class I>
	gtn_force_inline  rgb_t<C,I> operator /( const rgb_t<C,I> &c1, double s )                { rgb_t<C,I> ct(c1); ct /= s;  return ct; }

template <class C,class I>
	gtn_force_inline  rgb_t<C,I> operator /( const rgb_t<C,I> &c1, uint32 s )                { rgb_t<C,I> ct(c1); ct /= s;  return ct; }

template <class COMP, class RGB_B> struct rgb_c : public RGB_B			// Use 'RGB_B' instead of 'RGB' to avoir &^%*&^%*& VisualC++ macro 'RGB'
{
	gtn_force_inline  rgb_c() {}
	gtn_force_inline  rgb_c( const RGB_B &rgb ) : RGB_B( rgb ) {}
	gtn_force_inline  rgb_c( COMP r, COMP g, COMP b ) { construct( r, g, b ); }
};

typedef rgb_t<uint8  ,rgb_indices_0>  rgb_uint8_0_t;
typedef rgb_t<uint8  ,rgb_indices_1>  rgb_uint8_1_t;
typedef rgb_t<uint16 ,rgb_indices_0>  rgb_uint16_t;
typedef rgb_t<uint32 ,rgb_indices_0>  rgb_uint32_t;
typedef rgb_t<float32,rgb_indices_0>  rgb_float32_t;
typedef rgb_t<float64,rgb_indices_0>  rgb_float64_t;

typedef rgb_c<uint8   ,rgb_uint8_0_t> rgb_uint8_0;
typedef rgb_c<uint8   ,rgb_uint8_1_t> rgb_uint8_1;
typedef rgb_c<uint16  ,rgb_uint16_t>  rgb_uint16;
typedef rgb_c<uint32  ,rgb_uint32_t>  rgb_uint32;
typedef rgb_c<float32 ,rgb_float32_t> rgb_float32;
typedef rgb_c<float64 ,rgb_float64_t> rgb_float64;

template <class RGB1, class RGB2, class Conv> struct conv_rgb : public conv_base<RGB1,RGB2>
{
	gtn_force_inline  void operator()( const RGB1 &rgb1, RGB2 &rgb2 ) const { Conv conv; conv( rgb1.red(), rgb2.red() ); conv( rgb1.green(), rgb2.green() ); conv( rgb1.blue(), rgb2.blue() ); }
};


template <class RGB1, class RGB2> bool rgb_eql( const RGB1 &rgb1, const RGB2 &rgb2 )
{
	return ( ( rgb1.red() == rgb2.red() ) && ( rgb1.green() == rgb2.green() ) && ( rgb1.blue() == rgb2.blue() ) );
}

template <class From, class To> struct ScaleData;

template <> struct ScaleData<uint8,uint8>  { void operator()( const uint8 &f, uint8  &t ) { t = f; } };
template <> struct ScaleData<uint8,uint16> { void operator()( const uint8 &f, uint16 &t ) { t = (uint16) ( ( uint32(f) * 0xFFFFul + 0x80ul ) / 0xFFul ); } };
template <> struct ScaleData<uint8,uint32> { void operator()( const uint8 &f, uint32 &t ) { t = uint32(f) * ( 0xFFFFFFFFul / 0xFFul ) + ( ( uint32(f) * ( 0xFFFFFFFFul % 0xFFul ) + 0x80ul ) / 0xFFul ); } };

template <> struct ScaleData<uint16,uint8>  { void operator()( const uint16 &f, uint8  &t ) { t = (uint8) ( ( uint32(f) * 0xFFul + 0x8000ul ) / 0xFFFFul ); } };
template <> struct ScaleData<uint16,uint16> { void operator()( const uint16 &f, uint16 &t ) { t = f; } };
template <> struct ScaleData<uint16,uint32> { void operator()( const uint16 &f, uint32 &t ) { t = uint32(f) * ( 0xFFFFFFFFul / 0xFFFFul ) + ( ( uint32(f) * ( 0xFFFFFFFFul % 0xFFFFul ) + 0x8000ul ) / 0xFFFFul ); } };

template <> struct ScaleData<uint32,uint8>  { void operator()( const uint32 &f, uint8  &t ) { t = (uint8) ( double(f) * double(0xFFul) / double(0xFFFFFFFFul) + 0.5 ); } };
template <> struct ScaleData<uint32,uint16> { void operator()( const uint32 &f, uint16 &t ) { t = (uint16) ( double(f) * double(0xFFFFul) / double(0xFFFFFFFFul) + 0.5 ); } };
template <> struct ScaleData<uint32,uint32> { void operator()( const uint32 &f, uint32 &t ) { t = f; } };

template <> struct ScaleData<float64,float64> { void operator()( const float64 &f, float64 &t ) { t = f; } };
template <> struct ScaleData<float64,float32> { void operator()( const float64 &f, float32 &t ) { t = (float32) f; } };
template <> struct ScaleData<float32,float64> { void operator()( const float32 &f, float64 &t ) { t = (float64) f; } };

template <> struct ScaleData<uint8 ,float64>  { void operator()( const uint8  &f, float64 &t ) { t = ( (double) f / 255.0 ); } };
template <> struct ScaleData<uint16,float64>  { void operator()( const uint16 &f, float64 &t ) { t = ( (double) f / 65535.0 ); } };
template <> struct ScaleData<uint32,float64>  { void operator()( const uint32 &f, float64 &t ) { t = ( (double) f / double(0xFFFFFFFFul) ); } };

template <> struct ScaleData<float64,uint8 > { void operator()( const float64 &f, uint8  &t ) { t = (uint8)  ( ( 256.0 * ( 1.0 - std::numeric_limits<float64>::epsilon() ) ) * f );  } };
template <> struct ScaleData<float64,uint16> { void operator()( const float64 &f, uint16 &t ) { t = (uint16) ( ( 65536 * ( 1.0 - std::numeric_limits<float64>::epsilon() ) ) * f ); } };
template <> struct ScaleData<float64,uint32> { void operator()( const float64 &f, uint32 &t ) { t = (uint32) ( ( double(0xFFFFFFFFul) * ( 1.0 - std::numeric_limits<float64>::epsilon() ) ) * f ); } };

template <class RGB1, class RGB2> struct conv_rgb_scale : public conv_rgb<RGB1,RGB2,ScaleData<typename RGB1::component_type, typename RGB2::component_type> >{};


struct rgba_indices_0 { enum { RED = 0, GREEN = 1, BLUE = 2, ALPHA = 3 }; static ulong variant() { return 0; } };
struct rgba_indices_1 { enum { RED = 3, GREEN = 2, BLUE = 1, ALPHA = 0 }; static ulong variant() { return 1; } };
struct rgba_indices_2 { enum { RED = 1, GREEN = 2, BLUE = 3, ALPHA = 0 }; static ulong variant() { return 2; } };
struct rgba_indices_3 { enum { RED = 2, GREEN = 1, BLUE = 0, ALPHA = 3 }; static ulong variant() { return 3; } };

template <class COMP, class IND> struct rgba_t
{
	typedef COMP component_type;
	typedef numeric_data::rgba_numeric_class_tag numeric_class;

	component_type components[4];

	static ulong variant() { return IND::variant(); }

	gtn_force_inline const COMP *get_components() const { return &components[0]; }
	gtn_force_inline       COMP *get_components()       { return &components[0]; }

	gtn_force_inline  const COMP &red() const   { return components[IND::RED];   }
	gtn_force_inline  const COMP &green() const { return components[IND::GREEN]; }
	gtn_force_inline  const COMP &blue() const  { return components[IND::BLUE];  }
	gtn_force_inline  const COMP &alpha() const { return components[IND::ALPHA]; }
	gtn_force_inline  const COMP &comp( ulong index ) const { return components[index]; }
	
	gtn_force_inline        COMP &red()         { return components[IND::RED];   }
	gtn_force_inline        COMP &green()       { return components[IND::GREEN]; }
	gtn_force_inline        COMP &blue()        { return components[IND::BLUE];  }
	gtn_force_inline        COMP &alpha()       { return components[IND::ALPHA]; }
	gtn_force_inline        COMP &comp( ulong index )       { return components[index]; }
		  
	gtn_force_inline  rgba_t &red( COMP r )   { components[IND::RED]   = r; return *this; }
	gtn_force_inline  rgba_t &green( COMP g ) { components[IND::GREEN] = g; return *this; }
	gtn_force_inline  rgba_t &blue( COMP b )  { components[IND::BLUE]  = b; return *this; }
	gtn_force_inline  rgba_t &alpha( COMP a ) { components[IND::ALPHA] = a; return *this; }
	gtn_force_inline  rgba_t &comp( ulong index, COMP c ) { components[index] = c; return *this; }
	
	static gtn_force_inline  ulong red_index()         { return IND::RED; }
	static gtn_force_inline  ulong green_index()       { return IND::GREEN; }
	static gtn_force_inline  ulong blue_index()        { return IND::BLUE; }
	static gtn_force_inline  ulong alpha_index()       { return IND::ALPHA; }
	static gtn_force_inline  ulong comp_index( ulong i_comp )
	{
		ulong act_index = 0;
		switch( i_comp )
		{
			case 0: act_index = IND::RED; break;
			case 1: act_index = IND::GREEN; break;
			case 2: act_index = IND::BLUE; break;
			case 3: act_index = IND::ALPHA; break;
		}
		return act_index;
	}
	
	gtn_force_inline  bool eql( const rgba_t &c2 ) const { return ( red() == c2.red() ) && ( green() == c2.green() ) && ( blue() == c2.blue() ) && ( alpha() == c2.alpha() ); }

	gtn_force_inline  void construct( COMP r, COMP g, COMP b, COMP a ) { red() = r; green() = g; blue() = b; alpha() = a; }
	gtn_force_inline  void construct_all( component_type comp_val )    { construct( comp_val, comp_val, comp_val ); }

	static gtn_force_inline  COMP mul( COMP v, double s )     { return (COMP) ( v * s ); }
	static gtn_force_inline  COMP mul( COMP v, uint32 s )     { return (COMP) ( v * s ); }
	static gtn_force_inline  COMP div( COMP v, double s )     { return (COMP) ( ( v + s/2) / s ); }
	static gtn_force_inline  COMP div( COMP v, uint32 s )     { return (COMP) ( ( v + s/2) / s ); }

	gtn_force_inline  rgba_t &operator +=( const rgba_t &c2 ) { red() += c2.red(); green() += c2.green(); blue() += c2.blue(); alpha() += c2.alpha(); return *this; }
	gtn_force_inline  rgba_t &operator -=( const rgba_t &c2 ) { red() -= c2.red(); green() -= c2.green(); blue() -= c2.blue(); alpha() -= c2.alpha(); return *this; }
	gtn_force_inline  rgba_t &operator *=( double s )         { red() = mul( red(), s ); blue() = mul( blue(), s ); green() = mul( green(), s ); alpha() = mul( alpha(), s ); return *this; }
	gtn_force_inline  rgba_t &operator *=( uint32 s )         { red() = mul( red(), s ); blue() = mul( blue(), s ); green() = mul( green(), s ); alpha() = mul( alpha(), s ); return *this; }
	gtn_force_inline  rgba_t &operator /=( double s )         { red() = div( red(), s ); blue() = div( blue(), s ); green() = div( green(), s ); alpha() = div( alpha(), s ); return *this; }
	gtn_force_inline  rgba_t &operator /=( uint32 s )         { red() = div( red(), s ); blue() = div( blue(), s ); green() = div( green(), s ); alpha() = div( alpha(), s ); return *this; }

	gtn_force_inline  bool operator ==(const rgba_t &c2) const { return  eql(c2); }
	gtn_force_inline  bool operator !=(const rgba_t &c2) const { return !eql(c2); }		// Use template definition in <utility>
};

template <class C,class I>
	gtn_force_inline  rgba_t<C,I> operator +( const rgba_t<C,I> &c1, const rgba_t<C,I> &c2 )   { rgba_t<C,I> ct(c1); ct += c2; return ct; }

template <class C,class I>
	gtn_force_inline  rgba_t<C,I> operator -( const rgba_t<C,I> &c1, const rgba_t<C,I> &c2 )   { rgba_t<C,I> ct(c1); ct -= c2; return ct; }

template <class C,class I>
	gtn_force_inline  rgba_t<C,I> operator *( const rgba_t<C,I> &c1, double s )                { rgba_t<C,I> ct(c1); ct *= s;  return ct; }

template <class C,class I>
	gtn_force_inline  rgba_t<C,I> operator *( const rgba_t<C,I> &c1, uint32 s )                { rgba_t<C,I> ct(c1); ct *= s;  return ct; }

template <class C,class I>
	gtn_force_inline  rgba_t<C,I> operator *( double s, const rgba_t<C,I> &c1 )                { rgba_t<C,I> ct(c1); ct *= s;  return ct; }

template <class C,class I>
	gtn_force_inline  rgba_t<C,I> operator *( uint32 s, const rgba_t<C,I> &c1 )                { rgba_t<C,I> ct(c1); ct *= s;  return ct; }

template <class C,class I>
	gtn_force_inline  rgba_t<C,I> operator /( const rgba_t<C,I> &c1, double s )                { rgba_t<C,I> ct(c1); ct /= s;  return ct; }

template <class C,class I>
	gtn_force_inline  rgba_t<C,I> operator /( const rgba_t<C,I> &c1, uint32 s )                { rgba_t<C,I> ct(c1); ct /= s;  return ct; }

template <class COMP, class RGBA> struct rgba_c : public RGBA
{
	gtn_force_inline  rgba_c() {}
	gtn_force_inline  rgba_c( const RGBA &rgb ) : RGBA( rgb ) {}
	gtn_force_inline  rgba_c( COMP r, COMP g, COMP b, COMP a = 0 ) { construct( r, g, b, a ); }
};

typedef rgba_t<uint8 ,rgba_indices_0>  rgba_uint8_0_t;
typedef rgba_t<uint8 ,rgba_indices_1>  rgba_uint8_1_t;
typedef rgba_t<uint8 ,rgba_indices_2>  rgba_uint8_2_t;
typedef rgba_t<uint8 ,rgba_indices_3>  rgba_uint8_3_t;
typedef rgba_t<uint16,rgba_indices_0>  rgba_uint16_t;
typedef rgba_t<uint32,rgba_indices_0>  rgba_uint32_t;
typedef rgba_t<float64,rgba_indices_0> rgba_float64_t;
typedef rgba_t<float32,rgba_indices_0> rgba_float32_t;

typedef rgba_c<uint8 ,rgba_uint8_0_t  > rgba_uint8_0;
typedef rgba_c<uint8 ,rgba_uint8_1_t  > rgba_uint8_1;
typedef rgba_c<uint8 ,rgba_uint8_2_t  > rgba_uint8_2;
typedef rgba_c<uint8 ,rgba_uint8_3_t  > rgba_uint8_3;
typedef rgba_c<uint16,rgba_uint16_t   > rgba_uint16;
typedef rgba_c<uint32,rgba_uint32_t   > rgba_uint32;
typedef rgba_c<float32,rgba_float32_t > rgba_float32;
typedef rgba_c<float64,rgba_float64_t > rgba_float64;

template <class RGBA1, class RGBA2, class Conv> struct conv_rgba : public conv_base<RGBA1,RGBA2>
{
	gtn_force_inline  void operator()( const RGBA1 &rgba1, RGBA2 &rgba2 ) const { Conv conv; conv( rgba1.red(), rgba2.red() ); conv( rgba1.green(), rgba2.green() ); conv( rgba1.blue(), rgba2.blue() ); conv( rgba1.alpha(), rgba2.alpha() ); }
};


template <class RGBA1, class RGBA2> bool rgba_eql( const RGBA1 &rgba1, const RGBA2 &rgba2 )
{
	return ( ( rgba1.red() == rgba2.red() ) && ( rgba1.green() == rgba2.green() ) && ( rgba1.blue() == rgba2.blue() ) && ( rgba1.alpha() == rgba2.alpha() ) );
}

template <class RGBA1, class RGBA2> struct conv_rgba_scale : public conv_rgba<RGBA1,RGBA2,ScaleData<typename RGBA1::component_type, typename RGBA2::component_type> > {};


// Point support
struct point2_indices_0 { enum { X = 0, Y = 1 }; static ulong variant() { return 0; } };
struct point2_indices_1 { enum { X = 1, Y = 0 }; static ulong variant() { return 1; } };

template <class COMP, class IND> struct point2_t
{
	typedef COMP component_type;
	typedef numeric_data::point2_numeric_class_tag numeric_class;

	component_type components[2];

	gtn_force_inline static ulong variant() { return IND::variant(); }

	gtn_force_inline const COMP *get_components() const { return &components[0]; }
	gtn_force_inline       COMP *get_components()       { return &components[0]; }

	gtn_force_inline  const COMP &x() const { return components[IND::X]; }
	gtn_force_inline  const COMP &y() const { return components[IND::Y]; }
	gtn_force_inline  const COMP &comp( ulong index ) const { return components[index]; }

	gtn_force_inline        COMP &x()       { return components[IND::X]; }
	gtn_force_inline        COMP &y()       { return components[IND::Y]; }
	gtn_force_inline        COMP &comp( ulong index )       { return components[index]; }

	gtn_force_inline  point2_t &x( COMP x_ ) { components[IND::X] = x_; return *this; }
	gtn_force_inline  point2_t &y( COMP y_ ) { components[IND::Y] = y_; return *this; }
	gtn_force_inline  point2_t &comp( ulong index, COMP c ) { components[index] = c; return *this; }

	static gtn_force_inline  ulong x_index()     { return IND::X; }
	static gtn_force_inline  ulong y_index()     { return IND::Y; }
	static gtn_force_inline  ulong comp_index( ulong i_comp )
	{
		ulong act_index = 0;
		switch( i_comp )
		{
			case 0: act_index = IND::X; break;
			case 1: act_index = IND::Y; break;
		}
		return act_index;
	}

	gtn_force_inline  bool eql( const point2_t &p2 ) const { return ( x() == p2.x() ) && ( y() == p2.y() ); }

	gtn_force_inline  void construct( COMP x_, COMP y_ ) { x() = x_; y() = y_; }
	gtn_force_inline  void construct_all( component_type comp_val ) { construct( comp_val, comp_val ); }

	gtn_force_inline  bool operator ==(const point2_t &p2) const { return  eql(p2); }
	gtn_force_inline  bool operator !=(const point2_t &p2) const { return !eql(p2); }
};

template <class COMP, class POINT_T> struct point2_c : public POINT_T
{
	gtn_force_inline  point2_c() {}
	gtn_force_inline  point2_c( const POINT_T &p ) : POINT_T(p) {}
	gtn_force_inline  point2_c( COMP x_, COMP y_ ) { construct( x_, y_ ); }
};

typedef point2_t<sint16,point2_indices_0>   point2_sint16_0_t;
typedef point2_t<sint16,point2_indices_1>   point2_sint16_1_t;
typedef point2_t<sint32,point2_indices_0>   point2_sint32_0_t;
typedef point2_t<float32,point2_indices_0>  point2_float32_0_t;
typedef point2_t<float64,point2_indices_0>  point2_float64_0_t;

template <class P1, class P2, class Conv> struct conv_point2 : public conv_base<P1,P2>
{
	gtn_force_inline  void operator()( const P1 &a1, P2 &a2 ) const { Conv conv; conv( a1.x(), a2.x() ); conv( a1.y(), a2.y() ); }
};

// Rect support
struct rect_indices_0 { enum { LEFT = 0, TOP = 1, RIGHT = 2, BOTTOM = 3 }; static ulong variant() { return 0; }  };
struct rect_indices_1 { enum { LEFT = 1, TOP = 0, RIGHT = 3, BOTTOM = 2 }; static ulong variant() { return 1; }  };

template <class COMP, class IND> struct rect_t
{
	typedef COMP component_type;
	typedef numeric_data::rect_numeric_class_tag numeric_class;

	component_type components[4];

	gtn_force_inline static ulong variant() { return IND::variant(); }

	gtn_force_inline const COMP *get_components() const { return &components[0]; }
	gtn_force_inline       COMP *get_components()       { return &components[0]; }

	gtn_force_inline  const COMP &left()   const { return components[IND::LEFT]; }
	gtn_force_inline  const COMP &top()    const { return components[IND::TOP]; }
	gtn_force_inline  const COMP &right()  const { return components[IND::RIGHT]; }
	gtn_force_inline  const COMP &bottom() const { return components[IND::BOTTOM]; }
	gtn_force_inline  const COMP &comp( ulong index ) const { return components[index]; }

	gtn_force_inline        COMP &left()           { return components[IND::LEFT]; }
	gtn_force_inline        COMP &top()            { return components[IND::TOP]; }
	gtn_force_inline        COMP &right()          { return components[IND::RIGHT]; }
	gtn_force_inline        COMP &bottom()         { return components[IND::BOTTOM]; }
	gtn_force_inline        COMP &comp( ulong index ) { return comonents[index]; }

	gtn_force_inline  rect_t &left( COMP l_ )      { components[IND::LEFT] = l_; return *this; }
	gtn_force_inline  rect_t &top( COMP t_ )       { components[IND::TOP] = t_; return *this; }
	gtn_force_inline  rect_t &right( COMP r_ )     { components[IND::RIGHT] = r_; return *this; }
	gtn_force_inline  rect_t &bottom( COMP b_ )    { components[IND::BOTTOM] = b_; return *this; }
	gtn_force_inline  rect_t &comp( ulong index, COMP c ) { components[index] = c; return *this; }

	static gtn_force_inline  ulong left_index()    { return IND::LEFT; }
	static gtn_force_inline  ulong top_index()     { return IND::TOP; }
	static gtn_force_inline  ulong right_index()   { return IND::RIGHT; }
	static gtn_force_inline  ulong bottom_index()  { return IND::BOTTOM; }
	static gtn_force_inline  ulong comp_index( ulong i_comp )
	{
		ulong act_index = 0;
		switch( i_comp )
		{
			case 0: act_index = IND::LEFT; break;
			case 1: act_index = IND::TOP; break;
			case 2: act_index = IND::RIGHT; break;
			case 3: act_index = IND::BOTTOM; break;
		}
		return act_index;
	}

	gtn_force_inline  bool eql( const rect_t &r ) const { return    ( left() == r.left() )   && ( top() == r.top() )
	                                                  && ( right() == r.right() ) && ( bottom() == r.bottom() ); }

	gtn_force_inline  void construct( COMP l_, COMP t_, COMP r_, COMP b_ ) { left() = l_; top() = t_; right() = r_; bottom() = b_; }
	gtn_force_inline  void construct_all( component_type comp_val )        { construct( comp_val, comp_val, comp_val, comp_val ); }

	gtn_force_inline  bool operator ==(const rect_t &r2) const { return  eql(r2); }
	gtn_force_inline  bool operator !=(const rect_t &r2) const { return !eql(r2); }
};

template <class COMP, class RECT_T> struct rect_c : public RECT_T
{
	gtn_force_inline  rect_c() {}
	gtn_force_inline  rect_c( const RECT_T &r ) : RECT_T( r ) {}
	gtn_force_inline  rect_c( COMP l_, COMP t_, COMP r_, COMP b_ ) { construct( l_, t_, r_, b_ ); }
};

typedef rect_t<sint16,rect_indices_1>     rect_sint16_1_t;
typedef rect_t<sint32,rect_indices_1>     rect_sint32_1_t;
typedef rect_t<float32,rect_indices_1>    rect_float32_1_t;
typedef rect_t<float32,rect_indices_0>    rect_float32_0_t;
typedef rect_t<float64,rect_indices_0>    rect_float64_0_t;

typedef rect_c<sint16,rect_sint16_1_t>    rect_sint16_1;
typedef rect_c<sint32,rect_sint32_1_t>    rect_sint32_1;
typedef rect_c<float32,rect_float32_1_t>  rect_float32_1;
typedef rect_c<float32,rect_float32_0_t>  rect_float32_0;

template <class R1, class R2, class Conv> struct conv_rect : public conv_base<R1,R2>
{
	gtn_force_inline  void operator()( const R1 &r1, R2 &r2 ) const
	{
		Conv conv;
		conv( r1.top(), r2.top() );
		conv( r1.left(), r2.left() );
		conv( r1.bottom(), r2.bottom() );
		conv( r1.right(), r2.right() );
	}
};

} // namespace Gatan


/*
**	 The following '_os' types specify the default way of laying out 'rgb' and 'rgba'
** in bitmaps for the specified operating system.  It is really only still here for
** backwards compatibility to specify the data stored for 'RGB_DATA', which has a different
** ordering on Mac and Win32 versions of DM.
*/

#ifdef _GATAN_OS_MACOS
namespace Gatan
{
// Mac 32-bit color format: rgba_indices_2

	typedef rgb_uint8_0_t  rgb_uint8_os_t;
	typedef rgb_uint8_0    rgb_uint8_os;
	
	typedef rgba_indices_2 rgba_indices_os;
	typedef rgba_uint8_2_t rgba_uint8_os_t;
	typedef rgba_uint8_2   rgba_uint8_os;
} // namespace Gatan
#endif	// _GATAN_OS_MACOS
#ifdef _GATAN_OS_WIN32
namespace Gatan
{
// Win32 32-bit color format : rgba_indices_3
	typedef rgb_uint8_1_t  rgb_uint8_os_t;
	typedef rgb_uint8_1    rgb_uint8_os;
	
	typedef rgba_indices_3 rgba_indices_os;
	typedef rgba_uint8_3_t rgba_uint8_os_t;
	typedef rgba_uint8_3   rgba_uint8_os;
} // namespace Gatan
#endif	// _GATAN_OS_WIN32

namespace Gatan
{

namespace numeric_data
{
	enum NumericDataClass
	{
		  number_class_NONE     = 0
		, number_class_SCALAR   = 1
		, number_class_COMPLEX  = 2
		, number_class_RGB      = 3
		, number_class_RGBA     = 4
		, number_class_POINT2   = 5
		, number_class_RECT     = 6
	};

	enum NumericScalarClass
	{
		  scalar_class_NONE               = 0
		, scalar_class_SIGNED_INTEGER     = 1
		, scalar_class_UNSIGNED_INTEGER   = 2
		, scalar_class_FLOAT              = 3
		, scalar_class_BINARY             = 4
	};

	struct signed_integer_scalar_class_tag;
	struct unsigned_integer_scalar_class_tag;
	struct float_scalar_class_tag;
	struct binary_scalar_class_tag;

	template <typename NumericClass> struct number_class_traits;

	template <> 
	struct number_class_traits<scalar_numeric_class_tag>
	{
		BOOST_STATIC_CONSTANT( ulong,     enum_val =             numeric_data::number_class_SCALAR );
		BOOST_STATIC_CONSTANT( ulong,     num_components       = 1ul );
		static const char      *name()                 { return "scalar"; }
		static const char      *component_name( uint i_comp, uint name_format );
	};

	template <> 
	struct number_class_traits<complex_numeric_class_tag>
	{
		BOOST_STATIC_CONSTANT( ulong,     enum_val =             numeric_data::number_class_COMPLEX );
		BOOST_STATIC_CONSTANT( ulong,     num_components       = 2ul );
		static const char      *name()                 { return "complex"; }
		static const char      *component_name( uint i_comp, uint name_format );
	};

	template <> 
	struct number_class_traits<rgb_numeric_class_tag>
	{
		BOOST_STATIC_CONSTANT( ulong,     enum_val =             numeric_data::number_class_RGB );
		BOOST_STATIC_CONSTANT( ulong,     num_components       = 3ul );
		static const char      *name()                 { return "rgb"; }
		static const char      *component_name( uint i_comp, uint name_format );
	};

	template <> 
	struct number_class_traits<rgba_numeric_class_tag>
	{
		BOOST_STATIC_CONSTANT( ulong,     enum_val =             numeric_data::number_class_RGBA );
		BOOST_STATIC_CONSTANT( ulong,     num_components       = 4ul );
		static const char      *name()                 { return "rgba"; }
		static const char      *component_name( uint i_comp, uint name_format );
	};

	template <> 
	struct number_class_traits<point2_numeric_class_tag>
	{
		BOOST_STATIC_CONSTANT( ulong,     enum_val =             numeric_data::number_class_POINT2 );
		BOOST_STATIC_CONSTANT( ulong,     num_components       = 2ul );
		static const char      *name()                 { return "point2"; }
		static const char      *component_name( uint i_comp, uint name_format );
	};

	template <> 
	struct number_class_traits<rect_numeric_class_tag>
	{
		BOOST_STATIC_CONSTANT( ulong,     enum_val =             numeric_data::number_class_RECT );
		BOOST_STATIC_CONSTANT( ulong,     num_components       = 4ul );
		static const char      *name()                 { return "rect"; }
		static const char      *component_name( uint i_comp, uint name_format );
	};
	
	typedef number_class_traits<scalar_numeric_class_tag>   scalar_number_class_traits;
	typedef number_class_traits<complex_numeric_class_tag>  complex_number_class_traits;
	typedef number_class_traits<rgb_numeric_class_tag>      rgb_number_class_traits;
	typedef number_class_traits<rgba_numeric_class_tag>     rgba_number_class_traits;
	typedef number_class_traits<point2_numeric_class_tag>   point2_number_class_traits;
	typedef number_class_traits<rect_numeric_class_tag>     rect_number_class_traits;

	template <typename ScalarClass> struct scalar_class_traits;

	template <> 
	struct scalar_class_traits<signed_integer_scalar_class_tag>
	{
		BOOST_STATIC_CONSTANT( ulong,     enum_val =           numeric_data::scalar_class_SIGNED_INTEGER );
		static const char      *name()               { return "sint"; }
	};
	template <> 
	struct scalar_class_traits<unsigned_integer_scalar_class_tag>
	{
		BOOST_STATIC_CONSTANT( ulong,     enum_val =           numeric_data::scalar_class_UNSIGNED_INTEGER );
		static const char      *name()               { return "uint"; }
	};
	template <> 
	struct scalar_class_traits<float_scalar_class_tag>
	{
		BOOST_STATIC_CONSTANT( ulong,     enum_val =           numeric_data::scalar_class_FLOAT );
		static const char      *name()               { return "float"; }
	};
	template <> 
	struct scalar_class_traits<binary_scalar_class_tag>
	{
		BOOST_STATIC_CONSTANT( ulong,     enum_val =           numeric_data::scalar_class_BINARY );
		static const char      *name()               { return "binary"; }
	};

	template <typename Number> struct numeric_data_traits
	{
		typedef ulong                                size_type;
		typedef Number                               value_type;
		typedef typename value_type::component_type  component_type;
		typedef typename numeric_data_traits<component_type>::scalar_component_type scalar_component_type;
		typedef typename value_type::numeric_class   numeric_class;
		typedef typename numeric_data_traits<component_type>::scalar_class scalar_class;
		typedef number_class_traits<numeric_class>   class_traits;
		typedef scalar_class_traits<scalar_class>    scalar_traits;
		typedef numeric_data_traits<component_type>  component_numeric_traits;

		BOOST_STATIC_CONSTANT( ulong,      numeric_class_enum_val =  class_traits::enum_val );
		BOOST_STATIC_CONSTANT( ulong,     scalar_class_enum_val  =  scalar_traits::enum_val );

		BOOST_STATIC_CONSTANT( ulong,     size_bytes             = (class_traits::num_components * component_numeric_traits::size_bytes) );
		BOOST_STATIC_CONSTANT( ulong,     size_bits              = (class_traits::num_components * component_numeric_traits::size_bits) );
		BOOST_STATIC_CONSTANT( ulong,     num_components         = class_traits::num_components );

		static inline ulong      variant()
		{
			return value_type::variant();
		}

		static inline size_type  get_component_offset( ulong i )
		{
			return value_type::comp_index(i) * component_numeric_traits::size_bytes;
		}
		static inline value_type zero()
		{
			value_type val;
			val.construct_all( component_numeric_traits::zero() );
			return val;
		}
	};

	template <typename Number, typename NumericClass, typename ScalarClass> struct numeric_data_traits_scalar
	{
		typedef ulong                                size_type;
		typedef Number                               value_type;
		typedef value_type                           component_type;
		typedef value_type                           scalar_component_type;
		typedef NumericClass                         numeric_class;
		typedef ScalarClass                          scalar_class;
		typedef number_class_traits<numeric_class>   class_traits;
		typedef scalar_class_traits<scalar_class>    scalar_traits;
		typedef numeric_data_traits<component_type>  component_numeric_traits;

		BOOST_STATIC_CONSTANT( ulong,     numeric_class_enum_val =  class_traits::enum_val );
		BOOST_STATIC_CONSTANT( ulong,     scalar_class_enum_val  =  scalar_traits::enum_val );

		BOOST_STATIC_CONSTANT( ulong,     size_bytes             = sizeof(value_type) );
		BOOST_STATIC_CONSTANT( ulong,     size_bits              = (8 * size_bytes) );
		BOOST_STATIC_CONSTANT( ulong,     num_components         = class_traits::num_components );

		static inline ulong      variant()          { return 0; }
		static inline size_type  get_component_offset( ulong ) { return 0; }
		static inline value_type zero()             { return (value_type) 0; }
	};

	template <> struct numeric_data_traits<binary8>       : public numeric_data_traits_scalar<binary8,scalar_numeric_class_tag,binary_scalar_class_tag> {};
	template <> struct numeric_data_traits<uint8>         : public numeric_data_traits_scalar<uint8,scalar_numeric_class_tag,unsigned_integer_scalar_class_tag> {};
	template <> struct numeric_data_traits<sint8>         : public numeric_data_traits_scalar<sint8,scalar_numeric_class_tag,signed_integer_scalar_class_tag> {};
	template <> struct numeric_data_traits<uint16>        : public numeric_data_traits_scalar<uint16,scalar_numeric_class_tag,unsigned_integer_scalar_class_tag> {};
	template <> struct numeric_data_traits<sint16>        : public numeric_data_traits_scalar<sint16,scalar_numeric_class_tag,signed_integer_scalar_class_tag> {};
	template <> struct numeric_data_traits<uint32>        : public numeric_data_traits_scalar<uint32,scalar_numeric_class_tag,unsigned_integer_scalar_class_tag> {};
	template <> struct numeric_data_traits<sint32>        : public numeric_data_traits_scalar<sint32,scalar_numeric_class_tag,signed_integer_scalar_class_tag> {};
	template <> struct numeric_data_traits<uint64>        : public numeric_data_traits_scalar<uint64,scalar_numeric_class_tag,unsigned_integer_scalar_class_tag> {};
	template <> struct numeric_data_traits<sint64>        : public numeric_data_traits_scalar<sint64,scalar_numeric_class_tag,signed_integer_scalar_class_tag> {};

	template <> struct numeric_data_traits<float32>       : public numeric_data_traits_scalar<float32,scalar_numeric_class_tag,float_scalar_class_tag> {};
	template <> struct numeric_data_traits<float64>       : public numeric_data_traits_scalar<float64,scalar_numeric_class_tag,float_scalar_class_tag> {};
} // namespace numeric_data

} // namespace Gatan

namespace Gatan
{
	template <typename Arg1, typename Arg2> struct Convert;
} // namespace Gatan

#if defined( _GATAN_OS_WIN32 )

/*
**  The 'numeric_limits' templates were copied from the VisualC++ STL header
** <limits>, with the '_CRTIMP' qualifier removed so it won't look for implementations
** in the microsoft C++ libraries when compiled for dynamic linkage to those libraries.
**
*/

#if ( defined( _GATAN_STL_VISUAL_CPP ) && ( _GATAN_STL_VERSION < 1300 ) )

_STD_BEGIN

// CLASS numeric_limits<signed __int64>
class numeric_limits<signed __int64> : public _Num_int_base
{
public:
	typedef signed __int64 _Ty;
	static _Ty (__cdecl min)() _THROW0()
		{return (_I64_MIN); }
	static _Ty (__cdecl max)() _THROW0()
		{return (_I64_MAX); }
	static _Ty __cdecl epsilon() _THROW0()
		{return (0); }
	static _Ty __cdecl round_error() _THROW0()
		{return (0); }
	static _Ty __cdecl denorm_min() _THROW0()
		{return (0); }
	static _Ty __cdecl infinity() _THROW0()
		{return (0); }
	static _Ty __cdecl quiet_NaN() _THROW0()
		{return (0); }
	static _Ty __cdecl signaling_NaN() _THROW0()
		{return (0); }
	_STCONS(bool, is_signed, true);
	_STCONS(int, digits, CHAR_BIT * sizeof (signed __int64) - 1);
	_STCONS(int, digits10, (CHAR_BIT * sizeof (signed __int64) - 1)
		* 301L / 1000);
	};

		// CLASS numeric_limits<unsigned __int64>
class numeric_limits<unsigned __int64> : public _Num_int_base
{
public:
	typedef unsigned __int64 _Ty;
	static _Ty (__cdecl min)() _THROW0()
		{return (0); }
	static _Ty (__cdecl max)() _THROW0()
		{return (_UI64_MAX); }
	static _Ty __cdecl epsilon() _THROW0()
		{return (0); }
	static _Ty __cdecl round_error() _THROW0()
		{return (0); }
	static _Ty __cdecl denorm_min() _THROW0()
		{return (0); }
	static _Ty __cdecl infinity() _THROW0()
		{return (0); }
	static _Ty __cdecl quiet_NaN() _THROW0()
		{return (0); }
	static _Ty __cdecl signaling_NaN() _THROW0()
		{return (0); }
	_STCONS(bool, is_signed, false);
	_STCONS(int, digits, CHAR_BIT * sizeof (unsigned __int64));
	_STCONS(int, digits10, (CHAR_BIT * sizeof (unsigned __int64))
		* 301L / 1000);
	};

_STD_END
#endif // _GATAN_STL_*
#endif // _GATAN_OS_WIN32

#define POW_2_32_DBL ((double) 65536)*((double) 65536)
#define POW_2_64_DBL POW_2_32_DBL*POW_2_32_DBL
#define POW_2_63_DBL POW_2_32_DBL*(((double) 65536)*((double) 32768));
#define MAX_UINT64_DBL (POW_2_64_DBL - 1.0)

namespace Gatan
{

template <typename N> class numeric_bounds
{
public:
	static N low()  { return std::numeric_limits<N>::min(); }
	static N high() { return std::numeric_limits<N>::max(); }

	static float64 low_float()  { return (float64) std::numeric_limits<N>::min(); }
	static float64 high_float() { return (float64) std::numeric_limits<N>::max(); }
};

template <> class numeric_bounds<binary8>
{
public:
	static binary8 low()  { return 0; }
	static binary8 high() { return 1; }

	static float64 low_float()  { return 0.0; }
	static float64 high_float() { return 1.0; }
};
template <> class numeric_bounds<float32>
{
public:
	static float32 low()  { return -std::numeric_limits<float32>::infinity(); }
	static float32 high() { return std::numeric_limits<float32>::infinity(); }

	static float64 low_float()  { return (float64) std::numeric_limits<float32>::min(); }
	static float64 high_float() { return (float64) std::numeric_limits<float32>::max(); }
};

template <> class numeric_bounds<float64>
{
public:
	static float64 low()  { return -std::numeric_limits<float64>::infinity(); }
	static float64 high() { return std::numeric_limits<float64>::infinity(); }

	static float64 low_float()  { return (float64) std::numeric_limits<float64>::min(); }
	static float64 high_float() { return (float64) std::numeric_limits<float64>::max(); }
};

// Metrowerks 4 compiler has bug when converting 'std::numeric_limits<uint64>' to 'float64' during compilation ( converts it to -1.0 )
// For now, work around by setting implementing 'numeric_bounds<uint64>' explicitly
// VisualC++ 6.0 has a bug when converting 'std::numeric_limits<sint64>' to 'float64', so we explicitly instantiate here.

template <> class numeric_bounds<sint64>
{
public:
	static sint64 low()  { return std::numeric_limits<sint64>::min(); }
	static sint64 high() { return std::numeric_limits<sint64>::max(); }

	static float64 low_float()  { return -POW_2_63_DBL; }
	static float64 high_float() { return POW_2_63_DBL-1; }
};

template <> class numeric_bounds<uint64>
{
public:
	static uint64 low()  { return std::numeric_limits<uint64>::min(); }
	static uint64 high() { return std::numeric_limits<uint64>::max(); }

	static float64 low_float()  { return 0.0; }
	static float64 high_float() { return (POW_2_64_DBL - 1.0); }
};

} // namespace Gatan

namespace Gatan
{

#ifndef _GATAN_CLIP_TEMPLATE
#define _GATAN_CLIP_TEMPLATE

template <class T> inline const T &clip( const T &v, const T &min_, const T &max_ )
	{ return ( v < min_ ) ? min_ : ( ( max_ < v ) ? max_ : v ); }

template <class T, class Compare> inline const T &clip( const T &v, const T &min_, const T &max_, Compare comp )
	{ return comp( v, min_ ) ? min_ : ( comp( max_, v ) ? max_ : v ); }

/*
** Define this to avoid seeming optimization problem on Intel compiler w.r.t references
*/
template <class T> gtn_force_inline const T clip_val( const T v, const T min_, const T max_ )
	{ return ( v < min_ ) ? min_ : ( ( max_ < v ) ? max_ : v ); }

} // namespace Gatan

#endif // _GATAN_CLIP_TEMPLATE

#endif // __GATAN_IMAGETYPES__
