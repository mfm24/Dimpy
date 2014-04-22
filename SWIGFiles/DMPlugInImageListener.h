#ifndef __IMAGELISTENER__
#define __IMAGELISTENER__

//
// The image listener class. Just pass in the image to the constructor and override the desired methods.
//

namespace Gatan { namespace PlugIn
{
	class ImageListener : public Gatan::std_base_class_ref_count<ImageListener>
	{
	public:
		ImageListener( const Gatan::DM::Image &img );
		virtual ~ImageListener();
			// Attach this listener to the given image. Destruction will take place either by explicitly
			// deleting this listener or implicitly after the Destruct method is invoked.

		virtual void Destruct( const Gatan::DM::Image &image );
			// This method gets invoked just before the image that this listener is attached to is destructed.
			// This object will be automatically deleted after this call (so don't delete the object yourself).
	
		virtual bool GetComments( const Gatan::DM::Image &image, Gatan::DM::String &str1, Gatan::DM::String &str2 );
			// Retrieve comments about this image. Return true to indicate the comments have been filled in.

		virtual bool Key( const Gatan::DM::Image &image, long k, long m );
			// Receive a key event from the image. Return true to indicate that the key event has been handled.
	
		virtual void Idle( const Gatan::DM::Image &image );
			// Receive an idle event from the image.
	
		virtual bool IsInvalidWithRespectTo( const Gatan::DM::Image &image, const Gatan::DM::Image &testImage );
			// This method allows implementation of the application-wide mechanism for making sure that
			// all dependent images are updated properly before changing the data of the master images. For instance,
			// during acquisition, an FFT attached to the acquisition image should be complete before another
			// acquisition takes place.
	
		virtual void Stop( const Gatan::DM::Image &image, bool immediate );
			// Override this method to receive "stop" messages. This is a application-wide mechanism
			// for stopping attached daemons. Plug-ins can call "DMAbortAllAcquisitionDaemons" and this method
			// will eventually be invoked for images with attached listeners. It does NOT intercept
			// calls to DMAbortAcquisitionDaemon( DM_ImageToken )

		void DetachFromImage( const Gatan::DM::Image &img );
		void AttachToImage( const Gatan::DM::Image &img );

	private:
		static bool HandleListenerMessage( long listener, long object, long refCon, long message, void *data, long dataLen );

		bool Message( long listener, long object, long message, void *data, long dataLen );

		long theListener;
		long theObject;

		enum
		{
			kImageListenerClass = 100,
		
			kImageListener_Destruct,
			kImageListener_GetComments,
			kImageListener_Key,
			kImageListener_Idle,
			kImageListener_Stop,
			kImageListener_IsInvalidWithRespectTo
		};
		struct DestructParameters
		{
			DM_ImageToken image;
		};

		struct GetCommentsParameters
		{
			DM_ImageToken image;
			char *str1;
			long str1Length;
			char *str2;
			long str2Length;
		};

		struct KeyParameters
		{
			DM_ImageToken image;
			long k;
			long m;
		};

		struct IdleParameters
		{
			DM_ImageToken image;
		};

		struct StopParameters
		{
			DM_ImageToken image;
			bool immediate;
		};

		struct IsInvalidWithRespectToParameters
		{
			DM_ImageToken image;
			DM_ImageToken testImage;
		};
	};
} } // namespace Gatan::PlugIn

#endif // __IMAGELISTENER__

