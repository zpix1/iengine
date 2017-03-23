//
// Created by zpix on 23.03.17.
//
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#ifndef OPENGL_VECTOR2_H
#define OPENGL_VECTOR2_H


class Vector2 {
public:
    GLfloat x,y;
    Vector2(float x, float y);
    Vector2 operator+(float x);
    Vector2 operator+(Vector2 v);
};


#endif //OPENGL_VECTOR2_H
