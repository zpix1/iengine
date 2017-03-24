#include "iengine.h"
#include "Circle.h"
#include "Vector2.h"
#include "Utility.h"
#include <cmath>
using namespace std;

const Vector2 size(1000,1000);
void mousecallback(GLFWwindow* window, int button, int action, int mods);
void keycallback(GLFWwindow* window, int key, int scancode, int action, int mode);
void loop();

IEngine ei = IEngine(size.x, size.y, "Test",Color(83,134,139,26),keycallback,mousecallback,loop);


vector<Circle*> circles;
vector<Vector2> speeds;
int r = 10;
int a = 1;
Vector2 gravity (0.1,0.1);
void loop(){
//    for(int i=0;i<circles.size();i++) {
////        speeds[i].y += gravity.y;
////        speeds[i].x -= gravity.x;
//        Circle* d = circles[i];
//        if (d->x+r > size.x) {
//            speeds[i].x = -speeds[i].x;
//        }
//        if (d->x-r < 0) {
//            speeds[i].x = -speeds[i].x;
//        }
//        if (d->y+r > size.y) {
//            speeds[i].y = -speeds[i].y;
//        }
//        if (d->y-r < 0) {
//            speeds[i].y = -speeds[i].y;
//        }
//
//        d->apply_vector(speeds[i]);
//        d->reload();
//    }
    for(int i=0;i<circles.size();i++) {
        Circle* d = circles[i];
        Vector2 mouse = ei.getCursorPos();
        double wantedphi = atan2(mouse.y - d->y,mouse.x - d->x);
        double currentphi = atan2(speeds[i].y,speeds[i].x);
        double newphi = currentphi + (wantedphi - currentphi)*0.1;
        if (abs(newphi-0.001) < 0){
            cout << 'a';
            newphi = Utility::randFloat();
        }
        double currentv = sqrt(speeds[i].x*speeds[i].x + speeds[i].y*speeds[i].y);
        speeds[i].x = currentv * cos(newphi);
        speeds[i].y = currentv * sin(newphi);
        d->apply_vector(speeds[i]);
        d->reload();
    }
}

void keycallback(GLFWwindow* window, int key, int scancode, int action, int mode){
    cout << key << scancode << action <<endl;
    if (1) {
        int dvx = 0, dvy = 0;
        switch (key) {
            case GLFW_KEY_RIGHT:
                dvx = a;
                break;
            case GLFW_KEY_LEFT:
                dvx = -a;
                break;
            case GLFW_KEY_UP:
                dvy = -a;
                break;
            case GLFW_KEY_DOWN:
                dvy = a;
                break;

            case GLFW_KEY_W:
                gravity = Vector2(0,-0.1);
                break;
            case GLFW_KEY_A:
                gravity = Vector2(0.1,0);
                break;
            case GLFW_KEY_S:
                gravity = Vector2(0,0.1);
                break;
            case GLFW_KEY_D:
                gravity = Vector2(0.1,0);
                break;
        }
        for (int i = 0; i < circles.size(); i++) {
            Circle *d = circles[i];
            speeds[i].y += dvy;
            speeds[i].x += dvx;
            d->apply_vector(speeds[i]);
            d->reload();
        }
    }
};

void mousecallback(GLFWwindow* window, int button, int action, int mods){
    for(int i=0;i<circles.size();i++) {
        Circle* d = circles[i];
        Vector2 mouse = ei.getCursorPos();
        double wantedphi = atan2(mouse.y - d->y,mouse.x - d->x);
        double currentphi = atan2(speeds[i].y,speeds[i].x);
        double newphi = currentphi + (wantedphi - currentphi)*0.1;
        double currentv = sqrt(speeds[i].x*speeds[i].x + speeds[i].y*speeds[i].y)*0.9;
        speeds[i].x = currentv * cos(newphi);
        speeds[i].y = currentv * sin(newphi);
        d->apply_vector(speeds[i]);
        d->reload();
    }
    cout << button << " " << ei.getCursorPos().x << endl;
}
int main() {
    for (int x=100;x<1000;x+=100){
        for (int y=100;y<1000;y+=100){
            cout << Utility::randFloat()-1 << endl;
            Circle *c= new Circle(r,x,y,Color(200,200,0,100));
            ei.upload(c);
            circles.push_back(c);
            speeds.push_back(Vector2((Utility::randFloat()-0.5)*5.0,(Utility::randFloat()-0.5)*5.0));
            cout << speeds.back().x << " " << speeds.back().y << endl;
        }
    }
    ei.start_game();
}