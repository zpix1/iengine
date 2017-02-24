//
// Created by zpix on 23.02.17.
//
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#ifndef OPENGL_SHAPE_H
#define OPENGL_SHAPE_H


class Shape {
public:
    GLuint VBO;
    GLuint VAO;
    GLuint EBO;
    GLsizei nvertices;
    GLsizei nindices;
public:
    Shape(std::vector<GLfloat>& vertices, std::vector<GLuint>& indices);
    ~Shape();
};


#endif //OPENGL_SHAPE_H
