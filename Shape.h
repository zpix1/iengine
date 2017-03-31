//
// Created by zpix on 23.02.17.
//
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "Vector2.h"

#ifndef OPENGL_SHAPE_H
#define OPENGL_SHAPE_H


class Shape {
public:
    GLuint VAO;
    GLsizei nvertices;
    GLsizei nindices;
    GLenum mode;
    GLfloat angle=0.;
    void reload();
private:
    GLuint colorbuffer;
    GLuint VBO;
    GLuint EBO;
protected:
    void init(std::vector<GLfloat> &vertices, std::vector<GLuint> &indices,std::vector<GLfloat>& colors, GLenum mode);
public:
    virtual void gen(int mode=1);
    virtual Vector2 get_center();
    virtual void apply_vector(Vector2 v);
    void rotate(GLfloat angle);
    void destroy();
    void reload(std::vector<GLfloat> &vertices, std::vector<GLuint> &indices, std::vector<GLfloat> &colors, GLenum drawing_mode);
};


#endif //OPENGL_SHAPE_H
