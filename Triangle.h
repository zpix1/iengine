//
// Created by zpix on 31.03.17.
//

#ifndef OPENGL_TRIANGLE_H
#define OPENGL_TRIANGLE_H

#include "Shape.h"
#include "Color.h"
class Triangle : public Shape{
public:
    GLfloat x1,y1,x2,y2,x3,y3;
    Color color;
public:
    Triangle(GLfloat x1, GLfloat y1, GLfloat x2,GLfloat y2,GLfloat x3,GLfloat y3, Color color);
    void apply_vector(Vector2 v);
    void gen(int mode=1);
    Vector2 get_center();

};


#endif //OPENGL_TRIANGLE_H
