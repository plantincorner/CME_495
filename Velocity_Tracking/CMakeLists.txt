cmake_minimum_required(VERSION 3.0)
enable_language(CXX)
enable_language(C)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -std=c++11 -pthread -I/usr/local/include -L/opt/vc/lib -lraspicam -lraspicam_cv -lmmal -lmmal_core -lmmal_util -lopencv_highgui -lopencv_video -lopencv_imgproc -lopencv_core -lwiringPi")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall -lwiringPi")
project(CME_495)

include_directories(includes)

file(GLOB SOURCES "src/*.c*")

add_executable(velocityDetection ${SOURCES})
