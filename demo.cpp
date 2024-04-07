//
// Created by lWoHvYe on 2024/3/29.
//

#include "demo.h"
#include <cstdlib>

void demo_1() {
    char *name1 = (char *) malloc(2 + 1);
    char *name2 = new char[2 + 1];

    free(name1);
    delete[] name2;
}