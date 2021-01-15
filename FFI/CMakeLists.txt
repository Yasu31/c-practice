cmake_minimum_required (VERSION 3.10.2)
project(pybind11_example)

add_subdirectory(pybind11)

pybind11_add_module(cmake_example example.cpp)