cmake_minimum_required(VERSION 3.13)
project(MostOccuredLetters VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE main.cpp challenge_1_most_occurredLetters.cpp)

add_executable(run ${SOURCE})