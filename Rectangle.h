//
// Created by zpix on 26.02.17.
//


#ifndef OPENGL_RECTANGLE_H
#define OPENGL_RECTANGLE_H

#include "Shape.h"
#include "Color.h"
class Rectangle: public Shape {
    GLfloat x1,x2,y1,y2;
    Color color;
public:
    Rectangle(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2,Color color);
    void gen();
};


#endif //OPENGL_RECTANGLE_H
