#include <stdlib.h>
#include <argp.h>
#include <stdio.h>
#include <complex.h>

#include "julia.h"
#include "julia.c"
#include "argparse.h"


int main(int argc, char **argv){

    struct arguments arguments;
    arguments.resolution = 0;
    arguments.min_r = 0;
    arguments.max_r = 0;
    arguments.min_i = 0;
    arguments.max_i = 0;
    arguments.z_real = 0;
    arguments.z_imag = 0;

    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    double resolution = arguments.resolution ? arguments.resolution : .1f;

    double min_r, max_r, min_i, max_i;
    min_r = arguments.min_r ? arguments.min_r : -3.0f;
    max_r = arguments.max_r ? arguments.max_r : 1.0f;
    min_i = arguments.min_i ? arguments.min_i : -2.0f;
    max_i = arguments.max_i ? arguments.max_i : 2.0f;

    double z_real, z_imag;
    double complex z;
    z_real = arguments.z_real ? arguments.z_real : 0.99997f;
    z_imag = arguments.z_imag ? arguments.z_imag : 0.619998f;
    z = z_real + z_imag * I;

    run_program(min_r, max_r, min_i, max_i, z, resolution);
    return 0;
}

