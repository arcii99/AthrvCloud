//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: innovative
// Solar System Simulation
// This program simulates the planets in our solar system
// made by a creative chatbot

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#define GRAVITY 0.001 // gravitational constant

// define structure for planet
typedef struct {
    double mass; // mass of planet
    double x; // x-position of planet
    double y; // y-position of planet
    double vx; // x-velocity of planet
    double vy; // y-velocity of planet
} Planet;

// function to calculate distance between two planets
double distance(Planet *p1, Planet *p2) {
    double dx = p1->x - p2->x;
    double dy = p1->y - p2->y;
    return sqrt(dx*dx + dy*dy);
}

// function to calculate force between two planets
void calculate_force(Planet *p1, Planet *p2, double *fx, double *fy) {
    double d = distance(p1, p2);
    double f = GRAVITY * p1->mass * p2->mass / (d*d);
    *fx = f * (p2->x - p1->x) / d;
    *fy = f * (p2->y - p1->y) / d;
}

// function to update planet velocity and position
void update(Planet *p, double fx, double fy, double dt) {
    p->vx += fx / p->mass * dt;
    p->vy += fy / p->mass * dt;
    p->x += p->vx * dt;
    p->y += p->vy * dt;
}

// main program
int main() {
    // seed random number generator
    srand(time(NULL));

    // create array of planets
    const int NUM_PLANETS = 8;
    Planet planets[NUM_PLANETS];

    // set mass and position of the sun
    planets[0].mass = 333000;
    planets[0].x = 400;
    planets[0].y = 300;
    planets[0].vx = 0;
    planets[0].vy = 0;

    // set mass, position, and velocity of the planets
    for (int i = 1; i < NUM_PLANETS; i++) {
        planets[i].mass = (rand() % 10) + 1;
        planets[i].x = rand() % 800;
        planets[i].y = rand() % 600;
        planets[i].vx = ((rand() % 10) - 5) / 10.0;
        planets[i].vy = ((rand() % 10) - 5) / 10.0;
    }

    // simulation loop
    const double DT = 0.01; // time step
    const int MAX_TIME = 10000; // maximum simulation time
    for (int t = 0; t < MAX_TIME; t++) {
        // calculate net force on each planet
        double fx[NUM_PLANETS];
        double fy[NUM_PLANETS];
        for (int i = 0; i < NUM_PLANETS; i++) {
            fx[i] = fy[i] = 0;
            for (int j = 0; j < NUM_PLANETS; j++) {
                if (i == j) continue;
                double f1x, f1y;
                calculate_force(&planets[i], &planets[j], &f1x, &f1y);
                fx[i] += f1x;
                fy[i] += f1y;
            }
        }

        // update velocity and position of each planet
        for (int i = 0; i < NUM_PLANETS; i++) {
            update(&planets[i], fx[i], fy[i], DT);
        }

        // print positions of planets
        for (int i = 0; i < NUM_PLANETS; i++) {
            printf("Planet %d: x=%lf, y=%lf\n", i, planets[i].x, planets[i].y);
        }
        printf("\n");
    }

    return 0;
}