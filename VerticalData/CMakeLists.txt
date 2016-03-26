cmake_minimum_required(VERSION 3.0)
enable_language(CXX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
project(CME_495)

include_directories(includes)

file(GLOB SOURCES "src/*.cpp")

add_executable(velocityDetection ${SOURCES})
