//
// Created by zpix on 10.03.17.
//

#include "Line.h"

Line::Line(GLfloat xx1, GLfloat xy1, GLfloat xx2, GLfloat xy2) {
    x1 = xx1;
    x2 = xx2;
    y1 = xy1;
    y2 = xy2;
}

void Line::gen() {
    std::vector<GLfloat> vertices {x1,y1,x2,y2};
    std::vector<GLuint> indices {0,1};


    init(vertices,indices,GL_LINES);
}
