cmake_minimum_required(VERSION 3.6)
project(Trees)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES SameTrees.cpp)
add_executable(Trees ${SOURCE_FILES})