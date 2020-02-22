'''
setup.py file for SWIG mootypes
'''

from distutils.core import setup, Extension

mootypes_module = Extension(
    '_moo',
    sources=['moo_wrap.c', 'moostring.c', 'mootypes.c'],
)

setup(
    name = 'moo',
    version = '0.1',
    author = 'SWIG Docs',
    description = 'Simple swig moofrom docs',
    ext_modules = [mootypes_module],
    py_modules = ['moo'],
)
