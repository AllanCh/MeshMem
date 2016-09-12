cmake_minimum_required(VERSION 3.6)
project(Mesh_Mem)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set(SOURCE_FILES main.cpp Client.h Client.cpp xReference.h)
add_executable(Mesh_Mem ${SOURCE_FILES})