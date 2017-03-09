#include "iengine.h"
#include "Circle.h"
#include "Rectangle.h"
#include <vector>

int main() {
    IEngine ei = IEngine(500, 500, "Test",Color(83,134,139,26));

    Circle head(0.2f,0.0f,0.3f);
    Rectangle c(-0.1f,-0.3f,0.1f,0.3f);
    ei.upload(head);
    ei.upload(c);
    ei.start_game();
}