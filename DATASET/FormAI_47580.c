//FormAI DATASET v1.0 Category: Physics simulation ; Style: secure
#include <stdio.h>
#include <stdbool.h>

// Constants declaration
#define G 6.6743e-11
#define M 5.9742e24
#define m 7.342e22
#define d 3.84403e8
#define dt 100.0

// Function to calculate distance between two points
double dist(double x1, double y1, double x2, double y2) {
    return sqrt(pow((x2-x1), 2) + pow((y2-y1), 2));
}

int main() {
    // Initialize variables for position, velocity and acceleration
    double moonX = 0, moonY = d, moonVx = 1022.0, moonVy = 0;
    double earthX = 0, earthY = 0, earthVx = 0, earthVy = 0;
    double fx, fy, ax, ay;

    // Print initial positions
    printf("Initial Positions:\nMoon: (%lf, %lf)\nEarth: (%lf, %lf)\n\n", moonX, moonY, earthX, earthY);

    // Start simulation loop
    bool loop = true;
    while (loop) {
        // Calculate force and acceleration for the moon
        fx = G * M * m * (earthX - moonX) / pow(dist(earthX, earthY, moonX, moonY), 3);
        fy = G * M * m * (earthY - moonY) / pow(dist(earthX, earthY, moonX, moonY), 3);
        ax = fx / m;
        ay = fy / m;

        // Update moon's position and velocity using Euler's method
        moonX += moonVx * dt;
        moonY += moonVy * dt;
        moonVx += ax * dt;
        moonVy += ay * dt;

        // Calculate force and acceleration for the earth (assuming the moon's orbit is circular)
        fx = -fx;
        fy = -fy;
        ax = fx / M;
        ay = fy / M;

        // Update earth's position and velocity using Euler's method
        earthX += earthVx * dt;
        earthY += earthVy * dt;
        earthVx += ax * dt;
        earthVy += ay * dt;

        // Print current positions
        printf("Moon: (%lf, %lf)\nEarth: (%lf, %lf)\n\n", moonX, moonY, earthX, earthY);

        // Check if the moon returned to its original position
        if (dist(moonX, moonY, 0, d) < 10000.0) {
            loop = false;
        }
    }

    // Print final positions
    printf("Final Positions:\nMoon: (%lf, %lf)\nEarth: (%lf, %lf)\n", moonX, moonY, earthX, earthY);

    return 0;
}