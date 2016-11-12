#include <Python.h>
#include <stdio.h>
#include <complex.h>
#include "julia.c"

static PyObject *julia_Julia(PyObject *self, PyObject *args){

    double min_r, max_r, min_i, max_i, resolution;
    Py_complex z;
    complex float Z;

    if(!PyArg_ParseTuple(args, "ddddDd", &min_r, &max_r, &min_i, &max_i, &z, &resolution)){
        return NULL;
    }

    Z = z.real + z.imag * I;
    run_program(min_r, max_r, min_i, max_i, Z, resolution);

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
