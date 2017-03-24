//
// Created by zpix on 18.02.17.
//

#include "iengine.h"

IEngine::IEngine(int height1, int width1, const char *title, Color bg, GLFWkeyfun keycallback,GLFWmousebuttonfun mousecallback, std::function <void()> loopfunction1) {
    background = bg; //background color
    width = width1;
    height = height1;
    loopfunction = loopfunction1;
    const GLchar *vertexShaderSource = "#version 330 core\n"
            "uniform mat4 wh;\n"
            "uniform vec2 center;\n"
            "layout(location = 1) in vec4 vertexColor;\n"
            "layout (location = 0) in vec3 position;\n"
            "out vec4 fragmentColor;\n"
            "mat3 rotZ(float a){float c=cos(a),s=sin(a);return mat3(c,s,0.,-s,c,0.,0.,0.,0.);}\n"

            "void main()\n"
            "{\n"
            "mat3 trans = rotZ(1.7);\n"
            "vec3 pos = trans*vec3(position.x-center.x,position.y-center.y,0.0) + vec3(center,0.0);\n"
            "vec4 finalpos = wh*vec4(pos, 1.0);\n"
            "gl_Position = finalpos;\n"
            "fragmentColor = vertexColor;\n"
            "}\0";
    const GLchar *fragmentShaderSource = "#version 330 core\n"
            "out vec4 color;\n"
            "in vec4 fragmentColor;\n"
            "void main()\n"
            "{\n"
            "color = fragmentColor;\n"
            "}\n\0";


    std::cout << "Starting GLFW context, OpenGL 3.3" << std::endl;
    // Init GLFW
    glfwInit();
    // Set all the required options for GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // Create a GLFWwindow object that we can use for GLFW's functions
    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    glfwMakeContextCurrent(window);

    // Set the required callback functions
    glfwSetKeyCallback(window, keycallback);
    glfwSetMouseButtonCallback(window,mousecallback);

    // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
    glewExperimental = GL_TRUE;
    // Initialize GLEW to setup the OpenGL Function pointers
    glewInit();

    // Define the viewport dimensions
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);


    // Build and compile our shader program
    // Vertex shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // Check for compile time errors
    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // Fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // Check for compile time errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // Link shaders
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // Check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

}

IEngine::~IEngine() {
    glfwTerminate();
    return;
}

//void IEngine::upload_shape(std::vector<GLfloat>& vertices, std::vector<GLuint>& indices) {
//    shapes.push_back(Shape());
//    shapes.back().init(vertices,indices);
//}

void IEngine::start_game() {
    glm::mat4 mat= glm::ortho( 0.f, (float)width, (float)height, 0.f, 0.f, 0.5f );//glm::ortho(0.0f, (float)width,(float)height,0.0f, 0.5f, 100.0f);
    GLint vertexWH = glGetUniformLocation(shaderProgram, "wh");
    glm::vec3 center;
    GLint centerWH = glGetUniformLocation(shaderProgram, "center");

    while (!glfwWindowShouldClose(window)) {
        loopfunction();
        // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
        glfwPollEvents();
        // Render
        // Clear the colorbuffer
        glClearColor(background.r,background.g,background.b,background.alpha);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);

        glUniformMatrix4fv(vertexWH,1,GL_FALSE,glm::value_ptr(mat));

        // Draw our first triangle
        for (auto & shape : shapes){
            center = glm :: vec3(shape->get_center().x,shape->get_center().y,0.0);
            glUniform2f(centerWH,center.x,center.y);
            glBindVertexArray(shape->VAO);
            glDrawElements(shape->mode, shape->nindices, GL_UNSIGNED_INT, 0);
        }
        glBindVertexArray(0);
        //glDrawArrays(GL_TRIANGLES, 0, 6);

        // Swap the screen buffers
        glfwSwapBuffers(window);
    }
    // Properly de-allocate all resources once they've outlived their purpose
    for (auto & shape : shapes){
        shape->destroy();
    }
    // Terminate GLFW, clearing any resources allocated by GLFW.
    glfwTerminate();
    return;
}

void IEngine::upload(Shape *s) {
    s->gen();
    shapes.push_back(s);
}

void IEngine::regen_shapes() {
    for(auto shape: shapes){
        shape->gen(true);
    }
}

Vector2 IEngine::getCursorPos() {
    double x,y;
    glfwGetCursorPos(window,&x,&y);
    return Vector2(x, y);
}

