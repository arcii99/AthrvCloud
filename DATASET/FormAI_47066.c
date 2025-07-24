//FormAI DATASET v1.0 Category: Physics simulation ; Style: careful
#include <stdio.h>

// Constants
#define G 9.81 // acceleration due to gravity in m/s^2
#define DT 0.01 // time step for simulation in seconds
#define MASS 1.0 // mass of the object in kilograms
#define K 1.0 // spring constant in Newtons/meter
#define LENGTH 0.5 // length of the spring in meters

int main() {
    // Initialize variables
    double velocity = 0.0;
    double position = 0.0;
    double force = 0.0;
    double acceleration = 0.0;

    // Run simulation for 10 seconds
    for (double t = 0.0; t < 10.0; t += DT) {
        // Calculate force on object
        force = -G * MASS - K * position;

        // Calculate acceleration of object
        acceleration = force / MASS;

        // Update velocity of object
        velocity += acceleration * DT;

        // Update position of object
        position += velocity * DT;

        // Print current position of object
        printf("Position at t=%.2f: %.2f meters\n", t, position);

        // If object reaches bottom of spring, reverse direction
        if (position < -LENGTH) {
            velocity = -velocity;
            position = -LENGTH;
        }
    }

    return 0; // End of program
}