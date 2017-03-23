#include "iengine.h"
#include "Circle.h"
#include "Vector2.h"
#include "Utility.h"
using namespace std;

const Vector2 size(1000,1000);

void keycallback(GLFWwindow* window, int key, int scancode, int action, int mode){};
void loop();

IEngine ei = IEngine(size.x, size.y, "Test",Color(83,134,139,26),keycallback,loop);


vector<Circle*> circles;
vector<Vector2> speeds;

void loop(){
    for(int i=0;i<circles.size();i++) {
        Circle* d = circles[i];
        if (d->x > size.x) {
            speeds[i].x = -speeds[i].x;
        }
        if (d->x < 0) {
            speeds[i].x = -speeds[i].x;
        }
        if (d->y > size.y) {
            speeds[i].y = -speeds[i].y;
        }
        if (d->y < 0) {
            speeds[i].y = -speeds[i].y;
        }

        d->apply_vector(speeds[i]);
        d->reload();
    }
}

int main() {
    for (int x=100;x<1000;x+=50){
        for (int y=100;y<1000;y+=50){
            cout << Utility::randFloat()-1 << endl;
            Circle *c= new Circle(Utility::randInt(10,30),x,y,Color(x/1000.0*256.0,y/1000.0*256.0,abs(x-y),100));
            ei.upload(c);
            circles.push_back(c);
            speeds.push_back(Vector2((Utility::randFloat()-0.5)*5.0,(Utility::randFloat()-0.5)*5.0));
            cout << speeds.back().x << " " << speeds.back().y << endl;
        }
    }
    ei.start_game();
}