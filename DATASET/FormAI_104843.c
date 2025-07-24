//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: single-threaded
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define G 6.67e-11 // gravitational constant
#define DELTA_T 86400 // time increment (1 day in seconds)
#define NUM_PLANETS 4 // number of planets in the simulation

// define structure of a planet
struct planet {
    char name[20];
    double mass; // kg
    double radius; // m
    double x, y; // position (m)
    double vx, vy; // velocity (m/s)
    double ax, ay; // acceleration (m/s^2)
};

// function to calculate distance between two bodies
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    srand(time(0)); // seed random number generator

    // initialize array of planets
    struct planet planets[NUM_PLANETS] = {
        {"Mercury", 3.285e23, 2.439e6, -5.791e10, 0, 0, 47870, 0}, // kg, m, m/s
        {"Venus", 4.867e24, 6.052e6, -1.082e11, 0, 0, 35020, 0},
        {"Earth", 5.972e24, 6.371e6, -1.496e11, 0, 0, 29780, 0},
        {"Mars", 6.39e23, 3.39e6, -2.279e11, 0, 0, 24130, 0}
    };

    // calculate initial positions
    for (int i = 0; i < NUM_PLANETS; i++) {
        planets[i].y = rand() % 1000000; // set random y position
        planets[i].x = sqrt(pow(planets[i].radius + planets[i].y, 2) - pow(planets[i].y, 2)); // calculate x position
        planets[i].vx = -planets[i].vy * planets[i].x / sqrt(pow(planets[i].x, 2) + pow(planets[i].y, 2)) - rand() % 5000; // set random x velocity
    }

    // simulate motion of planets
    for (int t = 0; t < 365; t++) {
        for (int i = 0; i < NUM_PLANETS; i++) {
            double fx = 0, fy = 0; // initialize forces to zero
            for (int j = 0; j < NUM_PLANETS; j++) {
                if (j != i) {
                    double dist = distance(planets[i].x, planets[i].y, planets[j].x, planets[j].y);
                    double f = G * planets[i].mass * planets[j].mass / pow(dist, 2);
                    fx += f * (planets[j].x - planets[i].x) / dist;
                    fy += f * (planets[j].y - planets[i].y) / dist;
                }
            }
            // update acceleration
            planets[i].ax = fx / planets[i].mass;
            planets[i].ay = fy / planets[i].mass;

            // update velocity
            planets[i].vx += planets[i].ax * DELTA_T;
            planets[i].vy += planets[i].ay * DELTA_T;

            // update position
            planets[i].x += planets[i].vx * DELTA_T;
            planets[i].y += planets[i].vy * DELTA_T;
        }
    }

    // print final positions
    printf("Final position of planets after 1 year:\n");
    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("%s: (%.2e, %.2e) m\n", planets[i].name, planets[i].x, planets[i].y);
    }

    return 0;
}