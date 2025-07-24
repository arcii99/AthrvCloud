//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
    double z;
} Point;

typedef struct {
    double mass;
    Point position;
    Point velocity;
} Object;

Object sun = {1.989, {0, 0, 0}, {0, 0, 0}};
Object earth = {0.000003003, {149598023e3, 0, 0}, {0, 29800, 0}};
Object moon = {0.00000007346, {149598023e3 + 384400e3, 0, 0}, {0, 29800 + 1022, 0}};

void updateVelocity(Object *obj1, Object *obj2, double dt) {
    double dx = obj1->position.x - obj2->position.x;
    double dy = obj1->position.y - obj2->position.y;
    double dz = obj1->position.z - obj2->position.z;
    double d = sqrt(dx*dx + dy*dy + dz*dz);
    double f = 6.674e-11 * obj1->mass * obj2->mass / (d*d);
    obj1->velocity.x -= f * dx / d * dt / obj1->mass;
    obj1->velocity.y -= f * dy / d * dt / obj1->mass;
    obj1->velocity.z -= f * dz / d * dt / obj1->mass;
}

void updatePosition(Object *obj, double dt) {
    obj->position.x += obj->velocity.x * dt;
    obj->position.y += obj->velocity.y * dt;
    obj->position.z += obj->velocity.z * dt;
}

void simulate(double duration, double dt) {
    int steps = duration / dt;
    for (int i = 0; i < steps; i++) {
        updateVelocity(&earth, &sun, dt);
        updateVelocity(&moon, &earth, dt);
        updateVelocity(&moon, &sun, dt);
        updatePosition(&earth, dt);
        updatePosition(&moon, dt);
        printf("Earth position: (%e, %e, %e)\n", earth.position.x, earth.position.y, earth.position.z);
        printf("Moon position: (%e, %e, %e)\n", moon.position.x, moon.position.y, moon.position.z);
    }
}

int main() {
    simulate(3600*24*30, 1000);
    return 0;
}