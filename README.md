Dimpy Getting Started Instructions
==================================

Installation
============

*MFM 2015-09-05*

Instructions for 64-bit GMS2 and Python 3.4

1. Download python3.4 (WinPython recommended)
2. Copy `0_DimpyLoader.dll` and `Dimpy34.dll` to DM user plugin folder (usually C:\ProgramData\Gatan\Plugins)
3. We need to set a reigstry value so that the plugins can find the Python folder
this should be automated in the future:
 
 - Set **HKCU\Software\DimPy\Python34Path** to the location of `python34.dll`. 
   If using WinPython, will be something like `path\WinPython-64bit-3.4.3.5\python-3.4.3.amd64`
   
4. Run DM. Make sure you don't get any errors loading Dimpy34 or 0_DimpyLoader DLLs. You should see the following in the results window:

````
0_DimpyLoader: searching for Python3.4 environment...found!
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
im_taggroup = dm.ImageGetTagGroup(im)
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
*For debugging only*. Execute a single command. This won't work once the console is open, and there is no standard output for any results.
####void Dimpy_open_console(void)
Opens a console window and runs the Python interpreter in a new thread. All you need at the moment!


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


Quitting DM
-----------
Doens't quit nicely! Needs to close Python and console nicely when shutting down. Would be nice if console close button didn'y close DM too!

Next Steps
==========
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
- Add docstrings from header file automatically
