//
// Created by zpix on 26.02.17.
//
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#ifndef OPENGL_COLOR_H
#define OPENGL_COLOR_H

class Color {
public:
    Color();

    GLfloat r,g,b,alpha;
    Color(int r1,int g1, int b1, int alpha1);
};


#endif //OPENGL_COLOR_H
