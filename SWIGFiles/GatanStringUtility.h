
#ifndef __GATANSTRINGUTILITY__
#define __GATANSTRINGUTILITY__

#include <string>			// for 'std::char_traits'
#include <cassert>

#include <boost/config.hpp>

namespace Gatan
{
	template <typename T> class value_range
	{
	public:
		typedef T              value_type;
		typedef T             *iterator;
		typedef const T       *const_iterator;
		typedef T             &reference;
		typedef const T       &const_reference;
		typedef std::size_t    size_type;
		typedef std::ptrdiff_t difference_type;
	private:
		value_type *beg_;
		value_type *end_;
	public:
		value_range() : beg_( NULL ), end_( NULL ) {}
		value_range( value_type *beg__, value_type *end__ )
			: beg_( beg__ ), end_( end__ )
		{}
		value_range( value_type *beg__, size_type size )
			: beg_( beg__ ), end_( beg__ + size )
		{}
		template <typename Init> value_range( Init &init )
			: beg_( NULL ), end_( NULL )
		{
			construct_value_range( init, *this );
		}
			
		size_type   size()  const    { return ( end_ - beg_ ); }
		bool        empty() const    { return ( end_ == beg_ ); }
		size_type   max_size() const { return ( end_ - beg_ ); }

		iterator    begin() const    { return beg_; }
		iterator    end()   const    { return end_; }

		reference   operator[]( size_type i ) const { return beg[i]; }
		reference   at( size_type i ) const         { rangecheck( i, size() ); return beg[i]; }
		reference   front() const                   { return *beg; }
		reference   back() const                    { return *(end-1); }

		void assign( value_type *beg__, value_type *end__ )   { beg_ = beg__; end_ = end__; }

        static void rangecheck( size_type i, size_type size )
        {
            if ( i >= size ) { throw std::range_error("value_range"); }
        }
	};

	template <typename T> class const_value_range
	{
	public:
		typedef T              value_type;
		typedef T             *iterator;
		typedef const T       *const_iterator;
		typedef T             &reference;
		typedef const T       &const_reference;
		typedef std::size_t    size_type;
		typedef std::ptrdiff_t difference_type;
	private:
		const value_type *beg_;
		const value_type *end_;
	public:
		const_value_range() : beg_( NULL ), end_( NULL ) {}
		const_value_range( const value_type *beg__, const value_type *end__ )
			: beg_( beg__ ), end_( end__ )
		{}
		const_value_range( const value_type *beg__, size_type size )
			: beg_( beg__ ), end_( beg__ + size )
		{}
		template <typename Init> const_value_range( const Init &init )
			: beg_( NULL ), end_( NULL )
		{
			construct_const_value_range( init, *this );
		}
			
		size_type         size()  const    { return ( end_ - beg_ ); }
		bool              empty() const    { return ( end_ == beg_ ); }
		size_type         max_size() const { return ( end_ - beg_ ); }

		const_iterator    begin() const    { return beg_; }
		const_iterator    end() const      { return end_; }

		const_reference   operator[]( size_type i ) const { return beg[i]; }
		const_reference   at( size_type i ) const         { rangecheck( i, size() ); return beg[i]; }
		const_reference   front() const                   { return *beg; }
		const_reference   back() const                    { return *(end-1); }
		
		void assign( const value_type *beg__, const value_type *end__ )   { beg_ = beg__; end_ = end__; }

        static void rangecheck( size_type i, size_type size )
        {
            if ( i >= size ) { throw std::range_error("const_value_range"); }
        }
	};
}

namespace Gatan
{
	template <typename T, std::size_t N> class local_array
	{
	public:
		typedef T              value_type;
		typedef T             *iterator;
		typedef const T       *const_iterator;
		typedef T             &reference;
		typedef const T       &const_reference;
		typedef std::size_t    size_type;
		typedef std::ptrdiff_t difference_type;
	private:
		value_type arr[N];
	public:
		local_array() {}
		local_array( const value_type &val_0 )
			{ assert( N > 0 ); arr[0] = val_0; }
		local_array( const value_type &val_0, const value_type &val_1 )
			{ assert( N > 1 ); arr[0] = val_0; arr[1] = val_1; }
		local_array( const value_type &val_0, const value_type &val_1, const value_type &val_2 )
			{ assert( N > 2 ); arr[0] = val_0; arr[1] = val_1; arr[2] = val_2; }
		local_array( const value_type &val_0, const value_type &val_1, const value_type &val_2, const value_type &val_3 )
			{ assert( N > 3 ); arr[0] = val_0; arr[1] = val_1; arr[2] = val_2; arr[3] = val_3; }
		local_array( const value_type &val_0, const value_type &val_1, const value_type &val_2, const value_type &val_3, const value_type &val_4 )
			{ assert( N > 4 ); arr[0] = val_0; arr[1] = val_1; arr[2] = val_2; arr[3] = val_3; arr[4] = val_4; }
		local_array( const value_type &val_0, const value_type &val_1, const value_type &val_2, const value_type &val_3, const value_type &val_4, const value_type &val_5 )
			{ assert( N > 5 ); arr[0] = val_0; arr[1] = val_1; arr[2] = val_2; arr[3] = val_3; arr[4] = val_4; arr[5] = val_5; }

		size_type         size() const     { return N; }
		bool              empty() const    { return ( N == 0 ); }
		size_type         max_size() const { return N; }
			
		iterator          begin()       { return &arr[0]; }
		iterator          end()         { return &arr[N]; }
		const_iterator    begin() const { return &arr[0]; }
		const_iterator    end() const   { return &arr[N]; }

		reference         operator[]( size_type i )       { return arr[i]; }
		reference         at( size_type i )               { rangecheck( i ); return arr[i]; }
		const_reference   operator[]( size_type i ) const { return arr[i]; }
		const_reference   at( size_type i ) const         { rangecheck( i ); return arr[i]; }

		reference         front()                         { return arr[0]; }
		reference         back()                          { return arr[N-1]; }
		const_reference   front() const                   { return arr[0]; }
		const_reference   back() const                    { return arr[N-1]; }

        static void rangecheck( size_type i )
        {
            if ( i >= N ) { throw std::range_error("local_array"); }
        }
	};
}

// STL integration

#include <vector>

namespace Gatan
{
	template <typename Value, std::size_t N>
		void construct_const_value_range( const local_array<Value,N> &arr, const_value_range<Value> &val_range )
	{
		val_range.assign( arr.begin(), arr.end() );
	}

	template <typename Value, typename Allocator>
		void construct_const_value_range( const std::vector<Value,Allocator> &vec, const_value_range<Value> &val_range )
	{
		typename std::vector<Value,Allocator>::size_type vec_len = vec.size();
		const Value *vec_beg = ( vec_len == 0 ) ? NULL : &vec[0];
		val_range.assign( vec_beg, vec_beg + vec_len );
	}
}

// Boost integration

#include <boost/array.hpp>

namespace Gatan
{
	template <typename ValueType, std::size_t N>
		void construct_value_range( boost::array<ValueType,N> &arr, value_range<ValueType> &val_range )
	{
		val_range.assign( arr.begin(), arr.end() );
	}

	template <typename Value, std::size_t N>
		void construct_const_value_range( const boost::array<Value,N> &arr, const_value_range<Value> &val_range )
	{
		val_range.assign( arr.begin(), arr.end() );
	}
}

namespace Gatan
{
	/* char_range
	 *
	 *    A utility class to allow 'string' or 'char *' to be passed to an argument without
	 * requiring allocating space for a temporary 'string'.
	 *
	 */
	 
	template <typename CharType, typename TraitsType> class char_range_t
	{
	public:
		typedef char_range_t         this_type;
		typedef size_t               size_type;
		typedef TraitsType           traits_type;
		typedef CharType             char_type;
		typedef char_type            value_type;
		typedef const char_type     *const_iterator;

		BOOST_STATIC_CONSTANT( size_type, npos  = (size_type) -1 );

		const_iterator beg_;
		const_iterator end_;

		void construct( const_iterator s, const_iterator e ) { beg_ = s; end_ = e; }

		/*
		** char_range_t( char_type *s )
		**    this overload is used to avoid using template for 'char_type *' argument ( non-const )
		*/
		char_range_t() : beg_(NULL), end_(NULL) {}
		char_range_t( const_iterator s, const_iterator e ) : beg_(s), end_(e) {}
		char_range_t( const_iterator s, size_type length ) : beg_(s), end_(s+length) {}
		char_range_t( const_iterator s ) : beg_(s), end_( s + ((s==NULL)?0:traits_type::length(s)) ) {}
		char_range_t( char_type *s ) : beg_(s), end_( s + ((s==NULL)?0:traits_type::length(s)) ) {}

		template<typename string_type> char_range_t( const string_type &str )
			: beg_( NULL ), end_( NULL )
		{
			construct_char_range( str, *this );
		}

		bool           empty()  const { return ( beg_ == end_ ); }
		size_type      size() const   { return ( end_ - beg_ ); }
		size_type      length() const { return ( end_ - beg_ ); }
		const_iterator data() const   { return beg_; }

		const char_type &operator[]( size_type ind ) const { return beg_[ind]; }

		const_iterator begin() const  { return beg_; }
		const_iterator start() const  { return beg_; }
		const_iterator end() const    { return end_; }

		size_type find( char_type val, size_type off = 0 ) const
		{
			size_type found_pos = npos;
			size_type len = size();
			if ( off < len )
			{
				const char_type *found_char = traits_type::find( begin() + off, ( len - off ), val );
				if ( found_char != NULL ) { found_pos = ( found_char - begin() ); }
			}
			return found_pos;
		}

		int compare( const this_type &str2 ) const
		{
			const this_type &str1 = *this;
			size_type len     = std::min( str1.size(), str2.size() );
			int pref_comp_res = traits_type::compare( str1.data(), str2.data(), len );
			return ( pref_comp_res != 0 ) ? pref_comp_res : int( str1.size() - str2.size() );
		}

		this_type substr( size_type offset, size_type des_size ) const
		{
			size_type cur_size = size();
			size_type       max_size = ( offset < cur_size ) ? ( cur_size - offset ) : 0;
			const_iterator  sub_beg  = ( offset < cur_size ) ? ( begin() + offset ) : end();
			size_type act_size = std::min( des_size, max_size );
			return this_type( sub_beg,sub_beg+act_size);
		}
		size_type copy( char_type *dst, size_type des_copy, size_type offset = 0 ) const
		{
			this_type copy_substr = substr( offset, des_copy );
			traits_type::copy( dst, copy_substr.begin(), copy_substr.size() );
			return copy_substr.size();
		}
		template<typename string_type> size_type copy( string_type &str ) const
		{
			str.assign( begin(), end() );
			return size();
		}

		inline bool operator!=( const this_type &str2 ) const { return ( compare(str2) != 0 ); }
		inline bool operator==( const this_type &str2 ) const { return ( compare(str2) == 0 ); }
		inline bool operator< ( const this_type &str2 ) const { return ( compare(str2) < 0 ); }
		inline bool operator<=( const this_type &str2 ) const { return ( compare(str2) <= 0 ); }
		inline bool operator> ( const this_type &str2 ) const { return ( compare(str2) > 0 ); }
		inline bool operator>=( const this_type &str2 ) const { return ( compare(str2) >= 0 ); }
	};

	template <typename CharType>
		void construct_char_range( const CharType *str, char_range_t<CharType,std::char_traits<CharType> > &dst_char_range )
	{
		dst_char_range.construct( str, ( str + ((str==NULL) ? 0 : std::char_traits<CharType>::length(str)) ) );
	}

	template <typename CharType, typename TraitsType>
		void construct_char_range( const char_range_t<CharType,TraitsType> &str, char_range_t<CharType,TraitsType> &dst_char_range )
	{
		dst_char_range.construct( str.begin(), str.end() );
	}

	template <typename CharType, typename TraitsType>
		CharType get_string_char_type( const char_range_t<CharType,TraitsType> &str );
	/*
	**
	*/
	template <typename CharType, typename TraitsType> class char_range_buffer_t
	{
	public:
		typedef char_range_buffer_t  this_type;
		typedef size_t               size_type;
		typedef TraitsType           traits_type;
		typedef CharType             char_type;
		typedef char_type            value_type;
		typedef char_range_t<char_type,traits_type>      range_type;
		typedef const char_type     *const_iterator;
		typedef       char_type     *iterator;

		iterator  beg_;
		iterator  cur_;
		iterator  end_;
		size_type overflow_;

		void construct( iterator s, iterator c, iterator e )
		{
			beg_ = s; cur_ = c; end_ = e; overflow_ = 0;
		}

		char_range_buffer_t()
			: beg_(NULL), cur_( NULL ), end_(NULL), overflow_(0)
		{}
		char_range_buffer_t( iterator s, iterator e )
			: beg_(s), cur_(s), end_(e), overflow_(0)
		{}
		char_range_buffer_t( iterator s, iterator c, iterator e )
			: beg_(s), cur_(c), end_(e), overflow_(0)
		{}

		char_type       *begin() const     { return beg_; }
		char_type       *current() const   { return cur_; }
		char_type       *end() const       { return end_; }

		const char_type *data() const      { return beg_; }
		size_type        size() const      { return ( cur_ - beg_ ); }
		size_type      length() const      { return ( cur_ - beg_ ); }
		size_type      resize( size_type des_size )
		{
			size_type act_size = std::min( des_size, capacity() );
			cur_      = beg_ + act_size;
			overflow_ = ( des_size - act_size );
			return act_size;
		}

		const char_type &operator[]( size_type ind ) const { return beg_[ind]; }
		      char_type &operator[]( size_type ind )       { return beg_[ind]; }

		size_type  capacity() const           { return ( end_ - beg_ ); }
		size_type  capacity_remaining() const { return ( end_ - cur_ ); }
		size_type  overflow() const           { return overflow_; }

		size_type  reserve( size_type des_size )
		{
			size_type act_size = des_size;
			size_type tot_cap  = capacity();
			if ( act_size > tot_cap )
			{
				overflow_ = ( act_size - tot_cap );
				act_size  = tot_cap;
			}
			return act_size;
		}
		size_type  reserve_remaining( size_type des_size )
		{
			size_type act_size = des_size;
			size_type rem_cap = capacity_remaining();
			if ( act_size > rem_cap )
			{
				overflow_ += ( act_size - rem_cap );
				act_size = rem_cap;
			}
			return act_size;
		}

		this_type &bump( int off )
		{
			size_type des_pos = ( cur_ - beg_ ) + off;
			size_type act_pos = clip( des_pos, (size_type) 0, capacity() );
			cur_ = beg_ + act_pos;
			return *this;
		}
		this_type &skip( size_type num_skip )
		{
			cur_ += reserve_remaining( num_skip );
			return *this;
		}
		this_type &replace( size_type des_rep_beg, size_type des_rem_size, const range_type &str )
		{
			size_type orig_def_size = size();                             // original size of defined portion of buffer
			size_type cur_tot_size  = orig_def_size + overflow();
			size_type act_rep_beg   = ( des_rep_beg <= cur_tot_size ) ? des_rep_beg : cur_tot_size;
			size_type act_rep_end   = act_rep_beg + min( des_rem_size, ( cur_tot_size - act_rep_beg ) );
			size_type des_copy_size = str.size();
			size_type des_move_size = cur_tot_size - act_rep_end;
			size_type des_tot_size  = des_rep_beg + des_copy_size + des_move_size;

			size_type act_tot_size  = reserve( des_tot_size );
			size_type max_copy_size = ( des_rep_beg <= act_tot_size ) ? ( act_tot_size - des_rep_beg ) : 0;
			size_type act_copy_size = 0;
			if ( des_copy_size <= max_copy_size )
			{
				if ( des_move_size != 0 )
				{
					size_type act_move_beg_dst = des_rep_beg + des_copy_size;
					size_type act_move_beg_src = act_rep_end;
					if ( act_move_beg_dst < act_tot_size )
					{
						size_type max_move_size_dst = ( act_tot_size - act_move_beg_dst );
						size_type act_move_size_dst = std::min( des_move_size, max_move_size_dst );

						size_type max_move_size_src = ( act_rep_beg <= orig_def_size ) ? ( orig_def_size - act_rep_beg ) : 0;
						size_type act_move_size_src = std::min( act_move_size_dst, max_move_size_src );
						
						const char_type *dst_ptr = beg_ + act_move_beg_dst;
						traits_type::move( dst_ptr, beg_ + act_move_beg_src, act_move_size_src );
						dst_ptr += act_move_size_src;

						// Fill section that should be copied, but does not exist in the origin buffer, with '0'
						std::fill( dst_ptr, dst_ptr+(act_move_size_dst-act_move_size_src), (char_type) 0 );
					}
				}
				act_copy_size = des_copy_size;
			}
			else
			{
				act_copy_size = max_copy_size;
			}
			if ( act_copy_size != 0 )
			{
				traits_type::copy( cur_ + des_rep_beg, act_copy_size );
			}
			
			cur_ = beg_ + act_tot_size;
			return *this;
		}
		this_type &append( const range_type &str )
		{
			size_type num_copy = reserve_remaining( str.size() );

			traits_type::copy( cur_, str.begin(), num_copy );
			cur_ += num_copy;
			return *this;
		}
		
		this_type &append( size_type des_num, char_type c )
		{
			size_type act_num = reserve_remaining( des_num );
			traits_type::assign( cur_, act_num, c );
			cur_ += act_num;
			return *this;
		}

		this_type &assign( const range_type &str )
		{
			cur_ = beg_;
			return append( str );
		}
	};

	/*
	** class string_proxy_t<CharType>
	**
	**    Utility class that allows implementing a function that will work for a wide range of string types.
	** Its primary use is to allow a method of a low-level class to avoid specifying exactly the value of
	** strings it will work with.
	*/
	template <typename CharType,typename TraitsType> class string_proxy_t
	{
	public:
		typedef string_proxy_t         this_type;
		typedef string_proxy_t         string_proxy_type;
		typedef TraitsType             traits_type;
		typedef CharType               char_type;
		typedef char_range_t<char_type,traits_type>        range_type;
		typedef char_range_buffer_t<char_type,traits_type> range_buffer_type;
		typedef size_t                 size_type;
		typedef char_type              value_type;
		typedef void                  *string_token_type;

		typedef void      *(*lock_char_range_proc_type)(   string_token_type str_token, size_type des_size, range_buffer_type &locked_range );
		typedef void       (*unlock_char_range_proc_type)( string_token_type str_token, void *lock_data, const range_buffer_type &locked_range );
		typedef size_type  (*assign_char_range_proc_type)( string_token_type str_token, const range_type &range );
		typedef void       (*extract_char_range_proc_type)( string_token_type str_token, range_type &range );
	
		class char_range_lock
		{
		public:
			typedef char_range_lock this_type;
		private:
			const string_proxy_type  &string_proxy;
			range_buffer_type         range_buffer;
			void                     *lock_data;
			
			void do_lock( size_type des_size )
			{
				assert( lock_data == NULL );
				range_buffer = string_proxy.lock_char_range( des_size, lock_data );
			}
			void do_unlock()
			{
				if ( lock_data != NULL )
				{
					string_proxy.unlock_char_range( range_buffer, lock_data );
					range_buffer = range_buffer_type();
					lock_data = NULL;
				}
			}
		public:
			char_range_lock( const string_proxy_type &string_proxy_ )
				: string_proxy( string_proxy_ )
				, lock_data( NULL )
			{
			}
			char_range_lock( const string_proxy_type &string_proxy_, size_type des_size )
				: string_proxy( string_proxy_ )
				, lock_data( NULL )
			{
				do_lock( des_size );
			}
			~char_range_lock()
			{
				do_unlock();
			}
			
			void lock( size_type des_size )
			{
				do_lock( des_size );
			}
			void unlock()
			{
				do_unlock();
			}
			
			char_type *begin() const   { return range_buffer.begin(); }
			char_type *current() const { return range_buffer.current(); }
			char_type *end() const     { return range_buffer.end(); }
			size_type  size() const    { return range_buffer.size(); }
			size_type  capacity() const { return range_buffer.capacity(); }
			size_type  resize( size_type des_size ) { return range_buffer.resize( des_size ); }
			size_type  reserve( size_type des_cap, size_type alloc_block )
			{
				size_type cur_cap = capacity();
				if ( des_cap > cur_cap )
				{
					do_unlock();
					do_lock( iceil( des_cap, alloc_block ) );
				}
				return capacity();
			}
			this_type &append( const range_type &str ) { range_buffer.append( str ); return *this; }		
			this_type &append( size_type des_num, char_type c ) { range_buffer.append( des_num, c ); return *this; }

			range_buffer_type &get_buffer() { return range_buffer; }
		};
	private:
		string_token_type              string_token;
		lock_char_range_proc_type      lock_char_range_proc;
		unlock_char_range_proc_type    unlock_char_range_proc;
		assign_char_range_proc_type    assign_char_range_proc;
		extract_char_range_proc_type   extract_char_range_proc;
	public:
		string_proxy_t()
			: string_token( NULL )
			, lock_char_range_proc( NULL )
			, unlock_char_range_proc( NULL )
			, assign_char_range_proc( NULL )
			, extract_char_range_proc( NULL )
		{}
		/*
		** the 'bool' is an annoying hack to get around a VisualC++ 6 bug where it thinks
		** the copy constructor is ambiguous with the template constructor.
		*/
		string_proxy_t( const this_type &str_2, bool )
		{
			construct( str_2.string_token, str_2.lock_char_range_proc, str_2.unlock_char_range_proc
			         , str_2.assign_char_range_proc, str_2.extract_char_range_proc );
		}
		template <typename string_proxy_type> string_proxy_t( string_proxy_type &string_proxy )
		{
			construct_string_proxy( string_proxy, *this );
		}
		
		void  construct( string_token_type s, lock_char_range_proc_type l_p, unlock_char_range_proc_type u_p
		               , assign_char_range_proc_type a_p, extract_char_range_proc_type a_e )
		{
			string_token           = s;
			lock_char_range_proc   = l_p;
			unlock_char_range_proc = u_p;
			assign_char_range_proc = a_p;
			extract_char_range_proc = a_e;
		}

		range_buffer_type lock_char_range( size_type des_size, void *&lock_data ) const
		{
			range_buffer_type locked_range;
			lock_data = (*lock_char_range_proc)( string_token, des_size, locked_range );
			return locked_range;
		}
		void  unlock_char_range( const range_buffer_type &locked_range, void *lock_data ) const
		{
			(*unlock_char_range_proc)( string_token, lock_data, locked_range );
		}


		const this_type &assign( const range_type &range ) const
		{
			(*assign_char_range_proc)( string_token, range );
			return *this;
		}
		
		void extract_range( range_type &range ) const { (*extract_char_range_proc)( string_token, range ); }
	};


	template <typename CharType,typename TraitsType>
		void construct_char_range( const string_proxy_t<CharType,TraitsType> &str, char_range_t<CharType,TraitsType> &dst_char_range )
	{
		str.extract_range( dst_char_range );
	}
	template <typename CharType, typename TraitsType>
		CharType get_string_char_type( const string_proxy_t<CharType,TraitsType> &str );

	template <typename CharType,typename TraitsType>
		void construct_string_proxy( string_proxy_t<CharType,TraitsType> &str, string_proxy_t<CharType,TraitsType> &str_proxy )
	{
		str_proxy = str;
	}

	/*
	**
	*/

	template <typename CharType, typename TraitsType> struct base_char_range_traits
	{
		typedef CharType                                    char_type;
		typedef TraitsType                                  traits_type;
		typedef char_range_t<char_type,traits_type>         range_type;
		typedef char_range_buffer_t<char_type,traits_type>  range_buffer_type;
		typedef string_proxy_t<char_type,traits_type>       string_proxy_type;
	};
	template <std::size_t N> struct base_char_range_traits_1;

	char    get_string_char_type( const volatile char *val );
	template <> struct base_char_range_traits_1<sizeof(char)> : public base_char_range_traits<char,std::char_traits<char> > {};
	
	template <typename StringType> struct char_range_traits
	{
		static const StringType &make_string();
		BOOST_STATIC_CONSTANT( std::size_t,     value = sizeof(get_string_char_type(make_string())) );
		typedef base_char_range_traits_1<value> base_traits_type;
		
		typedef typename base_traits_type::char_type             char_type;
		typedef typename base_traits_type::traits_type           traits_type;
		typedef typename base_traits_type::range_type            range_type;
		typedef typename base_traits_type::range_buffer_type     range_buffer_type;
		typedef typename base_traits_type::string_proxy_type     string_proxy_type;
	};

	/*
	** class buffer_string_proxy_t<CharType>
	**
	**    Implements the functions needed to construct a 'string_proxy_t<CharType>' from a
	** 'char_range_buffer<CharType>'.
	**
	*/
	template <typename CharType,typename TraitsType>
		class buffer_string_proxy_t
	{
	public:
		typedef string_proxy_t<CharType,TraitsType>              string_proxy_type;
		typedef typename string_proxy_type::size_type            size_type;
		typedef typename string_proxy_type::string_token_type    string_token_type;
		typedef typename string_proxy_type::range_buffer_type    range_buffer_type;
		typedef typename string_proxy_type::range_type           range_type;
	private:
		static void      *lock_char_range_proc(   string_token_type str_token, size_type des_size, range_buffer_type &locked_range )
		{
			locked_range = *static_cast<range_buffer_type *>( str_token );
			return static_cast<void *>( str_token );
		}
		static void       unlock_char_range_proc( string_token_type str_token, void *lock_data, const range_buffer_type &locked_range )
		{
			*static_cast<range_buffer_type *>( str_token ) = locked_range;
		}
		static size_type  assign_char_range_proc( string_token_type str_token, const range_type &range )
		{
			return static_cast<range_buffer_type *>( str_token )->assign( range ).size();
		}
		static void       extract_char_range_proc( string_token_type str_token, range_type &range )
		{
			range.construct( static_cast<range_buffer_type *>( str_token )->begin()
			               , static_cast<range_buffer_type *>( str_token )->current() );
		}
	public:
		static void construct_string_proxy( range_buffer_type &str, string_proxy_type &str_proxy )
		{
			str_proxy.construct( static_cast<void *>( &str ), &lock_char_range_proc
			                   , &unlock_char_range_proc, &assign_char_range_proc, &extract_char_range_proc );
		}
	};


	template <typename CharType,typename TraitsType>
		void construct_string_proxy( char_range_buffer_t<CharType,TraitsType> &str, string_proxy_t<CharType,TraitsType> &str_proxy )
	{
		buffer_string_proxy_t<CharType,TraitsType>::construct_string_proxy( str, str_proxy );
	}
} // namespace Gatan

#include <string>   // used for 'std::basic_string'
#include <ostream>


/*
** class stl_string_proxy_t<CharType,TraitsType,Allocator>
**
**    Implements the functions needed to construct a 'string_proxy_t<CharType,TraitsType>' from a
** 'std::basic_string<CharType,TraitsType,Allocator>'.
**
*/
#if defined(BOOST_NO_ARGUMENT_DEPENDENT_LOOKUP)
namespace Gatan
#else
namespace std
#endif
{
	template <typename CharType, typename TraitsType, typename Allocator>
		CharType get_string_char_type( const std::basic_string<CharType,TraitsType,Allocator> &str );
}
namespace Gatan
{
	template <typename CharType, typename TraitsType, typename Allocator>
		void construct_char_range( const std::basic_string<CharType,TraitsType,Allocator> &str, ::Gatan::char_range_t<CharType,TraitsType> &dst_char_range )
	{
		dst_char_range.construct( str.data(), str.data() + str.size() );
	}

	template <typename CharType,typename TraitsType, typename Allocator>
		class stl_string_proxy_t
	{
	public:
		typedef CharType                                         char_type;
		typedef TraitsType                                       traits_type;
		typedef std::basic_string<CharType,TraitsType,Allocator> base_string_type;
		typedef string_proxy_t<char_type,traits_type>            string_proxy_type;
		typedef typename string_proxy_type::size_type            size_type;
		typedef typename string_proxy_type::string_token_type    string_token_type;
		typedef typename string_proxy_type::range_buffer_type    range_buffer_type;
		typedef typename string_proxy_type::range_type           range_type;
	private:
		static void      *lock_char_range_proc(   string_token_type str_token, size_type des_size, range_buffer_type &locked_range )
		{
			typename base_string_type::allocator_type a = static_cast<base_string_type *>( str_token )->get_allocator();
			char_type *lock_data = a.allocate( des_size, (void *) 0 );
			try
			{
				base_string_type *stl_string = static_cast<base_string_type *>( str_token );
				stl_string->reserve( des_size );
				size_type act_size = stl_string->copy( lock_data, des_size );
				locked_range.construct( lock_data, lock_data + act_size, lock_data + des_size );
			}
			catch (...)
			{
				a.deallocate( lock_data, des_size );
				throw;
			}
			return static_cast<void *>( lock_data );
		}
		static void       unlock_char_range_proc( string_token_type str_token, void *lock_data, const range_buffer_type &locked_range )
		{
			typename base_string_type::allocator_type a = static_cast<base_string_type *>( str_token )->get_allocator();
			static_cast<base_string_type *>( str_token )->assign( locked_range.begin(), locked_range.current() );
			a.deallocate( static_cast<char_type *>( lock_data ), locked_range.capacity() );
		}
		static size_type  assign_char_range_proc( string_token_type str_token, const range_type &range )
		{
			static_cast<base_string_type *>( str_token )->assign( range.begin(), range.end() );
			return range.size();
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

	template <typename CharType,typename TraitsType, typename Allocator>
		void construct_string_proxy( std::basic_string<CharType,TraitsType,Allocator> &str, string_proxy_t<CharType,TraitsType> &str_proxy )
	{
		stl_string_proxy_t<CharType,TraitsType,Allocator>::construct_string_proxy( str, str_proxy );
	}

	template<class E, class T>
		std::basic_ostream<E, T>& operator<<(std::basic_ostream<E, T> &os, const char_range_t<E,T> &str)
	{
		return os.write( str.begin(), str.size() );
	}
} // namespace Gatan


/*
** class stl_vector_proxy_t<CharType,TraitsType,Allocator>
**
**    Implements the functions needed to construct a 'string_proxy_t<CharType,TraitsType>' from a
** 'std::vector<CharType,Allocator>'.
**
*/

#include <vector>

#if defined(BOOST_NO_ARGUMENT_DEPENDENT_LOOKUP)
namespace Gatan
#else
namespace std
#endif
{
	template <typename CharType,typename Allocator>
		CharType get_string_char_type( const std::vector<CharType,Allocator> &str );
}
namespace Gatan
{
	template <typename CharType, typename TraitsType, typename Allocator>
		void construct_char_range( const std::vector<CharType,Allocator> &str, char_range_t<CharType,TraitsType> &dst_char_range )
	{
		const CharType *beg = ( str.size() == 0 ) ? NULL : &str[0];
		dst_char_range.construct( beg, beg + str.size() );
	}

	template <typename CharType,typename TraitsType, typename Allocator>
		class stl_vector_proxy_t
	{
	public:
		typedef CharType                                         char_type;
		typedef TraitsType                                       traits_type;
		typedef std::vector<CharType,Allocator>                  base_string_type;
		typedef string_proxy_t<char_type,traits_type>            string_proxy_type;
		typedef typename string_proxy_type::size_type            size_type;
		typedef typename string_proxy_type::string_token_type    string_token_type;
		typedef typename string_proxy_type::range_buffer_type    range_buffer_type;
		typedef typename string_proxy_type::range_type           range_type;
	private:
		static void      *lock_char_range_proc(   string_token_type str_token, size_type des_size, range_buffer_type &locked_range )
		{
			base_string_type *stl_vector = static_cast<base_string_type *>( str_token );
			size_type cur_size = stl_vector->size();
			if ( des_size >= cur_size )
			{
				stl_vector->resize( des_size );
			}
			size_type act_size = stl_vector->size();
			if ( act_size == 0 )
			{
				locked_range.construct( NULL, NULL, NULL );
			}
			else
			{
				char_type *beg = &((*stl_vector)[0]);
				locked_range.construct( beg, beg + cur_size, beg + act_size );
			}
			return static_cast<void *>( str_token );
		}
		static void       unlock_char_range_proc( string_token_type str_token, void *lock_data, const range_buffer_type &locked_range )
		{
			base_string_type *stl_vector = static_cast<base_string_type *>( str_token );
			stl_vector->resize( locked_range.size() );
		}
		static size_type  assign_char_range_proc( string_token_type str_token, const range_type &range )
		{
			static_cast<base_string_type *>( str_token )->assign( range.begin(), range.end() );
			return range.size();
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

	template <typename CharType, typename TraitsType, typename Allocator>
		void construct_string_proxy( std::vector<CharType,Allocator> &str, string_proxy_t<CharType,TraitsType> &str_proxy )
	{
		stl_vector_proxy_t<CharType,TraitsType,Allocator>::construct_string_proxy( str, str_proxy );
	}
} // namespace Gatan

#include "GatanDefines.h"
#include "GatanTypes.h"

/*
**
*/

namespace Gatan
{
	struct octet_traits
	{
        typedef octet               char_type;
        typedef int                 int_type;
        typedef std::streampos      pos_type;
        typedef std::streamoff      off_type;
        typedef uint32              state_type;
        static void assign( char_type &dst, const char_type &src )   { dst = src; }
        static bool eq( const char_type &val_0, const char_type &val_1 ) { return ( val_0 == val_1 ); }
        static bool lt( const char_type &val_0, const char_type &val_1 ) { return ( val_0 <  val_1 ); }
        static int  compare( const char_type *seq_0, const char_type *seq_1, pos_type len )
				{ return _GATAN_C_STL memcmp( seq_0, seq_1, len); }
        static pos_type length( const char_type *seq )
				{ return _GATAN_C_STL strlen( (const char *) seq ); }
        static char_type *copy( char_type *dst_seq, const char_type *src_seq, pos_type len )
				{ return (char_type *) _GATAN_C_STL memcpy(dst_seq, src_seq, len); }
        static const char_type* find( const char_type *seq, pos_type len, const char_type &val )
				{ return (const char_type *) _GATAN_C_STL memchr( seq, val, len ); }
        static char_type *move( char_type *dst_seq, const char_type *src_seq, pos_type len )
				{ return (char_type *) _GATAN_C_STL memmove( dst_seq, src_seq, len ); }
        static char_type *assign( char_type *dst_seq, pos_type len, const char_type &val )
				{ return (char_type *) _GATAN_C_STL memset( dst_seq, val, len ); }
	};
}

/*
** Specializations for 'char' and 'uncchar'
*/
namespace Gatan
{
	uncchar get_string_char_type( const volatile uncchar *val );
	template <> struct base_char_range_traits_1<sizeof(uncchar)> : public base_char_range_traits<uncchar,std::char_traits<uncchar> > {};

	typedef char_range_t<char,std::char_traits<char> >         char_range;
	typedef char_range_t<uncchar,std::char_traits<uncchar> >   uncchar_range;
	
	typedef char_range_buffer_t<char,std::char_traits<char> >        char_range_buffer;
	typedef char_range_buffer_t<uncchar,std::char_traits<uncchar> >  uncchar_range_buffer;

	typedef string_proxy_t<char,std::char_traits<char> >           char_string_proxy;
	typedef string_proxy_t<uncchar,std::char_traits<uncchar> >     uncchar_string_proxy;

	template <std::size_t Size> class char_range_buffer_static
		: public char_range_buffer
	{
	private:
		char buffer[Size+1];		// Allow extra byte at end so can blindly add null termination
	public:
		char_range_buffer_static() : char_range_buffer( &buffer[0], &buffer[Size] ) {}
	};

	template <typename CharType,typename TraitsType>
		void construct_char_range( const char_range_buffer_t<CharType,TraitsType> &str, char_range_t<CharType,TraitsType> &dst_char_range )
	{
		dst_char_range.construct( str.begin(), str.current() );
	}
	template <typename CharType, typename TraitsType>
		CharType get_string_char_type( const char_range_buffer_t<CharType,TraitsType> &str );

} // namespace Gatan

#include <cstdarg>

namespace Gatan
{
    extern int char_range_casecmp( const char_range &s1, const char_range &s2 );

	extern int char_range_buffer_vprintf( char_range_buffer &buff, const char *format, va_list var_args );
	extern int char_range_buffer_printf( char_range_buffer &buff, const char *format...);
	extern int string_proxy_vprintf( const char_string_proxy &buff, const char *format, va_list var_args );
	extern int string_proxy_printf( const char_string_proxy &buff, const char *format...);

	extern int uncchar_range_casecmp( const uncchar_range &s1, const uncchar_range &s2 );

} // namespace Gatan

#endif // __GATANSTRINGUTILITY__


