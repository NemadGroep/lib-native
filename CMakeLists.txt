cmake_minimum_required(VERSION 3.15...3.27)
project(${SKBUILD_PROJECT_NAME} LANGUAGES CXX)

# Find Python and pybind11
find_package(Python REQUIRED COMPONENTS Interpreter Development.Module)
find_package(pybind11 CONFIG REQUIRED)

# Create the Python extension module
python_add_library(_core MODULE src/lib_native/binding.cpp WITH_SOABI)
target_link_libraries(_core PRIVATE pybind11::headers)

# Install the extension module
install(TARGETS _core DESTINATION ${SKBUILD_PROJECT_NAME})
