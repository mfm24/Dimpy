// SimpleEmbeddedPython.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "python.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Py_SetPythonHome("C:\\WinPython-32bit-2.7.6.3\\python-2.7.6");
	Py_Initialize();
	PyRun_InteractiveLoop(stdin, "<stdin>");
	return 0;
}

