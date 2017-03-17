//
// Created by zpix on 26.02.17.
//

#include <math.h>
#include "Rectangle.h"

Rectangle::Rectangle(GLfloat xx1, GLfloat xy1, GLfloat xx2, GLfloat xy2, Color color1) {
    x1 = xx1;
    x2 = xx2;
    y1 = xy1;
    y2 = xy2;
    color = color1;
}

void Rectangle::gen(int mode) {

    std::vector<GLfloat> vertices {x1,y1,0.0f,x1,y2,0.0f,x2,y2,0.0f,x2,y1,0.0f};
    std::vector<GLuint> indices {0,1,2,0,3,2};
    std::vector<GLfloat > colors {color.r,color.g,color.b,color.alpha,color.r,color.g,color.b,color.alpha,color.r,color.g,color.b,color.alpha,color.r,color.g,color.b,color.alpha};
    mode ? init(vertices,indices,colors,GL_TRIANGLES) : reload(vertices,indices,colors,GL_TRIANGLES);
}
