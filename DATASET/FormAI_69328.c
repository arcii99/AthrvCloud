//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define G 6.6743e-11  // Universal gravitational constant

// Structure for representing a body in space
typedef struct {
    double mass;
    double x, y, z;  // position in Cartesian coordinates
    double vx, vy, vz;  // velocity in Cartesian coordinates
} Body;

// Function to calculate distance between two bodies
double distance(Body b1, Body b2) {
    double dx = b1.x - b2.x;
    double dy = b1.y - b2.y;
    double dz = b1.z - b2.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Define the bodies in our solar system
    Body sun = {1.989e30, 0, 0, 0, 0, 0, 0};
    Body earth = {5.972e24, 1.496e11, 0, 0, 0, 29780, 0};
    Body moon = {7.346e22, 1.496e11 + 3.844e8, 0, 0, 0, 3070 + 29780, 0};

    // Define the simulation parameters
    double dt = 3600;  // time step in seconds
    double totalTime = 31536000;  // total simulation time in seconds
    int numSteps = (int) (totalTime / dt);

    // Run the simulation
    for (int i = 0; i < numSteps; i++) {
        // Calculate the forces on each body from every other body
        double force_earth_sun = G * earth.mass * sun.mass / pow(distance(earth, sun), 2);
        double force_moon_earth = G * moon.mass * earth.mass / pow(distance(moon, earth), 2);
        double force_moon_sun = G * moon.mass * sun.mass / pow(distance(moon, sun), 2);

        // Update the velocity of each body using the net force acting on it
        earth.vx += (force_earth_sun / earth.mass) * dt;
        earth.vy += (force_earth_sun / earth.mass) * dt;
        earth.vz += (force_earth_sun / earth.mass) * dt;

        moon.vx += ((force_moon_earth / moon.mass) + (force_moon_sun / moon.mass)) * dt;
        moon.vy += ((force_moon_earth / moon.mass) + (force_moon_sun / moon.mass)) * dt;
        moon.vz += ((force_moon_earth / moon.mass) + (force_moon_sun / moon.mass)) * dt;

        sun.vx += ((-force_earth_sun / sun.mass) + (-force_moon_sun / sun.mass)) * dt;
        sun.vy += ((-force_earth_sun / sun.mass) + (-force_moon_sun / sun.mass)) * dt;
        sun.vz += ((-force_earth_sun / sun.mass) + (-force_moon_sun / sun.mass)) * dt;

        // Update the position of each body using its new velocity
        earth.x += earth.vx * dt;
        earth.y += earth.vy * dt;
        earth.z += earth.vz * dt;

        moon.x += moon.vx * dt;
        moon.y += moon.vy * dt;
        moon.z += moon.vz * dt;

        sun.x += sun.vx * dt;
        sun.y += sun.vy * dt;
        sun.z += sun.vz * dt;

        // Print out the position of each body every 1000th step
        if (i % 1000 == 0) {
            printf("Step %d: Earth (%.2e, %.2e, %.2e), Moon (%.2e, %.2e, %.2e), Sun (%.2e, %.2e, %.2e)\n",
             i, earth.x, earth.y, earth.z, moon.x, moon.y, moon.z, sun.x, sun.y, sun.z);
        }
    }

    // All done!
    return 0;
}