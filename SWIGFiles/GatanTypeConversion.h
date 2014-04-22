
#ifndef __GATANTYPECONVERSION__
#define __GATANTYPECONVERSION__

#include <algorithm>

#include "GatanTypes.h"

namespace Gatan
{

#if defined( _GATAN_COMPILER_GCC )

	#if defined(_GATAN_ARCHITECTURE_X86)

		gtn_force_inline float64 gtn_rint( float64 x )
		{
			double retval;
			__asm__ ("frndint;": "=t" (retval) : "0" (x));
			return retval;
		}
		

		gtn_force_inline void gtn_convert_float_to_int( float32 f_val, sint32 &i_val )
		{
			sint32 i_val_tmp;
			//{ __asm fld f_val __asm fistp i_val_tmp }
	
			// Goddamn X86 floating point conversion to int returns the most negative number if the floating point
			// number is too small to large.  If too small this is ok, but we need to check if too large.
			if ( i_val_tmp == std::numeric_limits<sint32>::min() )
			{
				if ( ((sint32*)&f_val)[0] > 0 ) { i_val_tmp -= 1; }
			}
			i_val = i_val_tmp;
		}

		gtn_force_inline void gtn_convert_float_to_int( float64 f_val, sint32 &i_val )
		{
			sint32 i_val_tmp;
			//{ __asm fld f_val __asm fistp i_val_tmp }

			// Goddamn X86 floating point conversion to int returns the most negative number if the floating point
			// number is too small to large.  If too small this is ok, but we need to check if too large.
			if ( i_val_tmp == std::numeric_limits<sint32>::min() )
			{
				if ( ((sint32*)&f_val)[1] > 0 ) { i_val_tmp -= 1; }
			}
			i_val = i_val_tmp;
		}

		gtn_force_inline void gtn_convert_float_to_int( float32 f_val, uint32 &ui_val )
		{
			if ( ((sint32*)&f_val)[0] < 0 )						// Check if negative
			{
				ui_val = 0;
			}
			else
			{
		//		{ uint32 ui_val_tmp; { __asm fld f_val __asm fist ui_val_tmp } ui_val = ui_val_tmp; }			// inline assembler can't deal with references( or pointers for that matter )
		
				if ( *((sint32 *)&ui_val) < 0 )								// We check for positive above, so if this is negative, must be overflow
				{
					float64 f_sint32_min = (float64) std::numeric_limits<sint32>::min();
		//			{ uint32 ui_val_tmp; { __asm fld f_sint32_min __asm faddp st(1), st __asm fistp ui_val_tmp } ui_val = ui_val_tmp; }
					ui_val ^= 0x80000000ul;		// Effectively adds '-numeric_limits<sint32>::min()'
					if ( ui_val == 0 )			// number too large ==> '(old ui_val) + 0x8000000 == 0'
					{
						ui_val -= 1;
					}
				}
				else
				{
		//			__asm fstp st
				}
			}
		}

		gtn_force_inline void gtn_convert_float_to_int(const float64 f_val, uint32 &ui_val )
		{
			if ( ((sint32*)&f_val)[1] < 0 )						// Check if negative
			{
				ui_val = 0;
			}
			else
			{
		//		{ uint32 ui_val_tmp; { __asm fld f_val __asm fist ui_val_tmp } ui_val = ui_val_tmp; }			// inline assembler can't deal with references( or pointers for that matter )
		
				if ( *((sint32 *)&ui_val) < 0 )								// We check for positive above, so if this is negative, must be overflow
				{
					float64 f_sint32_min = (float64) std::numeric_limits<sint32>::min();
		//			{ uint32 ui_val_tmp; { __asm fld f_sint32_min __asm faddp st(1), st __asm fistp ui_val_tmp } ui_val = ui_val_tmp; }
					ui_val ^= 0x80000000ul;		// Effectively adds '-numeric_limits<sint32>::min()'
					if ( ui_val == 0 )			// number too large ==> '(old ui_val) + 0x8000000 == 0'
					{
						ui_val -= 1;
					}
				}
				else
				{
		//			__asm fstp st
				}
			}
		}

		gtn_force_inline void gtn_convert_float_to_int_noclip( const float64 f_val, sint32 &i_val )
		{
			sint32 i_val_tmp;
		//	{ __asm fld f_val __asm fistp i_val_tmp }
			i_val = i_val_tmp;		
		}
        
        #define _GATAN_CONVERT_FLOAT_INT
    
	#endif // _GATAN_ARCHITECTURE

#endif // _GATAN_COMPILER_GCC
	
#if !defined( _GATAN_CONVERT_FLOAT_INT ) && defined( _GATAN_OS_MACOS )

    #if defined( _GATAN_COMPILER_GCC ) && defined(_GATAN_ARCHITECTURE_POWERPC)
		gtn_force_inline void gtn_rinttol( float64 f_val_in, sint32 *i_val )
		{
            union { float64 f_val; sint32 i_v[2]; } u;
            __asm__ ("fctiw %0,%1" : "=f"(u.f_val) : "f"(f_val_in));
            *i_val = u.i_v[1];
		}
    #else
        extern "C"
        {
            void gtn_rinttol( float64 f_val, sint32 *i_val );
        }
    #endif

	gtn_force_inline float64 gtn_rint( float64 v )
	{
		double v_out = gtn_floor(v);
		double v_diff  = ( v - v_out );
		if ( v_diff != 0.0 )
		{
			if ( v < 0.0 )
			{
				v_diff -= 1.0;
				v_out += 1.0;
			}
			sint32 v_i;
			gtn_rinttol( v_diff, &v_i );
			v_out += v_i;
		}
		return v_out;
	}
	
	gtn_force_inline void gtn_convert_float_to_int( const float32 &f_val, sint32 &l ) { gtn_rinttol( f_val, &l ); }
	gtn_force_inline void gtn_convert_float_to_int( const float64 &f_val, sint32 &l ) { gtn_rinttol( f_val, &l ); }
	
	gtn_force_inline void gtn_convert_float_to_int_fp1( float64 f_val, uint32 &ui_val, const sint32 &fp_high )
	{
		if ( fp_high < 0 )													// Handle case where less than 0
		{
			ui_val = 0;
		}
		else
		{
			gtn_rinttol( f_val, (sint32*) &ui_val );

			sint32 l_val   = *((sint32 *) &ui_val);
			sint32 l_val_1 = l_val + 1;						// 'l_val == 0x7FFFFFFF' ==> 'l_val_1 == 0x80000000'
			
			// f_val too large for sint32 ==> 'l_val == 0x7FFFFFFF' ==> 'l_val_1 < l_val'
			if ( l_val_1 < l_val )
			{
				// we add 'numeric_limits<sint32>::min()' and convert to 'sint32' to get a value in the range [-1,numeric_limits<sint32>::max()]
				// Then we add to 'numeric_limits<sing32>::max() + 1' ( requires wrapping in order to add '-1'
				float64 add_val = (float64) std::numeric_limits<sint32>::min();
				f_val += add_val;
				gtn_rinttol( f_val, (sint32*) &ui_val );
				ui_val += *((uint32 *) &l_val_1);
			}
		}
	}
	
#if ( defined( _GATAN_COMPILER_METROWERKS ) && ( _GATAN_COMPILER_VERSION <= 0x2100 ) )
	gtn_force_inline void gtn_convert_float_to_int( const float64 &f_val, uint32 &ul ) { sint32 neg = ( f_val < 0 ) ? -1.0 : 1.0; gtn_convert_float_to_int_fp1( f_val, ul, neg ); }
	gtn_force_inline void gtn_convert_float_to_int( const float32 &f_val, uint32 &ul ) { sint32 neg = ( f_val < 0 ) ? -1.0 : 1.0; gtn_convert_float_to_int_fp1( f_val, ul, neg ); }
#else
	gtn_force_inline void gtn_convert_float_to_int( const float64 &f_val, uint32 &ul ) { gtn_convert_float_to_int_fp1( f_val, ul, ((sint32*)&f_val)[0] ); }
	gtn_force_inline void gtn_convert_float_to_int( const float32 &f_val, uint32 &ul ) { gtn_convert_float_to_int_fp1( f_val, ul, ((sint32*)&f_val)[0] ); }
#endif

	gtn_force_inline void gtn_convert_float_to_int_noclip( const float64 f_val, sint32 &i_val )
	{
		gtn_rinttol( f_val, &i_val );
	}
    #define _GATAN_CONVERT_FLOAT_INT

#elif defined( _GATAN_OS_WIN32 )

	gtn_force_inline float64 gtn_rint( float64 val )   { float64 f; { __asm fld val __asm frndint __asm fstp f } return f; }

	gtn_force_inline void gtn_convert_float_to_int( float32 f_val, sint32 &i_val )
	{
		sint32 i_val_tmp;
		{ __asm fld f_val __asm fistp i_val_tmp }

		// Goddamn X86 floating point conversion to int returns the most negative number if the floating point
		// number is too small to large.  If too small this is ok, but we need to check if too large.
		if ( i_val_tmp == std::numeric_limits<sint32>::min() )
		{
			if ( ((sint32*)&f_val)[0] > 0 ) { i_val_tmp -= 1; }
		}
		i_val = i_val_tmp;
	}
	gtn_force_inline void gtn_convert_float_to_int( float64 f_val, sint32 &i_val )
	{
		sint32 i_val_tmp;
		{ __asm fld f_val __asm fistp i_val_tmp }

		// Goddamn X86 floating point conversion to int returns the most negative number if the floating point
		// number is too small to large.  If too small this is ok, but we need to check if too large.
		if ( i_val_tmp == std::numeric_limits<sint32>::min() )
		{
			if ( ((sint32*)&f_val)[1] > 0 ) { i_val_tmp -= 1; }
		}
		i_val = i_val_tmp;
	}

	gtn_force_inline void gtn_convert_float_to_int( float32 f_val, uint32 &ui_val )
	{
		if ( ((sint32*)&f_val)[0] < 0 )						// Check if negative
		{
			ui_val = 0;
		}
		else
		{
			{ uint32 ui_val_tmp; { __asm fld f_val __asm fist ui_val_tmp } ui_val = ui_val_tmp; }			// inline assembler can't deal with references( or pointers for that matter )
		
			if ( *((sint32 *)&ui_val) < 0 )								// We check for positive above, so if this is negative, must be overflow
			{
				float64 f_sint32_min = (float64) std::numeric_limits<sint32>::min();
				{ uint32 ui_val_tmp; { __asm fld f_sint32_min __asm faddp st(1), st __asm fistp ui_val_tmp } ui_val = ui_val_tmp; }
				ui_val ^= 0x80000000ul;		// Effectively adds '-numeric_limits<sint32>::min()'
				if ( ui_val == 0 )			// number too large ==> '(old ui_val) + 0x8000000 == 0'
				{
					ui_val -= 1;
				}
			}
			else
			{
				__asm fstp st
			}
		}
	}

	gtn_force_inline void gtn_convert_float_to_int(const float64 f_val, uint32 &ui_val )
	{
		if ( ((sint32*)&f_val)[1] < 0 )						// Check if negative
		{
			ui_val = 0;
		}
		else
		{
			{ uint32 ui_val_tmp; { __asm fld f_val __asm fist ui_val_tmp } ui_val = ui_val_tmp; }			// inline assembler can't deal with references( or pointers for that matter )
		
			if ( *((sint32 *)&ui_val) < 0 )								// We check for positive above, so if this is negative, must be overflow
			{
				float64 f_sint32_min = (float64) std::numeric_limits<sint32>::min();
				{ uint32 ui_val_tmp; { __asm fld f_sint32_min __asm faddp st(1), st __asm fistp ui_val_tmp } ui_val = ui_val_tmp; }
				ui_val ^= 0x80000000ul;		// Effectively adds '-numeric_limits<sint32>::min()'
				if ( ui_val == 0 )			// number too large ==> '(old ui_val) + 0x8000000 == 0'
				{
					ui_val -= 1;
				}
			}
			else
			{
				__asm fstp st
			}
		}
	}

	gtn_force_inline void gtn_convert_float_to_int_noclip( const float64 f_val, sint32 &i_val )
	{
		sint32 i_val_tmp;
		{ __asm fld f_val __asm fistp i_val_tmp }
		i_val = i_val_tmp;		
	}

    #define _GATAN_CONVERT_FLOAT_INT

#endif // defined( _GATAN_OS )

/*
 * class Convert<Arg1,Arg2>
 *
 *    Used to perform bounds-checked conversions fromtype 'Arg1' to 'Arg2'.
 *    Unless the class is specialized, 'Arg2' should be convertible without loss to 'Arg1',
 *    and 'Arg1' should have 'operator <' defined.
 *
 * class ComvertFloatToInt<Arg1,Arg2>
 *
 *    -- For now, 
 *
 *
 */

template <class Arg1, class Arg2> struct ConvertToBoolean : public conv_base<Arg1,Arg2>
{
	typedef numeric_data::numeric_data_traits<Arg1> arg1_numeric_traits;

	gtn_force_inline void operator()( const Arg1 &a1, Arg2 &a2 ) const { a2.val = ( ( a1 == arg1_numeric_traits::zero() ) ? 0 : 1 ); }
};
template <class Arg1, class Arg2> struct ConvertFromBoolean : public conv_base<Arg1,Arg2>
{
	gtn_force_inline void operator()( const Arg1 &a1, Arg2 &a2 ) const { a2 = (a1?((Arg2)1):((Arg2)0)); }
};
template <class Arg1, class Arg2> struct ConvertStandardCPP : public conv_base<Arg1,Arg2>
{
	gtn_force_inline void operator()( const Arg1 &a1, Arg2 &a2 ) const { a2 = ( (Arg2) a1 ); }
};

template <class Arg1, class Arg2> struct ConvertIntToInt_ClipBoth : public conv_base<Arg1,Arg2>
{
	gtn_force_inline void operator()( const Arg1 &a1, Arg2 &a2 ) const { a2 = (Arg2)( clip_val( a1, (Arg1) numeric_bounds<Arg2>::low(), (Arg1) numeric_bounds<Arg2>::high() ) ); }
};
template <class Arg1, class Arg2> struct ConvertIntToInt_ClipLow : public conv_base<Arg1,Arg2>
{
	gtn_force_inline void operator()( const Arg1 &a1, Arg2 &a2 ) const { a2 = ( a1 >= (Arg1) numeric_bounds<Arg2>::low() ) ? ((Arg2) a1) : numeric_bounds<Arg2>::low(); }
};
template <class Arg1, class Arg2> struct ConvertIntToInt_ClipHigh : public conv_base<Arg1,Arg2>
{
	gtn_force_inline void operator()( const Arg1 &a1, Arg2 &a2 ) const { a2 = ( a1 <= (Arg1) numeric_bounds<Arg2>::high() ) ? ((Arg2) a1) : numeric_bounds<Arg2>::high(); }
};
template <class Arg1, class Arg2> struct ConvertIntToInt_ClipNone : public conv_base<Arg1,Arg2>
{
	gtn_force_inline void operator()( const Arg1 &a1, Arg2 &a2 ) const { a2 = (Arg2) a1; }
};
template <class Arg1, class Arg2> struct ConvertFloatToInt : public conv_base<Arg1,Arg2>
{
	gtn_force_inline void operator()( const Arg1 &a1, Arg2 &a2 ) const { sint32 tmp; gtn_convert_float_to_int(a1,tmp); Convert<sint32,Arg2>()( tmp, a2 ); }
};

template <class RGB1, class RGB2>   struct conv_rgb_clip  : public conv_rgb<RGB1,RGB2,Convert<typename RGB1::component_type, typename RGB2::component_type> >{};
template <class RGBA1, class RGBA2> struct conv_rgba_clip : public conv_rgba<RGBA1,RGBA2,Convert<typename RGBA1::component_type, typename RGBA2::component_type> >{};
template <class P1, class P2> struct conv_point2_clip : public conv_point2<P1,P2,Convert<typename P1::component_type,typename P1::component_type> > {};

template <class Arg1, class Arg2> struct ConvertComplexToComplex : public conv_base<Arg1,Arg2>
{
	gtn_force_inline void operator()( const Arg1 &a1, Arg2 &a2 ) const
	{
		Convert<_GATAN_COMPILER_TYPENAME Arg1::component_type,_GATAN_COMPILER_TYPENAME Arg2::component_type > conv;
		conv( a1.real(), a2.real() ); conv( a1.imag(), a2.imag() );
	}
};
template <class Arg1, class Arg2> struct ConvertScalarToComplex : public conv_base<Arg1,Arg2>
{
	typedef numeric_data::numeric_data_traits<Arg1> arg1_numeric_traits;
	typedef numeric_data::numeric_data_traits<Arg2> arg2_numeric_traits;

	gtn_force_inline void operator()( const Arg1 &a1, Arg2 &a2 ) const
	{
		Convert<Arg1,_GATAN_COMPILER_TYPENAME Arg2::component_type>()( a1, a2.real() ); a2.imag() = arg2_numeric_traits::zero();
	}
};

template <class Arg1, class Arg2> struct Convert  : public conv_base<Arg1,Arg2>
{
	gtn_force_inline void operator()( const Arg1 &a1, Arg2 &a2 ) const {  a2 = a1; }
};

// Need special case when converting to 'uint32' ( out of range for 'rinttol' )
template <> struct ConvertFloatToInt<float32,uint32> : public conv_base<float32,uint32> { gtn_force_inline void operator()( const float32 &a1, uint32 &a2 ) const { gtn_convert_float_to_int( a1, a2 ); } };
template <> struct ConvertFloatToInt<float64,uint32> : public conv_base<float64,uint32> { gtn_force_inline void operator()( const float64 &a1, uint32 &a2 ) const { gtn_convert_float_to_int( a1, a2 ); } };

// The following aren't really correct.  They should use the current floating point rouding mode
template <> struct ConvertFloatToInt<float32,sint64> : public conv_base<float32,sint64> { gtn_force_inline void operator()( const float32 &a1, sint64 &a2 ) const { a2 = (sint64) a1; } };
template <> struct ConvertFloatToInt<float64,sint64> : public conv_base<float64,sint64> { gtn_force_inline void operator()( const float64 &a1, sint64 &a2 ) const { a2 = (sint64) a1; } };

template <> struct ConvertFloatToInt<float32,uint64> : public conv_base<float32,uint64> { gtn_force_inline void operator()( const float32 &a1, uint64 &a2 ) const { a2 = (uint64) a1; } };
template <> struct ConvertFloatToInt<float64,uint64> : public conv_base<float64,uint64> { gtn_force_inline void operator()( const float64 &a1, uint64 &a2 ) const { a2 = (uint64) a1; } };

#ifdef _GATAN_OS_WIN32
// These are not implemented by the VisualCPP 5 compiler
template <> struct ConvertStandardCPP<uint64,float64 > : public conv_base<uint64,float64>
{
	gtn_force_inline void operator()( const uint64 &a1_, float64 &a2 ) const
	{
		uint64 a1 = a1_;
		uint32 *a1_32  = (uint32 *) &a1;
		sint64 *a1_s64 = (sint64 *) &a1;
		if ( a1_32[1] & 0x80000000 )
		{
			a1_32[1] &= 0x7FFFFFFF;
			float64 a2_tmp = (float64) *a1_s64;
			a2 = a2_tmp + POW_2_63_DBL;
		}
		else
		{
			a2 = (float64) *a1_s64;
		}
	}
};
template <> struct ConvertStandardCPP<uint64,float32 > : public conv_base<uint64,float32>
{
	gtn_force_inline void operator()( const uint64 &a1, float32 &a2 ) const
	{
		float64 a2_tmp;
		ConvertStandardCPP<uint64,float64>()( a1, a2_tmp );
		a2 = a2_tmp;
	}
};


#endif // _GATAN_OS_WIN32

template <> struct Convert< binary8, binary8 >  : public ConvertStandardCPP< binary8, binary8 > {};
template <> struct Convert< sint8  , binary8 >  : public ConvertToBoolean< sint8  ,binary8 >  {};
template <> struct Convert< uint8  , binary8 >  : public ConvertToBoolean<  uint8 ,binary8 >  {};
template <> struct Convert< sint16 , binary8 >  : public ConvertToBoolean< sint16 ,binary8 >  {};
template <> struct Convert< uint16 , binary8 >  : public ConvertToBoolean< uint16 ,binary8 >  {};
template <> struct Convert< sint32 , binary8 >  : public ConvertToBoolean< sint32 ,binary8 >  {};
template <> struct Convert< uint32 , binary8 >  : public ConvertToBoolean< uint32 ,binary8 >  {};
template <> struct Convert< sint64 , binary8 >  : public ConvertToBoolean< sint64 ,binary8 >  {};
template <> struct Convert< uint64 , binary8 >  : public ConvertToBoolean< uint64 ,binary8 >  {};
template <> struct Convert< float32, binary8 >  : public ConvertToBoolean< float32, binary8 > {};
template <> struct Convert< float64, binary8 >  : public ConvertToBoolean< float64, binary8 > {};
template <> struct Convert< binary8, sint8   >  : public ConvertFromBoolean< binary8, sint8   > {};
template <> struct Convert< binary8, uint8   >  : public ConvertFromBoolean< binary8, uint8   > {};
template <> struct Convert< binary8, sint16  >  : public ConvertFromBoolean< binary8, sint16  > {};
template <> struct Convert< binary8, uint16  >  : public ConvertFromBoolean< binary8, uint16  > {};
template <> struct Convert< binary8, sint32  >  : public ConvertFromBoolean< binary8, sint32  > {};
template <> struct Convert< binary8, uint32  >  : public ConvertFromBoolean< binary8, uint32  > {};
template <> struct Convert< binary8, sint64  >  : public ConvertFromBoolean< binary8, sint64  > {};
template <> struct Convert< binary8, uint64  >  : public ConvertFromBoolean< binary8, uint64  > {};
template <> struct Convert< binary8, float32 >  : public ConvertFromBoolean< binary8, float32 > {};
template <> struct Convert< binary8, float64 >  : public ConvertFromBoolean< binary8, float64 > {};

template <> struct Convert< sint8  , sint8 >  : public ConvertIntToInt_ClipNone< sint8 ,sint8  > {};
template <> struct Convert< uint8  , sint8 >  : public ConvertIntToInt_ClipHigh<  uint8 ,sint8 > {};
template <> struct Convert< sint16 , sint8 >  : public ConvertIntToInt_ClipBoth< sint16 ,sint8 >   {};
template <> struct Convert< uint16 , sint8 >  : public ConvertIntToInt_ClipHigh< uint16 ,sint8 > {};
template <> struct Convert< sint32 , sint8 >  : public ConvertIntToInt_ClipBoth< sint32 ,sint8 >   {};
template <> struct Convert< uint32 , sint8 >  : public ConvertIntToInt_ClipHigh< uint32 ,sint8 > {};
template <> struct Convert< sint64 , sint8 >  : public ConvertIntToInt_ClipBoth< sint64 ,sint8 >   {};
template <> struct Convert< uint64 , sint8 >  : public ConvertIntToInt_ClipHigh< uint64 ,sint8 > {};
template <> struct Convert< float32, sint8 >  : public ConvertFloatToInt< float32, sint8 > {};
template <> struct Convert< float64, sint8 >  : public ConvertFloatToInt< float64, sint8 > {};

template <> struct Convert< sint8 , uint8 >   : public ConvertIntToInt_ClipLow< sint8 ,uint8 > {};
template <> struct Convert< uint8 , uint8 >   : public ConvertIntToInt_ClipNone< uint8 ,uint8  > {};
template <> struct Convert< sint16, uint8 >   : public ConvertIntToInt_ClipBoth< sint16,uint8 > {};
template <> struct Convert< uint16, uint8 >   : public ConvertIntToInt_ClipHigh< uint16,uint8 > {};
template <> struct Convert< sint32, uint8 >   : public ConvertIntToInt_ClipBoth< sint32,uint8 > {};
template <> struct Convert< uint32, uint8 >   : public ConvertIntToInt_ClipHigh< uint32,uint8 > {};
template <> struct Convert< sint64, uint8 >   : public ConvertIntToInt_ClipBoth< sint64,uint8 > {};
template <> struct Convert< uint64, uint8 >   : public ConvertIntToInt_ClipHigh< uint64,uint8 > {};
template <> struct Convert< float32, uint8 >  : public ConvertFloatToInt< float32, uint8 > {};
template <> struct Convert< float64, uint8 >  : public ConvertFloatToInt< float64, uint8 > {};

template <> struct Convert< sint8  , sint16 > : public ConvertIntToInt_ClipNone< sint8 ,sint16 > {};
template <> struct Convert< uint8  , sint16 > : public ConvertIntToInt_ClipNone< uint8 ,sint16 > {};
template <> struct Convert< sint16 , sint16 > : public ConvertIntToInt_ClipNone< sint16,sint16 > {};
template <> struct Convert< uint16 , sint16 > : public ConvertIntToInt_ClipHigh< uint16 ,sint16> {};
template <> struct Convert< sint32 , sint16 > : public ConvertIntToInt_ClipBoth< sint32 ,sint16> {};
template <> struct Convert< uint32 , sint16 > : public ConvertIntToInt_ClipHigh< uint32 ,sint16> {};
template <> struct Convert< sint64 , sint16 > : public ConvertIntToInt_ClipBoth< sint64 ,sint16> {};
template <> struct Convert< uint64 , sint16 > : public ConvertIntToInt_ClipHigh< uint64 ,sint16> {};
template <> struct Convert< float32, sint16>  : public ConvertFloatToInt< float32, sint16> {};
template <> struct Convert< float64, sint16>  : public ConvertFloatToInt< float64, sint16> {};

template <> struct Convert< sint8  , uint16 >  : public ConvertIntToInt_ClipLow< sint8 ,uint16> {};
template <> struct Convert< uint8  , uint16 >  : public ConvertIntToInt_ClipNone< uint8 ,uint16 > {};
template <> struct Convert< sint16 , uint16 >  : public ConvertIntToInt_ClipLow< sint16,uint16> {};
template <> struct Convert< uint16 , uint16 >  : public ConvertIntToInt_ClipNone< uint16,uint16 > {};
template <> struct Convert< sint32 , uint16 >  : public ConvertIntToInt_ClipBoth< sint32,uint16> {};
template <> struct Convert< uint32 , uint16 >  : public ConvertIntToInt_ClipHigh< uint32,uint16> {};
template <> struct Convert< sint64 , uint16 >  : public ConvertIntToInt_ClipBoth< sint64,uint16> {};
template <> struct Convert< uint64 , uint16 >  : public ConvertIntToInt_ClipHigh< uint64,uint16> {};
template <> struct Convert< float32, uint16 >  : public ConvertFloatToInt< float32, uint16> {};
template <> struct Convert< float64, uint16 >  : public ConvertFloatToInt< float64, uint16> {};

template <> struct Convert< sint8  , sint32 >  : public ConvertIntToInt_ClipNone< sint8  ,sint32 > {};
template <> struct Convert< uint8  , sint32 >  : public ConvertIntToInt_ClipNone< uint8  ,sint32 > {};
template <> struct Convert< sint16 , sint32 >  : public ConvertIntToInt_ClipNone< sint16 ,sint32 > {};
template <> struct Convert< uint16 , sint32 >  : public ConvertIntToInt_ClipNone< uint16 ,sint32 > {};
template <> struct Convert< sint32 , sint32 >  : public ConvertIntToInt_ClipNone< sint32 ,sint32 > {};
template <> struct Convert< uint32 , sint32 >  : public ConvertIntToInt_ClipHigh< uint32 ,sint32> {};
template <> struct Convert< sint64 , sint32 >  : public ConvertIntToInt_ClipBoth< sint64 ,sint32 > {};
template <> struct Convert< uint64 , sint32 >  : public ConvertIntToInt_ClipHigh< uint64 ,sint32> {};
template <> struct Convert< float32, sint32 >  : public ConvertFloatToInt< float32, sint32> {};
template <> struct Convert< float64, sint32 >  : public ConvertFloatToInt< float64, sint32> {};

template <> struct Convert< sint8  , uint32 >  : public ConvertIntToInt_ClipLow< sint8 ,uint32> {};
template <> struct Convert< uint8  , uint32 >  : public ConvertIntToInt_ClipNone< uint8 ,uint32 > {};
template <> struct Convert< sint16 , uint32 >  : public ConvertIntToInt_ClipLow< sint16 ,uint32> {};
template <> struct Convert< uint16 , uint32 >  : public ConvertIntToInt_ClipNone< uint16,uint32 > {};
template <> struct Convert< sint32 , uint32 >  : public ConvertIntToInt_ClipLow< sint32,uint32> {};
template <> struct Convert< uint32 , uint32 >  : public ConvertIntToInt_ClipNone< uint32,uint32 > {};
template <> struct Convert< sint64 , uint32 >  : public ConvertIntToInt_ClipBoth< sint64,uint32> {};
template <> struct Convert< uint64 , uint32 >  : public ConvertIntToInt_ClipHigh< uint64,uint32 > {};
template <> struct Convert< float32, uint32 >  : public ConvertFloatToInt< float32, uint32> {};
template <> struct Convert< float64, uint32 >  : public ConvertFloatToInt< float64, uint32> {};

template <> struct Convert< sint8  , sint64 >  : public ConvertIntToInt_ClipNone< sint8  ,sint64 > {};
template <> struct Convert< uint8  , sint64 >  : public ConvertIntToInt_ClipNone< uint8  ,sint64 > {};
template <> struct Convert< sint16 , sint64 >  : public ConvertIntToInt_ClipNone< sint16 ,sint64 > {};
template <> struct Convert< uint16 , sint64 >  : public ConvertIntToInt_ClipNone< uint16 ,sint64 > {};
template <> struct Convert< sint32 , sint64 >  : public ConvertIntToInt_ClipNone< sint32 ,sint64 > {};
template <> struct Convert< uint32 , sint64 >  : public ConvertIntToInt_ClipNone< uint32 ,sint64 > {};
template <> struct Convert< sint64 , sint64 >  : public ConvertIntToInt_ClipNone< sint64 ,sint64 > {};
template <> struct Convert< uint64 , sint64 >  : public ConvertIntToInt_ClipHigh< uint64 ,sint64> {};
template <> struct Convert< float32, sint64 >  : public ConvertFloatToInt< float32, sint64> {};
template <> struct Convert< float64, sint64 >  : public ConvertFloatToInt< float64, sint64> {};

template <> struct Convert< sint8  , uint64 >  : public ConvertIntToInt_ClipLow< sint8 ,uint64> {};
template <> struct Convert< uint8  , uint64 >  : public ConvertIntToInt_ClipNone< uint8 ,uint64 > {};
template <> struct Convert< sint16 , uint64 >  : public ConvertIntToInt_ClipLow< sint16 ,uint64> {};
template <> struct Convert< uint16 , uint64 >  : public ConvertIntToInt_ClipNone< uint16,uint64 > {};
template <> struct Convert< sint32 , uint64 >  : public ConvertIntToInt_ClipLow< sint32,uint64> {};
template <> struct Convert< uint32 , uint64 >  : public ConvertIntToInt_ClipNone< uint32,uint64 > {};
template <> struct Convert< sint64 , uint64 >  : public ConvertIntToInt_ClipLow< sint64,uint64> {};
template <> struct Convert< uint64 , uint64 >  : public ConvertIntToInt_ClipNone< uint64,uint64 > {};
template <> struct Convert< float32, uint64 >  : public ConvertFloatToInt< float32, uint64> {};
template <> struct Convert< float64, uint64 >  : public ConvertFloatToInt< float64, uint64> {};

template <> struct Convert< sint8  , float32>  : public ConvertStandardCPP< sint8 ,float32 > {};
template <> struct Convert< uint8  , float32>  : public ConvertStandardCPP< uint8 ,float32 > {};
template <> struct Convert< sint16 , float32>  : public ConvertStandardCPP< sint16,float32 > {};
template <> struct Convert< uint16 , float32>  : public ConvertStandardCPP< uint16,float32 > {};
template <> struct Convert< sint32 , float32>  : public ConvertStandardCPP< sint32,float32 > {};
template <> struct Convert< uint32 , float32>  : public ConvertStandardCPP< uint32,float32 > {};
template <> struct Convert< sint64 , float32>  : public ConvertStandardCPP< sint64,float32 > {};
template <> struct Convert< uint64 , float32>  : public ConvertStandardCPP< uint64,float32 > {};
template <> struct Convert< float32, float32>  : public ConvertStandardCPP<float32,float32 > {};
template <> struct Convert< float64, float32>  : public ConvertStandardCPP<float64,float32 > {};

template <> struct Convert< sint8  , float64> : public ConvertStandardCPP< sint8 ,float64 > {};
template <> struct Convert< uint8  , float64> : public ConvertStandardCPP< uint8 ,float64 > {};
template <> struct Convert< sint16 , float64> : public ConvertStandardCPP< sint16,float64 > {};
template <> struct Convert< uint16 , float64> : public ConvertStandardCPP< uint16,float64 > {};
template <> struct Convert< sint32 , float64> : public ConvertStandardCPP< sint32,float64 > {};
template <> struct Convert< uint32 , float64> : public ConvertStandardCPP< uint32,float64 > {};
template <> struct Convert< sint64 , float64> : public ConvertStandardCPP< sint64,float64 > {};
template <> struct Convert< uint64 , float64> : public ConvertStandardCPP< uint64,float64 > {};
template <> struct Convert< float32, float64> : public ConvertStandardCPP<float32,float64 > {};
template <> struct Convert< float64, float64> : public ConvertStandardCPP<float64,float64 > {};

template <> struct Convert< sint8       , complex64_t>  : public ConvertScalarToComplex<sint8,complex64_t>   {};
template <> struct Convert< uint8       , complex64_t>  : public ConvertScalarToComplex<uint8,complex64_t>   {};
template <> struct Convert< sint16      , complex64_t>  : public ConvertScalarToComplex<sint16,complex64_t>  {};
template <> struct Convert< uint16      , complex64_t>  : public ConvertScalarToComplex<uint16,complex64_t>  {};
template <> struct Convert< sint32      , complex64_t>  : public ConvertScalarToComplex<sint32,complex64_t>  {};
template <> struct Convert< uint32      , complex64_t>  : public ConvertScalarToComplex<uint32,complex64_t>  {};
template <> struct Convert< float32     , complex64_t>  : public ConvertScalarToComplex<float32,complex64_t> {};
template <> struct Convert< float64     , complex64_t>  : public ConvertScalarToComplex<float64,complex64_t> {};
template <> struct Convert< complex64_t , complex64_t>  : public ConvertStandardCPP<complex64_t,complex64_t>   {};
template <> struct Convert< complex128_t, complex64_t>  : public ConvertComplexToComplex<complex128_t,complex64_t> {};

template <> struct Convert< sint8       , complex128_t> : public ConvertScalarToComplex<sint8,complex128_t>   {};
template <> struct Convert< uint8       , complex128_t> : public ConvertScalarToComplex<uint8,complex128_t>   {};
template <> struct Convert< sint16      , complex128_t> : public ConvertScalarToComplex<sint16,complex128_t>  {};
template <> struct Convert< uint16      , complex128_t> : public ConvertScalarToComplex<uint16,complex128_t>  {};
template <> struct Convert< sint32      , complex128_t> : public ConvertScalarToComplex<sint32,complex128_t>  {};
template <> struct Convert< uint32      , complex128_t> : public ConvertScalarToComplex<uint32,complex128_t>  {};
template <> struct Convert< float32     , complex128_t> : public ConvertScalarToComplex<float32,complex128_t> {};
template <> struct Convert< float64     , complex128_t> : public ConvertScalarToComplex<float64,complex128_t> {};
template <> struct Convert< complex64_t , complex128_t> : public ConvertComplexToComplex<complex64_t,complex128_t> {};
template <> struct Convert< complex128_t, complex128_t> : public ConvertStandardCPP<complex128_t,complex128_t> {};

template <> struct Convert< rgba_uint8_os_t, rgba_uint8_os_t > : public ConvertStandardCPP< rgba_uint8_os_t, rgba_uint8_os_t > {};
template <> struct Convert< rgba_uint8_os_t, rgba_float32_t >  : public conv_rgba_clip< rgba_uint8_os_t, rgba_float32_t > {};
template <> struct Convert< rgba_uint8_os_t, rgba_float64_t >  : public conv_rgba_clip< rgba_uint8_os_t, rgba_float64_t > {};
template <> struct Convert< rgba_float32_t , rgba_uint8_os_t > : public conv_rgba_clip< rgba_float32_t, rgba_uint8_os_t > {};
template <> struct Convert< rgba_float64_t , rgba_uint8_os_t > : public conv_rgba_clip< rgba_float64_t, rgba_uint8_os_t > {};

template <> struct Convert< rgba_float64_t , rgba_float64_t >  : public ConvertStandardCPP< rgba_float64_t, rgba_float64_t > {};
template <> struct Convert< rgba_float32_t , rgba_float32_t >  : public ConvertStandardCPP< rgba_float32_t, rgba_float32_t > {};
template <> struct Convert< rgb_uint16_t   , rgb_uint16_t >    : public ConvertStandardCPP< rgb_uint16_t, rgb_uint16_t > {};


template <typename Src, typename Dst> inline Dst numeric_convert( const Src &src )
	{ Dst dst; Convert<Src,Dst>()( src, dst ); return dst; }

} // namespace Gatan

#endif // __GATANTYPECONVERSION__


