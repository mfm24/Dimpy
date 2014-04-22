
#define _GATANPLUGIN_USES_LIBRARY_VERSION 2
#include "DMPlugInLibrary.h"
#include "DMPlugInUtility.h"

namespace Gatan
{
	namespace DM
	{
		Image NewImageFromStaticPointer( const String &img_name, void *image_data_ptr, ulong img_data_size, ulong num_dim, ulong data_type, ulong pack_style, ulong dim_length_0, long dim_stride_0, ulong dim_length_1, long dim_stride_1 );
	}
}

namespace Gatan
{
	namespace PlugIn
	{
		class DMPlugInCameraLibrary
		{
		public:
			void Initialize( PlugInMain *plugin );
			void Deinitialize( PlugInMain *plugin );
		};
	}

	namespace DM
	{
		namespace CM
		{
			typedef ScriptObject CameraManager;
			typedef ScriptObject Camera;
			typedef ScriptObject CameraMode;
			typedef ScriptObject AcquisitionParameters;
			typedef ScriptObject Acquisition;
			typedef ScriptObject AcquisitionViewer;

			enum AcquisitionProcessing
			{
				  kUnprocessed = 1
				, kDarkSubtracted = 2
				, kGainNormalized = 3
				, kMaxProcessing = 0x7FFFFFFFul
			};
			
			enum ExposureMode
			{
				  kSpecifiedExposure   = 1
				, kAutoExposure        = 2
				, kOptimizedExposure   = 3
				, kMaxExposureMode     = 0x7FFFFFFFul
			};

			CameraManager GetCameraManager();
			uint32 CountCameras( const CameraManager &cam_mgr );
			Camera GetCameraByIndex( const CameraManager &cam_mgr, uint32 cam_index );
			void SelectCamera( const CameraManager &cam_mgr, const Camera &camera );
			Camera GetCurrentCamera( const CameraManager &cam_mgr );

			uint32 CountCameraModes( const CameraManager &cam_mgr, const Camera &camera );
			uint32 GetCurrentCameraModeIndex( const CameraManager &cam_mgr, const Camera &camera );
			CameraMode GetCurrentCameraMode( const CameraManager &cam_mgr, const Camera &camera );
			CameraMode GetCameraModeByIndex( const CameraManager &cam_mgr, const Camera &camera, uint32 index );
			void SetCurrentCameraModeByIndex( const CameraManager &cam_mgr, const Camera &camera, uint32 index );

			String CamMode_GetIdentifier( const CameraMode &cam_mode );
			String CamMode_GetName( const CameraMode &cam_mode );
			String CamMode_GetParameterModeName( const CameraMode &cam_mode );

			Camera GetCurrentCamera();
			AcquisitionViewer StartCameraViewer( const Camera &camera, const AcquisitionParameters &acq_params, bool save_changed_parameters, bool prepare_camera, bool open_new_window );
			void StopCurrentCameraViewer( bool close_view );

			/*
			** AcquisitionParameter functions
			*/
			void GetExposure( const AcquisitionParameters &acq_params, double *exposure_s );
			void SetExposure( const ScriptObject &acq_params, double exposure_s );
			void GetBinning( const AcquisitionParameters &acq_params, uint32 *bin_x, uint32 *bin_y );
			void SetBinning( const AcquisitionParameters &acq_params, uint32 bin_x, uint32 bin_y );
			void GetCCDReadArea( const AcquisitionParameters &acq_params, long *ccd_t, long *ccd_l, long *ccd_b, long *ccd_r );
			void SetCCDReadArea( const AcquisitionParameters &acq_params, long ccd_t, long ccd_l, long ccd_b, long ccd_r );
			void GetBinnedReadArea( const Camera &camera, const AcquisitionParameters &acq_params, long *area_t, long *area_l, long *area_b, long *area_r );
			void SetBinnedReadArea( const Camera &camera, const AcquisitionParameters &acq_params, long area_t, long area_l, long area_b, long area_r );
			void GetProcessing( const AcquisitionParameters &acq_params, AcquisitionProcessing *processing_out );
			void SetProcessing( const AcquisitionParameters &acq_params, AcquisitionProcessing processing );
			void GetCorrections( const AcquisitionParameters &acq_params, uint32 corr_mask, uint32 *corr );
			void SetCorrections( const AcquisitionParameters &acq_params, uint32 corr_mask, uint32 corr );
			void GetAcqTranspose( const AcquisitionParameters &acq_params, ImageData::Transform2D *transpose );
			void SetAcqTranspose( const AcquisitionParameters &acq_params, ImageData::Transform2D transpose );
			void GetReadMode( const AcquisitionParameters &acq_params, uint32 *read_mode );
			void SetReadMode( const AcquisitionParameters &acq_params, uint32 read_mode );
			void GetShutterExposure( const AcquisitionParameters &acq_params, bool *shut_exp );
			void SetShutterExposure( const AcquisitionParameters &acq_params, bool shut_exp );
			void GetDoContinuousReadout( const AcquisitionParameters &acq_params, bool *do_continuous_readout );
			void SetDoContinuousReadout( const AcquisitionParameters &acq_params, bool do_continuous_readout );
			void GetQualityLevel( const AcquisitionParameters &acq_params, uint32 *quality );
			void SetQualityLevel( const AcquisitionParameters &acq_params, uint32 quality );
			void GetExposureMode( const Camera &camera, const AcquisitionParameters &acq_params, ExposureMode *exposure_mode );
			void SetExposureMode( const Camera &camera, const AcquisitionParameters &acq_params, ExposureMode exposure_mode );
			void GetShutterIndex( const AcquisitionParameters &acq_params, uint32 *idx );
			void SetShutterIndex( const AcquisitionParameters &acq_params, uint32 idx );
			void GetDoAntiblooming( const AcquisitionParameters &acq_params, bool *do_antiblooming );
			void SetDoAntiblooming( const AcquisitionParameters &acq_params, bool do_antiblooming );
			void GetSettling( const AcquisitionParameters &acq_params, double *settling_s );
			void SetSettling( const AcquisitionParameters &acq_params, double settling_s );
			void GetTotalTranspose( const Camera &camera, const AcquisitionParameters &acq_params, ImageData::Transform2D *transpose );
			void SetTotalTranspose( const Camera &camera, const AcquisitionParameters &acq_params, ImageData::Transform2D transpose );

			/*
			** Camera functions
			*/
			String GetCameraName( const Camera &camera );
			void   SetCameraName( const Camera &camera, const String &name );
			String GetCameraControllerClass( const Camera &camera );

			ImageData::Transform2D Config_GetDefaultTranspose( const Camera &camera );
			void   Config_SetDefaultTranspose( const Camera &camera, ImageData::Transform2D transpose );
			String Config_GetLocationName( const Camera &camera );

			void CCD_GetSize( const Camera &camera, uint32 *ccd_width, uint32 *ccd_height );
			void CCD_GetPixelSize_um( const Camera &camera, uint32 *x_size_um, uint32 *y_size_um );

			bool CanDoOnlineDarkAcquisition( const Camera &camera );
			bool CanSetAntiblooming( const Camera &camera );

			bool IsCameraRetractable( const Camera &camera );
			bool GetCameraInserted( const Camera &camera );
			void SetCameraInserted( const Camera &camera, bool inserted );

			uint32 CountShutters( const Camera &camera );
			uint32 GetDefaultShutterIndex( const Camera &camera );
			void   SetCurrentShutterState( const Camera &camera, uint32 shut_idx, bool is_closed );

			uint32 CountQualityLevels( const Camera &camera, const AcquisitionParameters &acq_params );
			uint32 GetNamedQualityLevel( const Camera &camera, const String &qual_name );

			bool CanOptimizeExposure( const Camera &camera, const AcquisitionParameters &acq_params );

			AcquisitionParameters GetCameraAcquisitionParameterSet_HighQualityImagingAcquire( const Camera &argument_1 );
			AcquisitionParameters GetCameraAcquisitionParameterSet( const Camera &camera, const String &mode_name, const String &style_name, const String &set_name, bool create );
			void SaveCameraAcquisitionParameterSet( const Camera &camera, const AcquisitionParameters &acq_params );

			AcquisitionParameters CreateAcquisitionParameters( const Camera &camera, AcquisitionProcessing processing, double exposure, uint32 bin_x, uint32 bin_y, uint32 ccd_t, uint32 ccd_l, uint32 ccd_b, uint32 ccd_r );
			AcquisitionParameters CreateAcquisitionParameters_FullCCD( const Camera &camera, AcquisitionProcessing processing, double exposure, uint32 bin_x, uint32 bin_y );

			bool Validate_AcquisitionParameters( const Camera &camera, const AcquisitionParameters &acq_params );
			bool IsValid_AcquisitionParameters( const Camera &camera, const AcquisitionParameters &acq_params );
			bool Check_ReadoutParameter_Binning( const Camera &camera, const AcquisitionParameters &acq_params, bool validate, bool *was_changed, uint32 *bin_x, uint32 *bin_y );

			void  CameraCalcImageForm( const Camera &camera, const AcquisitionParameters &acq_params, uint32 *data_type, uint32 *width, uint32 *height );
			Image CreateImageForAcquire( const Camera &camera, const AcquisitionParameters &acq_params, const String &name );

			Image GetDarkReference( const Camera &camera, const AcquisitionParameters &acq_params );

			Image AcquireImage( const Camera &camera, const AcquisitionParameters &acq_params );
			void  AcquireImage( const Camera &camera, const AcquisitionParameters &acq_params, const Image &img );
			void  AcquireDarkReference( const Camera &camera, const AcquisitionParameters &acq_params, const Image &img );

			Acquisition CreateAcquisition( const Camera &camera, const AcquisitionParameters &acq_params );

			void ACQ_StartAcquire( const Acquisition &acq );
			void ACQ_ChangeAcquire( const Acquisition &acq, const AcquisitionParameters &new_acq_params );
			void ACQ_StopAcquire( const Acquisition &acq );
			void DoAcquire_LL( const Acquisition &acq, const ScriptObject &acq_lstnr, const Image &img, const ScriptObject &frame_info );
		}
	}
}

