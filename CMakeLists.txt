cmake_minimum_required(VERSION 2.8)
project(ctree)

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_VERBOSE_MAKEFILE OFF)
set (EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})
set (LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)

add_subdirectory(${PROJECT_SOURCE_DIR}/dependencies/cxxopts)
add_subdirectory(${PROJECT_SOURCE_DIR}/dependencies/spdlog)
add_executable(ctree ${PROJECT_SOURCE_DIR}/src/ctree.cpp)
target_link_libraries(ctree cxxopts spdlog)
