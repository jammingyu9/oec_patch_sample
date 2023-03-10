cmake_minimum_required(VERSION 3.16.3)

project(oec_patch_sample VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Threads REQUIRED)

add_executable(oec_patch_sample)

target_sources(oec_patch_sample PRIVATE src/main.cpp
                                	include/SignalHandler.hpp
	                                src/SignalHandler.cpp
        	                        include/ConfigParser.hpp
                	                src/ConfigParser.cpp)

target_link_libraries(Threads::Threads)
target_include_directories(oec_patch_sample PUBLIC "${PROJECT_SOURCE_DIR}/include")
