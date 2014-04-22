#ifndef __PLUGINTOOL__
#define __PLUGINTOOL__


//
// Multiple tools can exist. 
// Allocate new tools with the new operator. They are de-allocated
// by the plugin itself in UnregisterPlugInTool.
// Each PluginTool should be deleted explicitly in the code of the plugin.
//

namespace Gatan { namespace PlugIn
{
	class PlugInTool
	{
	public:
		typedef long ToolToken;
		enum { STATE_MOUSEUP, STATE_MOUSEDOWN, STATE_MOUSERISING, STATE_MOUSEFALLING };
	private:
		ToolToken fToolToken;
	public:

		PlugInTool( const char *customIcon );
		virtual	~PlugInTool();

		virtual void DoState( long imageID, const Gatan::LongPoint &where, long state );

		virtual void Select( void );

		virtual void Deselect( void );
	
		void Close();
	};
} } // namespace Gatan::PlugIn

#endif
