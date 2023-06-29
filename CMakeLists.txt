cmake_minimum_required(VERSION 3.25)
project(toy)

set(TOY_TEST 1)

set(CMAKE_CXX_STANDARD 20)

# 设置目标文件的生成目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/bin)

include_directories("include")
add_subdirectory("src")

if(TOY_TEST)
    add_subdirectory("test")
else()
    add_executable(toy "main.cpp")
endif ()

target_link_libraries(toy src_all_lib)