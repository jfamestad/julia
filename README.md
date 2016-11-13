# julia
Julia Set Generator

Julia generates a plottable data set of complex numbers and a score that indicates how quickly we diverge under iteration. 

https://en.wikipedia.org/wiki/Julia_set

This project can be built as a pure C standalone CLI utility or as a Python Module. When called from Python, we still use the C implementation for performance.

Build C CLI Utility  
`make`  
<br>
`[josh@sparky _julia]$ ./julia --help
Usage: julia [OPTION...] 

  -i, --z_imag=z_imag        imaginary component of complex quantity z
  -r, --z_real=z_real        real component of complex quantity z
  -s, --resolution=resolution   resolution, distance between sampled points in
                             complex plane
  -t, --min_r=min_r          minimum real component in grid
  -u, --max_r=max_r          maximum real component in grid
  -v, --min_i=min_i          minimum imaginary component in grid
  -w, --max_i=max_i          maximum imaginary component in grid
  -?, --help                 Give this help list
      --usage                Give a short usage message
  -V, --version              Print program version

Mandatory or optional arguments to long options are also mandatory or optional
for any corresponding short options.

Report bugs to josh@famestad.com.`  
<br>
Build and Install Python Module  
`sudo python setup.py install`
