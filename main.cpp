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
const int lap_heigth = 150;
const int lap_width = 50;
const int lap_offset = 100;
const int ball_raduis = 50;
int lap_speed = 10;

Rectangle leftLap(lap_offset,size.y/2+lap_heigth,lap_offset+lap_width,size.y/2-lap_heigth,Color(0,0,100,256));
Rectangle rightLap(size.x-lap_offset-lap_width,size.y/2+lap_heigth,size.x-lap_offset,size.y/2-lap_heigth,Color(0,255,100,256));
Circle ball(ball_raduis,size.x/2,size.y/2,Color(220,0,100,255));
Vector2 ball_speed(-5,0);
double currentphi = ball_speed.getatan2();
void mousecallback(GLFWwindow* window, int button, int action, int mods);
void keycallback(GLFWwindow* window, int key, int scancode, int action, int mode);
void loop();

IEngine ei = IEngine(size.x, size.y, "Test",Color(83,134,139,26),keycallback,mousecallback,loop);

void loop(){
    leftLap.y1 = ball.y+lap_heigth;
    leftLap.y2 = ball.y-lap_heigth;

    rightLap.y1 = ei.getCursorPos().y+lap_heigth;
    rightLap.y2 = ei.getCursorPos().y-lap_heigth;

    ball.apply_vector(ball_speed);
    ball.angle = ball_speed.getatan2();
    if (ball.y-ball_raduis<=0 || ball.y+ball_raduis>=size.y) {
        ball_speed.y *= -1;
    } else if (ball.x-ball_raduis<=0){

        system("notify-send 'CHELOVEKKK'");

        cout << "CHELOVEK WINS!!!" << endl;
        ball.x = size.x/2;
        ball.y = size.y/2;
        ball_speed = Vector2(Utility::randFloat()*10-5.,Utility::randFloat()*10-5.);
        lap_speed = 5;
    } else if (ball.x+ball_raduis>=size.x){
        system("notify-send 'COMPUTACTER'");
        cout << "COMPUTACTER WINS!!!" << endl;
        ball.x = size.x/2;
        ball.y = size.y/2;
        ball_speed = Vector2(Utility::randFloat()*10-5.,Utility::randFloat()*10-5.);
        lap_speed = 5;
    } else if (ball.x-ball_raduis < leftLap.x2  && (ball.y+ball_raduis>leftLap.y2 && ball.y-ball_raduis<leftLap.y1)) {
        ball_speed.x *=-1;
        ball_speed = ball_speed * 2.;
        lap_speed *= 2;
    } else if (ball.x+ball_raduis > rightLap.x1  && (ball.y+ball_raduis>rightLap.y2 && ball.y-ball_raduis<rightLap.y1)) {
        ball_speed.x *=-1;
        ball_speed = ball_speed * 2.;
        lap_speed *= 2;
    }
    leftLap.reload();
    rightLap.reload();
    ball.reload();
}

void keycallback(GLFWwindow* window, int key, int scancode, int action, int mode){
    cout << key << endl;
    switch (key){
        case GLFW_KEY_DOWN:
            rightLap.apply_vector(Vector2(0,lap_speed));
            break;
        case GLFW_KEY_UP:
            rightLap.apply_vector(Vector2(0,-lap_speed));
            break;
        case 'S':
            leftLap.apply_vector(Vector2(0,lap_speed));
            break;
        case 'W':
            leftLap.apply_vector(Vector2(0,-lap_speed));
            break;
    }
    rightLap.reload();
    leftLap.reload();
};

void mousecallback(GLFWwindow* window, int button, int action, int mods){
};
int main() {
    ei.upload(&leftLap);
    ei.upload(&rightLap);
    ei.upload(&ball);
    ei.start_game();
}