#include "iengine.h"
#include "Circle.h"
#include "Vector2.h"
#include "Utility.h"
#include "Triangle.h"
#include "Rectangle.h"
#include <cmath>
#include <stdlib.h>

using namespace std;

const Vector2 size(1920,1080);
void mousecallback(GLFWwindow* window, int button, int action, int mods);
void keycallback(GLFWwindow* window, int key, int scancode, int action, int mode);
void loop();

IEngine ei = IEngine(size.x, size.y, "Test",Color(83,134,139,26),keycallback,mousecallback,loop);

void loop(){
}

void keycallback(GLFWwindow* window, int key, int scancode, int action, int mode){
};

void mousecallback(GLFWwindow* window, int button, int action, int mods){
};
int main() {
    Rectangle a(0,0,1000,1000,Color(0,0,0,0));
    ei.upload(&a);
    ei.start_game();
}