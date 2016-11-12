#include <stdlib.h>
#include <stdio.h>
#include <complex.h>
#include "julia.h"


int run_program(float min_r, float max_r, float min_i, float max_i, complex float z, float resolution){
    complex float *grid;
    int number_of_elements_in_grid;
    int *divergence_scores;
    number_of_elements_in_grid = ( max_r - min_r + resolution) * ( max_i - min_i + resolution) / ( resolution * resolution );
    grid = initialize_grid(min_r, max_r, min_i, max_i, resolution, number_of_elements_in_grid);
    divergence_scores = score_grid(grid, number_of_elements_in_grid, z);

    int i=0;
    while (i<= number_of_elements_in_grid){ // should this be just < ?
        printf("%f\t%f\t%d\n", creal(grid[i]), cimag(grid[i]), divergence_scores[i]);
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

int* score_grid(complex float grid[], int number_of_elements_in_grid, complex float z){
    int *divergence_scores;
    divergence_scores = (int*)malloc(number_of_elements_in_grid * sizeof(int));
    
    int i = 0;
    while ( i < number_of_elements_in_grid ){
        divergence_scores[i] = check_for_convergence(grid[i], z);
        i++;
    }
    return divergence_scores;
}

complex float* initialize_grid(float min_r, float max_r, float min_i, float max_i, float resolution, int number_of_elements_in_grid){
    printf("initializing grid with %d\n", number_of_elements_in_grid);
    complex float *grid;
    float real_component;
    float imaginary_component;

    grid = (complex float*)malloc(number_of_elements_in_grid * sizeof(complex float));

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
