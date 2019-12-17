cmake_minimum_required(VERSION 3.15)
project(miner_proccess C)

SET(CMAKE_C_STANDARD 11)
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")

add_compile_options(-pthread)
add_executable(miner_proccess main.c queues_file.h)