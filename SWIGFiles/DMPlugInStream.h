
#ifndef __DM_PLUGIN_STREAM__
#define __DM_PLUGIN_STREAM__

#define _GATANPLUGIN_USES_LIBRARY_VERSION 2
#include "DMPlugInLibrary.h"
#include "DMPlugInLibraryDefs.h"
#include "DMPluginUtility.h"

namespace Gatan
{
	namespace DM
	{
		void   StreamWrite( const ScriptObject &stream, void *data, uint32 length );
		void   StreamRead( const ScriptObject &stream, void *data, uint32 length );
		ulong  StreamGetPos( const ScriptObject &stream );
		void   StreamSetPos( const ScriptObject &stream, ulong base, long offset );
		uint32 StreamGetSize( const ScriptObject &stream );
		void   StreamSetSize( const ScriptObject &stream, uint32 size );

		ScriptObject NewStreamFromBuffer( const ScriptObject &buffer );
		bool TagGroupLoadFromStream( const TagGroup &tagGroup, const ScriptObject &stream );
		void TagGroupSaveToStream( const TagGroup &tagGroup, const ScriptObject &stream );
	}
}

namespace Gatan
{
	namespace PlugIn
	{
		class DMPlugInStreamUtility
		{
		public:
			void Initialize( PlugInMain *plugin );
			void Deinitialize( PlugInMain *plugin );
		};
	}
}

#endif // __DM_PLUGIN_STREAM__
