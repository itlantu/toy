message("Loading Lex")

file(GLOB src_lex_files "*.cpp")

add_library(src_lex_lib "${src_lex_files}")