//
// Created by zpix on 18.02.17.
//
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <functional>
#include "Shape.h"
#include "Color.h"

#ifndef OPENGL_IENGINE_H
#define OPENGL_IENGINE_H


class IEngine {
    GLFWwindow *window;
    GLuint shaderProgram;
    std::vector<Shape*> shapes;
    Color background;
    int width,height;
public:
    IEngine(int height, int width, const char *title, Color bg, GLFWkeyfun keycallback);

    ~IEngine();

    //void upload_vector(GLfloat *vertices, GLuint *indices);
    void start_game();
    void upload(Shape *s);
    void regen_shapes();
};


#endif //OPENGL_IENGINE_H
