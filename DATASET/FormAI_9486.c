//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11  // gravitational constant

typedef struct {  // structure to hold planet information
    double mass;  // planet mass in kilograms
    double x;     // x-coordinate in meters
    double y;     // y-coordinate in meters
    double z;     // z-coordinate in meters
    double vx;    // x-velocity in meters per second
    double vy;    // y-velocity in meters per second
    double vz;    // z-velocity in meters per second
} Planet;

int main() {
    int i, j;
    double distance, force, fx, fy, fz;
    const int numPlanets = 3;  // number of planets to simulate
    const double timeStep = 86400.0;  // time step in seconds, equivalent to one day
    Planet planets[numPlanets];  // array to hold planet data

    // set up initial planetary data
    planets[0].mass = 5.97e24;
    planets[0].x = 0.0;
    planets[0].y = 0.0;
    planets[0].z = 0.0;
    planets[0].vx = 0.0;
    planets[0].vy = 0.0;
    planets[0].vz = 0.0;

    planets[1].mass = 6.39e23;
    planets[1].x = 227.9e9;
    planets[1].y = 0.0;
    planets[1].z = 0.0;
    planets[1].vx = 0.0;
    planets[1].vy = 24.077e3;
    planets[1].vz = 0.0;

    planets[2].mass = 1.99e30;
    planets[2].x = 0.0;
    planets[2].y = 149.6e9;
    planets[2].z = 0.0;
    planets[2].vx = -29.29e3;
    planets[2].vy = 0.0;
    planets[2].vz = 0.0;

    // simulate planetary motion
    for (i = 0; i < numPlanets; i++) {
        for (j = i + 1; j < numPlanets; j++) {  // iterate through pairs of planets
            distance = sqrt(pow(planets[i].x - planets[j].x, 2) +
                            pow(planets[i].y - planets[j].y, 2) +
                            pow(planets[i].z - planets[j].z, 2));  // calculate distance between planets
            force = G * planets[i].mass * planets[j].mass / pow(distance, 2);  // calculate force between planets
            fx = force * (planets[j].x - planets[i].x) / distance;  // calculate x-component of force
            fy = force * (planets[j].y - planets[i].y) / distance;  // calculate y-component of force
            fz = force * (planets[j].z - planets[i].z) / distance;  // calculate z-component of force
            planets[i].vx += fx / planets[i].mass * timeStep;  // update x-velocity of planet i
            planets[i].vy += fy / planets[i].mass * timeStep;  // update y-velocity of planet i
            planets[i].vz += fz / planets[i].mass * timeStep;  // update z-velocity of planet i
            planets[j].vx += -fx / planets[j].mass * timeStep;  // update x-velocity of planet j
            planets[j].vy += -fy / planets[j].mass * timeStep;  // update y-velocity of planet j
            planets[j].vz += -fz / planets[j].mass * timeStep;  // update z-velocity of planet j
        }

        planets[i].x += planets[i].vx * timeStep;  // update x-coordinate of planet i
        planets[i].y += planets[i].vy * timeStep;  // update y-coordinate of planet i
        planets[i].z += planets[i].vz * timeStep;  // update z-coordinate of planet i
    }

    // print final planet positions
    for (i = 0; i < numPlanets; i++) {
        printf("Planet %d: (%.2e, %.2e, %.2e)\n", i+1, planets[i].x, planets[i].y, planets[i].z);
    }

    return 0;
}