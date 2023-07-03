cmake_minimum_required(VERSION 3.25)
project(toy)

set(CMAKE_CXX_STANDARD 20)

include_directories("include")

add_subdirectory("src")

add_executable(toy "main.cpp")
target_link_libraries(toy src_all_lib)