cmake_minimum_required(VERSION 3.27 FATAL_ERROR)

project(substring_search)

add_library(kmp include/kmp.h src/kmp.cpp)

add_library(rabin_karp include/rabin_karp.h src/rabin_karp.cpp) 

add_executable(substring_search src/main.cpp include/app.h src/app.cpp tests/test.h tests/test.cpp)

target_link_libraries(substring_search kmp)

target_link_libraries(substring_search rabin_karp)