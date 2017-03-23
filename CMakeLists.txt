cmake_minimum_required(VERSION 3.5)
project(opengl)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lGL -lglfw -lGLEW")

set(SOURCE_FILES main.cpp iengine.cpp iengine.h Shape.cpp Shape.h Circle.cpp Circle.h Color.cpp Color.h Rectangle.cpp Rectangle.h Line.cpp Line.h Vector2.cpp Vector2.h Utility.cpp Utility.h)
add_executable(opengl ${SOURCE_FILES})