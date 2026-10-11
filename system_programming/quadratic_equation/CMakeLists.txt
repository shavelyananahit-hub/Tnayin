cmake_minimum_required(VERSION 3.7)

project(qep VERSION 1.1.0.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

configure_file(include/path.h.in ${CMAKE_BINARY_DIR}/path.h)
configure_file(include/ver.h.in ${CMAKE_BINARY_DIR}/version.h)

add_library(qe_static STATIC lib_src/qe.cpp)
add_library(qe_shared SHARED lib_src/qe.cpp)

target_include_directories(qe_static PUBLIC include)
target_include_directories(qe_shared PUBLIC include)

add_executable(qep src/qex.cpp)

target_include_directories(qep PRIVATE include ${CMAKE_BINARY_DIR})
target_link_libraries(qep PRIVATE qe_static)
