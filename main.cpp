#include "iengine.h"
#include "Circle.h"
#include "Rectangle.h"
#include <vector>

int main() {
    IEngine ei = IEngine(1000, 1000, "Test",Color(83,134,139,26));
    Circle b(500,500,500,Color(255,0,100,255));
    Circle c(300,500,500,Color(10,0,255,255));
    Rectangle d(0,0,500,500,Color(255,0,0,255));
    ei.upload(b);
    ei.upload(c);

    ei.upload(d);

//    for (int x=100;x<1000;x+=100){
//        for (int y=100;y<1000;y+=100){
//            Circle c((x+y)/20,x,y,Color(100,0,100,100));
//            ei.upload(c);
//        }
//    }
    ei.start_game();
}