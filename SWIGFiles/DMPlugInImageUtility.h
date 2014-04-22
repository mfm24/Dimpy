//
// Image utility functions.
//

#ifndef __IMAGEUTILITY__
#define __IMAGEUTILITY__

#include <vector>

namespace Gatan
{
	namespace ImageData
	{
		enum
		{
			  NULL_DATA                  =  0
			, SIGNED_INT16_DATA          =  1
			, REAL4_DATA                 =  2
			, COMPLEX8_DATA              =  3
			, OBSELETE_DATA              =  4
			, PACKED_DATA                =  5
			, UNSIGNED_INT8_DATA         =  6
			, SIGNED_INT32_DATA          =  7
			, RGB_DATA                   =  8
			, SIGNED_INT8_DATA           =  9
			, UNSIGNED_INT16_DATA        = 10
			, UNSIGNED_INT32_DATA        = 11
			, REAL8_DATA                 = 12
			, COMPLEX16_DATA             = 13
			, BINARY_DATA                = 14
		};

		// Diagonal flip is done after horizontal and vertical
		enum Transform2D
		{
			  trans_NONE            = 0x0000
			, trans_FLIP_HORIZONTAL = 0x0001
			, trans_FLIP_VERTICAL   = 0x0002
			, trans_FLIP_DIAGONAL   = 0x0100

			, trans_ROTATE_RIGHT    = 0x0102 // flip second, swap
			, trans_ROTATE_LEFT     = 0x0101 // flip first, swap
		};

		Transform2D transform2d_invert( Transform2D trans );
		Transform2D transform2d_compose( Transform2D trans_0, Transform2D trans_1 );

		struct image_data_t
		{
		public:
			struct dim_desc_type { ulong length; long stride; };
			
			enum
			{
				  max_dim = 5
			};
		private:
			octet *data;
			ulong  num_dim;
			ulong  data_type;
			dim_desc_type dim[max_dim];
		public:
			image_data_t() : data( NULL ), num_dim( 0 ), data_type( 0 ) {}
			image_data_t( ulong des_num_dim, const image_data_t &src_data )
				{ assign( des_num_dim, src_data ); }
	
			void assign( ulong des_num_dim, const image_data_t &src_data );

			inline octet *get_data() const { return data; }
			inline void   set_data( octet *data_ ) { data = data_; }

			inline void  set_num_dim( ulong num_dim_ )     { num_dim = num_dim_; }
			inline ulong get_num_dim() const               { return num_dim; }

			inline void  set_data_type( ulong data_type_ ) { data_type = data_type_; }
			inline ulong get_data_type() const             { return data_type; }

			inline ulong get_dim_length( ulong i ) const   { return ( i < num_dim ) ? dim[i].length : 1; }
			inline  long get_dim_stride( ulong i ) const   { return ( i < num_dim ) ? dim[i].stride : 0; }
			inline  long get_dim_size( ulong i_dim ) const { return ( i_dim < num_dim ) ? ( dim[i_dim].length * dim[i_dim].stride ) : 0; }
			inline  long get_dim_pad( ulong i ) const      { return get_dim_stride(i) - ( ( i == 0 ) ? 0 : get_dim_size(i-1) ); }

			inline  void set_dim_length( ulong i_dim, ulong length ) { dim[i_dim].length = length; }
			inline  void set_dim_stride( ulong i_dim,  long stride ) { dim[i_dim].stride = stride; }
			inline  void set_dim_data( ulong i_dim, ulong length, long stride ) { dim[i_dim].length = length; dim[i_dim].stride = stride; }

			void flip_dim( ulong i_dim );
			void swap_dim( ulong i_dim1, ulong i_dim2 );

			void transform_2d( Transform2D transform );
			void untransform_2d( Transform2D transform );

			ulong calc_contig_level() const;

			void extend_dimensions_to( ulong new_num_dim, image_data_t &dst_data ) const;
		};
	}
}

namespace Gatan
{
	namespace DM
	{
		ulong ImageConstructDataType( const String &data_class, const String &scalar_class, ulong variant, ulong bit_size );
		bool  ImageDeconstructDataType( ulong image_data_type, String &data_class, String &scalar_class, ulong *variant, ulong *scalar_bit_size );

		ulong ImageDataTypeGetByteSize( ulong image_data_type );
		Image NewImageDataSourceImage( const String &img_name, const ScriptObject &img_data_src, ulong img_data_src_index, const ScriptObject &img_slice, bool is_utility );

		void ImageChangeDataType( const Image &img, uint32 dataType );

		ScriptObject ImageGetLockedData( const Image &im, ulong lock_flags );
		ScriptObject ImageGetLockedData( const Image &im, ulong lock_flags, const ScriptObject &data_slice, ulong slice_dim );
		void  ImageDataChanged( const Image &argument_1, const ScriptObject &locked_data, const ScriptObject &changed_slice );

		Image NewUtilityImage( const String &name, ulong num_dim, ulong data_type, ulong pack_style... );
		
		struct PluginMemoryBuffer : public Gatan::std_base_class_ref_count<PluginMemoryBuffer>
		{
			typedef uint size_type;

			virtual ~PluginMemoryBuffer();

			virtual void *LockData( size_type *size, void **lock_data ) = 0;
			virtual void UnlockData( void *lock_data ) = 0;
		};

		ScriptObject NewImageDataSource_Buffer( const ScriptObject &buffer, const String &lock_method_name, const String &unlock_method_name, ulong slice_dim, ulong num_dim, ulong data_type, ulong pack_style... );
		ScriptObject NewImageDataSource_StaticPointer( void *image_data_ptr, ulong image_data_size, ulong slice_dim, ulong num_dim, ulong data_type, ulong pack_style... );
		ScriptObject NewImageDataSource_Buffer_A( const ScriptObject &buffer, const String &lock_method_name, const String &unlock_method_name, ulong slice_dim, ulong num_dim, ulong img_data_type, ulong pack_style, const ImageData::image_data_t::dim_desc_type *dim_descs );
		ScriptObject NewImageDataSource_Buffer_A( const ref_ptr<PluginMemoryBuffer> &mem_buff, ulong slice_dim, ulong num_dim, ulong img_data_type, ulong pack_style, const ImageData::image_data_t::dim_desc_type *dim_descs );

		ScriptObject NewMemoryBuffer( ulong initial_size );
		ScriptObject NewMemoryBuffer_StaticPointer( void *buffer, ulong size );

		ScriptObject NewImageDataSize( ulong des_num_dim... );
		ScriptObject NewImageDataSliceFromRect( const ScriptObject &image_data_size, long top, long left, long bottom, long right );
		ScriptObject NewImageDataSliceFromSize( const ScriptObject &image_data_size );
		ScriptObject NewImageDataSlice( uint32 des_start_num_dim, uint32 des_num_dim... );
		ScriptObject TransposeImageDataSlice( const ScriptObject &image_data_slice, ulong transpose_desc, bool do_inverse );
		ScriptObject TransposeImageDataSize( const ScriptObject &image_data_slice, ulong transpose_desc, bool do_inverse );

		class LockableMemory
		{
		private:
			ScriptObject          fObject;
			std::vector<Function> fMethods;
		public:
			LockableMemory( const ScriptObject &o );
			void UnlockMemory( void *lock_data );
			void *LockMemory( uint32 *size, void **lock_data );
		};
	}
}

namespace Gatan
{
	namespace PlugIn
	{
		class PlugInMain;

		class DMPlugInImageUtility
		{
		public:
			void Initialize( PlugInMain *plugin );
			void Deinitialize( PlugInMain *plugin );
		};

		struct ImageDataLock
		{
			ulong  v_ulong;
			void  *v_ptr;
		};


		class ImageDataLocker
		{
		public:
			enum LockDataFlags
			{
			  lock_data_NONE                         = 0x00000000
			, lock_data_CONTIGUOUS                   = 0x00000001		// Entire data set must be contiguous
			, lock_data_CONTIGUITY_LEVEL             = 0x0000000E		// If '0x01' bit not set, required contiguous dimensions
			, lock_data_CONTIGUITY_MASK              = 0x0000000F		// 

			, lock_data_DONT_MODIFY_LOCKEDDATA       = 0x00000010
			, lock_data_DONT_UNPACK_DATA             = 0x00000020
			, lock_data_LOCK_AS_RAW_DATA             = 0x00000020

			, lock_data_NOT_IN                       = 0x00000100		// Don't write temporary data back into original
			, lock_data_NOT_OUT                      = 0x00000200		// Don't initialize temporary data from original 
			, lock_data_WONT_READ                    = 0x00000400		// Locked data won't be read
			, lock_data_WONT_WRITE                   = 0x00000800		// Locked data won't be written

			, lock_data_LOCK_AS_CONTIGUOUS_RAW_DATA  = 0x00000021
			};
		public:
			ImageDataLocker( uint32 lock_flags = lock_data_CONTIGUOUS )
				: fImage( )
				, fLockFlags( lock_flags )
				, fIsDataLocked( false )
				, fHasDataChanged( false )
			{}

			ImageDataLocker( const DM::Image &image_, uint32 lock_flags = lock_data_CONTIGUOUS )
				: fImage()
				, fLockFlags( lock_flags )
				, fIsDataLocked( false )
				, fHasDataChanged( false )
			{ lock( image_ ); }

			ImageDataLocker( const DM::Image &image_, uint32 lock_flags, const Gatan::LongRect &sub_area )
				: fImage()
				, fLockFlags( lock_flags )
				, fIsDataLocked( false )
				, fHasDataChanged( false )
			{
				lock( image_, &sub_area );
			}

			~ImageDataLocker()
			{
				unlock();
			}

			ImageDataLocker &operator=( const DM::Image &new_image )
			{
				lock( new_image );
				return *this;
			}

			void lock( const DM::Image &image );
			void lock( const DM::Image &image, ulong slice_dim, ulong slice );
			void lock( const DM::Image &image, const Gatan::LongRect *sub_area );
			void unlock();

			void *get() const { return (void *) fData.get_data(); }
			const ImageData::image_data_t &get_image_data() const { return fData; }
			void GetImageData( ulong num_dim, ImageData::image_data_t &data ) const;
			void GetImageData( ulong num_dim, ulong slice, ImageData::image_data_t &data ) const;

			void SetLockFlags( uint32 new_lock_flags )
			{
				fLockFlags = new_lock_flags;
			}

			void MarkDataChanged();
		private:
			ImageData::image_data_t    fData;
			DM::Image                  fImage;
			uint32                     fLockFlags;
			ImageDataLock              fLockData;
			bool                       fIsDataLocked;
			bool                       fHasDataChanged;
		};


		DM::Image ConvertRGBToUInt8( const DM::Image &img );
			// Converts the given RGB image to unsigned single byte integer image.

		void ConvertRGBToUInt8( const DM::Image &img, const DM::Image &dst );
			// Converts the given RGB image to unsigned single byte integer image.

		bool IsGrayScaleRGB( const DM::Image &image );
			// Determines whether the given RGB image is a grayscale image or not.

	} // namespace PlugIn

} // namespace Gatan

#endif __IMAGEUTILITY__

