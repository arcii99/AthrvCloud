//FormAI DATASET v1.0 Category: Physics simulation ; Style: single-threaded
#include <stdio.h>
#include <math.h>

#define GRAV_CONST 6.67430E-11     // gravitational constant G

typedef struct vector {
    double x, y, z;
} Vector;

typedef struct object {
    Vector pos, vel, acc;
    double mass;
} Object;

int main() {
    double dt = 0.01;               // time step
    Object obj1 = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 100};
    Object obj2 = {{1E6, 0, 0}, {0, 10, 0}, {0, 0, 0}, 200};
    double dist = sqrt(pow(obj1.pos.x - obj2.pos.x, 2) 
                     + pow(obj1.pos.y - obj2.pos.y, 2) 
                     + pow(obj1.pos.z - obj2.pos.z, 2));
    Vector force = {GRAV_CONST * obj1.mass * obj2.mass / pow(dist, 2), 0, 0};
    Vector force2 = {GRAV_CONST * obj2.mass * obj1.mass / pow(dist, 2), 0, 0};
    obj1.acc.x = force.x / obj1.mass;
    obj2.acc.x = force2.x / obj2.mass;
    for (int i = 0; i < 1000; i++) {
        obj1.vel.x += obj1.acc.x * dt;
        obj1.pos.x += obj1.vel.x * dt;
        obj2.vel.x += obj2.acc.x * dt;
        obj2.pos.x += obj2.vel.x * dt;
        dist = sqrt(pow(obj1.pos.x - obj2.pos.x, 2) 
                  + pow(obj1.pos.y - obj2.pos.y, 2) 
                  + pow(obj1.pos.z - obj2.pos.z, 2));
        force.x = GRAV_CONST * obj1.mass * obj2.mass / pow(dist, 2);
        force2.x = GRAV_CONST * obj2.mass * obj1.mass / pow(dist, 2);
        obj1.acc.x = force.x / obj1.mass;
        obj2.acc.x = force2.x / obj2.mass;
        printf("Time: %.2f, Object 1: (%.2f, %.2f), Object 2: (%.2f, %.2f)\n", dt * i, obj1.pos.x, obj1.pos.y, obj2.pos.x, obj2.pos.y);
    }
    return 0;
}