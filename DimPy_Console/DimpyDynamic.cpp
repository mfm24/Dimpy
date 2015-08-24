#define _GATANPLUGIN_USES_LIBRARY_VERSION 2
#include "DMPlugInBasic.h"


#include <python.h>

/*
mfm 2Feb12 This function attempts to call the given function name with the given args
So eg, 
s="Hi Bob"
CallDM("Result", s)

should call DM::Result("Hi Bob")
*/
static PyObject *
CallDM(PyObject *self, PyObject *args)
{
    const char *command;
	int nargs=PyTuple_Size(args);
	for(int argi=0; argi<nargs; argi++)
	{
		PyObject* arg=PyTuple_GetItem(args, argi);
		printf("%d is %s", argi, arg->ob_type->tp_name);
	}

    int sts;
	if(PyTuple_Check(args))
		printf("Got a TUPLE");

    if (!PyArg_ParseTuple(args, "s", &command))
        return NULL;
    Gatan::DM::Result(command);
    return Py_BuildValue("i", sts);
}


static PyMethodDef DimpyDynamicMethods[] = {
    {"CallDM",  CallDM, METH_VARARGS,
     "Executes the given DM function"},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

PyMODINIT_FUNC
initDimpyDynamic(void)
{
    (void) Py_InitModule("DimpyDynamic", DimpyDynamicMethods);
}