# IEngine
A very simple OpenGL C++ engine to prototype simple games or school projects using OpenGL

Let's review main.cpp:
```C++
#include "iengine.h" // Include core of engine
#include "Circle.h" // Include circle class
#include "Vector2.h" // Include xy-vector class
#include "Utility.h" // Include utility functions
#include "Triangle.h" // Include triagle class
#include "Rectangle.h" // Include rectangle class
#include <cmath>
#include <stdlib.h>

using namespace std;

const Vector2 size(1920,1080); // Window resolution
void mousecallback(GLFWwindow* window, int button, int action, int mods); // Mouse and key callback functions
void keycallback(GLFWwindow* window, int key, int scancode, int action, int mode);
void loop(); // Loop functions
// Creates IEngine object
// IEngine(int window_width, int windows_height, string window_title, Color background_color, function keycallback, function mousecallback, function loop)
IEngine ei = IEngine(size.x, size.y, "Test",Color(83,134,139,26),keycallback,mousecallback,loop);

void loop(){
}

void keycallback(GLFWwindow* window, int key, int scancode, int action, int mode){
};

void mousecallback(GLFWwindow* window, int button, int action, int mods){
};
int main() {
    // Creates rectangle object 1000x1000 with rgb(0,0,0) color
    Rectangle a(0,0,1000,1000,Color(0,0,0,0));
    // Uploads a to core
    ei.upload(&a);
    // Starts main loop (loop function)
    ei.start_game();
}
```
