message("loading Debug")

add_subdirectory("View")

add_library(src_debug_lib "EmptyFile.cpp")

target_link_libraries(src_debug_lib "src_debug_view_lib")
