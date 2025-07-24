//FormAI DATASET v1.0 Category: Physics simulation ; Style: sophisticated
#include <stdio.h>
#include <math.h>

#define pi 3.14159265358979323846

double mass = 1;        // mass in kg
double dt = 0.01;       // time interval 

struct Vec {
    double x, y;
};

struct Object {
    struct Vec pos;
    struct Vec vel;
    struct Vec accel;
};

void update_accel(struct Object *o1, struct Object *o2) {
    double dx = o1->pos.x - o2->pos.x;
    double dy = o1->pos.y - o2->pos.y;
    double r = sqrt(dx*dx + dy*dy);
    double f = mass*mass / (r*r);
    double fx = f * dx / r;
    double fy = f * dy / r;
    o1->accel.x = -fx / mass;
    o1->accel.y = -fy / mass;
    o2->accel.x = fx / mass;
    o2->accel.y = fy / mass;
}

void update_vel(struct Object *o) {
    o->vel.x += o->accel.x * dt;
    o->vel.y += o->accel.y * dt;
}

void update_pos(struct Object *o) {
    o->pos.x += o->vel.x * dt;
    o->pos.y += o->vel.y * dt;
}

void simulate(struct Object *o1, struct Object *o2, int steps) {
    for (int i = 0; i < steps; i++) {
        update_accel(o1, o2);
        update_vel(o1);
        update_pos(o1);
        update_accel(o2, o1);
        update_vel(o2);
        update_pos(o2);
        printf("Object 1: (%f, %f)\n", o1->pos.x, o1->pos.y);
        printf("Object 2: (%f, %f)\n", o2->pos.x, o2->pos.y);
        printf("--------------\n");
    }
}

int main() {
    struct Object o1 = { {0, 0}, {0, 0}, {0, 0} };
    struct Object o2 = { {1, 0}, {0, 1}, {0, 0} };
    double period = 2*pi*sqrt(1);   // period of circular orbit
    int steps = (int) (period / dt);
    simulate(&o1, &o2, steps);
    return 0;
}