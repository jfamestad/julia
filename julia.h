//julia.h
#ifndef JULIA_H
#define JULIA_H

complex float* initialize_grid(float min_r, float max_r, float min_i, float max_i, float resolution, int number_of_elements_in_grid);
int* score_grid(complex float grid[], int number_of_elements_in_grid, complex float z); 
int check_for_convergence(complex float cnum, complex float z);

#endif
