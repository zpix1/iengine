#include "iengine.h"
#include "Circle.h"
#include <vector>

int main() {
    IEngine ei = IEngine(500, 500, "Test");

    Circle a(0.5f,0.0f,0.0f);
    Circle b(0.2f,0.4f,0.4f);
    ei.upload(a);
    ei.upload(b);
    ei.start_game();
}