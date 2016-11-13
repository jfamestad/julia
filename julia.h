//julia.h
#ifndef JULIA_H
#define JULIA_H

double complex* initialize_grid(double min_r, double max_r, double min_i, double max_i, double resolution, int number_of_elements_in_grid);
int run_program(double min_r, double max_r, double min_i, double max_i, double complex z, double resolution);
int* score_grid(double complex grid[], int number_of_elements_in_grid, double complex z); 
int check_for_convergence(double complex cnum, double complex z);

#endif
