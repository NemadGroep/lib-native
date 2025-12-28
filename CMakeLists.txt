cmake_minimum_required(VERSION 3.16)
project(lib_native LANGUAGES CXX)

find_package(Python3 REQUIRED COMPONENTS Interpreter Development.Module)
find_package(pybind11 REQUIRED)

# Build the extension module.
# The Python package lives in src/lib_native; we install the compiled module
# into that package so scikit-build-core can bundle it into the wheel.
pybind11_add_module(_core src/lib_native/binding.cpp)

# When building a wheel, install into the package directory (NOT system site-packages).
install(
  TARGETS _core
  LIBRARY DESTINATION lib_native
  RUNTIME DESTINATION lib_native
)
