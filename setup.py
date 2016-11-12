from distutils.core import setup, Extension

setup(
    name='_julia', 
    version='0.11', 
    ext_modules=[Extension('_julia', ['pyjulia.c'], extra_compile_args=['-lm'])]
    )
