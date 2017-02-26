//
// Created by zpix on 18.02.17.
//
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

#include "Shape.h"
#include "Color.h"

#ifndef OPENGL_IENGINE_H
#define OPENGL_IENGINE_H


class IEngine {
    GLFWwindow *window;
    GLuint shaderProgram;
    std::vector<Shape> shapes;
    Color background;
public:
    IEngine(int height, int width, const char *title, Color bg);

    ~IEngine();

    //void upload_vector(GLfloat *vertices, GLuint *indices);
    void start_game();
    void upload(Shape& s);
};


#endif //OPENGL_IENGINE_H
