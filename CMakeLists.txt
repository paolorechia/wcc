cmake_minimum_required(VERSION 3.27)


file(
  DOWNLOAD
  https://github.com/cpm-cmake/CPM.cmake/releases/download/v0.38.3/CPM.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake
  EXPECTED_HASH SHA256=cc155ce02e7945e7b8967ddfaff0b050e958a723ef7aad3766d368940cb15494
)
include(${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake)


set(CMAKE_CXX_STANDARD_REQUIRED, true)
set(CMAKE_CXX_STANDARD, 11)

project(wcc VERSION 0.1)

add_executable(wcc src/wcc.cpp src/count.cpp src/count.h.in)

add_subdirectory(pybind11)
pybind11_add_module(python_extension src/python_extension.cpp src/count.cpp src/count.h.in)

CPMAddPackage("gh:jarro2783/cxxopts@3.1.1")
target_compile_features(wcc PUBLIC cxx_std_11)
target_link_libraries(wcc PUBLIC cxxopts::cxxopts pybind11::pybind11)
