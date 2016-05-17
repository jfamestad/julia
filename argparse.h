//argparse.h
#ifndef ARGPARSE_H
#define ARGPARSE_H

struct arguments{
        char *args[1];
        float z_real, z_imag, resolution, min_r, max_r, min_i, max_i;
};

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

static char args_doc[] = ""; 

static error_t parse_opt(int key, char *arg, struct argp_state *state){
        
        struct arguments *arguments = state->input;
            char *end;
            switch (key){
                case 'r':
                    arguments->z_real = strtof(arg, &end);
                    break;
                case 'i':
                    arguments->z_imag = strtof(arg, &end);
                    break;
                case 's':
                    arguments->resolution = strtof(arg, &end);
                     break;
                case 't':
                    arguments->min_r = strtof(arg, &end);
                    break;
                case 'u':
                    arguments->max_r = strtof(arg, &end);
                    break;
                case 'v':
                    arguments->min_i = strtof(arg, &end);
                    break;
                case 'w':
                        arguments->max_i = strtof(arg, &end);
                        break;
                case ARGP_KEY_ARG:
                        if (state->arg_num <= 8){ 
                          argp_usage(state);
                        }   
                        arguments->args[state->arg_num] = arg;
                        &state->argv[state->next];
                        break;
                 case ARGP_KEY_END:
                        break;
                 default:
                        return ARGP_ERR_UNKNOWN;
                    }   
                 return 0;
}

#endif
