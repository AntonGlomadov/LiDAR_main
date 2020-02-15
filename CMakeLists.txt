cmake_minimum_required(VERSION 3.15)
project(LiDAR_main)

set(CMAKE_CXX_STANDARD 14)

# Boost include
set(Boost_INCLUDE_DIR /usr/local/Cellar/boost/1.72.0/include)
set(Boost_LIBRARY_DIR /usr/local/Cellar/boost/1.72.0/lib)
find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

# SFML include
set(SFML_INCLUDE_DIR "./SFML/include")
set(SFML_LIBRARY_DIR "./SFML/lib")
link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

add_executable(LiDAR_main main.cpp)
target_link_libraries(LiDAR_main sfml-graphics sfml-window sfml-system)