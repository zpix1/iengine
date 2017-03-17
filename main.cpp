#include "iengine.h"
#include "Circle.h"
#include "Rectangle.h"
#include <vector>
void keycallback(GLFWwindow* window, int key, int scancode, int action, int mode);

IEngine ei = IEngine(1000, 1000, "Test",Color(83,134,139,26),keycallback);

Rectangle d(0,0,500,500,Color(255,0,0,255));
void keycallback(GLFWwindow* window, int key, int scancode, int action, int mode){
    int speed = 10;
    switch (key){
        case GLFW_KEY_UP:
            d.y1-=speed;d.y2-=speed;
        break;
        case GLFW_KEY_DOWN:
            d.y1+=speed;d.y2+=speed;
            break;
        case GLFW_KEY_LEFT:
            d.x1-=speed;d.x2-=speed;
            break;
        case GLFW_KEY_RIGHT:
            d.x1+=speed;d.x2+=speed;
            break;
    }
    std::cout<<key<<" "<<action<<std::endl;
    d.reload();

}

int main() {
    ei.upload(&d);
    for (int x=100;x<1000;x+=100){
        for (int y=100;y<1000;y+=100){
            Circle *c= new Circle((x*x+y*y)/50000,x,y,Color(x,y,abs(x-y),100));
            ei.upload(c);
        }
    }
    ei.start_game();
}