Dimpy Swig Files GMS2 64-bit
===========================

*MFM 2015-08-28*

Trying to create a SWIG file for GMS2.

The last attempt used SWIG 2.04 and ended up with a huge monolithic file.
This time, I'd like to:

1. Stick with just the DM native (global) functions.
Eg although it's nice to have image.GetTagGroup() it makes translating existing scripts harder and just introduces two ways to do things. Lets stick with the global ImageGetTagGroup for now, unless including the full DM classes is easier in general

2. Keep wrapped DM functions separate from the more complex buffer and mapping interfaces we give to taggroup and images.

If we edit any DM header files, we keep track of how we did so here.

Easiest way would be to %import DMPlugInStubs.h, but this fails with syntax errors so...

Build
=====

..\swigwin-3.0.7\swig -c++ -python -shadow -builtin DigitalMicrograph.i

Modifications to DM header files
================================

- Remove vararg functions (ImageGetDimensionSizes, LogEvent)
- Remove __declspec(deprecated) functions (GetApplicationDirectory, ImageUtilities_MeanAndVariance)
Delete everything ater line 7159 (first class definition)

dimpy.i File
============

This contains DM specific python conversion functions. Specifically:
- **Gatan::DM::Image** implements the buffer protocol.
  For python <3 we have to add  Py_TPFLAGS_HAVE_NEWBUFFER to the class definition, and the only way to do so is to redefine Py_TPFLAGS_DEFAULT. For python >=3 we don't need to worry about this
	  
- **Gatan::DM::TagGroup implemetns the iteration, length, and subscript slots.
	  
