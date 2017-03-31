//
// Created by zpix on 31.03.17.
//

#include "Triangle.h"

Triangle::Triangle(GLfloat x11, GLfloat y11, GLfloat x21, GLfloat y21, GLfloat x31, GLfloat y31, Color color1) {
    color = color1;
    x1 = x11;
    x2 = x21;
    x3 = x31;

    y1 = y11;
    y2 = y21;
    y3 = y31;
}

void Triangle::gen(int mode) {

    std::vector<GLfloat> vertices(3*3);



    vertices[0] = x1;
    vertices[1] = y1;
    vertices[2] = 0.0f;

    vertices[3] = x2;
    vertices[4] = y2;
    vertices[5] = 0.0f;

    vertices[6] = x3;
    vertices[7] = y3;
    vertices[8] = 0.0f;

    std::vector<GLuint> indices {0,1,2};

    std::vector<GLfloat> colors (3*4);
    for (int i=0;i<3;i++){
        colors[4 * i + 0] = color.r; //r
        colors[4 * i + 1] = color.g; //g
        colors[4 * i + 2] = color.b; //b
        colors[4 * i + 3] = color.alpha;  //a
    }
    mode ? init(vertices,indices,colors,GL_TRIANGLES) : reload(vertices,indices,colors,GL_TRIANGLES);
}

void Triangle::apply_vector(Vector2 v) {
    x1 += v.x;
    x2 += v.x;
    x3 += v.x;

    y1 += v.y;
    y2 += v.y;
    y3 += v.y;
}

Vector2 Triangle::get_center() {
    return Vector2((x1+x2+x3)/3,(y1+y2+y3)/3);
}
