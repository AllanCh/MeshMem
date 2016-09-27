cmake_minimum_required(VERSION 3.6)
project(Mesh_Mem)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
set(SOURCE_FILES main.cpp Client.h Client.cpp xReference.h ManejadorJson.cpp API.cpp API.h base64.h base64.cpp)
add_executable(Mesh_Mem ${SOURCE_FILES})

include(FindPkgConfig)
find_package(Jsoncpp REQUIRED)



target_link_libraries(Mesh_Mem /usr/lib/libjson_linux-gcc-4.8_libmt.so)
