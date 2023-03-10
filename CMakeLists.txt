cmake_minimum_required(VERSION 3.16.3)

project(oec_patch_sample VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Threads REQUIRED)

add_executable(oec_patch_sample)

target_sources(oec_patch_sample main.cpp
                                SignalHandler.hpp
                                SignalHandler.cpp
                                ConfigParser.hpp
                                ConfigParser.cpp)

target_link_libraries(Threads::Threads)
