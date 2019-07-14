cmake_minimum_required(VERSION 3.14)
project(Third_web_stat)

set(CMAKE_CXX_STANDARD 17)

add_executable(Third_web_stat main.cpp http_request.h stats.h stats.cpp)