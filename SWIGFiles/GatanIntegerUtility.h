
#ifndef __GATANINTEGERUTILITY__
#define __GATANINTEGERUTILITY__

#include "GatanDefines.h"
#include "GatanFoundationBase.h"
#include "GatanTypes.h"

namespace Gatan
{
	/*
	** Useful integer functions.
	*/

	extern bool   gtn_idiv_sint32( sint32 numer, sint32 denom, sint32 &quot_out, sint32 &rem_out );
	extern bool   gtn_idiv_uint32( uint32 numer, uint32 denom, uint32 &quot_out, uint32 &rem_out );
	extern uint32 gtn_factorial( uint32 val );

	inline sint32 idiv_floor( sint32 numer, sint32 denom )
		{ sint32 quot = 0, rem = 0; gtn_idiv_sint32( numer, denom, quot, rem ); return quot + ( ( ( rem != 0 ) && ( denom < 0 ) ) ? -1 : 0 ); }

	inline sint32 idiv_ceil( sint32 numer, sint32 denom )
		{ sint32 quot = 0, rem = 0; gtn_idiv_sint32( numer, denom, quot, rem ); return quot + ( ( ( rem != 0 ) && ( denom > 0 ) ) ?  1 : 0 ); }

	inline uint32 ifloor( uint32 numer, uint32 denom )
		{ return denom * ( numer / denom ); }
	inline uint32 iceil( uint32 numer, uint32 denom )
		{ uint32 val = denom * ( numer / denom ); if ( val != numer ) { val += denom; } return val; }

	inline bool   is_pow2( uint32 number )
		{ return ( number != 0 ) && ( ( ( number - 1 ) & number ) == 0 ); }
	extern uint32 ipow2( uint32 val );
	extern double ipow( double val, long p );

	extern uint32 rotate_right( uint32 value, uint32 count );
	extern uint32 rotate_left( uint32 value, uint32 count );

	extern uint32 count_ones( uint32 num );
	extern uint32 count_zeros( uint32 num );

	template <typename ValType> int gtn_sign( ValType val_in )
	{
		return ( val_in == (ValType) 0 ) ? 0 : ( (val_in < (ValType) 0 ) ? -1 : 1 );
	}

	extern uint32 ilog2_floor_v0( uint32 val );
	extern uint32 ifloor_pow2_v0( uint32 val );
	extern uint32 iceil_pow2( uint32 val );
	extern uint32 ilog2_ceil( uint32 number );

#if defined( _GATAN_ARCHITECTURE_POWERPC )

	inline uint32 ilog2_floor( uint32 val ) { return ilog2_floor_v0( val ); }
	inline uint32 ifloor_pow2( uint32 val ) { return ifloor_pow2_v0( val ); }

#elif defined( _GATAN_ARCHITECTURE_X86 )

	extern "C" uint32 ilog2_floor_asm_x86( uint32 number );
	extern "C" uint32 ifloor_pow2_asm_x86( uint32 number );

	inline uint32 ilog2_floor( uint32 val ) { return ilog2_floor_asm_x86( val ); }
	inline uint32 ifloor_pow2( uint32 val ) { return ifloor_pow2_asm_x86( val ); }

#endif // defined(_GATAN_ARCHITECTURE )
}

#endif // __GATANINTEGERUTILITY__