#ifndef __PLUGINMENU__
#define __PLUGINMENU__

//
// Changes needed for second version:
//
// 1 - plug-ins should not "register" or "unregister" menu anymore.
// 2 - the Adjust() function should not have a (void) argument list.
// 3 - DoMenuAction now should return a bool
// 4 - plug-ins should prefer the AddAction() and AddBar() methods
// 5 - menu constructor no longer takes a count.
// 6 - StaticPlugInMenu class has been renamed to PlugInMenu 
//

#include <vector>

//
// The plugin menu manager class keeps track of a list of menus. Since we implemented
// the custom menu stuff on the Mac in such a way as to allow us to register only a single
// menu handler component per plug-in, we use the plug-in menu manager to manage dispatching
// to multiple "pluginmenu" objects.
//

namespace Gatan { namespace PlugIn
{
	class ActionSpec
	{
	public:
		typedef long   id_type;
		typedef long   index_type;
	public:
		ActionSpec( id_type action, index_type index = 0 ) : action( action ), index( index ) { }
	
		bool operator==( const ActionSpec &as ) const { return ( action == as.action ) && ( index == as.index ); }

		id_type     action;
		index_type  index;
	};

	class PlugInMenuEntry
	{
	public:
		PlugInMenuEntry();
	
		Gatan::DM::String fMenu;
		Gatan::DM::String fSubMenu;

		//
		// These two fields determine the item's text (or bar)
		//

		bool fIsBar;
		Gatan::DM::String fName;

		//
		// These fields determine the appearance of the menu item.
		//

		bool  fEnabled;
		bool  fChecked;
		Gatan::uint8 fStyle;
		Gatan::uint8 fIconIndex;
		long  fAccessPos;
	
		char  fCmdKeyEquivalent;

		// This is the command.
	
		ActionSpec fAction;
	};

	class PlugInMenu
	{
	public:
		typedef unsigned long          index_type;
		typedef ActionSpec::id_type    CommandID;
		typedef ActionSpec::index_type CommandIndex;
	public:
		PlugInMenu();
		~PlugInMenu();

		virtual void Adjust();
			// Override this method to "adjust" your menu items.

		virtual index_type CountItems() const = 0;

		virtual bool DoMenuAction( CommandID action, CommandIndex index ) = 0;
			// Override this method to carry out your actions.

		virtual void GetMenuItemEntry( index_type itemIndex, PlugInMenuEntry &menuEntry, CommandID &cmdNumber, CommandIndex &cmdIndex ) const = 0;

	};

	class StandardPlugInMenu : public PlugInMenu
	{
	public:

		StandardPlugInMenu( const Gatan::DM::String &title );
		StandardPlugInMenu( const Gatan::DM::String &title, const Gatan::DM::String &subMenu );
		~StandardPlugInMenu();

		virtual index_type CountItems() const;

		virtual void GetMenuItemEntry( index_type itemIndex, PlugInMenuEntry &menuEntry, CommandID &cmdNumber, CommandIndex &cmdIndex ) const;

		void SetAction( index_type menuItem, const ActionSpec &action );
		void SetAction( index_type menuItem, CommandID action, CommandIndex index ) { SetAction( menuItem, ActionSpec( action, index ) ); }
		void SetBar( index_type menuItem, const Gatan::DM::String &subMenu );
	
		void AddAction( const ActionSpec &action );
		void AddAction( CommandID action, CommandIndex index ) { AddAction( ActionSpec( action, index ) ); }
		void AddBar();
		void AddBar( const Gatan::DM::String &subMenu );

		void RemoveAction( const ActionSpec &action );
	
		void SetChecked( const ActionSpec &action, bool checked );
		void SetKeyEquivalent( const ActionSpec &action, char c );
		void SetEnabled( const ActionSpec &action, bool enabled );
		void SetName( const ActionSpec &action, const Gatan::DM::String &name );
		void SetSubMenu( const ActionSpec &action, const Gatan::DM::String &subMenu );
		void SetAccessPos( const ActionSpec &action, long pos );

	private:

		typedef std::vector<PlugInMenuEntry> PlugInMenuEntryVector;

		PlugInMenuEntryVector fPlugInMenuEntryVector;
	
		Gatan::DM::String fTitle;
		Gatan::DM::String fSubMenu;
	
		PlugInMenuEntryVector::iterator ActionToMenuItem( const ActionSpec &action );

	};

	typedef StandardPlugInMenu StaticPlugInMenu;

} } // namespace Gatan::PlugIn

#endif

