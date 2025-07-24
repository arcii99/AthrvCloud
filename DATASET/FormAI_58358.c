//FormAI DATASET v1.0 Category: Physics simulation ; Style: sophisticated
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define PI 3.14159265

int main() {
    // Input variables
    double mass = 10.0; // kg
    double initialVelocity = 20.0; // m/s
    double angle = 45.0; // degrees
    double timeStep = 0.01; // seconds

    // Derived variables
    double velocityX = initialVelocity * cos(angle * PI / 180.0);
    double velocityY = initialVelocity * sin(angle * PI / 180.0);
    double accelerationX = 0.0;
    double accelerationY = -9.81;
    double positionX = 0.0;
    double positionY = 0.0;

    // Loop until the projectile lands on the ground
    while (positionY >= 0.0) {
        // Print the current position of the projectile
        printf("Position: (%.2f, %.2f)\n", positionX, positionY);

        // Update the velocity and position of the projectile
        velocityX += accelerationX * timeStep;
        velocityY += accelerationY * timeStep;
        positionX += velocityX * timeStep;
        positionY += velocityY * timeStep;

        // Check if the projectile hits the ground
        if (positionY < 0.0) {
            printf("The projectile hits the ground at %.2f meters.\n", positionX);
        }
    }

    return 0;
}