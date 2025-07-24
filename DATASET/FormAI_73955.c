//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: genious
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLANETS 9
#define G_CONST 6.673e-11
#define TIME_STEP 86400 // time step in seconds

typedef struct {
    double x, y; // position coordinates
    double vx, vy; // velocity components
    double mass;
} planet_t;

int main() {
    // initialize the solar system
    planet_t planets[NUM_PLANETS] = {
        {0, 0, 0, 0, 1.989e30}, // sun
        {0, 57910000000, -47870, 0, 3.3011e23}, // mercury
        {0, 108209475000, -35020, 0, 4.8675e24}, // venus
        {0, 149597870700, -29780, 0, 5.9724e24}, // earth
        {0, 227939100000, -24130, 0, 6.4185e23}, // mars
        {0, 778547200000, -13060, 0, 1.8982e27}, // jupiter
        {0, 1433449370000, -9690, 0, 5.6834e26}, // saturn
        {0, 2876679082000, -6810, 0, 8.6813e25}, // uranus
        {0, 4503443661000, -5400, 0, 1.0241e26} // neptune
    };

    // set random seed for initial perturbations
    srand(time(NULL));

    // perturb planets' initial positions and velocities
    for (int i = 1; i < NUM_PLANETS; i++) {
        planets[i].x += (rand() % 1000) - 500000000;
        planets[i].vx += (rand() % 100) - 50;
    }

    // simulate the solar system
    for (int t = 0; t < 365; t++) {
        // calculate forces between planets
        for (int i = 0; i < NUM_PLANETS; i++) {
            double fx = 0, fy = 0;
            for (int j = 0; j < NUM_PLANETS; j++) {
                if (i != j) {
                    double dx = planets[j].x - planets[i].x;
                    double dy = planets[j].y - planets[i].y;
                    double dist = sqrt(dx*dx + dy*dy);
                    double force = G_CONST * planets[i].mass * planets[j].mass / (dist*dist);
                    fx += force * dx / dist;
                    fy += force * dy / dist;
                }
            }
            // update planet's velocity and position
            double ax = fx / planets[i].mass;
            double ay = fy / planets[i].mass;
            planets[i].vx += ax * TIME_STEP;
            planets[i].vy += ay * TIME_STEP;
            planets[i].x += planets[i].vx * TIME_STEP;
            planets[i].y += planets[i].vy * TIME_STEP;
        }

        // print planet positions for this timestep
        printf("Day %d:\n", t);
        for (int i = 0; i < NUM_PLANETS; i++) {
            printf("Planet %d: x = %e, y = %e\n", i, planets[i].x, planets[i].y);
        }
        printf("\n");
    }

    return 0;
}