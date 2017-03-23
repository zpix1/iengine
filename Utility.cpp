//
// Created by zpix on 23.03.17.
//

#include "Utility.h"

int Utility::randInt(int min, int max) {
    return min + (std::rand() % (int)(max - min + 1));
}

double Utility::randFloat(){
    return ((double) rand() / (RAND_MAX));
}
