#include "iengine.h"
#include "Circle.h"
#include "Vector2.h"
#include "Utility.h"
#include "Triangle.h"
#include "Rectangle.h"
#include <cmath>
using namespace std;

const Vector2 size(1000,100);
const int lap_heigth = 300;
const int lap_width = 50;
const int lap_offset = 100;
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
    Rectangle leftLap(lap_offset,size.y/2+lap_heigth,lap_offset+lap_width,size.y/2-lap_heigth,Color(0,0,100,256));
    Rectangle rigthLap(size.x-lap_offset,size.y/2+lap_heigth,size.x-lap_width-lap_width,size.y/2-lap_heigth,Color(0,0,100,256));

    ei.upload(&leftLap);
    ei.upload(&rigthLap);
    ei.start_game();
}