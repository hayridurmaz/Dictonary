cmake_minimum_required(VERSION 3.10)
project(Dictonary C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Dictonary
        task2.c
        Trie.c
        Trie.h)
MATH(EXPR stack_size "5*1024 * 1024 * 1024") # 10 GB
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")