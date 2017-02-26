//
// Created by zpix on 26.02.17.
//

#include "Color.h"


Color::Color(int r1, int g1, int b1, int alpha1) {
    r = (GLfloat)r1 / 256;
    g = (GLfloat)g1 / 256;
    b = (GLfloat)b1 / 256;
    alpha = (GLfloat)alpha1 / 256;
}
Color::Color() {}