cmake_minimum_required(VERSION 3.2...3.27.5)

project(multi-projects)

enable_testing()
add_subdirectory(lib/googletest)

set(SCL_LIB "scl_lib")

add_subdirectory(bubble_sort)
add_subdirectory(comb_bubble_sort)
add_subdirectory(obuchaika)
add_subdirectory(scl)

set(CMAKE_SUPPRESS_REGENERATION true)