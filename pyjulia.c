#include <Python.h>
#include <stdio.h>
#include <complex.h>
#include "julia.c"

static PyObject *julia_Julia(PyObject* self, PyObject *args){
    float MIN_R, MAX_R, MIN_I, MAX_I, RESOLUTION;
    complex float Z;

    if(!PyArg_ParseTuple(args, "fffffD", &MIN_R, &MAX_R, &MIN_I, &MAX_I, &RESOLUTION, &Z)){
        return NULL;
    }

    Py_RETURN_NONE;
}

static PyMethodDef julia_methods[] = {
    { "Julia", (PyCFunction)julia_Julia, METH_NOARGS, NULL },
    { "Julia", julia_Julia, METH_VARARGS, NULL },
    { NULL, NULL, 0, NULL }
};

PyMODINIT_FUNC initjulia(void){
    Py_InitModule3("julia", julia_methods, "Julia Set generation utility");
}
