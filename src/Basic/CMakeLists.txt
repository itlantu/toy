message("Loading Basic")

file(GLOB src_basic_files "*.cpp")

add_library(src_basic_lib "${src_basic_files}")