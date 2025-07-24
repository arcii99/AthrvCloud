//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 // Gravitational constant
#define TIMESTEP 0.1 // Time step for simulation

// Define planet structure
typedef struct planet {
    double x,y; // x,y position
    double mass; // Mass of planet
    double vx,vy; // Velocity in x,y direction
    double fx,fy; // Force in x,y direction
} Planet;

// Function to calculate Euclidean distance
double distance(Planet p1, Planet p2) {
    return sqrt(pow(p1.x-p2.x,2) + pow(p1.y-p2.y,2));
}

int main() {
    int num_planets = 2; // Number of planets
    Planet planets[num_planets]; // Array of planets

    // Initialize planets
    planets[0].x = 0.0;
    planets[0].y = 0.0;
    planets[0].mass = 5.97e24;
    planets[0].vx = 0.0;
    planets[0].vy = 0.0;
    planets[0].fx = 0.0;
    planets[0].fy = 0.0;

    planets[1].x = 384400000.0;
    planets[1].y = 0.0;
    planets[1].mass = 7.34e22;
    planets[1].vx = 0.0;
    planets[1].vy = 1022.0;
    planets[1].fx = 0.0;
    planets[1].fy = 0.0;

    int num_steps = 1000; // Number of time steps

    // Run simulation
    for (int step=0; step<num_steps; step++) {

        // Reset force values for each planet
        for (int i=0; i<num_planets; i++) {
            planets[i].fx = 0.0;
            planets[i].fy = 0.0;
        }

        // Calculate force on each planet
        for (int i=0; i<num_planets; i++) {
            for (int j=i+1; j<num_planets; j++) {
                double dist = distance(planets[i], planets[j]);
                double force = G * planets[i].mass * planets[j].mass / pow(dist,2);
                double fx = force * (planets[j].x - planets[i].x) / dist;
                double fy = force * (planets[j].y - planets[i].y) / dist;
                planets[i].fx += fx;
                planets[i].fy += fy;
                planets[j].fx -= fx;
                planets[j].fy -= fy;
            }
        }

        // Update position and velocity of each planet
        for (int i=0; i<num_planets; i++) {
            planets[i].vx += planets[i].fx / planets[i].mass * TIMESTEP;
            planets[i].vy += planets[i].fy / planets[i].mass * TIMESTEP;
            planets[i].x += planets[i].vx * TIMESTEP;
            planets[i].y += planets[i].vy * TIMESTEP;
        }

        // Print planet positions
        printf("%f %f %f %f\n", planets[0].x, planets[0].y, planets[1].x, planets[1].y);
    }

    return 0;
}