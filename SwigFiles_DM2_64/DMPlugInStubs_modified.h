

#ifndef _GATAN_PLUGIN_DIGITALMICROGRAPH_FUNCTIONS
#define _GATAN_PLUGIN_DIGITALMICROGRAPH_FUNCTIONS

class CDialog;
class CWnd;
namespace Gatan
{
	namespace DM
	{

		class Image;
		class ROI;
		class Component;
		class ImageDisplay;
		class LinePlotImageDisplay;
		class RasterImageDisplay;
		class SurfacePlotImageDisplay;
		class ImageDocument;
		class TagGroup;
		class Window;
		class ScriptObject;
		class String;
		class Throwable;
		class Function;
		class DecoratedWindow;

enum MaximalWindowRectOptions
{
	  max_win_rect_NONE		          = 0x00000000
	, max_win_rect_INSIDE_APPLICATION = 0x00000001
	, max_win_rect_EXCLUDE_FRAME      = 0x00000002
	, max_win_rect_EXCLUDE_DOCKED_FLOATING_WINDOWS_LEFT   = 0x00000010
	, max_win_rect_EXCLUDE_DOCKED_FLOATING_WINDOWS_RIGHT  = 0x00000020
	, max_win_rect_EXCLUDE_DOCKED_FLOATING_WINDOWS_TOP    = 0x00000040
	, max_win_rect_EXCLUDE_DOCKED_FLOATING_WINDOWS_BOTTOM = 0x00000080
	, max_win_rect_EXCLUDE_DOCKED_FLOATING_WINDOWS        = 0x000000F0
};

namespace DatabarElementType
{
enum Databar_DataType
{
	TypeNone,
	TypeULL,     // unsigned long long
	TypeLL,      // long long
	TypeUL,      // unsigned long
	TypeL,       // long
	TypeF,       // float
	TypeD,       // double
	TypeChar	 // null terminated char
};
}


%feature("docstring") AbortAcquisitionDaemon 
"AbortAcquisitionDaemon: Abort all acquisition daemons associated with the image.";
void AbortAcquisitionDaemon( const Image &argument_1 );

%feature("docstring") AbortAllAcquisitionDaemons 
"AbortAllAcquisitionDaemons: Abort all acquisition daemons with any image within the 
application.";
void AbortAllAcquisitionDaemons( );

%feature("docstring") AddCustomTool 
"AddCustomTool: Add the tool to the custom tool list. See the SDK documentation for more 
information.";
void AddCustomTool( const char *icon, long toolInstance );

%feature("docstring") AddFunction 
"AddFunction: Uses the prototype string to define a function for use in the script 
language.";
void AddFunction( const char *prototype, void *function );

%feature("docstring") AddPathToCopyToImageList 
"AddPathToCopyToImageList: Adds 'path' to the list of tags to transfer to acquired images.";
void AddPathToCopyToImageList( const char *path );

%feature("docstring") AddScriptFileToMenu 
"AddScriptFileToMenu: Install the script in the file indicated by fileName into the 
application. The commandName indicates the string by which this script will be known to 
the application. If the script is to be installed in the menu, the menuName and 
optionalSubMenuName parameters specify the menu. Pass 1 for isLibrary if the script is a 
library only and 0 to install it in the menu.";
void AddScriptFileToMenu( const char *fileName, const char *commandName, const char *menuName, const char *optionalSubMenuName, bool isLibrary );

%feature("docstring") AddScriptFileToPackage 
"AddScriptFileToPackage: Install the script in the file indicated by fileName into the 
package. The commandName indicates the string by which this script will be known to the 
application. If the script is to be installed in the menu, the menuName and 
optionalSubMenuName parameters specify the menu. Pass 1 for isLibrary if the script is a 
library only and 0 to install it in the menu.";
void AddScriptFileToPackage( const char *fileName, const char *packageName, long packageLevel, const char *commandName, const char *menuName, const char *optionalSubMenuName, bool isLibrary );

%feature("docstring") AddScriptToMenu 
"AddScriptToMenu: Install the script into the application. The commandName indicates the 
string by which this script will be known to the application. If the script is to be 
installed in the menu, the menuName and optionalSubMenuName parameters specify the menu. 
Pass 1 for isLibrary if the script is a library only and 0 to install it in the menu.";
void AddScriptToMenu( const char *script, const char *commandName, const char *menuName, const char *optionalSubMenuName, bool isLibrary );

%feature("docstring") AddScriptToPackage 
"AddScriptToPackage: Install the script into the application. The commandName indicates 
the string by which this script will be known to the application. If the script is to be 
installed in the menu, the menuName and optionalSubMenuName parameters specify the menu. 
Pass 1 for isLibrary if the script is a library only and 0 to install it in the menu.";
void AddScriptToPackage( const char *script, const char *packageName, long packageLevel, const char *commandName, const char *menuName, const char *optionalSubMenuName, bool isLibrary );

%feature("docstring") AddTagsToPackage 
"AddTagsToPackage: Install the tags into the package. The identifier is used to identify 
the tags in the packages. Clients should take care to use unique identifiers. See the 
Java model of naming classes.";
void AddTagsToPackage( const TagGroup &tags, const char *packageName, long packageLevel, const char *identifier );

%feature("docstring") AdjustScriptMenuItem 
"AdjustScriptMenuItem: Adjusts the display characteristics of the given script menu item. 
NewCommandName specifies the new name for the menu item. The menu item will have to be 
referred to by that name from then forth. Enabled/checked indicate whether the item is 
enabled/checked. Key refers to the command key equivalent on the MacOS. Pass 0 to have no 
command key equivalent. AcceleratorPos refers to the position of the accelerator 
equivalent on Windows. Pass -1 to have to accelerator.";
void AdjustScriptMenuItem( const char *commandName, const char *menuName, const char *optionalSubMenuName, const char *newCommandName, bool enabled, bool checked, char key, long acceleratorPos );

%feature("docstring") AllocString 
"AllocString: Allocates a string used in the script language. Length should include eos 
character.";
long AllocString( long length );

%feature("docstring") ApplicationGetApplicationMode 
"ApplicationGetApplicationMode: Gets the current mode of DigitalMicrograph as a string.";
String ApplicationGetApplicationMode();

%feature("docstring") ApplicationGetBounds 
"ApplicationGetBounds: Gets the bounds of the main area of the application in application 
coordinates.";
void ApplicationGetBounds( long *t, long *l, long *b, long *r );

%feature("docstring") ApplicationGetOrigin 
"ApplicationGetOrigin: Gets the origin of the application in global coordinates.";
void ApplicationGetOrigin( long *x, long *y );

%feature("docstring") ApplyDataBar 
"ApplyDataBar: Applies a data bar to the image.";
void ApplyDataBar( const ImageDisplay &imgDisp );

%feature("docstring") ApproveDisplayBuffer 
"ApproveDisplayBuffer: Mark the display buffer as valid.";
void ApproveDisplayBuffer( const Image &argument_1 );

%feature("docstring") ApproveSurvey 
"ApproveSurvey: Mark the image as already surveyed.";
void ApproveSurvey( const Image &argument_1 );

%feature("docstring") AutoCorrelate 
"AutoCorrelate: Return an image which is the result of the auto correlation of source.";
Image AutoCorrelate( const Image &source );

%feature("docstring") AutoCorrelation 
"AutoCorrelation: Return an image which is the result of the auto correlation of source.";
Image AutoCorrelation( const Image &source );

%feature("docstring") Beep 
"Beep: Play the current system beep.";
void Beep( );

%feature("docstring") BinaryImage 
"BinaryImage: Creates a 4D binary image of size [d0,d1,d2] with the given title.";
Image BinaryImage( const char *title, long d0, long d1, long d2, long d3);

%feature("docstring") BinaryImage 
"BinaryImage: Creates a 3D binary image of size [d0,d1,d2] with the given title.";
Image BinaryImage( const char *title, long d0, long d1, long d2 );

%feature("docstring") BinaryImage 
"BinaryImage: Creates a 1D binary image of size [d0] with the given title.";
Image BinaryImage( const char *title, long d0 );

%feature("docstring") BinaryImage 
"BinaryImage: Creates a 2D binary image of size [d0,d1] with the given title.";
Image BinaryImage( const char *title, long d0, long d1 );

%feature("docstring") BrowseTagFile 
"BrowseTagFile: Present an open file dialog to the user, allow them to select a tag file, 
and then allow them to browse through it.";
void BrowseTagFile( );

%feature("docstring") ChooseMenuItem 
"ChooseMenuItem: Choose the given menu item.";
bool ChooseMenuItem( const char *menu, const char *subMenu, const char *item );

%feature("docstring") ClassAddMethod 
"ClassAddMethod:";
Function ClassAddMethod( ::Gatan::PlugIn::DM_Env *dm_env, const String &class_name, const Function &method );

%feature("docstring") ClassRemoveMethod 
"ClassRemoveMethod:";
void ClassRemoveMethod( const String &class_name, const Function &method );

%feature("docstring") CleanImage 
"CleanImage: Mark the image as having been saved.";
void CleanImage( const Image &argument_1 );

%feature("docstring") ClearDisplayBuffer 
"ClearDisplayBuffer: Clear the display buffer.";
void ClearDisplayBuffer( const Image &argument_1 );

%feature("docstring") ClearSelection 
"ClearSelection: Remove selection (if any) from the image.";
void ClearSelection( const Image &argument_1 );

%feature("docstring") ClipboardGetAsString 
"ClipboardGetAsString: Gets the contents of the clipboard as a string with the given 
encoding, if possible, and returns true if successful.";
bool ClipboardGetAsString( String &str );

%feature("docstring") ClipboardGetAsTagGroup 
"ClipboardGetAsTagGroup: Gets the contents of the clipboard as a tag group, if possible, 
and returns true if successful.";
bool ClipboardGetAsTagGroup( TagGroup &tagGroup );

%feature("docstring") ClipboardSetAsString 
"ClipboardSetAsString: Sets the contents of the clipboard to the text.";
void ClipboardSetAsString( const String &argument_1 );

%feature("docstring") ClipboardSetAsTagGroup 
"ClipboardSetAsTagGroup: Sets the contents of the clipboard to the tag group.";
void ClipboardSetAsTagGroup( const TagGroup &tagGroup );

%feature("docstring") CloseFile 
"CloseFile: Close the file. This function should be called to close a file whenever a 
file is opened.";
void CloseFile( DM_FileReference file );

%feature("docstring") CloseImage 
"CloseImage: Attempt to close the image.  If the data has changed, a dialog box appears 
to ask the user to save the image before closing it.";
void CloseImage( const Image &argument_1 );

%feature("docstring") CloseProgressWindow 
"CloseProgressWindow: Close the progress window if it is open.";
void CloseProgressWindow( );

%feature("docstring") CloseTimeBar 
"CloseTimeBar: Closes the time bar.";
void CloseTimeBar( );

%feature("docstring") CommandDown 
"CommandDown: Returns 1 if the command key is down and 0 otherwise.";
bool CommandDown( );

%feature("docstring") LMouseButtonDown 
"CommandDown: Returns 1 if the command key is down and 0 otherwise.";
bool LMouseButtonDown( );

%feature("docstring") RMouseButtonDown 
"CommandDown: Returns 1 if the command key is down and 0 otherwise.";
bool RMouseButtonDown( );

%feature("docstring") ComplexImage 
"ComplexImage: Creates a 4D complex image of size [d0,d1,d2,d3] with the given title. The 
bytes parameter can be 8 or 16 for single and double precision floating point numbers.";
Image ComplexImage( const char *title, long bytes, long d0, long d1, long d2, long d3);

%feature("docstring") ComplexImage 
"ComplexImage: Creates a 3D complex image of size [d0,d1,d2] with the given title. The 
bytes parameter can be 8 or 16 for single and double precision floating point numbers.";
Image ComplexImage( const char *title, long bytes, long d0, long d1, long d2 );

%feature("docstring") ComplexImage 
"ComplexImage: Creates a 2D complex image of size [d0,d1] with the given title. The bytes 
parameter can be 8 or 16 for single and double precision floating point numbers.";
Image ComplexImage( const char *title, long bytes, long d0, long d1 );

%feature("docstring") ComplexImage 
"ComplexImage: Creates a 1D complex image of size [d0] with the given title. The bytes 
parameter can be 8 or 16 for single and double precision floating point numbers.";
Image ComplexImage( const char *title, long bytes, long d0 );

%feature("docstring") ComplexToPacked 
"ComplexToPacked: Creates a new packed complex image from the complex 8-byte source.";
Image ComplexToPacked( const Image &source );

%feature("docstring") ComplexToPacked2 
"ComplexToPacked2: Creates a new packed complex image from the complex 8-byte source.";
Image ComplexToPacked2( const Image &source, long style );

%feature("docstring") ComponentAddChildAfter 
"ComponentAddChildAfter: Adds 'child' to 'parent's list of sub-annotations after 
'annot_pos'.";
void ComponentAddChildAfter( const Component &parent, const Component &child, const Component &annot_pos );

%feature("docstring") ComponentAddChildAtBeginning 
"ComponentAddChildAtBeginning: Adds 'child' to the beginning of 'parent's list of 
sub-annotations.";
void ComponentAddChildAtBeginning( const Component &parent, const Component &child );

%feature("docstring") ComponentAddChildAtEnd 
"ComponentAddChildAtEnd: Adds 'child' to the end of 'parent's list of sub-annotations.";
void ComponentAddChildAtEnd( const Component &parent, const Component &child );

%feature("docstring") ComponentAddChildBefore 
"ComponentAddChildBefore: Adds 'child' to 'parent's list of sub-annotations before 
'annot_pos'.";
void ComponentAddChildBefore( const Component &parent, const Component &child, const Component &annot_pos );

%feature("docstring") ComponentAddNewComponent 
"ComponentAddNewComponent: Creates a new annotaiton of type 'type' and adds it to 'parent'";
Component ComponentAddNewComponent( const Component &parent, long type, float f1, float f2, float f3, float f4 );

%feature("docstring") ComponentClone 
"ComponentClone: Returns a identical copy of the component and all its sub-components, 
copying associated images if 'doDeepCopy' is true.";
Component ComponentClone( const Component &comp, bool doDeepCopy );

%feature("docstring") ComponentCountChildren 
"ComponentCountChildren: Returns the number of sub components.";
long ComponentCountChildren( const Component &comp );

%feature("docstring") ComponentCountChildrenOfType 
"ComponentCountChildrenOfType: Returns the number of sub-components of type 'type'.";
long ComponentCountChildrenOfType( const Component &comp, long type );

%feature("docstring") ComponentGetBoundingRect 
"ComponentGetBoundingRect: Gets the bounding rect of the annotation.";
void ComponentGetBoundingRect( const Component &comp, float *t, float *l, float *b, float *r );

%feature("docstring") ComponentGetBoundingRectInView 
"ComponentGetBoundingRectInView: Gets the bounding rect of the annotation.";
void ComponentGetBoundingRectInView( const Component &comp, float *t, float *l, float *b, float *r );

%feature("docstring") ComponentGetChild 
"ComponentGetChild: Returns the 'index'th sub-component of 'comp'.";
Component ComponentGetChild( const Component &comp, long index );

%feature("docstring") ComponentGetChildByID 
"ComponentGetChildByID: Returns the component child of 'comp' with id 'ID'.";
Component ComponentGetChildByID( const Component &comp, long ID );

%feature("docstring") ComponentGetChildToLocalTransform 
"ComponentGetChildToLocalTransform: Gets the transformation from  child to local 
coordinates.";
void ComponentGetChildToLocalTransform( const Component &comp, float *off_x, float *off_y, float *scale_x, float *scale_y );

%feature("docstring") ComponentGetChildToPageTransform 
"ComponentGetChildToPageTransform: Gets the transformation from child to page coordinates.";
void ComponentGetChildToPageTransform( const Component &comp, float *off_x, float *off_y, float *scale_x, float *scale_y );

%feature("docstring") ComponentGetChildToViewTransform 
"ComponentGetChildToViewTransform: Gets the transformation from child to view coordinates.";
void ComponentGetChildToViewTransform( const Component &comp, float *off_x, float *off_y, float *scale_x, float *scale_y );

%feature("docstring") ComponentGetChildToWindowTransform 
"ComponentGetChildToWindowTransform: Gets the transformation from child to window 
coordinates.";
void ComponentGetChildToWindowTransform( const Component &comp, float *off_x, float *off_y, float *scale_x, float *scale_y );

%feature("docstring") ComponentGetControlPoint 
"ComponentGetControlPoint: Returns the value '(x,y)' associated with the control point, 
and returns 'true' if the control point is valid";
bool ComponentGetControlPoint( const Component &comp, long loc, float *x, float *y );

%feature("docstring") ComponentGetDescendentByID 
"ComponentGetDescendentByID: Returns the component child of 'comp' with id 'ID'.";
Component ComponentGetDescendentByID( const Component &comp, long ID );

%feature("docstring") ComponentGetDrawingMode 
"ComponentGetDrawingMode: Gets the drawing mode of the image doucment component.";
long ComponentGetDrawingMode( const Component &comp );

%feature("docstring") ComponentGetFillMode 
"ComponentGetFillMode: Gets the fill mode of the image doucment component.";
long ComponentGetFillMode( const Component &comp );

%feature("docstring") ComponentGetFontAttributes 
"ComponentGetFontAttributes: Gets the attributes of the component's font.";
long ComponentGetFontAttributes( const Component &comp );

%feature("docstring") ComponentGetFontFaceName 
"ComponentGetFontFaceName: Gets the face name of the component's font.";
String ComponentGetFontFaceName( const Component &comp );

%feature("docstring") ComponentGetFontInfo 
"ComponentGetFontInfo: Gets a description of the component's font.";
void ComponentGetFontInfo( const Component &comp, String &faceName, long *attributes, long *size );

%feature("docstring") ComponentGetFontSize 
"ComponentGetFontSize: Gets the point size of the component's font.";
long ComponentGetFontSize( const Component &comp );

%feature("docstring") ComponentGetID 
"ComponentGetID: Gets the unique identifier of the annotation in the image document.";
long ComponentGetID( const Component &annot );

%feature("docstring") ComponentGetImageDocument 
"ComponentGetImageDocument: Gets the image document associated with the annotation.";
ImageDocument ComponentGetImageDocument( const Component &annot );

%feature("docstring") ComponentGetLocalToPageTransform 
"ComponentGetLocalToPageTransform: Gets the transformation from local to page coordinates.";
void ComponentGetLocalToPageTransform( const Component &comp, float *off_x, float *off_y, float *scale_x, float *scale_y );

%feature("docstring") ComponentGetLocalToViewTransform 
"ComponentGetLocalToViewTransform: Gets the transformation from local to view coordinates.";
void ComponentGetLocalToViewTransform( const Component &comp, float *off_x, float *off_y, float *scale_x, float *scale_y );

%feature("docstring") ComponentGetLocalToWindowTransform 
"ComponentGetLocalToWindowTransform: Gets the transformation from local to window 
coordinates.";
void ComponentGetLocalToWindowTransform( const Component &comp, float *off_x, float *off_y, float *scale_x, float *scale_y );

%feature("docstring") ComponentGetNthChildOfType 
"ComponentGetNthChildOfType: Returns the nth sub-component of type 'type'.";
Component ComponentGetNthChildOfType( const Component &comp, long type, long index );

%feature("docstring") ComponentGetParentComponent 
"ComponentGetParentComponent: Gets the parent component of 'comp', if any.";
Component ComponentGetParentComponent( const Component &comp );

%feature("docstring") ComponentGetParentImageDisplay 
"ComponentGetParentImageDisplay: Gets the parent image display of the 'comp', if any.";
ImageDisplay ComponentGetParentImageDisplay( const Component &comp );

%feature("docstring") ComponentGetRect 
"ComponentGetRect: Gets the rectangle of the annotation.";
void ComponentGetRect( const Component &comp, float *top, float *left, float *bottom, float *right );

%feature("docstring") ComponentGetRectInView 
"ComponentGetRectInView: Gets the rectangle of the annotation.";
void ComponentGetRectInView( const Component &comp, float *top, float *left, float *bottom, float *right );

%feature("docstring") ComponentGetTagGroup 
"ComponentGetTagGroup: Gets the tag group associated with the annotation.";
TagGroup ComponentGetTagGroup( const Component &annot );

%feature("docstring") ComponentGetType 
"ComponentGetType: Gets the type of the annotation.";
long ComponentGetType( const Component &annot );

%feature("docstring") ComponentIsOfType 
"ComponentIsOfType: Gets the type of the annotation.";
bool ComponentIsOfType( const Component &annot, long type );

%feature("docstring") ComponentIsSelected 
"ComponentIsSelected: Returns whether the component is selected.";
bool ComponentIsSelected( const Component &comp );

%feature("docstring") ComponentIsValid 
"ComponentIsValid: Returns true if 'annot' points to a valid object.";
bool ComponentIsValid( const Component &annot );

%feature("docstring") ComponentOffsetControlPoint 
"ComponentOffsetControlPoint: Changes the control point 'loc' of 'comp' by '(x,y)' using 
restrictions specified by 'restrict_style'.";
void ComponentOffsetControlPoint( const Component &comp, long loc, float x, float y, long restrict_style );

%feature("docstring") ComponentPositionAroundPoint 
"ComponentPositionAroundPoint: Moves the annotation so if 'horz', the 'rel_x' horizontal 
point in the bounding rect is at 'new_x', and if 'vert', the 'rel_y' vertical point in 
the bounding rect is at 'new_y'";
void ComponentPositionAroundPoint( const Component &comp, float new_x, float new_y, float rel_x, float rel_y, bool horz, bool vert );

%feature("docstring") ComponentRemoveFromParent 
"ComponentRemoveFromParent: Removes the image document component from its parent.";
void ComponentRemoveFromParent( const Component &comp );

%feature("docstring") ComponentSetControlPoint 
"ComponentSetControlPoint: Sets the control point 'loc' of 'comp' to '(x,y)' using 
restrictions specified by 'restrict_style'.";
void ComponentSetControlPoint( const Component &comp, long loc, float x, float y, long restrict_style );

%feature("docstring") ComponentSetDrawingMode 
"ComponentSetDrawingMode: Sets the drawing mode of the image document component.";
void ComponentSetDrawingMode( const Component &comp, long mode );

%feature("docstring") ComponentSetFillMode 
"ComponentSetFillMode: Sets the fill mode of the image document component.";
void ComponentSetFillMode( const Component &comp, long mode );

%feature("docstring") ComponentSetFontAttributes 
"ComponentSetFontAttributes: Sets the attributes of the component's font.";
void ComponentSetFontAttributes( const Component &comp, long attributes );

%feature("docstring") ComponentSetFontFaceName 
"ComponentSetFontFaceName: Sets the face name of the component's font.";
void ComponentSetFontFaceName( const Component &comp, const String &face_name );

%feature("docstring") ComponentSetFontInfo 
"ComponentSetFontInfo: Sets the font information of the component's font.";
void ComponentSetFontInfo( const Component &comp, const String &face_name, long attributes, long size );

%feature("docstring") ComponentSetFontSize 
"ComponentSetFontSize: Sets the point size of the component's font.";
void ComponentSetFontSize( const Component &comp, long size );

%feature("docstring") ComponentSetRect 
"ComponentSetRect: Sets the rectangle of the annotation.";
void ComponentSetRect( const Component &comp, float top, float left, float bottom, float right );

%feature("docstring") ComponentSetSelected 
"ComponentSetSelected: Sets the selection status of the component.";
void ComponentSetSelected( const Component &comp, bool select );

%feature("docstring") ComponentSetSelectable 
"ComponentSetSelectable: Sets whether the component can be selected.";
void ComponentSetSelectable( const Component &comp, bool selectable );

%feature("docstring") ComponentTransformCoordinates 
"ComponentTransformCoordinates: Transforms the component by the specified transform.";
void ComponentTransformCoordinates( const Component &comp, float off_x, float off_y, float scale_x, float scale_y );

%feature("docstring") ConjMultiplyPackedByPacked 
"ConjMultiplyPackedByPacked: Conjugate multiply packed image a by packed image b and 
store the result in b. No data type checking is performed.";
void ConjMultiplyPackedByPacked( const Image &a, const Image &b );

%feature("docstring") ConnectObject 
"ConnectObject: Build the connection with the given object and message under ident.";
void ConnectObject( long object, const char *message, const char *ident, const ScriptObject &scriptObject, const char *method );

%feature("docstring") ContinueCancelDialog 
"ContinueCancelDialog: Puts up a dialog with both a Continue button and Cancel button. 
Returns 1 for Continue and 0 for Cancel.";
bool ContinueCancelDialog( const char *prompt );

%feature("docstring") ControlDown 
"ControlDown: Returns 1 if the control key is down and 0 otherwise.";
bool ControlDown( );

%feature("docstring") ConvertImageData 
"ConvertImageData:";
void ConvertImageData( const Image &from, const Image &to );

%feature("docstring") ConvertImageDataSlice_2D 
"ConvertImageDataSlice_2D:";
void ConvertImageDataSlice_2D( const Image &from, const Image &to, long x_l, long y_l, long f_x_0, long f_y_0, long f_x_d, long f_x_s, long f_y_d, long f_y_s, long t_x_0, long t_y_0, long t_x_d, long t_x_s, long t_y_d, long t_y_s );

%feature("docstring") ConvertInt16ToFloat 
"ConvertInt16ToFloat: Convert the signed 2-byte data in image a to real data and store 
the result in image b. No data type checking is performed.";
void ConvertInt16ToFloat( const Image &a, const Image &b );

%feature("docstring") ConvertPICTToRGBImage 
"ConvertPICTToRGBImage: Convert a PICT stored in a handle to an RGB image.";
Image ConvertPICTToRGBImage( long picture );

%feature("docstring") ConvertToByte 
"ConvertToByte: Converts the given image to unsigned integer 1-byte data.";
void ConvertToByte( const Image &argument_1 );

%feature("docstring") ConvertToComplex 
"ConvertToComplex: Converts the given image to complex single precision data.";
void ConvertToComplex( const Image &argument_1 );

%feature("docstring") ConvertToFloat 
"ConvertToFloat: Converts the given image to single precision real data.";
void ConvertToFloat( const Image &argument_1 );

%feature("docstring") ConvertToLong 
"ConvertToLong: Converts the given image to signed integer 4-byte data.";
void ConvertToLong( const Image &argument_1 );

%feature("docstring") ConvertToPackedComplex 
"ConvertToPackedComplex: Converts the given image to packed complex data.";
void ConvertToPackedComplex( const Image &argument_1 );

%feature("docstring") ConvertToShort 
"ConvertToShort: Converts the given image to signed integer 2-byte data.";
void ConvertToShort( const Image &argument_1 );

%feature("docstring") ConvertUInt8ToFloat 
"ConvertUInt8ToFloat: Convert the unsigned 1-byte data in image a to real data and 
store the result in image b. No data type checking is performed.";
void ConvertUInt8ToFloat( const Image &a, const Image &b );

%feature("docstring") ConvertUInt8ToDisplay8 
"ConvertUInt8ToDisplay8: Copy the sub-area of unsigned 1-byte integer image src 
indicated by [top,left,bottom,right] to dst. The rowBytes parameter indicates the length 
of the row of dst. To copy to the screen, pass 0 for dst and rowBytes. No data type 
checking is performed.";
void ConvertUInt8ToDisplay8( const Image &src, long top, long left, long bottom, long right, long dst, long rowBytes );

%feature("docstring") Convolution 
"Convolution: Creates a new image that is the convolution of the source image with the 
kernel. The kernel should be less than 7x7.";
Image Convolution( const Image &source, const Image &kernel );

%feature("docstring") CopyGWorldCTable 
"CopyGWorldCTable: Copy the OS Color Table of the image and return it. ( Returns 
CTabHandle for MacOS, HGLOBAL for Windows ).";
long CopyGWorldCTable( const Image &argument_1 );

%feature("docstring") CountAllImages 
"CountAllImages: Returns the number of images.";
long CountAllImages( );

%feature("docstring") CountDocumentWindows 
"CountDocumentWindows: Returns the number of document windows.";
long CountDocumentWindows( );

%feature("docstring") CountDocumentWindowsOfType 
"CountDocumentWindowsOfType: Returns the number of document windows with type 'type'.";
long CountDocumentWindowsOfType( long type );

%feature("docstring") CountFloatingWindows 
"CountFloatingWindows: Returns the number of floating windows.";
long CountFloatingWindows( );

%feature("docstring") CountImageDocuments 
"CountImageDocuments: Returns the number of image documents.";
long CountImageDocuments( );

%feature("docstring") CountImages 
"CountImages: Count the number of images.";
long CountImages( );

%feature("docstring") CountScreens 
"CountScreens: Returns the number of screens.";
long CountScreens( );

%feature("docstring") CountScriptFunctions 
"CountScriptFunctions: Returns the number of script functions having name 'fnName'.";
long CountScriptFunctions( const char *fnName );

%feature("docstring") CreateBinary1DImage 
"CreateBinary1DImage: Creates a 1D binary image of size [d0] with the given title.";
Image CreateBinary1DImage( const char *title, long d0 );

%feature("docstring") CreateBinary2DImage 
"CreateBinary2DImage: Creates a 2D binary image of size [d0,d1] with the given title.";
Image CreateBinary2DImage( const char *title, long d0, long d1 );

%feature("docstring") CreateBinary3DImage 
"CreateBinary3DImage: Creates a 3D binary image of size [d0,d1,d2] with the given title.";
Image CreateBinary3DImage( const char *title, long d0, long d1, long d2 );

%feature("docstring") CreateByteImage 
"CreateByteImage: Creates a 2D unsigned 1-byte integer image of size [width,height] with 
the given title.";
Image CreateByteImage( const char *title, long width, long height );

%feature("docstring") CreateComplex1DImage 
"CreateComplex1DImage: Creates a 1D complex image of size [d0] with the given title. The 
bytes parameter can be 8 or 16 for single and double precision floating point numbers.";
Image CreateComplex1DImage( const char *title, long bytes, long d0 );

%feature("docstring") CreateComplex2DImage 
"CreateComplex2DImage: Creates a 2D complex image of size [d0,d1] with the given title. 
The bytes parameter can be 8 or 16 for single and double precision floating point numbers.";
Image CreateComplex2DImage( const char *title, long bytes, long d0, long d1 );

%feature("docstring") CreateComplex3DImage 
"CreateComplex3DImage: Creates a 3D complex image of size [d0,d1,d2] with the given 
title. The bytes parameter can be 8 or 16 for single and double precision floating point 
numbers.";
Image CreateComplex3DImage( const char *title, long bytes, long d0, long d1, long d2 );

%feature("docstring") CreateComplexImage 
"CreateComplexImage: Creates a 2D single precision complex image of size [width,height] 
with the given title.";
Image CreateComplexImage( const char *title, long width, long height );

%feature("docstring") CreateDirectory 
"CreateDirectory: Create a folder named fileName.";
void CreateDirectory( const String &dir_path );

%feature("docstring") CreateFile 
"CreateFile: Create a file named fileName.";
void CreateFile( const String &file_path );

%feature("docstring") CreateFileForWriting 
"CreateFileForWriting: Create and open the file for writing. Return the file reference 
for this file. This call must be balanced with call to CloseFile() with the returned 
reference number.";
DM_FileReference CreateFileForWriting( const String &file_path );

%feature("docstring") CreateFloatImage 
"CreateFloatImage: Creates a 2D single precision float image of size [width,height] with 
the given title.";
Image CreateFloatImage( const char *title, long width, long height );

%feature("docstring") CreateImageFromDisplay 
"CreateImageFromDisplay: Convert the display of image to an RGB image.";
Image CreateImageFromDisplay( const Image &argument_1 );

%feature("docstring") CreateInteger1DImage 
"CreateInteger1DImage: Creates a 1D integer image of size [d0] with the given title. The 
bytes and isSigned parameters specify integer specific attributes of the data.";
Image CreateInteger1DImage( const char *title, long bytes, bool isSigned, long d0 );

%feature("docstring") CreateInteger2DImage 
"CreateInteger2DImage: Creates a 2D integer image of size [d0,d1] with the given title. 
The bytes and isSigned parameters specify integer specific attributes of the data.";
Image CreateInteger2DImage( const char *title, long bytes, bool isSigned, long d0, long d1 );

%feature("docstring") CreateInteger3DImage 
"CreateInteger3DImage: Creates a 3D integer image of size [d0,d1,d2] with the given 
title. The bytes can be 1, 2, or 4 and isSigned can be 1 (true) or 0 (false).";
Image CreateInteger3DImage( const char *title, long bytes, bool isSigned, long d0, long d1, long d2 );

%feature("docstring") CreateLongImage 
"CreateLongImage: Creates a 2D signed 4-byte integer image of size [width,height] with 
the given title.";
Image CreateLongImage( const char *title, long width, long height );

%feature("docstring") CreateMaskFromAnnotations 
"CreateMaskFromAnnotations: Creates a 2D binary mask from an image display's annotations.";
Image CreateMaskFromAnnotations( const RasterImageDisplay rdisp, long filter_length, bool is_opaque, bool * has_mask);

%feature("docstring") CreatePackedComplexImage 
"CreatePackedComplexImage: Creates a 2D packed complex image of size [width,height] with 
the given title and 8byte complex data (floats).";
Image CreatePackedComplexImage( const char *title, long width, long height );

%feature("docstring") CreatePackedComplexImage 
"CreatePackedComplexImage: Creates a 2D packed complex image of size [width,height] with 
the given title and the given data type.";
Image CreatePackedComplexImage( const char *title, long data_type, long width, long height );

%feature("docstring") CreateReal1DImage 
"CreateReal1DImage: Creates a 1D real image of size [d0] with the given title. The bytes 
parameter can be 4 or 8 for single and double precision floating point numbers.";
Image CreateReal1DImage( const char *title, long bytes, long d0 );

%feature("docstring") CreateReal2DImage 
"CreateReal2DImage: Creates a 2D real image of size [d0,d1] with the given title. The 
bytes parameter can be 4 or 8 for single and double precision floating point numbers.";
Image CreateReal2DImage( const char *title, long bytes, long d0, long d1 );

%feature("docstring") CreateReal3DImage 
"CreateReal3DImage: Creates a 3D real image of size [d0,d1,d2] with the given title. The 
bytes parameter can be 4 or 8 for single and double precision floating point numbers.";
Image CreateReal3DImage( const char *title, long bytes, long d0, long d1, long d2 );

%feature("docstring") CreateRGB1DImage 
"CreateRGB1DImage: Creates a 1D RGB image of size [d0] with the given title. The bytes 
parameter must be 4.";
Image CreateRGB1DImage( const char *title, long bytes, long d0 );

%feature("docstring") CreateRGB2DImage 
"CreateRGB2DImage: Creates a 2D RGB image of size [d0,d1] with the given title. The bytes 
parameter must be 4.";
Image CreateRGB2DImage( const char *title, long bytes, long d0, long d1 );

%feature("docstring") CreateRGB3DImage 
"CreateRGB3DImage: Creates a 3D RGB image of size [d0,d1,d2] with the given title. The 
bytes parameter must be 4.";
Image CreateRGB3DImage( const char *title, long bytes, long d0, long d1, long d2 );

%feature("docstring") CreateRGBImage 
"CreateRGBImage: Creates a 2D RGB image of size [width,height] with the given title.";
Image CreateRGBImage( const char *title, long width, long height );

%feature("docstring") CreateRGBImageFromPicture 
"CreateRGBImageFromPicture: Create an RGB image by drawing into it with a picture";
Image CreateRGBImageFromPicture( long picture );

%feature("docstring") CreateShortImage 
"CreateShortImage: Creates a 2D signed 2-byte integer image of size [width,height] with 
the given title.";
Image CreateShortImage( const char *title, long width, long height );

%feature("docstring") CrossCorrelate 
"CrossCorrelate: Return an image which is the result of the cross correlation of source1 
and source2.";
Image CrossCorrelate( const Image &source1, const Image &source2 );

%feature("docstring") CrossCorrelation 
"CrossCorrelation: Return an image which is the result of the cross correlation of 
source1 and source2.";
Image CrossCorrelation( const Image &source1, const Image &source2 );

%feature("docstring") CrossProduct 
"CrossProduct: Return the matrix cross product image of matrix images a and b.";
Image CrossProduct( const Image &a, const Image &b );

%feature("docstring") CWCloseWindow 
"CWCloseWindow: Close a custom window. See the SDK documentation for more information.";
void CWCloseWindow( long windowObject );

%feature("docstring") CWCreateWindow 
"CWCreateWindow: Create a custom window. See the SDK documentation for more information.";
long CWCreateWindow( long windowInstance, short top, short left, short bottom, short right );

%feature("docstring") CWDeleteWindow 
"CWDeleteWindow: Delete a custom window. See the SDK documentation for more information.";
void CWDeleteWindow( long windowObject );

%feature("docstring") CWGetWindowPtr 
"CWGetWindowPtr: Get the MacOS WindowPtr from the window. See the SDK documentation for 
more information.";
long CWGetWindowPtr( long windowObject );

%feature("docstring") CWInvalidateWindow 
"CWInvalidateWindow: Invalidate a custom window. See the SDK documentation for more 
information.";
void CWInvalidateWindow( long windowObject );

%feature("docstring") DeallocString 
"DeallocString: Deallocates a string used in the script language.";
void DeallocString( long string );

%feature("docstring") Delay 
"Delay: Delay for the given number of tick counts.";
void Delay( long argument_1 );

%feature("docstring") DeleteDirectory 
"DeleteDirectory: Deletes the folder named dirName.";
void DeleteDirectory( const String &dir_path );

%feature("docstring") DeleteFile 
"DeleteFile: Delete the file.";
void DeleteFile( const String &file_path );

%feature("docstring") DeleteImage 
"DeleteImage: Close the image without asking the user to save it.";
void DeleteImage( const Image &argument_1 );

%feature("docstring") DeleteImageFile 
"DeleteImageFile: Delete the image file.";
void DeleteImageFile( const char *fileName );

%feature("docstring") DestroyPicture 
"DestroyPicture: Destroy a picture";
void DestroyPicture( long *picture );

%feature("docstring") DisconnectObject 
"DisconnectObject: Break the connection specified by ident for the given object and 
message.";
void DisconnectObject( long object, const char *message, const char *ident );

%feature("docstring") DisplayAt 
"DisplayAt: Display the image's image document if it is not display already and moves the 
window position to [x,y] screen coordinates.";
void DisplayAt( const Image &argument_1, long x, long y );

%feature("docstring") DisplayImageDocumentWithDialog 
"DisplayImageDocumentWithDialog: Display the image document with a dialog attached.  The
position of the dialog is set by dlgPosition (top=0, bottom=1, left=2, right=3).";
void DisplayImageDocumentWithDialog(const ImageDocument &imgDoc, CDialog* dlgPtr, uint32 dlgPosition);

%feature("docstring") DoesClassExist 
"DoesClassExist:";
bool DoesClassExist( const String &dir_path );

%feature("docstring") DoesDirectoryExist 
"DoesDirectoryExist: Returns 'true' if the named directory exists";
bool DoesDirectoryExist( const String &dir_path );

%feature("docstring") DoesFileExist 
"DoesFileExist: Returns 'true' if the named file exists";
bool DoesFileExist( const String &dir_path );

%feature("docstring") DoesFunctionExist 
"DoesFunctionExist: Determines if the given function exists.";
bool DoesFunctionExist( const String &dir_path );

%feature("docstring") DoesImageExist 
"DoesImageExist: Determine if the image with imageID exists and returns 1 if it does; 
return 0 otherwise.";
bool DoesImageExist( long imageID );

%feature("docstring") DoEvents 
"DoEvents: Process all pending MacOS events.";
void DoEvents( );

%feature("docstring") EditorWindowAddText 
"EditorWindowAddText: Appends the text to a editor window.";
void EditorWindowAddText( const Window &window, const String &text );

%feature("docstring") EditorWindowGetFont 
"EditorWindowGetFont: Gets the font of a script window.";
void EditorWindowGetFont( const Window &window, String &face_name, ulong *attributes, ulong *size );

%feature("docstring") EditorWindowGetText 
"EditorWindowGetText: Gets the text in an editor window.";
String EditorWindowGetText( const Window &window );

%feature("docstring") EditorWindowPrint 
"EditorWindowPrint: Prints the editor window.";
bool EditorWindowPrint( const Window &window );

%feature("docstring") EditorWindowSaveToFile 
"EditorWindowSaveToFile: Saves the editor window to the specified path.";
void EditorWindowSaveToFile( const Window &window, const String &path );

%feature("docstring") EditorWindowSetFont 
"EditorWindowSetFont: Sets the font of a script window.";
void EditorWindowSetFont( const Window &window, const String &face_name, ulong attributes, ulong size );

%feature("docstring") EditorWindowSetText 
"EditorWindowSetText: Sets the text in an editor window.";
void EditorWindowSetText( const Window &window, const String &text );

%feature("docstring") EMBeamShift 
"EMBeamShift: Shift the beam by xAmount, yAmount. The EM Control Plug-in must be 
currently installed and configured.";
void EMBeamShift( long xAmount, long yAmount );

%feature("docstring") EMChangeFocus 
"EMChangeFocus: Change the focus by amount. The EM Control Plug-in must be currently 
installed and configured.";
void EMChangeFocus( long amount );

%feature("docstring") EMChangeStigmation 
"EMChangeStigmation: Change the stigmation by xAmount, yAmount. The EM Control Plug-in 
must be currently installed and configured.";
void EMChangeStigmation( long xAmount, long yAmount );

%feature("docstring") EMChangeTilt 
"EMChangeTilt: Change the tilt by xAmount, yAmount. The EM Control Plug-in must be 
currently installed and configured.";
void EMChangeTilt( long xAmount, long yAmount );

%feature("docstring") EMCloseCommunication 
"EMCloseCommunication: Close communication to the microscope. The EM Control Plug-in must 
be currently installed and configured.";
void EMCloseCommunication( );

%feature("docstring") EMImageShift 
"EMImageShift: Shift the image by xAmount, yAmount. The EM Control Plug-in must be 
currently installed and configured.";
void EMImageShift( long xAmount, long yAmount );

%feature("docstring") EMLinkControlFunctions 
"EMLinkControlFunctions: Establish link between microscope control functions and the 
application. The EM Control Plug-in must be currently installed and configured.";
void EMLinkControlFunctions( void *functions );

%feature("docstring") EMPrepareImageShift 
"EMPrepareImageShift: Prepare image shift. Call this before a sequence of image shift 
changes. The EM Control Plug-in must be currently installed and configured.";
void EMPrepareImageShift( );

%feature("docstring") EMPrepareShift 
"EMPrepareShift: Prepare beam shift. Call this before a sequence of beam shift changes. 
The EM Control Plug-in must be currently installed and configured.";
void EMPrepareShift( );

%feature("docstring") EMPrepareStigmation 
"EMPrepareStigmation: Prepare stigmation. Call this before a sequence of stigmation 
changes. The EM Control Plug-in must be currently installed and configured.";
void EMPrepareStigmation( );

%feature("docstring") EMPrepareTilt 
"EMPrepareTilt: Prepare tilt. Call this before a sequence of tilt changes. The EM Control 
Plug-in must be currently installed and configured.";
void EMPrepareTilt( );

%feature("docstring") EMSetupCommunication 
"EMSetupCommunication: Setup communication with the microscope. The EM Control Plug-in 
must be currently installed and configured.";
void EMSetupCommunication( );

%feature("docstring") EMUnlinkControlFunctions 
"EMUnlinkControlFunctions: Break link between microscope control functions and the 
application. The EM Control Plug-in must be currently installed and configured.";
void EMUnlinkControlFunctions( );

%feature("docstring") ErrorDialog 
"ErrorDialog: Puts up a dialog explaining the application error.";
void ErrorDialog( short error );

%feature("docstring") ExecuteScriptFile 
"ExecuteScriptFile: Executes the script file indicated by fileName and returns the exit 
value of that script.  A script may specify a specific exit value by exiting with the 
exit(n) function.  If a script does not use the exit() function the exit value will be 0.";
double ExecuteScriptFile( const char *fileName, ulong script_index );

%feature("docstring") ExecuteScriptFile 
"ExecuteScriptFile: Executes the script file indicated by fileName and returns the exit 
value of that script.  A script may specify a specific exit value by exiting with the 
exit(n) function.  If a script does not use the exit() function the exit value will be 0.";
double ExecuteScriptFile( const char *fileName );

%feature("docstring") ExecuteScriptString 
"ExecuteScriptString: Executes the script text and returns the exit value of that script. 
 A script may specify a specific exit value by exiting with the exit(n) function.  If a 
script does not use the exit() function the exit value will be 0.";
double ExecuteScriptString( const String &text );

%feature("docstring") Extract2D_Linear 
"Extract2D_Linear:";
void Extract2D_Linear( const Image &from, const Image &to, long extract_style, double x_start, double y_start, double x_scale_0, double y_scale_0, double x_scale_1, double y_scale_1 );

%feature("docstring") FFT 
"FFT: Creates a new complex 8-byte image from the FFT of the complex image source.";
Image FFT( const Image &source );

%feature("docstring") FindFrontImage 
"FindFrontImage: Returns the front image. Doesn't throw exceptions.";
Image FindFrontImage( );

%feature("docstring") FindFunctionBySignature 
"FindFunctionBySignature: Looks for a function that matches the given signature.";
Function FindFunctionBySignature( const char_range &signature );

%feature("docstring") FindFunctionBySignature 
"FindFunctionBySignature: Looks for a function that matches the given signature.";
Function FindFunctionBySignature( const char_range &name, const char_range &signature );

%feature("docstring") FindImageByID 
"FindImageByID: Returns the image having the given id, or an invalid image of no image 
has that id.";
Image FindImageByID( long id );

%feature("docstring") FindImageByIndex 
"FindImageByIndex: Returns the 'index'th image.";
Image FindImageByIndex( long index );

%feature("docstring") FindImageByLabel 
"FindImageByLabel: Returns the image having the given label, or an invalid image if no 
such image exists.";
Image FindImageByLabel( const char *label );

%feature("docstring") FindImageByName 
"FindImageByName: Returns the image having the given name, or an invalid image of no 
image has that name.";
Image FindImageByName( const char *name );

%feature("docstring") FindLike 
"FindLike: Look for an image with the given name, width, height, and dataType. Return it 
if found.";
Image FindLike( const char *name, long width, long height, short dataType );

%feature("docstring") FindNextImage 
"FindNextImage: Find the next image.";
Image FindNextImage( const Image &argument_1 );

%feature("docstring") FindReferenceImage 
"FindReferenceImage: Look for an image with the given name, width, height, and dataType. 
If it's found, return it. If it's not found, try to load it from disk.";
Image FindReferenceImage( const char *name, short dataType, long width, long height );

%feature("docstring") FirstImage 
"FirstImage: Find the first image.";
Image FirstImage( );

%feature("docstring") FlipHorizontal 
"FlipHorizontal: Flips the image horizontally.";
void FlipHorizontal( const Image &argument_1 );

%feature("docstring") FlipVertical 
"FlipVertical: Flips the image vertically.";
void FlipVertical( const Image &argument_1 );

%feature("docstring") FloatingModelessDialog 
"FloatingModelessDialog: Present a floating window with the prompt and buttonName. When 
the user presses the button, the semaphore will be cleared. This function can only be 
used in the background.";
void FloatingModelessDialog( const char *prompt, const char *buttonName, long semaphore );

%feature("docstring") fngetkey 
"fngetkey: Returns the key that was last pressed.";
short fngetkey( );

%feature("docstring") ForceSurvey 
"ForceSurvey: Cause an immediate survey of the image.";
void ForceSurvey( const Image &argument_1 );

%feature("docstring") FreeSemaphore 
"FreeSemaphore: Free the semaphore. Used only with background processing.";
void FreeSemaphore( long argument_1 );

%feature("docstring") FunctionCountParameters 
"FunctionCountParameters: Returns the number of parameters of the function.";
ulong FunctionCountParameters( const Function &func );

%feature("docstring") FunctionGenerateStub 
"FunctionGenerateStub: Generates a stub function in the format specified by version.";
String FunctionGenerateStub( const Function &func, bool include_body, ulong version );

%feature("docstring") FunctionIsValid 
"FunctionIsValid: Returns true if 'func' is a valid object.";
bool FunctionIsValid( const Function &func );

%feature("docstring") Get1DSize 
"Get1DSize: Store the length of the 1D image into the d0 variable.";
void Get1DSize( const Image &argument_1, long *d0 );

%feature("docstring") Get2DSize 
"Get2DSize: Store the width and height of the 2D image into the d0 and d1 variables.";
void Get2DSize( const Image &argument_1, long *d0, long *d1 );

%feature("docstring") Get3DSize 
"Get3DSize: Store the x,y, and z sizes of the 3D image into the d0, d1, and d2 variables.";
void Get3DSize( const Image &argument_1, long *d0, long *d1, long *d2 );

%feature("docstring") WindowGetPlatformImplementation 
"WindowGetPlatformImplementation: gets the window handle";
ULONG_PTR WindowGetPlatformImplementation( const Window &window );

%feature("docstring") GetBoolean 
"GetBoolean: Puts up a dialog with the given prompt and allows the user to enter Boolean. 
The initial value is passed as a parameter and the result in stored in result. Returns 1 
for OK and 0 for Cancel.";
bool GetBoolean( const char *prompt, bool initalValue, bool *result );

%feature("docstring") GetCalibrationDialog 
"GetCalibrationDialog: Present the calibration dialog to the user. The calibrating pixel 
dimensions are passed as the [aw,ah] parameters. The resulting calibration is stored into 
the [xs,ys] parameters. The initial unit string is passed in and the resulting unit 
string is copied into the unitString buffer.Returns 1 for OK and 0 for Cancel.";
bool GetCalibrationDialog( float aw, float ah, float *xs, float *ys, const char *initialUnitString, char *unitString );

%feature("docstring") GetCLUT 
"GetCLUT: Return the image's CLUT as a 256x1 RGB image.";
Image GetCLUT( const Image &argument_1 );

%feature("docstring") GetDataPtr 
"GetDataPtr: Return a pointer to the actual image data.  If the image data is changed, 
the function DMImageDataChanged() must be called to ensure proper updating, etc. This 
call must be balanced with a call to ReleaseDataPtr().";
long GetDataPtr( const Image &argument_1 );

%feature("docstring") GetDataType 
"GetDataType: Return the enumerated data type of the image.";
short GetDataType( const Image &argument_1 );

%feature("docstring") GetDate 
"GetDate: Return a string representing the current date in the date format indicated by 
dateFormat. The dateFormat parameter can be 0=short, 1=long, 2=abbreviated.";
void GetDate( long dateFormat, char *buffer, long buffer_length );

%feature("docstring") GetDirectoryDialog 
"GetDirectoryDialog: Puts up the GetDirectory dialog and stores the path of the chosen 
directory in 'dirName'";
bool GetDirectoryDialog( char *dirName, long buff_length );

%feature("docstring") GetDirectoryDialog 
"GetDirectoryDialog: Puts up the GetDirectory dialog in init path and stores the path of the chosen 
directory in 'dirName'";
bool GetDirectoryDialog(const String &prompt, const String &init_path, String &dirName );

%feature("docstring") GetDisplayAsImage 
"GetDisplayAsImage: Convert the display of image to an RGB image.";
Image GetDisplayAsImage( const Image &argument_1 );

%feature("docstring") GetDocumentWindow 
"GetDocumentWindow: Gets the 'index'th document window.";
Window GetDocumentWindow( long index );

%feature("docstring") GetDocumentWindowByTitle 
"GetDocumentWindowByTitle: Gets the document window named 'name'.";
Window GetDocumentWindowByTitle( const String &name );

%feature("docstring") GetEstimatedMinMax 
"GetEstimatedMinMax: Store the current estimated minimum and maximum of the image into 
the minPtr and maxPtr variables.";
void GetEstimatedMinMax( const Image &argument_1, float *minPtr, float *maxPtr );

%feature("docstring") GetException 
"GetException: Store the current exception into the error and context variables.";
void GetException( short *error, long *context );

%feature("docstring") GetExceptionDescription 
"GetExceptionDescription: Return the message that would be displayed in the error dialog 
box for an exception as a string.";
String GetExceptionDescription( );

%feature("docstring") GetExceptionString 
"GetExceptionString: Copies the message that would displayed in the error dialog box for 
an exception into dst.";
void GetExceptionString( char *dst );

%feature("docstring") GetFilesInDirectory 
"GetFilesInDirectory: Returns a tag group containing a list of the file names in the 
directory 'dir_path'";
TagGroup GetFilesInDirectory( const String &path, ulong search_flags );

%feature("docstring") GetFloatingWindow 
"GetFloatingWindow: Gets the 'index'th floating window.";
Window GetFloatingWindow( long index );

%feature("docstring") GetFourImages 
"GetFourImages: Puts up a dialog and allows the user to choose four images.  Returns 1 
for Ok and 0 for Cancel.";
bool GetFourImages( const char *title, Image &image1, Image &image2, Image &image3, Image &image4 );

%feature("docstring") GetFourImagesWithPrompt 
"GetFourImagesWithPrompt: Puts up a dialog with the given prompt and allows the user to 
choose four images.  Returns 1 for Ok and 0 for Cancel.";
bool GetFourImagesWithPrompt( const char *prompt, const char *title, Image &image1, Image &image2, Image &image3, Image &image4 );

%feature("docstring") GetFourLabeledImagesWithPrompt 
"GetFourLabeledImagesWithPrompt: Puts up a dialog with the given prompt and allows the 
user to choose four images.  Returns 1 for Ok and 0 for Cancel.";
bool GetFourLabeledImagesWithPrompt( const char *prompt, const char *title, const char *label1, Image &image1, const char *label2, Image &image2, const char *label3, Image &image3, const char *label4, Image &image4 );

%feature("docstring") GetFrontImage 
"GetFrontImage: Return the foremost image.";
Image GetFrontImage( );

%feature("docstring") GetFrontImage 
"GetFrontImage: Set the image variable to represent the foremost image, returns 1 if 
successful; return 0 otherwise.";
bool GetFrontImage( Image &argument_1 );

%feature("docstring") GetFrontImageDocument 
"GetFrontImageDocument: Returns the front image document.";
ImageDocument GetFrontImageDocument( );

%feature("docstring") GetFrontImageID 
"GetFrontImageID: Return the id of the front most image window.";
long GetFrontImageID( );

%feature("docstring") GetImageDataSeed 
"GetImageDataSeed: Return a seed representing the data of the image. Each time the image 
data changes, the seed will change.";
long GetImageDataSeed( const Image &argument_1 );

%feature("docstring") GetImageDocument 
"GetImageDocument: Returns the image document by position with the application.";
ImageDocument GetImageDocument( long position );

%feature("docstring") GetImageDocumentByID 
"GetImageDocumentByID: Returns the image document whose id is 'id'.";
ImageDocument GetImageDocumentByID( long id );

%feature("docstring") GetImageDocumentByPath 
"GetImageDocumentByID: Returns the image document whose id is 'id'.";
ImageDocument GetImageDocumentByPath( const String &path );

%feature("docstring") GetImageFromID 
"GetImageFromID: Store the image corresponding the imageID into the image variable. 
Return 1 if one is found; return 0 otherwise.";
bool GetImageFromID( Image &argument_1, long imageID );

%feature("docstring") GetImageFromID 
"GetImageFromID: Store the image corresponding the imageID into the image variable. 
Return 1 if one is found; return 0 otherwise.";
Image GetImageFromID( long imageID );

%feature("docstring") GetImageID 
"GetImageID: Return the id of the image.";
long GetImageID( const Image &argument_1 );

%feature("docstring") GetImageWindow 
"GetImageWindow: Return the MacOS window associated with the image.";
long GetImageWindow( const Image &argument_1 );

%feature("docstring") GetInteger 
"GetInteger: Puts up a dialog with the given prompt and allows the user to enter an 
integer. The initial value is passed as a parameter and the result in stored in result. 
Returns 1 for OK and 0 for Cancel.";
bool GetInteger( const char *prompt, long initalValue, long *result );

%feature("docstring") GetInversionMode 
"GetInversionMode: Return the contrast inversion mode of the image (1=inverted, 0=not 
inverted).";
bool GetInversionMode( const Image &argument_1 );

%feature("docstring") GetLabel 
"GetLabel: Return the image label of the image.";
String GetLabel( const Image &argument_1 );

%feature("docstring") GetLabel 
"GetLabel: Store the image label of the image into buffer.";
void GetLabel( const Image &argument_1, char *buffer );

%feature("docstring") GetLimits 
"GetLimits: Stores display limits into the lowPtr and highPtr variables.";
void GetLimits( const Image &argument_1, float *lowPtr, float *highPtr );

%feature("docstring") GetMaximalDocumentWindowRect 
"GetMaximalDocumentWindowRect: Gets the bounds of the content region of the largest 
document window.";
void GetMaximalDocumentWindowRect( long options, long *top, long *left, long *bottom, long *right );

%feature("docstring") GetName 
"GetName: Return the name of the image's image document.";
String GetName( const Image &argument_1 );

%feature("docstring") GetName 
"GetName: Store the name of the image's image document into buffer.";
void GetName( const Image &argument_1, char *buffer );

%feature("docstring") GetNamedImage 
"GetNamedImage: Return the image with the image document name.";
Image GetNamedImage( const char *name );

%feature("docstring") GetNamedImage 
"GetNamedImage: Store the image with the image document name into the image variable. 
Return 1 if one is found; return 0 otherwise.";
bool GetNamedImage( Image &argument_1, const char *name );

%feature("docstring") GetNextImageID 
"GetNextImageID: Return the id of the image window following the image with the given id.";
long GetNextImageID( long id );

%feature("docstring") GetNthDocumentWindowOfType 
"GetNthDocumentWindowOfType: Returns the 'index'th document window of type 'type'.";
Window GetNthDocumentWindowOfType( long type, long index );

%feature("docstring") GetNthImageID 
"GetNthImageID: Return the id of the nth image (number from 0). The images are in no 
particular order.";
long GetNthImageID( long n );

%feature("docstring") GetNumber 
"GetNumber: Puts up a dialog with the given prompt and allows the user to enter a number. 
The initial value is passed as a parameter and the result in stored in result. Returns 1 
for OK and 0 for Cancel.";
bool GetNumber( const char *prompt, float initalValue, float *result );

%feature("docstring") GetOneImage 
"GetOneImage: Puts up a dialog and allows the user to choose an image.  Returns 1 for Ok 
and 0 for Cancel.";
bool GetOneImage( const char *title, Image &image1 );

%feature("docstring") GetOneImageWithPrompt 
"GetOneImageWithPrompt: Puts up a dialog and allows the user to choose an image.  Returns 
1 for Ok and 0 for Cancel.";
bool GetOneImageWithPrompt( const char *prompt, const char *title, Image &image1 );

%feature("docstring") GetOneLabeledImageWithPrompt 
"GetOneLabeledImageWithPrompt: Puts up a dialog and allows the user to choose an image.  
Returns 1 for Ok and 0 for Cancel.";
bool GetOneLabeledImageWithPrompt( const char *prompt, const char *title, const char *label1, Image &image1 );

%feature("docstring") GetOrigin 
"GetOrigin: Store the origin of image into the x and y variables. The origin is in the 
same units as scale.";
void GetOrigin( const Image &argument_1, float *x, float *y );

%feature("docstring") GetOSTickCount 
"GetOSTickCount: Return a tick count appropriate for the operating system.";
uint32 GetOSTickCount( );

%feature("docstring") GetOSTicksPerSecond 
"GetOSTicksPerSecond: Return the number of ticks per second of a tick count appropriate 
for the operating system.";
uint32 GetOSTicksPerSecond( );

%feature("docstring") GetPackageTags 
"GetPackageTags: Return the tags specified by identifier. The identifier is used to 
identify tags loaded with a specific package.";
TagGroup GetPackageTags( const char *identifier );

%feature("docstring") GetPersistentTagGroup 
"GetPersistentTagGroup: Gets the persistent tag group.";
TagGroup GetPersistentTagGroup( );

%feature("docstring") GetUserPersistentTagGroup 
"GetPersistentTagGroup: Gets the persistent tag group.";
TagGroup GetUserPersistentTagGroup( );

%feature("docstring") GetPixel 
"GetPixel: Gets the value of the pixel in the image at [x,y].";
double GetPixel( const Image &argument_1, long x, long y );

%feature("docstring") GetPlatformInfo 
"GetPlatformInfo: Return platform info. info=1 is general platform (1=MacOS,2=Win32,3=Windows64).";
long GetPlatformInfo( long info );

%feature("docstring") GetRawSize 
"GetRawSize: Return the total size of the image data of the image.";
long GetRawSize( const Image &argument_1 );

%feature("docstring") GetRawStreamPos 
"GetRawStreamPos: Store the current position in rawStream into the pos variable.";
void GetRawStreamPos( long rawStream, long *pos );

%feature("docstring") GetRawStreamSize 
"GetRawStreamSize: Store the length of rawStream into the size variable.";
void GetRawStreamSize( long rawStream, long *size );

%feature("docstring") GetResultsWindow 
"GetResultsWindow: Gets the results window.  If the window is not open, and 'open' is 
true, the results window is opened.";
Window GetResultsWindow( bool open );

%feature("docstring") GetROIFromID 
"GetROIFromID: Returns the region of interest associated with the ID or NULL if it does 
not exist.";
ROI GetROIFromID( long id );

%feature("docstring") GetScale 
"GetScale: Store the scale of image into the x and y variables.";
void GetScale( const Image &argument_1, float *x, float *y );

%feature("docstring") GetScreenSize 
"GetScreenSize: Store the size of the screen into the width and height variables.";
void GetScreenSize( long *width, long *height );

%feature("docstring") GetScriptObjectFromID 
"GetScriptObjectFromID: Returns the script object associated with the ID or NULL if the 
object does not exist.";
ScriptObject GetScriptObjectFromID( long id );

%feature("docstring") GetSelection 
"GetSelection: Stores the coordinates (in pixels) of the image's selection into the top, 
left, bottom, and right variables. Returns 1 if there was a selection and 0 if there 
wasn't.";
bool GetSelection( const Image &argument_1, long *top, long *left, long *bottom, long *right );

%feature("docstring") GetSize 
"GetSize: Store the width and height of the 2D image into the width and height variables.";
void GetSize( const Image &argument_1, long *width, long *height );

%feature("docstring") GetSpecialDirectory 
"GetSpecialDirectory: Return one of the special directories. 0=current directory, 
1=executable directory.";
String GetSpecialDirectory( long index );

%feature("docstring") GetSpecialWindow 
"GetSpecialWindow: Return one of the special windows. On Windows, 0=frame window, 
1=top-most dialog.";
long GetSpecialWindow( long index );

%feature("docstring") GetString 
"GetString: Puts up a dialog with the given prompt and allows the user to enter a string. 
The initial value is passed as a parameter and the result in stored in result. Returns 1 
for OK and 0 for Cancel.";
bool GetString( const char *prompt, const char *initalValue, char *result );

%feature("docstring") GetSurvey 
"GetSurvey: Return 1 if the survey is on; return 0 otherwise.";
bool GetSurvey( const Image &argument_1 );

%feature("docstring") GetThreeImages 
"GetThreeImages: Puts up a dialog and allows the user to choose three images.  Returns 1 
for Ok and 0 for Cancel.";
bool GetThreeImages( const char *title, Image &image1, Image &image2, Image &image3 );

%feature("docstring") GetThreeImagesWithPrompt 
"GetThreeImagesWithPrompt: Puts up a dialog with the given prompt and allows the user to 
choose three images.  Returns 1 for Ok and 0 for Cancel.";
bool GetThreeImagesWithPrompt( const char *prompt, const char *title, Image &image1, Image &image2, Image &image3 );

%feature("docstring") GetThreeLabeledImagesWithPrompt 
"GetThreeLabeledImagesWithPrompt: Puts up a dialog with the given prompt and allows the 
user to choose three images.  Returns 1 for Ok and 0 for Cancel.";
bool GetThreeLabeledImagesWithPrompt( const char *prompt, const char *title, const char *label1, Image &image1, const char *label2, Image &image2, const char *label3, Image &image3 );

%feature("docstring") GetTicks 
"GetTicks: Return the MacOS system tick count.";
uint32 GetTicks( );

%feature("docstring") GetTicksPerSecond 
"GetTicksPerSecond: Return the number of ticks per second.";
uint32 GetTicksPerSecond( );

%feature("docstring") GetTime 
"GetTime: Return a string representing the current time with or without seconds as 
indicated by the wantSeconds parameter.";
void GetTime( bool wantSeconds, char *buffer, long buffer_length );

%feature("docstring") GetTwoImages 
"GetTwoImages: Puts up a dialog and allows the user to choose two images.  Returns 1 for 
Ok and 0 for Cancel.";
bool GetTwoImages( const char *title, Image &image1, Image &image2 );

%feature("docstring") GetTwoImagesWithPrompt 
"GetTwoImagesWithPrompt: Puts up a dialog with the given prompt and allows the user to 
choose two images.  Returns 1 for Ok and 0 for Cancel.";
bool GetTwoImagesWithPrompt( const char *prompt, const char *title, Image &image1, Image &image2 );

%feature("docstring") GetTwoLabeledImagesWithPrompt 
"GetTwoLabeledImagesWithPrompt: Puts up a dialog with the given prompt and allows the 
user to choose two images.  Returns 1 for Ok and 0 for Cancel.";
bool GetTwoLabeledImagesWithPrompt( const char *prompt, const char *title, const char *label1, Image &image1, const char *label2, Image &image2 );

%feature("docstring") GetUnitsH 
"GetUnitsH: Return the horizontal pixels x in calibrated units.";
float GetUnitsH( const Image &argument_1, float x );

%feature("docstring") GetUnitString 
"GetUnitString: Copies the unit string of the image into the buffer.";
void GetUnitString( const Image &argument_1, char *buffer );

%feature("docstring") GetUnitsV 
"GetUnitsV: Return the vertical pixels y in calibrated units.";
float GetUnitsV( const Image &argument_1, float y );

%feature("docstring") GetVarianceFloat 
"GetVarianceFloat: Return the variance of the image. No data type checking is 
performed.";
float GetVarianceFloat( const Image &argument_1 );

%feature("docstring") GetWindowPosition 
"GetWindowPosition: Store the image's image document window position into the xPos and 
yPos variables.";
void GetWindowPosition( const Image &argument_1, long *xPos, long *yPos );

%feature("docstring") GetWindowSize 
"GetWindowSize: Store the image's image document window size into the width and height 
variables.";
void GetWindowSize( const Image &argument_1, long *width, long *height );

%feature("docstring") GetZoom 
"GetZoom: Return the zoom of the image display.";
float GetZoom( const Image &argument_1 );

%feature("docstring") GrabSemaphore 
"GrabSemaphore: Grab the semaphore. Block until it is available. Used only with 
background processing.";
void GrabSemaphore( long argument_1 );

%feature("docstring") GroupAnnotationUngroup 
"GroupAnnotationUngroup: Ungroups the group annotation.";
void GroupAnnotationUngroup( const Component &comp );

%feature("docstring") HasAcquisitionDaemon 
"HasAcquisitionDaemon: Returns 1 if the image has an attached daemon and returns 0 
otherwise.";
bool HasAcquisitionDaemon( const Image &argument_1 );

%feature("docstring") HideImage 
"HideImage: Hide the image's image document.";
void HideImage( const Image &argument_1 );

%feature("docstring") IFFT 
"IFFT: Creates a new complex 8-byte image from the inverse FFT of the complex image 
source.";
Image IFFT( const Image &source );

%feature("docstring") ImageCalculateHistogram 
"ImageCalculateHistogram: Calculates the histogram of 'image', mapping [min,max] into 
'hist_image'.";
void ImageCalculateHistogram( const Image &image, const Image &hist_image, long complexMode, float min, float max );

%feature("docstring") ImageCalculateMinMax 
"ImageCalculateMinMax: Calculates the minimum and maximum value of 'image' using survey 
technique 'surveyTechnique'.";
void ImageCalculateMinMax( const Image &image, long surveyTechnique, long complexMode, float *min, float *max );

%feature("docstring") ImageClone 
"ImageClone: Returns a clone of 'img'.";
Image ImageClone( const Image &img );

%feature("docstring") ImageCopyCalibrationFrom 
"ImageCopyCalibrationFrom: Copy the calibration of 'src_image' to 'image'.";
void ImageCopyCalibrationFrom( const Image &image, const Image &src_image );

%feature("docstring") ImageCountImageDisplays 
"ImageCountImageDisplays: Returns the number of image displays in which this image is 
displayed.";
long ImageCountImageDisplays( const Image &argument_1 );

%feature("docstring") ImageCountImageDisplaysInImageDocument 
"ImageCountImageDisplaysInImageDocument: Returns the number of image displays in the 
image document in which this image is displayed.";
long ImageCountImageDisplaysInImageDocument( const Image &argument_1, const ImageDocument &imgDoc );

%feature("docstring") ImageCreateImageDisplay 
"ImageCreateImageDisplay: Creates a new image display of type 'displayType' for the image.";
ImageDisplay ImageCreateImageDisplay( const Image &argument_1, long displayType );

%feature("docstring") ImageDataChanged 
"ImageDataChanged: Signal that the data of the image has changed.";
void ImageDataChanged( const Image &argument_1 );

%feature("docstring") ImageDisplayAccumulateROIsToMask 
"ImageDisplayAccumulateROIsToMask: Sets mask to mask_val at points in imageDisplay's rois";
void ImageDisplayAccumulateROIsToMask( const ImageDisplay &imgDisp, const Image &mask, float top, float left, float bottom, float right, float mask_val );

%feature("docstring") ImageDisplayAddKeyListener 
"ImageDisplayAddKeyListener: Adds the listener_script to the key listener list under the 
tag listener_key.";
void ImageDisplayAddKeyListener( const ImageDisplay &imgDisp, const char *listener_key, const char *listener_script, const char *client_id );

%feature("docstring") ImageDisplayAddROI 
"ImageDisplayAddROI: Adds the roi to this image display.";
void ImageDisplayAddROI( const ImageDisplay &imgDisp, const ROI &roi );

%feature("docstring") ImageDisplayAddROIAtBeginning 
"ImageDisplayAddROIAtBeginning: Adds the roi to the start of this image displays ROI list.";
void ImageDisplayAddROIAtBeginning( const ImageDisplay &imgDisp, const ROI &roi );

%feature("docstring") ImageDisplayAddROIAtEnd 
"ImageDisplayAddROIAtEnd: Adds the roi to the end of this image displays ROI list.";
void ImageDisplayAddROIAtEnd( const ImageDisplay &imgDisp, const ROI &roi );

%feature("docstring") ImageDisplayChangeDisplayType 
"ImageDisplayChangeDisplayType: Changes the type of the image display.";
void ImageDisplayChangeDisplayType( const ImageDisplay &imgDisp, long new_type );

%feature("docstring") ImageDisplayCountROIs 
"ImageDisplayCountROIs: Returns the number of ROIs on this image display.";
long ImageDisplayCountROIs( const ImageDisplay &imgDisp );

%feature("docstring") ImageDisplayDeleteROI 
"ImageDisplayDeleteROI: Deletes the roi from this image display.";
void ImageDisplayDeleteROI( const ImageDisplay &imgDisp, const ROI &roi );

%feature("docstring") ImageDisplayDoesROIExist 
"ImageDisplayDoesROIExist: Determines whether the given ROI exists on this image display.";
bool ImageDisplayDoesROIExist( const ImageDisplay &imgDisp, const char *name );

%feature("docstring") ImageDisplayExportToFile 
"ImageDisplayExportToFile: Exports the display to the file 'file_name' using the format 
'format'.";
void ImageDisplayExportToFile( const ImageDisplay &imgDisp, const String &format, const String &file_name );

%feature("docstring") ImageDisplayGetBufferedImage 
"ImageDisplayGetBufferedImage: Gets the image resulting from the contrast transformation.";
Image ImageDisplayGetBufferedImage( const ImageDisplay &imgDisp );

%feature("docstring") ImageDisplayGetComplexMode 
"ImageDisplayGetComplexMode: Gets the complex mode of the display.";
long ImageDisplayGetComplexMode( const ImageDisplay &imgDisp );

%feature("docstring") ImageDisplayGetComplexModeRange 
"ImageDisplayGetComplexModeRange: Gets the parameter used in converting complex to real.";
float ImageDisplayGetComplexModeRange( const ImageDisplay &imgDisp );

%feature("docstring") ImageDisplayGetContrastLimits 
"ImageDisplayGetContrastLimits: Gets the contrast limits of the display.";
void ImageDisplayGetContrastLimits( const ImageDisplay &imgDisp, float *low, float *high );

%feature("docstring") ImageDisplayGetOutlierTrimLimits 
"ImageDisplayGetOutlierTrimLimits: Gets the outlier limits of the display.";
void ImageDisplayGetOutlierTrimLimits( const ImageDisplay &imgDisp, double* low, double* high );

%feature("docstring") ImageDisplayGetContrastChangeTriggerFractions 
"ImageDisplaySetContrastChangeTriggerFractions: Sets the contrast change % limits of the display.";
void ImageDisplayGetContrastChangeTriggerFractions( const ImageDisplay &imgDisp, double* low, double* high );

%feature("docstring") ImageDisplayGetContrastMode 
"ImageDisplayGetContrastMode: Returns the contrast mode.";
long ImageDisplayGetContrastMode( const ImageDisplay &imgDisp );

%feature("docstring") ImageDisplayGetContrastParameters 
"ImageDisplayGetContrastParameters: Gets the parameters for the contrast mode.";
void ImageDisplayGetContrastParameters( const ImageDisplay &imgDisp, float *bright, float *contrast );

%feature("docstring") ImageDisplayGetDisplayedImage 
"ImageDisplayGetDisplayedImage: Gets the image that is actually displayed in the image 
display.";
Image ImageDisplayGetDisplayedImage( const ImageDisplay &imgDisp );

%feature("docstring") ImageDisplayGetDisplayedLayers 
"ImageDisplayGetDisplayedLayers: Gets the layers that are summed into the display.";
void ImageDisplayGetDisplayedLayers( const ImageDisplay &imgDisp, long *start, long *end );

%feature("docstring") ImageDisplayGetDisplayedLayers 
"ImageDisplayGetDisplayedLayers: Gets the layers that are summed into the display (4D case).";
void ImageDisplayGetDisplayedLayers( const ImageDisplay &imgDisp, long *start1, long *end1, long *start2, long *end2);

%feature("docstring") ImageDisplayGetDisplayType 
"ImageDisplayGetDisplayType: Returns type of the image display.";
long ImageDisplayGetDisplayType( const ImageDisplay &imgDisp );

%feature("docstring") ImageDisplayGetDoAutoSurvey 
"ImageDisplayGetDoAutoSurvey: Determines whether min and max are determined automatically.";
bool ImageDisplayGetDoAutoSurvey( const ImageDisplay &imgDisp );

%feature("docstring") ImageDisplayGetExportImage 
"ImageDisplayGetExportImage: Gets the image representation of the image as it appears on 
the screen at full resolution.";
Image ImageDisplayGetExportImage( const ImageDisplay &imgDisp, ulong mode, ImageDisplay &clut_display );

%feature("docstring") ImageDisplayGetImage 
"ImageDisplayGetImage: Returns the single image displayed by the image display.";
Image ImageDisplayGetImage( const ImageDisplay &imgDisp );

%feature("docstring") ImageDisplayGetImageAdjustRect 
"ImageDisplayGetImageAdjustRect: Returns the image display outside the image rect";
void ImageDisplayGetImageAdjustRect( const ImageDisplay &imgDisp, float *top, float *left, float *bottom, float *right );

%feature("docstring") ImageDisplayGetImageAdjustRectInView 
"ImageDisplayGetImageAdjustRectInView: Returns the image display outside the image rect 
in view coordinates";
void ImageDisplayGetImageAdjustRectInView( const ImageDisplay &imgDisp, float *top, float *left, float *bottom, float *right );

%feature("docstring") ImageDisplayGetImageRect 
"ImageDisplayGetImageRect: Gets the bounds of the image in the image display.";
void ImageDisplayGetImageRect( const ImageDisplay &imgDisp, float *top, float *left, float *bottom, float *right );

%feature("docstring") ImageDisplayGetImageRectInView 
"ImageDisplayGetImageRectInView: Gets the bounds of the image in the image display in 
view coordinates.";
void ImageDisplayGetImageRectInView( const ImageDisplay &imgDisp, float *top, float *left, float *bottom, float *right );

%feature("docstring") ImageDisplayGetInputColorTable 
"ImageDisplayGetInputColorTable: Gets the input color table for the display.";
Image ImageDisplayGetInputColorTable( const ImageDisplay &imgDisp );

%feature("docstring") ImageDisplayGetIntensityTransformation 
"ImageDisplayGetIntensityTransformation: Gets the ITT of the display.";
Image ImageDisplayGetIntensityTransformation( const ImageDisplay &imgDisp );

%feature("docstring") ImageDisplayIsColorTableInverted 
"ImageDisplayIsColorTableInverted: Returns true if the color table is inverted.";
bool ImageDisplayIsColorTableInverted( const ImageDisplay &imgDisp );

%feature("docstring") ImageDisplayGetMinimumContrast 
"ImageDisplayGetMinimumContrast: Gets the minimum contrast of the display.";
float ImageDisplayGetMinimumContrast( const ImageDisplay &imgDisp );

%feature("docstring") ImageDisplayGetOutputColorTable 
"ImageDisplayGetOutputColorTable: Gets the output color table for the display.";
Image ImageDisplayGetOutputColorTable( const ImageDisplay &imgDisp );

%feature("docstring") ImageDisplayGetROI 
"ImageDisplayGetROI: Returns the given ROI on this image display.";
ROI ImageDisplayGetROI( const ImageDisplay &imgDisp, long index );

%feature("docstring") ImageDisplayGetROISelectionStyle 
"ImageDisplayGetROISelectionStyle: Gets the selection style of the roi in the imag 
display.";
long ImageDisplayGetROISelectionStyle( const ImageDisplay &imgDisp, const ROI &r );

%feature("docstring") ImageDisplayGetShowExtractionAnnotation 
"ImageDisplayGetShowExtractionAnnotation: Returns true if extraction annotation should be displayed.";
bool ImageDisplayGetShowExtractionAnnotation( const ImageDisplay &imgDisp );

%feature("docstring") ImageDisplayGetSurveyTechnique 
"ImageDisplayGetSurveyTechnique: Gets the survey technique of the display.";
long ImageDisplayGetSurveyTechnique( const ImageDisplay &imgDisp );

%feature("docstring") ImageDisplayIsCaptionOn 
"ImageDisplayIsCaptionOn: Returns true if captions are drawn.";
bool ImageDisplayIsCaptionOn( const ImageDisplay &imgDisp );

%feature("docstring") ImageDisplayIsROISelected 
"ImageDisplayIsROISelected: Determines whether the given ROI is selected on this image 
display.";
bool ImageDisplayIsROISelected( const ImageDisplay &imgDisp, const ROI &roi );

%feature("docstring") ImageDisplayIsValid 
"ImageDisplayIsValid: Returns true if 'imageDisplay' points to a valid object.";
bool ImageDisplayIsValid( const ImageDisplay &imgDisp );

%feature("docstring") ImageDisplayLookupROI 
"ImageDisplayLookupROI: Returns the given ROI on this image display.";
ROI ImageDisplayLookupROI( const ImageDisplay &imgDisp, const char *name );

%feature("docstring") ImageDisplayLookupROIByID 
"ImageDisplayLookupROIByID: Returns the ROI with the given id on this image display.";
ROI ImageDisplayLookupROIByID( const ImageDisplay &imgDisp, long id );

%feature("docstring") ImageDisplayRemoveKeyListener 
"ImageDisplayRemoveKeyListener: Removes the listener script with the tag listener_key 
from the key listener list.";
void ImageDisplayRemoveKeyListener( const ImageDisplay &imgDisp, const char *listener_key );

%feature("docstring") ImageDisplaySetCaptionOn 
"ImageDisplaySetCaptionOn: Sets whether to draw captions.";
void ImageDisplaySetCaptionOn( const ImageDisplay &imgDisp, bool on );

%feature("docstring") ImageDisplaySetComplexMode 
"ImageDisplaySetComplexMode: Sets the complex mode of the display.";
void ImageDisplaySetComplexMode( const ImageDisplay &imgDisp, long mode );

%feature("docstring") ImageDisplaySetComplexModeRange 
"ImageDisplaySetComplexModeRange: Sets the parameter used in converting complex to real.";
void ImageDisplaySetComplexModeRange( const ImageDisplay &imgDisp, float range );

%feature("docstring") ImageDisplaySetContrastLimits 
"ImageDisplaySetContrastLimits: Sets the contrast limits of the display.";
void ImageDisplaySetContrastLimits( const ImageDisplay &imgDisp, float low, float hight );

%feature("docstring") ImageDisplaySetOutlierTrimLimits 
"ImageDisplaySetOutlierTrimLimits: Sets the outlier limits of the display.";
void ImageDisplaySetOutlierTrimLimits( const ImageDisplay &imgDisp, double low, double high );

%feature("docstring") ImageDisplaySetContrastChangeTriggerFractions 
"ImageDisplaySetContrastChangeTriggerFractions: Sets the contrast change % limits of the display.";
void ImageDisplaySetContrastChangeTriggerFractions( const ImageDisplay &imgDisp, double low, double high );

%feature("docstring") ImageDisplaySetContrastMode 
"ImageDisplaySetContrastMode: Sets the contrast mode.";
void ImageDisplaySetContrastMode( const ImageDisplay &imgDisp, long mode );

%feature("docstring") ImageDisplaySetContrastParameters 
"ImageDisplaySetContrastParameters: Gets the parameters for the contrast mode.";
void ImageDisplaySetContrastParameters( const ImageDisplay &imgDisp, float bright, float contrast );

%feature("docstring") ImageDisplaySetDisplayedLayers 
"ImageDisplaySetDisplayedLayers: Sets the layers that are summed into the display.";
void ImageDisplaySetDisplayedLayers( const ImageDisplay &imgDisp, long start, long end );

%feature("docstring") ImageDisplaySetDisplayedLayers 
"ImageDisplaySetDisplayedLayers: Sets the layers that are summed into the display (4D case).";
void ImageDisplaySetDisplayedLayers( const ImageDisplay &imgDisp, long start1, long end1, long start2, long end2);

%feature("docstring") ImageDisplaySetDoAutoSurvey 
"ImageDisplaySetDoAutoSurvey: Sets whether min and max are determined automatically.";
void ImageDisplaySetDoAutoSurvey( const ImageDisplay &imgDisp, bool do_survey );

%feature("docstring") ImageDisplaySetImageRect 
"ImageDisplaySetImageRect: Sets the bounds of the image part of the image display.";
void ImageDisplaySetImageRect( const ImageDisplay &imgDisp, float top, float left, float bottom, float right );

%feature("docstring") ImageDisplaySetInputColorTable 
"ImageDisplaySetInputColorTable: Sets the input color table of the display.";
void ImageDisplaySetInputColorTable( const ImageDisplay &imgDisp, const Image &clut );

%feature("docstring") ImageDisplaySetIntensityTransformation 
"ImageDisplaySetIntensityTransformation: Sets the ITT of the display.";
void ImageDisplaySetIntensityTransformation( const ImageDisplay &imgDisp, const Image &itt );

%feature("docstring") ImageDisplaySetMinimumContrast 
"ImageDisplaySetMinimumContrast: Sets the minimum contrast of the display.";
void ImageDisplaySetMinimumContrast( const ImageDisplay &imgDisp, float contrast );

%feature("docstring") ImageDisplaySetROISelected 
"ImageDisplaySetROISelected: Sets the selection status of the region of interest in the 
image display.";
void ImageDisplaySetROISelected( const ImageDisplay &imgDisp, const ROI &roi, bool select );

%feature("docstring") ImageDisplaySetROISelectionStyle 
"ImageDisplaySetROISelectionStyle: Sets the selection style of the roi in the imag 
display.";
void ImageDisplaySetROISelectionStyle( const ImageDisplay &imgDisp, const ROI &r, long style );

%feature("docstring") ImageDisplaySetShowExtractionAnnotation 
"ImageDisplaySetShowExtractionAnnotation: Sets if extraction annotation should be displayed.";
void ImageDisplaySetShowExtractionAnnotation( const ImageDisplay &imgDisp, bool show);

%feature("docstring") ImageDisplaySetSurveyTechnique 
"ImageDisplaySetSurveyTechnique: Sets the survey technique of the display.";
void ImageDisplaySetSurveyTechnique( const ImageDisplay &imgDisp, long tech );

%feature("docstring") ImageDocumentAddImage 
"ImageDocumentAddImage: Adds the given image to the list maintained in the image document.";
void ImageDocumentAddImage( const ImageDocument &imgDoc, const Image &image );

%feature("docstring") ImageDocumentAddImageDisplay 
"ImageDocumentAddImageDisplay: Adds the given image and an image display for it of the 
given type.";
ImageDisplay ImageDocumentAddImageDisplay( const ImageDocument &imgDoc, const Image &image, long displayType );

%feature("docstring") ImageDocumentAddToUserInterface 
"ImageDocumentAddToUserInterface: Places the image document in the list of user interface 
documents.";
void ImageDocumentAddToUserInterface( const ImageDocument &imgDoc );

%feature("docstring") ImageDocumentClean 
"ImageDocumentClean: Marks the image document as clean (doesn't need to be saved).";
void ImageDocumentClean( const ImageDocument &imgDoc );

%feature("docstring") ImageDocumentClone 
"ImageDocumentClone: Returns a duplicate of the image docuemnt, creating a copy of its 
images if 'doDeepCopy' is true.";
ImageDocument ImageDocumentClone( const ImageDocument &imgDoc, bool doDeepCopy );

%feature("docstring") ImageDocumentClose 
"ImageDocumentClose: Closes the given image document. If saving is true then asks whether 
to save it, otherwise just closes it.";
void ImageDocumentClose( const ImageDocument &imgDoc, bool saving );

%feature("docstring") ImageDocumentCountImages 
"ImageDocumentCountImages: Returns the number of images contained in this image document.";
long ImageDocumentCountImages( const ImageDocument &imgDoc );

%feature("docstring") ImageDocumentCreateRGBImageFromDocument 
"ImageDocumentCreateRGBImageFromDocument: Creates an image by scaling the image document 
into ( width, height ).";
Image ImageDocumentCreateRGBImageFromDocument( const ImageDocument &imgDoc, long width, long height, long extract_style, long constraints );

%feature("docstring") ImageDocumentDeleteImage 
"ImageDocumentDeleteImage: Deletes the given image from this image document.";
void ImageDocumentDeleteImage( const ImageDocument &imgDoc, const Image &image );

%feature("docstring") ImageDocumentDoesImageWithIDExist 
"ImageDocumentDoesImageWithIDExist: Determines whether the image with the given id exists 
within this image document.";
bool ImageDocumentDoesImageWithIDExist( const ImageDocument &imgDoc, long id );

%feature("docstring") ImageDocumentEnsurePlacedOnPage 
"ImageDocumentEnsurePlacedOnPage: Makes sure the document has been layed out on the 
physical page.";
void ImageDocumentEnsurePlacedOnPage( const ImageDocument &imgDoc );

%feature("docstring") ImageDocumentGetAsPICT 
"ImageDocumentGetAsPICT: Returns this image as a PICT.";
long ImageDocumentGetAsPICT( const ImageDocument &imgDoc );

%feature("docstring") ImageDocumentGetComponentByID 
"ImageDocumentGetComponentByID: Returns an annotation contained in this image document by 
id.";
Component ImageDocumentGetComponentByID( const ImageDocument &imgDoc, long id );

%feature("docstring") ImageDocumentGetDrawMarginsInPageMode 
"ImageDocumentGetDrawMarginsInPageMode: returns true if the paper margins are drawn for documents
in page mode, false otherwise.";
bool ImageDocumentGetDrawMarginsInPageMode( const ImageDocument &imgDoc );

%feature("docstring") ImageDocumentGetDrawPaperInPageMode 
"ImageDocumentGetDrawPaperInPageMode: returns true if the paper is drawn for documents in page
 mode, false otherwise.";
bool ImageDocumentGetDrawPaperInPageMode( const ImageDocument &imgDoc );

%feature("docstring") ImageDocumentGetFixedWindowSize 
"ImageDocumentGetFixedWindowSize: Returns values of width and height for image documents with
fixed size.";
void ImageDocumentGetFixedWindowSize( const ImageDocument &img_doc, double *width, double *height );

%feature("docstring") ImageDocumentGetID 
"ImageDocumentGetID: Gets the id of the image document.";
long ImageDocumentGetID( const ImageDocument &imgDoc );

%feature("docstring") ImageDocumentGetImage 
"ImageDocumentGetImage: Returns the image contained within this image document by 
position.";
Image ImageDocumentGetImage( const ImageDocument &imgDoc, long position );

%feature("docstring") ImageDocumentGetImageByID 
"ImageDocumentGetImageByID: Returns an image contained in this image document by id.";
Image ImageDocumentGetImageByID( const ImageDocument &imgDoc, long id );

%feature("docstring") ImageDocumentGetImageModeDisplay 
"ImageDocumentGetImageModeDisplay: Gets the image display targeted by the current image 
mode.";
ImageDisplay ImageDocumentGetImageModeDisplay( const ImageDocument &imgDoc );

%feature("docstring") ImageDocumentGetMinimumPointSize 
"ImageDocumentGetMinimumPointSize: Gets the size of the minimum point in view coordinates.";
void ImageDocumentGetMinimumPointSize( const ImageDocument &imgDoc, float *x, float *y );

%feature("docstring") ImageDocumentGetName 
"ImageDocumentGetName: Returns the name of the image document.";
String ImageDocumentGetName( const ImageDocument &imgDoc );

%feature("docstring") ImageDocumentGetOrientation 
"ImageDocumentGetOrientation: Get document orientation, 0: portrait, 1: landscape";
uint32 ImageDocumentGetOrientation( const ImageDocument &imgDoc );

%feature("docstring") ImageDocumentGetPageBounds 
"ImageDocumentGetPageBounds: Gets the page bounds of the document in page coordinates.";
void ImageDocumentGetPageBounds( const ImageDocument &imgDoc, float *top, float *left, float *bottom, float *right );

%feature("docstring") ImageDocumentGetPageResolution_72dpi 
"ImageDocumentGetPageResolution_72dpi: Returns the resolution of page coordinates in 72 
dots per inch ( returns page units per dot ).";
void ImageDocumentGetPageResolution_72dpi( const ImageDocument &imgDoc, float *horz, float *vert );

%feature("docstring") ImageDocumentGetPageResolution_Printer 
"ImageDocumentGetPageResolution_Printer: Returns the resolution of page coordinates in 
printer pixels ( returns page units per printer pixel ).";
void ImageDocumentGetPageResolution_Printer( const ImageDocument &imgDoc, float *horz, float *vert );

%feature("docstring") ImageDocumentGetPaperBounds 
"ImageDocumentGetPaperBounds: Gets the paper bounds of the document in page coordinates.";
void ImageDocumentGetPaperBounds( const ImageDocument &imgDoc, float *top, float *left, float *bottom, float *right );

%feature("docstring") ImageDocumentGetPreferredViewRect 
"ImageDocumentGetPreferredViewRect: Gets rectangle in view coordinates of the area that 
is by default displayed in this mode.";
void ImageDocumentGetPreferredViewRect( const ImageDocument &imgDoc, float *top, float *left, float *bottom, float *right );

%feature("docstring") ImageDocumentGetReferencePointSize 
"ImageDocumentGetReferencePointSize: Gets the size of the reference point in view 
coordinates.";
void ImageDocumentGetReferencePointSize( const ImageDocument &imgDoc, float *x, float *y );

%feature("docstring") ImageDocumentGetRootComponent 
"ImageDocumentGetRootComponent: Gets the root annotation of the image document.";
Component ImageDocumentGetRootComponent( const ImageDocument &imgDoc );

%feature("docstring") ImageDocumentGetTagGroup 
"ImageDocumentGetTagGroup: Gets the tag group associated with the image document.";
TagGroup ImageDocumentGetTagGroup( const ImageDocument &imgDoc );

%feature("docstring") ImageDocumentGetUnzoomedPointSize 
"ImageDocumentGetUnzoomedPointSize: Gets the size of the unzoomed point in view 
coordinates.";
void ImageDocumentGetUnzoomedPointSize( const ImageDocument &imgDoc, float *x, float *y );

%feature("docstring") ImageDocumentGetViewExtent 
"ImageDocumentGetViewExtent: Gets the extent in view coordinates of the items visible in 
the current view mode.";
void ImageDocumentGetViewExtent( const ImageDocument &imgDoc, float *top, float *left, float *bottom, float *right );

%feature("docstring") ImageDocumentGetViewToWindowTransform 
"ImageDocumentGetViewToWindowTransform: Returns the transformation from view to screen 
coordinates.";
void ImageDocumentGetViewToWindowTransform( const ImageDocument &imgDoc, float *off_x, float *off_y, float *scale_x, float *scale_y );

%feature("docstring") ImageDocumentGetVisibleViewRect 
"ImageDocumentGetVisibleViewRect: Gets the view coordinates of the rectangle visible in 
the view.";
void ImageDocumentGetVisibleViewRect( const ImageDocument &imgDoc, float *top, float *left, float *bottom, float *right );

%feature("docstring") ImageDocumentGetWindow 
"ImageDocumentGetWindow: Returns the window displaying the document.";
Window ImageDocumentGetWindow( const ImageDocument &imgDoc );

%feature("docstring") ImageDocumentHasBeenPlacedOnPage 
"ImageDocumentHasBeenPlacedOnPage: Returns 'true' if the document has been layed out 
within the physical page.";
bool ImageDocumentHasBeenPlacedOnPage( const ImageDocument &imgDoc );

%feature("docstring") ImageDocumentHasFixedWindowSize 
"ImageDocumentHasFixedWindowSize: Returns true if the image document is not resizable. This means
the window has a fixed, nonresizable frame and attempts to resize the window will fail.";
bool ImageDocumentHasFixedWindowSize( const ImageDocument &img_doc );

%feature("docstring") ImageDocumentHide 
"ImageDocumentHide: Hides the given image document.";
void ImageDocumentHide( const ImageDocument &imgDoc );

%feature("docstring") ImageDocumentIsDirty 
"ImageDocumentIsDirty: Returns true if the document has changed since last saving it.";
bool ImageDocumentIsDirty( const ImageDocument &img_doc );

%feature("docstring") ImageDocumentIsInImageMode 
"ImageDocumentIsInImageMode: Returns true if the view of the document is in image mode.";
bool ImageDocumentIsInImageMode( const ImageDocument &imgDoc );

%feature("docstring") ImageDocumentIsInPageMode 
"ImageDocumentIsInPageMode: Returns true if the view of the document is in page mode.";
bool ImageDocumentIsInPageMode( const ImageDocument &imgDoc );

%feature("docstring") ImageDocumentIsLockedInPageMode 
"ImageDocumentIsLockedInPageMode: Returns true if the view of the document is always in page mode
and cannot be switched into image mode.";
bool ImageDocumentIsLockedInPageMode( const ImageDocument &img_doc );

%feature("docstring") ImageDocumentIsValid 
"ImageDocumentIsValid: Returns true if 'imageDocument' points to a valid object.";
bool ImageDocumentIsValid( const ImageDocument &imgDoc );

%feature("docstring") ImageDocumentLockInPageMode 
"ImageDocumentLockInPageMode: Locks/Unlocks image documents in page mode display. A document
which is locked in page mode cannot be displayed in image mode, unless the lock is cleared.";
bool ImageDocumentLockInPageMode( const ImageDocument &img_doc, bool lock );

%feature("docstring") ImageDocumentMaximizeRectInView 
"ImageDocumentMaximizeRectInView: Zooms the view so the rectangle is centered and maximal.";
void ImageDocumentMaximizeRectInView( const ImageDocument &imgDoc, float top, float left, float bottom, float right );

%feature("docstring") ImageDocumentPrint 
"ImageDocumentPrint: Print the image document, returning 'true' if successful.";
bool ImageDocumentPrint( const ImageDocument &imgDoc );

%feature("docstring") ImageDocumentRemoveFromUserInterface 
"ImageDocumentRemoveFromUserInterface: Removes the image document from the list of user 
interface documents.";
void ImageDocumentRemoveFromUserInterface( const ImageDocument &imgDoc );

%feature("docstring") ImageDocumentSaveToFile 
"ImageDocumentSaveToFile: Saves the image document to the given file name using the I/O 
handler specified.";
void ImageDocumentSaveToFile( const ImageDocument &imgDoc, const String &handler, const String &fileName );

%feature("docstring") ImageDocumentSaveToFile 
"ImageDocumentSaveToFile: Saves the image document to the given file name using the I/O 
handler specified and the saveType specified. saveType = 0 is the view, saveType = 1 is the data.";
void ImageDocumentSaveToFile( const ImageDocument &imgDoc, const String &handler, const String &fileName, const uint32 saveType );

%feature("docstring") ImageDocumentSetCurrentViewAsUnzoomed 
"ImageDocumentSetCurrentViewAsUnzoomed: Makes the current view the unzoomed view.";
void ImageDocumentSetCurrentViewAsUnzoomed( const ImageDocument &imgDoc );

%feature("docstring") ImageDocumentSetDoIntegralZoom 
"ImageDocumentSetDoIntegralZoom: Sets the integral zoom flag of the image document.";
void ImageDocumentSetDoIntegralZoom( const ImageDocument &imgDoc, bool do_integral_zoom );

%feature("docstring") ImageDocumentSetDrawMarginsInPageMode 
"ImageDocumentSetDrawMarginsInPageMode: Switches on/off drawing of paper margins for documents
in page mode.";
bool ImageDocumentSetDrawMarginsInPageMode( const ImageDocument &imgDoc, bool doDraw );

%feature("docstring") ImageDocumentSetDrawPaperInPageMode 
"ImageDocumentSetDrawPaperInPageMode: Switches on/off drawing of paper rectangle for documents
in page mode.";
bool ImageDocumentSetDrawPaperInPageMode( const ImageDocument &imgDoc, bool doDraw );

%feature("docstring") ImageDocumentSetFixedWindowSize 
"ImageDocumentSetFixedWindowSize: Sets width and height of an image document and the indication
that the image document should use those values as a fixed size for the displayed window. This
function should be used before the image document is displayed for the very first time.";
void ImageDocumentSetFixedWindowSize( const ImageDocument &img_doc, double width, double height );

%feature("docstring") ImageDocumentSetName 
"ImageDocumentSetName: Sets the name of the image document.";
void ImageDocumentSetName( const ImageDocument &imgDoc, const String &name );

%feature("docstring") ImageDocumentSetOrientation 
"ImageDocumentSetOrientation: Set document orientation, 0: portrait, 1: landscape. Function return
true if the orientation was changed, false if there was no change.";
bool ImageDocumentSetOrientation( const ImageDocument &imgDoc , uint32 orientation );

%feature("docstring") ImageDocumentSetRectInView 
"ImageDocumentSetRectInView: Zooms the view so the view rect (v_l,v_t,v_b,v_r) is 
displayed in the window rect (w_l,w_t,w_b,w_r).";
void ImageDocumentSetRectInView( const ImageDocument &imgDoc, float v_t, float v_l, float v_b, float v_r, float w_t, float w_l, float w_b, float w_r );

%feature("docstring") ImageDocumentShow 
"ImageDocumentShow: Shows the given image document.";
Window ImageDocumentShow( const ImageDocument &imgDoc );

%feature("docstring") ImageDocumentShowAtPosition 
"ImageDocumentShowAtPosition: Shows the given image document at the application position 
(x,y).";
Window ImageDocumentShowAtPosition( const ImageDocument &imgDoc, long x, long y );

%feature("docstring") ImageDocumentShowAtRect 
"ImageDocumentShowAtRect: Shows the given image document at the rect 
(top,left,bottom,right).";
Window ImageDocumentShowAtRect( const ImageDocument &imgDoc, long top, long left, long bottom, long right );

%feature("docstring") ImageDocumentSwitchToImageMode 
"ImageDocumentSwitchToImageMode: Switches the view of the document to image mode focused 
on the display 'imgDisp'.";
void ImageDocumentSwitchToImageMode( const ImageDocument &imgDoc, const ImageDisplay &imgDisp );

%feature("docstring") ImageDocumentSwitchToPageMode 
"ImageDocumentSwitchToPageMode: Switches the view of the document to page mode.";
void ImageDocumentSwitchToPageMode( const ImageDocument &imgDoc );

%feature("docstring") ImageDocumentUnsetFixedWindowSize 
"ImageDocumentUnsetFixedWindowSize: Unsets the indication that the image document will be displayed
with a fixed, nonresizable window size. Function should be used before an image document is
displayed for the very first time.";
void ImageDocumentUnsetFixedWindowSize( const ImageDocument &img_doc );

%feature("docstring") ImageDocumentUpdateDisplay 
"ImageDocumentUpdateDisplay: Updates the display of the image document.";
void ImageDocumentUpdateDisplay( const ImageDocument &imgDoc );

%feature("docstring") ImageGetDataElementBitSize 
"ImageGetDataElementBitSize: Returns the size of the data elements in bits.";
ulong ImageGetDataElementBitSize( const Image &img );

%feature("docstring") ImageGetDataElementByteSize 
"ImageGetDataElementByteSize: Returns the smallest number of bytes that can hold a data 
element.";
ulong ImageGetDataElementByteSize( const Image &img );

%feature("docstring") ImageGetDataSeed 
"ImageGetDataSeed: Gets the seed of the image data.";
ulong ImageGetDataSeed( const Image &img );

%feature("docstring") ImageGetDataType 
"ImageGetDataType: Returns a long representing the data type.";
ulong ImageGetDataType( const Image &img );

%feature("docstring") ImageGetDescriptionText 
"ImageGetDescriptionText: Gets the description text associated with the image.";
String ImageGetDescriptionText( const Image &img );

%feature("docstring") ImageGetDimensionCalibration 
"ImageGetDimensionCalibration: Gets the calibration information of the given dimension.";
void ImageGetDimensionCalibration( const Image &argument_1, long dimension, float *origin, float *scale, String &units, long calibrationFormat );

%feature("docstring") ImageGetDimensionOrigin 
"ImageGetDimensionOrigin: Returns the origin of the given dimension of image.";
float ImageGetDimensionOrigin( const Image &argument_1, long dimension );

%feature("docstring") ImageGetDimensionScale 
"ImageGetDimensionScale: Returns the scale of the given dimension of image.";
float ImageGetDimensionScale( const Image &argument_1, long dimension );

%feature("docstring") ImageGetDimensionSize 
"ImageGetDimensionSize: Gets the size of the given dimension.";
ulong ImageGetDimensionSize( const Image &argument_1, ulong dimension );

%feature("docstring") ImageGetDimensionUnitInfo 
"ImageGetDimensionUnitInfo: Copies the unit string of the given dimension of image to the 
buffer.";
void ImageGetDimensionUnitInfo( const Image &argument_1, long dimension, String &canon_units, long *power );

%feature("docstring") ImageGetDimensionUnitString 
"ImageGetDimensionUnitString: Copies the unit string of the given dimension of image to 
the buffer.";
String ImageGetDimensionUnitString( const Image &argument_1, long dimension );

%feature("docstring") ImageGetID 
"ImageGetID: Returns a unique identifier for the image.";
ulong ImageGetID( const Image &argument_1 );

%feature("docstring") ImageGetImageDisplay 
"ImageGetImageDisplay: Returns the given image display in which this image is displayed.";
ImageDisplay ImageGetImageDisplay( const Image &argument_1, long index );

%feature("docstring") ImageGetImageDisplayInImageDocument 
"ImageGetImageDisplayInImageDocument: Returns the given image display in the image 
document in which this image is displayed.";
ImageDisplay ImageGetImageDisplayInImageDocument( const Image &argument_1, const ImageDocument &imgDoc, long index );

%feature("docstring") ImageGetIntensityOrigin 
"ImageGetIntensityOrigin: Returns the origin of image's intensity.";
float ImageGetIntensityOrigin( const Image &argument_1 );

%feature("docstring") ImageGetIntensityScale 
"ImageGetIntensityScale: Returns the scale of image's intensity.";
float ImageGetIntensityScale( const Image &argument_1 );

%feature("docstring") ImageGetIntensityUnitInfo 
"ImageGetIntensityUnitInfo: Copies the unit string of image's intensity to the buffer.";
void ImageGetIntensityUnitInfo( const Image &argument_1, String &canon_units, long *power );

%feature("docstring") ImageGetIntensityUnitString 
"ImageGetIntensityUnitString: Returns the units of the image's intensity.";
String ImageGetIntensityUnitString( const Image &argument_1 );

%feature("docstring") ImageGetLabel 
"ImageGetLabel: Gets the label of the image as used in scripts.";
String ImageGetLabel( const Image &img );

%feature("docstring") ImageGetName 
"ImageGetName: Gets the name of the image.";
String ImageGetName( const Image &img );

%feature("docstring") ImageGetNumDimensions 
"ImageGetNumDimensions: Returns number of dimensions of the image.";
ulong ImageGetNumDimensions( const Image &argument_1 );

%feature("docstring") ImageGetOrCreateImageDocument 
"ImageGetOrCreateImageDocument: Returns an image document containing the image, creating 
one if necessary.";
ImageDocument ImageGetOrCreateImageDocument( const Image &im );

%feature("docstring") ImageSetActiveSubArea 
"ImageSetActiveSubArea: Sets the area to use for surveying the image data.";
void ImageSetActiveSubArea( const Image &im, bool setSubArea, long top, long left, long bottom, long right );

%feature("docstring") ImageGetTagGroup 
"ImageGetTagGroup: Gets the tags associated with the image.";
TagGroup ImageGetTagGroup( const Image &img );

%feature("docstring") ImageGetUniqueID 
"ImageGetUniqueID: Returns the unique ID for this image. This id is globally unique 
across sessions and locations.";
ScriptObject ImageGetUniqueID( const Image &image );

%feature("docstring") ImageIsDataTypeBinary 
"ImageIsDataTypeBinary: Returns true if the data in the image is binary.";
bool ImageIsDataTypeBinary( const Image &img );

%feature("docstring") ImageIsDataTypeComplex 
"ImageIsDataTypeComplex: Returns true if the data in the image is complex.";
bool ImageIsDataTypeComplex( const Image &img );

%feature("docstring") ImageIsDataTypeFloat 
"ImageIsDataTypeFloat: Returns true if the data in the image is floating point.";
bool ImageIsDataTypeFloat( const Image &img );

%feature("docstring") ImageIsDataTypeInteger 
"ImageIsDataTypeInteger: Returns true if the data in the image is integral.";
bool ImageIsDataTypeInteger( const Image &img );

%feature("docstring") ImageIsDataTypePackedComplex 
"ImageIsDataTypePackedComplex: Returns true if the data in the image is packed complex.";
bool ImageIsDataTypePackedComplex( const Image &img );

%feature("docstring") ImageIsDataTypeReal 
"ImageIsDataTypeReal: Returns true if the data in the image is real.";
bool ImageIsDataTypeReal( const Image &img );

%feature("docstring") ImageIsDataTypeRGB 
"ImageIsDataTypeRGB: Returns true if the data in the image is rgb.";
bool ImageIsDataTypeRGB( const Image &img );

%feature("docstring") ImageIsDataTypeSignedInteger 
"ImageIsDataTypeSignedInteger: Returns true if the data in the image is integral and 
signed.";
bool ImageIsDataTypeSignedInteger( const Image &img );

%feature("docstring") ImageIsDataTypeUnsignedInteger 
"ImageIsDataTypeUnsignedInteger: Returns true if the data in the image is integral and 
unsigned.";
bool ImageIsDataTypeUnsignedInteger( const Image &img );

%feature("docstring") ImageIsDimensionCalibrationDisplayed 
"ImageIsDimensionCalibrationDisplayed: Returns 'true' if the calibration of the 'dim'th 
dimension is displayed.";
bool ImageIsDimensionCalibrationDisplayed( const Image &im, ulong dim );

%feature("docstring") ImageIsIntensityCalibrationDisplayed 
"ImageIsIntensityCalibrationDisplayed: Returns 'true' if the calibration of the intensity 
is displayed.";
bool ImageIsIntensityCalibrationDisplayed( const Image &im );

%feature("docstring") ImageIsValid 
"ImageIsValid: Returns true if 'image' is a valid object.";
bool ImageIsValid( const Image &image );

%feature("docstring") ImageOp_ScalarCombine 
"ImageOp_ScalarCombine: add/multiply image 1 with scalar and assign result to image 2
op is add:0, mul:2";
void ImageOp_ScalarCombine(uint32 op, const Image& im1, double scalar, const Image& im2);

%feature("docstring") ImageOp_ScalarCombineAssign 
"ImageOp_ScalarCombineAssign: add/multiply image with scalar
op is add:0, mul:2";
void ImageOp_ScalarCombineAssign(uint32 op, double scalar, const Image& im);

%feature("docstring") ImageSetDescriptionText 
"ImageSetDescriptionText: Sets the description text associated with the image.";
void ImageSetDescriptionText( const Image &img, const String &description );

%feature("docstring") ImageSetDimensionCalibration 
"ImageSetDimensionCalibration: Sets the calibration for the given dimension.";
void ImageSetDimensionCalibration( const Image &argument_1, long dimenstion, float origin, float scale, const String &unitString, long calibrationFormat );

%feature("docstring") ImageSetDimensionCalibrationDisplayed 
"ImageSetDimensionCalibrationDisplayed: Sets whether or not to display the 'dim'th 
dimension in calibrated units to 'do_display'.";
void ImageSetDimensionCalibrationDisplayed( const Image &im, ulong dim, bool do_display );

%feature("docstring") ImageSetDimensionOrigin 
"ImageSetDimensionOrigin: Sets the origin of the given dimension of image.";
void ImageSetDimensionOrigin( const Image &argument_1, long dimension, float origin );

%feature("docstring") ImageSetDimensionScale 
"ImageSetDimensionScale: Sets the scale of the given dimension of image.";
void ImageSetDimensionScale( const Image &argument_1, long dimension, float scale );

%feature("docstring") ImageSetDimensionUnitInfo 
"ImageSetDimensionUnitInfo: Sets the unit string of the given dimension of image.";
void ImageSetDimensionUnitInfo( const Image &argument_1, long dimension, const String &canon_units, long power );

%feature("docstring") ImageSetDimensionUnitString 
"ImageSetDimensionUnitString: Sets the unit string of the given dimension of image.";
void ImageSetDimensionUnitString( const Image &argument_1, long dimension, const String &units );

%feature("docstring") ImageSetIntensityCalibrationDisplayed 
"ImageSetIntensityCalibrationDisplayed: Sets whether or not to display the intensity in 
calibrated units to 'do_display'.";
void ImageSetIntensityCalibrationDisplayed( const Image &im, bool do_display );

%feature("docstring") ImageSetIntensityOrigin 
"ImageSetIntensityOrigin: Sets the origin of image's intensity.";
void ImageSetIntensityOrigin( const Image &argument_1, float origin );

%feature("docstring") ImageSetIntensityScale 
"ImageSetIntensityScale: Sets the scale of image's intensity.";
void ImageSetIntensityScale( const Image &argument_1, float scale );

%feature("docstring") ImageSetIntensityUnitInfo 
"ImageSetIntensityUnitInfo: Sets the unit string of image's intensity.";
void ImageSetIntensityUnitInfo( const Image &argument_1, const String &canon_units, long power );

%feature("docstring") ImageSetIntensityUnitString 
"ImageSetIntensityUnitString: Sets the unit string of image's intensity.";
void ImageSetIntensityUnitString( const Image &argument_1, const String &units );

%feature("docstring") ImageSetName 
"ImageSetName: Sets the name of the image.";
void ImageSetName( const Image &img, const String &name );

%feature("docstring") ImageWindowGetImageDocument 
"ImageWindowGetImageDocument: Gets the image document displayed in the window.";
ImageDocument ImageWindowGetImageDocument( const Window &window );

%feature("docstring") InstallScriptLibraryFile 
"InstallScriptLibraryFile: Loads the script file indicated by fileName, executes it, and 
publishes any functions contained inside. Always returns 0.";
float InstallScriptLibraryFile( const char *fileName );

%feature("docstring") IntegerImage 
"IntegerImage: Creates a 4D integer image of size [d0,d1,d2,d3] with the given title. The 
bytes can be 1, 2, or 4 and isSigned can be 1 (true) or 0 (false).";
Image IntegerImage( const char *title, long bytes, bool isSigned, long d0, long d1, long d2, long d3);

%feature("docstring") IntegerImage 
"IntegerImage: Creates a 3D integer image of size [d0,d1,d2] with the given title. The 
bytes can be 1, 2, or 4 and isSigned can be 1 (true) or 0 (false).";
Image IntegerImage( const char *title, long bytes, bool isSigned, long d0, long d1, long d2 );

%feature("docstring") IntegerImage 
"IntegerImage: Creates a 2D integer image of size [d0,d1] with the given title. The bytes 
and isSigned parameters specify integer specific attributes of the data.";
Image IntegerImage( const char *title, long bytes, bool isSigned, long d0, long d1 );

%feature("docstring") IntegerImage 
"IntegerImage: Creates a 1D integer image of size [d0] with the given title. The bytes 
and isSigned parameters specify integer specific attributes of the data.";
Image IntegerImage( const char *title, long bytes, bool isSigned, long d0 );

%feature("docstring") Is2DDisplay 
"Is2DDisplay: Return 1 if the image is displayed as a raster image display; return 0 
otherwise.";
bool Is2DDisplay( const Image &argument_1 );

%feature("docstring") IsBinaryDataType 
"IsBinaryDataType: Returns 1 if the image is an binary data type; returns 0 otherwise.";
bool IsBinaryDataType( const Image &argument_1 );

%feature("docstring") IsByteImage 
"IsByteImage: Returns 1 if the image is unsigned 1-byte integer data; returns 0 otherwise.";
bool IsByteImage( const Image &argument_1 );

%feature("docstring") IsComplexDataType 
"IsComplexDataType: Returns 1 if the image is an complex data type of size bytes; returns 
0 otherwise.";
bool IsComplexDataType( const Image &argument_1, long bytes );

%feature("docstring") IsComplexImage 
"IsComplexImage: Returns 1 if the image is single precision complex data; returns 0 
otherwise.";
bool IsComplexImage( const Image &argument_1 );

%feature("docstring") IsDisplayValid 
"IsDisplayValid: Return 1 if the image's display is up-to-date and 0 otherwise.";
bool IsDisplayValid( const Image &argument_1 );

%feature("docstring") IsExceptionUserAbort 
"IsExceptionUserAbort: Returns true if the exception currently in effect is a user abort.";
bool IsExceptionUserAbort( );

%feature("docstring") IsFloatImage 
"IsFloatImage: Returns 1 if the image is single precision real data; returns 0 otherwise.";
bool IsFloatImage( const Image &argument_1 );

%feature("docstring") IsImageComplex 
"IsImageComplex: Return true or false to indicate whether given image with the given id 
is complex-valued or not.";
bool IsImageComplex( long id );

%feature("docstring") IsImageReal 
"IsImageReal: Return true or false to indicate whether given image with the given id is 
real-valued or not.";
bool IsImageReal( long id );

%feature("docstring") IsImageRGB 
"IsImageRGB: Return true or false to indicate whether given image with the given id is 
RGB-valued or not.";
bool IsImageRGB( long id );

%feature("docstring") IsIntegerDataType 
"IsIntegerDataType: Returns 1 if the image is an integer data type of size bytes with a 
matching sign charateristic as signed; returns 0 otherwise.";
bool IsIntegerDataType( const Image &argument_1, long bytes, bool isSigned );

%feature("docstring") IsLongImage 
"IsLongImage: Returns 1 if the image is signed 4-byte integer data; returns 0 otherwise.";
bool IsLongImage( const Image &argument_1 );

%feature("docstring") IsPackedComplexImage 
"IsPackedComplexImage: Returns 1 if the image is packed complex data; returns 0 otherwise.";
bool IsPackedComplexImage( const Image &argument_1 );

%feature("docstring") IsRealDataType 
"IsRealDataType: Returns 1 if the image is an real data type of size bytes; returns 0 
otherwise.";
bool IsRealDataType( const Image &argument_1, long bytes );

%feature("docstring") IsRGBDataType 
"IsRGBDataType: Returns 1 if the image is an RGB data type of size bytes; returns 0 
otherwise.";
bool IsRGBDataType( const Image &argument_1, long bytes );

%feature("docstring") IsShortImage 
"IsShortImage: Returns 1 if the image is signed 2-byte integer data; returns 0 otherwise.";
bool IsShortImage( const Image &argument_1 );

%feature("docstring") KeepImage 
"KeepImage: Keep the image from being deleted automatically when the image's script scope 
is exited.";
void KeepImage( const Image &argument_1 );

%feature("docstring") LinePlotImageDisplayCountSlices 
"LinePlotImageDisplayCountSlices: Returns the number of slices in the line plot.";
long LinePlotImageDisplayCountSlices( const LinePlotImageDisplay &lpid );

%feature("docstring") LinePlotImageDisplayGetBaseIntensity 
"LinePlotImageDisplayGetBaseIntensity: Returns the base intensity of the line plot.";
double LinePlotImageDisplayGetBaseIntensity( const LinePlotImageDisplay &lpid );

%feature("docstring") LinePlotImageDisplayGetContrastLimits 
"LinePlotImageDisplayGetContrastLimits: Gets the lowest and higest intensities displayed.";
void LinePlotImageDisplayGetContrastLimits( const LinePlotImageDisplay &lpid, float *lowLimit, float *highLimit );

%feature("docstring") LinePlotImageDisplayGetDisplayedChannels 
"LinePlotImageDisplayGetDisplayedChannels: Gets the leftmost and rightmost displayed 
channels.";
void LinePlotImageDisplayGetDisplayedChannels( const LinePlotImageDisplay &lpid, float *leftChannel, float *rightChannel );

%feature("docstring") LinePlotImageDisplayGetDoAutoSurvey 
"LinePlotImageDisplayGetDoAutoSurvey: Gets whether to auto-survey is done on the high and 
low intensity limits.";
void LinePlotImageDisplayGetDoAutoSurvey( const LinePlotImageDisplay &lpid, bool *doAutoSurveyLow, bool *doAutoSurveyHigh );

%feature("docstring") LinePlotImageDisplayGetImageToGroupTransform 
"LinePlotImageDisplayGetImageToGroupTransform: return image to group transform.";
void LinePlotImageDisplayGetImageToGroupTransform( const LinePlotImageDisplay &lpid, const ScriptObject &slice_id, const ScriptObject &ref_id, double *off_val, double *scale_val, double *off_dim_0, double *scale_dim_0 );

%feature("docstring") LinePlotImageDisplayGetSlice 
"LinePlotImageDisplayGetSlice: Returns slice currently displayed at the bottom.";
long LinePlotImageDisplayGetSlice( const LinePlotImageDisplay &lpid );

%feature("docstring") LinePlotImageDisplayGetSliceComponentColor 
"LinePlotImageDisplayGetSliceComponentColor: Returns the color of the 'comp_index'th 
component of the 'slice_index'th slice.";
void LinePlotImageDisplayGetSliceComponentColor( const LinePlotImageDisplay &lpid, long slice_index, long comp_index, double *r, double *g, double *b );

%feature("docstring") LinePlotImageDisplayGetSliceDrawingStyle 
"LinePlotImageDisplayGetSliceDrawingStyle: Returns the drawing style of the 
'slice_index'th slice.";
long LinePlotImageDisplayGetSliceDrawingStyle( const LinePlotImageDisplay &lpid, long slice_index );

%feature("docstring") LinePlotImageDisplayGetTrackingStyle 
"LinePlotImageDisplayGetTrackingStyle: Gets the tracking style of the line plot.";
void LinePlotImageDisplayGetTrackingStyle( const LinePlotImageDisplay &lpid, uint16 *track_style_x, uint16 *track_style_y );

%feature("docstring") LinePlotImageDisplayGetSliceTransparency 
"LinePlotImageDisplayGetSliceTransparency: Gets the transparency of the 'slice_index'th 
slice.";
void LinePlotImageDisplayGetSliceTransparency( const LinePlotImageDisplay &lpid, long slice_index, bool * doTransparent, double * transparency );

%feature("docstring") LinePlotImageDisplayGetSliceTransparencyStyle 
"LinePlotImageDisplayGetSliceTransparencyStyle: Gets the transparencyStyle of the 'slice_index'th 
slice.";
void LinePlotImageDisplayGetSliceTransparencyStyle( const LinePlotImageDisplay &lpid, long slice_index, uint32 * transparencyStyle );

%feature("docstring") LinePlotImageDisplayGetSliceLineThickness 
"LinePlotImageDisplayGetSliceLineThickness: Gets the line thickness of the 'slice_index'th 
slice.";
long LinePlotImageDisplayGetSliceLineThickness( const LinePlotImageDisplay &lpid, long slice_index);

%feature("docstring") LinePlotImageDisplayIsBackgroundOn 
"LinePlotImageDisplayIsBackgroundOn: Returns true if the background is erased.";
bool LinePlotImageDisplayIsBackgroundOn( const LinePlotImageDisplay &lpid );

%feature("docstring") LinePlotImageDisplayIsFilled 
"LinePlotImageDisplayIsFilled: Returns true if the line plot is filled.";
bool LinePlotImageDisplayIsFilled( const LinePlotImageDisplay &lpid );

%feature("docstring") LinePlotImageDisplayIsFrameOn 
"LinePlotImageDisplayIsFrameOn: Returns true if the frame is drawn.";
bool LinePlotImageDisplayIsFrameOn( const LinePlotImageDisplay &lpid );

%feature("docstring") LinePlotImageDisplayIsGridOn 
"LinePlotImageDisplayIsGridOn: Returns true if the grid is displayed on.";
bool LinePlotImageDisplayIsGridOn( const LinePlotImageDisplay &lpid );

%feature("docstring") LinePlotImageDisplaySetBackgroundOn 
"LinePlotImageDisplaySetBackgroundOn: Sets whether to erase the background.";
void LinePlotImageDisplaySetBackgroundOn( const LinePlotImageDisplay &lpid, bool on );

%feature("docstring") LinePlotImageDisplaySetBaseIntensity 
"LinePlotImageDisplaySetBaseIntensity: Sets the base intensity of the line plot.";
void LinePlotImageDisplaySetBaseIntensity( const LinePlotImageDisplay &lpid, double base_intensity );

%feature("docstring") LinePlotImageDisplaySetContrastLimits 
"LinePlotImageDisplaySetContrastLimits: Sets the lowest and highest intensities displayed.";
void LinePlotImageDisplaySetContrastLimits( const LinePlotImageDisplay &lpid, float lowLimit, float highLimit );

%feature("docstring") LinePlotImageDisplaySetDisplayedChannels 
"LinePlotImageDisplaySetDisplayedChannels: Sets the leftmost and rightmost displayed 
channels.";
void LinePlotImageDisplaySetDisplayedChannels( const LinePlotImageDisplay &lpid, float leftChannel, float rightChannel );

%feature("docstring") LinePlotImageDisplaySetDoAutoSurvey 
"LinePlotImageDisplaySetDoAutoSurvey: Sets whether to do auto-survey on the high and low 
intensity limits.";
void LinePlotImageDisplaySetDoAutoSurvey( const LinePlotImageDisplay &lpid, bool doAutoSurveyLow, bool doAutoSurveyHigh );

%feature("docstring") LinePlotImageDisplaySetFilled 
"LinePlotImageDisplaySetFilled: Sets whether to fill the lineplot.";
void LinePlotImageDisplaySetFilled( const LinePlotImageDisplay &lpid, bool on );

%feature("docstring") LinePlotImageDisplaySetFrameOn 
"LinePlotImageDisplaySetFrameOn: Sets whether to draw the frame.";
void LinePlotImageDisplaySetFrameOn( const LinePlotImageDisplay &lpid, bool on );

%feature("docstring") LinePlotImageDisplaySetGridOn 
"LinePlotImageDisplaySetGridOn: Sets whether to draw the grid.";
void LinePlotImageDisplaySetGridOn( const LinePlotImageDisplay &lpid, bool on );

%feature("docstring") LinePlotImageDisplaySetImageToGroupTransform 
"LinePlotImageDisplaySetImageToGroupTransform: Sets image to group transfor,.";
void LinePlotImageDisplaySetImageToGroupTransform( const LinePlotImageDisplay &lpid, const ScriptObject &slice_id, const ScriptObject &ref_id, double off_val, double scale_val, double off_dim_0, double scale_dim_0 );

%feature("docstring") LinePlotImageDisplaySetLegendShown 
"LinePlotImageDisplaySetLegendShown: Sets whether or not the legend is shown.";
void LinePlotImageDisplaySetLegendShown( const LinePlotImageDisplay &lpid, bool on );

%feature("docstring") LinePlotImageDisplaySetSlice 
"LinePlotImageDisplaySetSlice: Sets the slice currently displayed at the bottom.";
void LinePlotImageDisplaySetSlice( const LinePlotImageDisplay &lpid, long slice );

%feature("docstring") LinePlotImageDisplaySetSliceComponentColor 
"LinePlotImageDisplaySetSliceComponentColor: Sets the color of the 'comp_index'th 
component of the 'slice_index'th slice.";
void LinePlotImageDisplaySetSliceComponentColor( const LinePlotImageDisplay &lpid, long slice_index, long comp_index, double r, double g, double b );

%feature("docstring") LinePlotImageDisplaySetSliceDrawingStyle 
"LinePlotImageDisplaySetSliceDrawingStyle: Sets the drawing style of the 'slice_index'th 
slice.";
void LinePlotImageDisplaySetSliceDrawingStyle( const LinePlotImageDisplay &lpid, long slice_index, long style );

%feature("docstring") LinePlotImageDisplaySetSliceTransparency 
"LinePlotImageDisplaySetSliceTransparency: Sets the transparency of the 'slice_index'th 
slice.";
void LinePlotImageDisplaySetSliceTransparency( const LinePlotImageDisplay &lpid, long slice_index, bool doTransparent, double transparency );

%feature("docstring") LinePlotImageDisplaySetSliceTransparencyStyle 
"LinePlotImageDisplaySetSliceTransparencyStyle: Sets the transparencyStyle of the 'slice_index'th 
slice.";
void LinePlotImageDisplaySetSliceTransparencyStyle( const LinePlotImageDisplay &lpid, uint32 slice_index, uint32 transparencyStyle );

%feature("docstring") LinePlotImageDisplaySetSliceLineThickness 
"LinePlotImageDisplaySetSliceLineThickness: Sets the line thickness of the 'slice_index'th 
slice.";
void LinePlotImageDisplaySetSliceLineThickness( const LinePlotImageDisplay &lpid, long slice_index, long thickness);

%feature("docstring") LinePlotImageDisplaySetTrackingStyle 
"LinePlotImageDisplaySetTrackingStyle: Sets the tracking style of the line plot.";
void LinePlotImageDisplaySetTrackingStyle( const LinePlotImageDisplay &lpid, uint16 track_style_x, uint16 track_style_y );

%feature("docstring") LUDecomposition 
"LUDecomposition: Return the image resulting from a LU decomposition on images a,b.";
Image LUDecomposition( const Image &a, const Image &b );

%feature("docstring") MaintainStatus 
"MaintainStatus: Update the status window if it needs to be updated.";
void MaintainStatus( );

%feature("docstring") MatrixDeterminant 
"MatrixDeterminant: Return the matrix determinant number of matrix image a.";
float MatrixDeterminant( const Image &a );

%feature("docstring") MatrixInverse 
"MatrixInverse: Return the matrix inverse image of matrix image a.";
Image MatrixInverse( const Image &a );

%feature("docstring") MatrixMultiply 
"MatrixMultiply: Return the matrix product image of matrix images a and b.";
Image MatrixMultiply( const Image &a, const Image &b );

%feature("docstring") MatrixPrint 
"MatrixPrint: Print an image as a matrix to the results window.";
void MatrixPrint( const Image &a );

%feature("docstring") MatrixTranspose 
"MatrixTranspose: Return the matrix transpose image of matrix image a.";
Image MatrixTranspose( const Image &a );

%feature("docstring") MedianFilter 
"MedianFilter: Performs a median filter on the source image according to the filterType 
parameter (0=horizontal, 1=vertical, 2=cross, 3=entire) and the size parameter. Size 
specifies size in each direction - so a 'size' of 2 is a 5x5 window.";
Image MedianFilter( const Image &source, long filterType, long size );

%feature("docstring") ModelessDialog 
"ModelessDialog: Present a modeless dialog with the prompt and buttonName. When the user 
presses the button, the semaphore will be cleared. This function can only be used in the 
background.";
void ModelessDialog( const char *prompt, const char *buttonName, long semaphore );

%feature("docstring") ModelessFFT 
"ModelessFFT: Begin the modeless FFT procedure with the image as the source. The 
parameter reduce indicates whether to perform a reduced FFT.";
void ModelessFFT( const Image &argument_1, bool reduce );

%feature("docstring") MPClose 
"MPClose: Morphologically close the image using the neighbors parameter to control the 
closing and return the resulting image. The source image must be binary.";
Image MPClose( const Image &image, long neighbors );

%feature("docstring") MPDilate 
"MPDilate: Morphologically dilate the image using the neighbors parameter to control the 
dilation and return the resulting image. The source image must be binary.";
Image MPDilate( const Image &image, long neighbors );

%feature("docstring") MPDistanceMap 
"MPDistanceMap: Generate a distance map from the source image and return the resulting 
real image. The source image must be binary.";
Image MPDistanceMap( const Image &image );

%feature("docstring") MPErode 
"MPErode: Morphologically erode the image using the neighbors parameter to control the 
erosion and return the resulting image. The source image must be binary.";
Image MPErode( const Image &image, long neighbors );

%feature("docstring") MPEuclideanDistanceMap 
"MPEuclideanDistanceMap: Generate a Euclidean distance map from the source image and 
return the resulting real image. The source image must be binary.";
Image MPEuclideanDistanceMap( const Image &image );

%feature("docstring") MPExactDistanceMap 
"MPExactDistanceMap: Generate an exact distance map from the source image and return the 
resulting complex image. The source image must be binary.";
Image MPExactDistanceMap( const Image &image );

%feature("docstring") MPOpen 
"MPOpen: Morphologically open the image using the neighbors parameter to control the 
opening and return the resulting image. The source image must be binary.";
Image MPOpen( const Image &image, long neighbors );

%feature("docstring") MPOutline 
"MPOutline: Morphologically outline the image and return the resulting image. The source 
image must be binary.";
Image MPOutline( const Image &image );

%feature("docstring") MultiplyFloatByFloat 
"MultiplyFloatByFloat: Multiply real image a by real image b and store the result in 
a. No data type checking is performed.";
void MultiplyFloatByFloat( const Image &a, const Image &b );

%feature("docstring") MultiplyPackedByFloat 
"MultiplyPackedByFloat: Multiply packed image a by real image b and store the result 
in a. No data type checking is performed.";
void MultiplyPackedByFloat( const Image &a, const Image &b );

%feature("docstring") MultiplyPackedByScalar 
"MultiplyPackedByScalar: Multiply packed image a by real and store the result in a. No 
data type checking is performed.";
void MultiplyPackedByScalar( const Image &a, float argument_2 );

%feature("docstring") NewArrowAnnotation 
"NewArrowAnnotation: Creates a new arrow annotation.";
Component NewArrowAnnotation( float top, float left, float bottom, float right );

%feature("docstring") NewBoxAnnotation 
"NewBoxAnnotation: Creates a new box annotation.";
Component NewBoxAnnotation( float top, float left, float bottom, float right );

%feature("docstring") NewComponent 
"NewComponent: Creates a new annotaiton of type 'type'";
Component NewComponent( long type, float f1, float f2, float f3, float f4 );

%feature("docstring") NewDoubleArrowAnnotation 
"NewDoubleArrowAnnotation: Creates a new double arrow annotation.";
Component NewDoubleArrowAnnotation( float top, float left, float bottom, float right );

%feature("docstring") NewGroupAnnotation 
"NewGroupAnnotation: Creates a new group annotation.";
Component NewGroupAnnotation( );

%feature("docstring") NewImageFromFile 
"NewImageFromFile: Opens a file and reads it as an image.";
Image NewImageFromFile( const String &file_path );

%feature("docstring") NewLineAnnotation 
"NewLineAnnotation: Creates a new line annotation.";
Component NewLineAnnotation( float top, float left, float bottom, float right );

%feature("docstring") NewLiveFFT 
"NewLiveFFT: Creates a new live fft of the area in 'roi', that is reduced if 'reduce' is 
'true'";
Image NewLiveFFT( const ImageDisplay &imageDisplay, const ROI &roi, bool reduce );

%feature("docstring") NewLiveHistogram 
"NewLiveHistogram: Creates a new live histogram of the area in 'roi', binned by 
'num_channels'";
Image NewLiveHistogram( const ImageDisplay &imageDisplay, const ROI &roi, long num_channels );

%feature("docstring") NewLiveProfile 
"NewLiveProfile: Creates a new live profile from (start_x,start_y) to (end_x,end_y)";
Image NewLiveProfile( const ImageDisplay &imageDisplay, float start_x, float start_y, float end_x, float end_y, float width );

%feature("docstring") NewOvalAnnotation 
"NewOvalAnnotation: Creates a new oval annotation.";
Component NewOvalAnnotation( float top, float left, float bottom, float right );

%feature("docstring") NewPictureAnnotation 
"NewPictureAnnotation: Creates a new picture annotation.";
Component NewPictureAnnotation( float top, float left, float bottom, float right, long picture );

%feature("docstring") NewROI 
"NewROI: Creates an empty region of interest.";
ROI NewROI( );

%feature("docstring") NewScriptWindow 
"NewScriptWindow: Creates a new editor window.";
Window NewScriptWindow( const String &title, long top, long left, long bottom, long right );

%feature("docstring") NewScriptWindowFromFile 
"NewScriptWindowFromFile: Opens a file into a script window.";
Window NewScriptWindowFromFile( const String &file_name, long top, long left, long bottom, long right );

%feature("docstring") NewScriptWindowFromFile 
"NewScriptWindowFromFile: Opens a file into a script window.";
Window NewScriptWindowFromFile( const String &file_name );

%feature("docstring") NewScriptWindowFromFile 
"NewScriptWindowFromFile: Opens a file into a script window.";
Window NewScriptWindowFromFile( const String &file_name, const String &font_name, ulong attributes, ulong size );

%feature("docstring") NewScriptWindowFromFile 
"NewScriptWindowFromFile: Opens a file into a script window.";
Window NewScriptWindowFromFile( const String &file_name, const String &font_name, ulong attributes, ulong size, long top, long left, long bottom, long right );

%feature("docstring") NewSemaphore 
"NewSemaphore: Create a semaphore. Used only with background processing.";
long NewSemaphore( );

%feature("docstring") NewTagGroup 
"NewTagGroup: Creates an empty tag group.";
TagGroup NewTagGroup( );

%feature("docstring") NewTagList 
"NewTagList: Creates an empty tag list.";
TagGroup NewTagList( );

%feature("docstring") NewTextAnnotation 
"NewTextAnnotation: Creates a new text annotation.";
Component NewTextAnnotation( float left, float top, const String &text, float size );

%feature("docstring") NextImage 
"NextImage: Find the next image.";
Image NextImage( const Image &argument_1 );

%feature("docstring") OkCancelDialog 
"OkCancelDialog: Puts up a dialog with the given prompt. Returns 1 for OK and 0 for 
Cancel.";
bool OkCancelDialog( const char *prompt );

%feature("docstring") OkDialog 
"OkDialog: Puts up a dialog with the given prompt.";
void OkDialog( const char *prompt );

%feature("docstring") OpenAndSetProgressWindow 
"OpenAndSetProgressWindow: Open the progress window and sets the text within to line1, 
line2, and line3.";
void OpenAndSetProgressWindow( const char *line1, const char *line2, const char *line3 );

%feature("docstring") OpenDialog 
"OpenDialog: Puts up an Open dialog, allows the user to select a file, and stores the 
pathname into the pathname variable. Returns 1 for OK and 0 for Cancel.";
bool OpenDialog( String &pathname );

%feature("docstring") OpenFileForReading 
"OpenFileForReading: Open the file for reading. Return the file reference for this file. 
This call must be balanced with call to CloseFile() with the returned reference number.";
DM_FileReference OpenFileForReading( const String &file_path );

%feature("docstring") OpenFileForReadingAndWriting 
"OpenFileForReadingAndWriting: Open the file for reading and writing. Return the file 
reference for this file. This call must be balanced with call to CloseFile() with the 
returned reference number.";
DM_FileReference OpenFileForReadingAndWriting( const String &file_path );

%feature("docstring") OpenFileForWriting 
"OpenFileForWriting: Open the file for writing. Return the file reference for this file. 
This call must be balanced with call to CloseFile() with the returned reference number.";
DM_FileReference OpenFileForWriting( const String &file_path );

%feature("docstring") OpenImage 
"OpenImage: Open the image with the filename. Returns the opened image.";
Image OpenImage( const String &fileName );

%feature("docstring") OpenResultsWindow 
"OpenResultsWindow: Open the results window if it is not already open.";
void OpenResultsWindow( );

%feature("docstring") OpenTimeBar 
"OpenTimeBar: Opens the time bar with the given prompt. The total parameter is ignored. 
CloseTimeBar() must be invoked exactly once for every OpenTimeBar() call.";
void OpenTimeBar( const char *prompt, long total );

%feature("docstring") OptionDown 
"OptionDown: Returns 1 if the option key is down and 0 otherwise.";
bool OptionDown( );

%feature("docstring") PackedFFT 
"PackedFFT: Creates a new packed complex image from the FFT of the real image source.";
Image PackedFFT( const Image &source );

%feature("docstring") PackedIFFT 
"PackedIFFT: Creates a new real image from the inverse FFT of the packed complex image 
source.";
Image PackedIFFT( const Image &source );

%feature("docstring") PackedLnModulusToImage 
"PackedLnModulusToImage: Store the unpacked log modulus of the packed complex image 
imageSrc into imageDst using the lowLimit, highLimit, and range parameters. No data type 
checking is performed.";
void PackedLnModulusToImage( const Image &imageSrc, const Image &imageDst, float lowLimit, float highLimit, float range );

%feature("docstring") PackedToComplex 
"PackedToComplex: Creates a new complex 8-byte image from the packed complex source.";
Image PackedToComplex( const Image &source );

%feature("docstring") PathAddParentIndirection 
"PathAddParentIndirection: Returns 'path' appended with a string denoting indirection to 
the parent directory";
String PathAddParentIndirection( const String &path );

%feature("docstring") PathBeginRelative 
"PathBeginRelative: Returns a string that begins a relative path";
String PathBeginRelative( );

%feature("docstring") PathConcatenate 
"PathConcatenate: Concatenates 'final_path' to 'initial_path' to create a new path, 
adding separators as necessary.";
String PathConcatenate( const String &initial_path, const String &final_path );

%feature("docstring") PathExtractBaseName 
"PathExtractBaseName: Returns the base name portion of 'dir_path', where 'path_type' 
denotes '1' for Mac paths, '2' for Windows paths, and '0' for current OS paths";
String PathExtractBaseName( const String &path, ulong path_type );

%feature("docstring") PathExtractDirectory 
"PathExtractDirectory: Returns the directory portion of 'dir_path', where 'path_type' 
denotes '1' for Mac paths, '2' for Windows paths, and '0' for current OS paths";
String PathExtractDirectory( const String &path, ulong path_type );

%feature("docstring") PathExtractExtension 
"PathExtractExtension: Returns the extension portion of 'dir_path', where 'path_type' 
denotes '1' for Mac paths, '2' for Windows32 paths, '3' for Windows64 paths, and '0' for current OS paths";
String PathExtractExtension( const String &path, ulong path_type );

%feature("docstring") PathExtractFileName 
"PathExtractFileName: Returns the file name portion of 'dir_path', where 'path_type' 
denotes '1' for Mac paths, '2' for Windows paths, and '0' for current OS paths";
String PathExtractFileName( const String &path, ulong path_type );

%feature("docstring") PathExtractParentDirectory 
"PathExtractParentDirectory: Returns the parent directory portion of 'dir_path', where 
'path_type' denotes '1' for Mac paths, '2' for Windows paths, and '0' for current OS paths";
String PathExtractParentDirectory( const String &path, ulong path_type );

%feature("docstring") PathGetFullpath 
"PathGetFullpath: Returns the full path name of the file denoted by 'dir_path'";
String PathGetFullpath( const String &path );

%feature("docstring") PathsSpecifySameFile 
"PathGetFullpath: Returns the full path name of the file denoted by 'dir_path'";
bool PathsSpecifySameFile( const String &path_1, const String &path_2 );

%feature("docstring") Pi 
"Pi: Return an approximation of pi.";
double Pi( );

%feature("docstring") PictureAnnotationSetPicture 
"PictureAnnotationSetPicture: Sets the picture of an annotation.";
void PictureAnnotationSetPicture( const Component &comp, long picture );

%feature("docstring") PIctureGetBounds 
"PIctureGetBounds: Gets the preferred bounds of the picture for display on the screen.";
void PIctureGetBounds( long picture, float *top, float *left, float *bottom, float *right );

%feature("docstring") PrintImage 
"PrintImage: Print the image.";
void PrintImage( const Image &argument_1 );

%feature("docstring") RasterImageDisplayAddThresholdToMask 
"RasterImageDisplayAddThresholdToMask: Sets the points in mask to 1 if they lie within 
the threshold.";
void RasterImageDisplayAddThresholdToMask( const RasterImageDisplay &rid, const Image &mask, float top, float left, float bottom, float right );

%feature("docstring") RasterImageDisplayGetThresholdLimits 
"RasterImageDisplayGetThresholdLimits: Gets the threshold limits of the display.";
void RasterImageDisplayGetThresholdLimits( const RasterImageDisplay &rid, float *low, float *high );

%feature("docstring") RasterImageDisplayIsThresholdOn 
"RasterImageDisplayIsThresholdOn: Determines whether the thresholding overlay is on or 
off.";
bool RasterImageDisplayIsThresholdOn( const RasterImageDisplay &rid );

%feature("docstring") RasterImageDisplaySetThresholdLimits 
"RasterImageDisplaySetThresholdLimits: Sets the threshold limits of the display.";
void RasterImageDisplaySetThresholdLimits( const RasterImageDisplay &rid, float low, float high );

%feature("docstring") RasterImageDisplaySetThresholdOn 
"RasterImageDisplaySetThresholdOn: Sets whether the thresholding overlay is on or off.";
void RasterImageDisplaySetThresholdOn( const RasterImageDisplay &rid, bool on );

%feature("docstring") RasterizeRGB 
"RasterizeRGB: Rasterize the source RGB image and return the resulting Raster image 
displayed image with an appropriate color table. The dither parameter controls dithering.";
Image RasterizeRGB( const Image &source, bool dither );

%feature("docstring") RawCopyImage 
"RawCopyImage: Copies the src image to the dst image ignoring data types. The data type 
sizes of the two images must be the same.";
void RawCopyImage( const Image &src, const Image &dst );

%feature("docstring") ReadFile 
"ReadFile: Read count bytes from the file, returning them as a string.";
String ReadFile( DM_FileReference file, long count );

%feature("docstring") ReadFileLine 
"ReadFileLine: Read a line of text from the file, storing it into the string variable. 
Return 1 if successful and 0 otherwise.";
bool ReadFileLine( DM_FileReference file, String &string );

%feature("docstring") ReadRawStream 
"ReadRawStream: Read length bytes from rawStream and store it into the memory pointed to 
by data.";
void ReadRawStream( long rawStream, long data, long length );

%feature("docstring") RealFFT 
"RealFFT: Creates a new complex 8-byte image from the FFT of the real image source.";
Image RealFFT( const Image &source );

%feature("docstring") RealIFFT 
"RealIFFT: Creates a new real image from the inverse FFT of the complex 8-byte image 
source.";
Image RealIFFT( const Image &source );

%feature("docstring") RealImage 
"RealImage: Creates a 4D real image of size [d0,d1,d2,d3] with the given title. The bytes 
parameter can be 4 or 8 for single and double precision floating point numbers.";
Image RealImage( const String &title, uint32 bytes, uint32 d0, uint32 d1, uint32 d2, uint32 d3);

%feature("docstring") RealImage 
"RealImage: Creates a 3D real image of size [d0,d1,d2] with the given title. The bytes 
parameter can be 4 or 8 for single and double precision floating point numbers.";
Image RealImage( const String &title, uint32 bytes, uint32 d0, uint32 d1, uint32 d2 );

%feature("docstring") RealImage 
"RealImage: Creates a 2D real image of size [d0,d1] with the given title. The bytes 
parameter can be 4 or 8 for single and double precision floating point numbers.";
Image RealImage( const String &title, uint32 bytes, uint32 d0, uint32 d1 );

%feature("docstring") RealImage 
"RealImage: Creates a 1D real image of size [d0] with the given title. The bytes 
parameter can be 4 or 8 for single and double precision floating point numbers.";
Image RealImage( const String &title, uint32 bytes, uint32 d0 );

%feature("docstring") Reduce 
"Reduce: Reduces the image by 2X.";
void Reduce( const Image &argument_1 );

%feature("docstring") ReducedFFT 
"ReducedFFT: Creates a new packed complex image from the FFT of the real image source 
after reducing the source by a factor of 2.";
Image ReducedFFT( const Image &source );

%feature("docstring") ImageUtilities_MeanAndVariance 
"ImageUtilities_MeanAndVariance: Calculates image stats";
double ImageUtilities_MeanAndVariance( const Image &src_img, const Image &mask_img, double &mean, double &variance );

%feature("docstring") RegisterCustomMenu 
"RegisterCustomMenu: Register a custom menu. See the SDK documentation for more 
information.";
long RegisterCustomMenu( long menuHandler );

%feature("docstring") SetStatusBarVisibility 
"Show/Hide status bar";
void SetStatusBarVisibility( bool visibility );

%feature("docstring") SetShowHideStatusBarMenuItemEnabled 
"Show/Hide status bar menu item ( poor, but we want to disable item for serial scopes from Microscope plugin. RTH)";
void SetShowHideStatusBarMenuItemEnabled( bool enabled );

%feature("docstring") UpdateStatusBar 
"Update status bar's pane text";
void UpdateStatusBar(long nIndex, const char* pcText);

%feature("docstring") RegisterCustomTool 
"RegisterCustomTool: Add the tool to the custom tool list. See the SDK documentation for 
more information.";
ULONG_PTR RegisterCustomTool( ULONG_PTR toolInstance, const char* toolTip, ULONG_PTR hBitmap );

%feature("docstring") RegisterMenuAdjustment 
"RegisterMenuAdjustment: Unregister a menu name adjustment. See the SDK documentation for 
more information.";
void RegisterMenuAdjustment( const char *menuName, const char *adjustedMenuName );

%feature("docstring") RegisterObjectListener 
"RegisterObjectListener: Add object listener to OM object. See the SDK documentation for 
more information.";
ulong_ptr_t RegisterObjectListener( ulong_ptr_t object, ulong_ptr_t proc, ulong_ptr_t refCon );

%feature("docstring") RegisterScriptPalette 
"RegisterScriptPalette:";
void RegisterScriptPalette( const ScriptObject &argument_1, const char *type, const char *name );

%feature("docstring") RegisterSystemIdle 
"RegisterSystemIdle: Register a system idle procedure.";
void RegisterSystemIdle( SystemIdleProc SystemIdleProc );

%feature("docstring") ReleaseDataPtr 
"ReleaseDataPtr: Releases the pointer to the image data acquired using the GetDataPtr() 
function.";
void ReleaseDataPtr( const Image &argument_1 );

%feature("docstring") ReleaseSemaphore 
"ReleaseSemaphore: Release a semaphore. Used only with background processing.";
void ReleaseSemaphore( long argument_1 );

%feature("docstring") RemoveCustomTool 
"RemoveCustomTool: Remove the tool to the custom tool list. See the SDK documentation for 
more information.";
void RemoveCustomTool( long doStateProc );

%feature("docstring") RevertToDefaultTool 
"RevertToDefaultTool: Revert DM to the default tool";
void RevertToDefaultTool();

%feature("docstring") RemoveFunction 
"RemoveFunction: Removes the user defined function with an entry point matching fnPtr.";
void RemoveFunction( void *fnPtr );

%feature("docstring") RemovePathFromCopyToImageList 
"RemovePathFromCopyToImageList: Removes 'path' from the copy to image list.";
void RemovePathFromCopyToImageList( const char *path );

%feature("docstring") RemoveScriptFromMenu 
"RemoveScriptFromMenu: Removes the given menu command from the menu. The commandName 
indicates the string by which this script is known to the application. The menuName and 
optionalSubMenuName parameters specify the menu.";
void RemoveScriptFromMenu( const char *commandName, const char *menuName, const char *optionalSubMenuName );

%feature("docstring") ResetContrastLimitsAlways 
"ResetContrastLimitsAlways: Reset the contrast limits of the image from the survey 
information.";
void ResetContrastLimitsAlways( const Image &argument_1 );

%feature("docstring") Result 
"Result: Output the string to the results window.";
void Result( const String &argument_1 );

%feature("docstring") Debug 
"Debug: Output the string to the debug window.";
void Debug( const String &argument_1 );

%feature("docstring") GetLogDirectory 
"DM logger: Get DM log file directory.";
bool GetLogDirectory(std::string &log_dir);

%feature("docstring") GetLogFilename 
"DM logger: Get current DM log file name.";
bool GetLogFilename(std::string &filename);

%feature("docstring") CopyLogFile 
"DM logger: Copied DM log file to temp with specified Level filter";
bool CopyLogFile(uint32 level);

%feature("docstring") GetCopyLogFilename 
"DM logger: Get copied file name created by function CopyLogFile";
bool GetCopyLogFilename(std::string &copyfilename);

%feature("docstring") FlushLogFile 
"DM logger: Force disc-write of log message queue";
bool FlushLogFile();

%feature("docstring") GetLogMessageCount 
"DM logger: Get message count with specified Level filter";
uint32 GetLogMessageCount(uint32 level);

%feature("docstring") RGBImage 
"RGBImage: Creates a 4D RGB image of size [d0,d1,d2, d3] with the given title. The bytes 
parameter must be 4.";
Image RGBImage( const char *title, long bytes, long d0, long d1, long d2, long d3);

%feature("docstring") RGBImage 
"RGBImage: Creates a 3D RGB image of size [d0,d1,d2] with the given title. The bytes 
parameter must be 4.";
Image RGBImage( const char *title, long bytes, long d0, long d1, long d2 );

%feature("docstring") RGBImage 
"RGBImage: Creates a 2D RGB image of size [d0,d1] with the given title. The bytes 
parameter must be 4.";
Image RGBImage( const char *title, long bytes, long d0, long d1 );

%feature("docstring") RGBImage 
"RGBImage: Creates a 1D RGB image of size [d0] with the given title. The bytes parameter 
must be 4.";
Image RGBImage( const char *title, long bytes, long d0 );

%feature("docstring") ROIAddToMask 
"ROIAddToMask: Add the region of interest to the image within the bounds of the specified 
rectangle.";
void ROIAddToMask( const ROI &roi, const Image &mask, float top, float left, float bottom, float right );

%feature("docstring") ROIAddVertex 
"ROIAddVertex: Add a vertex with the given coordinates to the region of interest.";
void ROIAddVertex( const ROI &roi, float x, float y );

%feature("docstring") ROIClearVertices 
"ROIClearVertices: Remove all vertices from the region of interest.";
void ROIClearVertices( const ROI &roi );

%feature("docstring") ROIClone 
"ROIClone: Returns a clone of the roi.";
ROI ROIClone( const ROI &roi );

%feature("docstring") ROIContainsPoint 
"ROIContainsPoint: Returns whether the region of interest encloses the given point.";
bool ROIContainsPoint( const ROI &roi, float x, float y );

%feature("docstring") ROICountVertices 
"ROICountVertices: Return the number of vertices comprising the region of interest.";
long ROICountVertices( const ROI &roi );

%feature("docstring") ROIDeleteVertex 
"ROIDeleteVertex: Delete the given vertex from the region of interest.";
void ROIDeleteVertex( const ROI &roi, long index );

%feature("docstring") ROIGetColor 
"ROIGetColor: Stores the color of the region of interest into the variables. Each number 
will be in the range of 0 to 1.";
void ROIGetColor( const ROI &roi, float *r, float *g, float *b );

%feature("docstring") ROIGetDeletable 
"ROIGetDeletable: Return whether the region of interest is deletable or not.";
bool ROIGetDeletable( const ROI &roi );

%feature("docstring") ROIGetID 
"ROIGetID: Return the ID for the region of interest.";
long ROIGetID( const ROI &roi );

%feature("docstring") ROIGetLabel 
"ROIGetLabel: Return the label of the region of interest.";
String ROIGetLabel( const ROI &roi );

%feature("docstring") ROIGetLabelStripeColor 
"ROIGetLabelStripeColor: Stores the color of the label stripe into the variables. Each number 
will be in the range of 0 to 1.";
void ROIGetLabelStripeColor( const ROI &roi, float *r, float *g, float *b );

%feature("docstring") ROIGetLine 
"ROIGetLine: Fill in the start and end points of the line represented by the region of 
interest.";
void ROIGetLine( const ROI &roi, float *sx, float *sy, float *ex, float *ey );

%feature("docstring") ROIGetMoveable 
"ROIGetMoveable: Return whether the region of interest is moveable or not.";
bool ROIGetMoveable( const ROI &roi );

%feature("docstring") ROIGetName 
"ROIGetName: Return the name of the region of interest.";
String ROIGetName( const ROI &roi );

%feature("docstring") ROIGetPoint 
"ROIGetPoint: Return the coordinates of the point represented by this region of interest.";
void ROIGetPoint( const ROI &roi, float *x, float *y );

%feature("docstring") ROIGetRange 
"ROIGetRange: Fills in the start and end columns of the range represented by the region 
of interest.";
void ROIGetRange( const ROI &roi, float *start, float *end );

%feature("docstring") ROIGetRectangle 
"ROIGetRectangle: Fill in the coordinates of the rectangle represented by the region of 
interest.";
void ROIGetRectangle( const ROI &roi, float *top, float *left, float *bottom, float *right );

%feature("docstring") ROIGetResizable 
"ROIGetResizable: Return whether the region of interest is resizable or not.";
bool ROIGetResizable( const ROI &roi );

%feature("docstring") ROIGetVertex 
"ROIGetVertex: Return the coordinates of the given vertex of the region of interest.";
void ROIGetVertex( const ROI &roi, long index, float *x, float *y );

%feature("docstring") ROIGetVolatile 
"ROIGetVolatile: Return whether the region of interest is volatile or not.";
bool ROIGetVolatile( const ROI &roi );

%feature("docstring") ROIInsertVertex 
"ROIInsertVertex: Insert a vertex with the given coordinates before the indicated vertex 
of the region of interest.";
void ROIInsertVertex( const ROI &roi, long before, float x, float y );

%feature("docstring") ROIIsClosed 
"ROIIsClosed: Returns whether the region of interest is a closed loop or not.";
bool ROIIsClosed( const ROI &roi );

%feature("docstring") ROIIsLine 
"ROIIsLine: Return whether the region of interest is a line.";
bool ROIIsLine( const ROI &roi );

%feature("docstring") ROIIsPoint 
"ROIIsPoint: Return whether the region of interest is a point.";
bool ROIIsPoint( const ROI &roi );

%feature("docstring") ROIIsRange 
"ROIIsRange: Returns whether the region of interest is a range.";
bool ROIIsRange( const ROI &roi );

%feature("docstring") ROIIsRectangle 
"ROIIsRectangle: Return whether the region of interest is a rectangle.";
bool ROIIsRectangle( const ROI &roi );

%feature("docstring") ROIIsValid 
"ROIIsValid: Returns 'true' if the region of interest is a valid object.";
bool ROIIsValid( const ROI &roi );

%feature("docstring") ROISetColor 
"ROISetColor: Set the color of the region of interest. Each number should be in the range 
of 0 to 1.";
void ROISetColor( const ROI &roi, float r, float g, float b );

%feature("docstring") ROISetDeletable 
"ROISetDeletable: Sets whether the region of interest should be deletable or not.";
void ROISetDeletable( const ROI &roi, bool deletable );

%feature("docstring") ROISetIsClosed 
"ROISetIsClosed: Sets whether the region of interest is a closed loop or not (that is the 
last vertex connects to the first).";
void ROISetIsClosed( const ROI &roi, bool is_closed );

%feature("docstring") ROISetLabel 
"ROISetLabel: Set the label on the region of interest.";
void ROISetLabel( const ROI &roi, const String &name );

%feature("docstring") ROISetBoldLabel 
"ROISetLabel: Set the label on the region of interest to bold.";
void ROISetBoldLabel( const ROI &roi, bool boldLabel );

%feature("docstring") ROISetBorderThickness 
"ROISetLabel: Set the label on the region of interest to bold.";
void ROISetBorderThickness( const ROI &roi, float borderThickness );

%feature("docstring") ROISetColor 
"ROISetLabelStripeColor: Set the stripe color of the ROI label. Each number should be in the  
range of 0 to 1.";
void ROISetColor( const ROI &roi, float r, float g, float b );

%feature("docstring") ROISetLine 
"ROISetLine: Set the region of interest to a line with the given start and end 
coordinates.";
void ROISetLine( const ROI &roi, float sx, float sy, float ex, float ey );

%feature("docstring") ROISetMoveable 
"ROISetMoveable: Sets whether the region of interest should be moveable or not.";
void ROISetMoveable( const ROI &roi, bool moveable );

%feature("docstring") ROISetName 
"ROISetName: Set the name of the region of interest.";
void ROISetName( const ROI &roi, const String &name );

%feature("docstring") ROISetPoint 
"ROISetPoint: Set the region of interest to a point with the given coordinate.";
void ROISetPoint( const ROI &roi, float x, float y );

%feature("docstring") ROISetRange 
"ROISetRange: Sets the region of interest to a range with the given start and end columns.";
void ROISetRange( const ROI &roi, float start, float end );

%feature("docstring") ROISetRectangle 
"ROISetRectangle: Set the region of interest to a rectangle with the given coordinates.";
void ROISetRectangle( const ROI &roi, float top, float left, float bottom, float right );

%feature("docstring") ROISetRegionToComplexValue 
"ROISetRegionToComplexValue: Sets the area in 'mask' corresponding to the region to the 
value 'value'.";
void ROISetRegionToComplexValue( const ROI &roi, const Image &mask, const complex128_t &value, float top, float left, float bottom, float right );

%feature("docstring") ROISetRegionToRGBValue 
"ROISetRegionToRGBValue: Sets the area in 'mask' corresponding to the region to the value 
'value'.";
void ROISetRegionToRGBValue( const ROI &roi, const Image &mask, rgba_uint8_os_t value, float top, float left, float bottom, float right );

%feature("docstring") ROISetRegionToValue 
"ROISetRegionToValue: Sets the area in 'mask' corresponding to the region to the value 
'value'.";
void ROISetRegionToValue( const ROI &roi, const Image &mask, double value, float top, float left, float bottom, float right );

%feature("docstring") ROISetResizable 
"ROISetResizable: Sets whether the region of interest should be resizable or not.";
void ROISetResizable( const ROI &roi, bool resizable );

%feature("docstring") ROISetVertex 
"ROISetVertex: Set the coordinates of the given vertex of the region of interest.";
void ROISetVertex( const ROI &roi, long index, float x, float y );

%feature("docstring") ROISetVolatile 
"ROISetVolatile: Set whether the region of interest is volatile or not.";
void ROISetVolatile( const ROI &roi, bool is_volatile );

%feature("docstring") Rotate 
"Rotate: Creates a new real image by rotating the source image counterclockwise by 
radians.";
Image Rotate( const Image &source, float radians );

%feature("docstring") RotateLeft 
"RotateLeft: Rotates the image to the left by 90�.";
void RotateLeft( const Image &argument_1 );

%feature("docstring") RotateRight 
"RotateRight: Rotates the image to the right by 90�.";
void RotateRight( const Image &argument_1 );

%feature("docstring") Save 
"Save: Save the image under the it's current filename.";
void Save( const Image &argument_1 );

%feature("docstring") SaveAsDialog 
"SaveAsDialog: Puts up the SaveAs dialog with the given prompt and default file name, and 
then stores the chosen path for the saved file into the saveName variable. Returns 1 for 
OK and 0 for Cancel.";
bool SaveAsDialog( const char *prompt, const char *defaultName, char *saveName );

%feature("docstring") SaveAsGatan 
"SaveAsGatan: Save the image to the fileName in Gatan 4.0 file format.";
void SaveAsGatan( const Image &argument_1, const String &file_path );

%feature("docstring") SaveAsGatan 
"SaveAsGatan: Save the image to the fileName in Gatan 4.0 file format. 
With or without thumbnail image.";
void SaveAsGatan( const Image &argument_1, const String &file_path, bool inc_thumb );

%feature("docstring") SaveAsGatan3 
"SaveAsGatan3: Save the image to the fileName in Gatan 3.0 file format. 
( No thumbnail option ).";
void SaveAsGatan3( const Image &argument_1, const String &file_path );

%feature("docstring") SaveAsGatan3 
"SaveAsGatan3: Save the image to the fileName in Gatan 3.0 file format. 
( No thumbnail option ).";
void SaveAsGatan3( const Image &argument_1, const String &file_path, bool inc_thumb );

%feature("docstring") SaveAsGIF 
"SaveAsGIF: Save the image to the fileName in GIF file format. The DM Import/Export 
Plug-in must be installed in order for this function to work.";
void SaveAsGIF( const Image &argument_1, const String &fileName );

%feature("docstring") SaveAsPCX 
"SaveAsPCX: Save the image to the fileName in PCX file format. The DM Import/Export 
Plug-in must be installed in order for this function to work.";
void SaveAsPCX( const Image &argument_1, const String &fileName );

%feature("docstring") SaveAsPICT 
"SaveAsPICT: Save the image to the fileName in PICT file format. The DM Import/Export 
Plug-in must be installed in order for this function to work.";
void SaveAsPICT( const Image &argument_1, const String &file_path );

%feature("docstring") SaveAsRawData 
"SaveAsRawData: Save the image to the fileName in raw file format.";
void SaveAsRawData( const Image &argument_1, const String &file_path );

%feature("docstring") SaveAsSmallHeader 
"SaveAsSmallHeader: Save the image to the fileName in Gatan small header file format.";
void SaveAsSmallHeader( const Image &argument_1, const String &file_path );

%feature("docstring") SaveAsText 
"SaveAsText: Save the image to the fileName in text file format.";
void SaveAsText( const Image &argument_1, const String &file_path );

%feature("docstring") SaveAsTIFF 
"SaveAsTIFF: Save the image to the fileName in TIFF file format. The DM Import/Export 
Plug-in must be installed in order for this function to work.";
void SaveAsTIFF( const Image &argument_1, const String &fileName );

%feature("docstring") SaveImage 
"SaveImage: Save the image to the fileName in it's current file format.";
void SaveImage( const Image &argument_1, const String &file_path );

%feature("docstring") SaveAsMSA 
"SaveAsMSA: Save the image to the fileName in MSA file format.";
void SaveAsMSA( const Image &argument_1, const String &file_path );

%feature("docstring") ScrapClear 
"ScrapClear: Clear the pasted image (if there is one) from the image.";
void ScrapClear( const Image &argument_1 );

%feature("docstring") ScrapCopy 
"ScrapCopy: Copy the selected portion of the image to the scrap.";
void ScrapCopy( const Image &argument_1 );

%feature("docstring") ScrapGetLocation 
"ScrapGetLocation: Store the pasted image location (in image coordinates) into the top 
and left variables.";
void ScrapGetLocation( const Image &argument_1, long *top, long *left );

%feature("docstring") ScrapGetSize 
"ScrapGetSize: Store the pasted image size (in image coordinates) into the width and 
height variables.";
void ScrapGetSize( const Image &argument_1, long *width, long *height );

%feature("docstring") ScrapMerge 
"ScrapMerge: Merge the pasted image (if there is one) with the image.";
void ScrapMerge( const Image &argument_1 );

%feature("docstring") ScrapPaste 
"ScrapPaste: Paste the scrap into the image.";
void ScrapPaste( const Image &argument_1 );

%feature("docstring") ScrapPasteNew 
"ScrapPasteNew: Paste the scrap into a new image.";
void ScrapPasteNew( );

%feature("docstring") ScrapSetLocation 
"ScrapSetLocation: Set the location of the pasted image (if there is one) to [top,left].";
void ScrapSetLocation( const Image &argument_1, long top, long left );

%feature("docstring") ScreenGetBounds 
"ScreenGetBounds: Gets the bounds of the 'index'th screen.";
void ScreenGetBounds( long index, long *t, long *l, long *b, long *r );

%feature("docstring") ScreenGetWorkArea 
"ScreenGetWorkArea: Gets the bounds of the 'index'th screen.";
void ScreenGetWorkArea( long index, long *t, long *l, long *b, long *r );

%feature("docstring") ScriptInterfaceGenerateStubs 
"ScriptInterfaceGenerateStubs: Generates C++ stubs for the interface.";
void ScriptInterfaceGenerateStubs( const char *interface_name, String &str_h, String &str_cp );

%feature("docstring") ScriptObjectGetClassToken 
"ScriptObjectGetClassToken: Gets the token in 'scriptObject' corresponding to the class 
'class_name'.";
ulong ScriptObjectGetClassToken( const ScriptObject &scriptObject, const String &class_name );

%feature("docstring") ScriptObjectGetID 
"ScriptObjectGetID: Returns a unique ID for this object. The object can be recovered by 
using GetScriptObjectFromID function.";
long ScriptObjectGetID( const ScriptObject &scriptObject );

%feature("docstring") ScriptObjectIsValid 
"ScriptObjectIsValid: Returns true if 'scriptObject' references a valid object.";
bool ScriptObjectIsValid( const ScriptObject &scriptObject );

%feature("docstring") ScriptObjectLookupMethod 
"ScriptObjectLookupMethod: Returns the method of this object corresponding to the 
abstract method 'meth_abs' and class 'class_name'.";
Function ScriptObjectLookupMethod( const ScriptObject &scriptObject, const Function &meth_abs, const char *class_name );

%feature("docstring") ScriptObjectLookupMethod 
"ScriptObjectLookupMethod: Returns the specific method of this object corresponding to 
the abstract method 'meth_abs'.";
Function ScriptObjectLookupMethod( const ScriptObject &scriptObject, const Function &meth_abs );

%feature("docstring") ScriptWindowExecute 
"ScriptWindowExecute: Executes the script in the script window.";
void ScriptWindowExecute( const Window &window );

%feature("docstring") SelectImage 
"SelectImage: Bring the image's image document window to the front.";
void SelectImage( const Image &argument_1 );

%feature("docstring") SetColorMode 
"SetColorMode: Set the color mode of the image. The possible values for mode are 
1=greyscale, 3=rainbow, 4=temperature.";
void SetColorMode( const Image &argument_1, short mode );

%feature("docstring") SetComplexMode 
"SetComplexMode: Set the complex-to-real mode of the image. The possible value for mode 
are 1=real, 2=imaginary, 3=modulus, 4=log of modulus, 5=phase.";
void SetComplexMode( const Image &argument_1, short mode );

%feature("docstring") SetContrastMode 
"SetContrastMode: Set the constrast mode of the image. The possible value for mode are 
1=linear, 2=equalized, 3=contoured, 4=custom.";
void SetContrastMode( const Image &argument_1, short mode );

%feature("docstring") SetCustomCLUT 
"SetCustomCLUT: Set the CLUT for the image to clutImage. clutImage must be a 256x1 RGB 
image.";
void SetCustomCLUT( const Image &argument_1, const Image &clutImage );

%feature("docstring") SetDisplayType 
"SetDisplayType: Set the display type of the image. Possible displayType values are 
-1=best, 1=raster image, 2=surface plot, 3=RGB, 4=line plot, 5=spreadsheet.";
void SetDisplayType( const Image &argument_1, long displayType );

%feature("docstring") SetDoCreateCustomIcon 
"SetDoCreateCustomIcon: Open the image with the filename. Returns the opened image.";
void SetDoCreateCustomIcon( const Image &image, bool doCreateCustomIcon );

%feature("docstring") SetDoSavePreview 
"SetDoSavePreview: Sets whether to save a preview along with the saved file.";
void SetDoSavePreview( const Image &image, bool doSavePreview );

%feature("docstring") SetEstimatedMinMax 
"SetEstimatedMinMax: Set the estimated minimum and maximum of the image to min, max. This 
can be used if survey is turned off.";
void SetEstimatedMinMax( const Image &argument_1, float min, float max );

%feature("docstring") SetImagePositionWithinWindow 
"SetImagePositionWithinWindow: Set top-left position of the image to [x,y] within the 
image document.";
void SetImagePositionWithinWindow( const Image &argument_1, long x, long y );

%feature("docstring") SetInversionMode 
"SetInversionMode: Set the contrast of the image to be inverted or not inverted.";
void SetInversionMode( const Image &argument_1, bool inverted );

%feature("docstring") SetLimits 
"SetLimits: Set the lowest and highest displayed pixel values for the image. Everything 
below low will be the 'black' color and every above high will be the 'white' color. The 
black and white colors may not actually be black and white if the color table is not 
greyscale.";
void SetLimits( const Image &argument_1, float low, float high );

%feature("docstring") SetMinContrast 
"SetMinContrast: Set the minimum amount of contrast for the image to minContrast.";
void SetMinContrast( const Image &argument_1, float minContrast );

%feature("docstring") SetName 
"SetName: Sets the name of the image's image document to name.";
void SetName( const Image &argument_1, const char *name );

%feature("docstring") SetOrigin 
"SetOrigin: Set the origin of the image coordinates to [x,y] which are in pixel units.";
void SetOrigin( const Image &argument_1, float x, float y );

%feature("docstring") SetPixel 
"SetPixel: Sets the pixel in the image at [x,y] to value.";
void SetPixel( const Image &argument_1, long x, long y, double value );

%feature("docstring") SetRawStreamPos 
"SetRawStreamPos: Set the current position in rawStream to offset using the mode.";
void SetRawStreamPos( long rawStream, long mode, long offset );

%feature("docstring") SetScale 
"SetScale: Set the scale of the image to [x,y].";
void SetScale( const Image &argument_1, float x, float y );

%feature("docstring") SetSelection 
"SetSelection: Sets the selection of the image to [top,left,bottom,right].";
void SetSelection( const Image &argument_1, long top, long left, long bottom, long right );

%feature("docstring") SetSurvey 
"SetSurvey: Turn surveying on or off for the image.";
void SetSurvey( const Image &argument_1, bool surveyOnOff );

%feature("docstring") SetSurveyTechnique 
"SetSurveyTechnique: Set the survey technique for the image to mode. Mode can be 
0=cross-wire, 1=whole image, 2=sparse.";
void SetSurveyTechnique( const Image &argument_1, short mode );

%feature("docstring") SetToZero 
"SetToZero: Set the image to zero.";
void SetToZero( const Image &argument_1 );

%feature("docstring") SetUnitString 
"SetUnitString: Set the units of the image to unitString.";
void SetUnitString( const Image &argument_1, const char *unitString );

%feature("docstring") SetUsesToZero 
"SetUsesToZero: Mark the image as deletable at scope exit.";
void SetUsesToZero( const Image &argument_1 );

%feature("docstring") SetWindowBounds 
"SetWindowBounds: Set the image's image document window bounds to 
(left,top),(right,bottom).";
void SetWindowBounds( const Image &argument_1, long top, long left, long bottom, long right );

%feature("docstring") SetWindowPosition 
"SetWindowPosition: Set the image's image document window position to [xPos, yPos]. Only 
valid for images that are already shown in a window.";
void SetWindowPosition( const Image &argument_1, long xPos, long yPos );

%feature("docstring") SetWindowSize 
"SetWindowSize: Set the image's image document window size to [width, height].";
void SetWindowSize( const Image &argument_1, long width, long height );

%feature("docstring") SetZoom 
"SetZoom: Set the zoom of the image display.";
void SetZoom( const Image &argument_1, float zoom );

%feature("docstring") ShiftCenter 
"ShiftCenter: Shifts each dimension of an image by half. For two dimensional images it
 will swap quadrants. This is the forward shift function to move the image center
 from (0,0) to (x/2, y/2). To shift it back use the UnShiftCenter function.";
void ShiftCenter( const Image &image );

%feature("docstring") ShiftDown 
"ShiftDown: Returns 1 if the shift key is down and 0 otherwise.";
bool ShiftDown( );

%feature("docstring") ShowAlert 
"ShowAlert: Puts up an alert with the given prompt and style.";
void ShowAlert( const String &prompt, long alertStyle );

%feature("docstring") ShowWarning 
"ShowWarning: Puts up a warning with the given title and prompt with a choice to prevent 
future warnings. Returns 1 for OK and 0 for Cancel.";
bool ShowWarning( const String &title, const String &prompt, bool *do_not_warn_again );

%feature("docstring") Sleep 
"Sleep: Puts the current thread to sleep for the given number of seconds (resolution may 
vary by platform).";
void Sleep( float seconds );

%feature("docstring") SpaceDown 
"SpaceDown: Returns 1 if the space key is down and 0 otherwise.";
bool SpaceDown( );

%feature("docstring") StopAcquisitionDaemon 
"StopAcquisitionDaemon: Stop all acquisition daemons associated with the image.";
void StopAcquisitionDaemon( const Image &argument_1 );

%feature("docstring") StopAllAcquisitionDaemons 
"StopAllAcquisitionDaemons: Stop all acquisition daemons with any image within the 
application.";
void StopAllAcquisitionDaemons( );

%feature("docstring") StringAppend 
"StringAppend: Appends string s2 to s1, converting its encoding to that of s1 if 
necessary.";
String StringAppend( String &s1, const String &s2 );

%feature("docstring") StringAppend 
"StringAppend: Appends character ch to s1, converting its encoding to that of s1 if 
necessary.";
String StringAppend( String &s1, ulong ch, ulong encoding_id );

%feature("docstring") StringCompare 
"StringCompare: Compares strings 's1' and 's2', returning -1,0, or 1 if s1 is less, 
equal, or greater than s2.";
long StringCompare( const String &s1, const String &s2 );

%feature("docstring") StringConvertToEncoding 
"StringConvertToEncoding: Converts 's1' to the encoding specified by 'encoding_id'.";
String StringConvertToEncoding( const String &s1, ulong encoding_id );

%feature("docstring") StringIsValid 
"StringIsValid: Returns true if 'str' is a valid object.";
bool StringIsValid( const String &str );

%feature("docstring") SubtractMeanPacked 
"SubtractMeanPacked: Subtract the mean from the packed image a. No data type checking 
is performed.";
void SubtractMeanPacked( const Image &a );

%feature("docstring") SubtractMultiply 
"SubtractMultiply: Subtract real image b from real image a, multiply the result by 
real image c, and store the result in image a. No data type checking is performed.";
void SubtractMultiply( const Image &a, const Image &b, const Image &c );

%feature("docstring") SurfacePlotImageDisplayGetCubeAxes 
"SurfacePlotImageDisplayGetCubeAxes: Gets the points describing the surface plot cube.";
void SurfacePlotImageDisplayGetCubeAxes( const SurfacePlotImageDisplay &spid, float *x_axis_x, float *x_axis_y, float *y_axis_x, float *y_axis_y, float *z_axis );

%feature("docstring") SurfacePlotImageDisplayGetCubePoint 
"SurfacePlotImageDisplayGetCubePoint: Gets the child coordinates of the cube point 
indicated by 'which_point'";
void SurfacePlotImageDisplayGetCubePoint( const SurfacePlotImageDisplay &spid, long which_point, float *x, float *y );

%feature("docstring") SurfacePlotImageDisplayIsShadingOn 
"SurfacePlotImageDisplayIsShadingOn: Determines whether shading is on or off.";
bool SurfacePlotImageDisplayIsShadingOn( const SurfacePlotImageDisplay &spid );

%feature("docstring") SurfacePlotImageDisplaySetCubeAxes 
"SurfacePlotImageDisplaySetCubeAxes: Sets the points describing the surface plot cube.";
void SurfacePlotImageDisplaySetCubeAxes( const SurfacePlotImageDisplay &spid, float x_axis_x, float x_axis_y, float y_axis_x, float y_axis_y, float z_axis );

%feature("docstring") SurfacePlotImageDisplaySetShadingOn 
"SurfacePlotImageDisplaySetShadingOn: Sets whether shading is on or off.";
void SurfacePlotImageDisplaySetShadingOn( const SurfacePlotImageDisplay &spid, bool on );

%feature("docstring") SurveyNormalPackedModulus 
"SurveyNormalPackedModulus: Survey packed image a and store the minimum and maximum 
values found into the lowLimit and highLimit variables. No data type checking is 
performed.";
void SurveyNormalPackedModulus( const Image &image, float *lowLimit, float *highLimit );

%feature("docstring") SVDecomposition 
"SVDecomposition: Return the image resulting from a SV decomposition on images a,b.";
Image SVDecomposition( const Image &a, const Image &b );

%feature("docstring") SVDFit 
"SVDFit: Return the image resulting from a SVD fit on images a,b with the given tolerance.";
Image SVDFit( const Image &a, const Image &b, float tolerance );

%feature("docstring") SwapByteOrder 
"SwapByteOrder: Swaps the byte order for each long word in the image. ABCD become DCBA.";
void SwapByteOrder( const Image &argument_1 );

%feature("docstring") SwapWordOrder 
"SwapWordOrder: Swaps the byte order for each short word in the image. ABCD become BADC.";
void SwapWordOrder( const Image &argument_1 );

%feature("docstring") TagGroupAddLabeledTagGroup 
"TagGroupAddLabeledTagGroup: Adds 'newGroup' to 'tagGroup' at the label 'label'.";
TagGroup TagGroupAddLabeledTagGroup( const TagGroup &tagGroup, const char *label, const TagGroup &newGroup );

%feature("docstring") TagGroupAddTagGroupAfter 
"TagGroupAddTagGroupAfter: Adds 'newGroup' to 'tagList' after index 'ref_index'.";
TagGroup TagGroupAddTagGroupAfter( const TagGroup &tagList, long ref_index, const TagGroup &newGroup );

%feature("docstring") TagGroupAddTagGroupAtBeginning 
"TagGroupAddTagGroupAtBeginning: Adds 'newGroup' to the beginning of 'tagList'.";
TagGroup TagGroupAddTagGroupAtBeginning( const TagGroup &tagList, const TagGroup &newGroup );

%feature("docstring") TagGroupAddTagGroupAtEnd 
"TagGroupAddTagGroupAtEnd: Adds 'newGroup' to the end of 'tagList'.";
TagGroup TagGroupAddTagGroupAtEnd( const TagGroup &tagList, const TagGroup &newGroup );

%feature("docstring") TagGroupAddTagGroupBefore 
"TagGroupAddTagGroupBefore: Adds 'newGroup' to 'tagList' before index 'ref_index'.";
TagGroup TagGroupAddTagGroupBefore( const TagGroup &tagList, long ref_index, const TagGroup &newGroup );

%feature("docstring") TagGroupClone 
"TagGroupClone: Returns an identical copy of 'tagGroup' and its sub-tags.";
TagGroup TagGroupClone( const TagGroup &tagGroup );

%feature("docstring") TagGroupCopyTag 
"TagGroupCopyTag: Copies the 'srcIndex'th tag in 'srcGroup' to 'tagGroup'.";
long TagGroupCopyTag( const TagGroup &tagGroup, const TagGroup &srcGroup, long srcIndex );

%feature("docstring") TagGroupCopyTagToPath 
"TagGroupCopyTag: Copies the 'srcIndex'th tag in 'srcGroup' to 'tagGroup'.";
long TagGroupCopyTagToPath( const TagGroup &tagGroup, const String &tag_path_dst, const TagGroup &srcGroup, const String &tag_path_src );

%feature("docstring") TagGroupCopyTagsFrom 
"TagGroupCopyTagsFrom: Copies tags in 'srcGroup' to 'tagGroup'.";
void TagGroupCopyTagsFrom( const TagGroup &tagGroup, const TagGroup &srcGroup );

%feature("docstring") TagGroupCopyTagToIndex 
"TagGroupCopyTagToIndex: Copies data in the 'srcIndex'th tag in 'srcGroup' to the 
'dstIndex'th tag in 'tagGroup'.";
void TagGroupCopyTagToIndex( const TagGroup &tagGroup, long dstIndex, const TagGroup &srcGroup, long srcIndex );

%feature("docstring") TagGroupCountTags 
"TagGroupCountTags: Returns the number of sub-tags in this tag group.";
long TagGroupCountTags( const TagGroup &tagGroup );

%feature("docstring") TagGroupCreateGroupTagAfter 
"TagGroupCreateGroupTagAfter: Creates a new tag group after 'ref_index' in 'tagList'.";
TagGroup TagGroupCreateGroupTagAfter( const TagGroup &tagList, long ref_index );

%feature("docstring") TagGroupCreateGroupTagAtBeginning 
"TagGroupCreateGroupTagAtBeginning: Creates a new tag group at the beginning of 'tagList'.";
TagGroup TagGroupCreateGroupTagAtBeginning( const TagGroup &tagList );

%feature("docstring") TagGroupCreateGroupTagAtEnd 
"TagGroupCreateGroupTagAtEnd: Creates a new tag group at the end of 'tagList'.";
TagGroup TagGroupCreateGroupTagAtEnd( const TagGroup &tagList );

%feature("docstring") TagGroupCreateGroupTagBefore 
"TagGroupCreateGroupTagBefore: Creates a new tag group before 'ref_index' in 'tagList'.";
TagGroup TagGroupCreateGroupTagBefore( const TagGroup &tagList, long ref_index );

%feature("docstring") TagGroupCreateListTagAfter 
"TagGroupCreateListTagAfter: Creates a new tag group after 'ref_index' in 'tagList'.";
TagGroup TagGroupCreateListTagAfter( const TagGroup &tagList, long ref_index );

%feature("docstring") TagGroupCreateListTagAtBeginning 
"TagGroupCreateListTagAtBeginning: Creates a new tag group at the beginning of 'tagList'.";
TagGroup TagGroupCreateListTagAtBeginning( const TagGroup &tagList );

%feature("docstring") TagGroupCreateListTagAtEnd 
"TagGroupCreateListTagAtEnd: Creates a new tag group at the end of 'tagList'.";
TagGroup TagGroupCreateListTagAtEnd( const TagGroup &tagList );

%feature("docstring") TagGroupCreateListTagBefore 
"TagGroupCreateListTagBefore: Creates a new tag group before 'ref_index' in 'tagList'.";
TagGroup TagGroupCreateListTagBefore( const TagGroup &tagList, long ref_index );

%feature("docstring") TagGroupCreateNewLabeledGroup 
"TagGroupCreateNewLabeledGroup: Adds a new tag group at label 'label' and returns the new 
group.";
TagGroup TagGroupCreateNewLabeledGroup( const TagGroup &tagGroup, const char *label );

%feature("docstring") TagGroupCreateNewLabeledList 
"TagGroupCreateNewLabeledList: Adds a new tag list at label 'label' and returns the new 
group.";
TagGroup TagGroupCreateNewLabeledList( const TagGroup &tagGroup, const char *label );

%feature("docstring") TagGroupCreateNewLabeledTag 
"TagGroupCreateNewLabeledTag: Creates a new labeled tag and returns its index.";
long TagGroupCreateNewLabeledTag( const TagGroup &tagGroup, const char *label );

%feature("docstring") TagGroupCreateNewTagAfter 
"TagGroupCreateNewTagAfter: Creates a new tag after 'ref_index' in 'tagList'.";
long TagGroupCreateNewTagAfter( const TagGroup &tagList, long ref_index );

%feature("docstring") TagGroupCreateNewTagAtBeginning 
"TagGroupCreateNewTagAtBeginning: Creates a new tag at the beginning of 'tagList'.";
long TagGroupCreateNewTagAtBeginning( const TagGroup &tagList );

%feature("docstring") TagGroupCreateNewTagAtEnd 
"TagGroupCreateNewTagAtEnd: Creates a new tag at the end of 'tagList'.";
long TagGroupCreateNewTagAtEnd( const TagGroup &tagList );

%feature("docstring") TagGroupCreateNewTagBefore 
"TagGroupCreateNewTagBefore: Creates a new tag before 'ref_index' in 'tagList'.";
long TagGroupCreateNewTagBefore( const TagGroup &tagList, long ref_index );

%feature("docstring") TagGroupDeleteAllTags 
"TagGroupDeleteAllTags: Deletes all the tags in 'tagGroup'.";
void TagGroupDeleteAllTags( const TagGroup &tagGroup );

%feature("docstring") TagGroupDeleteTagWithIndex 
"TagGroupDeleteTagWithIndex: Deletes the tag at index 'index'.";
void TagGroupDeleteTagWithIndex( const TagGroup &taGroup, long index );

%feature("docstring") TagGroupDeleteTagWithLabel 
"TagGroupDeleteTagWithLabel: Deletes the tag labelled by the path 'tagPath'. Returns false
if the label could not be found.";
bool TagGroupDeleteTagWithLabel( const TagGroup &tagGroup, const String &tagPath );

%feature("docstring") TagGroupDoesTagExist 
"TagGroupDoesTagExist: Finds the tag group and index corresponding to the tag referenced 
by 'tagPath' in 'tagGroup'.";
bool TagGroupDoesTagExist( const TagGroup &tagGroup, const String &tagPath );

%feature("docstring") TagGroupExecuteScriptGroup 
"TagGroupExecuteScriptGroup: Execute a group of script functions in 'tagGroup'. The 
actual scripts executed will be formed by sprintf'ing into the 'form' parameter.  The 
form parameter should contain exactly one '%s' into which the function name will be 
inserted.";
void TagGroupExecuteScriptGroup( const TagGroup &tagGroup, const char *form );

%feature("docstring") TagGroupGetIndexedTagAsArray 
"TagGroupGetIndexedTagAsArray: Gets the data at 'index' in 'tagGroup' as an array of data 
in 'image'.";
bool TagGroupGetIndexedTagAsArray( const TagGroup &tagGroup, ulong index, const Image &image );

%feature("docstring") TagGroupGetIndexedTagAsBoolean 
"TagGroupGetIndexedTagAsBoolean: Gets the data at 'index' in 'tagGroup' as a boolean.";
bool TagGroupGetIndexedTagAsBoolean( const TagGroup &tagGroup, long index, bool *val );

%feature("docstring") TagGroupGetIndexedTagAsDouble 
"TagGroupGetIndexedTagAsDouble: Gets the data at 'index' in 'tagGroup' as a double.";
bool TagGroupGetIndexedTagAsDouble( const TagGroup &tagGroup, long index, double *number );

%feature("docstring") TagGroupGetIndexedTagAsDoubleComplex 
"TagGroupGetIndexedTagAsDoubleComplex: Gets the data at 'index' in 'tagGroup' as a double 
complex.";
bool TagGroupGetIndexedTagAsDoubleComplex( const TagGroup &tagGroup, long index, complex128_t *c );

%feature("docstring") TagGroupGetIndexedTagAsEightBitColor 
"TagGroupGetIndexedTagAsEightBitColor: Gets the data at 'index' in 'tagGroup' as an eight 
bit color.";
bool TagGroupGetIndexedTagAsEightBitColor( const TagGroup &tagGroup, long index, rgba_uint8_os_t *c );

%feature("docstring") TagGroupGetIndexedTagAsFloat 
"TagGroupGetIndexedTagAsFloat: Gets the data at 'index' in 'tagGroup' as a float.";
bool TagGroupGetIndexedTagAsFloat( const TagGroup &tagGroup, long index, float *number );

%feature("docstring") TagGroupGetIndexedTagAsFloatComplex 
"TagGroupGetIndexedTagAsFloatComplex: Gets the data at 'index' in 'tagGroup' as a float 
complex.";
bool TagGroupGetIndexedTagAsFloatComplex( const TagGroup &tagGroup, long index, complex128_t *c );

%feature("docstring") TagGroupGetIndexedTagAsFloatPoint 
"TagGroupGetIndexedTagAsFloatPoint: Gets the data at 'index' in 'tagGroup' as a float 
point.";
bool TagGroupGetIndexedTagAsFloatPoint( const TagGroup &tagGroup, long index, float *x, float *y );

%feature("docstring") TagGroupGetIndexedTagAsFloatRect 
"TagGroupGetIndexedTagAsFloatRect: Gets the data at 'index' in 'tagGroup' as a float rect.";
bool TagGroupGetIndexedTagAsFloatRect( const TagGroup &tagGroup, long index, float *t, float *l, float *b, float *r );

%feature("docstring") TagGroupGetIndexedTagAsLong 
"TagGroupGetIndexedTagAsLong: Gets the data at 'index' in 'tagGroup' as a long.";
bool TagGroupGetIndexedTagAsLong( const TagGroup &tagGroup, long index, long *number );

%feature("docstring") TagGroupGetIndexedTagAsLongPoint 
"TagGroupGetIndexedTagAsLongPoint: Gets the data at 'index' in 'tagGroup' as a long point.";
bool TagGroupGetIndexedTagAsLongPoint( const TagGroup &tagGroup, long index, SSIZE_T *x, SSIZE_T *y );

%feature("docstring") TagGroupGetIndexedTagAsLongRect 
"TagGroupGetIndexedTagAsLongRect: Gets the data at 'index' in 'tagGroup' as a long rect.";
bool TagGroupGetIndexedTagAsLongRect( const TagGroup &tagGroup, long index, SSIZE_T *t, SSIZE_T *l, SSIZE_T *b, SSIZE_T *r );

%feature("docstring") TagGroupGetIndexedTagAsShort 
"TagGroupGetIndexedTagAsShort: Gets the data at 'index' in 'tagGroup' as a short.";
bool TagGroupGetIndexedTagAsShort( const TagGroup &tagGroup, long index, short *number );

%feature("docstring") TagGroupGetIndexedTagAsShortPoint 
"TagGroupGetIndexedTagAsShortPoint: Gets the data at 'index' in 'tagGroup' as a short 
point.";
bool TagGroupGetIndexedTagAsShortPoint( const TagGroup &tagGroup, long index, short *x, short *y );

%feature("docstring") TagGroupGetIndexedTagAsShortRect 
"TagGroupGetIndexedTagAsShortRect: Gets the data at 'index' in 'tagGroup' as a short rect.";
bool TagGroupGetIndexedTagAsShortRect( const TagGroup &tagGroup, long index, short *t, short *l, short *b, short *r );

%feature("docstring") TagGroupGetIndexedTagAsString 
"TagGroupGetIndexedTagAsString: Gets the data at 'index' in 'tagGroup' as a string.";
bool TagGroupGetIndexedTagAsString( const TagGroup &tagGroup, long index, String &str );

%feature("docstring") TagGroupGetIndexedTagAsTagGroup 
"TagGroupGetIndexedTagAsTagGroup: Gets the data at 'index' in 'TagGroup' as a group.";
bool TagGroupGetIndexedTagAsTagGroup( const TagGroup &tagGroup, long index, TagGroup &subGroup );

%feature("docstring") TagGroupGetIndexedTagAsText 
"TagGroupGetIndexedTagAsText: Gets the data at 'index' in 'tagGroup' as a string.";
bool TagGroupGetIndexedTagAsText( const TagGroup &tagGroup, long index, String &str );

%feature("docstring") TagGroupGetIndexedTagAsUInt16 
"TagGroupGetIndexedTagAsUInt16: Gets the data at 'index' in 'tagGroup' as a 16-bit 
unsigned integer.";
bool TagGroupGetIndexedTagAsUInt16( const TagGroup &tagGroup, long index, uint16 *number );

%feature("docstring") TagGroupGetIndexedTagAsUInt32 
"TagGroupGetIndexedTagAsUInt32: Gets the data at 'index' in 'tagGroup' as a 32-bit 
unsigned integer.";
bool TagGroupGetIndexedTagAsUInt32( const TagGroup &tagGroup, long index, ulong *number );

%feature("docstring") TagGroupGetOrCreateTagGroup 
"TagGroupGetOrCreateTagGroup: Gets the tag group named by 'tagPath', or creates a new 
such group and all necessary intermediate groups.";
TagGroup TagGroupGetOrCreateTagGroup( const TagGroup &tagGroup, const String &tagPath );

%feature("docstring") TagGroupGetOrCreateTagList 
"TagGroupGetOrCreateTagList: Gets the tag list named by 'tagPath', or creates a new such 
list and all necessary intermediate groups.";
TagGroup TagGroupGetOrCreateTagList( const TagGroup &tagGroup, const String &tagPath );

%feature("docstring") TagGroupGetSeeds 
"TagGroupGetSeeds: Gets a set of seeds that describe the tag group.";
long TagGroupGetSeeds( const TagGroup &tagGroup );

%feature("docstring") TagGroupGetTagAsArray 
"TagGroupGetTagAsArray: Gets the data at 'tagPath' in 'tagGroup' as an array of data in 
'image'.";
bool TagGroupGetTagAsArray( const TagGroup &tagGroup, const char *tagPath, const Image &image );

%feature("docstring") TagGroupGetTagAsBoolean 
"TagGroupGetTagAsBoolean: Gets the data at 'tagPath' in 'tagGroup' as a boolean.";
bool TagGroupGetTagAsBoolean( const TagGroup &tags, const String &tag_path, bool *tag_val );

%feature("docstring") TagGroupGetTagAsDouble 
"TagGroupGetTagAsDouble: Gets the data at 'tagPath' in 'tagGroup' as a double.";
bool TagGroupGetTagAsDouble( const TagGroup &tagGroup, const char *tagPath, double *number );

%feature("docstring") TagGroupGetTagAsDoubleComplex 
"TagGroupGetTagAsDoubleComplex: Gets the data at 'tagPath' in 'tagGroup' as a double 
complex.";
bool TagGroupGetTagAsDoubleComplex( const TagGroup &tagGroup, const char *tagPath, complex128_t *c );

%feature("docstring") TagGroupGetTagAsEightBitColor 
"TagGroupGetTagAsEightBitColor: Gets the data at 'tagPath' in 'tagGroup' as an eight bit 
color.";
bool TagGroupGetTagAsEightBitColor( const TagGroup &tagGroup, const char *tagPath, rgba_uint8_os_t *c );

%feature("docstring") TagGroupGetTagAsFloat 
"TagGroupGetTagAsFloat: Gets the data at 'tagPath' in 'tagGroup' as a float.";
bool TagGroupGetTagAsFloat( const TagGroup &tagGroup, const char *tagPath, float *number );

%feature("docstring") TagGroupGetTagAsFloatComplex 
"TagGroupGetTagAsFloatComplex: Gets the data at 'tagPath' in 'tagGroup' as a float 
complex.";
bool TagGroupGetTagAsFloatComplex( const TagGroup &tagGroup, const char *tagPath, complex128_t *c );

%feature("docstring") TagGroupGetTagAsFloatPoint 
"TagGroupGetTagAsFloatPoint: Gets the data at 'tagPath' in 'tagGroup' as a short point.";
bool TagGroupGetTagAsFloatPoint( const TagGroup &tagGroup, const char *tagPath, float *x, float *y );

%feature("docstring") TagGroupGetTagAsFloatRect 
"TagGroupGetTagAsFloatRect: Gets the data at 'tagPath' in 'tagGroup' as a short rect.";
bool TagGroupGetTagAsFloatRect( const TagGroup &tagGroup, const char *tagPath, float *t, float *l, float *b, float *r );

%feature("docstring") TagGroupGetTagAsLong 
"TagGroupGetTagAsLong: Gets the data at 'tagPath' in 'tagGroup' as a long.";
bool TagGroupGetTagAsLong( const TagGroup &tagGroup, const char *tagPath, long *number );

%feature("docstring") TagGroupGetTagAsLongPoint 
"TagGroupGetTagAsLongPoint: Gets the data at 'tagPath' in 'tagGroup' as a long point.";
bool TagGroupGetTagAsLongPoint( const TagGroup &tagGroup, const char *tagPath, long *x, long *y );

%feature("docstring") TagGroupGetTagAsLongRect 
"TagGroupGetTagAsLongRect: Gets the data at 'tagPath' in 'tagGroup' as a long rect.";
bool TagGroupGetTagAsLongRect( const TagGroup &tagGroup, const char *tagPath, long *t, long *l, long *b, long *r );

%feature("docstring") TagGroupGetTagAsRGBUInt16 
"TagGroupGetTagAsRGBUInt16: Gets the data at 'index' in 'tagGroup' as a 16-bit rgb value.";
bool TagGroupGetTagAsRGBUInt16( const TagGroup &tagGroup, long index, uint16 *r, uint16 *g, uint16 *b );

%feature("docstring") TagGroupGetTagAsRGBUInt16 
"TagGroupGetTagAsRGBUInt16: Gets the data at 'tagPath' in 'tagGroup' as a 16-bit rgb 
value.";
bool TagGroupGetTagAsRGBUInt16( const TagGroup &tagGroup, const char *tagPath, uint16 *r, uint16 *g, uint16 *b );

%feature("docstring") TagGroupGetTagAsShort 
"TagGroupGetTagAsShort: Gets the data at 'tagPath' in 'tagGroup' as a short.";
bool TagGroupGetTagAsShort( const TagGroup &tagGroup, const char *tagPath, short *number );

%feature("docstring") TagGroupGetTagAsShortPoint 
"TagGroupGetTagAsShortPoint: Gets the data at 'tagPath' in 'tagGroup' as a short point.";
bool TagGroupGetTagAsShortPoint( const TagGroup &tagGroup, const char *tagPath, short *x, short *y );

%feature("docstring") TagGroupGetTagAsShortRect 
"TagGroupGetTagAsShortRect: Gets the data at 'tagPath' in 'tagGroup' as a short rect.";
bool TagGroupGetTagAsShortRect( const TagGroup &tagGroup, const char *tagPath, short *t, short *l, short *b, short *r );

%feature("docstring") TagGroupGetTagAsString 
"TagGroupGetTagAsString: Gets the data at 'tagPath' in 'tagGroup' as a string.";
bool TagGroupGetTagAsString( const TagGroup &tagGroup, const char *tagPath, String &str );

%feature("docstring") TagGroupGetTagAsTagGroup 
"TagGroupGetTagAsTagGroup: Gets the data at 'tagPath' in 'TagGroup' as a group.";
bool TagGroupGetTagAsTagGroup( const TagGroup &tags, const String &tag_path, TagGroup &sub_tags );

%feature("docstring") TagGroupGetTagAsList 
"TagGroupGetTagAsList: Gets the data at 'tagPath' in 'TagGroup' as a list.";
bool TagGroupGetTagAsList( const TagGroup &tagGroup, const char *tagPath, TagGroup &subGroup );

%feature("docstring") TagGroupGetTagAsText 
"TagGroupGetTagAsText: Gets the data at 'tagPath' in 'tagGroup' as a string.";
bool TagGroupGetTagAsText( const TagGroup &tagGroup, const char *tagPath, String &str );

%feature("docstring") TagGroupGetTagAsUInt16 
"TagGroupGetTagAsUInt16: Gets the data at 'tagPath' in 'tagGroup' as a 16-bit unsigned 
integer.";
bool TagGroupGetTagAsUInt16( const TagGroup &tagGroup, const char *tagPath, uint16 *number );

%feature("docstring") TagGroupGetTagAsUInt32 
"TagGroupGetTagAsUInt32: Gets the data at 'tagPath' in 'tagGroup' as a 32-bit unsigned 
integer.";
bool TagGroupGetTagAsUInt32( const TagGroup &tagGroup, const char *tagPath, ulong *number );

%feature("docstring") TagGroupGetTagLabel 
"TagGroupGetTagLabel: Gets the label of the 'index'th tag in the tag group.";
String TagGroupGetTagLabel( const TagGroup &tagGroup, long index );

%feature("docstring") TagGroupGetTagSize 
"TagGroupGetTagSize: Gets the size of the tag.";
long TagGroupGetTagSize( const TagGroup &tagGroup, long index );

%feature("docstring") TagGroupGetTagType 
"TagGroupGetTagType: Returns the 'type_index'th element of the tag's type.";
long TagGroupGetTagType( const TagGroup &tagGroup, long index, long type_index );

%feature("docstring") TagGroupGetTagTypeLength 
"TagGroupGetTagTypeLength: Returns number of elements in the tag's type.";
long TagGroupGetTagTypeLength( const TagGroup &tagGroup, long index );

%feature("docstring") TagGroupHasChangedSince 
"TagGroupHasChangedSince: Returns true if the tag group has changed since 'seeds' was 
constructed.";
bool TagGroupHasChangedSince( const TagGroup &tagGroup, long seeds );

%feature("docstring") TagGroupInsertTagAsArray 
"TagGroupInsertTagAsArray: Inserts new data before 'ref_index' in 'tagGroup' as an array 
of data in 'image'.";
void TagGroupInsertTagAsArray( const TagGroup &tagGroup, ulong ref_index, const Image &image );

%feature("docstring") TagGroupInsertTagAsBoolean 
"TagGroupInsertTagAsBoolean: Inserts new data before 'ref_index' in 'tagGroup' as a 
boolean.";
void TagGroupInsertTagAsBoolean( const TagGroup &tagGroup, long ref_index, bool val );

%feature("docstring") TagGroupInsertTagAsDouble 
"TagGroupInsertTagAsDouble: Inserts new data before 'ref_index' in 'tagGroup' as a double.";
void TagGroupInsertTagAsDouble( const TagGroup &tagGroup, long ref_index, double number );

%feature("docstring") TagGroupInsertTagAsDoubleComplex 
"TagGroupInsertTagAsDoubleComplex: Inserts new data before 'ref_index' in 'tagGroup' as a 
double complex.";
void TagGroupInsertTagAsDoubleComplex( const TagGroup &tagGroup, long ref_index, const complex128_t &c );

%feature("docstring") TagGroupInsertTagAsEightBitColor 
"TagGroupInsertTagAsEightBitColor: Inserts new data before 'ref_index' in 'tagGroup' as 
an eight bit color.";
void TagGroupInsertTagAsEightBitColor( const TagGroup &tagGroup, long ref_index, rgba_uint8_os_t c );

%feature("docstring") TagGroupInsertTagAsFloat 
"TagGroupInsertTagAsFloat: Inserts new data before 'ref_index' in 'tagGroup' as a float.";
void TagGroupInsertTagAsFloat( const TagGroup &tagGroup, long ref_index, float number );

%feature("docstring") TagGroupInsertTagAsFloatComplex 
"TagGroupInsertTagAsFloatComplex: Inserts new data before 'ref_index' in 'tagGroup' as a 
float complex.";
void TagGroupInsertTagAsFloatComplex( const TagGroup &tagGroup, long ref_index, const complex128_t &c );

%feature("docstring") TagGroupInsertTagAsFloatPoint 
"TagGroupInsertTagAsFloatPoint: Inserts new data before 'ref_index' in 'tagGroup' as a 
float point.";
void TagGroupInsertTagAsFloatPoint( const TagGroup &tagGroup, long ref_index, float x, float y );

%feature("docstring") TagGroupInsertTagAsFloatRect 
"TagGroupInsertTagAsFloatRect: Inserts new data before 'ref_index' in 'tagGroup' as a 
float rect.";
void TagGroupInsertTagAsFloatRect( const TagGroup &tagGroup, long ref_index, float t, float l, float b, float r );

%feature("docstring") TagGroupInsertTagAsLong 
"TagGroupInsertTagAsLong: Inserts new data before 'ref_index' in 'tagGroup' as a long.";
void TagGroupInsertTagAsLong( const TagGroup &tagGroup, long ref_index, long number );

%feature("docstring") TagGroupInsertTagAsLongPoint 
"TagGroupInsertTagAsLongPoint: Inserts new data before 'ref_index' in 'tagGroup' as a 
long point.";
void TagGroupInsertTagAsLongPoint( const TagGroup &tagGroup, long ref_index, long x, long y );

%feature("docstring") TagGroupInsertTagAsLongRect 
"TagGroupInsertTagAsLongRect: Inserts new data before 'ref_index' in 'tagGroup' as a long 
rect.";
void TagGroupInsertTagAsLongRect( const TagGroup &tagGroup, long ref_index, long t, long l, long b, long r );

%feature("docstring") TagGroupInsertTagAsRGBUInt16 
"TagGroupInsertTagAsRGBUInt16: Inserts new data before 'ref_index' in 'tagGroup' as a 
16-bit rgb value.";
void TagGroupInsertTagAsRGBUInt16( const TagGroup &tagGroup, long ref_index, uint16 r, uint16 g, uint16 b );

%feature("docstring") TagGroupInsertTagAsShort 
"TagGroupInsertTagAsShort: Inserts new data before 'ref_index' in 'tagGroup' as a short.";
void TagGroupInsertTagAsShort( const TagGroup &tagGroup, long ref_index, short number );

%feature("docstring") TagGroupInsertTagAsShortPoint 
"TagGroupInsertTagAsShortPoint: Inserts new data before 'ref_index' in 'tagGroup' as a 
short point.";
void TagGroupInsertTagAsShortPoint( const TagGroup &tagGroup, long ref_index, short x, short y );

%feature("docstring") TagGroupInsertTagAsShortRect 
"TagGroupInsertTagAsShortRect: Inserts new data before 'ref_index' in 'tagGroup' as a 
short rect.";
void TagGroupInsertTagAsShortRect( const TagGroup &tagGroup, long ref_index, short t, short l, short b, short r );

%feature("docstring") TagGroupInsertTagAsString 
"TagGroupInsertTagAsString: Inserts new data before 'ref_index' in 'tagGroup' as a string.";
void TagGroupInsertTagAsString( const TagGroup &tagGroup, long ref_index, const String &s );

%feature("docstring") TagGroupInsertTagAsTagGroup 
"TagGroupInsertTagAsTagGroup: Inserts new data before 'ref_index' in 'TagGroup' as a 
group.";
void TagGroupInsertTagAsTagGroup( const TagGroup &tagGroup, long ref_index, const TagGroup &subGroup );

%feature("docstring") TagGroupInsertTagAsText 
"TagGroupInsertTagAsText: Inserts new data before 'ref_index' in 'tagGroup' as a string.";
void TagGroupInsertTagAsText( const TagGroup &tagGroup, long ref_index, const String &s );

%feature("docstring") TagGroupInsertTagAsUInt16 
"TagGroupInsertTagAsUInt16: Inserts new data before 'ref_index' in 'tagGroup' as a 16-bit 
unsigned integer.";
void TagGroupInsertTagAsUInt16( const TagGroup &tagGroup, long ref_index, uint16 number );

%feature("docstring") TagGroupInsertTagAsUInt32 
"TagGroupInsertTagAsUInt32: Inserts new data before 'ref_index' in 'tagGroup' as a 32-bit 
unsigned integer.";
void TagGroupInsertTagAsUInt32( const TagGroup &tagGroup, long ref_index, ulong number );

%feature("docstring") TagGroupIsList 
"TagGroupIsList: Returns true if the tag group is a list.";
bool TagGroupIsList( const TagGroup &tagGroup );

%feature("docstring") TagGroupIsOpen 
"TagGroupIsOpen: Returns whether 'tagGroup' is open or not.";
bool TagGroupIsOpen( const TagGroup &tagGroup );

%feature("docstring") TagGroupIsValid 
"TagGroupIsValid: Returns true if 'tagGroup' references a valid object.";
bool TagGroupIsValid( const TagGroup &tagGroup );

%feature("docstring") TagGroupLoadFromFile 
"TagGroupLoadFromFile: Loads the contents of the file specified by 'path' into the tag 
group.";
bool TagGroupLoadFromFile( const TagGroup &tagGroup, const String &path );

%feature("docstring") TagGroupLoadFromFileWithLabel 
"TagGroupLoadFromFileWithLabel: Loads the contents of the file specified by 'path' into 
the tag group and returns the label, if any.";
bool TagGroupLoadFromFileWithLabel( const TagGroup &tagGroup, const String &path, String &label );

%feature("docstring") TagGroupMarkAsChanged 
"TagGroupMarkAsChanged: Marks 'tagGroup' as having beein modified.";
void TagGroupMarkAsChanged( const TagGroup &tagGroup );

%feature("docstring") TagGroupMergeTagsFrom 
"TagGroupMergeTagsFrom: merges tags from 'srcGroup' into 'tagGroup'.";
void TagGroupMergeTagsFrom( const TagGroup &tagGroup, const TagGroup &srcGroup );

%feature("docstring") TagGroupOpenBrowserWindow 
"TagGroupOpenBrowserWindow: Opens a browser window for the tag group.";
Window TagGroupOpenBrowserWindow( const TagGroup &tagGroup, bool isFileBased );

%feature("docstring") TagGroupParseAndCreateTagPath 
"TagGroupParseAndCreateTagPath: Finds the tag group and index corresponding to the tag 
referenced by 'tagPath' in 'tagGroup'.";
long TagGroupParseAndCreateTagPath( const TagGroup &tagGroup, const String &tagPath, TagGroup &parentGroup, String &label );

%feature("docstring") TagGroupParseTagPath 
"TagGroupParseTagPath: Finds the tag group and index corresponding to the tag referenced 
by 'tagPath' in 'tagGroup'.";
long TagGroupParseTagPath( const TagGroup &tagGroup, const String &tagPath, TagGroup &parentGroup, String &label );

%feature("docstring") TagGroupReleaseSeeds 
"TagGroupReleaseSeeds: Releases the seeds returned by 'TagGroupGetSeeds'.";
void TagGroupReleaseSeeds( const TagGroup &tagGroup, long seeds );

%feature("docstring") TagGroupReplaceTagsWithCopy 
"TagGroupReplaceTagsWithCopy: Deletes all tags in 'tagGroup' and copies tags in 
'srcGroup' to 'tagGroup'.";
void TagGroupReplaceTagsWithCopy( const TagGroup &tagGroup, const TagGroup &srcGroup );

%feature("docstring") TagGroupSaveToFile 
"TagGroupSaveToFile: Saves the contents of the tag group to the file specified by 'path'.";
void TagGroupSaveToFile( const TagGroup &tagGroup, const String &path );

%feature("docstring") TagGroupSaveToFileWithLabel 
"TagGroupSaveToFileWithLabel: Saves the contents of the tag group and the label 'label' 
to the file specified by 'path'.";
void TagGroupSaveToFileWithLabel( const TagGroup &tagGroup, const String &path, const String &label );

%feature("docstring") TagGroupSetIndexedTagAsArray 
"TagGroupSetIndexedTagAsArray: Set the data at 'index' in 'tagGroup' as an array of data 
in 'image'.";
void TagGroupSetIndexedTagAsArray( const TagGroup &tagGroup, ulong index, const Image &image );

%feature("docstring") TagGroupSetIndexedTagAsBoolean 
"TagGroupSetIndexedTagAsBoolean: Sets the data at 'index' in 'tagGroup' as a boolean.";
void TagGroupSetIndexedTagAsBoolean( const TagGroup &tagGroup, long index, bool val );

%feature("docstring") TagGroupSetIndexedTagAsDouble 
"TagGroupSetIndexedTagAsDouble: Sets the data at 'index' in 'tagGroup' as a double.";
void TagGroupSetIndexedTagAsDouble( const TagGroup &tagGroup, long index, double number );

%feature("docstring") TagGroupSetIndexedTagAsDoubleComplex 
"TagGroupSetIndexedTagAsDoubleComplex: Sets the data at 'index' in 'tagGroup' as a double 
complex.";
void TagGroupSetIndexedTagAsDoubleComplex( const TagGroup &tagGroup, long index, const complex128_t &c );

%feature("docstring") TagGroupSetIndexedTagAsEightBitColor 
"TagGroupSetIndexedTagAsEightBitColor: Sets the data at 'index' in 'tagGroup' as an eight 
bit color.";
void TagGroupSetIndexedTagAsEightBitColor( const TagGroup &tagGroup, long index, rgba_uint8_os_t c );

%feature("docstring") TagGroupSetIndexedTagAsFloat 
"TagGroupSetIndexedTagAsFloat: Sets the data at 'index' in 'tagGroup' as a float.";
void TagGroupSetIndexedTagAsFloat( const TagGroup &tagGroup, long index, float number );

%feature("docstring") TagGroupSetIndexedTagAsFloatComplex 
"TagGroupSetIndexedTagAsFloatComplex: Sets the data at 'index' in 'tagGroup' as a float 
complex.";
void TagGroupSetIndexedTagAsFloatComplex( const TagGroup &tagGroup, long index, const complex128_t &c );

%feature("docstring") TagGroupSetIndexedTagAsFloatPoint 
"TagGroupSetIndexedTagAsFloatPoint: Sets the data at 'index' in 'tagGroup' as a float 
point.";
void TagGroupSetIndexedTagAsFloatPoint( const TagGroup &tagGroup, long index, float x, float y );

%feature("docstring") TagGroupSetIndexedTagAsFloatRect 
"TagGroupSetIndexedTagAsFloatRect: Sets the data at 'index' in 'tagGroup' as a float rect.";
void TagGroupSetIndexedTagAsFloatRect( const TagGroup &tagGroup, long index, float t, float l, float b, float r );

%feature("docstring") TagGroupSetIndexedTagAsLong 
"TagGroupSetIndexedTagAsLong: Sets the data at 'index' in 'tagGroup' as a long.";
void TagGroupSetIndexedTagAsLong( const TagGroup &tagGroup, long index, long number );

%feature("docstring") TagGroupSetIndexedTagAsLongPoint 
"TagGroupSetIndexedTagAsLongPoint: Sets the data at 'index' in 'tagGroup' as a long point.";
void TagGroupSetIndexedTagAsLongPoint( const TagGroup &tagGroup, long index, SSIZE_T x, SSIZE_T y );

%feature("docstring") TagGroupSetIndexedTagAsLongRect 
"TagGroupSetIndexedTagAsLongRect: Sets the data at 'index' in 'tagGroup' as a long rect.";
void TagGroupSetIndexedTagAsLongRect( const TagGroup &tagGroup, long index, SSIZE_T t, SSIZE_T l, SSIZE_T b, SSIZE_T r );

%feature("docstring") TagGroupSetIndexedTagAsRGBUInt16 
"TagGroupSetIndexedTagAsRGBUInt16: Sets the data at 'index' in 'tagGroup' as a 16-bit rgb 
value.";
void TagGroupSetIndexedTagAsRGBUInt16( const TagGroup &tagGroup, long index, uint16 r, uint16 g, uint16 b );

%feature("docstring") TagGroupSetIndexedTagAsShort 
"TagGroupSetIndexedTagAsShort: Sets the data at 'index' in 'tagGroup' as a short.";
void TagGroupSetIndexedTagAsShort( const TagGroup &tagGroup, long index, short number );

%feature("docstring") TagGroupSetIndexedTagAsShortPoint 
"TagGroupSetIndexedTagAsShortPoint: Sets the data at 'index' in 'tagGroup' as a short 
point.";
void TagGroupSetIndexedTagAsShortPoint( const TagGroup &tagGroup, long index, short x, short y );

%feature("docstring") TagGroupSetIndexedTagAsShortRect 
"TagGroupSetIndexedTagAsShortRect: Sets the data at 'index' in 'tagGroup' as a short rect.";
void TagGroupSetIndexedTagAsShortRect( const TagGroup &tagGroup, long index, short t, short l, short b, short r );

%feature("docstring") TagGroupSetIndexedTagAsString 
"TagGroupSetIndexedTagAsString: Sets the data at 'index' in 'tagGroup' as a string.";
void TagGroupSetIndexedTagAsString( const TagGroup &tagGroup, long index, const String &s );

%feature("docstring") TagGroupSetIndexedTagAsTagGroup 
"TagGroupSetIndexedTagAsTagGroup: Sets the data at 'index' in 'TagGroup' as a group.";
void TagGroupSetIndexedTagAsTagGroup( const TagGroup &tagGroup, long index, const TagGroup &subGroup );

%feature("docstring") TagGroupSetIndexedTagAsText 
"TagGroupSetIndexedTagAsText: Sets the data at 'index' in 'tagGroup' as a string.";
void TagGroupSetIndexedTagAsText( const TagGroup &tagGroup, long index, const String &s );

%feature("docstring") TagGroupSetIndexedTagAsUInt16 
"TagGroupSetIndexedTagAsUInt16: Sets the data at 'index' in 'tagGroup' as a 16-bit 
unsigned integer.";
void TagGroupSetIndexedTagAsUInt16( const TagGroup &tagGroup, long index, uint16 number );

%feature("docstring") TagGroupSetIndexedTagAsUInt32 
"TagGroupSetIndexedTagAsUInt32: Sets the data at 'index' in 'tagGroup' as a 32-bit 
unsigned integer.";
void TagGroupSetIndexedTagAsUInt32( const TagGroup &tagGroup, long index, ulong number );

%feature("docstring") TagGroupSetIsOpen 
"TagGroupSetIsOpen: Sets whether 'tagGroup' is open or not.";
void TagGroupSetIsOpen( const TagGroup &tagGroup, bool is_open );

%feature("docstring") TagGroupSetTagAsArray 
"TagGroupSetTagAsArray: Set the data at 'tagPath' in 'tagGroup' as an array of data in 
'image'.";
void TagGroupSetTagAsArray( const TagGroup &tagGroup, const char *tagPath, const Image &image );

%feature("docstring") TagGroupSetTagAsBoolean 
"TagGroupSetTagAsBoolean: Sets the data at 'tagPath' in 'tagGroup' as a boolean.";
void TagGroupSetTagAsBoolean( const TagGroup &tagGroup, const char *tagPath, bool val );

%feature("docstring") TagGroupSetTagAsDouble 
"TagGroupSetTagAsDouble: Sets the data at 'tagPath' in 'tagGroup' as a double.";
void TagGroupSetTagAsDouble( const TagGroup &tagGroup, const char *tagPath, double number );

%feature("docstring") TagGroupSetTagAsDoubleComplex 
"TagGroupSetTagAsDoubleComplex: Sets the data at 'tagPath' in 'tagGroup' as a double 
complex.";
void TagGroupSetTagAsDoubleComplex( const TagGroup &tagGroup, const char *tagPath, const complex128_t &c );

%feature("docstring") TagGroupSetTagAsEightBitColor 
"TagGroupSetTagAsEightBitColor: Sets the data at 'tagPath' in 'tagGroup' as an eight bit 
color.";
void TagGroupSetTagAsEightBitColor( const TagGroup &tagGroup, const char *tagPath, rgba_uint8_os_t c );

%feature("docstring") TagGroupSetTagAsFloat 
"TagGroupSetTagAsFloat: Sets the data at 'tagPath' in 'tagGroup' as a float.";
void TagGroupSetTagAsFloat( const TagGroup &tagGroup, const char *tagPath, float number );

%feature("docstring") TagGroupSetTagAsFloatComplex 
"TagGroupSetTagAsFloatComplex: Sets the data at 'tagPath' in 'tagGroup' as a float 
complex.";
void TagGroupSetTagAsFloatComplex( const TagGroup &tagGroup, const char *tagPath, const complex128_t &c );

%feature("docstring") TagGroupSetTagAsFloatPoint 
"TagGroupSetTagAsFloatPoint: Sets the data at 'tagPath' in 'tagGroup' as a float point.";
void TagGroupSetTagAsFloatPoint( const TagGroup &tagGroup, const char *tagPath, float x, float y );

%feature("docstring") TagGroupSetTagAsFloatRect 
"TagGroupSetTagAsFloatRect: Sets the data at 'tagPath' in 'tagGroup' as a float rect.";
void TagGroupSetTagAsFloatRect( const TagGroup &tagGroup, const char *tagPath, float t, float l, float b, float r );

%feature("docstring") TagGroupSetTagAsLong 
"TagGroupSetTagAsLong: Sets the data at 'tagPath' in 'tagGroup' as a long.";
void TagGroupSetTagAsLong( const TagGroup &tagGroup, const char *tagPath, long number );

%feature("docstring") TagGroupSetTagAsLongPoint 
"TagGroupSetTagAsLongPoint: Sets the data at 'tagPath' in 'tagGroup' as a long point.";
void TagGroupSetTagAsLongPoint( const TagGroup &tagGroup, const char *tagPath, long x, long y );

%feature("docstring") TagGroupSetTagAsLongRect 
"TagGroupSetTagAsLongRect: Sets the data at 'tagPath' in 'tagGroup' as a long rect.";
void TagGroupSetTagAsLongRect( const TagGroup &tagGroup, const char *tagPath, long t, long l, long b, long r );

%feature("docstring") TagGroupSetTagAsRGBUInt16 
"TagGroupSetTagAsRGBUInt16: Sets the data at 'tagPath' in 'tagGroup' as a 16-bit rgb 
value.";
void TagGroupSetTagAsRGBUInt16( const TagGroup &tagGroup, const char *tagPath, uint16 r, uint16 g, uint16 b );

%feature("docstring") TagGroupSetTagAsShort 
"TagGroupSetTagAsShort: Sets the data at 'tagPath' in 'tagGroup' as a short.";
void TagGroupSetTagAsShort( const TagGroup &tagGroup, const char *tagPath, short number );

%feature("docstring") TagGroupSetTagAsShortPoint 
"TagGroupSetTagAsShortPoint: Sets the data at 'tagPath' in 'tagGroup' as a short point.";
void TagGroupSetTagAsShortPoint( const TagGroup &tagGroup, const char *tagPath, short x, short y );

%feature("docstring") TagGroupSetTagAsShortRect 
"TagGroupSetTagAsShortRect: Sets the data at 'tagPath' in 'tagGroup' as a short rect.";
void TagGroupSetTagAsShortRect( const TagGroup &tagGroup, const char *tagPath, short t, short l, short b, short r );

%feature("docstring") TagGroupSetTagAsString 
"TagGroupSetTagAsString: Sets the data at 'tagPath' in 'tagGroup' as a string.";
void TagGroupSetTagAsString( const TagGroup &tagGroup, const char *tagPath, const String &s );

%feature("docstring") TagGroupSetTagAsTagGroup 
"TagGroupSetTagAsTagGroup: Sets the data at 'tagPath' in 'TagGroup' as a group.";
void TagGroupSetTagAsTagGroup( const TagGroup &tags, const String &tag_path, const TagGroup &tag_val );

%feature("docstring") TagGroupSetTagAsText 
"TagGroupSetTagAsText: Sets the data at 'tagPath' in 'tagGroup' as a string.";
void TagGroupSetTagAsText( const TagGroup &tagGroup, const char *tagPath, const String &s );

%feature("docstring") TagGroupSetTagAsUInt16 
"TagGroupSetTagAsUInt16: Sets the data at 'tagPath' in 'tagGroup' as a 16-bit unsigned 
integer.";
void TagGroupSetTagAsUInt16( const TagGroup &tagGroup, const char *tagPath, uint16 number );

%feature("docstring") TagGroupSetTagAsUInt32 
"TagGroupSetTagAsUInt32: Sets the data at 'tagPath' in 'tagGroup' as a 32-bit unsigned 
integer.";
void TagGroupSetTagAsUInt32( const TagGroup &tagGroup, const char *tagPath, ulong number );

%feature("docstring") TagGroupSetTagRGBBitmap 
"TagGroupSetTagRGBBitmap: Sets the data at 'tagPath' in 'tagGroup' as a RGB bitmap.";
void TagGroupSetTagRGBBitmap( const TagGroup &tagGroup, const char *tagPath, const Image &image );

%feature("docstring") TextAnnotationGetAlignment 
"TextAnnotationGetAlignment: Gets the alignment of the text in the text annotation.";
long TextAnnotationGetAlignment( const Component &comp );

%feature("docstring") TextAnnotationGetFixedPoint 
"TextAnnotationGetFixedPoint: Gets the fixed point of the text annotation.";
void TextAnnotationGetFixedPoint( const Component &comp, float *x, float *y );

%feature("docstring") TextAnnotationGetResizeStyle 
"TextAnnotationGetResizeStyle: Gets the resize style of the text annotation.";
long TextAnnotationGetResizeStyle( const Component &comp );

%feature("docstring") TextAnnotationGetText 
"TextAnnotationGetText: Gets the text of a text annotation.";
String TextAnnotationGetText( const Component &comp );

%feature("docstring") TextAnnotationSetAlignment 
"TextAnnotationSetAlignment: Sets the alignment of the text in the text annotation.";
void TextAnnotationSetAlignment( const Component &comp, long alignment );

%feature("docstring") TextAnnotationSetFixedPoint 
"TextAnnotationSetFixedPoint: Sets the fixed point of the text annotation.";
void TextAnnotationSetFixedPoint( const Component &comp, float x, float y );

%feature("docstring") TextAnnotationSetResizeStyle 
"TextAnnotationSetResizeStyle: Sets the resize style of the text annotation.";
void TextAnnotationSetResizeStyle( const Component &comp, long style );

%feature("docstring") TextAnnotationSetText 
"TextAnnotationSetText: Sets the text of a text annotation.";
void TextAnnotationSetText( const Component &comp, const String &text );

%feature("docstring") ThrowableIsValid 
"ThrowableIsValid: Returns true if 'throw_' is a valid object.";
bool ThrowableIsValid( const Throwable &throw_ );

%feature("docstring") TickCount 
"TickCount: Return the MacOS system tick count.";
uint32 TickCount( );

%feature("docstring") TransferTagsAndApplyDataBar 
"TransferTagsAndApplyDataBar: Transfer tags and apply data bar to the image. (Deprecated, use
 AutoApplyDefaultLayout instead.)";
void TransferTagsAndApplyDataBar( const Image &argument_1 );

%feature("docstring") TransformPointFromImageToWindow 
"TransformPointFromImageToWindow: Place in (x_window,y_window) the";
void TransformPointFromImageToWindow( const Image &image, float x_image, float y_image, float *x_window, float *y_window );

%feature("docstring") TrapException 
"TrapException: Mark the exception to be thrown upon return external function call.";
void TrapException( short error, long context );

%feature("docstring") TryToUse 
"TryToUse: Look for an image with the given name, width, height, dataType, and position 
[h,v]. Return it if found and create it if not. Store 1 into fresh if it was created and 
0 if not.";
Image TryToUse( const char *name, long width, long height, short dataType, short h, short v, bool *fresh );

%feature("docstring") TurboFFT 
"TurboFFT: Perform a turbo FFT on the real image fft minus the real dark image and 
multiplied by the real gain image. Store the resulting FFT into the packed complex image 
fft. Copy the sub-area of unsigned 1-byte integer image src indicated by 
[top,left,bottom,right] to dst. The rowBytes parameter indicates the length of the row of 
dst. To copy to the screen, pass 0 for dst and rowBytes. The real buffer image is a 
scratch area. No data type checking is performed.";
void TurboFFT( const Image &buffer, const Image &fft, const Image &dark, const Image &gain, long top, long left, long bottom, long right, long dst, long rowBytes );

%feature("docstring") TwoButtonDialog 
"TwoButtonDialog: Puts up a dialog with the given prompt and two buttons labeled 
according to the parameters. Returns 1 for the acceptLabel button and false for the other 
one.";
bool TwoButtonDialog( const char *prompt, const char *acceptLabel, const char *rejectLabel );

%feature("docstring") UpdateDataBar 
"UpdateDataBar: causes an update of the live data bar components based on the passed image.";
void UpdateDataBar( const Image &argument_1 );

%feature("docstring") UpdateDataBar 
"UpdateDataBar: causes an update of the live data bar components or of all data bar elements,
based on the passed image.";
void UpdateDataBar( const Image &argument_1, bool update_all );

%feature("docstring") ApplyDefaultLayout 
"ApplyDefaultLayout: applies a default layout to the image document containing the zero'th 
image display of this image. The default layout may include a scalemark and/or a databar.
In the page mode the layout includes image display position(s). The databar components are generated based
on the tags on this image.";
void ApplyDefaultLayout(const Image &img);

%feature("docstring") AutoApplyDefaultLayout 
"AutoApplyDefaultLayout: checks DM preferences and optionally applies a default layout to the 
image document containing the zero'th image display of this image. The default layout may 
include a scalemark and/or a databar. In the page mode the layout includes image display position(s). 
The databar components are generated based on the tags on this image.";
void AutoApplyDefaultLayout(const Image &img);

%feature("docstring") UnregisterCustomMenu 
"UnregisterCustomMenu: Unregister a custom menu. See the SDK documentation for more 
information.";
void UnregisterCustomMenu( long menuHandlerToken );

%feature("docstring") UnregisterCustomTool 
"UnregisterCustomTool: Remove the tool to the custom tool list. See the SDK documentation 
for more information.";
void UnregisterCustomTool( ULONG_PTR toolToken );

%feature("docstring") UnregisterObjectListener 
"UnregisterObjectListener: Remove object listener from OM object. See the SDK 
documentation for more information.";
void UnregisterObjectListener( ulong_ptr_t object, ulong_ptr_t id );

%feature("docstring") UnregisterSystemIdle 
"UnregisterSystemIdle: Unregister a system idle procedure.";
void UnregisterSystemIdle( SystemIdleProc SystemIdleProc );

%feature("docstring") UnShiftCenter 
"UnShiftCenter: Shifts each dimension of an image by half. For two dimensional images it
 will swap quadrants. This is the backward shift function to move the image center
 from (x/2, y/2) to (0,0). To shift it forward use the ShiftCenter function.";
void UnShiftCenter( const Image &image );

%feature("docstring") UpdateDisplay 
"UpdateDisplay: Update the image display portion that displays the image rows from 
startRow to endRow.";
void UpdateDisplay( const Image &argument_1, long startRow, long endRow );

%feature("docstring") UpdateImage 
"UpdateImage: Update the image immediately.";
void UpdateImage( const Image &argument_1 );

%feature("docstring") UpdateTimeBarPercentage 
"UpdateTimeBarPercentage: Updates an open time bar to the given percentage.";
void UpdateTimeBarPercentage( float percentage );

%feature("docstring") ValidateSurvey 
"ValidateSurvey: Do the survey if necessary.";
void ValidateSurvey( const Image &argument_1 );

%feature("docstring") variance 
"variance: Return the variance of the image.";
float variance( const Image &argument_1 );

%feature("docstring") WindowClose 
"WindowClose: Closes the window, prompting the user if 'verify' is true.";
void WindowClose( const Window &window, bool verify );

%feature("docstring") WindowGetCurrentFile 
"WindowGetCurrentFile: Gets the file name of the window's document.";
String WindowGetCurrentFile( const Window &window );

%feature("docstring") WindowGetContentBounds 
"WindowGetContentBounds: Gets the bounding rectangle of the content area of the 'window'.";
void WindowGetContentBounds( const Window &window, long *top, long *left, long *bottom, long *right );

%feature("docstring") WindowGetContentPosition 
"WindowGetContentPosition: Gets the position of the top-left corner of the content area 
of the 'window'.";
void WindowGetContentPosition( const Window &window, long *x, long *y );

%feature("docstring") WindowGetContentSize 
"WindowGetContentSize: Gets the size of the content area of the 'window'.";
void WindowGetContentSize( const Window &window, long *x, long *y );

%feature("docstring") WindowGetFrameBounds 
"WindowGetFrameBounds: Gets the bounding rectangle of the frame area of the 'window'.";
void WindowGetFrameBounds( const Window &window, long *top, long *left, long *bottom, long *right );

%feature("docstring") WindowGetFramePosition 
"WindowGetFramePosition: Gets the position of the top-left corner of the frame area of 
the 'window'.";
void WindowGetFramePosition( const Window &window, long *x, long *y );

%feature("docstring") WindowGetFrameSize 
"WindowGetFrameSize: Gets the size of the frame area of the 'window'.";
void WindowGetFrameSize( const Window &window, long *x, long *y );

%feature("docstring") WindowGetMousePosition 
"WindowGetMousePosition: Gets the current position of the mouse in the windows coordinate 
system.";
void WindowGetMousePosition( const Window &window, long *x, long *y );

%feature("docstring") WindowGetTitle 
"WindowGetTitle: Gets the title of the window.";
String WindowGetTitle( const Window &window );

%feature("docstring") WindowGetType 
"WindowGetType: Gets the type of the window.";
long WindowGetType( const Window &window );

%feature("docstring") WindowGetViewState 
"WindowGetViewState: Gets the view state of the window. (0 normal, 1 maximized, 2 minimized";
long WindowGetViewState( const Window &window );

%feature("docstring") WindowHide 
"WindowHide: Hides the window.";
void WindowHide( const Window &window );

%feature("docstring") WindowIsOpen 
"WindowIsOpen: Returns true if the window has not been closed.";
bool WindowIsOpen( const Window &window );

%feature("docstring") WindowIsShown 
"WindowIsShown: Returns true if the window is shown.";
bool WindowIsShown( const Window &window );

%feature("docstring") WindowIsValid 
"WindowIsValid: Returns true if 'window' points to a valid object.";
bool WindowIsValid( const Window &window );

%feature("docstring") WindowSelect 
"WindowSelect: Brings 'window' to the front.";
void WindowSelect( const Window &window );

%feature("docstring") WindowSendBehind 
"WindowSendBehind: Sends 'window' behind 'behind_window'.";
void WindowSendBehind( const Window &window, const Window &behind_window );

%feature("docstring") WindowSetCurrentFile 
"WindowSetCurrentFile: Sets the file of the window's document to the specified file.";
void WindowSetCurrentFile( const Window &window, const String &file_path_tok );

%feature("docstring") WindowSetContentBounds 
"WindowSetContentBounds: Sets the bounding rectangle of the content area of the 'window'.";
void WindowSetContentBounds( const Window &window, long top, long left, long bottom, long right );

%feature("docstring") WindowSetContentPosition 
"WindowSetContentPosition: Sets the position of the top-left corner of the content area 
of the 'window'.";
void WindowSetContentPosition( const Window &window, long x, long y );

%feature("docstring") WindowSetContentSize 
"WindowSetContentSize: Sets the size of the content area of the 'window'.";
void WindowSetContentSize( const Window &window, long x, long y );

%feature("docstring") WindowSetFrameBounds 
"WindowSetFrameBounds: Sets the bounding rectangle of the frame area of the 'window'.";
void WindowSetFrameBounds( const Window &window, long top, long left, long bottom, long right );

%feature("docstring") WindowSetFramePosition 
"WindowSetFramePosition: Sets the position of the top-left corner of the frame area of 
the 'window'.";
void WindowSetFramePosition( const Window &window, long x, long y );

%feature("docstring") WindowSetFrameSize 
"WindowSetFrameSize: Sets the size of the frame area of the 'window'.";
void WindowSetFrameSize( const Window &window, long x, long y );

%feature("docstring") WindowSetTitle 
"WindowSetTitle: Sets the title of the window.";
void WindowSetTitle( const Window &window, const String &title );

%feature("docstring") WindowSetViewState 
"WindowSetViewState: sets the view type of the window (0 normal,1 maximized, 2 minimized.";
void WindowSetViewState( const Window &window, long viewState );

%feature("docstring") WindowShow 
"WindowShow: Shows the window.";
void WindowShow( const Window &window );

%feature("docstring") WindowUpdate 
"WindowUpdate: Updates 'window's display.";
void WindowUpdate( const Window &window );

%feature("docstring") SetFloatingWindowHeight 
"SetFloatingWindowHeight: sets height of a named floating window (DM palette).
 If the window is docked, the adjustment causes re-computation and an update of the docking 
 column layout.";
void SetFloatingWindowHeight(const String &name, long height);

%feature("docstring") WriteFile 
"WriteFile: Write the string to the file.";
void WriteFile( DM_FileReference file, const String &data );

%feature("docstring") WriteRawStream 
"WriteRawStream: Write length bytes from the memory pointed to by data to rawStream.";
void WriteRawStream( long rawStream, long data, long length );

%feature("docstring") XX_GetProcessKey 
"XX_GetProcessKey: Return a keystroke associated with the background process indicated by 
pid.";
short XX_GetProcessKey( long pid );

%feature("docstring") XX_InstallImageProcess 
"XX_InstallImageProcess: Associate the process indicated by pid with the image. 
Keystrokes going to the image will queue in the process after this call.";
void XX_InstallImageProcess( const Image &argument_1, long pid );

%feature("docstring") Yield 
"Yield: Yield to another background task.";
void Yield( );

%feature("docstring") SetForbidScriptDialogFlag 
"SetForbidScriptDialogFlag: Sets flag that allows to disable script dialogs implemented in 
Scriptdialog.cpp";
bool SetForbidScriptDialogFlag( bool flag );

}
}
#endif // _GATAN_PLUGIN_DIGITALMICROGRAPH_FUNCTIONS
