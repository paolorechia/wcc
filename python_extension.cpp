#include <pybind11/pybind11.h>
#include <iostream>
#include "count.h.in"

namespace py = pybind11;

int add(int i, int j) {
    return i + j;
}

PYBIND11_MODULE(python_extension, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("add", &add, "A function that adds two numbers");

    m.def("count_bytes", &count_bytes, "Count bytes of a file stream");
}
