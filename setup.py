from distutils.core import setup
from distutils.extension import Extension

setup(name="Diamond_subsidys",
    ext_modules=[
        Extension("Diamond_subsidy", ["Diamond_GetBlockBaseValue.cpp"],
        libraries = ["boost_python"])
    ])
