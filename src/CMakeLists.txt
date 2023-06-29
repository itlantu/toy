set(src_dirs "Token" "Lex")

set(src_lib_prefix "src_")
set(src_lib_suffix "_lib")

add_executable(toy "main.cpp")

foreach(dir ${src_dirs})
    add_subdirectory("${dir}")

    # 拼接字符串生成库名
    set(library_name "${src_lib_prefix}")
    string(APPEND library_name "${dir}")
    string(APPEND library_name "${src_lib_suffix}")

    # 字符串内容全部转为小写字母
    string(TOLOWER "${library_name}" library_name)

    # debug
#    message("${library_name}")

    target_link_libraries(toy "${library_name}")
endforeach()
