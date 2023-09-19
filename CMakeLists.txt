cmake_minimum_required(VERSION 3.27 FATAL_ERROR)

project(substring_search)

add_library(kmp include/kmp.h src/kmp.cpp)

add_executable(substring_search src/main.cpp)

target_link_libraries(substring_search kmp)