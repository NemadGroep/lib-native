#include <pybind11/pybind11.h>
#include <chrono>
#include <iostream>

namespace py = pybind11;

int add(int i, int j) {
    auto start = std::chrono::high_resolution_clock::now();
    int result = i + j;
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << "Add function took " << elapsed.count() << " ms\n";
    return result;
}

const int e = {20};

PYBIND11_MODULE(_core, m) {
    m.doc() = "Native C++ extensions for lib-native";

    m.def("add", &add, "A function that adds two numbers");
}
