cmake_minimum_required(VERSION 3.13)
project(FilenameFinder VERSION 1.0)

set(CMAKE_C_STANDARD 17)

set(SOURCE main.c filenameFinder.c)

add_executable(run ${SOURCE})