# 获得当前目录下所有一级子目录和一级子文件
file(GLOB src_files "${CMAKE_CURRENT_SOURCE_DIR}/*")

add_library(src_all_lib STATIC "EmptyFile.cpp")

foreach (file ${src_files})
    # 如果为目录，则add_subdirectory改目录，并链接对应的静态库到src_all_lib
    if(IS_DIRECTORY "${file}")
        set(dir "${file}")

        add_subdirectory("${dir}")
        get_filename_component(dir ${dir} NAME)
        # message("${dir}")
        # string(TOLOWER "src_${dir}_lib" lib_name)
        target_link_libraries(src_all_lib "${lib_name}")

    endif ()
endforeach ()
