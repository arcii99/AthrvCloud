//FormAI DATASET v1.0 Category: Physics simulation ; Style: modular
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Function prototypes
double calcDisplacement(double initialVelocity, double acceleration, double time);
double calcVelocity(double initialVelocity, double acceleration, double time);
double calcAcceleration(double force, double mass);
bool isEqual(double a, double b);

int main() {
    double initialVelocity = 0; // m/s
    double timeInterval = 0.01; // s
    double time = 0; // s
    double force = 10; // Newtons
    double mass = 2; // kg
    double acceleration = calcAcceleration(force, mass); // m/s^2
    double deltaDisplacement; // m
    double currentDisplacement = 0; // m
    double previousDisplacement = 0; // m
    double currentVelocity = 0; // m/s
    double previousVelocity = 0; // m/s

    for (int i = 0; i < 500; i++) {
        deltaDisplacement = calcDisplacement(initialVelocity, acceleration, timeInterval);
        currentDisplacement = previousDisplacement + deltaDisplacement;

        currentVelocity = calcVelocity(initialVelocity, acceleration, timeInterval);

        // Output displacement and velocity
        printf("Displacement: %.2lf m\n", currentDisplacement);
        printf("Velocity: %.2lf m/s\n", currentVelocity);

        // Check if displacement and velocity are equal to zero
        if (isEqual(currentDisplacement, 0) && isEqual(currentVelocity, 0)) {
            break;
        }

        // Update variables
        previousDisplacement = currentDisplacement;
        previousVelocity = currentVelocity;
        time += timeInterval;
        initialVelocity = currentVelocity;
    }

    return 0;
}

/**
 * Calculates the displacement using the formula: d = vi*t + (1/2)*a*t^2
 */
double calcDisplacement(double initialVelocity, double acceleration, double time) {
    return (initialVelocity * time) + (0.5 * acceleration * pow(time, 2));
}

/**
 * Calculates the velocity using the formula: vf = vi + a*t
 */
double calcVelocity(double initialVelocity, double acceleration, double time) {
    return initialVelocity + (acceleration * time);
}

/**
 * Calculates the acceleration using the formula: a = F/m
 */
double calcAcceleration(double force, double mass) {
    return force / mass;
}

/**
 * Checks if two doubles are equal
 */
bool isEqual(double a, double b) {
    double epsilon = 0.0001; // tolerance for comparison
    return fabs(a - b) < epsilon;
}