//
// Created by zpix on 10.03.17.
//

#ifndef OPENGL_LINE_H
#define OPENGL_LINE_H

#include "Shape.h"

class Line : public Shape{
    GLfloat x1,x2,y1,y2;
public:
    Line(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
    void gen();
};


#endif //OPENGL_LINE_H
