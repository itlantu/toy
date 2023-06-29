set(src_dirs "Debug" "Token" "Lex")

set(src_lib_prefix "src_")
set(src_lib_suffix "_lib")

# 设置静态库文件的生成路径
set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/build")

# 在cmake3.20版本，必须要添加至少一个source才能使add_library不报错
add_library(src_all_lib STATIC "EmptyFile.cpp")

foreach(dir ${src_dirs})
    add_subdirectory("${dir}")

    # 拼接字符串生成库名
    set(library_name "${src_lib_prefix}")
    string(APPEND library_name "${dir}")
    string(APPEND library_name "${src_lib_suffix}")

    # 字符串内容全部转为小写字母
    string(TOLOWER "${library_name}" library_name)

    # Debug
#    message("${library_name}")

    target_link_libraries(src_all_lib "${library_name}")
endforeach()

# 生成静态库文件
#install(TARGETS src_all_lib ARCHIVE DESTINATION "lib")