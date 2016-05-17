

const char *argp_program_version = "julia 0.1";
const char *argp_program_bug_address = "josh@famestad.com";
static struct argp_option options[] = { 
        { "z_real", 'r', "z_real", 0, "real component of complex quantity z"},
        { "z_imag", 'i', "z_imag", 0, "imaginary component of complex quantity z"},
        { "resolution", 's', "resolution", 0, "resolution, distance between sampled points in complex plane"},
        { "min_r", 't', "min_r", 0, "minimum real component in grid"},
        { "max_r", 'u', "max_r", 0, "maximum real component in grid"},
        { "min_i", 'v', "min_i", 0, "minimum imaginary component in grid"},
        { "max_i", 'w', "max_i", 0, "maximum imaginary component in grid"},
        { 0 } 
};
