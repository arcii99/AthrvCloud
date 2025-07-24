//FormAI DATASET v1.0 Category: Physics simulation ; Style: thoughtful
#include <stdio.h>
#include <math.h>

int main() {

    /* This program simulates the motion of a ball being thrown in the air
    using the laws of physics */
    
    // Initialize variables
    double v0 = 20.0; // Initial velocity (m/s)
    double y0 = 2.5; // Initial height (m)
    double g = 9.81; // Acceleration due to gravity (m/s^2)
    double tMax = (2 * v0) / g; // Total time in air (s)
    double dt = 0.01; // Time step (s)
    
    // Loop through time steps
    for (double t = 0.0; t < tMax; t += dt) {
        double y = y0 + v0 * t - 0.5 * g * pow(t, 2);
        printf("Time: %.2f s, Height: %.2f m\n", t, y);
    }

    return 0;
}