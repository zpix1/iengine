#include "iengine.h"
#include <vector>

int main() {
    IEngine ei = IEngine(500, 500, "Test");

    std::vector<GLfloat> vertices({
                                          0.5f, 0.5f, 0.0f,  // Top Right
                                          0.5f, -0.5f, 0.0f,  // Bottom Right
                                          -0.5f, -0.5f, 0.0f,  // Bottom Left
                                  });
    std::vector<GLuint> indices({
                                        0, 1, 2  // Second Triangle
                                });

    std::vector<GLfloat> vertices1({
                                          -0.2f,  0.2f, 0.0f,  // Top Right
                                          -0.2f, -0.0f, 0.0f,  // Bottom Right
                                          -0.5f, -0.0f, 0.0f,  // Bottom Left
                                  });
    std::vector<GLuint> indices1({
                                        0, 1, 2  // Second Triangle
                                });


    ei.upload_shape(vertices1, indices1);
    ei.upload_shape(vertices, indices);

    ei.start_game();
}