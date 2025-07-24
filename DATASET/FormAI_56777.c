//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 // gravitational constant

typedef struct {
    double x, y, z; // position
    double vx, vy, vz; // velocity
    double mass; // mass
} Body;

void update_position(Body* body, double dt) {
    body->x += body->vx * dt;
    body->y += body->vy * dt;
    body->z += body->vz * dt;
}

void update_velocity(Body* body, Body* other, double dt) {
    double dx = other->x - body->x;
    double dy = other->y - body->y;
    double dz = other->z - body->z;
    double d2 = dx*dx + dy*dy + dz*dz;
    double a = G * other->mass / d2;
    double f = a / sqrt(d2);
    body->vx += dx * f * dt;
    body->vy += dy * f * dt;
    body->vz += dz * f * dt;
}

void update(Body* bodies, int n, double dt) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            update_velocity(&bodies[i], &bodies[j], dt);
        }
    }
    for (int i = 0; i < n; i++) {
        update_position(&bodies[i], dt);
    }
}

int main() {
    Body sun = { 0, 0, 0, 0, 0, 0, 1.989e30 };
    Body earth = { 1.49598e11, 0, 0, 0, 29783, 0, 5.972e24 };
    Body moon = { 1.49598e11 + 3.84e8, 0, 0, 0, 29783 + 1022, 0, 7.342e22 };
    int steps = 365 * 86400 / 100; // simulate 1 year with 100 steps per day
    double dt = 1.0 / steps;

    for (int i = 0; i < steps; i++) {
        update(&earth, 1, dt);
        update(&moon, 1, dt);
        update(&sun, 1, dt);
    }

    printf("Earth Position: x=%f y=%f z=%f\n", earth.x, earth.y, earth.z);
    printf("Moon Position: x=%f y=%f z=%f\n", moon.x, moon.y, moon.z);
    printf("Sun Position: x=%f y=%f z=%f\n", sun.x, sun.y, sun.z);

    return 0;
}