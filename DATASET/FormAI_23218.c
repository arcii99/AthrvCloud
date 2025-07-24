//FormAI DATASET v1.0 Category: Physics simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAV_CONST 6.67430E-11 // Gravitational constant
#define TIME_STEP 0.1 // Time step size
#define MAX_ITERATIONS 1000 // Maximum number of simulation iterations

// Structure representing a celestial body
typedef struct {
    double mass; // Mass
    double x; // x-coordinate
    double y; // y-coordinate
    double z; // z-coordinate
    double vx; // x-velocity
    double vy; // y-velocity
    double vz; // z-velocity
} CelestialBody;

// Function to compute the Euclidean distance between two points in 3D space
double distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}

int main() {
    CelestialBody sun = {1.989E30, 0, 0, 0, 0, 0, 0}; // Sun
    CelestialBody earth = {5.972E24, 1.496E11, 0, 0, 0, 3E4, 0}; // Earth

    int i; // Iteration counter

    // Perform simulation
    for (i = 0; i < MAX_ITERATIONS; i++) {
        double distance_s = distance(sun.x, sun.y, sun.z, earth.x, earth.y, earth.z); // Distance between Sun and Earth
        double distance_e = distance(sun.x, sun.y, sun.z, earth.x, earth.y, earth.z); // Distance between Earth and Sun
        double force_magnitude = GRAV_CONST * sun.mass * earth.mass / pow(distance_e, 2); // Gravitational force magnitude
        double force_x = force_magnitude * (earth.x - sun.x) / distance_e; // Gravitational force x-component
        double force_y = force_magnitude * (earth.y - sun.y) / distance_e; // Gravitational force y-component
        double force_z = force_magnitude * (earth.z - sun.z) / distance_e; // Gravitational force z-component
        double acceleration_x = force_x / earth.mass; // Acceleration x-component
        double acceleration_y = force_y / earth.mass; // Acceleration y-component
        double acceleration_z = force_z / earth.mass; // Acceleration z-component

        // Update Earth's velocity and position
        earth.vx += acceleration_x * TIME_STEP;
        earth.vy += acceleration_y * TIME_STEP;
        earth.vz += acceleration_z * TIME_STEP;
        earth.x += earth.vx * TIME_STEP;
        earth.y += earth.vy * TIME_STEP;
        earth.z += earth.vz * TIME_STEP;

        // Print Earth's position
        printf("Iteration %d: Earth position: (%.2f, %.2f, %.2f)\n", i + 1, earth.x, earth.y, earth.z);
    }

    return 0;
}