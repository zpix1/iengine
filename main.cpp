#include "iengine.h"
#include "Circle.h"
#include "Rectangle.h"
#include <vector>

int main() {
    IEngine ei = IEngine(1000, 1000, "Test",Color(83,134,139,26));

    Rectangle a(0,0,100,100);
    Circle b(100,100,100);
    ei.upload(a);
    ei.upload(b);
    ei.start_game();
}