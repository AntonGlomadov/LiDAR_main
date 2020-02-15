cmake_minimum_required(VERSION 3.15)
project(LiDAR_main)

set(CMAKE_CXX_STANDARD 14)

set(Boost_INCLUDE_DIR /usr/local/Cellar/boost/1.72.0/include)
set(Boost_LIBRARY_DIR /usr/local/Cellar/boost/1.72.0/lib)


find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_executable(LiDAR_main main.cpp)