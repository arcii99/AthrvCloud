//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: genious
#include <stdio.h>
#include <math.h>

#define G 6.674e-11

typedef struct {
    double mass;
    double x, y, z;
    double vx, vy, vz;
    double ax, ay, az;
} body;

body sun = { 1.989e30, 0, 0, 0, 0, 0, 0};
body earth = { 5.972e24, 149.6e9, 0, 0, 0, 29.78e3, 0};
body moon = { 7.347e22, 149.6e9+384.4e6, 0, 0, 0, 29.78e3+1.02e3, 0};

void update(body *b, double dt) {
    b->vx += b->ax * dt;
    b->vy += b->ay * dt;
    b->vz += b->az * dt;
    b->x += b->vx * dt;
    b->y += b->vy * dt;
    b->z += b->vz * dt;
}

void do_gravity(body *b1, body *b2) {
    double dx = b2->x - b1->x;
    double dy = b2->y - b1->y;
    double dz = b2->z - b1->z;
    double d = sqrt(dx*dx + dy*dy + dz*dz);
    double f = G * b1->mass * b2->mass / (d*d);
    b1->ax += f*dx/b1->mass;
    b1->ay += f*dy/b1->mass;
    b1->az += f*dz/b1->mass;
}

int main() {
    double dt = 60*60*24; // one day
    for (int i = 0; i < 365*10; i++) {
        do_gravity(&sun, &earth);
        do_gravity(&sun, &moon);
        do_gravity(&earth, &moon);
        update(&sun, dt);
        update(&earth, dt);
        update(&moon, dt);
        printf("Day %d: Earth %f, %f, %f | Moon %f, %f, %f\n", i, earth.x, earth.y, earth.z, moon.x, moon.y, moon.z);
    }
    return 0;
}