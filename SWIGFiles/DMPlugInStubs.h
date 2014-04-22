//
// Copyright 1999, Gatan Inc.  All Rights Reserved.
// FILE IS COMPUTER GENERATED -- DO NOT MODIFY!
// Generated with "CreatePlugInInterfaceFiles()" script function.
// Generated on 9/29/99 at 6:00:57 PM.
//

#ifndef _GATAN_PLUGIN_DIGITALMICROGRAPH_FUNCTIONS
#define _GATAN_PLUGIN_DIGITALMICROGRAPH_FUNCTIONS

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

/********************************************************************************************
 AbortAcquisitionDaemon: Abort all acquisition daemons associated with the image.
********************************************************************************************/
void AbortAcquisitionDaemon( const Image &argument_1 );


/********************************************************************************************
 AbortAllAcquisitionDaemons: Abort all acquisition daemons with any image within the 
application.
********************************************************************************************/
void AbortAllAcquisitionDaemons( );


/********************************************************************************************
 AddCustomTool: Add the tool to the custom tool list. See the SDK documentation for more 
information.
********************************************************************************************/
void AddCustomTool( const char *icon, long toolInstance );


/********************************************************************************************
 AddFunction: Uses the prototype string to define a function for use in the script 
language.
********************************************************************************************/
void AddFunction( const char *prototype, void *function );


/********************************************************************************************
 AddPathToCopyToImageList: Adds 'path' to the list of tags to transfer to acquired images.
********************************************************************************************/
void AddPathToCopyToImageList( const char *path );


/********************************************************************************************
 AddScriptFileToMenu: Install the script in the file indicated by fileName into the 
application. The commandName indicates the string by which this script will be known to 
the application. If the script is to be installed in the menu, the menuName and 
optionalSubMenuName parameters specify the menu. Pass 1 for isLibrary if the script is a 
library only and 0 to install it in the menu.
********************************************************************************************/
void AddScriptFileToMenu( const char *fileName, const char *commandName, const char 
*menuName, const char *optionalSubMenuName, bool isLibrary );


/********************************************************************************************
 AddScriptFileToPackage: Install the script in the file indicated by fileName into the 
package. The commandName indicates the string by which this script will be known to the 
application. If the script is to be installed in the menu, the menuName and 
optionalSubMenuName parameters specify the menu. Pass 1 for isLibrary if the script is a 
library only and 0 to install it in the menu.
********************************************************************************************/
void AddScriptFileToPackage( const char *fileName, const char *packageName, long 
packageLevel, const char *commandName, const char *menuName, const char 
*optionalSubMenuName, bool isLibrary );


/********************************************************************************************
 AddScriptToMenu: Install the script into the application. The commandName indicates the 
string by which this script will be known to the application. If the script is to be 
installed in the menu, the menuName and optionalSubMenuName parameters specify the menu. 
Pass 1 for isLibrary if the script is a library only and 0 to install it in the menu.
********************************************************************************************/
void AddScriptToMenu( const char *script, const char *commandName, const char *menuName, 
const char *optionalSubMenuName, bool isLibrary );


/********************************************************************************************
 AddScriptToPackage: Install the script into the application. The commandName indicates 
the string by which this script will be known to the application. If the script is to be 
installed in the menu, the menuName and optionalSubMenuName parameters specify the menu. 
Pass 1 for isLibrary if the script is a library only and 0 to install it in the menu.
********************************************************************************************/
void AddScriptToPackage( const char *script, const char *packageName, long packageLevel, 
const char *commandName, const char *menuName, const char *optionalSubMenuName, bool 
isLibrary );


/********************************************************************************************
 AddTagsToPackage: Install the tags into the package. The identifier is used to identify 
the tags in the packages. Clients should take care to use unique identifiers. See the 
Java model of naming classes.
********************************************************************************************/
void AddTagsToPackage( const TagGroup &tags, const char *packageName, long packageLevel, 
const char *identifier );


/********************************************************************************************
 AdjustScriptMenuItem: Adjusts the display characteristics of the given script menu item. 
NewCommandName specifies the new name for the menu item. The menu item will have to be 
referred to by that name from then forth. Enabled/checked indicate whether the item is 
enabled/checked. Key refers to the command key equivalent on the MacOS. Pass 0 to have no 
command key equivalent. AcceleratorPos refers to the position of the accelerator 
equivalent on Windows. Pass -1 to have to accelerator. 
********************************************************************************************/
void AdjustScriptMenuItem( const char *commandName, const char *menuName, const char 
*optionalSubMenuName, const char *newCommandName, bool enabled, bool checked, char key, 
long acceleratorPos );


/********************************************************************************************
 AllocString: Allocates a string used in the script language. Length should include eos 
character.
********************************************************************************************/
long AllocString( long length );


/********************************************************************************************
 ApplicationGetBounds: Gets the bounds of the main area of the application in application 
coordinates.
********************************************************************************************/
void ApplicationGetBounds( long *t, long *l, long *b, long *r );


/********************************************************************************************
 ApplicationGetOrigin: Gets the origin of the application in global coordinates.
********************************************************************************************/
void ApplicationGetOrigin( long *x, long *y );


/********************************************************************************************
 ApplyDataBar: Applies a data bar to the image.
********************************************************************************************/
void ApplyDataBar( const ImageDisplay &imgDisp );


/********************************************************************************************
 ApproveDisplayBuffer: Mark the display buffer as valid.
********************************************************************************************/
void ApproveDisplayBuffer( const Image &argument_1 );


/********************************************************************************************
 ApproveSurvey: Mark the image as already surveyed.
********************************************************************************************/
void ApproveSurvey( const Image &argument_1 );


/********************************************************************************************
 AutoCorrelate: Return an image which is the result of the auto correlation of source.
********************************************************************************************/
Image AutoCorrelate( const Image &source );


/********************************************************************************************
 AutoCorrelation: Return an image which is the result of the auto correlation of source.
********************************************************************************************/
Image AutoCorrelation( const Image &source );


/********************************************************************************************
 Beep: Play the current system beep.
********************************************************************************************/
void Beep( );


/********************************************************************************************
 BinaryImage: Creates a 3D binary image of size [d0,d1,d2] with the given title.
********************************************************************************************/
Image BinaryImage( const char *title, long d0, long d1, long d2 );


/********************************************************************************************
 BinaryImage: Creates a 1D binary image of size [d0] with the given title.
********************************************************************************************/
Image BinaryImage( const char *title, long d0 );


/********************************************************************************************
 BinaryImage: Creates a 2D binary image of size [d0,d1] with the given title.
********************************************************************************************/
Image BinaryImage( const char *title, long d0, long d1 );


/********************************************************************************************
 BrowseTagFile: Present an open file dialog to the user, allow them to select a tag file, 
and then allow them to browse through it.
********************************************************************************************/
void BrowseTagFile( );


/********************************************************************************************
 ChooseMenuItem: Choose the given menu item.
********************************************************************************************/
bool ChooseMenuItem( const char *menu, const char *subMenu, const char *item );


/********************************************************************************************
 ClassAddMethod: 
********************************************************************************************/
Function ClassAddMethod( const String &class_name, const Function &method );


/********************************************************************************************
 ClassNewObject: 
********************************************************************************************/
ScriptObject ClassNewObject( const String &class_name );


/********************************************************************************************
 ClassRemoveMethod: 
********************************************************************************************/
void ClassRemoveMethod( const String &class_name, const Function &method );


/********************************************************************************************
 CleanImage: Mark the image as having been saved.
********************************************************************************************/
void CleanImage( const Image &argument_1 );


/********************************************************************************************
 ClearDisplayBuffer: Clear the display buffer.
********************************************************************************************/
void ClearDisplayBuffer( const Image &argument_1 );


/********************************************************************************************
 ClearSelection: Remove selection (if any) from the image.
********************************************************************************************/
void ClearSelection( const Image &argument_1 );


/********************************************************************************************
 ClipboardGetAsString: Gets the contents of the clipboard as a string with the given 
encoding, if possible, and returns true if successful.
********************************************************************************************/
bool ClipboardGetAsString( String &str );


/********************************************************************************************
 ClipboardGetAsTagGroup: Gets the contents of the clipboard as a tag group, if possible, 
and returns true if successful.
********************************************************************************************/
bool ClipboardGetAsTagGroup( TagGroup &tagGroup );


/********************************************************************************************
 ClipboardSetAsString: Sets the contents of the clipboard to the text.
********************************************************************************************/
void ClipboardSetAsString( const String &argument_1 );


/********************************************************************************************
 ClipboardSetAsTagGroup: Sets the contents of the clipboard to the tag group.
********************************************************************************************/
void ClipboardSetAsTagGroup( const TagGroup &tagGroup );


/********************************************************************************************
 CloseFile: Close the file. This function should be called to close a file whenever a 
file is opened.
********************************************************************************************/
void CloseFile( DM_FileReference file );


/********************************************************************************************
 CloseImage: Attempt to close the image.  If the data has changed, a dialog box appears 
to ask the user to save the image before closing it.
********************************************************************************************/
void CloseImage( const Image &argument_1 );


/********************************************************************************************
 CloseProgressWindow: Close the progress window if it is open.
********************************************************************************************/
void CloseProgressWindow( );


/********************************************************************************************
 CloseTimeBar: Closes the time bar.
********************************************************************************************/
void CloseTimeBar( );


/********************************************************************************************
 CommandDown: Returns 1 if the command key is down and 0 otherwise.
********************************************************************************************/
bool CommandDown( );


/********************************************************************************************
 ComplexImage: Creates a 3D complex image of size [d0,d1,d2] with the given title. The 
bytes parameter can be 8 or 16 for single and double precision floating point numbers.
********************************************************************************************/
Image ComplexImage( const char *title, long bytes, long d0, long d1, long d2 );


/********************************************************************************************
 ComplexImage: Creates a 2D complex image of size [d0,d1] with the given title. The bytes 
parameter can be 8 or 16 for single and double precision floating point numbers.
********************************************************************************************/
Image ComplexImage( const char *title, long bytes, long d0, long d1 );


/********************************************************************************************
 ComplexImage: Creates a 1D complex image of size [d0] with the given title. The bytes 
parameter can be 8 or 16 for single and double precision floating point numbers.
********************************************************************************************/
Image ComplexImage( const char *title, long bytes, long d0 );


/********************************************************************************************
 ComplexToPacked: Creates a new packed complex image from the complex 8-byte source.
********************************************************************************************/
Image ComplexToPacked( const Image &source );


/********************************************************************************************
 ComplexToPacked2: Creates a new packed complex image from the complex 8-byte source.
********************************************************************************************/
Image ComplexToPacked2( const Image &source, long style );


/********************************************************************************************
 ComponentAddChildAfter: Adds 'child' to 'parent's list of sub-annotations after 
'annot_pos'.
********************************************************************************************/
void ComponentAddChildAfter( const Component &parent, const Component &child, const 
Component &annot_pos );


/********************************************************************************************
 ComponentAddChildAtBeginning: Adds 'child' to the beginning of 'parent's list of 
sub-annotations.
********************************************************************************************/
void ComponentAddChildAtBeginning( const Component &parent, const Component &child );


/********************************************************************************************
 ComponentAddChildAtEnd: Adds 'child' to the end of 'parent's list of sub-annotations.
********************************************************************************************/
void ComponentAddChildAtEnd( const Component &parent, const Component &child );


/********************************************************************************************
 ComponentAddChildBefore: Adds 'child' to 'parent's list of sub-annotations before 
'annot_pos'.
********************************************************************************************/
void ComponentAddChildBefore( const Component &parent, const Component &child, const 
Component &annot_pos );


/********************************************************************************************
 ComponentAddNewComponent: Creates a new annotaiton of type 'type' and adds it to 'parent'
********************************************************************************************/
Component ComponentAddNewComponent( const Component &parent, long type, float f1, float 
f2, float f3, float f4 );


/********************************************************************************************
 ComponentClone: Returns a identical copy of the component and all its sub-components, 
copying associated images if 'doDeepCopy' is true.
********************************************************************************************/
Component ComponentClone( const Component &comp, bool doDeepCopy );


/********************************************************************************************
 ComponentCountChildren: Returns the number of sub components.
********************************************************************************************/
long ComponentCountChildren( const Component &comp );


/********************************************************************************************
 ComponentCountChildrenOfType: Returns the number of sub-components of type 'type'.
********************************************************************************************/
long ComponentCountChildrenOfType( const Component &comp, long type );


/********************************************************************************************
 ComponentGetBoundingRect: Gets the bounding rect of the annotation.
********************************************************************************************/
void ComponentGetBoundingRect( const Component &comp, float *t, float *l, float *b, float 
*r );


/********************************************************************************************
 ComponentGetBoundingRectInView: Gets the bounding rect of the annotation.
********************************************************************************************/
void ComponentGetBoundingRectInView( const Component &comp, float *t, float *l, float *b, 
float *r );


/********************************************************************************************
 ComponentGetChild: Returns the 'index'th sub-component of 'comp'.
********************************************************************************************/
Component ComponentGetChild( const Component &comp, long index );


/********************************************************************************************
 ComponentGetChildByID: Returns the component child of 'comp' with id 'ID'.
********************************************************************************************/
Component ComponentGetChildByID( const Component &comp, long ID );


/********************************************************************************************
 ComponentGetChildToLocalTransform: Gets the transformation from  child to local 
coordinates.
********************************************************************************************/
void ComponentGetChildToLocalTransform( const Component &comp, float *off_x, float *off_y,
 float *scale_x, float *scale_y );


/********************************************************************************************
 ComponentGetChildToPageTransform: Gets the transformation from child to page coordinates.
********************************************************************************************/
void ComponentGetChildToPageTransform( const Component &comp, float *off_x, float *off_y, 
float *scale_x, float *scale_y );


/********************************************************************************************
 ComponentGetChildToViewTransform: Gets the transformation from child to view coordinates.
********************************************************************************************/
void ComponentGetChildToViewTransform( const Component &comp, float *off_x, float *off_y, 
float *scale_x, float *scale_y );


/********************************************************************************************
 ComponentGetChildToWindowTransform: Gets the transformation from child to window 
coordinates.
********************************************************************************************/
void ComponentGetChildToWindowTransform( const Component &comp, float *off_x, float 
*off_y, float *scale_x, float *scale_y );


/********************************************************************************************
 ComponentGetControlPoint: Returns the value '(x,y)' associated with the control point, 
and returns 'true' if the control point is valid
********************************************************************************************/
bool ComponentGetControlPoint( const Component &comp, long loc, float *x, float *y );


/********************************************************************************************
 ComponentGetDescendentByID: Returns the component child of 'comp' with id 'ID'.
********************************************************************************************/
Component ComponentGetDescendentByID( const Component &comp, long ID );


/********************************************************************************************
 ComponentGetDrawingMode: Gets the drawing mode of the image doucment component.
********************************************************************************************/
long ComponentGetDrawingMode( const Component &comp );


/********************************************************************************************
 ComponentGetFillMode: Gets the fill mode of the image doucment component.
********************************************************************************************/
long ComponentGetFillMode( const Component &comp );


/********************************************************************************************
 ComponentGetFontAttributes: Gets the attributes of the component's font.
********************************************************************************************/
long ComponentGetFontAttributes( const Component &comp );


/********************************************************************************************
 ComponentGetFontFaceName: Gets the face name of the component's font.
********************************************************************************************/
String ComponentGetFontFaceName( const Component &comp );


/********************************************************************************************
 ComponentGetFontInfo: Gets a description of the component's font.
********************************************************************************************/
void ComponentGetFontInfo( const Component &comp, String &faceName, long *attributes, 
long *size );


/********************************************************************************************
 ComponentGetFontSize: Gets the point size of the component's font.
********************************************************************************************/
long ComponentGetFontSize( const Component &comp );


/********************************************************************************************
 ComponentGetID: Gets the unique identifier of the annotation in the image document.
********************************************************************************************/
long ComponentGetID( const Component &annot );


/********************************************************************************************
 ComponentGetImageDocument: Gets the image document associated with the annotation.
********************************************************************************************/
ImageDocument ComponentGetImageDocument( const Component &annot );


/********************************************************************************************
 ComponentGetLocalToPageTransform: Gets the transformation from local to page coordinates.
********************************************************************************************/
void ComponentGetLocalToPageTransform( const Component &comp, float *off_x, float *off_y, 
float *scale_x, float *scale_y );


/********************************************************************************************
 ComponentGetLocalToViewTransform: Gets the transformation from local to view coordinates.
********************************************************************************************/
void ComponentGetLocalToViewTransform( const Component &comp, float *off_x, float *off_y, 
float *scale_x, float *scale_y );


/********************************************************************************************
 ComponentGetLocalToWindowTransform: Gets the transformation from local to window 
coordinates.
********************************************************************************************/
void ComponentGetLocalToWindowTransform( const Component &comp, float *off_x, float 
*off_y, float *scale_x, float *scale_y );


/********************************************************************************************
 ComponentGetNthChildOfType: Returns the nth sub-component of type 'type'.
********************************************************************************************/
Component ComponentGetNthChildOfType( const Component &comp, long type, long index );


/********************************************************************************************
 ComponentGetParentComponent: Gets the parent component of 'comp', if any.
********************************************************************************************/
Component ComponentGetParentComponent( const Component &comp );


/********************************************************************************************
 ComponentGetParentImageDisplay: Gets the parent image display of the 'comp', if any.
********************************************************************************************/
ImageDisplay ComponentGetParentImageDisplay( const Component &comp );


/********************************************************************************************
 ComponentGetRect: Gets the rectangle of the annotation.
********************************************************************************************/
void ComponentGetRect( const Component &comp, float *top, float *left, float *bottom, 
float *right );


/********************************************************************************************
 ComponentGetRectInView: Gets the rectangle of the annotation.
********************************************************************************************/
void ComponentGetRectInView( const Component &comp, float *top, float *left, float 
*bottom, float *right );


/********************************************************************************************
 ComponentGetTagGroup: Gets the tag group associated with the annotation.
********************************************************************************************/
TagGroup ComponentGetTagGroup( const Component &annot );


/********************************************************************************************
 ComponentGetType: Gets the type of the annotation.
********************************************************************************************/
long ComponentGetType( const Component &annot );


/********************************************************************************************
 ComponentIsOfType: Gets the type of the annotation.
********************************************************************************************/
bool ComponentIsOfType( const Component &annot, long type );


/********************************************************************************************
 ComponentIsSelected: Returns whether the component is selected.
********************************************************************************************/
bool ComponentIsSelected( const Component &comp );


/********************************************************************************************
 ComponentIsValid: Returns true if 'annot' points to a valid object.
********************************************************************************************/
bool ComponentIsValid( const Component &annot );


/********************************************************************************************
 ComponentOffsetControlPoint: Changes the control point 'loc' of 'comp' by '(x,y)' using 
restrictions specified by 'restrict_style'.
********************************************************************************************/
void ComponentOffsetControlPoint( const Component &comp, long loc, float x, float y, long 
restrict_style );


/********************************************************************************************
 ComponentPositionAroundPoint: Moves the annotation so if 'horz', the 'rel_x' horizontal 
point in the bounding rect is at 'new_x', and if 'vert', the 'rel_y' vertical point in 
the bounding rect is at 'new_y'
********************************************************************************************/
void ComponentPositionAroundPoint( const Component &comp, float new_x, float new_y, float 
rel_x, float rel_y, bool horz, bool vert );


/********************************************************************************************
 ComponentRemoveFromParent: Removes the image document component from its parent.
********************************************************************************************/
void ComponentRemoveFromParent( const Component &comp );


/********************************************************************************************
 ComponentSetControlPoint: Sets the control point 'loc' of 'comp' to '(x,y)' using 
restrictions specified by 'restrict_style'.
********************************************************************************************/
void ComponentSetControlPoint( const Component &comp, long loc, float x, float y, long 
restrict_style );


/********************************************************************************************
 ComponentSetDrawingMode: Sets the drawing mode of the image document component.
********************************************************************************************/
void ComponentSetDrawingMode( const Component &comp, long mode );


/********************************************************************************************
 ComponentSetFillMode: Sets the fill mode of the image document component.
********************************************************************************************/
void ComponentSetFillMode( const Component &comp, long mode );


/********************************************************************************************
 ComponentSetFontAttributes: Sets the attributes of the component's font.
********************************************************************************************/
void ComponentSetFontAttributes( const Component &comp, long attributes );


/********************************************************************************************
 ComponentSetFontFaceName: Sets the face name of the component's font.
********************************************************************************************/
void ComponentSetFontFaceName( const Component &comp, const String &face_name );


/********************************************************************************************
 ComponentSetFontInfo: Sets the font information of the component's font.
********************************************************************************************/
void ComponentSetFontInfo( const Component &comp, const String &face_name, long 
attributes, long size );


/********************************************************************************************
 ComponentSetFontSize: Sets the point size of the component's font.
********************************************************************************************/
void ComponentSetFontSize( const Component &comp, long size );


/********************************************************************************************
 ComponentSetRect: Sets the rectangle of the annotation.
********************************************************************************************/
void ComponentSetRect( const Component &comp, float top, float left, float bottom, float 
right );


/********************************************************************************************
 ComponentSetSelected: Sets the selection status of the component.
********************************************************************************************/
void ComponentSetSelected( const Component &comp, bool select );


/********************************************************************************************
 ComponentTransformCoordinates: Transforms the component by the specified transform.
********************************************************************************************/
void ComponentTransformCoordinates( const Component &comp, float off_x, float off_y, 
float scale_x, float scale_y );


/********************************************************************************************
 ConnectObject: Build the connection with the given object and message under ident.
********************************************************************************************/
void ConnectObject( long object, const char *message, const char *ident, const 
ScriptObject &scriptObject, const char *method );


/********************************************************************************************
 ContinueCancelDialog: Puts up a dialog with both a Continue button and Cancel button. 
Returns 1 for Continue and 0 for Cancel.
********************************************************************************************/
bool ContinueCancelDialog( const char *prompt );


/********************************************************************************************
 ControlDown: Returns 1 if the control key is down and 0 otherwise.
********************************************************************************************/
bool ControlDown( );


/********************************************************************************************
 ConvertImageData: 
********************************************************************************************/
void ConvertImageData( const Image &from, const Image &to );


/********************************************************************************************
 ConvertImageDataSlice_2D: 
********************************************************************************************/
void ConvertImageDataSlice_2D( const Image &from, const Image &to, long x_l, long y_l, 
long f_x_0, long f_y_0, long f_x_d, long f_x_s, long f_y_d, long f_y_s, long t_x_0, long 
t_y_0, long t_x_d, long t_x_s, long t_y_d, long t_y_s );


/********************************************************************************************
 ConvertPICTToRGBImage: Convert a PICT stored in a handle to an RGB image.
********************************************************************************************/
Image ConvertPICTToRGBImage( long picture );


/********************************************************************************************
 ConvertToByte: Converts the given image to unsigned integer 1-byte data.
********************************************************************************************/
void ConvertToByte( const Image &argument_1 );


/********************************************************************************************
 ConvertToComplex: Converts the given image to complex single precision data.
********************************************************************************************/
void ConvertToComplex( const Image &argument_1 );


/********************************************************************************************
 ConvertToFloat: Converts the given image to single precision real data.
********************************************************************************************/
void ConvertToFloat( const Image &argument_1 );


/********************************************************************************************
 ConvertToLong: Converts the given image to signed integer 4-byte data.
********************************************************************************************/
void ConvertToLong( const Image &argument_1 );


/********************************************************************************************
 ConvertToPackedComplex: Converts the given image to packed complex data.
********************************************************************************************/
void ConvertToPackedComplex( const Image &argument_1 );


/********************************************************************************************
 ConvertToShort: Converts the given image to signed integer 2-byte data.
********************************************************************************************/
void ConvertToShort( const Image &argument_1 );


/********************************************************************************************
 Convolution: Creates a new image that is the convolution of the source image with the 
kernel. The kernel should be less than 7x7.
********************************************************************************************/
Image Convolution( const Image &source, const Image &kernel );


/********************************************************************************************
 CopyGWorldCTable: Copy the OS Color Table of the image and return it. ( Returns 
CTabHandle for MacOS, HGLOBAL for Windows ).
********************************************************************************************/
long CopyGWorldCTable( const Image &argument_1 );


/********************************************************************************************
 CountAllImages: Returns the number of images.
********************************************************************************************/
long CountAllImages( );


/********************************************************************************************
 CountDocumentWindows: Returns the number of document windows.
********************************************************************************************/
long CountDocumentWindows( );


/********************************************************************************************
 CountDocumentWindowsOfType: Returns the number of document windows with type 'type'.
********************************************************************************************/
long CountDocumentWindowsOfType( long type );


/********************************************************************************************
 CountFloatingWindows: Returns the number of floating windows.
********************************************************************************************/
long CountFloatingWindows( );


/********************************************************************************************
 CountImageDocuments: Returns the number of image documents.
********************************************************************************************/
long CountImageDocuments( );


/********************************************************************************************
 CountImages: Count the number of images.
********************************************************************************************/
long CountImages( );


/********************************************************************************************
 CountScreens: Returns the number of screens.
********************************************************************************************/
long CountScreens( );


/********************************************************************************************
 CountScriptFunctions: Returns the number of script functions having name 'fnName'.
********************************************************************************************/
long CountScriptFunctions( const char *fnName );


/********************************************************************************************
 CreateBinary1DImage: Creates a 1D binary image of size [d0] with the given title.
********************************************************************************************/
Image CreateBinary1DImage( const char *title, long d0 );


/********************************************************************************************
 CreateBinary2DImage: Creates a 2D binary image of size [d0,d1] with the given title.
********************************************************************************************/
Image CreateBinary2DImage( const char *title, long d0, long d1 );


/********************************************************************************************
 CreateBinary3DImage: Creates a 3D binary image of size [d0,d1,d2] with the given title.
********************************************************************************************/
Image CreateBinary3DImage( const char *title, long d0, long d1, long d2 );


/********************************************************************************************
 CreateByteImage: Creates a 2D unsigned 1-byte integer image of size [width,height] with 
the given title.
********************************************************************************************/
Image CreateByteImage( const char *title, long width, long height );


/********************************************************************************************
 CreateComplex1DImage: Creates a 1D complex image of size [d0] with the given title. The 
bytes parameter can be 8 or 16 for single and double precision floating point numbers.
********************************************************************************************/
Image CreateComplex1DImage( const char *title, long bytes, long d0 );


/********************************************************************************************
 CreateComplex2DImage: Creates a 2D complex image of size [d0,d1] with the given title. 
The bytes parameter can be 8 or 16 for single and double precision floating point numbers.
********************************************************************************************/
Image CreateComplex2DImage( const char *title, long bytes, long d0, long d1 );


/********************************************************************************************
 CreateComplex3DImage: Creates a 3D complex image of size [d0,d1,d2] with the given 
title. The bytes parameter can be 8 or 16 for single and double precision floating point 
numbers.
********************************************************************************************/
Image CreateComplex3DImage( const char *title, long bytes, long d0, long d1, long d2 );


/********************************************************************************************
 CreateComplexImage: Creates a 2D single precision complex image of size [width,height] 
with the given title.
********************************************************************************************/
Image CreateComplexImage( const char *title, long width, long height );


/********************************************************************************************
 CreateDirectory: Create a folder named fileName.
********************************************************************************************/
void CreateDirectory( const char *fileName );


/********************************************************************************************
 CreateFile: Create a file named fileName.
********************************************************************************************/
void CreateFile( const char *fileName );


/********************************************************************************************
 CreateFileForWriting: Create and open the file for writing. Return the file reference 
for this file. This call must be balanced with call to CloseFile() with the returned 
reference number.
********************************************************************************************/
DM_FileReference CreateFileForWriting( const char *fileName );


/********************************************************************************************
 CreateFloatImage: Creates a 2D single precision float image of size [width,height] with 
the given title.
********************************************************************************************/
Image CreateFloatImage( const char *title, long width, long height );


/********************************************************************************************
 CreateImageFromDisplay: Convert the display of image to an RGB image.
********************************************************************************************/
Image CreateImageFromDisplay( const Image &argument_1 );


/********************************************************************************************
 CreateInteger1DImage: Creates a 1D integer image of size [d0] with the given title. The 
bytes and isSigned parameters specify integer specific attributes of the data.
********************************************************************************************/
Image CreateInteger1DImage( const char *title, long bytes, bool isSigned, long d0 );


/********************************************************************************************
 CreateInteger2DImage: Creates a 2D integer image of size [d0,d1] with the given title. 
The bytes and isSigned parameters specify integer specific attributes of the data.
********************************************************************************************/
Image CreateInteger2DImage( const char *title, long bytes, bool isSigned, long d0, long 
d1 );


/********************************************************************************************
 CreateInteger3DImage: Creates a 3D integer image of size [d0,d1,d2] with the given 
title. The bytes can be 1, 2, or 4 and isSigned can be 1 (true) or 0 (false).
********************************************************************************************/
Image CreateInteger3DImage( const char *title, long bytes, bool isSigned, long d0, long 
d1, long d2 );


/********************************************************************************************
 CreateLongImage: Creates a 2D signed 4-byte integer image of size [width,height] with 
the given title.
********************************************************************************************/
Image CreateLongImage( const char *title, long width, long height );


/********************************************************************************************
 CreatePackedComplexImage: Creates a 2D packed complex image of size [width,height] with 
the given title.
********************************************************************************************/
Image CreatePackedComplexImage( const char *title, long width, long height );


/********************************************************************************************
 CreateReal1DImage: Creates a 1D real image of size [d0] with the given title. The bytes 
parameter can be 4 or 8 for single and double precision floating point numbers.
********************************************************************************************/
Image CreateReal1DImage( const char *title, long bytes, long d0 );


/********************************************************************************************
 CreateReal2DImage: Creates a 2D real image of size [d0,d1] with the given title. The 
bytes parameter can be 4 or 8 for single and double precision floating point numbers.
********************************************************************************************/
Image CreateReal2DImage( const char *title, long bytes, long d0, long d1 );


/********************************************************************************************
 CreateReal3DImage: Creates a 3D real image of size [d0,d1,d2] with the given title. The 
bytes parameter can be 4 or 8 for single and double precision floating point numbers.
********************************************************************************************/
Image CreateReal3DImage( const char *title, long bytes, long d0, long d1, long d2 );


/********************************************************************************************
 CreateRGB1DImage: Creates a 1D RGB image of size [d0] with the given title. The bytes 
parameter must be 4.
********************************************************************************************/
Image CreateRGB1DImage( const char *title, long bytes, long d0 );


/********************************************************************************************
 CreateRGB2DImage: Creates a 2D RGB image of size [d0,d1] with the given title. The bytes 
parameter must be 4.
********************************************************************************************/
Image CreateRGB2DImage( const char *title, long bytes, long d0, long d1 );


/********************************************************************************************
 CreateRGB3DImage: Creates a 3D RGB image of size [d0,d1,d2] with the given title. The 
bytes parameter must be 4.
********************************************************************************************/
Image CreateRGB3DImage( const char *title, long bytes, long d0, long d1, long d2 );


/********************************************************************************************
 CreateRGBImage: Creates a 2D RGB image of size [width,height] with the given title.
********************************************************************************************/
Image CreateRGBImage( const char *title, long width, long height );


/********************************************************************************************
 CreateRGBImageFromPicture: Create an RGB image by drawing into it with a picture
********************************************************************************************/
Image CreateRGBImageFromPicture( long picture );


/********************************************************************************************
 CreateShortImage: Creates a 2D signed 2-byte integer image of size [width,height] with 
the given title.
********************************************************************************************/
Image CreateShortImage( const char *title, long width, long height );


/********************************************************************************************
 CrossCorrelate: Return an image which is the result of the cross correlation of source1 
and source2.
********************************************************************************************/
Image CrossCorrelate( const Image &source1, const Image &source2 );


/********************************************************************************************
 CrossCorrelation: Return an image which is the result of the cross correlation of 
source1 and source2.
********************************************************************************************/
Image CrossCorrelation( const Image &source1, const Image &source2 );


/********************************************************************************************
 CrossProduct: Return the matrix cross product image of matrix images a and b.
********************************************************************************************/
Image CrossProduct( const Image &a, const Image &b );


/********************************************************************************************
 CWCloseWindow: Close a custom window. See the SDK documentation for more information.
********************************************************************************************/
void CWCloseWindow( long windowObject );


/********************************************************************************************
 CWCreateWindow: Create a custom window. See the SDK documentation for more information.
********************************************************************************************/
long CWCreateWindow( long windowInstance, short top, short left, short bottom, short 
right );


/********************************************************************************************
 CWDeleteWindow: Delete a custom window. See the SDK documentation for more information.
********************************************************************************************/
void CWDeleteWindow( long windowObject );


/********************************************************************************************
 CWGetWindowPtr: Get the MacOS WindowPtr from the window. See the SDK documentation for 
more information.
********************************************************************************************/
long CWGetWindowPtr( long windowObject );


/********************************************************************************************
 CWInvalidateWindow: Invalidate a custom window. See the SDK documentation for more 
information.
********************************************************************************************/
void CWInvalidateWindow( long windowObject );


/********************************************************************************************
 DeallocString: Deallocates a string used in the script language.
********************************************************************************************/
void DeallocString( long string );


/********************************************************************************************
 Delay: Delay for the given number of tick counts.
********************************************************************************************/
void Delay( long argument_1 );


/********************************************************************************************
 DeleteDirectory: Deletes the folder named dirName.
********************************************************************************************/
void DeleteDirectory( const char *dirName );


/********************************************************************************************
 DeleteFile: Delete the file.
********************************************************************************************/
void DeleteFile( const char *fileName );


/********************************************************************************************
 DeleteImage: Close the image without asking the user to save it.
********************************************************************************************/
void DeleteImage( const Image &argument_1 );


/********************************************************************************************
 DeleteImageFile: Delete the image file.
********************************************************************************************/
void DeleteImageFile( const char *fileName );


/********************************************************************************************
 DestroyPicture: Destroy a picture
********************************************************************************************/
void DestroyPicture( long *picture );


/********************************************************************************************
 DisconnectObject: Break the connection specified by ident for the given object and 
message.
********************************************************************************************/
void DisconnectObject( long object, const char *message, const char *ident );


/********************************************************************************************
 DisplayAt: Display the image's image document if it is not display already and moves the 
window position to [x,y] screen coordinates.
********************************************************************************************/
void DisplayAt( const Image &argument_1, long x, long y );


/********************************************************************************************
 DoesClassExist: 
********************************************************************************************/
bool DoesClassExist( const char *class_name );


/********************************************************************************************
 DoesDirectoryExist: Returns 'true' if the named directory exists
********************************************************************************************/
bool DoesDirectoryExist( const char *dirName );


/********************************************************************************************
 DoesFileExist: Returns 'true' if the named file exists
********************************************************************************************/
bool DoesFileExist( const char *dirName );


/********************************************************************************************
 DoesFunctionExist: Determines if the given function exists.
********************************************************************************************/
bool DoesFunctionExist( const char *fnName );


/********************************************************************************************
 DoesImageExist: Determine if the image with imageID exists and returns 1 if it does; 
return 0 otherwise.
********************************************************************************************/
bool DoesImageExist( long imageID );


/********************************************************************************************
 DoEvents: Process all pending MacOS events.
********************************************************************************************/
void DoEvents( );


/********************************************************************************************
 EditorWindowAddText: Appends the text to a editor window.
********************************************************************************************/
void EditorWindowAddText( const Window &window, const String &text );


/********************************************************************************************
 EditorWindowGetFont: Gets the font of a script window.
********************************************************************************************/
void EditorWindowGetFont( const Window &window, String &face_name, ulong *attributes, 
ulong *size );


/********************************************************************************************
 EditorWindowGetText: Gets the text in an editor window.
********************************************************************************************/
String EditorWindowGetText( const Window &window );


/********************************************************************************************
 EditorWindowPrint: Prints the editor window.
********************************************************************************************/
bool EditorWindowPrint( const Window &window );


/********************************************************************************************
 EditorWindowSaveToFile: Saves the editor window to the specified path.
********************************************************************************************/
void EditorWindowSaveToFile( const Window &window, const String &path );


/********************************************************************************************
 EditorWindowSetFont: Sets the font of a script window.
********************************************************************************************/
void EditorWindowSetFont( const Window &window, const String &face_name, ulong attributes,
 ulong size );


/********************************************************************************************
 EditorWindowSetText: Sets the text in an editor window.
********************************************************************************************/
void EditorWindowSetText( const Window &window, const String &text );


/********************************************************************************************
 EMBeamShift: Shift the beam by xAmount, yAmount. The EM Control Plug-in must be 
currently installed and configured.
********************************************************************************************/
void EMBeamShift( long xAmount, long yAmount );


/********************************************************************************************
 EMChangeFocus: Change the focus by amount. The EM Control Plug-in must be currently 
installed and configured.
********************************************************************************************/
void EMChangeFocus( long amount );


/********************************************************************************************
 EMChangeStigmation: Change the stigmation by xAmount, yAmount. The EM Control Plug-in 
must be currently installed and configured.
********************************************************************************************/
void EMChangeStigmation( long xAmount, long yAmount );


/********************************************************************************************
 EMChangeTilt: Change the tilt by xAmount, yAmount. The EM Control Plug-in must be 
currently installed and configured.
********************************************************************************************/
void EMChangeTilt( long xAmount, long yAmount );


/********************************************************************************************
 EMCloseCommunication: Close communication to the microscope. The EM Control Plug-in must 
be currently installed and configured.
********************************************************************************************/
void EMCloseCommunication( );


/********************************************************************************************
 EMImageShift: Shift the image by xAmount, yAmount. The EM Control Plug-in must be 
currently installed and configured.
********************************************************************************************/
void EMImageShift( long xAmount, long yAmount );


/********************************************************************************************
 EMLinkControlFunctions: Establish link between microscope control functions and the 
application. The EM Control Plug-in must be currently installed and configured.
********************************************************************************************/
void EMLinkControlFunctions( void *functions );


/********************************************************************************************
 EMPrepareImageShift: Prepare image shift. Call this before a sequence of image shift 
changes. The EM Control Plug-in must be currently installed and configured.
********************************************************************************************/
void EMPrepareImageShift( );


/********************************************************************************************
 EMPrepareShift: Prepare beam shift. Call this before a sequence of beam shift changes. 
The EM Control Plug-in must be currently installed and configured.
********************************************************************************************/
void EMPrepareShift( );


/********************************************************************************************
 EMPrepareStigmation: Prepare stigmation. Call this before a sequence of stigmation 
changes. The EM Control Plug-in must be currently installed and configured.
********************************************************************************************/
void EMPrepareStigmation( );


/********************************************************************************************
 EMPrepareTilt: Prepare tilt. Call this before a sequence of tilt changes. The EM Control 
Plug-in must be currently installed and configured.
********************************************************************************************/
void EMPrepareTilt( );


/********************************************************************************************
 EMSetupCommunication: Setup communication with the microscope. The EM Control Plug-in 
must be currently installed and configured.
********************************************************************************************/
void EMSetupCommunication( );


/********************************************************************************************
 EMUnlinkControlFunctions: Break link between microscope control functions and the 
application. The EM Control Plug-in must be currently installed and configured.
********************************************************************************************/
void EMUnlinkControlFunctions( );


/********************************************************************************************
 ErrorDialog: Puts up a dialog explaining the application error.
********************************************************************************************/
void ErrorDialog( short error );


/********************************************************************************************
 ExecuteScriptFile: Executes the script file indicated by fileName and returns the exit 
value of that script.  A script may specify a specific exit value by exiting with the 
exit(n) function.  If a script does not use the exit() function the exit value will be 0.
********************************************************************************************/
double ExecuteScriptFile( const char *fileName, ulong script_index );


/********************************************************************************************
 ExecuteScriptFile: Executes the script file indicated by fileName and returns the exit 
value of that script.  A script may specify a specific exit value by exiting with the 
exit(n) function.  If a script does not use the exit() function the exit value will be 0.
********************************************************************************************/
double ExecuteScriptFile( const char *fileName );


/********************************************************************************************
 ExecuteScriptString: Executes the script text and returns the exit value of that script. 
 A script may specify a specific exit value by exiting with the exit(n) function.  If a 
script does not use the exit() function the exit value will be 0.
********************************************************************************************/
double ExecuteScriptString( const String &text );


/********************************************************************************************
 Extract2D_Linear: 
********************************************************************************************/
void Extract2D_Linear( const Image &from, const Image &to, long extract_style, double 
x_start, double y_start, double x_scale_0, double y_scale_0, double x_scale_1, double 
y_scale_1 );


/********************************************************************************************
 FFT: Creates a new complex 8-byte image from the FFT of the complex image source.
********************************************************************************************/
Image FFT( const Image &source );


/********************************************************************************************
 FindFrontImage: Returns the front image. Doesn't throw exceptions.
********************************************************************************************/
Image FindFrontImage( );


/********************************************************************************************
 FindFunctionBySignature: Looks for a function that matches the given signature.
********************************************************************************************/
Function FindFunctionBySignature( const char *signature );


/********************************************************************************************
 FindImageByID: Returns the image having the given id, or an invalid image of no image 
has that id.
********************************************************************************************/
Image FindImageByID( long id );


/********************************************************************************************
 FindImageByIndex: Returns the 'index'th image.
********************************************************************************************/
Image FindImageByIndex( long index );


/********************************************************************************************
 FindImageByLabel: Returns the image having the given label, or an invalid image if no 
such image exists.
********************************************************************************************/
Image FindImageByLabel( const char *label );


/********************************************************************************************
 FindImageByName: Returns the image having the given name, or an invalid image of no 
image has that name.
********************************************************************************************/
Image FindImageByName( const char *name );


/********************************************************************************************
 FindLike: Look for an image with the given name, width, height, and dataType. Return it 
if found.
********************************************************************************************/
Image FindLike( const char *name, long width, long height, short dataType );


/********************************************************************************************
 FindNextImage: Find the next image.
********************************************************************************************/
Image FindNextImage( const Image &argument_1 );


/********************************************************************************************
 FindReferenceImage: Look for an image with the given name, width, height, and dataType. 
If it's found, return it. If it's not found, try to load it from disk.
********************************************************************************************/
Image FindReferenceImage( const char *name, short dataType, long width, long height );


/********************************************************************************************
 FirstImage: Find the first image.
********************************************************************************************/
Image FirstImage( );


/********************************************************************************************
 FlipHorizontal: Flips the image horizontally.
********************************************************************************************/
void FlipHorizontal( const Image &argument_1 );


/********************************************************************************************
 FlipVertical: Flips the image vertically.
********************************************************************************************/
void FlipVertical( const Image &argument_1 );


/********************************************************************************************
 FloatingModelessDialog: Present a floating window with the prompt and buttonName. When 
the user presses the button, the semaphore will be cleared. This function can only be 
used in the background.
********************************************************************************************/
void FloatingModelessDialog( const char *prompt, const char *buttonName, long semaphore );


/********************************************************************************************
 FlushCache: Flush the image data from the array processor if necessary.
********************************************************************************************/
void FlushCache( const Image &argument_1 );


/********************************************************************************************
 FM_ConjMultiplyPackedByPacked: Conjugate multiply packed image a by packed image b and 
store the result in b. No data type checking is performed. This function uses the array 
processor if present.
********************************************************************************************/
void FM_ConjMultiplyPackedByPacked( const Image &a, const Image &b );


/********************************************************************************************
 FM_ConvertInt16ToFloat: Convert the signed 2-byte data in image a to real data and store 
the result in image b. No data type checking is performed. This function uses the array 
processor if present.
********************************************************************************************/
void FM_ConvertInt16ToFloat( const Image &a, const Image &b );


/********************************************************************************************
 FM_ConvertUInt8ToDisplay8: Copy the sub-area of unsigned 1-byte integer image src 
indicated by [top,left,bottom,right] to dst. The rowBytes parameter indicates the length 
of the row of dst. To copy to the screen, pass 0 for dst and rowBytes. No data type 
checking is performed. This function uses the array processor if present.
********************************************************************************************/
void FM_ConvertUInt8ToDisplay8( const Image &src, long top, long left, long bottom, long 
right, long dst, long rowBytes );


/********************************************************************************************
 FM_ConvertUInt8ToFloat: Convert the unsigned 1-byte data in image a to real data and 
store the result in image b. No data type checking is performed. This function uses the 
array processor if present.
********************************************************************************************/
void FM_ConvertUInt8ToFloat( const Image &a, const Image &b );


/********************************************************************************************
 FM_FinishDMA: Finish an image for DMA access. This function should be called once for 
every FM_PrepareDMA() call.
********************************************************************************************/
void FM_FinishDMA( const Image &image );


/********************************************************************************************
 FM_Flush: Finish any pending operations on the array processor.
********************************************************************************************/
void FM_Flush( );


/********************************************************************************************
 FM_GetVarianceFloat: Return the variance of the image. No data type checking is 
performed. This function uses the array processor if present.
********************************************************************************************/
float FM_GetVarianceFloat( const Image &argument_1 );


/********************************************************************************************
 FM_ImageDataChanged: Inform the application that the image has changed due to DMA or 
other memory access.
********************************************************************************************/
void FM_ImageDataChanged( const Image &image );


/********************************************************************************************
 FM_MultiplyFloatByFloat: Multiply real image a by real image b and store the result in 
a. No data type checking is performed. This function uses the array processor if present.
********************************************************************************************/
void FM_MultiplyFloatByFloat( const Image &a, const Image &b );


/********************************************************************************************
 FM_MultiplyPackedByFloat: Multiply packed image a by real image b and store the result 
in a. No data type checking is performed. This function uses the array processor if 
present.
********************************************************************************************/
void FM_MultiplyPackedByFloat( const Image &a, const Image &b );


/********************************************************************************************
 FM_MultiplyPackedByScalar: Multiply packed image a by real and store the result in a. No 
data type checking is performed. This function uses the array processor if present.
********************************************************************************************/
void FM_MultiplyPackedByScalar( const Image &a, float argument_2 );


/********************************************************************************************
 FM_PackedFFT: Perform an in-place packed FFT on image a. No data type checking is 
performed. This function uses the array processor if present.
********************************************************************************************/
void FM_PackedFFT( const Image &a );


/********************************************************************************************
 FM_PackedIFFT: Perform an in-place packed inverse FFT on image a. No data type checking 
is performed. This function uses the array processor if present.
********************************************************************************************/
void FM_PackedIFFT( const Image &argument_1 );


/********************************************************************************************
 FM_PackedLnModulusToImage: Store the unpacked log modulus of the packed complex image 
imageSrc into imageDst using the lowLimit, highLimit, and range parameters. No data type 
checking is performed. This function uses the array processor if present.
********************************************************************************************/
void FM_PackedLnModulusToImage( const Image &imageSrc, const Image &imageDst, float 
lowLimit, float highLimit, float range );


/********************************************************************************************
 FM_PrepareDMA: Prepare an image for DMA access by locking down the data and preventing 
it from being deleted. If DMA access is possible, store the physical address in the 
physicalAddress variable. Store the logical address in the logicalAddress variable.The 
FM_FinishDMA() function should be called once for every FM_PrepareDMA() call.
********************************************************************************************/
void FM_PrepareDMA( const Image &image, long *logicalAddress, long *physicalAddress );


/********************************************************************************************
 FM_SetMacOnly: Disable the plug-in array processor if present. This function may not be 
supported by plug-in array processors. 
********************************************************************************************/
void FM_SetMacOnly( bool b );


/********************************************************************************************
 FM_ShiftCenterFloat: Shift the center of image a in-place (after a forward FFT or before 
an inverse FFT). No data type checking is performed. This function uses the array 
processor if present.
********************************************************************************************/
void FM_ShiftCenterFloat( const Image &a );


/********************************************************************************************
 FM_SubtractMeanPacked: Subtract the mean from the packed image a. No data type checking 
is performed. This function uses the array processor if present.
********************************************************************************************/
void FM_SubtractMeanPacked( const Image &a );


/********************************************************************************************
 FM_SubtractMultiply: Subtract real image b from real image a, multiply the result by 
real image c, and store the result in image a. No data type checking is performed. This 
function uses the array processor if present.
********************************************************************************************/
void FM_SubtractMultiply( const Image &a, const Image &b, const Image &c );


/********************************************************************************************
 FM_SurveyNormalPackedModulus: Survey packed image a and store the minimum and maximum 
values found into the lowLimit and highLimit variables. No data type checking is 
performed. This function uses the array processor if present.
********************************************************************************************/
void FM_SurveyNormalPackedModulus( const Image &image, float *lowLimit, float *highLimit 
);


/********************************************************************************************
 FM_TurboFFT: Perform a turbo FFT on the real image fft minus the real dark image and 
multiplied by the real gain image. Store the resulting FFT into the packed complex image 
fft. Copy the sub-area of unsigned 1-byte integer image src indicated by 
[top,left,bottom,right] to dst. The rowBytes parameter indicates the length of the row of 
dst. To copy to the screen, pass 0 for dst and rowBytes. The real buffer image is a 
scratch area. No data type checking is performed. This function uses the array processor 
if present.
********************************************************************************************/
void FM_TurboFFT( const Image &buffer, const Image &fft, const Image &dark, const Image 
&gain, long top, long left, long bottom, long right, long dst, long rowBytes );


/********************************************************************************************
 fngetkey: Returns the key that was last pressed.
********************************************************************************************/
short fngetkey( );


/********************************************************************************************
 ForceSurvey: Cause an immediate survey of the image.
********************************************************************************************/
void ForceSurvey( const Image &argument_1 );


/********************************************************************************************
 FreeSemaphore: Free the semaphore. Used only with background processing.
********************************************************************************************/
void FreeSemaphore( long argument_1 );


/********************************************************************************************
 FunctionCountParameters: Returns the number of parameters of the function.
********************************************************************************************/
ulong FunctionCountParameters( const Function &func );


/********************************************************************************************
 FunctionGenerateStub: Generates a stub function in the format specified by version.
********************************************************************************************/
String FunctionGenerateStub( const Function &func, bool include_body, ulong version );


/********************************************************************************************
 FunctionIsValid: Returns true if 'func' is a valid object.
********************************************************************************************/
bool FunctionIsValid( const Function &func );


/********************************************************************************************
 Get1DSize: Store the length of the 1D image into the d0 variable.
********************************************************************************************/
void Get1DSize( const Image &argument_1, long *d0 );


/********************************************************************************************
 Get2DSize: Store the width and height of the 2D image into the d0 and d1 variables.
********************************************************************************************/
void Get2DSize( const Image &argument_1, long *d0, long *d1 );


/********************************************************************************************
 Get3DSize: Store the x,y, and z sizes of the 3D image into the d0, d1, and d2 variables.
********************************************************************************************/
void Get3DSize( const Image &argument_1, long *d0, long *d1, long *d2 );


/********************************************************************************************
 GetApplicationDirectory: Return one of the application directories. 0=current directory, 
1=executable directory.
********************************************************************************************/
String GetApplicationDirectory( long index, bool create_if_necessary );


/********************************************************************************************
 GetApplicationInfo: Get application info. For 'info_kind == 0', bit 2 of '*info' is set 
for demo versions.
********************************************************************************************/
bool GetApplicationInfo( long info_kind, long *info );


/********************************************************************************************
 GetApplicationWindow: Gets the application window.
********************************************************************************************/
Window GetApplicationWindow( );


/********************************************************************************************
 GetBoolean: Puts up a dialog with the given prompt and allows the user to enter Boolean. 
The initial value is passed as a parameter and the result in stored in result. Returns 1 
for OK and 0 for Cancel.
********************************************************************************************/
bool GetBoolean( const char *prompt, bool initalValue, bool *result );


/********************************************************************************************
 GetCalibrationDialog: Present the calibration dialog to the user. The calibrating pixel 
dimensions are passed as the [aw,ah] parameters. The resulting calibration is stored into 
the [xs,ys] parameters. The initial unit string is passed in and the resulting unit 
string is copied into the unitString buffer.Returns 1 for OK and 0 for Cancel.
********************************************************************************************/
bool GetCalibrationDialog( float aw, float ah, float *xs, float *ys, const char 
*initialUnitString, char *unitString );


/********************************************************************************************
 GetCLUT: Return the image's CLUT as a 256x1 RGB image.
********************************************************************************************/
Image GetCLUT( const Image &argument_1 );


/********************************************************************************************
 GetDataPtr: Return a pointer to the actual image data.  If the image data is changed, 
the function DMImageDataChanged() must be called to ensure proper updating, etc. This 
call must be balanced with a call to ReleaseDataPtr().
********************************************************************************************/
long GetDataPtr( const Image &argument_1 );


/********************************************************************************************
 GetDataType: Return the enumerated data type of the image.
********************************************************************************************/
short GetDataType( const Image &argument_1 );


/********************************************************************************************
 GetDate: Return a string representing the current date in the date format indicated by 
dateFormat. The dateFormat parameter can be 0=short, 1=long, 2=abbreviated.
********************************************************************************************/
void GetDate( long dateFormat, char *buffer, long buffer_length );


/********************************************************************************************
 GetDepth: Return the number of bytes per pixel of the image.
********************************************************************************************/
long GetDepth( const Image &argument_1 );


/********************************************************************************************
 GetDirectoryDialog: Puts up the GetDirectory dialog and stores the path of the chosen 
directory in 'dirName'
********************************************************************************************/
bool GetDirectoryDialog( char *dirName, long buff_length );


/********************************************************************************************
 GetDisplayAsImage: Convert the display of image to an RGB image.
********************************************************************************************/
Image GetDisplayAsImage( const Image &argument_1 );


/********************************************************************************************
 GetDocumentWindow: Gets the 'index'th document window.
********************************************************************************************/
Window GetDocumentWindow( long index );


/********************************************************************************************
 GetDocumentWindowByTitle: Gets the document window named 'name'.
********************************************************************************************/
Window GetDocumentWindowByTitle( const String &name );


/********************************************************************************************
 GetEstimatedMinMax: Store the current estimated minimum and maximum of the image into 
the minPtr and maxPtr variables.
********************************************************************************************/
void GetEstimatedMinMax( const Image &argument_1, float *minPtr, float *maxPtr );


/********************************************************************************************
 GetException: Store the current exception into the error and context variables.
********************************************************************************************/
void GetException( short *error, long *context );


/********************************************************************************************
 GetExceptionDescription: Return the message that would be displayed in the error dialog 
box for an exception as a string.
********************************************************************************************/
String GetExceptionDescription( );


/********************************************************************************************
 GetExceptionString: Copies the message that would displayed in the error dialog box for 
an exception into dst.
********************************************************************************************/
void GetExceptionString( char *dst );


/********************************************************************************************
 GetFilesInDirectory: Returns a tag group containing a list of the file names in the 
directory 'dir_path'
********************************************************************************************/
TagGroup GetFilesInDirectory( const String &path, ulong search_flags );


/********************************************************************************************
 GetFloatingWindow: Gets the 'index'th floating window.
********************************************************************************************/
Window GetFloatingWindow( long index );


/********************************************************************************************
 GetFourImages: Puts up a dialog and allows the user to choose four images.  Returns 1 
for Ok and 0 for Cancel.
********************************************************************************************/
bool GetFourImages( const char *title, Image &image1, Image &image2, Image &image3, Image 
&image4 );


/********************************************************************************************
 GetFourImagesWithPrompt: Puts up a dialog with the given prompt and allows the user to 
choose four images.  Returns 1 for Ok and 0 for Cancel.
********************************************************************************************/
bool GetFourImagesWithPrompt( const char *prompt, const char *title, Image &image1, Image 
&image2, Image &image3, Image &image4 );


/********************************************************************************************
 GetFourLabeledImagesWithPrompt: Puts up a dialog with the given prompt and allows the 
user to choose four images.  Returns 1 for Ok and 0 for Cancel.
********************************************************************************************/
bool GetFourLabeledImagesWithPrompt( const char *prompt, const char *title, const char 
*label1, Image &image1, const char *label2, Image &image2, const char *label3, Image 
&image3, const char *label4, Image &image4 );


/********************************************************************************************
 GetFrontImage: Return the foremost image.
********************************************************************************************/
Image GetFrontImage( );


/********************************************************************************************
 GetFrontImage: Set the image variable to represent the foremost image, returns 1 if 
successful; return 0 otherwise.
********************************************************************************************/
bool GetFrontImage( Image &argument_1 );


/********************************************************************************************
 GetFrontImageDocument: Returns the front image document.
********************************************************************************************/
ImageDocument GetFrontImageDocument( );


/********************************************************************************************
 GetFrontImageID: Return the id of the front most image window.
********************************************************************************************/
long GetFrontImageID( );


/********************************************************************************************
 GetImageDataSeed: Return a seed representing the data of the image. Each time the image 
data changes, the seed will change.
********************************************************************************************/
long GetImageDataSeed( const Image &argument_1 );


/********************************************************************************************
 GetImageDocument: Returns the image document by position with the application.
********************************************************************************************/
ImageDocument GetImageDocument( long position );


/********************************************************************************************
 GetImageDocumentByID: Returns the image document whose id is 'id'.
********************************************************************************************/
ImageDocument GetImageDocumentByID( long id );


/********************************************************************************************
 GetImageFromID: Store the image corresponding the imageID into the image variable. 
Return 1 if one is found; return 0 otherwise.
********************************************************************************************/
bool GetImageFromID( Image &argument_1, long imageID );


/********************************************************************************************
 GetImageID: Return the id of the image.
********************************************************************************************/
long GetImageID( const Image &argument_1 );


/********************************************************************************************
 GetImageWindow: Return the MacOS window associated with the image.
********************************************************************************************/
long GetImageWindow( const Image &argument_1 );


/********************************************************************************************
 GetInteger: Puts up a dialog with the given prompt and allows the user to enter an 
integer. The initial value is passed as a parameter and the result in stored in result. 
Returns 1 for OK and 0 for Cancel.
********************************************************************************************/
bool GetInteger( const char *prompt, long initalValue, long *result );


/********************************************************************************************
 GetInversionMode: Return the contrast inversion mode of the image (1=inverted, 0=not 
inverted).
********************************************************************************************/
bool GetInversionMode( const Image &argument_1 );


/********************************************************************************************
 GetLabel: Return the image label of the image.
********************************************************************************************/
String GetLabel( const Image &argument_1 );


/********************************************************************************************
 GetLabel: Store the image label of the image into buffer.
********************************************************************************************/
void GetLabel( const Image &argument_1, char *buffer );


/********************************************************************************************
 GetLimits: Stores display limits into the lowPtr and highPtr variables.
********************************************************************************************/
void GetLimits( const Image &argument_1, float *lowPtr, float *highPtr );


/********************************************************************************************
 GetMaximalDocumentWindowRect: Gets the bounds of the content region of the largest 
document window.
********************************************************************************************/
void GetMaximalDocumentWindowRect( long options, long *top, long *left, long *bottom, 
long *right );


/********************************************************************************************
 GetName: Return the name of the image's image document.
********************************************************************************************/
String GetName( const Image &argument_1 );


/********************************************************************************************
 GetName: Store the name of the image's image document into buffer.
********************************************************************************************/
void GetName( const Image &argument_1, char *buffer );


/********************************************************************************************
 GetNamedImage: Return the image with the image document name.
********************************************************************************************/
Image GetNamedImage( const char *name );


/********************************************************************************************
 GetNamedImage: Store the image with the image document name into the image variable. 
Return 1 if one is found; return 0 otherwise.
********************************************************************************************/
bool GetNamedImage( Image &argument_1, const char *name );


/********************************************************************************************
 GetNextImageID: Return the id of the image window following the image with the given id.
********************************************************************************************/
long GetNextImageID( long id );


/********************************************************************************************
 GetNthDocumentWindowOfType: Returns the 'index'th document window of type 'type'.
********************************************************************************************/
Window GetNthDocumentWindowOfType( long type, long index );


/********************************************************************************************
 GetNthImageID: Return the id of the nth image (number from 0). The images are in no 
particular order.
********************************************************************************************/
long GetNthImageID( long n );


/********************************************************************************************
 GetNumber: Puts up a dialog with the given prompt and allows the user to enter a number. 
The initial value is passed as a parameter and the result in stored in result. Returns 1 
for OK and 0 for Cancel.
********************************************************************************************/
bool GetNumber( const char *prompt, float initalValue, float *result );


/********************************************************************************************
 GetOneImage: Puts up a dialog and allows the user to choose an image.  Returns 1 for Ok 
and 0 for Cancel.
********************************************************************************************/
bool GetOneImage( const char *title, Image &image1 );


/********************************************************************************************
 GetOneImageWithPrompt: Puts up a dialog and allows the user to choose an image.  Returns 
1 for Ok and 0 for Cancel.
********************************************************************************************/
bool GetOneImageWithPrompt( const char *prompt, const char *title, Image &image1 );


/********************************************************************************************
 GetOneLabeledImageWithPrompt: Puts up a dialog and allows the user to choose an image.  
Returns 1 for Ok and 0 for Cancel.
********************************************************************************************/
bool GetOneLabeledImageWithPrompt( const char *prompt, const char *title, const char 
*label1, Image &image1 );


/********************************************************************************************
 GetOrigin: Store the origin of image into the x and y variables. The origin is in the 
same units as scale.
********************************************************************************************/
void GetOrigin( const Image &argument_1, float *x, float *y );


/********************************************************************************************
 GetOSTickCount: Return a tick count appropriate for the operating system.
********************************************************************************************/
uint32 GetOSTickCount( );


/********************************************************************************************
 GetOSTicksPerSecond: Return the number of ticks per second of a tick count appropriate 
for the operating system.
********************************************************************************************/
uint32 GetOSTicksPerSecond( );


/********************************************************************************************
 GetPackageTags: Return the tags specified by identifier. The identifier is used to 
identify tags loaded with a specific package.
********************************************************************************************/
TagGroup GetPackageTags( const char *identifier );


/********************************************************************************************
 GetPersistentTagGroup: Gets the persistent tag group.
********************************************************************************************/
TagGroup GetPersistentTagGroup( );


/********************************************************************************************
 GetPlatformInfo: Return platform info. info=1 is general platform (1=MacOS,2=Windows).
********************************************************************************************/
long GetPlatformInfo( long info );


/********************************************************************************************
 GetRawSize: Return the total size of the image data of the image.
********************************************************************************************/
long GetRawSize( const Image &argument_1 );


/********************************************************************************************
 GetRawStreamPos: Store the current position in rawStream into the pos variable.
********************************************************************************************/
void GetRawStreamPos( long rawStream, long *pos );


/********************************************************************************************
 GetRawStreamSize: Store the length of rawStream into the size variable.
********************************************************************************************/
void GetRawStreamSize( long rawStream, long *size );


/********************************************************************************************
 GetResultsWindow: Gets the results window.  If the window is not open, and 'open' is 
true, the results window is opened.
********************************************************************************************/
Window GetResultsWindow( bool open );


/********************************************************************************************
 GetROIFromID: Returns the region of interest associated with the ID or NULL if it does 
not exist.
********************************************************************************************/
ROI GetROIFromID( long id );


/********************************************************************************************
 GetScale: Store the scale of image into the x and y variables.
********************************************************************************************/
void GetScale( const Image &argument_1, float *x, float *y );


/********************************************************************************************
 GetScreenSize: Store the size of the screen into the width and height variables.
********************************************************************************************/
void GetScreenSize( long *width, long *height );


/********************************************************************************************
 GetScriptObjectFromID: Returns the script object associated with the ID or NULL if the 
object does not exist.
********************************************************************************************/
ScriptObject GetScriptObjectFromID( long id );


/********************************************************************************************
 GetSelection: Stores the coordinates (in pixels) of the image's selection into the top, 
left, bottom, and right variables. Returns 1 if there was a selection and 0 if there 
wasn't.
********************************************************************************************/
bool GetSelection( const Image &argument_1, long *top, long *left, long *bottom, long 
*right );


/********************************************************************************************
 GetSize: Store the width and height of the 2D image into the width and height variables.
********************************************************************************************/
void GetSize( const Image &argument_1, long *width, long *height );


/********************************************************************************************
 GetSpecialDirectory: Return one of the special directories. 0=current directory, 
1=executable directory.
********************************************************************************************/
String GetSpecialDirectory( long index );


/********************************************************************************************
 GetSpecialWindow: Return one of the special windows. On Windows, 0=frame window, 
1=top-most dialog.
********************************************************************************************/
long GetSpecialWindow( long index );


/********************************************************************************************
 GetString: Puts up a dialog with the given prompt and allows the user to enter a string. 
The initial value is passed as a parameter and the result in stored in result. Returns 1 
for OK and 0 for Cancel.
********************************************************************************************/
bool GetString( const char *prompt, const char *initalValue, char *result );


/********************************************************************************************
 GetSurvey: Return 1 if the survey is on; return 0 otherwise.
********************************************************************************************/
bool GetSurvey( const Image &argument_1 );


/********************************************************************************************
 GetThreeImages: Puts up a dialog and allows the user to choose three images.  Returns 1 
for Ok and 0 for Cancel.
********************************************************************************************/
bool GetThreeImages( const char *title, Image &image1, Image &image2, Image &image3 );


/********************************************************************************************
 GetThreeImagesWithPrompt: Puts up a dialog with the given prompt and allows the user to 
choose three images.  Returns 1 for Ok and 0 for Cancel.
********************************************************************************************/
bool GetThreeImagesWithPrompt( const char *prompt, const char *title, Image &image1, 
Image &image2, Image &image3 );


/********************************************************************************************
 GetThreeLabeledImagesWithPrompt: Puts up a dialog with the given prompt and allows the 
user to choose three images.  Returns 1 for Ok and 0 for Cancel.
********************************************************************************************/
bool GetThreeLabeledImagesWithPrompt( const char *prompt, const char *title, const char 
*label1, Image &image1, const char *label2, Image &image2, const char *label3, Image 
&image3 );


/********************************************************************************************
 GetTicks: Return the MacOS system tick count.
********************************************************************************************/
uint32 GetTicks( );


/********************************************************************************************
 GetTicksPerSecond: Return the number of ticks per second.
********************************************************************************************/
uint32 GetTicksPerSecond( );


/********************************************************************************************
 GetTime: Return a string representing the current time with or without seconds as 
indicated by the wantSeconds parameter.
********************************************************************************************/
void GetTime( bool wantSeconds, char *buffer, long buffer_length );


/********************************************************************************************
 GetTwoImages: Puts up a dialog and allows the user to choose two images.  Returns 1 for 
Ok and 0 for Cancel.
********************************************************************************************/
bool GetTwoImages( const char *title, Image &image1, Image &image2 );


/********************************************************************************************
 GetTwoImagesWithPrompt: Puts up a dialog with the given prompt and allows the user to 
choose two images.  Returns 1 for Ok and 0 for Cancel.
********************************************************************************************/
bool GetTwoImagesWithPrompt( const char *prompt, const char *title, Image &image1, Image 
&image2 );


/********************************************************************************************
 GetTwoLabeledImagesWithPrompt: Puts up a dialog with the given prompt and allows the 
user to choose two images.  Returns 1 for Ok and 0 for Cancel.
********************************************************************************************/
bool GetTwoLabeledImagesWithPrompt( const char *prompt, const char *title, const char 
*label1, Image &image1, const char *label2, Image &image2 );


/********************************************************************************************
 GetUnitsH: Return the horizontal pixels x in calibrated units.
********************************************************************************************/
float GetUnitsH( const Image &argument_1, float x );


/********************************************************************************************
 GetUnitString: Copies the unit string of the image into the buffer.
********************************************************************************************/
void GetUnitString( const Image &argument_1, char *buffer );


/********************************************************************************************
 GetUnitsV: Return the vertical pixels y in calibrated units.
********************************************************************************************/
float GetUnitsV( const Image &argument_1, float y );


/********************************************************************************************
 GetWindowPosition: Store the image's image document window position into the xPos and 
yPos variables.
********************************************************************************************/
void GetWindowPosition( const Image &argument_1, long *xPos, long *yPos );


/********************************************************************************************
 GetWindowSize: Store the image's image document window size into the width and height 
variables.
********************************************************************************************/
void GetWindowSize( const Image &argument_1, long *width, long *height );


/********************************************************************************************
 GetZoom: Return the zoom of the image display.
********************************************************************************************/
float GetZoom( const Image &argument_1 );


/********************************************************************************************
 GrabSemaphore: Grab the semaphore. Block until it is available. Used only with 
background processing.
********************************************************************************************/
void GrabSemaphore( long argument_1 );


/********************************************************************************************
 GroupAnnotationUngroup: Ungroups the group annotation.
********************************************************************************************/
void GroupAnnotationUngroup( const Component &comp );


/********************************************************************************************
 HasAcquisitionDaemon: Returns 1 if the image has an attached daemon and returns 0 
otherwise.
********************************************************************************************/
bool HasAcquisitionDaemon( const Image &argument_1 );


/********************************************************************************************
 HideImage: Hide the image's image document.
********************************************************************************************/
void HideImage( const Image &argument_1 );


/********************************************************************************************
 IFFT: Creates a new complex 8-byte image from the inverse FFT of the complex image 
source.
********************************************************************************************/
Image IFFT( const Image &source );


/********************************************************************************************
 ImageCalculateHistogram: Calculates the histogram of 'image', mapping [min,max] into 
'hist_image'.
********************************************************************************************/
void ImageCalculateHistogram( const Image &image, const Image &hist_image, long 
complexMode, float min, float max );


/********************************************************************************************
 ImageCalculateMinMax: Calculates the minimum and maximum value of 'image' using survey 
technique 'surveyTechnique'.
********************************************************************************************/
void ImageCalculateMinMax( const Image &image, long surveyTechnique, long complexMode, 
float *min, float *max );


/********************************************************************************************
 ImageClone: Returns a clone of 'img'.
********************************************************************************************/
Image ImageClone( const Image &img );


/********************************************************************************************
 ImageCopyCalibrationFrom: Copy the calibration of 'src_image' to 'image'.
********************************************************************************************/
void ImageCopyCalibrationFrom( const Image &image, const Image &src_image );


/********************************************************************************************
 ImageCountImageDisplays: Returns the number of image displays in which this image is 
displayed.
********************************************************************************************/
long ImageCountImageDisplays( const Image &argument_1 );


/********************************************************************************************
 ImageCountImageDisplaysInImageDocument: Returns the number of image displays in the 
image document in which this image is displayed.
********************************************************************************************/
long ImageCountImageDisplaysInImageDocument( const Image &argument_1, const ImageDocument 
&imgDoc );


/********************************************************************************************
 ImageCreateImageDisplay: Creates a new image display of type 'displayType' for the image.
********************************************************************************************/
ImageDisplay ImageCreateImageDisplay( const Image &argument_1, long displayType );


/********************************************************************************************
 ImageData_CacheChanged: Tell the array processor manager that the cached image has 
changed. See the SDK documentation for more information.
********************************************************************************************/
void ImageData_CacheChanged( long imageDataID );


/********************************************************************************************
 ImageData_Changed: Tell the array processor manager that the image has changed. See the 
SDK documentation for more information.
********************************************************************************************/
void ImageData_Changed( long imageDataID );


/********************************************************************************************
 ImageData_FlushCache: Tell the array processor manager to flush the image from the 
cache. See the SDK documentation for more information.
********************************************************************************************/
void ImageData_FlushCache( long imageDataID );


/********************************************************************************************
 ImageData_GetSeed: Ask the array processor manager for the data seed of the image. See 
the SDK documentation for more information.
********************************************************************************************/
long ImageData_GetSeed( long imageDataID );


/********************************************************************************************
 ImageData_IsLocalCopyValid: Ask the array processor manager if the local copy is valid 
or not. See the SDK documentation for more information.
********************************************************************************************/
bool ImageData_IsLocalCopyValid( long imageDataID );


/********************************************************************************************
 ImageData_SetLocalSeed: Tell the array processor manager to set the local data seed. See 
the SDK documentation for more information.
********************************************************************************************/
void ImageData_SetLocalSeed( long imageDataID, long value );


/********************************************************************************************
 ImageDataChanged: Signal that the data of the image has changed.
********************************************************************************************/
void ImageDataChanged( const Image &argument_1 );


/********************************************************************************************
 ImageDisplayAccumulateROIsToMask: Sets mask to mask_val at points in imageDisplay's rois
********************************************************************************************/
void ImageDisplayAccumulateROIsToMask( const ImageDisplay &imgDisp, const Image &mask, 
float top, float left, float bottom, float right, float mask_val );


/********************************************************************************************
 ImageDisplayAddKeyListener: Adds the listener_script to the key listener list under the 
tag listener_key.
********************************************************************************************/
void ImageDisplayAddKeyListener( const ImageDisplay &imgDisp, const char *listener_key, 
const char *listener_script );


/********************************************************************************************
 ImageDisplayAddROI: Adds the roi to this image display.
********************************************************************************************/
void ImageDisplayAddROI( const ImageDisplay &imgDisp, const ROI &roi );


/********************************************************************************************
 ImageDisplayChangeDisplayType: Changes the type of the image display.
********************************************************************************************/
void ImageDisplayChangeDisplayType( const ImageDisplay &imgDisp, long new_type );


/********************************************************************************************
 ImageDisplayCountROIs: Returns the number of ROIs on this image display.
********************************************************************************************/
long ImageDisplayCountROIs( const ImageDisplay &imgDisp );


/********************************************************************************************
 ImageDisplayDeleteROI: Deletes the roi from this image display.
********************************************************************************************/
void ImageDisplayDeleteROI( const ImageDisplay &imgDisp, const ROI &roi );


/********************************************************************************************
 ImageDisplayDoesROIExist: Determines whether the given ROI exists on this image display.
********************************************************************************************/
bool ImageDisplayDoesROIExist( const ImageDisplay &imgDisp, const char *name );


/********************************************************************************************
 ImageDisplayExportToFile: Exports the display to the file 'file_name' using the format 
'format'.
********************************************************************************************/
void ImageDisplayExportToFile( const ImageDisplay &imgDisp, const char *format, const 
char *file_name );


/********************************************************************************************
 ImageDisplayGetBufferedImage: Gets the image resulting from the contrast transformation.
********************************************************************************************/
Image ImageDisplayGetBufferedImage( const ImageDisplay &imgDisp );


/********************************************************************************************
 ImageDisplayGetComplexMode: Gets the complex mode of the display.
********************************************************************************************/
long ImageDisplayGetComplexMode( const ImageDisplay &imgDisp );


/********************************************************************************************
 ImageDisplayGetComplexModeRange: Gets the parameter used in converting complex to real.
********************************************************************************************/
float ImageDisplayGetComplexModeRange( const ImageDisplay &imgDisp );


/********************************************************************************************
 ImageDisplayGetContrastLimits: Gets the contrast limits of the display.
********************************************************************************************/
void ImageDisplayGetContrastLimits( const ImageDisplay &imgDisp, float *low, float *high 
);


/********************************************************************************************
 ImageDisplayGetContrastMode: Returns the contrast mode.
********************************************************************************************/
long ImageDisplayGetContrastMode( const ImageDisplay &imgDisp );


/********************************************************************************************
 ImageDisplayGetContrastParameters: Gets the parameters for the contrast mode.
********************************************************************************************/
void ImageDisplayGetContrastParameters( const ImageDisplay &imgDisp, float *bright, float 
*contrast );


/********************************************************************************************
 ImageDisplayGetDisplayedImage: Gets the image that is actually displayed in the image 
display.
********************************************************************************************/
Image ImageDisplayGetDisplayedImage( const ImageDisplay &imgDisp );


/********************************************************************************************
 ImageDisplayGetDisplayedLayers: Gets the layers that are summed into the display.
********************************************************************************************/
void ImageDisplayGetDisplayedLayers( const ImageDisplay &imgDisp, long *start, long *end 
);


/********************************************************************************************
 ImageDisplayGetDisplayType: Returns type of the image display.
********************************************************************************************/
long ImageDisplayGetDisplayType( const ImageDisplay &imgDisp );


/********************************************************************************************
 ImageDisplayGetDoAutoSurvey: Determines whether min and max are determined automatically.
********************************************************************************************/
bool ImageDisplayGetDoAutoSurvey( const ImageDisplay &imgDisp );


/********************************************************************************************
 ImageDisplayGetExportImage: Gets the image representation of the image as it appears on 
the screen at full resolution.
********************************************************************************************/
Image ImageDisplayGetExportImage( const ImageDisplay &imgDisp, ulong mode, ImageDisplay 
&clut_display );


/********************************************************************************************
 ImageDisplayGetImage: Returns the single image displayed by the image display.
********************************************************************************************/
Image ImageDisplayGetImage( const ImageDisplay &imgDisp );


/********************************************************************************************
 ImageDisplayGetImageAdjustRect: Returns the image display outside the image rect 
********************************************************************************************/
void ImageDisplayGetImageAdjustRect( const ImageDisplay &imgDisp, float *top, float *left,
 float *bottom, float *right );


/********************************************************************************************
 ImageDisplayGetImageAdjustRectInView: Returns the image display outside the image rect 
in view coordinates
********************************************************************************************/
void ImageDisplayGetImageAdjustRectInView( const ImageDisplay &imgDisp, float *top, float 
*left, float *bottom, float *right );


/********************************************************************************************
 ImageDisplayGetImageRect: Gets the bounds of the image in the image display.
********************************************************************************************/
void ImageDisplayGetImageRect( const ImageDisplay &imgDisp, float *top, float *left, 
float *bottom, float *right );


/********************************************************************************************
 ImageDisplayGetImageRectInView: Gets the bounds of the image in the image display in 
view coordinates.
********************************************************************************************/
void ImageDisplayGetImageRectInView( const ImageDisplay &imgDisp, float *top, float *left,
 float *bottom, float *right );


/********************************************************************************************
 ImageDisplayGetInputColorTable: Gets the input color table for the display.
********************************************************************************************/
Image ImageDisplayGetInputColorTable( const ImageDisplay &imgDisp );


/********************************************************************************************
 ImageDisplayGetIntensityTransformation: Gets the ITT of the display.
********************************************************************************************/
Image ImageDisplayGetIntensityTransformation( const ImageDisplay &imgDisp );


/********************************************************************************************
 ImageDisplayGetMinimumContrast: Gets the minimum contrast of the display.
********************************************************************************************/
float ImageDisplayGetMinimumContrast( const ImageDisplay &imgDisp );


/********************************************************************************************
 ImageDisplayGetOutputColorTable: Gets the output color table for the display.
********************************************************************************************/
Image ImageDisplayGetOutputColorTable( const ImageDisplay &imgDisp );


/********************************************************************************************
 ImageDisplayGetROI: Returns the given ROI on this image display.
********************************************************************************************/
ROI ImageDisplayGetROI( const ImageDisplay &imgDisp, long index );


/********************************************************************************************
 ImageDisplayGetROISelectionStyle: Gets the selection style of the roi in the imag 
display.
********************************************************************************************/
long ImageDisplayGetROISelectionStyle( const ImageDisplay &imgDisp, const ROI &r );


/********************************************************************************************
 ImageDisplayGetSurveyTechnique: Gets the survey technique of the display.
********************************************************************************************/
long ImageDisplayGetSurveyTechnique( const ImageDisplay &imgDisp );


/********************************************************************************************
 ImageDisplayIsCaptionOn: Returns true if captions are drawn.
********************************************************************************************/
bool ImageDisplayIsCaptionOn( const ImageDisplay &imgDisp );


/********************************************************************************************
 ImageDisplayIsROISelected: Determines whether the given ROI is selected on this image 
display.
********************************************************************************************/
bool ImageDisplayIsROISelected( const ImageDisplay &imgDisp, const ROI &roi );


/********************************************************************************************
 ImageDisplayIsValid: Returns true if 'imageDisplay' points to a valid object.
********************************************************************************************/
bool ImageDisplayIsValid( const ImageDisplay &imgDisp );


/********************************************************************************************
 ImageDisplayLookupROI: Returns the given ROI on this image display.
********************************************************************************************/
ROI ImageDisplayLookupROI( const ImageDisplay &imgDisp, const char *name );


/********************************************************************************************
 ImageDisplayLookupROIByID: Returns the ROI with the given id on this image display.
********************************************************************************************/
ROI ImageDisplayLookupROIByID( const ImageDisplay &imgDisp, long id );


/********************************************************************************************
 ImageDisplayRemoveKeyListener: Removes the listener script with the tag listener_key 
from the key listener list.
********************************************************************************************/
void ImageDisplayRemoveKeyListener( const ImageDisplay &imgDisp, const char *listener_key 
);


/********************************************************************************************
 ImageDisplaySetCaptionOn: Sets whether to draw captions.
********************************************************************************************/
void ImageDisplaySetCaptionOn( const ImageDisplay &imgDisp, bool on );


/********************************************************************************************
 ImageDisplaySetComplexMode: Sets the complex mode of the display.
********************************************************************************************/
void ImageDisplaySetComplexMode( const ImageDisplay &imgDisp, long mode );


/********************************************************************************************
 ImageDisplaySetComplexModeRange: Sets the parameter used in converting complex to real.
********************************************************************************************/
void ImageDisplaySetComplexModeRange( const ImageDisplay &imgDisp, float range );


/********************************************************************************************
 ImageDisplaySetContrastLimits: Sets the contrast limits of the display.
********************************************************************************************/
void ImageDisplaySetContrastLimits( const ImageDisplay &imgDisp, float low, float hight );


/********************************************************************************************
 ImageDisplaySetContrastMode: Sets the contrast mode.
********************************************************************************************/
void ImageDisplaySetContrastMode( const ImageDisplay &imgDisp, long mode );


/********************************************************************************************
 ImageDisplaySetContrastParameters: Gets the parameters for the contrast mode.
********************************************************************************************/
void ImageDisplaySetContrastParameters( const ImageDisplay &imgDisp, float bright, float 
contrast );


/********************************************************************************************
 ImageDisplaySetDisplayedLayers: Sets the layers that are summed into the display.
********************************************************************************************/
void ImageDisplaySetDisplayedLayers( const ImageDisplay &imgDisp, long start, long end );


/********************************************************************************************
 ImageDisplaySetDoAutoSurvey: Sets whether min and max are determined automatically.
********************************************************************************************/
void ImageDisplaySetDoAutoSurvey( const ImageDisplay &imgDisp, bool do_survey );


/********************************************************************************************
 ImageDisplaySetImageRect: Sets the bounds of the image part of the image display.
********************************************************************************************/
void ImageDisplaySetImageRect( const ImageDisplay &imgDisp, float top, float left, float 
bottom, float right );


/********************************************************************************************
 ImageDisplaySetInputColorTable: Sets the input color table of the display.
********************************************************************************************/
void ImageDisplaySetInputColorTable( const ImageDisplay &imgDisp, const Image &clut );


/********************************************************************************************
 ImageDisplaySetIntensityTransformation: Sets the ITT of the display.
********************************************************************************************/
void ImageDisplaySetIntensityTransformation( const ImageDisplay &imgDisp, const Image 
&itt );


/********************************************************************************************
 ImageDisplaySetMinimumContrast: Sets the minimum contrast of the display.
********************************************************************************************/
void ImageDisplaySetMinimumContrast( const ImageDisplay &imgDisp, float contrast );


/********************************************************************************************
 ImageDisplaySetROISelected: Sets the selection status of the region of interest in the 
image display.
********************************************************************************************/
void ImageDisplaySetROISelected( const ImageDisplay &imgDisp, const ROI &roi, bool select 
);


/********************************************************************************************
 ImageDisplaySetROISelectionStyle: Sets the selection style of the roi in the imag 
display.
********************************************************************************************/
void ImageDisplaySetROISelectionStyle( const ImageDisplay &imgDisp, const ROI &r, long 
style );


/********************************************************************************************
 ImageDisplaySetSurveyTechnique: Sets the survey technique of the display.
********************************************************************************************/
void ImageDisplaySetSurveyTechnique( const ImageDisplay &imgDisp, long tech );


/********************************************************************************************
 ImageDocumentAddImage: Adds the given image to the list maintained in the image document.
********************************************************************************************/
void ImageDocumentAddImage( const ImageDocument &imgDoc, const Image &image );


/********************************************************************************************
 ImageDocumentAddImageDisplay: Adds the given image and an image display for it of the 
given type.
********************************************************************************************/
ImageDisplay ImageDocumentAddImageDisplay( const ImageDocument &imgDoc, const Image 
&image, long displayType );


/********************************************************************************************
 ImageDocumentAddToUserInterface: Places the image document in the list of user interface 
documents.
********************************************************************************************/
void ImageDocumentAddToUserInterface( const ImageDocument &imgDoc );


/********************************************************************************************
 ImageDocumentClean: Marks the image document as clean (doesn't need to be saved).
********************************************************************************************/
void ImageDocumentClean( const ImageDocument &imgDoc );


/********************************************************************************************
 ImageDocumentClone: Returns a duplicate of the image docuemnt, creating a copy of its 
images if 'doDeepCopy' is true.
********************************************************************************************/
ImageDocument ImageDocumentClone( const ImageDocument &imgDoc, bool doDeepCopy );


/********************************************************************************************
 ImageDocumentClose: Closes the given image document. If saving is true then asks whether 
to save it, otherwise just closes it.
********************************************************************************************/
void ImageDocumentClose( const ImageDocument &imgDoc, bool saving );


/********************************************************************************************
 ImageDocumentCountImages: Returns the number of images contained in this image document.
********************************************************************************************/
long ImageDocumentCountImages( const ImageDocument &imgDoc );


/********************************************************************************************
 ImageDocumentCreateRGBImageFromDocument: Creates an image by scaling the image document 
into ( width, height ).
********************************************************************************************/
Image ImageDocumentCreateRGBImageFromDocument( const ImageDocument &imgDoc, long width, 
long height, long extract_style, long constraints );


/********************************************************************************************
 ImageDocumentDeleteImage: Deletes the given image from this image document.
********************************************************************************************/
void ImageDocumentDeleteImage( const ImageDocument &imgDoc, const Image &image );


/********************************************************************************************
 ImageDocumentDoesImageWithIDExist: Determines whether the image with the given id exists 
within this image document.
********************************************************************************************/
bool ImageDocumentDoesImageWithIDExist( const ImageDocument &imgDoc, long id );


/********************************************************************************************
 ImageDocumentEnsurePlacedOnPage: Makes sure the document has been layed out on the 
physical page.
********************************************************************************************/
void ImageDocumentEnsurePlacedOnPage( const ImageDocument &imgDoc );


/********************************************************************************************
 ImageDocumentGetAsPICT: Returns this image as a PICT.
********************************************************************************************/
long ImageDocumentGetAsPICT( const ImageDocument &imgDoc );


/********************************************************************************************
 ImageDocumentGetComponentByID: Returns an annotation contained in this image document by 
id.
********************************************************************************************/
Component ImageDocumentGetComponentByID( const ImageDocument &imgDoc, long id );


/********************************************************************************************
 ImageDocumentGetID: Gets the id of the image document.
********************************************************************************************/
long ImageDocumentGetID( const ImageDocument &imgDoc );


/********************************************************************************************
 ImageDocumentGetImage: Returns the image contained within this image document by 
position.
********************************************************************************************/
Image ImageDocumentGetImage( const ImageDocument &imgDoc, long position );


/********************************************************************************************
 ImageDocumentGetImageByID: Returns an image contained in this image document by id.
********************************************************************************************/
Image ImageDocumentGetImageByID( const ImageDocument &imgDoc, long id );


/********************************************************************************************
 ImageDocumentGetImageModeDisplay: Gets the image display targeted by the current image 
mode.
********************************************************************************************/
ImageDisplay ImageDocumentGetImageModeDisplay( const ImageDocument &imgDoc );


/********************************************************************************************
 ImageDocumentGetMinimumPointSize: Gets the size of the minimum point in view coordinates.
********************************************************************************************/
void ImageDocumentGetMinimumPointSize( const ImageDocument &imgDoc, float *x, float *y );


/********************************************************************************************
 ImageDocumentGetName: Returns the name of the image document.
********************************************************************************************/
String ImageDocumentGetName( const ImageDocument &imgDoc );


/********************************************************************************************
 ImageDocumentGetPageBounds: Gets the page bounds of the document in page coordinates.
********************************************************************************************/
void ImageDocumentGetPageBounds( const ImageDocument &imgDoc, float *top, float *left, 
float *bottom, float *right );


/********************************************************************************************
 ImageDocumentGetPageResolution_72dpi: Returns the resolution of page coordinates in 72 
dots per inch ( returns page units per dot ).
********************************************************************************************/
void ImageDocumentGetPageResolution_72dpi( const ImageDocument &imgDoc, float *horz, 
float *vert );


/********************************************************************************************
 ImageDocumentGetPageResolution_Printer: Returns the resolution of page coordinates in 
printer pixels ( returns page units per printer pixel ).
********************************************************************************************/
void ImageDocumentGetPageResolution_Printer( const ImageDocument &imgDoc, float *horz, 
float *vert );


/********************************************************************************************
 ImageDocumentGetPaperBounds: Gets the paper bounds of the document in page coordinates.
********************************************************************************************/
void ImageDocumentGetPaperBounds( const ImageDocument &imgDoc, float *top, float *left, 
float *bottom, float *right );


/********************************************************************************************
 ImageDocumentGetPreferredViewRect: Gets rectangle in view coordinates of the area that 
is by default displayed in this mode.
********************************************************************************************/
void ImageDocumentGetPreferredViewRect( const ImageDocument &imgDoc, float *top, float 
*left, float *bottom, float *right );


/********************************************************************************************
 ImageDocumentGetReferencePointSize: Gets the size of the reference point in view 
coordinates.
********************************************************************************************/
void ImageDocumentGetReferencePointSize( const ImageDocument &imgDoc, float *x, float *y 
);


/********************************************************************************************
 ImageDocumentGetRootComponent: Gets the root annotation of the image document.
********************************************************************************************/
Component ImageDocumentGetRootComponent( const ImageDocument &imgDoc );


/********************************************************************************************
 ImageDocumentGetTagGroup: Gets the tag group associated with the image document.
********************************************************************************************/
TagGroup ImageDocumentGetTagGroup( const ImageDocument &imgDoc );


/********************************************************************************************
 ImageDocumentGetUnzoomedPointSize: Gets the size of the unzoomed point in view 
coordinates.
********************************************************************************************/
void ImageDocumentGetUnzoomedPointSize( const ImageDocument &imgDoc, float *x, float *y );


/********************************************************************************************
 ImageDocumentGetViewExtent: Gets the extent in view coordinates of the items visible in 
the current view mode.
********************************************************************************************/
void ImageDocumentGetViewExtent( const ImageDocument &imgDoc, float *top, float *left, 
float *bottom, float *right );


/********************************************************************************************
 ImageDocumentGetViewToWindowTransform: Returns the transformation from view to screen 
coordinates.
********************************************************************************************/
void ImageDocumentGetViewToWindowTransform( const ImageDocument &imgDoc, float *off_x, 
float *off_y, float *scale_x, float *scale_y );


/********************************************************************************************
 ImageDocumentGetVisibleViewRect: Gets the view coordinates of the rectangle visible in 
the view.
********************************************************************************************/
void ImageDocumentGetVisibleViewRect( const ImageDocument &imgDoc, float *top, float 
*left, float *bottom, float *right );


/********************************************************************************************
 ImageDocumentGetWindow: Returns the window displaying the document.
********************************************************************************************/
Window ImageDocumentGetWindow( const ImageDocument &imgDoc );


/********************************************************************************************
 ImageDocumentHasBeenPlacedOnPage: Returns 'true' if the document has been layed out 
within the physical page.
********************************************************************************************/
bool ImageDocumentHasBeenPlacedOnPage( const ImageDocument &imgDoc );


/********************************************************************************************
 ImageDocumentHide: Hides the given image document.
********************************************************************************************/
void ImageDocumentHide( const ImageDocument &imgDoc );


/********************************************************************************************
 ImageDocumentIsInImageMode: Returns true if the view of the document is in image mode.
********************************************************************************************/
bool ImageDocumentIsInImageMode( const ImageDocument &imgDoc );


/********************************************************************************************
 ImageDocumentIsInPageMode: Returns true if the view of the document is in page mode.
********************************************************************************************/
bool ImageDocumentIsInPageMode( const ImageDocument &imgDoc );


/********************************************************************************************
 ImageDocumentIsValid: Returns true if 'imageDocument' points to a valid object.
********************************************************************************************/
bool ImageDocumentIsValid( const ImageDocument &imgDoc );


/********************************************************************************************
 ImageDocumentMaximizeRectInView: Zooms the view so the rectangle is centered and maximal.
********************************************************************************************/
void ImageDocumentMaximizeRectInView( const ImageDocument &imgDoc, float top, float left, 
float bottom, float right );


/********************************************************************************************
 ImageDocumentPrint: Print the image document, returning 'true' if successful.
********************************************************************************************/
bool ImageDocumentPrint( const ImageDocument &imgDoc );


/********************************************************************************************
 ImageDocumentRemoveFromUserInterface: Removes the image document from the list of user 
interface documents.
********************************************************************************************/
void ImageDocumentRemoveFromUserInterface( const ImageDocument &imgDoc );


/********************************************************************************************
 ImageDocumentSaveToFile: Saves the image document to the given file name using the I/O 
handler specified.
********************************************************************************************/
void ImageDocumentSaveToFile( const ImageDocument &imgDoc, const char *handler, const 
char *fileName );


/********************************************************************************************
 ImageDocumentSetCurrentViewAsUnzoomed: Makes the current view the unzoomed view.
********************************************************************************************/
void ImageDocumentSetCurrentViewAsUnzoomed( const ImageDocument &imgDoc );


/********************************************************************************************
 ImageDocumentSetName: Sets the name of the image document.
********************************************************************************************/
void ImageDocumentSetName( const ImageDocument &imgDoc, const String &name );


/********************************************************************************************
 ImageDocumentSetRectInView: Zooms the view so the view rect (v_l,v_t,v_b,v_r) is 
displayed in the window rect (w_l,w_t,w_b,w_r).
********************************************************************************************/
void ImageDocumentSetRectInView( const ImageDocument &imgDoc, float v_t, float v_l, float 
v_b, float v_r, float w_t, float w_l, float w_b, float w_r );


/********************************************************************************************
 ImageDocumentShow: Shows the given image document.
********************************************************************************************/
Window ImageDocumentShow( const ImageDocument &imgDoc );


/********************************************************************************************
 ImageDocumentShowAtPosition: Shows the given image document at the application position 
(x,y).
********************************************************************************************/
Window ImageDocumentShowAtPosition( const ImageDocument &imgDoc, long x, long y );


/********************************************************************************************
 ImageDocumentShowAtRect: Shows the given image document at the rect 
(top,left,bottom,right).
********************************************************************************************/
Window ImageDocumentShowAtRect( const ImageDocument &imgDoc, long top, long left, long 
bottom, long right );


/********************************************************************************************
 ImageDocumentSwitchToImageMode: Switches the view of the document to image mode focused 
on the display 'imgDisp'.
********************************************************************************************/
void ImageDocumentSwitchToImageMode( const ImageDocument &imgDoc, const ImageDisplay 
&imgDisp );


/********************************************************************************************
 ImageDocumentSwitchToPageMode: Switches the view of the document to page mode.
********************************************************************************************/
void ImageDocumentSwitchToPageMode( const ImageDocument &imgDoc );


/********************************************************************************************
 ImageDocumentUpdateDisplay: Updates the display of the image document.
********************************************************************************************/
void ImageDocumentUpdateDisplay( const ImageDocument &imgDoc );


/********************************************************************************************
 ImageGetDataElementBitSize: Returns the size of the data elements in bits.
********************************************************************************************/
ulong ImageGetDataElementBitSize( const Image &img );


/********************************************************************************************
 ImageGetDataElementByteSize: Returns the smallest number of bytes that can hold a data 
element.
********************************************************************************************/
ulong ImageGetDataElementByteSize( const Image &img );


/********************************************************************************************
 ImageGetDataSeed: Gets the seed of the image data.
********************************************************************************************/
ulong ImageGetDataSeed( const Image &img );


/********************************************************************************************
 ImageGetDataType: Returns a long representing the data type.
********************************************************************************************/
ulong ImageGetDataType( const Image &img );


/********************************************************************************************
 ImageGetDescriptionText: Gets the description text associated with the image.
********************************************************************************************/
String ImageGetDescriptionText( const Image &img );


/********************************************************************************************
 ImageGetDimensionCalibration: Gets the calibration information of the given dimension.
********************************************************************************************/
void ImageGetDimensionCalibration( const Image &argument_1, long dimension, float *origin,
 float *scale, String &units, long calibrationFormat );


/********************************************************************************************
 ImageGetDimensionOrigin: Returns the origin of the given dimension of image.
********************************************************************************************/
float ImageGetDimensionOrigin( const Image &argument_1, long dimension );


/********************************************************************************************
 ImageGetDimensionScale: Returns the scale of the given dimension of image.
********************************************************************************************/
float ImageGetDimensionScale( const Image &argument_1, long dimension );


/********************************************************************************************
 ImageGetDimensionSize: Gets the size of the given dimension.
********************************************************************************************/
ulong ImageGetDimensionSize( const Image &argument_1, ulong dimension );


/********************************************************************************************
 ImageGetDimensionUnitInfo: Copies the unit string of the given dimension of image to the 
buffer.
********************************************************************************************/
void ImageGetDimensionUnitInfo( const Image &argument_1, long dimension, String 
&canon_units, long *power );


/********************************************************************************************
 ImageGetDimensionUnitString: Copies the unit string of the given dimension of image to 
the buffer.
********************************************************************************************/
String ImageGetDimensionUnitString( const Image &argument_1, long dimension );


/********************************************************************************************
 ImageGetID: Returns a unique identifier for the image.
********************************************************************************************/
ulong ImageGetID( const Image &argument_1 );


/********************************************************************************************
 ImageGetImageDisplay: Returns the given image display in which this image is displayed.
********************************************************************************************/
ImageDisplay ImageGetImageDisplay( const Image &argument_1, long index );


/********************************************************************************************
 ImageGetImageDisplayInImageDocument: Returns the given image display in the image 
document in which this image is displayed.
********************************************************************************************/
ImageDisplay ImageGetImageDisplayInImageDocument( const Image &argument_1, const 
ImageDocument &imgDoc, long index );


/********************************************************************************************
 ImageGetIntensityOrigin: Returns the origin of image's intensity.
********************************************************************************************/
float ImageGetIntensityOrigin( const Image &argument_1 );


/********************************************************************************************
 ImageGetIntensityScale: Returns the scale of image's intensity.
********************************************************************************************/
float ImageGetIntensityScale( const Image &argument_1 );


/********************************************************************************************
 ImageGetIntensityUnitInfo: Copies the unit string of image's intensity to the buffer.
********************************************************************************************/
void ImageGetIntensityUnitInfo( const Image &argument_1, String &canon_units, long *power 
);


/********************************************************************************************
 ImageGetIntensityUnitString: Returns the units of the image's intensity.
********************************************************************************************/
String ImageGetIntensityUnitString( const Image &argument_1 );


/********************************************************************************************
 ImageGetLabel: Gets the label of the image as used in scripts.
********************************************************************************************/
String ImageGetLabel( const Image &img );


/********************************************************************************************
 ImageGetName: Gets the name of the image.
********************************************************************************************/
String ImageGetName( const Image &img );


/********************************************************************************************
 ImageGetNumDimensions: Returns number of dimensions of the image.
********************************************************************************************/
ulong ImageGetNumDimensions( const Image &argument_1 );


/********************************************************************************************
 ImageGetOrCreateImageDocument: Returns an image document containing the image, creating 
one if necessary.
********************************************************************************************/
ImageDocument ImageGetOrCreateImageDocument( const Image &im );


/********************************************************************************************
 ImageGetTagGroup: Gets the tags associated with the image.
********************************************************************************************/
TagGroup ImageGetTagGroup( const Image &img );


/********************************************************************************************
 ImageGetUniqueID: Returns the unique ID for this image. This id is globally unique 
across sessions and locations.
********************************************************************************************/
ScriptObject ImageGetUniqueID( const Image &image );


/********************************************************************************************
 ImageIsDataTypeBinary: Returns true if the data in the image is binary.
********************************************************************************************/
bool ImageIsDataTypeBinary( const Image &img );


/********************************************************************************************
 ImageIsDataTypeComplex: Returns true if the data in the image is complex.
********************************************************************************************/
bool ImageIsDataTypeComplex( const Image &img );


/********************************************************************************************
 ImageIsDataTypeFloat: Returns true if the data in the image is floating point.
********************************************************************************************/
bool ImageIsDataTypeFloat( const Image &img );


/********************************************************************************************
 ImageIsDataTypeInteger: Returns true if the data in the image is integral.
********************************************************************************************/
bool ImageIsDataTypeInteger( const Image &img );


/********************************************************************************************
 ImageIsDataTypePackedComplex: Returns true if the data in the image is complex.
********************************************************************************************/
bool ImageIsDataTypePackedComplex( const Image &img );


/********************************************************************************************
 ImageIsDataTypeReal: Returns true if the data in the image is real.
********************************************************************************************/
bool ImageIsDataTypeReal( const Image &img );


/********************************************************************************************
 ImageIsDataTypeRGB: Returns true if the data in the image is rgb.
********************************************************************************************/
bool ImageIsDataTypeRGB( const Image &img );


/********************************************************************************************
 ImageIsDataTypeSignedInteger: Returns true if the data in the image is integral and 
signed.
********************************************************************************************/
bool ImageIsDataTypeSignedInteger( const Image &img );


/********************************************************************************************
 ImageIsDataTypeUnsignedInteger: Returns true if the data in the image is integral and 
unsigned.
********************************************************************************************/
bool ImageIsDataTypeUnsignedInteger( const Image &img );


/********************************************************************************************
 ImageIsDimensionCalibrationDisplayed: Returns 'true' if the calibration of the 'dim'th 
dimension is displayed.
********************************************************************************************/
bool ImageIsDimensionCalibrationDisplayed( const Image &im, ulong dim );


/********************************************************************************************
 ImageIsIntensityCalibrationDisplayed: Returns 'true' if the calibration of the intensity 
is displayed.
********************************************************************************************/
bool ImageIsIntensityCalibrationDisplayed( const Image &im );


/********************************************************************************************
 ImageIsValid: Returns true if 'image' is a valid object.
********************************************************************************************/
bool ImageIsValid( const Image &image );


/********************************************************************************************
 ImageSetDescriptionText: Sets the description text associated with the image.
********************************************************************************************/
void ImageSetDescriptionText( const Image &img, const String &description );


/********************************************************************************************
 ImageSetDimensionCalibration: Sets the calibration for the given dimension.
********************************************************************************************/
void ImageSetDimensionCalibration( const Image &argument_1, long dimenstion, float origin,
 float scale, const String &unitString, long calibrationFormat );


/********************************************************************************************
 ImageSetDimensionCalibrationDisplayed: Sets whether or not to display the 'dim'th 
dimension in calibrated units to 'do_display'.
********************************************************************************************/
void ImageSetDimensionCalibrationDisplayed( const Image &im, ulong dim, bool do_display );


/********************************************************************************************
 ImageSetDimensionOrigin: Sets the origin of the given dimension of image.
********************************************************************************************/
void ImageSetDimensionOrigin( const Image &argument_1, long dimension, float origin );


/********************************************************************************************
 ImageSetDimensionScale: Sets the scale of the given dimension of image.
********************************************************************************************/
void ImageSetDimensionScale( const Image &argument_1, long dimension, float scale );


/********************************************************************************************
 ImageSetDimensionUnitInfo: Sets the unit string of the given dimension of image.
********************************************************************************************/
void ImageSetDimensionUnitInfo( const Image &argument_1, long dimension, const String 
&canon_units, long power );


/********************************************************************************************
 ImageSetDimensionUnitString: Sets the unit string of the given dimension of image.
********************************************************************************************/
void ImageSetDimensionUnitString( const Image &argument_1, long dimension, const String 
&units );


/********************************************************************************************
 ImageSetIntensityCalibrationDisplayed: Sets whether or not to display the intensity in 
calibrated units to 'do_display'.
********************************************************************************************/
void ImageSetIntensityCalibrationDisplayed( const Image &im, bool do_display );


/********************************************************************************************
 ImageSetIntensityOrigin: Sets the origin of image's intensity.
********************************************************************************************/
void ImageSetIntensityOrigin( const Image &argument_1, float origin );


/********************************************************************************************
 ImageSetIntensityScale: Sets the scale of image's intensity.
********************************************************************************************/
void ImageSetIntensityScale( const Image &argument_1, float scale );


/********************************************************************************************
 ImageSetIntensityUnitInfo: Sets the unit string of image's intensity.
********************************************************************************************/
void ImageSetIntensityUnitInfo( const Image &argument_1, const String &canon_units, long 
power );


/********************************************************************************************
 ImageSetIntensityUnitString: Sets the unit string of image's intensity.
********************************************************************************************/
void ImageSetIntensityUnitString( const Image &argument_1, const String &units );


/********************************************************************************************
 ImageSetName: Sets the name of the image.
********************************************************************************************/
void ImageSetName( const Image &img, const String &name );


/********************************************************************************************
 ImageWindowGetImageDocument: Gets the image document displayed in the window.
********************************************************************************************/
ImageDocument ImageWindowGetImageDocument( const Window &window );


/********************************************************************************************
 InstallScriptLibraryFile: Loads the script file indicated by fileName, executes it, and 
publishes any functions contained inside. Always returns 0.
********************************************************************************************/
float InstallScriptLibraryFile( const char *fileName );


/********************************************************************************************
 IntegerImage: Creates a 3D integer image of size [d0,d1,d2] with the given title. The 
bytes can be 1, 2, or 4 and isSigned can be 1 (true) or 0 (false).
********************************************************************************************/
Image IntegerImage( const char *title, long bytes, bool isSigned, long d0, long d1, long 
d2 );


/********************************************************************************************
 IntegerImage: Creates a 2D integer image of size [d0,d1] with the given title. The bytes 
and isSigned parameters specify integer specific attributes of the data.
********************************************************************************************/
Image IntegerImage( const char *title, long bytes, bool isSigned, long d0, long d1 );


/********************************************************************************************
 IntegerImage: Creates a 1D integer image of size [d0] with the given title. The bytes 
and isSigned parameters specify integer specific attributes of the data.
********************************************************************************************/
Image IntegerImage( const char *title, long bytes, bool isSigned, long d0 );


/********************************************************************************************
 Is2DDisplay: Return 1 if the image is displayed as a raster image display; return 0 
otherwise.
********************************************************************************************/
bool Is2DDisplay( const Image &argument_1 );


/********************************************************************************************
 IsBinaryDataType: Returns 1 if the image is an binary data type; returns 0 otherwise.
********************************************************************************************/
bool IsBinaryDataType( const Image &argument_1 );


/********************************************************************************************
 IsByteImage: Returns 1 if the image is unsigned 1-byte integer data; returns 0 otherwise.
********************************************************************************************/
bool IsByteImage( const Image &argument_1 );


/********************************************************************************************
 IsComplexDataType: Returns 1 if the image is an complex data type of size bytes; returns 
0 otherwise.
********************************************************************************************/
bool IsComplexDataType( const Image &argument_1, long bytes );


/********************************************************************************************
 IsComplexImage: Returns 1 if the image is single precision complex data; returns 0 
otherwise.
********************************************************************************************/
bool IsComplexImage( const Image &argument_1 );


/********************************************************************************************
 IsDisplayValid: Return 1 if the image's display is up-to-date and 0 otherwise.
********************************************************************************************/
bool IsDisplayValid( const Image &argument_1 );


/********************************************************************************************
 IsExceptionUserAbort: Returns true if the exception currently in effect is a user abort.
********************************************************************************************/
bool IsExceptionUserAbort( );


/********************************************************************************************
 IsFloatImage: Returns 1 if the image is single precision real data; returns 0 otherwise.
********************************************************************************************/
bool IsFloatImage( const Image &argument_1 );


/********************************************************************************************
 IsImageComplex: Return true or false to indicate whether given image with the given id 
is complex-valued or not.
********************************************************************************************/
bool IsImageComplex( long id );


/********************************************************************************************
 IsImageReal: Return true or false to indicate whether given image with the given id is 
real-valued or not.
********************************************************************************************/
bool IsImageReal( long id );


/********************************************************************************************
 IsImageRGB: Return true or false to indicate whether given image with the given id is 
RGB-valued or not.
********************************************************************************************/
bool IsImageRGB( long id );


/********************************************************************************************
 IsIntegerDataType: Returns 1 if the image is an integer data type of size bytes with a 
matching sign charateristic as signed; returns 0 otherwise.
********************************************************************************************/
bool IsIntegerDataType( const Image &argument_1, long bytes, bool isSigned );


/********************************************************************************************
 IsLongImage: Returns 1 if the image is signed 4-byte integer data; returns 0 otherwise.
********************************************************************************************/
bool IsLongImage( const Image &argument_1 );


/********************************************************************************************
 IsPackedComplexImage: Returns 1 if the image is packed complex data; returns 0 otherwise.
********************************************************************************************/
bool IsPackedComplexImage( const Image &argument_1 );


/********************************************************************************************
 IsRealDataType: Returns 1 if the image is an real data type of size bytes; returns 0 
otherwise.
********************************************************************************************/
bool IsRealDataType( const Image &argument_1, long bytes );


/********************************************************************************************
 IsRGBDataType: Returns 1 if the image is an RGB data type of size bytes; returns 0 
otherwise.
********************************************************************************************/
bool IsRGBDataType( const Image &argument_1, long bytes );


/********************************************************************************************
 IsShortImage: Returns 1 if the image is signed 2-byte integer data; returns 0 otherwise.
********************************************************************************************/
bool IsShortImage( const Image &argument_1 );


/********************************************************************************************
 KeepImage: Keep the image from being deleted automatically when the image's script scope 
is exited.
********************************************************************************************/
void KeepImage( const Image &argument_1 );


/********************************************************************************************
 LinePlotImageDisplayCountSlices: Returns the number of slices in the line plot.
********************************************************************************************/
long LinePlotImageDisplayCountSlices( const LinePlotImageDisplay &lpid );


/********************************************************************************************
 LinePlotImageDisplayGetBaseIntensity: Returns the base intensity of the line plot.
********************************************************************************************/
double LinePlotImageDisplayGetBaseIntensity( const LinePlotImageDisplay &lpid );


/********************************************************************************************
 LinePlotImageDisplayGetContrastLimits: Gets the lowest and higest intensities displayed.
********************************************************************************************/
void LinePlotImageDisplayGetContrastLimits( const LinePlotImageDisplay &lpid, float 
*lowLimit, float *highLimit );


/********************************************************************************************
 LinePlotImageDisplayGetDisplayedChannels: Gets the leftmost and rightmost displayed 
channels.
********************************************************************************************/
void LinePlotImageDisplayGetDisplayedChannels( const LinePlotImageDisplay &lpid, float 
*leftChannel, float *rightChannel );


/********************************************************************************************
 LinePlotImageDisplayGetDoAutoSurvey: Gets whether to auto-survey is done on the high and 
low intensity limits.
********************************************************************************************/
void LinePlotImageDisplayGetDoAutoSurvey( const LinePlotImageDisplay &lpid, bool 
*doAutoSurveyLow, bool *doAutoSurveyHigh );


/********************************************************************************************
 LinePlotImageDisplayGetSlice: Returns slice currently displayed at the bottom.
********************************************************************************************/
long LinePlotImageDisplayGetSlice( const LinePlotImageDisplay &lpid );


/********************************************************************************************
 LinePlotImageDisplayGetSliceComponentColor: Returns the color of the 'comp_index'th 
component of the 'slice_index'th slice.
********************************************************************************************/
void LinePlotImageDisplayGetSliceComponentColor( const LinePlotImageDisplay &lpid, long 
slice_index, long comp_index, double *r, double *g, double *b );


/********************************************************************************************
 LinePlotImageDisplayGetSliceDrawingStyle: Returns the drawing style of the 
'slice_index'th slice.
********************************************************************************************/
long LinePlotImageDisplayGetSliceDrawingStyle( const LinePlotImageDisplay &lpid, long 
slice_index );


/********************************************************************************************
 LinePlotImageDisplayGetTrackingStyle: Gets the tracking style of the line plot.
********************************************************************************************/
void LinePlotImageDisplayGetTrackingStyle( const LinePlotImageDisplay &lpid, uint16 
*track_style_x, uint16 *track_style_y );


/********************************************************************************************
 LinePlotImageDisplayIsBackgroundOn: Returns true if the background is erased.
********************************************************************************************/
bool LinePlotImageDisplayIsBackgroundOn( const LinePlotImageDisplay &lpid );


/********************************************************************************************
 LinePlotImageDisplayIsFilled: Returns true if the line plot is filled.
********************************************************************************************/
bool LinePlotImageDisplayIsFilled( const LinePlotImageDisplay &lpid );


/********************************************************************************************
 LinePlotImageDisplayIsFrameOn: Returns true if the frame is drawn.
********************************************************************************************/
bool LinePlotImageDisplayIsFrameOn( const LinePlotImageDisplay &lpid );


/********************************************************************************************
 LinePlotImageDisplayIsGridOn: Returns true if the grid is displayed on.
********************************************************************************************/
bool LinePlotImageDisplayIsGridOn( const LinePlotImageDisplay &lpid );


/********************************************************************************************
 LinePlotImageDisplaySetBackgroundOn: Sets whether to erase the background.
********************************************************************************************/
void LinePlotImageDisplaySetBackgroundOn( const LinePlotImageDisplay &lpid, bool on );


/********************************************************************************************
 LinePlotImageDisplaySetBaseIntensity: Sets the base intensity of the line plot.
********************************************************************************************/
void LinePlotImageDisplaySetBaseIntensity( const LinePlotImageDisplay &lpid, double 
base_intensity );


/********************************************************************************************
 LinePlotImageDisplaySetContrastLimits: Sets the lowest and highest intensities displayed.
********************************************************************************************/
void LinePlotImageDisplaySetContrastLimits( const LinePlotImageDisplay &lpid, float 
lowLimit, float highLimit );


/********************************************************************************************
 LinePlotImageDisplaySetDisplayedChannels: Sets the leftmost and rightmost displayed 
channels.
********************************************************************************************/
void LinePlotImageDisplaySetDisplayedChannels( const LinePlotImageDisplay &lpid, float 
leftChannel, float rightChannel );


/********************************************************************************************
 LinePlotImageDisplaySetDoAutoSurvey: Sets whether to do auto-survey on the high and low 
intensity limits.
********************************************************************************************/
void LinePlotImageDisplaySetDoAutoSurvey( const LinePlotImageDisplay &lpid, bool 
doAutoSurveyLow, bool doAutoSurveyHigh );


/********************************************************************************************
 LinePlotImageDisplaySetFilled: Sets whether to fill the lineplot.
********************************************************************************************/
void LinePlotImageDisplaySetFilled( const LinePlotImageDisplay &lpid, bool on );


/********************************************************************************************
 LinePlotImageDisplaySetFrameOn: Sets whether to draw the frame.
********************************************************************************************/
void LinePlotImageDisplaySetFrameOn( const LinePlotImageDisplay &lpid, bool on );


/********************************************************************************************
 LinePlotImageDisplaySetGridOn: Sets whether to draw the grid.
********************************************************************************************/
void LinePlotImageDisplaySetGridOn( const LinePlotImageDisplay &lpid, bool on );


/********************************************************************************************
 LinePlotImageDisplaySetSlice: Sets the slice currently displayed at the bottom.
********************************************************************************************/
void LinePlotImageDisplaySetSlice( const LinePlotImageDisplay &lpid, long slice );


/********************************************************************************************
 LinePlotImageDisplaySetSliceComponentColor: Sets the color of the 'comp_index'th 
component of the 'slice_index'th slice.
********************************************************************************************/
void LinePlotImageDisplaySetSliceComponentColor( const LinePlotImageDisplay &lpid, long 
slice_index, long comp_index, double r, double g, double b );


/********************************************************************************************
 LinePlotImageDisplaySetSliceDrawingStyle: Sets the drawing style of the 'slice_index'th 
slice.
********************************************************************************************/
void LinePlotImageDisplaySetSliceDrawingStyle( const LinePlotImageDisplay &lpid, long 
slice_index, long style );


/********************************************************************************************
 LinePlotImageDisplaySetTrackingStyle: Sets the tracking style of the line plot.
********************************************************************************************/
void LinePlotImageDisplaySetTrackingStyle( const LinePlotImageDisplay &lpid, uint16 
track_style_x, uint16 track_style_y );


/********************************************************************************************
 LUDecomposition: Return the image resulting from a LU decomposition on images a,b.
********************************************************************************************/
Image LUDecomposition( const Image &a, const Image &b );


/********************************************************************************************
 MaintainStatus: Update the status window if it needs to be updated.
********************************************************************************************/
void MaintainStatus( );


/********************************************************************************************
 MatrixDeterminant: Return the matrix determinant number of matrix image a.
********************************************************************************************/
float MatrixDeterminant( const Image &a );


/********************************************************************************************
 MatrixInverse: Return the matrix inverse image of matrix image a.
********************************************************************************************/
Image MatrixInverse( const Image &a );


/********************************************************************************************
 MatrixMultiply: Return the matrix product image of matrix images a and b.
********************************************************************************************/
Image MatrixMultiply( const Image &a, const Image &b );


/********************************************************************************************
 MatrixPrint: Print an image as a matrix to the results window.
********************************************************************************************/
void MatrixPrint( const Image &a );


/********************************************************************************************
 MatrixTranspose: Return the matrix transpose image of matrix image a.
********************************************************************************************/
Image MatrixTranspose( const Image &a );


/********************************************************************************************
 MedianFilter: Performs a median filter on the source image according to the filterType 
parameter (0=horizontal, 1=vertical, 2=cross, 3=entire) and the size parameter. Size 
specifies size in each direction - so a 'size' of 2 is a 5x5 window.
********************************************************************************************/
Image MedianFilter( const Image &source, long filterType, long size );


/********************************************************************************************
 ModelessDialog: Present a modeless dialog with the prompt and buttonName. When the user 
presses the button, the semaphore will be cleared. This function can only be used in the 
background.
********************************************************************************************/
void ModelessDialog( const char *prompt, const char *buttonName, long semaphore );


/********************************************************************************************
 ModelessFFT: Begin the modeless FFT procedure with the image as the source. The 
parameter reduce indicates whether to perform a reduced FFT.
********************************************************************************************/
void ModelessFFT( const Image &argument_1, bool reduce );


/********************************************************************************************
 MPClose: Morphologically close the image using the neighbors parameter to control the 
closing and return the resulting image. The source image must be binary.
********************************************************************************************/
Image MPClose( const Image &image, long neighbors );


/********************************************************************************************
 MPDilate: Morphologically dilate the image using the neighbors parameter to control the 
dilation and return the resulting image. The source image must be binary.
********************************************************************************************/
Image MPDilate( const Image &image, long neighbors );


/********************************************************************************************
 MPDistanceMap: Generate a distance map from the source image and return the resulting 
real image. The source image must be binary.
********************************************************************************************/
Image MPDistanceMap( const Image &image );


/********************************************************************************************
 MPErode: Morphologically erode the image using the neighbors parameter to control the 
erosion and return the resulting image. The source image must be binary.
********************************************************************************************/
Image MPErode( const Image &image, long neighbors );


/********************************************************************************************
 MPEuclideanDistanceMap: Generate a Euclidean distance map from the source image and 
return the resulting real image. The source image must be binary.
********************************************************************************************/
Image MPEuclideanDistanceMap( const Image &image );


/********************************************************************************************
 MPExactDistanceMap: Generate an exact distance map from the source image and return the 
resulting complex image. The source image must be binary.
********************************************************************************************/
Image MPExactDistanceMap( const Image &image );


/********************************************************************************************
 MPOpen: Morphologically open the image using the neighbors parameter to control the 
opening and return the resulting image. The source image must be binary.
********************************************************************************************/
Image MPOpen( const Image &image, long neighbors );


/********************************************************************************************
 MPOutline: Morphologically outline the image and return the resulting image. The source 
image must be binary.
********************************************************************************************/
Image MPOutline( const Image &image );


/********************************************************************************************
 NewAbstractMethod: Returns an abstract method with name 'method_name' and signature 
'method_signature'.
********************************************************************************************/
Function NewAbstractMethod( const String &method_name, const String &method_signature );


/********************************************************************************************
 NewArrowAnnotation: Creates a new arrow annotation.
********************************************************************************************/
Component NewArrowAnnotation( float top, float left, float bottom, float right );


/********************************************************************************************
 NewBoxAnnotation: Creates a new box annotation.
********************************************************************************************/
Component NewBoxAnnotation( float top, float left, float bottom, float right );


/********************************************************************************************
 NewCallbackFunction: Creates a function representing a callback to a C function 
'callback'.
********************************************************************************************/
Function NewCallbackFunction( const String &method_signature, void *callback, uint32 linkage_style );


/********************************************************************************************
 NewComponent: Creates a new annotaiton of type 'type'
********************************************************************************************/
Component NewComponent( long type, float f1, float f2, float f3, float f4 );


/********************************************************************************************
 NewDoubleArrowAnnotation: Creates a new double arrow annotation.
********************************************************************************************/
Component NewDoubleArrowAnnotation( float top, float left, float bottom, float right );


/********************************************************************************************
 NewFunctionFromScript: Compiles script and returns the function matching signature.
********************************************************************************************/
Function NewFunctionFromScript( const String &script, const String &signature );


/********************************************************************************************
 NewGroupAnnotation: Creates a new group annotation.
********************************************************************************************/
Component NewGroupAnnotation( );


/********************************************************************************************
 NewImage: Creates a 1D image of type 'type' and size [d0] with the given title.
********************************************************************************************/
Image NewImage( const char *title, long type, long d0 );


/********************************************************************************************
 NewImage: Creates a 2D image of type 'type' and size [d0,d1] with the given title.
********************************************************************************************/
Image NewImage( const char *title, long type, long d0, long d1 );


/********************************************************************************************
 NewImage: Creates a 3D image of type 'type' and size [d0,d1,d2] with the given title.
********************************************************************************************/
Image NewImage( const char *title, long type, long d0, long d1, long d2 );


/********************************************************************************************
 NewImage: Creates a 4D image of type 'type' and size [d0,d1,d2,d3] with the given title.
********************************************************************************************/
Image NewImage( const char *title, long type, long d0, long d1, long d2, long d3 );


/********************************************************************************************
 NewImageDocument: Creates an empty image document.
********************************************************************************************/
ImageDocument NewImageDocument( const char *title );


/********************************************************************************************
 NewImageDocumentFromFile: Creates a new image document from a file.
********************************************************************************************/
ImageDocument NewImageDocumentFromFile( const char *path_name );


/********************************************************************************************
 NewImageFromFile: Opens a file and reads it as an image.
********************************************************************************************/
Image NewImageFromFile( const char *file_path );


/********************************************************************************************
 NewLineAnnotation: Creates a new line annotation.
********************************************************************************************/
Component NewLineAnnotation( float top, float left, float bottom, float right );


/********************************************************************************************
 NewLiveFFT: Creates a new live fft of the area in 'roi', that is reduced if 'reduce' is 
'true'
********************************************************************************************/
Image NewLiveFFT( const ImageDisplay &imageDisplay, const ROI &roi, bool reduce );


/********************************************************************************************
 NewLiveHistogram: Creates a new live histogram of the area in 'roi', binned by 
'num_channels'
********************************************************************************************/
Image NewLiveHistogram( const ImageDisplay &imageDisplay, const ROI &roi, long 
num_channels );


/********************************************************************************************
 NewLiveProfile: Creates a new live profile from (start_x,start_y) to (end_x,end_y)
********************************************************************************************/
Image NewLiveProfile( const ImageDisplay &imageDisplay, float start_x, float start_y, 
float end_x, float end_y, float width );


/********************************************************************************************
 NewOvalAnnotation: Creates a new oval annotation.
********************************************************************************************/
Component NewOvalAnnotation( float top, float left, float bottom, float right );


/********************************************************************************************
 NewPictureAnnotation: Creates a new picture annotation.
********************************************************************************************/
Component NewPictureAnnotation( float top, float left, float bottom, float right, long 
picture );


/********************************************************************************************
 NewROI: Creates an empty region of interest.
********************************************************************************************/
ROI NewROI( );


/********************************************************************************************
 NewScriptWindow: Creates a new editor window.
********************************************************************************************/
Window NewScriptWindow( const String &title, long top, long left, long bottom, long right 
);


/********************************************************************************************
 NewScriptWindowFromFile: Opens a file into a script window.
********************************************************************************************/
Window NewScriptWindowFromFile( const String &file_name, long top, long left, long bottom,
 long right );


/********************************************************************************************
 NewScriptWindowFromFile: Opens a file into a script window.
********************************************************************************************/
Window NewScriptWindowFromFile( const String &file_name );


/********************************************************************************************
 NewScriptWindowFromFile: Opens a file into a script window.
********************************************************************************************/
Window NewScriptWindowFromFile( const String &file_name, const String &font_name, ulong 
attributes, ulong size );


/********************************************************************************************
 NewScriptWindowFromFile: Opens a file into a script window.
********************************************************************************************/
Window NewScriptWindowFromFile( const String &file_name, const String &font_name, ulong 
attributes, ulong size, long top, long left, long bottom, long right );


/********************************************************************************************
 NewSemaphore: Create a semaphore. Used only with background processing.
********************************************************************************************/
long NewSemaphore( );


/********************************************************************************************
 NewTagGroup: Creates an empty tag group.
********************************************************************************************/
TagGroup NewTagGroup( );


/********************************************************************************************
 NewTagList: Creates an empty tag list.
********************************************************************************************/
TagGroup NewTagList( );


/********************************************************************************************
 NewTextAnnotation: Creates a new text annotation.
********************************************************************************************/
Component NewTextAnnotation( float left, float top, const String &text, float size );


/********************************************************************************************
 NextImage: Find the next image.
********************************************************************************************/
Image NextImage( const Image &argument_1 );


/********************************************************************************************
 ObjectTransformCompose: Composes the transform (i1_o_x,i1_o_y,i1_s_x,i1_s_y) with 
(i2_o_x,i2_o_y,i2_s_x,i2_s_y) and places the result in (*o_o_x,*o_o_y,*o_s_x,*o_s_y).
********************************************************************************************/
void ObjectTransformCompose( double i1_o_x, double i1_o_y, double i1_s_x, double i1_s_y, 
double i2_o_x, double i2_o_y, double i2_s_x, double i2_s_y, double *o_o_x, double *o_o_y, 
double *o_s_x, double *o_s_y );


/********************************************************************************************
 ObjectTransformInvert: Inverts the transform (i_o_x,i_o_y,i_s_x,i_s_y) and places the 
result in (*o_o_x,*o_o_y,*o_s_x,*o_s_y).
********************************************************************************************/
void ObjectTransformInvert( double i_o_x, double i_o_y, double i_s_x, double i_s_y, 
double *o_o_x, double *o_o_y, double *o_s_x, double *o_s_y );


/********************************************************************************************
 ObjectTransformTransformPoint: Transforms the point (i_p_x,i_p_y) by the transform 
(i_o_x,i_o_y,i_s_x,i_s_y) and places the result in (*o_p_x,*o_p_y).
********************************************************************************************/
void ObjectTransformTransformPoint( double i_o_x, double i_o_y, double i_s_x, double 
i_s_y, double i_p_x, double i_p_y, double *o_p_x, double *o_p_y );


/********************************************************************************************
 ObjectTransformTransformRect: Transforms the point (i_r_t,i_r_l,i_r_b,i_r_r) by the 
transform (i_o_x,i_o_y,i_s_x,i_s_y) and places the result in 
(*o_r_t,*o_r_l,*o_r_b,*o_r_r).
********************************************************************************************/
void ObjectTransformTransformRect( double i_o_x, double i_o_y, double i_s_x, double i_s_y,
 double i_r_t, double i_r_l, double i_r_b, double i_r_r, double *o_r_t, double *o_r_l, 
double *o_r_b, double *o_r_r );


/********************************************************************************************
 ObjectTransformUntransformPoint: Transforms the point (i_p_x,i_p_y) by the transform 
(i_o_x,i_o_y,i_s_x,i_s_y) and places the result in (*o_p_x,*o_p_y).
********************************************************************************************/
void ObjectTransformUntransformPoint( double i_o_x, double i_o_y, double i_s_x, double 
i_s_y, double i_p_x, double i_p_y, double *o_p_x, double *o_p_y );


/********************************************************************************************
 ObjectTransformUntransformRect: Transforms the point (i_r_t,i_r_l,i_r_b,i_r_r) by the 
transform (i_o_x,i_o_y,i_s_x,i_s_y) and places the result in 
(*o_r_t,*o_r_l,*o_r_b,*o_r_r).
********************************************************************************************/
void ObjectTransformUntransformRect( double i_o_x, double i_o_y, double i_s_x, double 
i_s_y, double i_r_t, double i_r_l, double i_r_b, double i_r_r, double *o_r_t, double 
*o_r_l, double *o_r_b, double *o_r_r );


/********************************************************************************************
 OkCancelDialog: Puts up a dialog with the given prompt. Returns 1 for OK and 0 for 
Cancel.
********************************************************************************************/
bool OkCancelDialog( const char *prompt );


/********************************************************************************************
 OkDialog: Puts up a dialog with the given prompt.
********************************************************************************************/
void OkDialog( const char *prompt );


/********************************************************************************************
 OpenAndSetProgressWindow: Open the progress window and sets the text within to line1, 
line2, and line3.
********************************************************************************************/
void OpenAndSetProgressWindow( const char *line1, const char *line2, const char *line3 );


/********************************************************************************************
 OpenDialog: Puts up an Open dialog, allows the user to select a file, and stores the 
pathname into the pathname variable. Returns 1 for OK and 0 for Cancel.
********************************************************************************************/
bool OpenDialog( char *pathname );


/********************************************************************************************
 OpenFileForReading: Open the file for reading. Return the file reference for this file. 
This call must be balanced with call to CloseFile() with the returned reference number.
********************************************************************************************/
DM_FileReference OpenFileForReading( const char *fileName );


/********************************************************************************************
 OpenFileForReadingAndWriting: Open the file for reading and writing. Return the file 
reference for this file. This call must be balanced with call to CloseFile() with the 
returned reference number.
********************************************************************************************/
DM_FileReference OpenFileForReadingAndWriting( const char *fileName );


/********************************************************************************************
 OpenFileForWriting: Open the file for writing. Return the file reference for this file. 
This call must be balanced with call to CloseFile() with the returned reference number.
********************************************************************************************/
DM_FileReference OpenFileForWriting( const char *fileName );


/********************************************************************************************
 OpenImage: Open the image with the filename. Returns the opened image.
********************************************************************************************/
Image OpenImage( const char *fileName );


/********************************************************************************************
 OpenResultsWindow: Open the results window if it is not already open.
********************************************************************************************/
void OpenResultsWindow( );


/********************************************************************************************
 OpenTimeBar: Opens the time bar with the given prompt. The total parameter is ignored. 
CloseTimeBar() must be invoked exactly once for every OpenTimeBar() call.
********************************************************************************************/
void OpenTimeBar( const char *prompt, long total );


/********************************************************************************************
 OptionDown: Returns 1 if the option key is down and 0 otherwise.
********************************************************************************************/
bool OptionDown( );


/********************************************************************************************
 PackedFFT: Creates a new packed complex image from the FFT of the real image source.
********************************************************************************************/
Image PackedFFT( const Image &source );


/********************************************************************************************
 PackedIFFT: Creates a new real image from the inverse FFT of the packed complex image 
source.
********************************************************************************************/
Image PackedIFFT( const Image &source );


/********************************************************************************************
 PackedToComplex: Creates a new complex 8-byte image from the packed complex source.
********************************************************************************************/
Image PackedToComplex( const Image &source );


/********************************************************************************************
 PathAddParentIndirection: Returns 'path' appended with a string denoting indirection to 
the parent directory 
********************************************************************************************/
String PathAddParentIndirection( const String &path );


/********************************************************************************************
 PathBeginRelative: Returns a string that begins a relative path
********************************************************************************************/
String PathBeginRelative( );


/********************************************************************************************
 PathConcatenate: Concatenates 'final_path' to 'initial_path' to create a new path, 
adding separators as necessary.
********************************************************************************************/
String PathConcatenate( const String &initial_path, const String &final_path );


/********************************************************************************************
 PathExtractBaseName: Returns the base name portion of 'dir_path', where 'path_type' 
denotes '1' for Mac paths, '2' for Windows paths, and '0' for current OS paths
********************************************************************************************/
String PathExtractBaseName( const String &path, ulong path_type );


/********************************************************************************************
 PathExtractDirectory: Returns the directory portion of 'dir_path', where 'path_type' 
denotes '1' for Mac paths, '2' for Windows paths, and '0' for current OS paths
********************************************************************************************/
String PathExtractDirectory( const String &path, ulong path_type );


/********************************************************************************************
 PathExtractExtension: Returns the extension portion of 'dir_path', where 'path_type' 
denotes '1' for Mac paths, '2' for Windows paths, and '0' for current OS paths
********************************************************************************************/
String PathExtractExtension( const String &path, ulong path_type );


/********************************************************************************************
 PathExtractFileName: Returns the file name portion of 'dir_path', where 'path_type' 
denotes '1' for Mac paths, '2' for Windows paths, and '0' for current OS paths
********************************************************************************************/
String PathExtractFileName( const String &path, ulong path_type );


/********************************************************************************************
 PathExtractParentDirectory: Returns the parent directory portion of 'dir_path', where 
'path_type' denotes '1' for Mac paths, '2' for Windows paths, and '0' for current OS paths
********************************************************************************************/
String PathExtractParentDirectory( const String &path, ulong path_type );


/********************************************************************************************
 PathGetFullpath: Returns the full path name of the file denoted by 'dir_path'
********************************************************************************************/
String PathGetFullpath( const String &path );


/********************************************************************************************
 Pi: Return an approximation of pi.
********************************************************************************************/
double Pi( );


/********************************************************************************************
 PictureAnnotationSetPicture: Sets the picture of an annotation.
********************************************************************************************/
void PictureAnnotationSetPicture( const Component &comp, long picture );


/********************************************************************************************
 PIctureGetBounds: Gets the preferred bounds of the picture for display on the screen.
********************************************************************************************/
void PIctureGetBounds( long picture, float *top, float *left, float *bottom, float *right 
);


/********************************************************************************************
 PrintImage: Print the image.
********************************************************************************************/
void PrintImage( const Image &argument_1 );


/********************************************************************************************
 RasterImageDisplayAddThresholdToMask: Sets the points in mask to 1 if they lie within 
the threshold.
********************************************************************************************/
void RasterImageDisplayAddThresholdToMask( const RasterImageDisplay &rid, const Image 
&mask, float top, float left, float bottom, float right );


/********************************************************************************************
 RasterImageDisplayGetThresholdLimits: Gets the threshold limits of the display.
********************************************************************************************/
void RasterImageDisplayGetThresholdLimits( const RasterImageDisplay &rid, float *low, 
float *high );


/********************************************************************************************
 RasterImageDisplayIsThresholdOn: Determines whether the thresholding overlay is on or 
off.
********************************************************************************************/
bool RasterImageDisplayIsThresholdOn( const RasterImageDisplay &rid );


/********************************************************************************************
 RasterImageDisplaySetThresholdLimits: Sets the threshold limits of the display.
********************************************************************************************/
void RasterImageDisplaySetThresholdLimits( const RasterImageDisplay &rid, float low, 
float high );


/********************************************************************************************
 RasterImageDisplaySetThresholdOn: Sets whether the thresholding overlay is on or off.
********************************************************************************************/
void RasterImageDisplaySetThresholdOn( const RasterImageDisplay &rid, bool on );


/********************************************************************************************
 RasterizeRGB: Rasterize the source RGB image and return the resulting Raster image 
displayed image with an appropriate color table. The dither parameter controls dithering.
********************************************************************************************/
Image RasterizeRGB( const Image &source, bool dither );


/********************************************************************************************
 RawCopyImage: Copies the src image to the dst image ignoring data types. The data type 
sizes of the two images must be the same.
********************************************************************************************/
void RawCopyImage( const Image &src, const Image &dst );


/********************************************************************************************
 ReadFile: Read count bytes from the file, returning them as a string.
********************************************************************************************/
String ReadFile( DM_FileReference file, long count );


/********************************************************************************************
 ReadFileLine: Read a line of text from the file, storing it into the string variable. 
Return 1 if successful and 0 otherwise.
********************************************************************************************/
bool ReadFileLine( DM_FileReference file, String &string );


/********************************************************************************************
 ReadRawStream: Read length bytes from rawStream and store it into the memory pointed to 
by data.
********************************************************************************************/
void ReadRawStream( long rawStream, long data, long length );


/********************************************************************************************
 RealFFT: Creates a new complex 8-byte image from the FFT of the real image source.
********************************************************************************************/
Image RealFFT( const Image &source );


/********************************************************************************************
 RealIFFT: Creates a new real image from the inverse FFT of the complex 8-byte image 
source.
********************************************************************************************/
Image RealIFFT( const Image &source );


/********************************************************************************************
 RealImage: Creates a 3D real image of size [d0,d1,d2] with the given title. The bytes 
parameter can be 4 or 8 for single and double precision floating point numbers.
********************************************************************************************/
Image RealImage( const char *title, long bytes, long d0, long d1, long d2 );


/********************************************************************************************
 RealImage: Creates a 2D real image of size [d0,d1] with the given title. The bytes 
parameter can be 4 or 8 for single and double precision floating point numbers.
********************************************************************************************/
Image RealImage( const char *title, long bytes, long d0, long d1 );


/********************************************************************************************
 RealImage: Creates a 1D real image of size [d0] with the given title. The bytes 
parameter can be 4 or 8 for single and double precision floating point numbers.
********************************************************************************************/
Image RealImage( const char *title, long bytes, long d0 );


/********************************************************************************************
 Reduce: Reduces the image by 2X.
********************************************************************************************/
void Reduce( const Image &argument_1 );


/********************************************************************************************
 ReducedFFT: Creates a new packed complex image from the FFT of the real image source 
after reducing the source by a factor of 2.
********************************************************************************************/
Image ReducedFFT( const Image &source );


/********************************************************************************************
 RegisterCustomMenu: Register a custom menu. See the SDK documentation for more 
information.
********************************************************************************************/
long RegisterCustomMenu( long menuHandler );


/********************************************************************************************
 RegisterCustomTool: Add the tool to the custom tool list. See the SDK documentation for 
more information.
********************************************************************************************/
long RegisterCustomTool( const char *icon, long toolInstance );


/********************************************************************************************
 RegisterMenuAdjustment: Unregister a menu name adjustment. See the SDK documentation for 
more information.
********************************************************************************************/
void RegisterMenuAdjustment( const char *menuName, const char *adjustedMenuName );

/********************************************************************************************
 RegisterObjectListener: Add object listener to OM object. See the SDK documentation for 
more information.
********************************************************************************************/
long RegisterObjectListener( long object, long proc, long refCon );


/********************************************************************************************
 RegisterScriptPalette: 
********************************************************************************************/
void RegisterScriptPalette( const ScriptObject &argument_1, const char *type, const char 
*name );


/********************************************************************************************
 RegisterSystemIdle: Register a system idle procedure.
********************************************************************************************/
void RegisterSystemIdle( SystemIdleProc SystemIdleProc );


/********************************************************************************************
 ReleaseDataPtr: Releases the pointer to the image data acquired using the GetDataPtr() 
function.
********************************************************************************************/
void ReleaseDataPtr( const Image &argument_1 );


/********************************************************************************************
 ReleaseSemaphore: Release a semaphore. Used only with background processing.
********************************************************************************************/
void ReleaseSemaphore( long argument_1 );


/********************************************************************************************
 RemoveCustomTool: Remove the tool to the custom tool list. See the SDK documentation for 
more information.
********************************************************************************************/
void RemoveCustomTool( long doStateProc );


/********************************************************************************************
 RemoveFunction: Removes the user defined function with an entry point matching fnPtr.
********************************************************************************************/
void RemoveFunction( void *fnPtr );


/********************************************************************************************
 RemovePathFromCopyToImageList: Removes 'path' from the copy to image list.
********************************************************************************************/
void RemovePathFromCopyToImageList( const char *path );


/********************************************************************************************
 RemoveScriptFromMenu: Removes the given menu command from the menu. The commandName 
indicates the string by which this script is known to the application. The menuName and 
optionalSubMenuName parameters specify the menu. 
********************************************************************************************/
void RemoveScriptFromMenu( const char *commandName, const char *menuName, const char 
*optionalSubMenuName );


/********************************************************************************************
 ResetContrastLimitsAlways: Reset the contrast limits of the image from the survey 
information.
********************************************************************************************/
void ResetContrastLimitsAlways( const Image &argument_1 );


/********************************************************************************************
 Result: Output the string to the results window.
********************************************************************************************/
void Result( const String &argument_1 );


/********************************************************************************************
 RGBImage: Creates a 3D RGB image of size [d0,d1,d2] with the given title. The bytes 
parameter must be 4.
********************************************************************************************/
Image RGBImage( const char *title, long bytes, long d0, long d1, long d2 );


/********************************************************************************************
 RGBImage: Creates a 2D RGB image of size [d0,d1] with the given title. The bytes 
parameter must be 4.
********************************************************************************************/
Image RGBImage( const char *title, long bytes, long d0, long d1 );


/********************************************************************************************
 RGBImage: Creates a 1D RGB image of size [d0] with the given title. The bytes parameter 
must be 4.
********************************************************************************************/
Image RGBImage( const char *title, long bytes, long d0 );


/********************************************************************************************
 ROIAddToMask: Add the region of interest to the image within the bounds of the specified 
rectangle.
********************************************************************************************/
void ROIAddToMask( const ROI &roi, const Image &mask, float top, float left, float bottom,
 float right );


/********************************************************************************************
 ROIAddVertex: Add a vertex with the given coordinates to the region of interest.
********************************************************************************************/
void ROIAddVertex( const ROI &roi, float x, float y );


/********************************************************************************************
 ROIClearVertices: Remove all vertices from the region of interest.
********************************************************************************************/
void ROIClearVertices( const ROI &roi );


/********************************************************************************************
 ROIClone: Returns a clone of the roi.
********************************************************************************************/
ROI ROIClone( const ROI &roi );


/********************************************************************************************
 ROIContainsPoint: Returns whether the region of interest encloses the given point.
********************************************************************************************/
bool ROIContainsPoint( const ROI &roi, float x, float y );


/********************************************************************************************
 ROICountVertices: Return the number of vertices comprising the region of interest.
********************************************************************************************/
long ROICountVertices( const ROI &roi );


/********************************************************************************************
 ROIDeleteVertex: Delete the given vertex from the region of interest.
********************************************************************************************/
void ROIDeleteVertex( const ROI &roi, long index );


/********************************************************************************************
 ROIGetColor: Stores the color of the region of interest into the variables. Each number 
will be in the range of 0 to 1.
********************************************************************************************/
void ROIGetColor( const ROI &roi, float *r, float *g, float *b );


/********************************************************************************************
 ROIGetDeletable: Return whether the region of interest is deletable or not.
********************************************************************************************/
bool ROIGetDeletable( const ROI &roi );


/********************************************************************************************
 ROIGetID: Return the ID for the region of interest.
********************************************************************************************/
long ROIGetID( const ROI &roi );


/********************************************************************************************
 ROIGetLabel: Return the label of the region of interest.
********************************************************************************************/
String ROIGetLabel( const ROI &roi );


/********************************************************************************************
 ROIGetLine: Fill in the start and end points of the line represented by the region of 
interest.
********************************************************************************************/
void ROIGetLine( const ROI &roi, float *sx, float *sy, float *ex, float *ey );


/********************************************************************************************
 ROIGetMoveable: Return whether the region of interest is moveable or not.
********************************************************************************************/
bool ROIGetMoveable( const ROI &roi );


/********************************************************************************************
 ROIGetName: Return the name of the region of interest.
********************************************************************************************/
String ROIGetName( const ROI &roi );


/********************************************************************************************
 ROIGetPoint: Return the coordinates of the point represented by this region of interest.
********************************************************************************************/
void ROIGetPoint( const ROI &roi, float *x, float *y );


/********************************************************************************************
 ROIGetRange: Fills in the start and end columns of the range represented by the region 
of interest.
********************************************************************************************/
void ROIGetRange( const ROI &roi, float *start, float *end );


/********************************************************************************************
 ROIGetRectangle: Fill in the coordinates of the rectangle represented by the region of 
interest.
********************************************************************************************/
void ROIGetRectangle( const ROI &roi, float *top, float *left, float *bottom, float 
*right );


/********************************************************************************************
 ROIGetResizable: Return whether the region of interest is resizable or not.
********************************************************************************************/
bool ROIGetResizable( const ROI &roi );


/********************************************************************************************
 ROIGetVertex: Return the coordinates of the given vertex of the region of interest.
********************************************************************************************/
void ROIGetVertex( const ROI &roi, long index, float *x, float *y );


/********************************************************************************************
 ROIGetVolatile: Return whether the region of interest is volatile or not.
********************************************************************************************/
bool ROIGetVolatile( const ROI &roi );


/********************************************************************************************
 ROIInsertVertex: Insert a vertex with the given coordinates before the indicated vertex 
of the region of interest.
********************************************************************************************/
void ROIInsertVertex( const ROI &roi, long before, float x, float y );


/********************************************************************************************
 ROIIsClosed: Returns whether the region of interest is a closed loop or not.
********************************************************************************************/
bool ROIIsClosed( const ROI &roi );


/********************************************************************************************
 ROIIsLine: Return whether the region of interest is a line.
********************************************************************************************/
bool ROIIsLine( const ROI &roi );


/********************************************************************************************
 ROIIsPoint: Return whether the region of interest is a point.
********************************************************************************************/
bool ROIIsPoint( const ROI &roi );


/********************************************************************************************
 ROIIsRange: Returns whether the region of interest is a range.
********************************************************************************************/
bool ROIIsRange( const ROI &roi );


/********************************************************************************************
 ROIIsRectangle: Return whether the region of interest is a rectangle.
********************************************************************************************/
bool ROIIsRectangle( const ROI &roi );


/********************************************************************************************
 ROIIsValid: Returns 'true' if the region of interest is a valid object.
********************************************************************************************/
bool ROIIsValid( const ROI &roi );


/********************************************************************************************
 ROISetColor: Set the color of the region of interest. Each number should be in the range 
of 0 to 1.
********************************************************************************************/
void ROISetColor( const ROI &roi, float r, float g, float b );


/********************************************************************************************
 ROISetDeletable: Sets whether the region of interest should be deletable or not.
********************************************************************************************/
void ROISetDeletable( const ROI &roi, bool deletable );


/********************************************************************************************
 ROISetIsClosed: Sets whether the region of interest is a closed loop or not (that is the 
last vertex connects to the first).
********************************************************************************************/
void ROISetIsClosed( const ROI &roi, bool is_closed );


/********************************************************************************************
 ROISetLabel: Set the label on the region of interest.
********************************************************************************************/
void ROISetLabel( const ROI &roi, const String &name );


/********************************************************************************************
 ROISetLine: Set the region of interest to a line with the given start and end 
coordinates.
********************************************************************************************/
void ROISetLine( const ROI &roi, float sx, float sy, float ex, float ey );


/********************************************************************************************
 ROISetMoveable: Sets whether the region of interest should be moveable or not.
********************************************************************************************/
void ROISetMoveable( const ROI &roi, bool moveable );


/********************************************************************************************
 ROISetName: Set the name of the region of interest.
********************************************************************************************/
void ROISetName( const ROI &roi, const String &name );


/********************************************************************************************
 ROISetPoint: Set the region of interest to a point with the given coordinate.
********************************************************************************************/
void ROISetPoint( const ROI &roi, float x, float y );


/********************************************************************************************
 ROISetRange: Sets the region of interest to a range with the given start and end columns.
********************************************************************************************/
void ROISetRange( const ROI &roi, float start, float end );


/********************************************************************************************
 ROISetRectangle: Set the region of interest to a rectangle with the given coordinates.
********************************************************************************************/
void ROISetRectangle( const ROI &roi, float top, float left, float bottom, float right );


/********************************************************************************************
 ROISetRegionToComplexValue: Sets the area in 'mask' corresponding to the region to the 
value 'value'.
********************************************************************************************/
void ROISetRegionToComplexValue( const ROI &roi, const Image &mask, const 
complex128_t &value, float top, float left, float bottom, float right );


/********************************************************************************************
 ROISetRegionToRGBValue: Sets the area in 'mask' corresponding to the region to the value 
'value'.
********************************************************************************************/
void ROISetRegionToRGBValue( const ROI &roi, const Image &mask, rgba_uint8_os_t value, float top, 
float left, float bottom, float right );


/********************************************************************************************
 ROISetRegionToValue: Sets the area in 'mask' corresponding to the region to the value 
'value'.
********************************************************************************************/
void ROISetRegionToValue( const ROI &roi, const Image &mask, double value, float top, 
float left, float bottom, float right );


/********************************************************************************************
 ROISetResizable: Sets whether the region of interest should be resizable or not.
********************************************************************************************/
void ROISetResizable( const ROI &roi, bool resizable );


/********************************************************************************************
 ROISetVertex: Set the coordinates of the given vertex of the region of interest.
********************************************************************************************/
void ROISetVertex( const ROI &roi, long index, float x, float y );


/********************************************************************************************
 ROISetVolatile: Set whether the region of interest is volatile or not.
********************************************************************************************/
void ROISetVolatile( const ROI &roi, bool is_volatile );


/********************************************************************************************
 Rotate: Creates a new real image by rotating the source image counterclockwise by 
radians.
********************************************************************************************/
Image Rotate( const Image &source, float radians );


/********************************************************************************************
 RotateLeft: Rotates the image to the left by 90¡.
********************************************************************************************/
void RotateLeft( const Image &argument_1 );


/********************************************************************************************
 RotateRight: Rotates the image to the right by 90¡.
********************************************************************************************/
void RotateRight( const Image &argument_1 );


/********************************************************************************************
 Save: Save the image under the it's current filename.
********************************************************************************************/
void Save( const Image &argument_1 );


/********************************************************************************************
 SaveAsDialog: Puts up the SaveAs dialog with the given prompt and default file name, and 
then stores the chosen path for the saved file into the saveName variable. Returns 1 for 
OK and 0 for Cancel.
********************************************************************************************/
bool SaveAsDialog( const char *prompt, const char *defaultName, char *saveName );


/********************************************************************************************
 SaveAsGatan: Save the image to the fileName in Gatan 3.0 file format.
********************************************************************************************/
void SaveAsGatan( const Image &argument_1, const char *fileName );


/********************************************************************************************
 SaveAsGIF: Save the image to the fileName in GIF file format. The DM Import/Export 
Plug-in must be installed in order for this function to work.
********************************************************************************************/
void SaveAsGIF( const Image &argument_1, const char *fileName );


/********************************************************************************************
 SaveAsPCX: Save the image to the fileName in PCX file format. The DM Import/Export 
Plug-in must be installed in order for this function to work.
********************************************************************************************/
void SaveAsPCX( const Image &argument_1, const char *fileName );


/********************************************************************************************
 SaveAsPICT: Save the image to the fileName in PICT file format. The DM Import/Export 
Plug-in must be installed in order for this function to work.
********************************************************************************************/
void SaveAsPICT( const Image &argument_1, const char *fileName );


/********************************************************************************************
 SaveAsRawData: Save the image to the fileName in raw file format.
********************************************************************************************/
void SaveAsRawData( const Image &argument_1, const char *fileName );


/********************************************************************************************
 SaveAsSmallHeader: Save the image to the fileName in Gatan small header file format.
********************************************************************************************/
void SaveAsSmallHeader( const Image &argument_1, const char *fileName );


/********************************************************************************************
 SaveAsText: Save the image to the fileName in text file format.
********************************************************************************************/
void SaveAsText( const Image &argument_1, const char *fileName );


/********************************************************************************************
 SaveAsTIFF: Save the image to the fileName in TIFF file format. The DM Import/Export 
Plug-in must be installed in order for this function to work.
********************************************************************************************/
void SaveAsTIFF( const Image &argument_1, const char *fileName );


/********************************************************************************************
 SaveImage: Save the image to the fileName in it's current file format.
********************************************************************************************/
void SaveImage( const Image &argument_1, const char *fileName );


/********************************************************************************************
 ScrapClear: Clear the pasted image (if there is one) from the image.
********************************************************************************************/
void ScrapClear( const Image &argument_1 );


/********************************************************************************************
 ScrapCopy: Copy the selected portion of the image to the scrap.
********************************************************************************************/
void ScrapCopy( const Image &argument_1 );


/********************************************************************************************
 ScrapGetLocation: Store the pasted image location (in image coordinates) into the top 
and left variables.
********************************************************************************************/
void ScrapGetLocation( const Image &argument_1, long *top, long *left );


/********************************************************************************************
 ScrapGetSize: Store the pasted image size (in image coordinates) into the width and 
height variables.
********************************************************************************************/
void ScrapGetSize( const Image &argument_1, long *width, long *height );


/********************************************************************************************
 ScrapMerge: Merge the pasted image (if there is one) with the image.
********************************************************************************************/
void ScrapMerge( const Image &argument_1 );


/********************************************************************************************
 ScrapPaste: Paste the scrap into the image.
********************************************************************************************/
void ScrapPaste( const Image &argument_1 );


/********************************************************************************************
 ScrapPasteNew: Paste the scrap into a new image.
********************************************************************************************/
void ScrapPasteNew( );


/********************************************************************************************
 ScrapSetLocation: Set the location of the pasted image (if there is one) to [top,left].
********************************************************************************************/
void ScrapSetLocation( const Image &argument_1, long top, long left );


/********************************************************************************************
 ScreenGetBounds: Gets the bounds of the 'index'th screen.
********************************************************************************************/
void ScreenGetBounds( long index, long *t, long *l, long *b, long *r );


/********************************************************************************************
 ScreenGetWorkArea: Gets the bounds of the 'index'th screen.
********************************************************************************************/
void ScreenGetWorkArea( long index, long *t, long *l, long *b, long *r );


/********************************************************************************************
 ScriptInterfaceGenerateStubs: Generates C++ stubs for the interface.
********************************************************************************************/
void ScriptInterfaceGenerateStubs( const char *interface_name, String &str_h, String 
&str_cp );


/********************************************************************************************
 ScriptObjectGetClassToken: Gets the token in 'scriptObject' corresponding to the class 
'class_name'.
********************************************************************************************/
ulong ScriptObjectGetClassToken( const ScriptObject &scriptObject, const String &class_name 
);


/********************************************************************************************
 ScriptObjectGetID: Returns a unique ID for this object. The object can be recovered by 
using GetScriptObjectFromID function.
********************************************************************************************/
long ScriptObjectGetID( const ScriptObject &scriptObject );


/********************************************************************************************
 ScriptObjectIsValid: Returns true if 'scriptObject' references a valid object.
********************************************************************************************/
bool ScriptObjectIsValid( const ScriptObject &scriptObject );


/********************************************************************************************
 ScriptObjectLookupMethod: Returns the method of this object corresponding to the 
abstract method 'meth_abs' and class 'class_name'.
********************************************************************************************/
Function ScriptObjectLookupMethod( const ScriptObject &scriptObject, const Function 
&meth_abs, const char *class_name );


/********************************************************************************************
 ScriptObjectLookupMethod: Returns the specific method of this object corresponding to 
the abstract method 'meth_abs'.
********************************************************************************************/
Function ScriptObjectLookupMethod( const ScriptObject &scriptObject, const Function 
&meth_abs );


/********************************************************************************************
 ScriptWindowExecute: Executes the script in the script window.
********************************************************************************************/
void ScriptWindowExecute( const Window &window );


/********************************************************************************************
 SelectImage: Bring the image's image document window to the front.
********************************************************************************************/
void SelectImage( const Image &argument_1 );


/********************************************************************************************
 SetColorMode: Set the color mode of the image. The possible values for mode are 
1=greyscale, 3=rainbow, 4=temperature.
********************************************************************************************/
void SetColorMode( const Image &argument_1, short mode );


/********************************************************************************************
 SetComplexMode: Set the complex-to-real mode of the image. The possible value for mode 
are 1=real, 2=imaginary, 3=modulus, 4=log of modulus, 5=phase.
********************************************************************************************/
void SetComplexMode( const Image &argument_1, short mode );


/********************************************************************************************
 SetContrastMode: Set the constrast mode of the image. The possible value for mode are 
1=linear, 2=equalized, 3=contoured, 4=custom.
********************************************************************************************/
void SetContrastMode( const Image &argument_1, short mode );


/********************************************************************************************
 SetCustomCLUT: Set the CLUT for the image to clutImage. clutImage must be a 256x1 RGB 
image.
********************************************************************************************/
void SetCustomCLUT( const Image &argument_1, const Image &clutImage );


/********************************************************************************************
 SetDisplayType: Set the display type of the image. Possible displayType values are 
-1=best, 1=raster image, 2=surface plot, 3=RGB, 4=line plot, 5=spreadsheet.
********************************************************************************************/
void SetDisplayType( const Image &argument_1, long displayType );


/********************************************************************************************
 SetDoCreateCustomIcon: Open the image with the filename. Returns the opened image.
********************************************************************************************/
void SetDoCreateCustomIcon( const Image &image, bool doCreateCustomIcon );


/********************************************************************************************
 SetDoSavePreview: Sets whether to save a preview along with the saved file.
********************************************************************************************/
void SetDoSavePreview( const Image &image, bool doSavePreview );


/********************************************************************************************
 SetEstimatedMinMax: Set the estimated minimum and maximum of the image to min, max. This 
can be used if survey is turned off.
********************************************************************************************/
void SetEstimatedMinMax( const Image &argument_1, float min, float max );


/********************************************************************************************
 SetImagePositionWithinWindow: Set top-left position of the image to [x,y] within the 
image document.
********************************************************************************************/
void SetImagePositionWithinWindow( const Image &argument_1, long x, long y );


/********************************************************************************************
 SetInversionMode: Set the contrast of the image to be inverted or not inverted.
********************************************************************************************/
void SetInversionMode( const Image &argument_1, bool inverted );


/********************************************************************************************
 SetLimits: Set the lowest and highest displayed pixel values for the image. Everything 
below low will be the 'black' color and every above high will be the 'white' color. The 
black and white colors may not actually be black and white if the color table is not 
greyscale.
********************************************************************************************/
void SetLimits( const Image &argument_1, float low, float high );


/********************************************************************************************
 SetMinContrast: Set the minimum amount of contrast for the image to minContrast.
********************************************************************************************/
void SetMinContrast( const Image &argument_1, float minContrast );


/********************************************************************************************
 SetName: Sets the name of the image's image document to name.
********************************************************************************************/
void SetName( const Image &argument_1, const char *name );


/********************************************************************************************
 SetOrigin: Set the origin of the image coordinates to [x,y] which are in pixel units.
********************************************************************************************/
void SetOrigin( const Image &argument_1, float x, float y );


/********************************************************************************************
 SetPixel: Sets the pixel in the image at [x,y] to value.
********************************************************************************************/
void SetPixel( const Image &argument_1, long x, long y, float value );


/********************************************************************************************
 SetRawStreamPos: Set the current position in rawStream to offset using the mode.
********************************************************************************************/
void SetRawStreamPos( long rawStream, long mode, long offset );


/********************************************************************************************
 SetScale: Set the scale of the image to [x,y].
********************************************************************************************/
void SetScale( const Image &argument_1, float x, float y );


/********************************************************************************************
 SetSelection: Sets the selection of the image to [top,left,bottom,right].
********************************************************************************************/
void SetSelection( const Image &argument_1, long top, long left, long bottom, long right 
);


/********************************************************************************************
 SetSurvey: Turn surveying on or off for the image.
********************************************************************************************/
void SetSurvey( const Image &argument_1, bool surveyOnOff );


/********************************************************************************************
 SetSurveyTechnique: Set the survey technique for the image to mode. Mode can be 
0=cross-wire, 1=whole image, 2=sparse.
********************************************************************************************/
void SetSurveyTechnique( const Image &argument_1, short mode );


/********************************************************************************************
 SetToZero: Set the image to zero.
********************************************************************************************/
void SetToZero( const Image &argument_1 );


/********************************************************************************************
 SetUnitString: Set the units of the image to unitString.
********************************************************************************************/
void SetUnitString( const Image &argument_1, const char *unitString );


/********************************************************************************************
 SetUsesToZero: Mark the image as deletable at scope exit.
********************************************************************************************/
void SetUsesToZero( const Image &argument_1 );


/********************************************************************************************
 SetWindowBounds: Set the image's image document window bounds to 
(left,top),(right,bottom).
********************************************************************************************/
void SetWindowBounds( const Image &argument_1, long top, long left, long bottom, long 
right );


/********************************************************************************************
 SetWindowPosition: Set the image's image document window position to [xPos, yPos]. Only 
valid for images that are already shown in a window.
********************************************************************************************/
void SetWindowPosition( const Image &argument_1, long xPos, long yPos );


/********************************************************************************************
 SetWindowSize: Set the image's image document window size to [width, height].
********************************************************************************************/
void SetWindowSize( const Image &argument_1, long width, long height );


/********************************************************************************************
 SetZoom: Set the zoom of the image display.
********************************************************************************************/
void SetZoom( const Image &argument_1, float zoom );


/********************************************************************************************
 ShiftCenter: Shifts each dimension of an image by half.  For two dimensional images it 
will swap quadrants.
********************************************************************************************/
void ShiftCenter( const Image &image );


/********************************************************************************************
 ShiftDown: Returns 1 if the shift key is down and 0 otherwise.
********************************************************************************************/
bool ShiftDown( );


/********************************************************************************************
 ShowAlert: Puts up an alert with the given prompt and style.
********************************************************************************************/
void ShowAlert( const char *prompt, long alertStyle );


/********************************************************************************************
 Sleep: Puts the current thread to sleep for the given number of seconds (resolution may 
vary by platform).
********************************************************************************************/
void Sleep( float seconds );


/********************************************************************************************
 SpaceDown: Returns 1 if the space key is down and 0 otherwise.
********************************************************************************************/
bool SpaceDown( );


/********************************************************************************************
 StopAcquisitionDaemon: Stop all acquisition daemons associated with the image.
********************************************************************************************/
void StopAcquisitionDaemon( const Image &argument_1 );


/********************************************************************************************
 StopAllAcquisitionDaemons: Stop all acquisition daemons with any image within the 
application.
********************************************************************************************/
void StopAllAcquisitionDaemons( );


/********************************************************************************************
 StringAppend: Appends string s2 to s1, converting its encoding to that of s1 if 
necessary.
********************************************************************************************/
String StringAppend( String &s1, const String &s2 );


/********************************************************************************************
 StringAppend: Appends character ch to s1, converting its encoding to that of s1 if 
necessary.
********************************************************************************************/
String StringAppend( String &s1, ulong ch, ulong encoding_id );


/********************************************************************************************
 StringCompare: Compares strings 's1' and 's2', returning -1,0, or 1 if s1 is less, 
equal, or greater than s2.
********************************************************************************************/
long StringCompare( const String &s1, const String &s2 );


/********************************************************************************************
 StringConvertToEncoding: Converts 's1' to the encoding specified by 'encoding_id'.
********************************************************************************************/
String StringConvertToEncoding( const String &s1, ulong encoding_id );


/********************************************************************************************
 StringIsValid: Returns true if 'str' is a valid object.
********************************************************************************************/
bool StringIsValid( const String &str );


/********************************************************************************************
 SurfacePlotImageDisplayGetCubeAxes: Gets the points describing the surface plot cube.
********************************************************************************************/
void SurfacePlotImageDisplayGetCubeAxes( const SurfacePlotImageDisplay &spid, float 
*x_axis_x, float *x_axis_y, float *y_axis_x, float *y_axis_y, float *z_axis );


/********************************************************************************************
 SurfacePlotImageDisplayGetCubePoint: Gets the child coordinates of the cube point 
indicated by 'which_point'
********************************************************************************************/
void SurfacePlotImageDisplayGetCubePoint( const SurfacePlotImageDisplay &spid, long 
which_point, float *x, float *y );


/********************************************************************************************
 SurfacePlotImageDisplayIsShadingOn: Determines whether shading is on or off.
********************************************************************************************/
bool SurfacePlotImageDisplayIsShadingOn( const SurfacePlotImageDisplay &spid );


/********************************************************************************************
 SurfacePlotImageDisplaySetCubeAxes: Sets the points describing the surface plot cube.
********************************************************************************************/
void SurfacePlotImageDisplaySetCubeAxes( const SurfacePlotImageDisplay &spid, float 
x_axis_x, float x_axis_y, float y_axis_x, float y_axis_y, float z_axis );


/********************************************************************************************
 SurfacePlotImageDisplaySetShadingOn: Sets whether shading is on or off.
********************************************************************************************/
void SurfacePlotImageDisplaySetShadingOn( const SurfacePlotImageDisplay &spid, bool on );


/********************************************************************************************
 SVDecomposition: Return the image resulting from a SV decomposition on images a,b.
********************************************************************************************/
Image SVDecomposition( const Image &a, const Image &b );


/********************************************************************************************
 SVDFit: Return the image resulting from a SVD fit on images a,b with the given tolerance.
********************************************************************************************/
Image SVDFit( const Image &a, const Image &b, float tolerance );


/********************************************************************************************
 SwapByteOrder: Swaps the byte order for each long word in the image. ABCD become DCBA.
********************************************************************************************/
void SwapByteOrder( const Image &argument_1 );


/********************************************************************************************
 SwapWordOrder: Swaps the byte order for each short word in the image. ABCD become BADC.
********************************************************************************************/
void SwapWordOrder( const Image &argument_1 );


/********************************************************************************************
 TagGroupAddLabeledTagGroup: Adds 'newGroup' to 'tagGroup' at the label 'label'.
********************************************************************************************/
TagGroup TagGroupAddLabeledTagGroup( const TagGroup &tagGroup, const char *label, const 
TagGroup &newGroup );


/********************************************************************************************
 TagGroupAddTagGroupAfter: Adds 'newGroup' to 'tagList' after index 'ref_index'.
********************************************************************************************/
TagGroup TagGroupAddTagGroupAfter( const TagGroup &tagList, long ref_index, const 
TagGroup &newGroup );


/********************************************************************************************
 TagGroupAddTagGroupAtBeginning: Adds 'newGroup' to the beginning of 'tagList'.
********************************************************************************************/
TagGroup TagGroupAddTagGroupAtBeginning( const TagGroup &tagList, const TagGroup 
&newGroup );


/********************************************************************************************
 TagGroupAddTagGroupAtEnd: Adds 'newGroup' to the end of 'tagList'.
********************************************************************************************/
TagGroup TagGroupAddTagGroupAtEnd( const TagGroup &tagList, const TagGroup &newGroup );


/********************************************************************************************
 TagGroupAddTagGroupBefore: Adds 'newGroup' to 'tagList' before index 'ref_index'.
********************************************************************************************/
TagGroup TagGroupAddTagGroupBefore( const TagGroup &tagList, long ref_index, const 
TagGroup &newGroup );


/********************************************************************************************
 TagGroupClone: Returns an identical copy of 'tagGroup' and its sub-tags.
********************************************************************************************/
TagGroup TagGroupClone( const TagGroup &tagGroup );


/********************************************************************************************
 TagGroupCopyTag: Copies the 'srcIndex'th tag in 'srcGroup' to 'tagGroup'.
********************************************************************************************/
long TagGroupCopyTag( const TagGroup &tagGroup, const TagGroup &srcGroup, long srcIndex );


/********************************************************************************************
 TagGroupCopyTagsFrom: Copies tags in 'srcGroup' to 'tagGroup'.
********************************************************************************************/
void TagGroupCopyTagsFrom( const TagGroup &tagGroup, const TagGroup &srcGroup );


/********************************************************************************************
 TagGroupCopyTagToIndex: Copies data in the 'srcIndex'th tag in 'srcGroup' to the 
'dstIndex'th tag in 'tagGroup'.
********************************************************************************************/
void TagGroupCopyTagToIndex( const TagGroup &tagGroup, long dstIndex, const TagGroup 
&srcGroup, long srcIndex );


/********************************************************************************************
 TagGroupCountTags: Returns the number of sub-tags in this tag group.
********************************************************************************************/
long TagGroupCountTags( const TagGroup &tagGroup );


/********************************************************************************************
 TagGroupCreateGroupTagAfter: Creates a new tag group after 'ref_index' in 'tagList'.
********************************************************************************************/
TagGroup TagGroupCreateGroupTagAfter( const TagGroup &tagList, long ref_index );


/********************************************************************************************
 TagGroupCreateGroupTagAtBeginning: Creates a new tag group at the beginning of 'tagList'.
********************************************************************************************/
TagGroup TagGroupCreateGroupTagAtBeginning( const TagGroup &tagList );


/********************************************************************************************
 TagGroupCreateGroupTagAtEnd: Creates a new tag group at the end of 'tagList'.
********************************************************************************************/
TagGroup TagGroupCreateGroupTagAtEnd( const TagGroup &tagList );


/********************************************************************************************
 TagGroupCreateGroupTagBefore: Creates a new tag group before 'ref_index' in 'tagList'.
********************************************************************************************/
TagGroup TagGroupCreateGroupTagBefore( const TagGroup &tagList, long ref_index );


/********************************************************************************************
 TagGroupCreateListTagAfter: Creates a new tag group after 'ref_index' in 'tagList'.
********************************************************************************************/
TagGroup TagGroupCreateListTagAfter( const TagGroup &tagList, long ref_index );


/********************************************************************************************
 TagGroupCreateListTagAtBeginning: Creates a new tag group at the beginning of 'tagList'.
********************************************************************************************/
TagGroup TagGroupCreateListTagAtBeginning( const TagGroup &tagList );


/********************************************************************************************
 TagGroupCreateListTagAtEnd: Creates a new tag group at the end of 'tagList'.
********************************************************************************************/
TagGroup TagGroupCreateListTagAtEnd( const TagGroup &tagList );


/********************************************************************************************
 TagGroupCreateListTagBefore: Creates a new tag group before 'ref_index' in 'tagList'.
********************************************************************************************/
TagGroup TagGroupCreateListTagBefore( const TagGroup &tagList, long ref_index );


/********************************************************************************************
 TagGroupCreateNewLabeledGroup: Adds a new tag group at label 'label' and returns the new 
group.
********************************************************************************************/
TagGroup TagGroupCreateNewLabeledGroup( const TagGroup &tagGroup, const char *label );


/********************************************************************************************
 TagGroupCreateNewLabeledList: Adds a new tag list at label 'label' and returns the new 
group.
********************************************************************************************/
TagGroup TagGroupCreateNewLabeledList( const TagGroup &tagGroup, const char *label );


/********************************************************************************************
 TagGroupCreateNewLabeledTag: Creates a new labeled tag and returns its index.
********************************************************************************************/
long TagGroupCreateNewLabeledTag( const TagGroup &tagGroup, const char *label );


/********************************************************************************************
 TagGroupCreateNewTagAfter: Creates a new tag after 'ref_index' in 'tagList'.
********************************************************************************************/
long TagGroupCreateNewTagAfter( const TagGroup &tagList, long ref_index );


/********************************************************************************************
 TagGroupCreateNewTagAtBeginning: Creates a new tag at the beginning of 'tagList'.
********************************************************************************************/
long TagGroupCreateNewTagAtBeginning( const TagGroup &tagList );


/********************************************************************************************
 TagGroupCreateNewTagAtEnd: Creates a new tag at the end of 'tagList'.
********************************************************************************************/
long TagGroupCreateNewTagAtEnd( const TagGroup &tagList );


/********************************************************************************************
 TagGroupCreateNewTagBefore: Creates a new tag before 'ref_index' in 'tagList'.
********************************************************************************************/
long TagGroupCreateNewTagBefore( const TagGroup &tagList, long ref_index );


/********************************************************************************************
 TagGroupDeleteAllTags: Deletes all the tags in 'tagGroup'.
********************************************************************************************/
void TagGroupDeleteAllTags( const TagGroup &tagGroup );


/********************************************************************************************
 TagGroupDeleteTagWithIndex: Deletes the tag at index 'index'.
********************************************************************************************/
void TagGroupDeleteTagWithIndex( const TagGroup &taGroup, long index );


/********************************************************************************************
 TagGroupDeleteTagWithLabel: Deletes the tag labelled by the path 'tagPath'.
********************************************************************************************/
void TagGroupDeleteTagWithLabel( const TagGroup &tagGroup, const char *tagPath );


/********************************************************************************************
 TagGroupDoesTagExist: Finds the tag group and index corresponding to the tag referenced 
by 'tagPath' in 'tagGroup'.
********************************************************************************************/
bool TagGroupDoesTagExist( const TagGroup &tagGroup, const char *tagPath );


/********************************************************************************************
 TagGroupExecuteScriptGroup: Execute a group of script functions in 'tagGroup'. The 
actual scripts executed will be formed by sprintf'ing into the 'form' parameter.  The 
form parameter should contain exactly one '%s' into which the function name will be 
inserted.
********************************************************************************************/
void TagGroupExecuteScriptGroup( const TagGroup &tagGroup, const char *form );


/********************************************************************************************
 TagGroupGetIndexedTagAsArray: Gets the data at 'index' in 'tagGroup' as an array of data 
in 'image'.
********************************************************************************************/
bool TagGroupGetIndexedTagAsArray( const TagGroup &tagGroup, ulong index, const Image 
&image );


/********************************************************************************************
 TagGroupGetIndexedTagAsBoolean: Gets the data at 'index' in 'tagGroup' as a boolean.
********************************************************************************************/
bool TagGroupGetIndexedTagAsBoolean( const TagGroup &tagGroup, long index, bool *val );


/********************************************************************************************
 TagGroupGetIndexedTagAsDouble: Gets the data at 'index' in 'tagGroup' as a double.
********************************************************************************************/
bool TagGroupGetIndexedTagAsDouble( const TagGroup &tagGroup, long index, double *number 
);


/********************************************************************************************
 TagGroupGetIndexedTagAsDoubleComplex: Gets the data at 'index' in 'tagGroup' as a double 
complex.
********************************************************************************************/
bool TagGroupGetIndexedTagAsDoubleComplex( const TagGroup &tagGroup, long index, 
complex128_t *c );


/********************************************************************************************
 TagGroupGetIndexedTagAsEightBitColor: Gets the data at 'index' in 'tagGroup' as an eight 
bit color.
********************************************************************************************/
bool TagGroupGetIndexedTagAsEightBitColor( const TagGroup &tagGroup, long index, rgba_uint8_os_t 
*c );


/********************************************************************************************
 TagGroupGetIndexedTagAsFloat: Gets the data at 'index' in 'tagGroup' as a float.
********************************************************************************************/
bool TagGroupGetIndexedTagAsFloat( const TagGroup &tagGroup, long index, float *number );


/********************************************************************************************
 TagGroupGetIndexedTagAsFloatComplex: Gets the data at 'index' in 'tagGroup' as a float 
complex.
********************************************************************************************/
bool TagGroupGetIndexedTagAsFloatComplex( const TagGroup &tagGroup, long index, 
complex128_t *c );


/********************************************************************************************
 TagGroupGetIndexedTagAsFloatPoint: Gets the data at 'index' in 'tagGroup' as a float 
point.
********************************************************************************************/
bool TagGroupGetIndexedTagAsFloatPoint( const TagGroup &tagGroup, long index, float *x, 
float *y );


/********************************************************************************************
 TagGroupGetIndexedTagAsFloatRect: Gets the data at 'index' in 'tagGroup' as a float rect.
********************************************************************************************/
bool TagGroupGetIndexedTagAsFloatRect( const TagGroup &tagGroup, long index, float *t, 
float *l, float *b, float *r );


/********************************************************************************************
 TagGroupGetIndexedTagAsLong: Gets the data at 'index' in 'tagGroup' as a long.
********************************************************************************************/
bool TagGroupGetIndexedTagAsLong( const TagGroup &tagGroup, long index, long *number );


/********************************************************************************************
 TagGroupGetIndexedTagAsLongPoint: Gets the data at 'index' in 'tagGroup' as a long point.
********************************************************************************************/
bool TagGroupGetIndexedTagAsLongPoint( const TagGroup &tagGroup, long index, long *x, 
long *y );


/********************************************************************************************
 TagGroupGetIndexedTagAsLongRect: Gets the data at 'index' in 'tagGroup' as a long rect.
********************************************************************************************/
bool TagGroupGetIndexedTagAsLongRect( const TagGroup &tagGroup, long index, long *t, long 
*l, long *b, long *r );


/********************************************************************************************
 TagGroupGetIndexedTagAsShort: Gets the data at 'index' in 'tagGroup' as a short.
********************************************************************************************/
bool TagGroupGetIndexedTagAsShort( const TagGroup &tagGroup, long index, short *number );


/********************************************************************************************
 TagGroupGetIndexedTagAsShortPoint: Gets the data at 'index' in 'tagGroup' as a short 
point.
********************************************************************************************/
bool TagGroupGetIndexedTagAsShortPoint( const TagGroup &tagGroup, long index, short *x, 
short *y );


/********************************************************************************************
 TagGroupGetIndexedTagAsShortRect: Gets the data at 'index' in 'tagGroup' as a short rect.
********************************************************************************************/
bool TagGroupGetIndexedTagAsShortRect( const TagGroup &tagGroup, long index, short *t, 
short *l, short *b, short *r );


/********************************************************************************************
 TagGroupGetIndexedTagAsString: Gets the data at 'index' in 'tagGroup' as a string.
********************************************************************************************/
bool TagGroupGetIndexedTagAsString( const TagGroup &tagGroup, long index, String &str );


/********************************************************************************************
 TagGroupGetIndexedTagAsTagGroup: Gets the data at 'index' in 'TagGroup' as a group.
********************************************************************************************/
bool TagGroupGetIndexedTagAsTagGroup( const TagGroup &tagGroup, long index, TagGroup 
&subGroup );


/********************************************************************************************
 TagGroupGetIndexedTagAsText: Gets the data at 'index' in 'tagGroup' as a string.
********************************************************************************************/
bool TagGroupGetIndexedTagAsText( const TagGroup &tagGroup, long index, String &str );


/********************************************************************************************
 TagGroupGetIndexedTagAsUInt16: Gets the data at 'index' in 'tagGroup' as a 16-bit 
unsigned integer.
********************************************************************************************/
bool TagGroupGetIndexedTagAsUInt16( const TagGroup &tagGroup, long index, uint16 *number 
);


/********************************************************************************************
 TagGroupGetIndexedTagAsUInt32: Gets the data at 'index' in 'tagGroup' as a 32-bit 
unsigned integer.
********************************************************************************************/
bool TagGroupGetIndexedTagAsUInt32( const TagGroup &tagGroup, long index, ulong *number );


/********************************************************************************************
 TagGroupGetOrCreateTagGroup: Gets the tag group named by 'tagPath', or creates a new 
such group and all necessary intermediate groups.
********************************************************************************************/
TagGroup TagGroupGetOrCreateTagGroup( const TagGroup &tagGroup, const char *tagPath );


/********************************************************************************************
 TagGroupGetOrCreateTagList: Gets the tag list named by 'tagPath', or creates a new such 
list and all necessary intermediate groups.
********************************************************************************************/
TagGroup TagGroupGetOrCreateTagList( const TagGroup &tagGroup, const char *tagPath );


/********************************************************************************************
 TagGroupGetSeeds: Gets a set of seeds that describe the tag group.
********************************************************************************************/
long TagGroupGetSeeds( const TagGroup &tagGroup );


/********************************************************************************************
 TagGroupGetTagAsArray: Gets the data at 'tagPath' in 'tagGroup' as an array of data in 
'image'.
********************************************************************************************/
bool TagGroupGetTagAsArray( const TagGroup &tagGroup, const char *tagPath, const Image 
&image );


/********************************************************************************************
 TagGroupGetTagAsBoolean: Gets the data at 'tagPath' in 'tagGroup' as a boolean.
********************************************************************************************/
bool TagGroupGetTagAsBoolean( const TagGroup &tagGroup, const char *tagPath, bool *val );


/********************************************************************************************
 TagGroupGetTagAsDouble: Gets the data at 'tagPath' in 'tagGroup' as a double.
********************************************************************************************/
bool TagGroupGetTagAsDouble( const TagGroup &tagGroup, const char *tagPath, double 
*number );


/********************************************************************************************
 TagGroupGetTagAsDoubleComplex: Gets the data at 'tagPath' in 'tagGroup' as a double 
complex.
********************************************************************************************/
bool TagGroupGetTagAsDoubleComplex( const TagGroup &tagGroup, const char *tagPath, 
complex128_t *c );


/********************************************************************************************
 TagGroupGetTagAsEightBitColor: Gets the data at 'tagPath' in 'tagGroup' as an eight bit 
color.
********************************************************************************************/
bool TagGroupGetTagAsEightBitColor( const TagGroup &tagGroup, const char *tagPath, rgba_uint8_os_t 
*c );


/********************************************************************************************
 TagGroupGetTagAsFloat: Gets the data at 'tagPath' in 'tagGroup' as a float.
********************************************************************************************/
bool TagGroupGetTagAsFloat( const TagGroup &tagGroup, const char *tagPath, float *number 
);


/********************************************************************************************
 TagGroupGetTagAsFloatComplex: Gets the data at 'tagPath' in 'tagGroup' as a float 
complex.
********************************************************************************************/
bool TagGroupGetTagAsFloatComplex( const TagGroup &tagGroup, const char *tagPath, 
complex128_t *c );


/********************************************************************************************
 TagGroupGetTagAsFloatPoint: Gets the data at 'tagPath' in 'tagGroup' as a short point.
********************************************************************************************/
bool TagGroupGetTagAsFloatPoint( const TagGroup &tagGroup, const char *tagPath, float *x, 
float *y );


/********************************************************************************************
 TagGroupGetTagAsFloatRect: Gets the data at 'tagPath' in 'tagGroup' as a short rect.
********************************************************************************************/
bool TagGroupGetTagAsFloatRect( const TagGroup &tagGroup, const char *tagPath, float *t, 
float *l, float *b, float *r );


/********************************************************************************************
 TagGroupGetTagAsLong: Gets the data at 'tagPath' in 'tagGroup' as a long.
********************************************************************************************/
bool TagGroupGetTagAsLong( const TagGroup &tagGroup, const char *tagPath, long *number );


/********************************************************************************************
 TagGroupGetTagAsLongPoint: Gets the data at 'tagPath' in 'tagGroup' as a long point.
********************************************************************************************/
bool TagGroupGetTagAsLongPoint( const TagGroup &tagGroup, const char *tagPath, long *x, 
long *y );


/********************************************************************************************
 TagGroupGetTagAsLongRect: Gets the data at 'tagPath' in 'tagGroup' as a long rect.
********************************************************************************************/
bool TagGroupGetTagAsLongRect( const TagGroup &tagGroup, const char *tagPath, long *t, 
long *l, long *b, long *r );


/********************************************************************************************
 TagGroupGetTagAsRGBUInt16: Gets the data at 'index' in 'tagGroup' as a 16-bit rgb value.
********************************************************************************************/
bool TagGroupGetTagAsRGBUInt16( const TagGroup &tagGroup, long index, uint16 *r, uint16 
*g, uint16 *b );


/********************************************************************************************
 TagGroupGetTagAsRGBUInt16: Gets the data at 'tagPath' in 'tagGroup' as a 16-bit rgb 
value.
********************************************************************************************/
bool TagGroupGetTagAsRGBUInt16( const TagGroup &tagGroup, const char *tagPath, uint16 *r, 
uint16 *g, uint16 *b );


/********************************************************************************************
 TagGroupGetTagAsShort: Gets the data at 'tagPath' in 'tagGroup' as a short.
********************************************************************************************/
bool TagGroupGetTagAsShort( const TagGroup &tagGroup, const char *tagPath, short *number 
);


/********************************************************************************************
 TagGroupGetTagAsShortPoint: Gets the data at 'tagPath' in 'tagGroup' as a short point.
********************************************************************************************/
bool TagGroupGetTagAsShortPoint( const TagGroup &tagGroup, const char *tagPath, short *x, 
short *y );


/********************************************************************************************
 TagGroupGetTagAsShortRect: Gets the data at 'tagPath' in 'tagGroup' as a short rect.
********************************************************************************************/
bool TagGroupGetTagAsShortRect( const TagGroup &tagGroup, const char *tagPath, short *t, 
short *l, short *b, short *r );


/********************************************************************************************
 TagGroupGetTagAsString: Gets the data at 'tagPath' in 'tagGroup' as a string.
********************************************************************************************/
bool TagGroupGetTagAsString( const TagGroup &tagGroup, const char *tagPath, String &str );


/********************************************************************************************
 TagGroupGetTagAsTagGroup: Gets the data at 'tagPath' in 'TagGroup' as a group.
********************************************************************************************/
bool TagGroupGetTagAsTagGroup( const TagGroup &tagGroup, const char *tagPath, TagGroup 
&subGroup );


/********************************************************************************************
 TagGroupGetTagAsText: Gets the data at 'tagPath' in 'tagGroup' as a string.
********************************************************************************************/
bool TagGroupGetTagAsText( const TagGroup &tagGroup, const char *tagPath, String &str );


/********************************************************************************************
 TagGroupGetTagAsUInt16: Gets the data at 'tagPath' in 'tagGroup' as a 16-bit unsigned 
integer.
********************************************************************************************/
bool TagGroupGetTagAsUInt16( const TagGroup &tagGroup, const char *tagPath, uint16 
*number );


/********************************************************************************************
 TagGroupGetTagAsUInt32: Gets the data at 'tagPath' in 'tagGroup' as a 32-bit unsigned 
integer.
********************************************************************************************/
bool TagGroupGetTagAsUInt32( const TagGroup &tagGroup, const char *tagPath, ulong *number 
);


/********************************************************************************************
 TagGroupGetTagLabel: Gets the label of the 'index'th tag in the tag group.
********************************************************************************************/
String TagGroupGetTagLabel( const TagGroup &tagGroup, long index );


/********************************************************************************************
 TagGroupGetTagSize: Gets the size of the tag.
********************************************************************************************/
long TagGroupGetTagSize( const TagGroup &tagGroup, long index );


/********************************************************************************************
 TagGroupGetTagType: Returns the 'type_index'th element of the tag's type.
********************************************************************************************/
long TagGroupGetTagType( const TagGroup &tagGroup, long index, long type_index );


/********************************************************************************************
 TagGroupGetTagTypeLength: Returns number of elements in the tag's type.
********************************************************************************************/
long TagGroupGetTagTypeLength( const TagGroup &tagGroup, long index );


/********************************************************************************************
 TagGroupHasChangedSince: Returns true if the tag group has changed since 'seeds' was 
constructed.
********************************************************************************************/
bool TagGroupHasChangedSince( const TagGroup &tagGroup, long seeds );


/********************************************************************************************
 TagGroupInsertTagAsArray: Inserts new data before 'ref_index' in 'tagGroup' as an array 
of data in 'image'.
********************************************************************************************/
void TagGroupInsertTagAsArray( const TagGroup &tagGroup, ulong ref_index, const Image 
&image );


/********************************************************************************************
 TagGroupInsertTagAsBoolean: Inserts new data before 'ref_index' in 'tagGroup' as a 
boolean.
********************************************************************************************/
void TagGroupInsertTagAsBoolean( const TagGroup &tagGroup, long ref_index, bool val );


/********************************************************************************************
 TagGroupInsertTagAsDouble: Inserts new data before 'ref_index' in 'tagGroup' as a double.
********************************************************************************************/
void TagGroupInsertTagAsDouble( const TagGroup &tagGroup, long ref_index, double number );


/********************************************************************************************
 TagGroupInsertTagAsDoubleComplex: Inserts new data before 'ref_index' in 'tagGroup' as a 
double complex.
********************************************************************************************/
void TagGroupInsertTagAsDoubleComplex( const TagGroup &tagGroup, long ref_index, const 
complex128_t &c );


/********************************************************************************************
 TagGroupInsertTagAsEightBitColor: Inserts new data before 'ref_index' in 'tagGroup' as 
an eight bit color.
********************************************************************************************/
void TagGroupInsertTagAsEightBitColor( const TagGroup &tagGroup, long ref_index, rgba_uint8_os_t c 
);


/********************************************************************************************
 TagGroupInsertTagAsFloat: Inserts new data before 'ref_index' in 'tagGroup' as a float.
********************************************************************************************/
void TagGroupInsertTagAsFloat( const TagGroup &tagGroup, long ref_index, float number );


/********************************************************************************************
 TagGroupInsertTagAsFloatComplex: Inserts new data before 'ref_index' in 'tagGroup' as a 
float complex.
********************************************************************************************/
void TagGroupInsertTagAsFloatComplex( const TagGroup &tagGroup, long ref_index, const 
complex128_t &c );


/********************************************************************************************
 TagGroupInsertTagAsFloatPoint: Inserts new data before 'ref_index' in 'tagGroup' as a 
float point.
********************************************************************************************/
void TagGroupInsertTagAsFloatPoint( const TagGroup &tagGroup, long ref_index, float x, 
float y );


/********************************************************************************************
 TagGroupInsertTagAsFloatRect: Inserts new data before 'ref_index' in 'tagGroup' as a 
float rect.
********************************************************************************************/
void TagGroupInsertTagAsFloatRect( const TagGroup &tagGroup, long ref_index, float t, 
float l, float b, float r );


/********************************************************************************************
 TagGroupInsertTagAsLong: Inserts new data before 'ref_index' in 'tagGroup' as a long.
********************************************************************************************/
void TagGroupInsertTagAsLong( const TagGroup &tagGroup, long ref_index, long number );


/********************************************************************************************
 TagGroupInsertTagAsLongPoint: Inserts new data before 'ref_index' in 'tagGroup' as a 
long point.
********************************************************************************************/
void TagGroupInsertTagAsLongPoint( const TagGroup &tagGroup, long ref_index, long x, long 
y );


/********************************************************************************************
 TagGroupInsertTagAsLongRect: Inserts new data before 'ref_index' in 'tagGroup' as a long 
rect.
********************************************************************************************/
void TagGroupInsertTagAsLongRect( const TagGroup &tagGroup, long ref_index, long t, long 
l, long b, long r );


/********************************************************************************************
 TagGroupInsertTagAsRGBUInt16: Inserts new data before 'ref_index' in 'tagGroup' as a 
16-bit rgb value.
********************************************************************************************/
void TagGroupInsertTagAsRGBUInt16( const TagGroup &tagGroup, long ref_index, uint16 r, 
uint16 g, uint16 b );


/********************************************************************************************
 TagGroupInsertTagAsShort: Inserts new data before 'ref_index' in 'tagGroup' as a short.
********************************************************************************************/
void TagGroupInsertTagAsShort( const TagGroup &tagGroup, long ref_index, short number );


/********************************************************************************************
 TagGroupInsertTagAsShortPoint: Inserts new data before 'ref_index' in 'tagGroup' as a 
short point.
********************************************************************************************/
void TagGroupInsertTagAsShortPoint( const TagGroup &tagGroup, long ref_index, short x, 
short y );


/********************************************************************************************
 TagGroupInsertTagAsShortRect: Inserts new data before 'ref_index' in 'tagGroup' as a 
short rect.
********************************************************************************************/
void TagGroupInsertTagAsShortRect( const TagGroup &tagGroup, long ref_index, short t, 
short l, short b, short r );


/********************************************************************************************
 TagGroupInsertTagAsString: Inserts new data before 'ref_index' in 'tagGroup' as a string.
********************************************************************************************/
void TagGroupInsertTagAsString( const TagGroup &tagGroup, long ref_index, const String &s 
);


/********************************************************************************************
 TagGroupInsertTagAsTagGroup: Inserts new data before 'ref_index' in 'TagGroup' as a 
group.
********************************************************************************************/
void TagGroupInsertTagAsTagGroup( const TagGroup &tagGroup, long ref_index, const 
TagGroup &subGroup );


/********************************************************************************************
 TagGroupInsertTagAsText: Inserts new data before 'ref_index' in 'tagGroup' as a string.
********************************************************************************************/
void TagGroupInsertTagAsText( const TagGroup &tagGroup, long ref_index, const String &s );


/********************************************************************************************
 TagGroupInsertTagAsUInt16: Inserts new data before 'ref_index' in 'tagGroup' as a 16-bit 
unsigned integer.
********************************************************************************************/
void TagGroupInsertTagAsUInt16( const TagGroup &tagGroup, long ref_index, uint16 number );


/********************************************************************************************
 TagGroupInsertTagAsUInt32: Inserts new data before 'ref_index' in 'tagGroup' as a 32-bit 
unsigned integer.
********************************************************************************************/
void TagGroupInsertTagAsUInt32( const TagGroup &tagGroup, long ref_index, ulong number );


/********************************************************************************************
 TagGroupIsList: Returns true if the tag group is a list.
********************************************************************************************/
bool TagGroupIsList( const TagGroup &tagGroup );


/********************************************************************************************
 TagGroupIsOpen: Returns whether 'tagGroup' is open or not.
********************************************************************************************/
bool TagGroupIsOpen( const TagGroup &tagGroup );


/********************************************************************************************
 TagGroupIsValid: Returns true if 'tagGroup' references a valid object.
********************************************************************************************/
bool TagGroupIsValid( const TagGroup &tagGroup );


/********************************************************************************************
 TagGroupLoadFromFile: Loads the contents of the file specified by 'path' into the tag 
group.
********************************************************************************************/
bool TagGroupLoadFromFile( const TagGroup &tagGroup, const String &path );


/********************************************************************************************
 TagGroupLoadFromFileWithLabel: Loads the contents of the file specified by 'path' into 
the tag group and returns the label, if any.
********************************************************************************************/
bool TagGroupLoadFromFileWithLabel( const TagGroup &tagGroup, const String &path, String 
&label );


/********************************************************************************************
 TagGroupMarkAsChanged: Marks 'tagGroup' as having beein modified.
********************************************************************************************/
void TagGroupMarkAsChanged( const TagGroup &tagGroup );


/********************************************************************************************
 TagGroupOpenBrowserWindow: Opens a browser window for the tag group.
********************************************************************************************/
Window TagGroupOpenBrowserWindow( const TagGroup &tagGroup, bool isFileBased );


/********************************************************************************************
 TagGroupParseAndCreateTagPath: Finds the tag group and index corresponding to the tag 
referenced by 'tagPath' in 'tagGroup'.
********************************************************************************************/
long TagGroupParseAndCreateTagPath( const TagGroup &tagGroup, const String &tagPath, 
TagGroup &parentGroup, String &label );


/********************************************************************************************
 TagGroupParseTagPath: Finds the tag group and index corresponding to the tag referenced 
by 'tagPath' in 'tagGroup'.
********************************************************************************************/
long TagGroupParseTagPath( const TagGroup &tagGroup, const String &tagPath, TagGroup 
&parentGroup, String &label );


/********************************************************************************************
 TagGroupReleaseSeeds: Releases the seeds returned by 'TagGroupGetSeeds'.
********************************************************************************************/
void TagGroupReleaseSeeds( const TagGroup &tagGroup, long seeds );


/********************************************************************************************
 TagGroupReplaceTagsWithCopy: Deletes all tags in 'tagGroup' and copies tags in 
'srcGroup' to 'tagGroup'.
********************************************************************************************/
void TagGroupReplaceTagsWithCopy( const TagGroup &tagGroup, const TagGroup &srcGroup );


/********************************************************************************************
 TagGroupSaveToFile: Saves the contents of the tag group to the file specified by 'path'.
********************************************************************************************/
void TagGroupSaveToFile( const TagGroup &tagGroup, const String &path );


/********************************************************************************************
 TagGroupSaveToFileWithLabel: Saves the contents of the tag group and the label 'label' 
to the file specified by 'path'.
********************************************************************************************/
void TagGroupSaveToFileWithLabel( const TagGroup &tagGroup, const String &path, const 
String &label );


/********************************************************************************************
 TagGroupSetIndexedTagAsArray: Set the data at 'index' in 'tagGroup' as an array of data 
in 'image'.
********************************************************************************************/
void TagGroupSetIndexedTagAsArray( const TagGroup &tagGroup, ulong index, const Image 
&image );


/********************************************************************************************
 TagGroupSetIndexedTagAsBoolean: Sets the data at 'index' in 'tagGroup' as a boolean.
********************************************************************************************/
void TagGroupSetIndexedTagAsBoolean( const TagGroup &tagGroup, long index, bool val );


/********************************************************************************************
 TagGroupSetIndexedTagAsDouble: Sets the data at 'index' in 'tagGroup' as a double.
********************************************************************************************/
void TagGroupSetIndexedTagAsDouble( const TagGroup &tagGroup, long index, double number );


/********************************************************************************************
 TagGroupSetIndexedTagAsDoubleComplex: Sets the data at 'index' in 'tagGroup' as a double 
complex.
********************************************************************************************/
void TagGroupSetIndexedTagAsDoubleComplex( const TagGroup &tagGroup, long index, const 
complex128_t &c );


/********************************************************************************************
 TagGroupSetIndexedTagAsEightBitColor: Sets the data at 'index' in 'tagGroup' as an eight 
bit color.
********************************************************************************************/
void TagGroupSetIndexedTagAsEightBitColor( const TagGroup &tagGroup, long index, rgba_uint8_os_t c 
);


/********************************************************************************************
 TagGroupSetIndexedTagAsFloat: Sets the data at 'index' in 'tagGroup' as a float.
********************************************************************************************/
void TagGroupSetIndexedTagAsFloat( const TagGroup &tagGroup, long index, float number );


/********************************************************************************************
 TagGroupSetIndexedTagAsFloatComplex: Sets the data at 'index' in 'tagGroup' as a float 
complex.
********************************************************************************************/
void TagGroupSetIndexedTagAsFloatComplex( const TagGroup &tagGroup, long index, const 
complex128_t &c );


/********************************************************************************************
 TagGroupSetIndexedTagAsFloatPoint: Sets the data at 'index' in 'tagGroup' as a float 
point.
********************************************************************************************/
void TagGroupSetIndexedTagAsFloatPoint( const TagGroup &tagGroup, long index, float x, 
float y );


/********************************************************************************************
 TagGroupSetIndexedTagAsFloatRect: Sets the data at 'index' in 'tagGroup' as a float rect.
********************************************************************************************/
void TagGroupSetIndexedTagAsFloatRect( const TagGroup &tagGroup, long index, float t, 
float l, float b, float r );


/********************************************************************************************
 TagGroupSetIndexedTagAsLong: Sets the data at 'index' in 'tagGroup' as a long.
********************************************************************************************/
void TagGroupSetIndexedTagAsLong( const TagGroup &tagGroup, long index, long number );


/********************************************************************************************
 TagGroupSetIndexedTagAsLongPoint: Sets the data at 'index' in 'tagGroup' as a long point.
********************************************************************************************/
void TagGroupSetIndexedTagAsLongPoint( const TagGroup &tagGroup, long index, long x, long 
y );


/********************************************************************************************
 TagGroupSetIndexedTagAsLongRect: Sets the data at 'index' in 'tagGroup' as a long rect.
********************************************************************************************/
void TagGroupSetIndexedTagAsLongRect( const TagGroup &tagGroup, long index, long t, long 
l, long b, long r );


/********************************************************************************************
 TagGroupSetIndexedTagAsRGBUInt16: Sets the data at 'index' in 'tagGroup' as a 16-bit rgb 
value.
********************************************************************************************/
void TagGroupSetIndexedTagAsRGBUInt16( const TagGroup &tagGroup, long index, uint16 r, 
uint16 g, uint16 b );


/********************************************************************************************
 TagGroupSetIndexedTagAsShort: Sets the data at 'index' in 'tagGroup' as a short.
********************************************************************************************/
void TagGroupSetIndexedTagAsShort( const TagGroup &tagGroup, long index, short number );


/********************************************************************************************
 TagGroupSetIndexedTagAsShortPoint: Sets the data at 'index' in 'tagGroup' as a short 
point.
********************************************************************************************/
void TagGroupSetIndexedTagAsShortPoint( const TagGroup &tagGroup, long index, short x, 
short y );


/********************************************************************************************
 TagGroupSetIndexedTagAsShortRect: Sets the data at 'index' in 'tagGroup' as a short rect.
********************************************************************************************/
void TagGroupSetIndexedTagAsShortRect( const TagGroup &tagGroup, long index, short t, 
short l, short b, short r );


/********************************************************************************************
 TagGroupSetIndexedTagAsString: Sets the data at 'index' in 'tagGroup' as a string.
********************************************************************************************/
void TagGroupSetIndexedTagAsString( const TagGroup &tagGroup, long index, const String &s 
);


/********************************************************************************************
 TagGroupSetIndexedTagAsTagGroup: Sets the data at 'index' in 'TagGroup' as a group.
********************************************************************************************/
void TagGroupSetIndexedTagAsTagGroup( const TagGroup &tagGroup, long index, const 
TagGroup &subGroup );


/********************************************************************************************
 TagGroupSetIndexedTagAsText: Sets the data at 'index' in 'tagGroup' as a string.
********************************************************************************************/
void TagGroupSetIndexedTagAsText( const TagGroup &tagGroup, long index, const String &s );


/********************************************************************************************
 TagGroupSetIndexedTagAsUInt16: Sets the data at 'index' in 'tagGroup' as a 16-bit 
unsigned integer.
********************************************************************************************/
void TagGroupSetIndexedTagAsUInt16( const TagGroup &tagGroup, long index, uint16 number );


/********************************************************************************************
 TagGroupSetIndexedTagAsUInt32: Sets the data at 'index' in 'tagGroup' as a 32-bit 
unsigned integer.
********************************************************************************************/
void TagGroupSetIndexedTagAsUInt32( const TagGroup &tagGroup, long index, ulong number );


/********************************************************************************************
 TagGroupSetIsOpen: Sets whether 'tagGroup' is open or not.
********************************************************************************************/
void TagGroupSetIsOpen( const TagGroup &tagGroup, bool is_open );


/********************************************************************************************
 TagGroupSetTagAsArray: Set the data at 'tagPath' in 'tagGroup' as an array of data in 
'image'.
********************************************************************************************/
void TagGroupSetTagAsArray( const TagGroup &tagGroup, const char *tagPath, const Image 
&image );


/********************************************************************************************
 TagGroupSetTagAsBoolean: Sets the data at 'tagPath' in 'tagGroup' as a boolean.
********************************************************************************************/
void TagGroupSetTagAsBoolean( const TagGroup &tagGroup, const char *tagPath, bool val );


/********************************************************************************************
 TagGroupSetTagAsDouble: Sets the data at 'tagPath' in 'tagGroup' as a double.
********************************************************************************************/
void TagGroupSetTagAsDouble( const TagGroup &tagGroup, const char *tagPath, double number 
);


/********************************************************************************************
 TagGroupSetTagAsDoubleComplex: Sets the data at 'tagPath' in 'tagGroup' as a double 
complex.
********************************************************************************************/
void TagGroupSetTagAsDoubleComplex( const TagGroup &tagGroup, const char *tagPath, const 
complex128_t &c );


/********************************************************************************************
 TagGroupSetTagAsEightBitColor: Sets the data at 'tagPath' in 'tagGroup' as an eight bit 
color.
********************************************************************************************/
void TagGroupSetTagAsEightBitColor( const TagGroup &tagGroup, const char *tagPath, rgba_uint8_os_t 
c );


/********************************************************************************************
 TagGroupSetTagAsFloat: Sets the data at 'tagPath' in 'tagGroup' as a float.
********************************************************************************************/
void TagGroupSetTagAsFloat( const TagGroup &tagGroup, const char *tagPath, float number );


/********************************************************************************************
 TagGroupSetTagAsFloatComplex: Sets the data at 'tagPath' in 'tagGroup' as a float 
complex.
********************************************************************************************/
void TagGroupSetTagAsFloatComplex( const TagGroup &tagGroup, const char *tagPath, const 
complex128_t &c );


/********************************************************************************************
 TagGroupSetTagAsFloatPoint: Sets the data at 'tagPath' in 'tagGroup' as a float point.
********************************************************************************************/
void TagGroupSetTagAsFloatPoint( const TagGroup &tagGroup, const char *tagPath, float x, 
float y );


/********************************************************************************************
 TagGroupSetTagAsFloatRect: Sets the data at 'tagPath' in 'tagGroup' as a float rect.
********************************************************************************************/
void TagGroupSetTagAsFloatRect( const TagGroup &tagGroup, const char *tagPath, float t, 
float l, float b, float r );


/********************************************************************************************
 TagGroupSetTagAsLong: Sets the data at 'tagPath' in 'tagGroup' as a long.
********************************************************************************************/
void TagGroupSetTagAsLong( const TagGroup &tagGroup, const char *tagPath, long number );


/********************************************************************************************
 TagGroupSetTagAsLongPoint: Sets the data at 'tagPath' in 'tagGroup' as a long point.
********************************************************************************************/
void TagGroupSetTagAsLongPoint( const TagGroup &tagGroup, const char *tagPath, long x, 
long y );


/********************************************************************************************
 TagGroupSetTagAsLongRect: Sets the data at 'tagPath' in 'tagGroup' as a long rect.
********************************************************************************************/
void TagGroupSetTagAsLongRect( const TagGroup &tagGroup, const char *tagPath, long t, 
long l, long b, long r );


/********************************************************************************************
 TagGroupSetTagAsRGBUInt16: Sets the data at 'tagPath' in 'tagGroup' as a 16-bit rgb 
value.
********************************************************************************************/
void TagGroupSetTagAsRGBUInt16( const TagGroup &tagGroup, const char *tagPath, uint16 r, 
uint16 g, uint16 b );


/********************************************************************************************
 TagGroupSetTagAsShort: Sets the data at 'tagPath' in 'tagGroup' as a short.
********************************************************************************************/
void TagGroupSetTagAsShort( const TagGroup &tagGroup, const char *tagPath, short number );


/********************************************************************************************
 TagGroupSetTagAsShortPoint: Sets the data at 'tagPath' in 'tagGroup' as a short point.
********************************************************************************************/
void TagGroupSetTagAsShortPoint( const TagGroup &tagGroup, const char *tagPath, short x, 
short y );


/********************************************************************************************
 TagGroupSetTagAsShortRect: Sets the data at 'tagPath' in 'tagGroup' as a short rect.
********************************************************************************************/
void TagGroupSetTagAsShortRect( const TagGroup &tagGroup, const char *tagPath, short t, 
short l, short b, short r );


/********************************************************************************************
 TagGroupSetTagAsString: Sets the data at 'tagPath' in 'tagGroup' as a string.
********************************************************************************************/
void TagGroupSetTagAsString( const TagGroup &tagGroup, const char *tagPath, const String 
&s );


/********************************************************************************************
 TagGroupSetTagAsTagGroup: Sets the data at 'tagPath' in 'TagGroup' as a group.
********************************************************************************************/
void TagGroupSetTagAsTagGroup( const TagGroup &tagGroup, const char *tagPath, const 
TagGroup &subGroup );


/********************************************************************************************
 TagGroupSetTagAsText: Sets the data at 'tagPath' in 'tagGroup' as a string.
********************************************************************************************/
void TagGroupSetTagAsText( const TagGroup &tagGroup, const char *tagPath, const String &s 
);


/********************************************************************************************
 TagGroupSetTagAsUInt16: Sets the data at 'tagPath' in 'tagGroup' as a 16-bit unsigned 
integer.
********************************************************************************************/
void TagGroupSetTagAsUInt16( const TagGroup &tagGroup, const char *tagPath, uint16 number 
);


/********************************************************************************************
 TagGroupSetTagAsUInt32: Sets the data at 'tagPath' in 'tagGroup' as a 32-bit unsigned 
integer.
********************************************************************************************/
void TagGroupSetTagAsUInt32( const TagGroup &tagGroup, const char *tagPath, ulong number 
);


/********************************************************************************************
 TagGroupSetTagRGBBitmap: Sets the data at 'tagPath' in 'tagGroup' as a RGB bitmap.
********************************************************************************************/
void TagGroupSetTagRGBBitmap( const TagGroup &tagGroup, const char *tagPath, const Image 
&image );


/********************************************************************************************
 TextAnnotationGetAlignment: Gets the alignment of the text in the text annotation.
********************************************************************************************/
long TextAnnotationGetAlignment( const Component &comp );


/********************************************************************************************
 TextAnnotationGetFixedPoint: Gets the fixed point of the text annotation.
********************************************************************************************/
void TextAnnotationGetFixedPoint( const Component &comp, float *x, float *y );


/********************************************************************************************
 TextAnnotationGetResizeStyle: Gets the resize style of the text annotation.
********************************************************************************************/
long TextAnnotationGetResizeStyle( const Component &comp );


/********************************************************************************************
 TextAnnotationGetText: Gets the text of a text annotation.
********************************************************************************************/
String TextAnnotationGetText( const Component &comp );


/********************************************************************************************
 TextAnnotationSetAlignment: Sets the alignment of the text in the text annotation.
********************************************************************************************/
void TextAnnotationSetAlignment( const Component &comp, long alignment );


/********************************************************************************************
 TextAnnotationSetFixedPoint: Sets the fixed point of the text annotation.
********************************************************************************************/
void TextAnnotationSetFixedPoint( const Component &comp, float x, float y );


/********************************************************************************************
 TextAnnotationSetResizeStyle: Sets the resize style of the text annotation.
********************************************************************************************/
void TextAnnotationSetResizeStyle( const Component &comp, long style );


/********************************************************************************************
 TextAnnotationSetText: Sets the text of a text annotation.
********************************************************************************************/
void TextAnnotationSetText( const Component &comp, const String &text );


/********************************************************************************************
 ThrowableIsValid: Returns true if 'throw_' is a valid object.
********************************************************************************************/
bool ThrowableIsValid( const Throwable &throw_ );


/********************************************************************************************
 TickCount: Return the MacOS system tick count.
********************************************************************************************/
uint32 TickCount( );


/********************************************************************************************
 TransferTagsAndApplyDataBar: Transfer tags and apply data bar to the image.
********************************************************************************************/
void TransferTagsAndApplyDataBar( const Image &argument_1 );


/********************************************************************************************
 TransformPointFromImageToWindow: Place in (x_window,y_window) the 
********************************************************************************************/
void TransformPointFromImageToWindow( const Image &image, float x_image, float y_image, 
float *x_window, float *y_window );


/********************************************************************************************
 TrapException: Mark the exception to be thrown upon return external function call.
********************************************************************************************/
void TrapException( short error, long context );


/********************************************************************************************
 TryToUse: Look for an image with the given name, width, height, dataType, and position 
[h,v]. Return it if found and create it if not. Store 1 into fresh if it was created and 
0 if not.
********************************************************************************************/
Image TryToUse( const char *name, long width, long height, short dataType, short h, short 
v, bool *fresh );


/********************************************************************************************
 TwoButtonDialog: Puts up a dialog with the given prompt and two buttons labeled 
according to the parameters. Returns 1 for the acceptLabel button and false for the other 
one.
********************************************************************************************/
bool TwoButtonDialog( const char *prompt, const char *acceptLabel, const char 
*rejectLabel );


/********************************************************************************************
 UnregisterCustomMenu: Unregister a custom menu. See the SDK documentation for more 
information.
********************************************************************************************/
void UnregisterCustomMenu( long menuHandlerToken );


/********************************************************************************************
 UnregisterCustomTool: Remove the tool to the custom tool list. See the SDK documentation 
for more information.
********************************************************************************************/
void UnregisterCustomTool( long toolToken );


/********************************************************************************************
 UnregisterObjectListener: Remove object listener from OM object. See the SDK 
documentation for more information.
********************************************************************************************/
void UnregisterObjectListener( long object, long id );


/********************************************************************************************
 UnregisterSystemIdle: Unregister a system idle procedure.
********************************************************************************************/
void UnregisterSystemIdle( SystemIdleProc SystemIdleProc );


/********************************************************************************************
 UpdateDisplay: Update the image display portion that displays the image rows from 
startRow to endRow.
********************************************************************************************/
void UpdateDisplay( const Image &argument_1, long startRow, long endRow );


/********************************************************************************************
 UpdateImage: Update the image immediately.
********************************************************************************************/
void UpdateImage( const Image &argument_1 );


/********************************************************************************************
 UpdateTimeBarPercentage: Updates an open time bar to the given percentage.
********************************************************************************************/
void UpdateTimeBarPercentage( float percentage );


/********************************************************************************************
 ValidateSurvey: Do the survey if necessary.
********************************************************************************************/
void ValidateSurvey( const Image &argument_1 );


/********************************************************************************************
 variance: Return the variance of the image.
********************************************************************************************/
float variance( const Image &argument_1 );


/********************************************************************************************
 WindowClose: Closes the window, prompting the user if 'verify' is true.
********************************************************************************************/
void WindowClose( const Window &window, bool verify );


/********************************************************************************************
 WindowGetContentBounds: Gets the bounding rectangle of the content area of the 'window'.
********************************************************************************************/
void WindowGetContentBounds( const Window &window, long *top, long *left, long *bottom, 
long *right );


/********************************************************************************************
 WindowGetContentPosition: Gets the position of the top-left corner of the content area 
of the 'window'.
********************************************************************************************/
void WindowGetContentPosition( const Window &window, long *x, long *y );


/********************************************************************************************
 WindowGetContentSize: Gets the size of the content area of the 'window'.
********************************************************************************************/
void WindowGetContentSize( const Window &window, long *x, long *y );


/********************************************************************************************
 WindowGetFrameBounds: Gets the bounding rectangle of the frame area of the 'window'.
********************************************************************************************/
void WindowGetFrameBounds( const Window &window, long *top, long *left, long *bottom, 
long *right );


/********************************************************************************************
 WindowGetFramePosition: Gets the position of the top-left corner of the frame area of 
the 'window'.
********************************************************************************************/
void WindowGetFramePosition( const Window &window, long *x, long *y );


/********************************************************************************************
 WindowGetFrameSize: Gets the size of the frame area of the 'window'.
********************************************************************************************/
void WindowGetFrameSize( const Window &window, long *x, long *y );


/********************************************************************************************
 WindowGetMousePosition: Gets the current position of the mouse in the windows coordinate 
system.
********************************************************************************************/
void WindowGetMousePosition( const Window &window, long *x, long *y );


/********************************************************************************************
 WindowGetTitle: Gets the title of the window.
********************************************************************************************/
String WindowGetTitle( const Window &window );


/********************************************************************************************
 WindowGetType: Gets the type of thw window.
********************************************************************************************/
long WindowGetType( const Window &window );


/********************************************************************************************
 WindowHide: Hides the window.
********************************************************************************************/
void WindowHide( const Window &window );


/********************************************************************************************
 WindowIsOpen: Returns true if the window has not been closed.
********************************************************************************************/
bool WindowIsOpen( const Window &window );


/********************************************************************************************
 WindowIsShown: Returns true if the window is shown.
********************************************************************************************/
bool WindowIsShown( const Window &window );


/********************************************************************************************
 WindowIsValid: Returns true if 'window' points to a valid object.
********************************************************************************************/
bool WindowIsValid( const Window &window );


/********************************************************************************************
 WindowSelect: Brings 'window' to the front.
********************************************************************************************/
void WindowSelect( const Window &window );


/********************************************************************************************
 WindowSendBehind: Sends 'window' behind 'behind_window'.
********************************************************************************************/
void WindowSendBehind( const Window &window, const Window &behind_window );


/********************************************************************************************
 WindowSetContentBounds: Sets the bounding rectangle of the content area of the 'window'.
********************************************************************************************/
void WindowSetContentBounds( const Window &window, long top, long left, long bottom, long 
right );


/********************************************************************************************
 WindowSetContentPosition: Sets the position of the top-left corner of the content area 
of the 'window'.
********************************************************************************************/
void WindowSetContentPosition( const Window &window, long x, long y );


/********************************************************************************************
 WindowSetContentSize: Sets the size of the content area of the 'window'.
********************************************************************************************/
void WindowSetContentSize( const Window &window, long x, long y );


/********************************************************************************************
 WindowSetFrameBounds: Sets the bounding rectangle of the frame area of the 'window'.
********************************************************************************************/
void WindowSetFrameBounds( const Window &window, long top, long left, long bottom, long 
right );


/********************************************************************************************
 WindowSetFramePosition: Sets the position of the top-left corner of the frame area of 
the 'window'.
********************************************************************************************/
void WindowSetFramePosition( const Window &window, long x, long y );


/********************************************************************************************
 WindowSetFrameSize: Sets the size of the frame area of the 'window'.
********************************************************************************************/
void WindowSetFrameSize( const Window &window, long x, long y );


/********************************************************************************************
 WindowSetTitle: Sets the title of the window.
********************************************************************************************/
void WindowSetTitle( const Window &window, const String &title );


/********************************************************************************************
 WindowShow: Shows the window.
********************************************************************************************/
void WindowShow( const Window &window );


/********************************************************************************************
 WindowUpdate: Updates 'window's display.
********************************************************************************************/
void WindowUpdate( const Window &window );


/********************************************************************************************
 WriteFile: Write the string to the file.
********************************************************************************************/
void WriteFile( DM_FileReference file, const String &data );


/********************************************************************************************
 WriteRawStream: Write length bytes from the memory pointed to by data to rawStream.
********************************************************************************************/
void WriteRawStream( long rawStream, long data, long length );


/********************************************************************************************
 XX_GetProcessKey: Return a keystroke associated with the background process indicated by 
pid.
********************************************************************************************/
short XX_GetProcessKey( long pid );


/********************************************************************************************
 XX_InstallImageProcess: Associate the process indicated by pid with the image. 
Keystrokes going to the image will queue in the process after this call.
********************************************************************************************/
void XX_InstallImageProcess( const Image &argument_1, long pid );


/********************************************************************************************
 Yield: Yield to another background task.
********************************************************************************************/
void Yield( );

/*
**
*/


template <typename ClassDesc> class DMIntrinsicClassStaticInitBaseT
{
public:
	DMIntrinsicClassStaticInitBaseT()
	{
		static PlugIn::DigitalMicrographInterface::Init init( &Init );
		if ( ClassDesc::num_refs++ == 0 )
		{
			PlugIn::DM_Interface *app_desc = PlugIn::gDigitalMicrographInterface.GetInterface();
			DMIntrinsicClassStaticInitBaseT::Init( app_desc );
			PlugIn::gDigitalMicrographInterface.AddInitializer( &init );
		}
	}
	~DMIntrinsicClassStaticInitBaseT()
	{
		if ( --ClassDesc::num_refs == 0 )
		{
			ClassDesc::class_descriptor->rem_ref();
			ClassDesc::class_descriptor = NULL;
		}
	}
	static void Init( GatanPlugIn::DM_Interface *app_desc )
	{
		if ( ClassDesc::class_descriptor != NULL )
		{
			ClassDesc::class_descriptor->rem_ref();
		}
		ClassDesc::class_descriptor
			= reinterpret_cast<PlugIn::DM_ClassDesc *>( app_desc->get_class_descriptor( ClassDesc::class_name() ) );
	}
};

template <typename DMIntrnClassDesc> class DMIntrinsicClassBaseT
{
public:
	typedef DMIntrinsicClassBaseT                     this_type;
	typedef DMIntrnClassDesc                          class_desc_type;
	typedef typename class_desc_type::token_type      token_type;
	typedef typename class_desc_type::ret_token_type  ret_token_type;	
public:
	DMIntrinsicClassBaseT() : dm_token( NULL ) { }
	DMIntrinsicClassBaseT( token_type dm_token_in ) : dm_token( dm_token_in ) { add_ref_ptr( dm_token ); }
	DMIntrinsicClassBaseT( ret_token_type dm_token_in ) : dm_token(reinterpret_cast<token_type>(dm_token_in) ) {}
	DMIntrinsicClassBaseT(const this_type &other) : dm_token( other.dm_token ) { add_ref_ptr( dm_token ); }
	~DMIntrinsicClassBaseT() { rem_ref_ptr( dm_token ); }
	this_type &operator=(const this_type &other) { assign( other ); return *this; }

	void assign(const DMIntrinsicClassBaseT &other) { add_ref_ptr( other.dm_token ); rem_ref_ptr( dm_token ); dm_token = other.dm_token; }
	void assign( token_type dm_token_in)     { add_ref_ptr( dm_token_in ); rem_ref_ptr( dm_token ); dm_token = dm_token_in; }
	void assign( ret_token_type dm_token_in) { rem_ref_ptr( dm_token ); dm_token = reinterpret_cast<token_type>( dm_token_in ); }

	bool IsValid() const { return get_class_descriptor()->is_obj_valid( self_to_obj(dm_token) ); }

	bool is_same_as( const this_type &obj_2 ) const  { return get_class_descriptor()->is_obj_same_as( self_to_obj(dm_token), self_to_obj(obj_2.dm_token) ); }
	bool is_same_as( token_type dm_token_2 ) const   { return get_class_descriptor()->is_obj_same_as( self_to_obj(dm_token), self_to_obj(dm_token_2) ); }
	bool is_equal_to( const this_type &obj_2 ) const { return get_class_descriptor()->is_obj_equal_to( self_to_obj(dm_token), self_to_obj(obj_2.dm_token) ); }
	bool is_equal_to( token_type dm_token_2 ) const  { return get_class_descriptor()->is_obj_equal_to( self_to_obj(dm_token), self_to_obj(dm_token_2) ); }

	bool operator==( const this_type &obj_2 ) const  { return  is_equal_to( obj_2 ); }
	bool operator==( token_type dm_token_2 ) const   { return  is_equal_to( dm_token_2 ); }
	bool operator!=( const this_type &obj_2 ) const  { return !is_equal_to( obj_2 ); }
	bool operator!=( token_type dm_token_2 ) const   { return !is_equal_to( dm_token_2 ); }

	ret_token_type release()       { token_type dm_token_ret = dm_token; dm_token = NULL; return reinterpret_cast<ret_token_type>( dm_token_ret ); } 
	token_type     get() const     { return dm_token; }
	token_type    *get_ptr()       { return &dm_token; }

	static inline GatanPlugIn::DM_ClassDesc *get_class_descriptor() { return class_desc_type::class_descriptor; }

	static void add_ref_ptr( token_type tok ) { if ( tok != NULL ) { get_class_descriptor()->add_obj_ref( self_to_obj(tok) ); } }
	static void rem_ref_ptr( token_type tok ) { if ( tok != NULL ) { get_class_descriptor()->rem_obj_ref( self_to_obj(tok) ); } }
	static void assign_ptr( token_type &ltok, token_type rtok ) { if ( ltok != rtok ) { add_ref_ptr( rtok ); rem_ref_ptr( ltok ); ltok = rtok; } }
	static void assign_ptr( token_type &ltok, ret_token_type rtok ) { rem_ref_ptr( ltok ); ltok = reinterpret_cast<token_type>( rtok ); }
	static ret_token_type return_ptr( token_type rtok ) { add_ref_ptr(rtok); return reinterpret_cast<ret_token_type>( rtok ); } 

	typedef DMIntrinsicClassStaticInitBaseT<class_desc_type> StaticInit;
protected:
	token_type dm_token;

	static token_type obj_to_self( DM_ObjectToken tok ) { return reinterpret_cast<token_type>( tok ); }
	static DM_ObjectToken self_to_obj( token_type tok ) { return reinterpret_cast<DM_ObjectToken>( tok ); }
};

template <typename DMIntrnClassDesc,typename DMIntrnBaseClassDesc> class DMIntrinsicDerivedClassBaseT
	: public DMIntrnBaseClassDesc::final_type
{
public:
	typedef DMIntrinsicDerivedClassBaseT     this_type;
	typedef DMIntrnClassDesc                 class_desc_type;
	typedef DMIntrnBaseClassDesc             base_class_desc_type;
	typedef typename DMIntrnBaseClassDesc::final_type base_type;

	typedef typename class_desc_type::token_type      token_type;
	typedef typename class_desc_type::ret_token_type  ret_token_type;	

	typedef typename base_class_desc_type::token_type base_token_type;
	typedef typename base_class_desc_type::ret_token_type ret_base_token_type;

	DMIntrinsicDerivedClassBaseT()                           : base_type() {}
	DMIntrinsicDerivedClassBaseT( token_type dm_token_ )     : base_type( convert_to_base( dm_token_ ) ) {}
	DMIntrinsicDerivedClassBaseT( ret_token_type dm_token_ ) : base_type( convert_to_base_ret( dm_token_ ) ) {}
	void assign( const DMIntrinsicDerivedClassBaseT &other ) { base_type::assign( other ); }
	void assign( token_type dm_token )     { base_type::assign( convert_to_base( dm_token ) ); }
	void assign( ret_token_type dm_token ) { base_type::assign( convert_to_base_ret( dm_token ) ); }
	DMIntrinsicDerivedClassBaseT &operator=(const DMIntrinsicDerivedClassBaseT &other) { assign( other ); return *this; }
	DMIntrinsicDerivedClassBaseT &operator=( token_type dm_token_in)     { assign( dm_token_in ); return *this; }
	DMIntrinsicDerivedClassBaseT &operator=( ret_token_type dm_token_in) { assign( dm_token_in ); return *this; }

	bool IsValid() const { return get_class_descriptor()->is_obj_valid( self_to_obj(dm_token) ); }

	static inline GatanPlugIn::DM_ClassDesc *get_class_descriptor()      { return class_desc_type::class_descriptor; }
	static inline GatanPlugIn::DM_ClassDesc *get_base_class_descriptor() { return base_class_desc_type::class_descriptor; }

	ret_token_type release()       { token_type dm_token_ret = reinterpret_cast<token_type>( dm_token ); dm_token = NULL; return reinterpret_cast<ret_token_type>( dm_token_ret ); } 
	token_type     get() const     { return reinterpret_cast<token_type>( dm_token ); }
	token_type    *get_ptr()       { return reinterpret_cast<token_type *>( &dm_token ); }

	static void add_ref_ptr( token_type tok ) { if ( tok != NULL ) { get_class_descriptor()->add_obj_ref( self_to_obj(tok) ); } }
	static void rem_ref_ptr( token_type tok ) { if ( tok != NULL ) { get_class_descriptor()->rem_obj_ref( self_to_obj(tok) ); } }
	static void assign_ptr( token_type &ltok, token_type rtok ) { if ( ltok != rtok ) { add_ref_ptr( rtok ); rem_ref_ptr( ltok ); ltok = rtok; } }
	static void assign_ptr( token_type &ltok, ret_token_type rtok ) { rem_ref_ptr( ltok ); ltok = reinterpret_cast<token_type>( rtok ); }

	typedef DMIntrinsicClassStaticInitBaseT<class_desc_type> StaticInit;
protected:
	static token_type obj_to_self( DM_ObjectToken tok ) { return reinterpret_cast<token_type>( tok ); }
	static DM_ObjectToken self_to_obj( token_type tok ) { return reinterpret_cast<DM_ObjectToken>( tok ); }

	static base_token_type obj_to_base( DM_ObjectToken tok ) { return reinterpret_cast<base_token_type>( tok ); }
	static DM_ObjectToken base_to_obj( base_token_type tok ) { return reinterpret_cast<DM_ObjectToken>( tok ); }

	static base_token_type convert_to_base( token_type dm_token_in )               { return reinterpret_cast<base_token_type>( dm_token_in ); }
	static ret_base_token_type convert_to_base_ret( ret_token_type dm_token_in )   { return reinterpret_cast<ret_base_token_type>( dm_token_in ); }
	static token_type convert_from_base( base_token_type dm_token_in )             { return reinterpret_cast<token_type>( dm_token_in ); }
	static ret_token_type convert_from_base_ret( ret_base_token_type dm_token_in ) { return reinterpret_cast<ret_token_type>( dm_token_in ); }
};

/*
**
*/

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


/*
** class Image
*/

class Image;

struct DMIntrinsicClassDesc_Image
{
	typedef Image                  final_type;
	typedef DM_ImageToken          token_type;
	typedef DM_ImageToken_1Ref     ret_token_type;
	static ulong                      num_refs;
	static GatanPlugIn::DM_ClassDesc *class_descriptor;
	static const char *class_name() { return "Gatan:DigitalMicrograph:Image"; }
};

class Image : public DMIntrinsicClassBaseT<DMIntrinsicClassDesc_Image>
{
public:
	typedef Image this_type;
	typedef DMIntrinsicClassBaseT<DMIntrinsicClassDesc_Image> base_type;
public:
	Image() : base_type() { }
	Image( token_type dm_token_in )     : base_type( dm_token_in ) {}
	Image( ret_token_type dm_token_in ) : base_type( dm_token_in ) {}
	Image &operator=( token_type dm_token_in)     { assign( dm_token_in ); return *this; }
	Image &operator=( ret_token_type dm_token_in) { assign( dm_token_in ); return *this; }

	void CalculateHistogram(const Image &hist_image, long complexMode, float min, float max) const;
	void CalculateMinMax(long surveyTechnique, long complexMode, float *min, float *max) const;
	void ChangeDataType( uint32 dataType ) const;
	Image Clone() const;
	void CopyCalibrationFrom(const Image &src_image) const;
	long CountImageDisplays() const;
	long CountImageDisplaysInImageDocument(const ImageDocument &imgDoc) const;
	ImageDisplay CreateImageDisplay(long displayType) const;
	void DataChanged() const;
	ulong GetDataElementBitSize() const;
	ulong GetDataElementByteSize() const;
	ulong GetDataSeed() const;
	ulong GetDataType() const;
	String GetDescriptionText() const;
	void GetDimensionCalibration(long dimension, float *origin, float *scale, String &units, long calibrationFormat) const;
	float GetDimensionOrigin(long dimension) const;
	float GetDimensionScale(long dimension) const;
	ulong GetDimensionSize(ulong dimension) const;
	void GetDimensionUnitInfo(long dimension, String &canon_units, long *power) const;
	String GetDimensionUnitString(long dimension) const;
	ulong GetID() const;
	ImageDisplay GetImageDisplay(long index) const;
	ImageDisplay GetImageDisplayInImageDocument(const ImageDocument &imgDoc, long index) const;
	float GetIntensityOrigin() const;
	float GetIntensityScale() const;
	void GetIntensityUnitInfo(String &canon_units, long *power) const;
	String GetIntensityUnitString() const;
	String GetLabel() const;
	String GetName() const;
	ulong GetNumDimensions() const;
	ImageDocument GetOrCreateImageDocument() const;
	TagGroup GetTagGroup() const;
	ScriptObject GetUniqueID() const;
	bool IsDataTypeBinary() const;
	bool IsDataTypeComplex() const;
	bool IsDataTypeFloat() const;
	bool IsDataTypeInteger() const;
	bool IsDataTypePackedComplex() const;
	bool IsDataTypeReal() const;
	bool IsDataTypeRGB() const;
	bool IsDataTypeSignedInteger() const;
	bool IsDataTypeUnsignedInteger() const;
	bool IsDimensionCalibrationDisplayed(ulong dim) const;
	bool IsIntensityCalibrationDisplayed() const;
	void SetDescriptionText(const String &description) const;
	void SetDimensionCalibration(long dimension, float origin, float scale, const String &unitString, long calibrationFormat) const;
	void SetDimensionCalibrationDisplayed(ulong dim, bool do_display) const;
	void SetDimensionOrigin(long dimension, float origin) const;
	void SetDimensionScale(long dimension, float scale) const;
	void SetDimensionUnitInfo(long dimension, const String &canon_units, long power) const;
	void SetDimensionUnitString(long dimension, const String &units) const;
	void SetIntensityCalibrationDisplayed(bool do_display) const;
	void SetIntensityOrigin(float origin) const;
	void SetIntensityScale(float scale) const;
	void SetIntensityUnitInfo(const String &canon_units, long power) const;
	void SetIntensityUnitString(const String &units) const;
	void SetName(const String &name) const;
};
static Image::StaticInit sImageStaticInit;




/*
** class ROI
*/

class ROI;

struct DMIntrinsicClassDesc_ROI
{
	typedef ROI                 final_type;
	typedef DM_RegionOfInterestToken         token_type;
	typedef DM_RegionOfInterestToken_1Ref    ret_token_type;	
	static ulong                      num_refs;
	static GatanPlugIn::DM_ClassDesc *class_descriptor;
	static const char *class_name() { return "Gatan:DigitalMicrograph:RegionOfInterest"; }
};

class ROI : public DMIntrinsicClassBaseT<DMIntrinsicClassDesc_ROI>
{
public:
	typedef ROI this_type;
	typedef DMIntrinsicClassBaseT<DMIntrinsicClassDesc_ROI> base_type;
public:
	ROI() : base_type() { }
	ROI( token_type dm_token_in )     : base_type( dm_token_in ) {}
	ROI( ret_token_type dm_token_in ) : base_type(dm_token_in ) {}
	ROI &operator=( token_type dm_token_in)     { assign( dm_token_in ); return *this; }
	ROI &operator=( ret_token_type dm_token_in) { assign( dm_token_in ); return *this; }

	void AddToMask(const Image &mask, float top, float left, float bottom, float right) const;
	void AddVertex(float x, float y) const;
	void ClearVertices() const;
	ROI Clone() const;
	bool ContainsPoint(float x, float y) const;
	long CountVertices() const;
	void DeleteVertex(long index) const;
	void GetColor(float *r, float *g, float *b) const;
	bool GetDeletable() const;
	long GetID() const;
	String GetLabel() const;
	void GetLine(float *sx, float *sy, float *ex, float *ey) const;
	bool GetMoveable() const;
	String GetName() const;
	void GetPoint(float *x, float *y) const;
	void GetRange(float *start, float *end) const;
	void GetRectangle(float *top, float *left, float *bottom, float *right) const;
	bool GetResizable() const;
	void GetVertex(long index, float *x, float *y) const;
	bool GetVolatile() const;
	void InsertVertex(long before, float x, float y) const;
	bool IsClosed() const;
	bool IsLine() const;
	bool IsPoint() const;
	bool IsRange() const;
	bool IsRectangle() const;
	void SetColor(float r, float g, float b) const;
	void SetDeletable(bool deletable) const;
	void SetIsClosed(bool is_closed) const;
	void SetLabel(const String &name) const;
	void SetLine(float sx, float sy, float ex, float ey) const;
	void SetMoveable(bool moveable) const;
	void SetName(const String &name) const;
	void SetPoint(float x, float y) const;
	void SetRange(float start, float end) const;
	void SetRectangle(float top, float left, float bottom, float right) const;
	void SetRegionToComplexValue(const Image &mask, const complex128_t &value, float top, float left, float bottom, float right) const;
	void SetRegionToRGBValue(const Image &mask, rgba_uint8_os_t value, float top, float left, float bottom, float right) const;
	void SetRegionToValue(const Image &mask, double value, float top, float left, float bottom, float right) const;
	void SetResizable(bool resizable) const;
	void SetVertex(long index, float x, float y) const;
	void SetVolatile(bool is_volatile) const;
};
static ROI::StaticInit sROIStaticInit;



/*
** class Component
*/

class Component;

struct DMIntrinsicClassDesc_Component
{
	typedef Component                  final_type;
	typedef DM_ComponentToken          token_type;
	typedef DM_ComponentToken_1Ref     ret_token_type;
	static ulong                      num_refs;
	static GatanPlugIn::DM_ClassDesc *class_descriptor;
	static const char *class_name() { return "Gatan:DigitalMicrograph:Component"; }
};

class Component : public DMIntrinsicClassBaseT<DMIntrinsicClassDesc_Component>
{
public:
	typedef Component this_type;
	typedef DMIntrinsicClassBaseT<DMIntrinsicClassDesc_Component> base_type;
public:
	Component() : base_type() { }
	Component( token_type dm_token_in )     : base_type( dm_token_in ) {}
	Component( ret_token_type dm_token_in ) : base_type( dm_token_in ) {}
	Component &operator=( token_type dm_token_in)     { assign( dm_token_in ); return *this; }
	Component &operator=( ret_token_type dm_token_in) { assign( dm_token_in ); return *this; }

	void AddChildAfter(const Component &child, const Component &annot_pos) const;
	void AddChildAtBeginning(const Component &child) const;
	void AddChildAtEnd(const Component &child) const;
	void AddChildBefore(const Component &child, const Component &annot_pos) const;
	Component AddNewComponent(long type, float f1, float f2, float f3, float f4) const;
	Component Clone(bool doDeepCopy) const;
	long CountChildren() const;
	long CountChildrenOfType(long type) const;
	void GetBoundingRect(float *t, float *l, float *b, float *r) const;
	void GetBoundingRectInView(float *t, float *l, float *b, float *r) const;
	Component GetChild(long index) const;
	Component GetChildByID(long ID) const;
	void GetChildToLocalTransform(float *off_x, float *off_y, float *scale_x, float *scale_y) const;
	void GetChildToPageTransform(float *off_x, float *off_y, float *scale_x, float *scale_y) const;
	void GetChildToViewTransform(float *off_x, float *off_y, float *scale_x, float *scale_y) const;
	void GetChildToWindowTransform(float *off_x, float *off_y, float *scale_x, float *scale_y) const;
	bool GetControlPoint(long loc, float *x, float *y) const;
	Component GetDescendentByID(long ID) const;
	long GetDrawingMode() const;
	long GetFillMode() const;
	long GetFontAttributes() const;
	String GetFontFaceName() const;
	void GetFontInfo(String &faceName, long *attributes, long *size) const;
	long GetFontSize() const;
	long GetID() const;
	ImageDocument GetImageDocument() const;
	void GetLocalToPageTransform(float *off_x, float *off_y, float *scale_x, float *scale_y) const;
	void GetLocalToViewTransform(float *off_x, float *off_y, float *scale_x, float *scale_y) const;
	void GetLocalToWindowTransform(float *off_x, float *off_y, float *scale_x, float *scale_y) const;
	Component GetNthChildOfType(long type, long index) const;
	Component GetParentComponent() const;
	ImageDisplay GetParentImageDisplay() const;
	void GetRect(float *top, float *left, float *bottom, float *right) const;
	void GetRectInView(float *top, float *left, float *bottom, float *right) const;
	TagGroup GetTagGroup() const;
	long GetType() const;
	bool IsOfType(long type) const;
	bool IsSelected() const;
	void OffsetControlPoint(long loc, float x, float y, long restrict_style) const;
	void PositionAroundPoint(float new_x, float new_y, float rel_x, float rel_y, bool horz, bool vert) const;
	void RemoveFromParent() const;
	void SetControlPoint(long loc, float x, float y, long restrict_style) const;
	void SetDrawingMode(long mode) const;
	void SetFillMode(long mode) const;
	void SetFontAttributes(long attributes) const;
	void SetFontFaceName(const String &face_name) const;
	void SetFontInfo(const String &face_name, long attributes, long size) const;
	void SetFontSize(long size) const;
	void SetRect(float top, float left, float bottom, float right) const;
	void SetSelected(bool select) const;
	void TransformCoordinates(float off_x, float off_y, float scale_x, float scale_y) const;
};
static Component::StaticInit sComponentStaticInit;





/*
** class ImageDisplay
*/

class ImageDisplay;

struct DMIntrinsicClassDesc_ImageDisplay
{
	typedef ImageDisplay                  final_type;
	typedef DM_ImageDisplayToken          token_type;
	typedef DM_ImageDisplayToken_1Ref     ret_token_type;
	static ulong                      num_refs;
	static GatanPlugIn::DM_ClassDesc *class_descriptor;
	static const char *class_name() { return "Gatan:DigitalMicrograph:ImageDisplay"; }
};


class ImageDisplay : public DMIntrinsicDerivedClassBaseT<DMIntrinsicClassDesc_ImageDisplay,DMIntrinsicClassDesc_Component>
{
public:
	typedef ImageDisplay this_type;
	typedef DMIntrinsicDerivedClassBaseT<DMIntrinsicClassDesc_ImageDisplay,DMIntrinsicClassDesc_Component> base_type;
public:
	ImageDisplay()                           : base_type() {}
	ImageDisplay( token_type dm_token_ )     : base_type( dm_token_ ) {}
	ImageDisplay( ret_token_type dm_token_ ) : base_type( dm_token_ ) {}
	ImageDisplay &operator=( token_type dm_token_in)     { assign( dm_token_in ); return *this; }
	ImageDisplay &operator=( ret_token_type dm_token_in) { assign( dm_token_in ); return *this; }
	void AccumulateROIsToMask(const Image &mask, float top, float left, float bottom, float right, float mask_val) const;
	void AddKeyListener(const char *listener_key, const char *listener_script) const;
	void AddROI(const ROI &roi) const;
	void ChangeDisplayType(long new_type) const;
	long CountROIs() const;
	void DeleteROI(const ROI &roi) const;
	bool DoesROIExist(const char *name) const;
	void ExportToFile(const char *format, const char *file_name) const;
	Image GetBufferedImage() const;
	long GetComplexMode() const;
	float GetComplexModeRange() const;
	void GetContrastLimits(float *low, float *high) const;
	long GetContrastMode() const;
	void GetContrastParameters(float *bright, float *contrast) const;
	Image GetDisplayedImage() const;
	void GetDisplayedLayers(long *start, long *end) const;
	long GetDisplayType() const;
	bool GetDoAutoSurvey() const;
	Image GetExportImage(ulong mode, ImageDisplay &clut_display) const;
	Image GetImage() const;
	void GetImageAdjustRect(float *top, float *left, float *bottom, float *right) const;
	void GetImageAdjustRectInView(float *top, float *left, float *bottom, float *right) const;
	void GetImageRect(float *top, float *left, float *bottom, float *right) const;
	void GetImageRectInView(float *top, float *left, float *bottom, float *right) const;
	Image GetInputColorTable() const;
	Image GetIntensityTransformation() const;
	float GetMinimumContrast() const;
	Image GetOutputColorTable() const;
	ROI GetROI(long index) const;
	long GetROISelectionStyle(const ROI &r) const;
	long GetSurveyTechnique() const;
	bool IsCaptionOn() const;
	bool IsROISelected(const ROI &roi) const;
	ROI LookupROI(const char *name) const;
	ROI LookupROIByID(long id) const;
	void RemoveKeyListener(const char *listener_key) const;
	void SetCaptionOn(bool on) const;
	void SetComplexMode(long mode) const;
	void SetComplexModeRange(float range) const;
	void SetContrastLimits(float low, float hight) const;
	void SetContrastMode(long mode) const;
	void SetContrastParameters(float bright, float contrast) const;
	void SetDisplayedLayers(long start, long end) const;
	void SetDoAutoSurvey(bool do_survey) const;
	void SetImageRect(float top, float left, float bottom, float right) const;
	void SetInputColorTable(const Image &clut) const;
	void SetIntensityTransformation(const Image &itt) const;
	void SetMinimumContrast(float contrast) const;
	void SetROISelected(const ROI &roi, bool select) const;
	void SetROISelectionStyle(const ROI &r, long style) const;
	void SetSurveyTechnique(long tech) const;
};
static ImageDisplay::StaticInit sImageDisplayStaticInit;




/*
** class LinePlotImageDisplay
*/

class LinePlotImageDisplay;

struct DMIntrinsicClassDesc_LinePlotImageDisplay
{
	typedef LinePlotImageDisplay                  final_type;
	typedef DM_LinePlotImageDisplayToken          token_type;
	typedef DM_LinePlotImageDisplayToken_1Ref     ret_token_type;
	static ulong                      num_refs;
	static GatanPlugIn::DM_ClassDesc *class_descriptor;
	static const char *class_name() { return "Gatan:DigitalMicrograph:LinePlotImageDisplay"; }
};


class LinePlotImageDisplay : public DMIntrinsicDerivedClassBaseT<DMIntrinsicClassDesc_LinePlotImageDisplay,DMIntrinsicClassDesc_ImageDisplay>
{
public:
	typedef LinePlotImageDisplay this_type;
	typedef DMIntrinsicDerivedClassBaseT<DMIntrinsicClassDesc_LinePlotImageDisplay,DMIntrinsicClassDesc_ImageDisplay> base_type;
public:
	LinePlotImageDisplay()                           : base_type() {}
	LinePlotImageDisplay( token_type dm_token_ )     : base_type( dm_token_ ) {}
	LinePlotImageDisplay( ret_token_type dm_token_ ) : base_type( dm_token_ ) {}
	LinePlotImageDisplay &operator=( token_type dm_token_in)     { assign( dm_token_in ); return *this; }
	LinePlotImageDisplay &operator=( ret_token_type dm_token_in) { assign( dm_token_in ); return *this; }

	long CountSlices() const;
	double GetBaseIntensity() const;
	void GetContrastLimits(float *lowLimit, float *highLimit) const;
	void GetDisplayedChannels(float *leftChannel, float *rightChannel) const;
	void GetDoAutoSurvey(bool *doAutoSurveyLow, bool *doAutoSurveyHigh) const;
	long GetSlice() const;
	void GetSliceComponentColor(long slice_index, long comp_index, double *r, double *g, double *b) const;
	long GetSliceDrawingStyle(long slice_index) const;
	void GetTrackingStyle(uint16 *track_style_x, uint16 *track_style_y) const;
	bool IsBackgroundOn() const;
	bool IsFilled() const;
	bool IsFrameOn() const;
	bool IsGridOn() const;
	void SetBackgroundOn(bool on) const;
	void SetBaseIntensity(double base_intensity) const;
	void SetContrastLimits(float lowLimit, float highLimit) const;
	void SetDisplayedChannels(float leftChannel, float rightChannel) const;
	void SetDoAutoSurvey(bool doAutoSurveyLow, bool doAutoSurveyHigh) const;
	void SetFilled(bool on) const;
	void SetFrameOn(bool on) const;
	void SetGridOn(bool on) const;
	void SetSlice(long slice) const;
	void SetSliceComponentColor(long slice_index, long comp_index, double r, double g, double b) const;
	void SetSliceDrawingStyle(long slice_index, long style) const;
	void SetTrackingStyle(uint16 track_style_x, uint16 track_style_y) const;
};
static LinePlotImageDisplay::StaticInit sLinePlotImageDisplayStaticInit;





/*
** class RasterImageDisplay
*/

class RasterImageDisplay;

struct DMIntrinsicClassDesc_RasterImageDisplay
{
	typedef RasterImageDisplay                  final_type;
	typedef DM_RasterImageDisplayToken          token_type;
	typedef DM_RasterImageDisplayToken_1Ref     ret_token_type;
	static ulong                      num_refs;
	static GatanPlugIn::DM_ClassDesc *class_descriptor;
	static const char *class_name() { return "Gatan:DigitalMicrograph:RasterImageDisplay"; }
};


class RasterImageDisplay : public DMIntrinsicDerivedClassBaseT<DMIntrinsicClassDesc_RasterImageDisplay,DMIntrinsicClassDesc_ImageDisplay>
{
public:
	typedef RasterImageDisplay this_type;
	typedef DMIntrinsicDerivedClassBaseT<DMIntrinsicClassDesc_RasterImageDisplay,DMIntrinsicClassDesc_ImageDisplay> base_type;
public:
	RasterImageDisplay()                           : base_type() {}
	RasterImageDisplay( token_type dm_token_ )     : base_type( dm_token_ ) {}
	RasterImageDisplay( ret_token_type dm_token_ ) : base_type( dm_token_ ) {}
	RasterImageDisplay &operator=( token_type dm_token_in)     { assign( dm_token_in ); return *this; }
	RasterImageDisplay &operator=( ret_token_type dm_token_in) { assign( dm_token_in ); return *this; }

	void AddThresholdToMask(const Image &mask, float top, float left, float bottom, float right) const;
	void GetThresholdLimits(float *low, float *high) const;
	bool IsThresholdOn() const;
	void SetThresholdLimits(float low, float high) const;
	void SetThresholdOn(bool on) const;
};
static RasterImageDisplay::StaticInit sRasterImageDisplayStaticInit;




/*
** class SurfacePlotImageDisplay
*/

class SurfacePlotImageDisplay;

struct DMIntrinsicClassDesc_SurfacePlotImageDisplay
{
	typedef SurfacePlotImageDisplay                  final_type;
	typedef DM_SurfacePlotImageDisplayToken          token_type;
	typedef DM_SurfacePlotImageDisplayToken_1Ref     ret_token_type;
	static ulong                      num_refs;
	static GatanPlugIn::DM_ClassDesc *class_descriptor;
	static const char *class_name() { return "Gatan:DigitalMicrograph:SurfacePlotImageDisplay"; }
};


class SurfacePlotImageDisplay : public DMIntrinsicDerivedClassBaseT<DMIntrinsicClassDesc_SurfacePlotImageDisplay,DMIntrinsicClassDesc_ImageDisplay>
{
public:
	typedef SurfacePlotImageDisplay this_type;
	typedef DMIntrinsicDerivedClassBaseT<DMIntrinsicClassDesc_SurfacePlotImageDisplay,DMIntrinsicClassDesc_ImageDisplay> base_type;
public:
	SurfacePlotImageDisplay()                           : base_type() {}
	SurfacePlotImageDisplay( token_type dm_token_ )     : base_type( dm_token_ ) {}
	SurfacePlotImageDisplay( ret_token_type dm_token_ ) : base_type( dm_token_ ) {}
	SurfacePlotImageDisplay &operator=( token_type dm_token_in)     { assign( dm_token_in ); return *this; }
	SurfacePlotImageDisplay &operator=( ret_token_type dm_token_in) { assign( dm_token_in ); return *this; }

	void GetCubeAxes(float *x_axis_x, float *x_axis_y, float *y_axis_x, float *y_axis_y, float *z_axis) const;
	void GetCubePoint(long which_point, float *x, float *y) const;
	bool IsShadingOn() const;
	void SetCubeAxes(float x_axis_x, float x_axis_y, float y_axis_x, float y_axis_y, float z_axis) const;
	void SetShadingOn(bool on) const;
};
static SurfacePlotImageDisplay::StaticInit sSurfacePlotImageDisplayStaticInit;




/*
** class ImageDocument
*/

class ImageDocument;

struct DMIntrinsicClassDesc_ImageDocument
{
	typedef ImageDocument                  final_type;
	typedef DM_ImageDocumentToken          token_type;
	typedef DM_ImageDocumentToken_1Ref     ret_token_type;
	static ulong                      num_refs;
	static GatanPlugIn::DM_ClassDesc *class_descriptor;
	static const char *class_name() { return "Gatan:DigitalMicrograph:ImageDocument"; }
};

class ImageDocument : public DMIntrinsicClassBaseT<DMIntrinsicClassDesc_ImageDocument>
{
public:
	typedef ImageDocument this_type;
	typedef DMIntrinsicClassBaseT<DMIntrinsicClassDesc_ImageDocument> base_type;
public:
	ImageDocument() : base_type() { }
	ImageDocument( token_type dm_token_in )     : base_type( dm_token_in ) {}
	ImageDocument( ret_token_type dm_token_in ) : base_type( dm_token_in ) {}
	ImageDocument &operator=( token_type dm_token_in)     { assign( dm_token_in ); return *this; }
	ImageDocument &operator=( ret_token_type dm_token_in) { assign( dm_token_in ); return *this; }

	void AddImage(const Image &image) const;
	ImageDisplay AddImageDisplay(const Image &image, long displayType) const;
	void AddToUserInterface() const;
	void Clean() const;
	ImageDocument Clone(bool doDeepCopy) const;
	void Close(bool saving) const;
	long CountImages() const;
	Image CreateRGBImageFromDocument(long width, long height, long extract_style, long constraints) const;
	void DeleteImage(const Image &image) const;
	bool DoesImageWithIDExist(long id) const;
	void EnsurePlacedOnPage() const;
	long GetAsPICT() const;
	Component GetComponentByID(long id) const;
	long GetID() const;
	Image GetImage(long position) const;
	Image GetImageByID(long id) const;
	ImageDisplay GetImageModeDisplay() const;
	void GetMinimumPointSize(float *x, float *y) const;
	String GetName() const;
	void GetPageBounds(float *top, float *left, float *bottom, float *right) const;
	void GetPageResolution_72dpi(float *horz, float *vert) const;
	void GetPageResolution_Printer(float *horz, float *vert) const;
	void GetPaperBounds(float *top, float *left, float *bottom, float *right) const;
	void GetPreferredViewRect(float *top, float *left, float *bottom, float *right) const;
	void GetReferencePointSize(float *x, float *y) const;
	Component GetRootComponent() const;
	TagGroup GetTagGroup() const;
	void GetUnzoomedPointSize(float *x, float *y) const;
	void GetViewExtent(float *top, float *left, float *bottom, float *right) const;
	void GetViewToWindowTransform(float *off_x, float *off_y, float *scale_x, float *scale_y) const;
	void GetVisibleViewRect(float *top, float *left, float *bottom, float *right) const;
	Window GetWindow() const;
	bool HasBeenPlacedOnPage() const;
	void Hide() const;
	bool IsInImageMode() const;
	bool IsInPageMode() const;
	void MaximizeRectInView(float top, float left, float bottom, float right) const;
	bool Print() const;
	void RemoveFromUserInterface() const;
	void SaveToFile(const char *handler, const char *fileName) const;
	void SetCurrentViewAsUnzoomed() const;
	void SetName(const String &name) const;
	void SetRectInView(float v_t, float v_l, float v_b, float v_r, float w_t, float w_l, float w_b, float w_r) const;
	Window Show() const;
	Window ShowAtPosition(long x, long y) const;
	Window ShowAtRect(long top, long left, long bottom, long right) const;
	void SwitchToImageMode(const ImageDisplay &imgDisp) const;
	void SwitchToPageMode() const;
	void UpdateDisplay() const;
};
static ImageDocument::StaticInit sImageDocumentStaticInit;




/*
** class TagGroup
*/

class TagGroup;

struct DMIntrinsicClassDesc_TagGroup
{
	typedef TagGroup                  final_type;
	typedef DM_TagGroupToken          token_type;
	typedef DM_TagGroupToken_1Ref     ret_token_type;
	static ulong                      num_refs;
	static GatanPlugIn::DM_ClassDesc *class_descriptor;
	static const char *class_name() { return "Gatan:DigitalMicrograph:TagGroup"; }
};

class TagGroup : public DMIntrinsicClassBaseT<DMIntrinsicClassDesc_TagGroup>
{
public:
	typedef TagGroup this_type;
	typedef DMIntrinsicClassBaseT<DMIntrinsicClassDesc_TagGroup> base_type;
public:
	TagGroup() : base_type() { }
	TagGroup( token_type dm_token_in )     : base_type( dm_token_in ) {}
	TagGroup( ret_token_type dm_token_in ) : base_type( dm_token_in ) {}
	TagGroup &operator=( token_type dm_token_in)     { assign( dm_token_in ); return *this; }
	TagGroup &operator=( ret_token_type dm_token_in) { assign( dm_token_in ); return *this; }

	TagGroup AddLabeledTagGroup(const char *label, const TagGroup &newGroup) const;
	TagGroup AddTagGroupAfter(long ref_index, const TagGroup &newGroup) const;
	TagGroup AddTagGroupAtBeginning(const TagGroup &newGroup) const;
	TagGroup AddTagGroupAtEnd(const TagGroup &newGroup) const;
	TagGroup AddTagGroupBefore(long ref_index, const TagGroup &newGroup) const;
	TagGroup Clone() const;
	long CopyTag(const TagGroup &srcGroup, long srcIndex) const;
	void CopyTagsFrom(const TagGroup &srcGroup) const;
	void CopyTagToIndex(long dstIndex, const TagGroup &srcGroup, long srcIndex) const;
	long CountTags() const;
	TagGroup CreateGroupTagAfter(long ref_index) const;
	TagGroup CreateGroupTagAtBeginning() const;
	TagGroup CreateGroupTagAtEnd() const;
	TagGroup CreateGroupTagBefore(long ref_index) const;
	TagGroup CreateListTagAfter(long ref_index) const;
	TagGroup CreateListTagAtBeginning() const;
	TagGroup CreateListTagAtEnd() const;
	TagGroup CreateListTagBefore(long ref_index) const;
	TagGroup CreateNewLabeledGroup(const char *label) const;
	TagGroup CreateNewLabeledList(const char *label) const;
	long CreateNewLabeledTag(const char *label) const;
	long CreateNewTagAfter(long ref_index) const;
	long CreateNewTagAtBeginning() const;
	long CreateNewTagAtEnd() const;
	long CreateNewTagBefore(long ref_index) const;
	void DeleteAllTags() const;
	void DeleteTagWithIndex(long index) const;
	void DeleteTagWithLabel(const char *tagPath) const;
	bool DoesTagExist(const char *tagPath) const;
	void ExecuteScriptGroup(const char *form) const;
	bool GetIndexedTagAsArray(ulong index, const Image &image) const;
	bool GetIndexedTagAsBoolean(long index, bool *val) const;
	bool GetIndexedTagAsDouble(long index, double *number) const;
	bool GetIndexedTagAsDoubleComplex(long index, complex128_t *c) const;
	bool GetIndexedTagAsEightBitColor(long index, rgba_uint8_os_t *c) const;
	bool GetIndexedTagAsFloat(long index, float *number) const;
	bool GetIndexedTagAsFloatComplex(long index, complex128_t *c) const;
	bool GetIndexedTagAsFloatPoint(long index, float *x, float *y) const;
	bool GetIndexedTagAsFloatRect(long index, float *t, float *l, float *b, float *r) const;
	bool GetIndexedTagAsLong(long index, long *number) const;
	bool GetIndexedTagAsLongPoint(long index, long *x, long *y) const;
	bool GetIndexedTagAsLongRect(long index, long *t, long *l, long *b, long *r) const;
	bool GetIndexedTagAsShort(long index, short *number) const;
	bool GetIndexedTagAsShortPoint(long index, short *x, short *y) const;
	bool GetIndexedTagAsShortRect(long index, short *t, short *l, short *b, short *r) const;
	template <typename string_type>
		bool GetIndexedTagAsString(long index, string_type &str) const
		{
			bool succ = false;
			String dm_str;
			if ( TagGroupGetIndexedTagAsString( *this, index, dm_str ) )
			{
				copy_dm_string( dm_str, str );
				succ = true;
			}
			return succ;
		}
	bool GetIndexedTagAsTagGroup(long index, TagGroup &subGroup) const;
	bool GetIndexedTagAsText(long index, String &str) const;
	bool GetIndexedTagAsUInt16(long index, uint16 *number) const;
	bool GetIndexedTagAsUInt32(long index, ulong *number) const;
	TagGroup GetOrCreateTagGroup(const char *tagPath) const;
	TagGroup GetOrCreateTagList(const char *tagPath) const;
	long GetSeeds() const;
	bool GetTagAsArray(const char *tagPath, const Image &image) const;
	bool GetTagAsBoolean(const char *tagPath, bool *val) const;
	bool GetTagAsDouble(const char *tagPath, double *number) const;
	bool GetTagAsDoubleComplex(const char *tagPath, complex128_t *c) const;
	bool GetTagAsEightBitColor(const char *tagPath, rgba_uint8_os_t *c) const;
	bool GetTagAsFloat(const char *tagPath, float *number) const;
	bool GetTagAsFloatComplex(const char *tagPath, complex128_t *c) const;
	bool GetTagAsFloatPoint(const char *tagPath, float *x, float *y) const;
	bool GetTagAsFloatRect(const char *tagPath, float *t, float *l, float *b, float *r) const;
	bool GetTagAsLong(const char *tagPath, long *number) const;
	bool GetTagAsLongPoint(const char *tagPath, long *x, long *y) const;
	bool GetTagAsLongRect(const char *tagPath, long *t, long *l, long *b, long *r) const;
	bool GetTagAsRGBUInt16(long index, uint16 *r, uint16 *g, uint16 *b) const;
	bool GetTagAsRGBUInt16(const char *tagPath, uint16 *r, uint16 *g, uint16 *b) const;
	bool GetTagAsShort(const char *tagPath, short *number) const;
	bool GetTagAsShortPoint(const char *tagPath, short *x, short *y) const;
	bool GetTagAsShortRect(const char *tagPath, short *t, short *l, short *b, short *r) const;
	template <typename string_type>
		bool GetTagAsString(const char *tagPath, string_type &str) const
		{
			bool succ = false;
			String dm_str;
			if ( TagGroupGetTagAsString( *this, tagPath, dm_str ) )
			{
				copy_dm_string( dm_str, str );
				succ = true;
			}
			return succ;
		}
	bool GetTagAsTagGroup(const char *tagPath, TagGroup &subGroup) const;
	bool GetTagAsText(const char *tagPath, String &str) const;
	bool GetTagAsUInt16(const char *tagPath, uint16 *number) const;
	bool GetTagAsUInt32(const char *tagPath, ulong *number) const;
	String GetTagLabel(long index) const;
	long GetTagSize(long index) const;
	long GetTagType(long index, long type_index) const;
	long GetTagTypeLength(long index) const;
	bool HasChangedSince(long seeds) const;
	void InsertTagAsArray(ulong ref_index, const Image &image) const;
	void InsertTagAsBoolean(long ref_index, bool val) const;
	void InsertTagAsDouble(long ref_index, double number) const;
	void InsertTagAsDoubleComplex(long ref_index, const complex128_t &c) const;
	void InsertTagAsEightBitColor(long ref_index, rgba_uint8_os_t c) const;
	void InsertTagAsFloat(long ref_index, float number) const;
	void InsertTagAsFloatComplex(long ref_index, const complex128_t &c) const;
	void InsertTagAsFloatPoint(long ref_index, float x, float y) const;
	void InsertTagAsFloatRect(long ref_index, float t, float l, float b, float r) const;
	void InsertTagAsLong(long ref_index, long number) const;
	void InsertTagAsLongPoint(long ref_index, long x, long y) const;
	void InsertTagAsLongRect(long ref_index, long t, long l, long b, long r) const;
	void InsertTagAsRGBUInt16(long ref_index, uint16 r, uint16 g, uint16 b) const;
	void InsertTagAsShort(long ref_index, short number) const;
	void InsertTagAsShortPoint(long ref_index, short x, short y) const;
	void InsertTagAsShortRect(long ref_index, short t, short l, short b, short r) const;
	void InsertTagAsString(long ref_index, const String &s) const;
	void InsertTagAsTagGroup(long ref_index, const TagGroup &subGroup) const;
	void InsertTagAsText(long ref_index, const String &s) const;
	void InsertTagAsUInt16(long ref_index, uint16 number) const;
	void InsertTagAsUInt32(long ref_index, ulong number) const;
	bool IsList() const;
	bool IsOpen() const;
	bool LoadFromFile(const String &path) const;
	bool LoadFromFileWithLabel(const String &path, String &label) const;
	void MarkAsChanged() const;
	Window OpenBrowserWindow(bool isFileBased) const;
	long ParseAndCreateTagPath(const String &tagPath, TagGroup &parentGroup, String &label) const;
	long ParseTagPath(const String &tagPath, TagGroup &parentGroup, String &label) const;
	void ReleaseSeeds(long seeds) const;
	void ReplaceTagsWithCopy(const TagGroup &srcGroup) const;
	void SaveToFile(const String &path) const;
	void SaveToFileWithLabel(const String &path, const String &label) const;
	void SetIndexedTagAsArray(ulong index, const Image &image) const;
	void SetIndexedTagAsBoolean(long index, bool val) const;
	void SetIndexedTagAsDouble(long index, double number) const;
	void SetIndexedTagAsDoubleComplex(long index, const complex128_t &c) const;
	void SetIndexedTagAsEightBitColor(long index, rgba_uint8_os_t c) const;
	void SetIndexedTagAsFloat(long index, float number) const;
	void SetIndexedTagAsFloatComplex(long index, const complex128_t &c) const;
	void SetIndexedTagAsFloatPoint(long index, float x, float y) const;
	void SetIndexedTagAsFloatRect(long index, float t, float l, float b, float r) const;
	void SetIndexedTagAsLong(long index, long number) const;
	void SetIndexedTagAsLongPoint(long index, long x, long y) const;
	void SetIndexedTagAsLongRect(long index, long t, long l, long b, long r) const;
	void SetIndexedTagAsRGBUInt16(long index, uint16 r, uint16 g, uint16 b) const;
	void SetIndexedTagAsShort(long index, short number) const;
	void SetIndexedTagAsShortPoint(long index, short x, short y) const;
	void SetIndexedTagAsShortRect(long index, short t, short l, short b, short r) const;
	void SetIndexedTagAsString(long index, const String &s) const;
	void SetIndexedTagAsTagGroup(long index, const TagGroup &subGroup) const;
	void SetIndexedTagAsText(long index, const String &s) const;
	void SetIndexedTagAsUInt16(long index, uint16 number) const;
	void SetIndexedTagAsUInt32(long index, ulong number) const;
	void SetIsOpen(bool is_open) const;
	void SetTagAsArray(const char *tagPath, const Image &image) const;
	void SetTagAsBoolean(const char *tagPath, bool val) const;
	void SetTagAsDouble(const char *tagPath, double number) const;
	void SetTagAsDoubleComplex(const char *tagPath, const complex128_t &c) const;
	void SetTagAsEightBitColor(const char *tagPath, rgba_uint8_os_t c) const;
	void SetTagAsFloat(const char *tagPath, float number) const;
	void SetTagAsFloatComplex(const char *tagPath, const complex128_t &c) const;
	void SetTagAsFloatPoint(const char *tagPath, float x, float y) const;
	void SetTagAsFloatRect(const char *tagPath, float t, float l, float b, float r) const;
	void SetTagAsLong(const char *tagPath, long number) const;
	void SetTagAsLongPoint(const char *tagPath, long x, long y) const;
	void SetTagAsLongRect(const char *tagPath, long t, long l, long b, long r) const;
	void SetTagAsRGBUInt16(const char *tagPath, uint16 r, uint16 g, uint16 b) const;
	void SetTagAsShort(const char *tagPath, short number) const;
	void SetTagAsShortPoint(const char *tagPath, short x, short y) const;
	void SetTagAsShortRect(const char *tagPath, short t, short l, short b, short r) const;
	void SetTagAsString(const char *tagPath, const String &s) const;
	void SetTagAsTagGroup(const char *tagPath, const TagGroup &subGroup) const;
	void SetTagAsText(const char *tagPath, const String &s) const;
	void SetTagAsUInt16(const char *tagPath, uint16 number) const;
	void SetTagAsUInt32(const char *tagPath, ulong number) const;
	void SetTagRGBBitmap(const char *tagPath, const Image &image) const;
};
static TagGroup::StaticInit sTagGroupStaticInit;



/*
** class Window
*/

class Window;

struct DMIntrinsicClassDesc_Window
{
	typedef Window                    final_type;
	typedef DM_WindowToken            token_type;
	typedef DM_WindowToken_1Ref       ret_token_type;
	static ulong                      num_refs;
	static GatanPlugIn::DM_ClassDesc *class_descriptor;
	static const char *class_name() { return "Gatan:DigitalMicrograph:Window"; }
};

class Window : public DMIntrinsicClassBaseT<DMIntrinsicClassDesc_Window>
{
public:
	typedef Window this_type;
	typedef DMIntrinsicClassBaseT<DMIntrinsicClassDesc_Window> base_type;
public:
	Window() : base_type() { }
	Window( token_type dm_token_in )     : base_type( dm_token_in ) {}
	Window( ret_token_type dm_token_in ) : base_type( dm_token_in ) {}
	Window &operator=( token_type dm_token_in)     { assign( dm_token_in ); return *this; }
	Window &operator=( ret_token_type dm_token_in) { assign( dm_token_in ); return *this; }

	void Close(bool verify) const;
	void GetContentBounds(long *top, long *left, long *bottom, long *right) const;
	void GetContentPosition(long *x, long *y) const;
	void GetContentSize(long *x, long *y) const;
	void GetFrameBounds(long *top, long *left, long *bottom, long *right) const;
	void GetFramePosition(long *x, long *y) const;
	void GetFrameSize(long *x, long *y) const;
	void GetMousePosition(long *x, long *y) const;
	String GetTitle() const;
	long GetType() const;
	void Hide() const;
	bool IsOpen() const;
	bool IsShown() const;
	void Select() const;
	void SendBehind(const Window &behind_window) const;
	void SetContentBounds(long top, long left, long bottom, long right) const;
	void SetContentPosition(long x, long y) const;
	void SetContentSize(long x, long y) const;
	void SetFrameBounds(long top, long left, long bottom, long right) const;
	void SetFramePosition(long x, long y) const;
	void SetFrameSize(long x, long y) const;
	void SetTitle(const String &title) const;
	void Show() const;
	void Update() const;
};
static Window::StaticInit sWindowStaticInit;




/*
** class String
*/


class String;

struct DMIntrinsicClassDesc_String
{
	typedef String                    final_type;
	typedef DM_StringToken            token_type;
	typedef DM_StringToken_1Ref       ret_token_type;	
	static ulong                      num_refs;
	static GatanPlugIn::DM_ClassDesc *class_descriptor;
	static const char *class_name() { return "Gatan:DigitalMicrograph:String"; }
};

#include <cstring>
#ifdef _GATAN_USE_STL_STRING
#include <string>
#endif // _GATAN_USE_STL_STRING

class String : public DMIntrinsicClassBaseT<DMIntrinsicClassDesc_String>
{
public:
	typedef String this_type;
	typedef DMIntrinsicClassBaseT<DMIntrinsicClassDesc_String> base_type;
public:
	String() : base_type() { }
	String( token_type dm_token_in )     : base_type( dm_token_in ) {}
	String( ret_token_type dm_token_in ) : base_type( dm_token_in ) {}
#if !( defined( _GATAN_COMPILER_VISUAL_CPP ) && ( _GATAN_COMPILER_VERSION < 1300) )
	String( const String &str_2 ) : base_type( str_2 ) {}
#endif // defined( _GATAN_COMPILER_VISUAL_CPP )...
	String( const char *str, Gatan::ulong length )                        : base_type() { construct( 0, Gatan::char_range(str, str+length) ); }
	String( const char *str )                                             : base_type() { construct( 0, Gatan::char_range(str) ); }
	String( char *str )                                                   : base_type() { construct( 0, Gatan::char_range(str) ); }
	String( Gatan::ulong encoding, const char *str, Gatan::ulong length ) : base_type() { construct( encoding, Gatan::char_range(str, str+length) ); }
	String( Gatan::ulong encoding, const Gatan::char_range &str ) : base_type() { construct( encoding, str ); }
	template<typename string_type> String( const string_type &str )
		: base_type()
	{
		construct_dm_string( str, *this );
	}

	void construct( token_type dm_token_in )                      { dm_token = dm_token_in; add_ref_ptr( dm_token ); }
	void construct( const Gatan::char_range &str )                { construct( 0, str ); }
	void construct( Gatan::ulong encoding, const Gatan::char_range &str );
	Gatan::ulong copy_proxy( Gatan::ulong encoding, const Gatan::char_string_proxy &str ) const;
	template<typename string_type> Gatan::ulong copy( string_type &str ) const
	{
		char_range_traits<string_type>::string_proxy_type str_proxy;
		construct_string_proxy( str, str_proxy );
		return copy_proxy( 0, str_proxy );
	}
	template<typename string_type> Gatan::ulong copy( Gatan::ulong encoding, string_type &str ) const
	{
		char_range_traits<string_type>::string_proxy_type str_proxy;
		construct_string_proxy( str, str_proxy );
		return copy_proxy( encoding, str_proxy );
	}
#ifdef _GATAN_COMPILER_VISUAL_CPP
	void construct( const Gatan::uint16_char_range &str );
	String( const Gatan::uint16 *str, Gatan::ulong length )  : base_type() { construct( Gatan::uncchar_range((const uncchar *) str, (const uncchar *) str+length ) ); }
	Gatan::ulong copy_proxy( Gatan::ulong encoding, const Gatan::uint16_char_string_proxy &str ) const;
	Gatan::ulong copy( Gatan::uint16 *buffer, Gatan::ulong buffer_length ) const;

	#if (_GATAN_COMPILER_VERSION >= 1300 )
	void construct( const Gatan::__wchar_t_char_range &str );
	String( const __wchar_t *str, Gatan::ulong length )      : base_type() { construct( Gatan::uncchar_range((const uncchar *) str, (const uncchar *) str+length ) ); }
	Gatan::ulong copy_proxy( Gatan::ulong encoding, const Gatan::__wchar_t_char_string_proxy &str ) const;
	Gatan::ulong copy( __wchar_t *buffer, Gatan::ulong buffer_length ) const;
	#endif // (_GATAN_COMPILER_VERSION >= 1300 )
#else
	String( const Gatan::uncchar *str, Gatan::ulong length )       : base_type() { construct( Gatan::uncchar_range(str, str+length ) ); }
	void construct( const Gatan::uncchar_range &str );
	Gatan::ulong copy_proxy( Gatan::ulong encoding, const Gatan::uncchar_string_proxy &str ) const;
	Gatan::ulong copy( Gatan::uncchar *buffer, Gatan::ulong buffer_length ) const;
#endif // _GATAN_COMPILER_VISUAL_CPP


	Gatan::ulong copy( char *buffer, Gatan::ulong buffer_length ) const;
	Gatan::ulong copy( Gatan::ulong encoding, char *buffer, Gatan::ulong buffer_length ) const;

#ifdef _GATAN_USE_STL_STRING
	operator std::string() const                              { std::string str; copy( 0, str ); return str; }
	std::string get_string( Gatan::ulong encoding = 0 ) const { std::string str; copy( encoding, str ); return str; }
#endif // _GATAN_USE_STL_STRING

	String Append(const String &s2);
	String Append(ulong ch, ulong encoding_id);
	long Compare(const String &s2) const;
};
static String::StaticInit sStringStaticInit;

template <typename string_type> void construct_dm_string( const string_type &src_str, String &dm_str )
{
	char_range_traits<string_type>::range_type src_char_range;
	construct_char_range( src_str, src_char_range );
	dm_str.construct( src_char_range );
}
inline void construct_dm_string( const String &src_str, String &dm_str )
{
	dm_str.assign( src_str );
}

template <typename string_type> void copy_dm_string( const String &src_str, string_type &str )
{
	char_range_traits<string_type>::string_proxy_type str_proxy;
	construct_string_proxy( str, str_proxy );
	src_str.copy_proxy( 0, str_proxy );
}
inline void copy_dm_string( const String &src_str, String &dst_str )
{
	dst_str.assign( src_str );
}

/*
** class ScriptObject
*/


class ScriptObject;

struct DMIntrinsicClassDesc_ScriptObject
{
	typedef ScriptObject              final_type;
	typedef DM_ScriptObjectToken      token_type;
	typedef DM_ScriptObjectToken_1Ref ret_token_type;	
	static ulong                      num_refs;
	static GatanPlugIn::DM_ClassDesc *class_descriptor;
	static const char *class_name() { return "Gatan:DigitalMicrograph:ScriptObject"; }
};

class ScriptObject : public DMIntrinsicClassBaseT<DMIntrinsicClassDesc_ScriptObject>
{
public:
	typedef ScriptObject this_type;
	typedef DMIntrinsicClassBaseT<DMIntrinsicClassDesc_ScriptObject> base_type;
public:
	ScriptObject() : base_type() { }
	ScriptObject( token_type dm_token_in ) : base_type( dm_token_in ) {}
	ScriptObject( ret_token_type dm_token_in ) : base_type(dm_token_in) {}
	ScriptObject &operator=( token_type dm_token_in)     { assign( dm_token_in ); return *this; }
	ScriptObject &operator=( ret_token_type dm_token_in) { assign( dm_token_in ); return *this; }

	void Dispatch( const Function &method, Gatan::ulong num_args, Gatan::PlugIn::DM_Variant *args, Gatan::ulong obj_index ) const;
	ulong GetClassToken(const String &class_name) const;
	long GetID() const;
	Function LookupMethod(const Function &meth_abs, const char *class_name) const;
	Function LookupMethod(const Function &meth_abs) const;
};
static ScriptObject::StaticInit sScriptObjectStaticInit;



/*
** class Throwable
*/

class Throwable;

struct DMIntrinsicClassDesc_Throwable
{
	typedef Throwable                 final_type;
	typedef DM_ThrowableToken         token_type;
	typedef DM_ThrowableToken_1Ref    ret_token_type;	
	static ulong                      num_refs;
	static GatanPlugIn::DM_ClassDesc *class_descriptor;
	static const char *class_name() { return "Gatan:DigitalMicrograph:Throwable"; }
};

class Throwable : public DMIntrinsicClassBaseT<DMIntrinsicClassDesc_Throwable>
{
public:
	typedef Throwable this_type;
	typedef DMIntrinsicClassBaseT<DMIntrinsicClassDesc_Throwable> base_type;
public:
	Throwable() : base_type() { }
	Throwable( token_type dm_token_in )     : base_type( dm_token_in ) {}
	Throwable( ret_token_type dm_token_in ) : base_type(dm_token_in ) {}
	Throwable &operator=( token_type dm_token_in)     { assign( dm_token_in ); return *this; }
	Throwable &operator=( ret_token_type dm_token_in) { assign( dm_token_in ); return *this; }
};
static Throwable::StaticInit sThrowableStaticInit;




/*
** class Function
*/

class Function;

struct DMIntrinsicClassDesc_Function
{
	typedef Function                  final_type;
	typedef DM_FunctionToken          token_type;
	typedef DM_FunctionToken_1Ref     ret_token_type;
	static ulong                      num_refs;
	static GatanPlugIn::DM_ClassDesc *class_descriptor;
	static const char *class_name() { return "Gatan:DigitalMicrograph:Function"; }
};

class Function : public DMIntrinsicClassBaseT<DMIntrinsicClassDesc_Function>
{
public:
	typedef Function this_type;
	typedef DMIntrinsicClassBaseT<DMIntrinsicClassDesc_Function> base_type;
public:
	Function() : base_type() { }
	Function( token_type dm_token_in )     : base_type( dm_token_in ) {}
	Function( ret_token_type dm_token_in ) : base_type( dm_token_in ) {}
	Function &operator=( token_type dm_token_in)     { assign( dm_token_in ); return *this; }
	Function &operator=( ret_token_type dm_token_in) { assign( dm_token_in ); return *this; }

	void Call( Gatan::ulong num_args, Gatan::PlugIn::DM_Variant *args );
	ulong CountParameters() const;
	String GenerateStub(bool include_body, ulong version) const;
};
static Function::StaticInit sFunctionStaticInit;

/*
** class ScriptClass
*/

class ScriptClass;

struct DMIntrinsicClassDesc_ScriptClass
{
	typedef ScriptClass               final_type;
	typedef DM_ScriptClassToken       token_type;
	typedef DM_ScriptClassToken_1Ref  ret_token_type;
	static ulong                      num_refs;
	static GatanPlugIn::DM_ClassDesc *class_descriptor;
	static const char *class_name() { return "Gatan:DigitalMicrograph:ScriptClass"; }
};

class ScriptClass : public DMIntrinsicClassBaseT<DMIntrinsicClassDesc_ScriptClass>
{
public:
	typedef ScriptClass this_type;
	typedef DMIntrinsicClassBaseT<DMIntrinsicClassDesc_ScriptClass> base_type;
public:
	ScriptClass() : base_type() { }
	ScriptClass( token_type dm_token_in )     : base_type( dm_token_in ) {}
	ScriptClass( ret_token_type dm_token_in ) : base_type( dm_token_in ) {}
	ScriptClass &operator=( token_type dm_token_in)     { assign( dm_token_in ); return *this; }
	ScriptClass &operator=( ret_token_type dm_token_in) { assign( dm_token_in ); return *this; }

	void Call( Gatan::ulong num_args, Gatan::PlugIn::DM_Variant *args );
	ulong CountParameters() const;
	String GenerateStub(bool include_body, ulong version) const;
};
static ScriptClass::StaticInit sScriptClassStaticInit;

	} // namespace DM
} // namespace Gatan



/*
** DM 3.7 Script functions
*/

namespace Gatan
{
	namespace DM
	{
		uint32 ApplicationAddEventListener( const ScriptObject &listener, const String &event_handler_desc );

		void ApplicationRemoveEventListener( uint32 listener_id );

		uint32 ImageDisplayAddEventListener( const ImageDisplay &img_disp, const ScriptObject &listener, const String &event_handler_desc );
		void ImageDisplayRemoveEventListener( const ImageDisplay &img_disp, uint32 listener_id );

		uint32 ImageDisplayAddKeyHandler( const ImageDisplay &img_disp, const ScriptObject &listener, const String &event_handler_desc );
		void ImageDisplayRemoveKeyHandler( const ImageDisplay &img_disp, uint32 listener_id );
		bool MatchesKeyDescriptor( const ScriptObject &keystroke, const String &key_name );

		uint32 WindowAddWindowListener( const Window &window, const ScriptObject &listener, const String &event_handler_desc );
		void WindowRemoveWindowListener( const Window &window, uint32 listener_id );

		uint32 ImageAddEventListener( const Image &img, const ScriptObject &listener, const String &event_handler_desc );
		void ImageRemoveEventListener( const Image &img, uint32 listener_id );

		bool GetApplicationDirectory( const String &dir_name, bool create_if_necessary, String &dir_path );
	}
}

/*
** DM 3.8 Script functions
*/

namespace Gatan
{
	namespace DM
	{
		uint32 CountImageDisplays( );
		uint32 CountImageDisplays( const Image &argument_1 );

		Window ShowImage( const Image &img );
		Window ShowImage( const Image &img, ImageDisplay &img_disp );
		Window ShowImage( const Image &img, ImageDisplay &img_disp, ImageDocument &img_doc );
		Window ShowImageDisplay( const ImageDisplay &img_disp );
		Window ShowImageDisplay( const ImageDisplay &img_disp, ImageDocument &img_doc );

		ImageDisplay GetNthImageDisplay( uint32 index );
		ImageDisplay GetNthImageDisplay( uint32 index, ImageDocument &img_doc );
		ImageDisplay GetNthImageDisplay( uint32 index, ImageDocument &img_doc, Window &img_win );
		ImageDisplay GetNthImageDisplay( const Image &img, uint32 index );
		ImageDisplay GetNthImageDisplay( const Image &img, uint32 index, ImageDocument &img_doc );
		ImageDisplay GetNthImageDisplay( const Image &img, uint32 index, ImageDocument &img_doc, Window &img_win );

		ImageDisplay NewImageDisplay( const Image &img, const String &display_type );
		ImageDisplay AddImageDisplay( const  int &imgDoc, const ImageDisplay &img_disp );
		ImageDisplay ImageDocumentAddImageDisplay( const ImageDocument &img_doc, const Image &img, const String &img_disp_type_name );

		ScriptObject ImageDisplayAddImage( const ImageDisplay &img_disp, const Image &image, const String &label );
		ImageDisplay ImageDisplayChangeDisplayType( const ImageDisplay &imgDisp, const String &new_display_type );

		uint32 ImageDisplayCountSlices( const ImageDisplay &id );
		bool ImageDisplayFindSliceIndexById( const ImageDisplay &id, const ScriptObject &slice_id, uint32 *slice_index );
		ScriptObject ImageDisplayGetSliceIdByIndex( const ImageDisplay &id, uint32 slice_index );
		ScriptObject ImageDisplayGetSliceIdByLabel( const ImageDisplay &id, const String &slice_label );
		bool ImageDisplayContainsSliceWithId( const ImageDisplay &img_disp, const ScriptObject &slice_id );
		String ImageDisplayGetSliceLabelById( const ImageDisplay &img_disp, const ScriptObject &slice_id );
		void ImageDisplaySetSliceLabelById( const ImageDisplay &img_disp, const ScriptObject &slice_id, const String &label );
		String ImageDisplayGetFullSliceLabelById( const ImageDisplay &img_disp, const ScriptObject &slice_id );
		bool ImageDisplayFindSliceIdByLabel( const ImageDisplay &img_disp, const String &slice_label, ScriptObject &slice_id );

		ScriptObject ImageDisplayGetCalibrationSlice( const ImageDisplay &img_disp );
		void ImageDisplaySetCalibrationSlice( const ImageDisplay &img_disp, const ScriptObject &slice_id );
		ScriptObject ImageDisplayGetSinglePrimarySlice( const ImageDisplay &id );
		bool ImageDisplayIsSliceSelected( const ImageDisplay &id, const ScriptObject &slice_id );
		void ImageDisplaySetSliceSelected( const ImageDisplay &id, const ScriptObject &slice_id, bool is_selected );
		bool ImageDisplayIsSliceVisible( const ImageDisplay &id, const ScriptObject &slice_id );
		void ImageDisplaySetSliceVisible( const ImageDisplay &id, const ScriptObject &slice_id, bool is_visible );
		bool ImageDisplayDeleteSliceWithId( const ImageDisplay &id, const ScriptObject &slice_id );

		Image ImageDisplayGetSliceImageById( const ImageDisplay &img_disp, const ScriptObject &slice_id );
		Image ImageDisplayGetSliceImageByLabel( const ImageDisplay &img_disp, const String &slice_label );
		Image ImageDisplayGetSliceImageByIndex( const ImageDisplay &img_disp, uint32 slice_index );
		Image ImageDisplayGetSliceImageById( const ImageDisplay &img_disp, const ScriptObject &slice_id, const ROI &r );
		Image ImageDisplayGetSliceImageByLabel( const ImageDisplay &img_disp, const String &slice_label, const ROI &r );
		Image ImageDisplayGetSliceImageByIndex( const ImageDisplay &img_disp, uint32 slice_index, const ROI &r );

		void ImageDisplaySetIntensityLabel( const ImageDisplay &img_disp, const String &label );
		void ImageDisplaySetDimensionLabel( const ImageDisplay &img_disp, uint32 i_dim, const String &label );
		String ImageDisplayGetIntensityLabel( const ImageDisplay &img_disp );
		String ImageDisplayGetDimensionLabel( const ImageDisplay &img_disp, uint32 i_dim );
	}
}

#endif // _GATAN_PLUGIN_DIGITALMICROGRAPH_FUNCTIONS
