#include <stdlib.h>
#include <stdio.h>
#include <complex.h>
#include "julia.h"


int run_program(double min_r, double max_r, double min_i, double max_i, double complex z, double resolution){
    double complex *grid;
    int number_of_elements_in_grid;
    int *divergence_scores;
    number_of_elements_in_grid = ( max_r - min_r + resolution) * ( max_i - min_i + resolution) / ( resolution * resolution );
    grid = initialize_grid(min_r, max_r, min_i, max_i, resolution, number_of_elements_in_grid);
    divergence_scores = score_grid(grid, number_of_elements_in_grid, z);

    int i=0;
    while (i<= number_of_elements_in_grid){
        printf("%f\t%f\t%d\n", creal(grid[i]), cimag(grid[i]), divergence_scores[i]);
        i++;
    }

    return 0;
}

int check_for_convergence(double complex cnum, double complex z){
    double complex result = cnum;
    int bound = 4;
    int max_iterations = 100;
    int i = 0;
    while (i <= max_iterations){
        double complex previous = result;
        result = (result * result) + ( z );
    //    printf("\n\nprevious: %f+%fi\tresult: %f+%fi\n", creal(previous), cimag(previous), creal(result), cimag(result));
    //    printf("i: %d\tz: %f+%f\tcnum: %f+%fi\tcurrent result: %f+%fi\tabsv: %f\n", i, creal(z), cimag(z), creal(cnum), cimag(cnum), creal(result), cimag(result), cabsf(result));
        if (cabsf(result) > bound){
            break;
        }
        else{
            i++;
        }
    }
    return i;
}

int* score_grid(double complex grid[], int number_of_elements_in_grid, double complex z){
    int *divergence_scores;
    divergence_scores = (int*)malloc(number_of_elements_in_grid * sizeof(int));
    
    int i = 0;
    while ( i < number_of_elements_in_grid ){
        divergence_scores[i] = check_for_convergence(grid[i], z);
        i++;
    }
    return divergence_scores;
}

double complex* initialize_grid(double min_r, double max_r, double min_i, double max_i, double resolution, int number_of_elements_in_grid){
    //printf("initializing grid with %d\n", number_of_elements_in_grid);
    double complex *grid;
    double real_component;
    double imaginary_component;

    grid = (double complex*)malloc(number_of_elements_in_grid * sizeof(double complex));

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
