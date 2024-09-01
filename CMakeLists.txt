cmake_minimum_required(VERSION 3.29)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
PROJECT(mellow)

# will change later
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY /home/mickey/Documents/projects/CLion/pfhtml/test)

add_executable(pfhtml
        src/main.c
        src/files.c
        include/imports.h
        src/parser/md/md.c
        src/parser/addtags.cpp
        src/parser/transpile.c
)

# incase needed
# target_link_libraries(pfhtml, xyz)
