2014-03-08 4:05:32 PM
Trying to create a non-python-dependant DimpyLoader dll
that dynamically loads the python library, then DimPy dll.
Problem is that DimPy.dll needs all of the gatan stuff anyway,
so note sure it will link against DM libs without the plugins
at which point do we really gain snything with two separate
DLLs? Could we have the wrapped functions in the DMdll and only make them
a module in the python dll? Probably not, as there's a lot of python
specific stuff in the wrapped EM functions...

Also, got password from Gatan: dmsdk_382_8979323

6:39 PM 1/18/2014
Copied from Users/work folder on bedroom pc.

There's a regular and a static project, both use the same source code.
I'm including what I think are the latest builds here, the python script
used to edit the output files, and the cpp files.

Can build (?) using DM 2008 express edition as follows:
cl /MD /c DMHelper.cpp  # /c means don't link, produces only DMHelper.obj
# the above is, using multithreaded DLL (/MD) - works better with DimPy...
//default is /MT = multithreaded
lib DMHelper.obj    # makes DMHelper.lib

can then process with the python script:
python EditDM2008HelperStatic.py DMHelper.lib
to make DMHelper_edit.lib

Waiting on Gatan for 3.8.2 password before being able to check this works!