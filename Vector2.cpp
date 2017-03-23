//
// Created by zpix on 23.03.17.
//

#include "Vector2.h"

Vector2::Vector2(float x1, float y1) {
    x = x1;
    y = y1;
}

Vector2 Vector2::operator+(float x1) {
    return Vector2(x+x1, y+x1);
}

Vector2 Vector2::operator+(Vector2 v) {
    return Vector2(x+v.x, y+v.y);
}
