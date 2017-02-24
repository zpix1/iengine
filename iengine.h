//
// Created by zpix on 18.02.17.
//
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

#include "shape.h"

#ifndef OPENGL_IENGINE_H
#define OPENGL_IENGINE_H


class IEngine {
    GLFWwindow *window;
    GLuint shaderProgram;
    std::vector<Shape> shapes;
public:
    IEngine(int height, int width, const char *title);

    ~IEngine();

    //void upload_vector(GLfloat *vertices, GLuint *indices);
    void upload_shape(std::vector<GLfloat>& vertices, std::vector<GLuint>& indices);
    void start_game();
};


#endif //OPENGL_IENGINE_H
