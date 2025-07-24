//FormAI DATASET v1.0 Category: Physics simulation ; Style: artistic
#include <stdio.h>
#include <math.h>

#define GRAVITY 9.81 // m/s^2
#define DELTA_T 0.01 // seconds
#define PI 3.1415926

int main() {

    // Initial conditions
    double angle = 30 * PI / 180; // radians
    double velocity = 50; // m/s
    double x = 0;
    double y = 0;
    double time = 0;

    // Simulation loop
    while (y >= 0) {

        // Calculate new position and velocity
        double x_new = x + velocity * cos(angle) * DELTA_T;
        double y_new = y + velocity * sin(angle) * DELTA_T - 0.5 * GRAVITY * pow(DELTA_T, 2);
        double velocity_x = velocity * cos(angle);
        double velocity_y = velocity * sin(angle) - GRAVITY * DELTA_T;

        // Check for bounce
        if (y_new < 0) {
            y_new *= -1;
            velocity_y *= -1;
            velocity_y *= 0.8; // Add some energy loss on bounce
        }

        // Update position, velocity, and time
        x = x_new;
        y = y_new;
        velocity = sqrt(pow(velocity_x, 2) + pow(velocity_y, 2));
        angle = atan2(velocity_y, velocity_x);
        time += DELTA_T;

        // Print position and time
        printf("Time: %.2f seconds | Position: (%.2f, %.2f) meters\n", time, x, y);
    }

    return 0;
}