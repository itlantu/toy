message("loading Token")

file(GLOB src_token_files "*.cpp")

#message("${src_token_files}")

add_library(src_token_lib "${src_token_files}")