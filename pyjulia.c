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

    complex float *grid;
    int number_of_elements_in_grid;
    int *divergence_scores;

    number_of_elements_in_grid = ( max_r - min_r + resolution) * ( max_i - min_i + resolution) / ( resolution * resolution );
    grid = initialize_grid(min_r, max_r, min_i, max_i, resolution, number_of_elements_in_grid);
    divergence_scores = score_grid(grid, number_of_elements_in_grid, Z);

    int i=0;
    while (i<= number_of_elements_in_grid){ // should this be just < ?
        printf("%f\t%f\t%d\n", creal(grid[i]), cimag(grid[i]), divergence_scores[i]);
        i++;
    }
    
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

static PyMethodDef julia_methods[] = {
    { "Julia", (PyCFunction)julia_Julia, METH_NOARGS, NULL },
    { "Julia", julia_Julia, METH_VARARGS, NULL },
    { NULL, NULL, 0, NULL }
};

PyMODINIT_FUNC initjulia(void){
    Py_InitModule3("julia", julia_methods, "Julia Set generation utility");
}
