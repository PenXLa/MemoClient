cmake_minimum_required(VERSION 3.14)
project(MemoClient)

set(CMAKE_CXX_STANDARD 17)
link_libraries(ws2_32 wsock32)
set(CMAKE_EXE_LINKER_FLAGS -static)

add_executable(MemoClient main.cpp)