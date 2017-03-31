#include "iengine.h"
#include "Circle.h"
#include "Vector2.h"
#include "Utility.h"
#include "Triangle.h"
#include <cmath>
using namespace std;

const Vector2 size(1000,1000);
void mousecallback(GLFWwindow* window, int button, int action, int mods);
void keycallback(GLFWwindow* window, int key, int scancode, int action, int mode);
void loop();

IEngine ei = IEngine(size.x, size.y, "Test",Color(83,134,139,26),keycallback,mousecallback,loop);

void loop(){
}

void keycallback(GLFWwindow* window, int key, int scancode, int action, int mode){
};

void mousecallback(GLFWwindow* window, int button, int action, int mods){}
int main() {



    Triangle t(0.,0.,200.,0.,0.,100.,Color(100,0,0,255));
    ei.upload(&t);
    ei.start_game();
}