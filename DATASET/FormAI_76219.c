//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Define constants for the Solar System simulation
#define G 6.6743e-11 // gravitational constant
#define SUN_RADIUS 6.96342e8 // radius of the Sun
#define EARTH_ORBIT_RADIUS 1.496e11 // average distance from Earth to Sun
#define EARTH_ORBIT_VELOCITY 2.9783e4 // average velocity of Earth orbiting around Sun
#define EARTH_MASS 5.9722e24 // mass of Earth
#define SUN_MASS 1.9885e30 // mass of the Sun

typedef struct {
    double x, y; // position of the planet
    double vx, vy; // velocity of the planet
    double mass; // mass of the planet
} Body;

int main() {
    // Initialize the planets
    Body sun = {0, 0, 0, 0, SUN_MASS};
    Body earth = {EARTH_ORBIT_RADIUS, 0, 0, EARTH_ORBIT_VELOCITY, EARTH_MASS};

    // Define simulation parameters
    double dt = 3600; // time step in seconds
    double duration = 365 * 24 * 3600; // duration of simulation in seconds

    // Initialize variables for simulation loop
    double t = 0; // current time
    double Fx, Fy, r, ax, ay; // variables for computing forces and accelerations

    // Perform simulation
    while (t < duration) {
        // Compute gravitational force between Sun and Earth
        r = sqrt(pow(earth.x - sun.x, 2) + pow(earth.y - sun.y, 2));
        Fx = G * sun.mass * earth.mass * (sun.x - earth.x) / pow(r, 3);
        Fy = G * sun.mass * earth.mass * (sun.y - earth.y) / pow(r, 3);

        // Compute acceleration of Earth
        ax = Fx / earth.mass;
        ay = Fy / earth.mass;

        // Update velocity and position of Earth
        earth.vx += ax * dt;
        earth.vy += ay * dt;
        earth.x += earth.vx * dt;
        earth.y += earth.vy * dt;

        // Update current time
        t += dt;

        // Print position of Earth
        printf("t = %.2f, x = %.2e, y = %.2e\n", t, earth.x, earth.y);
    }

    return 0;
}