//FormAI DATASET v1.0 Category: Physics simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G            6.67430E-11
#define TIMESTEP     0.1
#define SIM_DURATION 100.0

// Define a structure to hold the state data for a body
typedef struct {
    double x, y, vx, vy, ax, ay, mass;
} Body;

// Define a function to calculate the distance between two bodies
double distance(Body a, Body b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
    // Define the bodies in our simulation
    Body bodies[] = {
        {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0},
        {1.0, 0.0, 0.0, 6.283, 0.0, 0.0, 0.005},
        {0.0, 2.0, -4.0, 0.0, 0.0, 0.0, 0.025},
        {-3.0, -4.0, 2.0, -3.0, 0.0, 0.0, 0.015}
    };

    // Compute the number of bodies in the simulation
    int nbodies = sizeof(bodies) / sizeof(Body);

    // Define variables to hold the simulation time
    double t = 0.0;
    double dt = TIMESTEP;

    // Define variables for the simulation loop
    int i, j;
    double d;
    double fx, fy;

    // Start the simulation loop
    while (t < SIM_DURATION) {
        // Zero out the force accumulators for each body
        for (i = 0; i < nbodies; i++) {
            bodies[i].ax = 0.0;
            bodies[i].ay = 0.0;
        }

        // Calculate the force between each pair of bodies
        for (i = 0; i < nbodies; i++) {
            for (j = i + 1; j < nbodies; j++) {
                // Compute the distance between the bodies
                d = distance(bodies[i], bodies[j]);

                // Compute the force between the bodies
                fx = (G * bodies[i].mass * bodies[j].mass * (bodies[j].x - bodies[i].x)) / (d * d * d);
                fy = (G * bodies[i].mass * bodies[j].mass * (bodies[j].y - bodies[i].y)) / (d * d * d);

                // Accumulate the force on each body
                bodies[i].ax += fx;
                bodies[i].ay += fy;
                bodies[j].ax -= fx;
                bodies[j].ay -= fy;
            }
        }

        // Update the position and velocity of each body
        for (i = 0; i < nbodies; i++) {
            // Update the velocity using the current acceleration
            bodies[i].vx += bodies[i].ax * dt;
            bodies[i].vy += bodies[i].ay * dt;

            // Update the position using the updated velocity
            bodies[i].x += bodies[i].vx * dt;
            bodies[i].y += bodies[i].vy * dt;
        }

        // Increment the simulation time
        t += dt;

        // Output the current state of the simulation
        printf("\n\nTime: %.2f\n", t);
        for (i = 0; i < nbodies; i++) {
            printf("Body %d: (%.2f, %.2f) V(%.2f, %.2f)\n", i, bodies[i].x, bodies[i].y, bodies[i].vx, bodies[i].vy);
        }
    }

    return 0;
}