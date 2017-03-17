//
// Created by zpix on 26.02.17.
//


#ifndef OPENGL_CIRCLE_H
#define OPENGL_CIRCLE_H

#include "Shape.h"
#define M_PI          3.141592653589793238462643383279502884
#include <math.h>
#include "Color.h"

class Circle: public Shape {
    GLfloat x,y,radius;
    Color color;
public:
    Circle(GLfloat radius, GLfloat x, GLfloat y, Color color);
    void gen(int mode=1);
};


#endif //OPENGL_CIRCLE_H
