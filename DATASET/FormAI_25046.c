//FormAI DATASET v1.0 Category: Physics simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main() {
    // Initial velocity
    float v = 50;
    // Launch angle in degrees
    float theta = 45;
    // Initial height
    float h = 10;
    // Time interval
    float dt = 0.01;
    // Acceleration due to gravity
    float g = 9.8;

    // Convert angle to radians
    float rad = theta * PI / 180.0;

    // Initial x and y velocities
    float vx = v * cos(rad);
    float vy = v * sin(rad);

    // Calculate total flight time
    float t_flight = 2.0 * vy / g;

    // Initialize position and time variables
    float x = 0;
    float y = h;
    float t = 0;
    float max_height = h;

    // Simulate projectile motion
    while (t < t_flight) {
        // Update position and velocity
        x = x + vx * dt;
        y = y + vy * dt;
        vy = vy - g * dt;
        t = t + dt;

        // Check for new maximum height
        if (y > max_height) {
            max_height = y;
        }

        // Print position at every second
        if (fmod(t, 1.0) < dt) {
            printf("Time: %f sec, Position: (%f, %f)\n", t, x, y);
        }
    }

    // Print maximum height
    printf("Maximum Height Reached: %f\n", max_height);

    return 0;
}