//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Ken Thompson
/*
 * This program simulates the gravity and motion of planets in a 2D space.
 * Inspired by Ken Thompson, I've tried to keep the code as minimal and efficient as possible.
 */

#include <stdio.h>
#include <math.h>

#define PLANET_COUNT 3
#define GRAV_CONST 0.1
#define STEP_SIZE 0.1
#define STEPS_PER_UNIT_TIME 100

struct planet {
    double x, y; // position
    double vx, vy; // velocity
    double m; // mass
};

struct planet planets[PLANET_COUNT] = {
    { 0.0, 2.0, 0.5, 0.0, 100.0 },
    { -2.0, 0.0, 0.0, -0.5, 50.0 },
    { 2.0, 0.0, 0.0, 0.5, 50.0 },
};

int main() {
    int i, j, step;

    for (step = 0; ; step++) {
        for (i = 0; i < PLANET_COUNT; i++) {
            double ax = 0, ay = 0;
            for (j = 0; j < PLANET_COUNT; j++) {
                if (i == j) continue;
                double dx = planets[j].x - planets[i].x;
                double dy = planets[j].y - planets[i].y;
                double r = sqrt(dx*dx + dy*dy);
                double f = GRAV_CONST * planets[i].m * planets[j].m / (r*r);
                ax += f * dx / r;
                ay += f * dy / r;
            }
            planets[i].vx += ax * STEP_SIZE / planets[i].m;
            planets[i].vy += ay * STEP_SIZE / planets[i].m;
        }
        for (i = 0; i < PLANET_COUNT; i++) {
            planets[i].x += planets[i].vx * STEP_SIZE * STEPS_PER_UNIT_TIME;
            planets[i].y += planets[i].vy * STEP_SIZE * STEPS_PER_UNIT_TIME;
        }
        printf("%d %f %f %f %f %f %f\n", step,
               planets[0].x, planets[0].y,
               planets[1].x, planets[1].y,
               planets[2].x, planets[2].y);
    }
    return 0;
}