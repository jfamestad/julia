from distutils.core import setup, Extension

setup(
    name='julia', 
    version='0.11', 
    ext_modules=[Extension('julia', ['pyjulia.c'], extra_compile_args=['-lm'])]
    )
