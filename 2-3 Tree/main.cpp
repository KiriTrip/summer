#include <pybind11/pybind11.h>  // Главный заголовок pybind11
#include <pybind11/stl.h>
#include "Tree.h"             // Наш класс

namespace py = pybind11;  // Упрощаем запись

PYBIND11_MODULE(tree_module, m) {
    // Делаем класс Tree доступным в Python
    py::class_<TreeInt>(m, "TreeInt")
        .def(py::init<>())      
        .def("insert", &TreeInt::insert)   
        .def("print", &TreeInt::print)
        .def("height", &TreeInt::height)   
        .def("search", &TreeInt::search)
        .def("genLinear", &TreeInt::genLinear)   
        .def("genRand", &TreeInt::genRand)
        .def("GearData", &TreeInt::GearData);

}
