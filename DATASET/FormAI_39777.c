//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: ephemeral
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define G 6.6743e-11 // Gravitational constant
#define TIME_STEP 86400 // Time in seconds for each iteration
#define SIMULATION_LENGTH 31536000 // Total simulation time in seconds
#define NUM_PLANETS 5 // Number of planets in the simulation

// Structure to hold the necessary information for each planet
typedef struct planet {
    char *name; // Name of the planet
    double mass; // Mass of the planet in kg
    double radius; // Radius of the planet in meters
    double x; // x position of the planet in meters
    double y; // y position of the planet in meters
    double z; // z position of the planet in meters
    double vx; // x velocity of the planet in meters/second
    double vy; // y velocity of the planet in meters/second
    double vz; // z velocity of the planet in meters/second
} Planet;

// Function to calculate the distance between two planets
double calculate_distance(Planet p1, Planet p2) {
    double x_diff = p1.x - p2.x;
    double y_diff = p1.y - p2.y;
    double z_diff = p1.z - p2.z;
    return sqrt(x_diff * x_diff + y_diff * y_diff + z_diff * z_diff);
}

int main() {
    // Seed the random number generator
    srand(time(0));
    
    // Define the planets in the simulation
    Planet planets[NUM_PLANETS] = {
        {"Earth", 5.972e24, 6.371e6, 0, 0, 0, 0, 0, 0}, // Earth
        {"Mars", 6.39e23, 3.389e6, 2.279e11, 0, 0, 0, 24047, 0}, // Mars
        {"Jupiter", 1.898e27, 6.9911e7, 7.7859e11, 0, 0, 0, 13070, 0}, // Jupiter
        {"Saturn", 5.683e26, 5.8232e7, 1.4294e12, 0, 0, 0, 9690, 0}, // Saturn
        {"Uranus", 8.681e25, 2.5362e7, -2.8702e12, 0, 0, 0, -6835, 0} // Uranus
    };
    
    // Initialize the positions and velocities of the planets randomly
    for (int i = 0; i < NUM_PLANETS; i++) {
        planets[i].x = ((double) rand() / RAND_MAX) * 2e11 - 1e11;
        planets[i].y = ((double) rand() / RAND_MAX) * 2e11 - 1e11;
        planets[i].z = ((double) rand() / RAND_MAX) * 2e11 - 1e11;
        planets[i].vx = ((double) rand() / RAND_MAX) * 20000 - 10000;
        planets[i].vy = ((double) rand() / RAND_MAX) * 20000 - 10000;
        planets[i].vz = ((double) rand() / RAND_MAX) * 20000 - 10000;
    }
    
    // Loop through the simulation length in time steps
    for (int t = 0; t < SIMULATION_LENGTH; t += TIME_STEP) {
        // Loop through each planet
        for (int i = 0; i < NUM_PLANETS; i++) {
            // Reset the acceleration for this time step
            double ax = 0, ay = 0, az = 0;
            
            // Loop through each other planet
            for (int j = 0; j < NUM_PLANETS; j++) {
                if (i == j) {
                    continue; // Skip if it's the same planet
                }
                // Calculate the distance between the two planets
                double distance = calculate_distance(planets[i], planets[j]);
                
                // Calculate the gravitational force between the two planets
                double force = G * planets[i].mass * planets[j].mass / (distance * distance);
                
                // Calculate the x, y, and z components of the force
                double x_diff = planets[j].x - planets[i].x;
                double y_diff = planets[j].y - planets[i].y;
                double z_diff = planets[j].z - planets[i].z;
                double x_force = force * x_diff / distance;
                double y_force = force * y_diff / distance;
                double z_force = force * z_diff / distance;
                
                // Add the x, y, and z components of the force to the acceleration
                ax += x_force / planets[i].mass;
                ay += y_force / planets[i].mass;
                az += z_force / planets[i].mass;
            }
            
            // Update the velocity and position of the planet based on the acceleration
            planets[i].vx += ax * TIME_STEP;
            planets[i].vy += ay * TIME_STEP;
            planets[i].vz += az * TIME_STEP;
            planets[i].x += planets[i].vx * TIME_STEP;
            planets[i].y += planets[i].vy * TIME_STEP;
            planets[i].z += planets[i].vz * TIME_STEP;
        }
    }
    
    // Print out the final positions of the planets
    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("%s: x=%f, y=%f, z=%f\n", planets[i].name, planets[i].x, planets[i].y, planets[i].z);
    }
    
    return 0;
}