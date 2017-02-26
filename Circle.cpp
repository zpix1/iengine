//
// Created by zpix on 26.02.17.
//

#include <math.h>
#include "Circle.h"

Circle::Circle(GLfloat radius1, GLfloat x1, GLfloat y1) {
    x = x1;
    y = y1;
    radius = radius1;
}

void Circle::gen() {
    int n = 1000;

    std::vector<GLfloat> vertices((unsigned long) (3 * (n + 1)));

    vertices[0] = x;
    vertices[1] = y;
    vertices[2] = 0.0f;

    std::vector<GLuint> indices((unsigned long) (3 * n));
    for (int i = 0; i < n; i++) {
        GLfloat a = (GLfloat) (((2 * M_PI) / n) * i);
        vertices[(i + 1) * 3 + 0] = x + radius * cos(a);
        vertices[(i + 1) * 3 + 1] = y + radius * sin(a);
        vertices[(i + 1) * 3 + 2] = 0.0f;

        indices[3 * i + 0] = 0;
        indices[3 * i + 1] = i + 1;
        indices[3 * i + 2] = i==n-1 ? 1 : i+2;
    }

    init(vertices,indices);
}
