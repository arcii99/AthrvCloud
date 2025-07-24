//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.6742e-11

struct body {
    double mass, x, y, z, vx, vy, vz;
};

struct body sun = {1.989e30, 0, 0, 0, 0, 0, 0};
struct body earth = {5.972e24, 1.496e11, 0, 0, 0, 29783, 0};

void update_position(struct body *b, double dt) {
    b->x += b->vx * dt;
    b->y += b->vy * dt;
    b->z += b->vz * dt;
}

void update_velocity(struct body *b, double fx, double fy, double fz, double dt) {
    b->vx += fx / b->mass * dt;
    b->vy += fy / b->mass * dt;
    b->vz += fz / b->mass * dt;
}

void update_body(struct body *b, double dt) {
    double dx = earth.x - b->x;
    double dy = earth.y - b->y;
    double dz = earth.z - b->z;
    double distance = sqrt(dx*dx + dy*dy + dz*dz);
    double force = G * b->mass * earth.mass / (distance * distance);
    double fx = force * dx / distance;
    double fy = force * dy / distance;
    double fz = force * dz / distance;
    update_velocity(b, fx, fy, fz, dt);
    update_position(b, dt);
}

int main() {
    double dt = 86400;
    int nsteps = 365;
    printf("Time\tSun X\tSun Y\tSun Z\tEarth X\tEarth Y\tEarth Z\n");
    for (int i = 0; i < nsteps; i++) {
        printf("%d\t%e\t%e\t%e\t%e\t%e\t%e\n", i, sun.x, sun.y, sun.z, earth.x, earth.y, earth.z);
        update_body(&sun, dt);
        update_body(&earth, dt);
    }
    return 0;
}