#include <Python.h>
#include <stdio.h>
#include <complex.h>
#include "julia.c"

static PyObject *_julia_Julia(PyObject *self, PyObject *args){

    double min_r, max_r, min_i, max_i, resolution;
    Py_complex z;
    double complex Z;

    if(!PyArg_ParseTuple(args, "ddddDd", &min_r, &max_r, &min_i, &max_i, &z, &resolution)){
        return NULL;
    }

    Z = z.real + z.imag * I;

    double complex *grid;
    int number_of_elements_in_grid;
    int *divergence_scores;

    number_of_elements_in_grid = ( max_r - min_r + resolution) * ( max_i - min_i + resolution) / ( resolution * resolution );
    grid = initialize_grid(min_r, max_r, min_i, max_i, resolution, number_of_elements_in_grid);
    divergence_scores = score_grid(grid, number_of_elements_in_grid, Z);

    PyObject* result;
    result = PyDict_New();

    for (int i=0; i<number_of_elements_in_grid; i++){
        Py_complex element;
        element.real = creal(grid[i]);
        element.imag = cimag(grid[i]);
        PyObject* ELEMENT;
        ELEMENT = PyComplex_FromCComplex(element);
        PyObject* SCORE;
        SCORE = PyInt_FromLong(divergence_scores[i]);
        PyDict_SetItem(result, ELEMENT, SCORE);
    }

    return result;
}

static PyMethodDef _julia_methods[] = {
    { "Julia", (PyCFunction)_julia_Julia, METH_NOARGS, NULL },
    { "Julia", _julia_Julia, METH_VARARGS, NULL },
    { NULL, NULL, 0, NULL }
};

PyMODINIT_FUNC init_julia(void){
    Py_InitModule3("_julia", _julia_methods, "C extension for Julia Set generation utility");
}
