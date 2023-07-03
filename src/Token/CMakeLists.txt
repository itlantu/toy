message("loading Token")

# 获得当前目录下所有以.cpp为后缀的文件名
file(GLOB src_token_files "*.cpp")

add_library(src_token_lib STATIC "${src_token_files}")