//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants
#define G 6.67 * pow(10, -11)  // gravitational constant
#define dt 0.1                 // time step

// Function to calculate the force between two planets
double force(double m1, double m2, double r) {
    return G * m1 * m2 / pow(r, 2);
}

// Recursive function to update the position and velocity of a planet
void update_position(double *px, double *py, double *vx, double *vy, double m, double fx, double fy) {
    // Update velocity
    *vx += fx / m * dt;
    *vy += fy / m * dt;

    // Update position
    *px += *vx * dt;
    *py += *vy * dt;

    // Check if planet is out of bounds
    if (*px > 1 || *px < -1 || *py > 1 || *py < -1) {
        printf("Planet escaped the simulation!\n");
        exit(0);
    }

    // Calculate new force
    double r = sqrt(pow(*px, 2) + pow(*py, 2));
    double new_fx = -force(m, 1, r) * (*px) / r;
    double new_fy = -force(m, 1, r) * (*py) / r;

    // Recursively call update function with new force
    update_position(px, py, vx, vy, m, new_fx, new_fy);
}

int main() {
    // Set initial planet values
    double px = 0.5;
    double py = 0;
    double vx = 0;
    double vy = 5;
    double m = 1000;

    // Print initial values
    printf("Initial position: (%f, %f)\n", px, py);
    printf("Initial velocity: (%f, %f)\n", vx, vy);
    printf("Mass: %f\n", m);

    // Update planet position and velocity
    update_position(&px, &py, &vx, &vy, m, 0, -force(m, 1, py));

    // Print final values
    printf("Final position: (%f, %f)\n", px, py);
    printf("Final velocity: (%f, %f)\n", vx, vy);

    return 0;
}