//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 // Gravitational constant
#define M_sun 1.989e30 // Mass of the Sun
#define M_earth 5.972e24 // Mass of the Earth
#define M_moon 7.342e22 // Mass of the Moon
#define R_earth 149.6e9 // Average distance between Earth and the Sun
#define R_moon 384.4e6 // Average distance between Moon and Earth

typedef struct {
    double x, y; // Position
    double vx, vy; // Velocity
    double ax, ay; // Acceleration
    double m; // Mass
} Body;

void update_velocity(Body* a, Body* b, double dt) {
    double dx = b->x - a->x;
    double dy = b->y - a->y;
    double r = sqrt(dx*dx + dy*dy);
    double F = G * a->m * b->m / (r*r);
    double fx = F * dx / r;
    double fy = F * dy / r;
    a->vx += fx / a->m * dt;
    a->vy += fy / a->m * dt;
    b->vx -= fx / b->m * dt;
    b->vy -= fy / b->m * dt;
}

void update_position(Body* a, double dt) {
    a->x += a->vx * dt;
    a->y += a->vy * dt;
}

int main() {
    Body sun = {0, 0, 0, 0, 0, M_sun};
    Body earth = {R_earth, 0, 0, 29.29e3, M_earth};
    Body moon = {R_earth + R_moon, 0, 0, 29.29e3 + 1.02e3, M_moon};
    double dt = 1; // Time step in seconds
    int steps = 365 * 24 * 60 * 60 / dt; // Number of steps in a year

    for (int n=0; n<steps; n++) {
        update_velocity(&earth, &sun, dt);
        update_velocity(&moon, &earth, dt);
        update_velocity(&moon, &sun, dt);

        update_position(&earth, dt);
        update_position(&moon, dt);

        printf("%f %f %f %f %f %f\n", earth.x, earth.y, moon.x, moon.y, sun.x, sun.y);
    }

    return 0;
}