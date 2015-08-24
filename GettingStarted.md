Dimpy Getting Started Instructions
==================================

Installation
============

*MFM 2015-08-22*

Currently for 32-bit DM1 and 32-bit Python 2.7

1. Download python2.7 (WinPython recommended)
2. Copy `0_DimpyLoader.dll` and `DimpyMain.dll` to DM plugin folder
3. We need to set some reigstry values so that the plugins can find the Python folder
this should be automated in the future:
 
 - Set **HKCU\Software\DimPy\PythonPath** to the location of `python27.dll`. 
   If using WinPython, will be something like `path\WinPython-32bit-2.7.10.2\python-2.7.10`
   
4. Run DM. Make sure you don't get any errors loading DimpyMain or 0_DimpyLoader DLLs. You should see the following in the results window:

````
DimpyLoader: Loaded Python library!
````

Usage
=====

Start DM and select **Open Console** from the **DimPy** menu.

A console window should open with a python prompt. Check this works:

```
>>> 4+6
10
>>> print('Hi there')
Hi there
>>> import sys
>>> sys.version
'2.7.10 (default, May 23 2015, 09:40:32) [MSC v.1500 32 bit (Intel)]'
>>>
```

Import the internal `_DimPy` module and numpy:

```
import _DimPy as dm
import numpy as np
```

Should then be able to call *native* DM functions:

```
dm.Result("Hello from Python {}!\n".format(sys.version))
```

Getting Images from DM
----------------------
Create an image in DM. Then in the DimPy console:

```
im = dm.GetFrontImage()
# can set tags in the image easily:
im_taggroup = im.GetTagGroup()
im_taggroup["MyTag"] = "Hello"
# convert to a numpy array using np.asarray. This becomes a read/write
# view of the underlying DM data 
im_data = np.asarray(im)
# can write to it. This sets the top left block of pixels to 0:
im_data[0:100, 0:100] = 0
```

Putting Images into DM
----------------------

```
# Create a numpy image
d = np.random.random((512, 512))
# Create an image in DM, DM will then own the buffer
dmimage = dm.CreateReal2DImage("MyImage", 4, d.shape[1], d.shape[0])
np.asarray(dmimage)[:] = d
dm.ShowImage(dmimage)
```

Let's try a more interesting example, getting data from the web, and showing in DM
(requires the requests and PIL (use Pillow) modules, both included with WinPython):

```
import requests
from PIL import Image
from io import BytesIO
url = 'http://inperc.com/wiki/images/f/fb/Lena.jpg'
lena_jpg = Image.open(BytesIO(requests.get(url).content))
# convert to numpy array and only take red channel
lena_jpg = np.asarray(lena_jpg)[..., 0]
dm_lena = dm.CreateByteImage("lena", lena_jpg.shape[1], lena_jpg.shape[0])
np.asarray(dm_lena)[:] = lena_jpg
dm.ShowImage(dm_lena)
```

Reference
---------
The following DM functions are exposed:

####long Dimpy_PyRun_SimpleString(string)
Execute a single command
####void Dimpy_alloc_console_and_reassign_std(void)
Allocate a console and reassign stdin and stdout to it
####void Dimpy_open_console(void)
Calls Dimpy_alloc_console_and_reassign_std then starts the REPL. All you need at the moment!


Outstanding Issues
==================
Manifests
---------
Because DM has a manifest(?) it means that all DLLs loaded into the process need a manifest too. Most do, but some of the python distributed files don't. Specifically libzmq doesn't, and scipy\linalg\_solve_toeplitz.pyd;#2 doesn't. Easiest way to fix this is to ues the mt.exe tool (part of Visual Studio) to copy the manifest from Python27.dll to the appropriate files:
```
mt -inputresource:python27.dll;#2 -outputresource:Lib\site-packages\zmq\libzmq.pyd;#2
mt -inputresource:python27.dll;#2 -outputresource:Lib\site-packages\scipy\linalg\_solve_toeplitz.pyd;#2
```

Can try and do all .pyd files with (starting in python directory):
```
for /R %x in (*.pyd) DO mt.exe -inputresource:python27.dll;#2 -outputresource:%x;#2
```
This doesn't solve all issues, however

SciPy
-----
Can't work out how to import scipy.misc, or scipy.linalg. I originally thought it was a manifest issue with the pyd files, but copying manifest from python27.dll doesn't fix it.

Eg the following hangs:
```
import scipy.linalg
```

RGB Images
----------
Not properly implemented yet.

Non-displayable types
---------------------
There are some types 

Quitting DM
-----------
Doens't quit nicely (but could be a DM1.8 under Win10 problem??)

Next Steps
==========
- Work on DM plugin to remove extraneous registry keys and add menu items for
  frequently used functionality.
- Get support for Python 3.x, GMS 2
- Start on Python side module. Should allow easy access to images, etc. May want
  a DM-only one (easy access to all loaded images, easy to add, get images (dm.images['MyImage'] = dm.images['A'] + dm.images['B'] etc) and a no-DM one (eg a module for doing easy irow, icol, same fft as
  DM, some identical functions like cross correlate, etc)
- Work out how to call external DM SCript functions. May need to wrap call in a script that
  can be executed. Maybe something like(?)
  ```
  object o=alloc(returndataobj)
  number x, y
  GetSize(im, x, y)
  o.ret0 = x
  o.ret1 = y
  exit(ObjectAsLong(o))
  ```
- Get installer working. (Custom command class in Python?)
