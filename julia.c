#include <stdlib.h>
#include <argp.h>
#include <stdio.h>
#include <complex.h>

#include "julia.h"
#include "argparse.h"



static struct argp argp = { options, parse_opt, args_doc, 0, 0, 0 };

int main(int argc, char **argv){
    complex float *grid;
    int *mandelbrot;
    int numberOfElementsInGrid;


    struct arguments arguments;
    arguments.resolution = 0;
    arguments.min_r = 0;
    arguments.max_r = 0;
    arguments.min_i = 0;
    arguments.max_i = 0;
    arguments.z_real = 0;
    arguments.z_imag = 0;

    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    float resolution = arguments.resolution ? arguments.resolution : .1f;

    float min_r, max_r, min_i, max_i;
    min_r = arguments.min_r ? arguments.min_r : -3.0f;
    max_r = arguments.max_r ? arguments.max_r : 1.0f;
    min_i = arguments.min_i ? arguments.min_i : -2.0f;
    max_i = arguments.max_i ? arguments.max_i : 2.0f;

    float z_real, z_imag;
    complex float z;
    z_real = arguments.z_real ? arguments.z_real : 0.99997;
    z_imag = arguments.z_imag ? arguments.z_imag : 0.619998;
    z = z_real + z_imag * I;

    numberOfElementsInGrid = ( max_r - min_r + resolution) * ( max_i - min_i + resolution) / ( resolution * resolution );
   
    grid = initialize_grid(min_r, max_r, min_i, max_i, resolution, numberOfElementsInGrid);
    
    mandelbrot = filter_for_mandelbrot(grid, numberOfElementsInGrid, z);

    int i=0;
    while (i<= numberOfElementsInGrid){
        printf("%f\t%f\t%d\n", creal(grid[i]), cimag(grid[i]), mandelbrot[i]);
        i++;
    }

    return 0;
}

int check_for_convergence(complex float cnum, complex float z){
    complex float result = cnum;
    int bound = 4;
    int max_iterations = 100;
    int i = 0;
    while (i < max_iterations){
        result = (result * result) + ( z * I );
        if (cabsf(result) > bound){
            break;
        }
        else{
            i++;
        }
    }
    return i;
}

int* filter_for_mandelbrot(complex float grid[], int numberOfElementsInGrid, complex float z){
    int *mandelbrot;
    mandelbrot = (int*)malloc(numberOfElementsInGrid * sizeof(int));
    
    int i = 0;
    while ( i < numberOfElementsInGrid ){
        mandelbrot[i] = check_for_convergence(grid[i], z);
        i++;
    }
    return mandelbrot;
}

complex float* initialize_grid(float min_r, float max_r, float min_i, float max_i, float resolution, int numberOfElementsInGrid){
    printf("initializing grid with %d", &numberOfElementsInGrid);
    complex float *grid;
    float real_component;
    float imaginary_component;

    grid = (complex float*)malloc(numberOfElementsInGrid * sizeof(complex float));

    int i = 0;
    real_component = min_r;
    while ( real_component <= max_r ){
        imaginary_component = min_i;
        while ( imaginary_component <= max_i ){
            grid[i] = real_component + imaginary_component * I;
            imaginary_component += resolution;
            i++;
        }
        real_component += resolution;
    }
    return grid;
}
