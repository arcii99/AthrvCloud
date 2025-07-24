//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Shapeshift {STAR, PLANET, MOON};
struct SpaceObject {
    enum Shapeshift shape;
    char* name;
    int distance_from_earth;
};

void print_space_object(struct SpaceObject* obj) {
    printf("%s is a ", obj->name);
    switch (obj->shape) {
        case STAR:
            printf("star");
            break;
        case PLANET:
            printf("planet");
            break;
        case MOON:
            printf("moon");
            break;
    }
    printf(" that is %d light years from Earth.\n", obj->distance_from_earth);
}

void shape_shift(struct SpaceObject* obj) {
    int num = rand() % 3;
    switch (num) {
        case 0:
            obj->shape = STAR;
            break;
        case 1:
            obj->shape = PLANET;
            break;
        case 2:
            obj->shape = MOON;
            break;
    }
    switch (obj->shape) {
        case STAR:
            obj->name = "Sirius";
            obj->distance_from_earth = 8;
            break;
        case PLANET:
            obj->name = "Kepler-438b";
            obj->distance_from_earth = 640;
            break;
        case MOON:
            obj->name = "Ganymede";
            obj->distance_from_earth = 628;
            break;
    }
}

int main() {
    srand(time(NULL));
    struct SpaceObject obj = {STAR, "Sirius", 8};
    print_space_object(&obj);
    for (int i = 0; i < 10; i++) {
        shape_shift(&obj);
        print_space_object(&obj);
    }
    return 0;
}