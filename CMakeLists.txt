cmake_minimum_required(VERSION 3.5)
project(opengl)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lGL -lglfw -lGLEW")

set(SOURCE_FILES main.cpp iengine.cpp iengine.h shape.cpp shape.h Circle.cpp Circle.h)
add_executable(opengl ${SOURCE_FILES})