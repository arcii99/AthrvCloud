//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DELTA_T 0.001 // time step
#define G 6.674e-11  // gravitational constant

typedef struct {
    double x, y; // position
    double vx, vy; // velocity
    double mass; // mass
} Body;

void updateVelocity(Body *body, double *ax, double *ay) {
    body->vx += *ax * DELTA_T;
    body->vy += *ay * DELTA_T;
}

void updatePosition(Body *body) {
    body->x += body->vx * DELTA_T;
    body->y += body->vy * DELTA_T;
}

void calculateAcceleration(Body *body, Body *planet, double *ax, double *ay) {
    double rx = planet->x - body->x;
    double ry = planet->y - body->y;
    double r = sqrt(rx * rx + ry * ry);
    double f = G * body->mass * planet->mass / (r * r);
    *ax = f * rx / r / body->mass;
    *ay = f * ry / r / body->mass;
}

int main() {
    Body sun = {0, 0, 0, 0, 1.989e30}; // mass of sun
    Body earth = {0, 147098291e3, 30290.0, 0, 5.972e24}; // distance from sun to earth = aphelion distance
    Body moon = {0, 147098291e3 + 384400e3, 30290.0 + 1022.0, 0, 7.342e22}; // distance from earth to moon = mean distance

    for (double t = 0; t < 365.24 * 24 * 3600; t += DELTA_T) { // simulate for one year
        double ax, ay;

        calculateAcceleration(&earth, &sun, &ax, &ay);
        updateVelocity(&earth, &ax, &ay);
        updatePosition(&earth);

        calculateAcceleration(&moon, &earth, &ax, &ay);
        calculateAcceleration(&moon, &sun, &ax, &ay);
        updateVelocity(&moon, &ax, &ay);
        updatePosition(&moon);

        printf("Earth: (%.2f, %.2f) \n", earth.x, earth.y);
        printf("Moon: (%.2f, %.2f) \n", moon.x, moon.y);
        printf("\n");
    }

    return 0;
}