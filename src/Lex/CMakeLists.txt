message("loading Lex")

file(GLOB src_lex_files "*.cpp")

#message("${src_lex_files}")

add_library(src_lex_lib "${src_lex_files}")