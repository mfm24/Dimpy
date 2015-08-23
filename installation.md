Dimpy Installation Instructions
===============================
*MFM 2015-08-22*

Currently for 32-bit DM2 and 32-bit Python 2.7

1. Download python2.7 (WinPython recommended)
2. Copy `0_DimpyLoader.dll` and `DimpyMain.dll` to DM plugin folder
3. We need to set some reigstry values so that the plugins can find the Python folder
this should be automated in the future:
 
 - Set **HKCU\Software\DimPy\Path** to something (needed but unused - REMOVE)
 - Set **HKCU\Software\DimPy\PythonPath** to the location of `python27.dll`. 
   If using WinPython, will be something like `path\WinPython-32bit-2.7.10.2\python-2.7.10`
   
4. Run DM. You should see in the results. Make sure you don't get any errors loading DimpyMain or 0_DimpyLoader DLLs:
````
FoundKey <what you put in HKCU\Software\DimPy\Path>
DimpyLoader: Loaded Python library!
````

Testing
-------
The following DM functions are exposed:

####long Dimpy_PyRun_SimpleString(const char*)
Runs a single string and returns the result code.

####long Dimpy_StartREPL(bool bUseThread)
Starts the REPL in a new window. If bUseThread is true the REPL will 
run in a seperate thread. Care must then be taken to ensure any DM calls
are thread safe

Both functions crashed for me! Do we need to build against identical 
python dll?? Trying that...