#ifndef __PIF_UTILITY__
#define __PIF_UTILITY__

#include <ostream>
#include <vector>
#include <string>

#include "GatanDefines.h"
#include "GatanFoundationBase.h"
#include "GatanPoint.h"
#include "GatanRect.h"
#include "GatanTypes.h"
#include "GatanStringUtility.h"
#include "GatanRefPointer.h"
#include "GatanInterface.h"
#include "GatanSynchronization.h"

#include "DMPluginLibraryDefs.h"
#include "DMPlugInStubs.h"

#include "DMPlugInImageUtility.h"

namespace Gatan
{
	namespace PlugIn
	{
	}

	inline void Throw( const char *string )   { Gatan::ThrowString( string ); }
}
namespace GatanPlugIn = Gatan::PlugIn;

namespace Gatan { namespace PlugIn
{
	extern std::ostream gResultOut;

	struct ObjectRect
	{
		float top;
		float left;
		float bottom;
		float right;
	};

	struct ObjectPoint
	{
		float x;
		float y;
	};

	struct DaemonMessage
	{
		long	message;
		long	extra;
	};

	enum CalibrationFormat
	{
		  e_CalibrationFormat_CO_CS    = 0x0000   // Calibrated origin, calibrated scale    ( origin:units, scale:units/pixel )
		, e_CalibrationFormat_UO_CS    = 0x0001   // Uncalibrated origin, calibrated scale  ( origin:pixels, scale:units/pixel )
		, e_CalibrationFormat_CO_US    = 0x0100   //                                        ( origin:units, scale:pixles/unit )
		, e_CalibrationFormat_UO_US    = 0x0101   //                                        ( origin:pixels, scale: pixels/unit )
	};

		//mfm 29Sep08 - removed to see if it helps:
	//we don't use std::exception anyway!
	//extern void DMScript_HandleException( Gatan::PlugIn::DM_Env *dm_env, const std::exception &ex );
	extern void DMScript_HandleException( Gatan::PlugIn::DM_Env *dm_env );

} } // namespace Gatan::PlugIn

//
// Support for plug-in entry and exit (no exceptions allowed to pass).
//

#define PLUG_IN_ENTRY_ENV( DM_ENV ) \
	{\
		::Gatan::PlugIn::DM_Env *_dm_env = DM_ENV;\
		::Gatan::OS::PlugInEntry _plugin_entry( _dm_env );\
		try \
		{\

#define PLUG_IN_ENTRY \
	{\
		::Gatan::PlugIn::DM_Env *_dm_env = NULL;\
		::Gatan::OS::PlugInEntry _plugin_entry( _dm_env );\
		try \
		{\

//mfm changed this too:
#define PLUG_IN_EXIT \
		} \
		catch( const std::exception &ex ) \
		{\
			::Gatan::PlugIn::DMScript_HandleException( _dm_env);\
		}\
		catch(...)\
		{\
			::Gatan::PlugIn::DMScript_HandleException( _dm_env);\
		}\
	}\
/*was:
#define PLUG_IN_EXIT \
		} \
		catch( const std::exception &ex ) \
		{\
			::Gatan::PlugIn::DMScript_HandleException( _dm_env, ex );\
		}\
		catch(...)\
		{\
			::Gatan::PlugIn::DMScript_HandleException( _dm_env, *NULL );\
		}\
	}\
*/

//
// Support for the object model.
//

/*
** Upon entry to every function in the plugin, 'OS::PlugInEntry' saves state
**
*/

#ifdef _GATAN_OS_MACOS
namespace Gatan
{
	namespace Macintosh
	{
		class PlugInEntry
		{
		private:
			enum
			{
				  state_buff_size = 32
			};

			octet state_buff[state_buff_size];
		public:
			PlugInEntry( ::Gatan::PlugIn::DM_Env *dm_env );

			~PlugInEntry();
		};

		class PlugInMain
		{
		};
	}
}
#endif // _GATAN_OS_MACOS

#ifdef _GATAN_OS_WIN32
namespace Gatan
{
	namespace Win32
	{
		class PlugInEntry
		{
		private:
			enum
			{
				  state_buff_size = 32
			};

			octet state_buff[state_buff_size];	// Curently, need only be large enough to hold 'AFX_MAINTAIN_STATE2'
		public:
			PlugInEntry( ::Gatan::PlugIn::DM_Env *dm_env );

			~PlugInEntry();
		};

		class PlugInMain
		{
		public:
			static void *GetPlugInOSHandle_();

			static void   Init( void *hModule );
			static void   Exit();
			static inline HMODULE GetPlugInOSHandle()               { return (HMODULE) GetPlugInOSHandle_(); }
		};
	}
}
#endif // _GATAN_OS_WIN32

namespace Gatan { namespace PlugIn
{
	using namespace Gatan;

	class PlugInLibrary
	{
	public:
		PlugInLibrary();
		~PlugInLibrary();
	};

	struct ImageDataLock;

	struct DigitalMicrographCallbacks
	{
		void (*write_to_results)( const char *s, ulong l );
		void (*show_alert)( const char *message, ulong alertStyle );

		long (*register_menu_manager)();
		void (*unregister_menu_manager)( long token );
		
		long (*register_tool)( void *tool, const char *icon );
		void (*unregister_tool)( long token );
		
		bool  (*lock_image_data)( DM_ImageToken image, uint32 lock_flags, ImageDataLock &lock );
		void  (*get_image_data)( DM_ImageToken image, ImageDataLock &lock, ImageData::image_data_t &image_data );
		void  (*unlock_image_data)( DM_ImageToken image, ImageDataLock &lock, bool has_data_changed );
	};
	
	class PlugInMain : public Gatan::OS::PlugInMain
	{
	private:
		DigitalMicrographInterface fDMPlugInInterface;
		PlugInLibrary              fPlugInLibrary;
		std::vector<DM::Function>  fInstalledFunctions;

		DMPlugInImageUtility       fImageUtility;
	public:
		PlugInMain();
		virtual ~PlugInMain();

		        void DoStart();
		        void DoRun();
		        void DoCleanup();
		        void DoEnd();

		virtual void Start();
		virtual void Run();
		virtual void Cleanup();
		virtual void End();
		virtual void AboutDialog();
		
		void Initialize();
		void Uninitialize();
		
		DM_Interface *GetDMInterface() { return fDMPlugInInterface.GetInterface(); }
		DM::Function AddFunction( unsigned long module, const char *signature, unsigned long linkage, void *proc );
		void         RemoveFunction( const DM::Function &func );
		void         RemoveAllFunctions();

		void   AddFunction( const char *signature, void *proc );

		static PlugInMain *GetPlugIn();
		
		static DigitalMicrographCallbacks &GetCallbacks();
	private:
		static PlugInMain *gPlugIn;
	};

} } // namespace Gatan::PlugIn


#endif //  __PIF_UTILITY__

