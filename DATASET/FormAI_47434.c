//FormAI DATASET v1.0 Category: Physics simulation ; Style: light-weight
#include<stdio.h>
#include<math.h>

#define G 6.674e-11 //Gravitational constant

struct object {
    double mass, x, y, vx, vy, ax, ay; //mass, position, velocity, acceleration in x and y directions
};

void updatePosition(struct object *obj, double t) {
    obj->x = obj->x + obj->vx * t + 0.5 * obj->ax * t * t;
    obj->y = obj->y + obj->vy * t + 0.5 * obj->ay * t * t;
}

void updateVelocity(struct object *obj, double t) {
    obj->vx = obj->vx + obj->ax * t;
    obj->vy = obj->vy + obj->ay * t;
}

void updateAcceleration(struct object *obj1, struct object *obj2) {
    double r = sqrt(pow(obj1->x - obj2->x, 2) + pow(obj1->y - obj2->y, 2));
    double F = G * obj1->mass * obj2->mass / (r * r);
    obj1->ax = -F * (obj1->x - obj2->x) / (obj1->mass * r);
    obj1->ay = -F * (obj1->y - obj2->y) / (obj1->mass * r);
}

int main() {
    struct object object1 = {5.97e24, 0, 0, 0, 0, 0, 0}; //Earth
    struct object object2 = {7.35e22, 3.84e8, 0, 0, 1022, 0, 0}; //Moon
    double t, dt = 60;
    printf("Time(s)\t\tDistance(m)\n");
    for(t = 0; t <= 3600*24*30; t += dt) { //30 days
        updateAcceleration(&object1, &object2);
        updateAcceleration(&object2, &object1);
        updateVelocity(&object1, dt);
        updateVelocity(&object2, dt);
        updatePosition(&object1, dt);
        updatePosition(&object2, dt);
        double distance = sqrt(pow(object1.x - object2.x, 2) + pow(object1.y - object2.y, 2));
        printf("%lf\t%lf\n", t, distance);
    }
    return 0;
}