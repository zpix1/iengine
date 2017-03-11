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
    GLuint VAO;
    GLsizei nvertices;
    GLsizei nindices;
    GLenum mode;
private:
    GLuint colorbuffer;
    GLuint VBO;
    GLuint EBO;
protected:
    void init(std::vector<GLfloat> &vertices, std::vector<GLuint> &indices,std::vector<GLfloat>& colors, GLenum mode);
public:
    virtual void gen();
    void destroy();
};


#endif //OPENGL_SHAPE_H
