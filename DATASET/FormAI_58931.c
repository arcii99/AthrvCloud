//FormAI DATASET v1.0 Category: Physics simulation ; Style: careful
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    // Define constants
    const int GRAVITY = 9.81; // m/s^2
    const int TIME_PER_FRAME = 1; // seconds
    const int MAX_HEIGHT = 100; // meters
    const int MAX_VEL = 50; // m/s
    const int MAX_ANGLE = 90; // degrees

    // Define variables
    int height, velocity, angle, x_pos=0, y_pos=0;
    float time_elapsed = 0.0;

    // Get input values
    srand(time(NULL)); // Initialize random seed
    height = rand() % MAX_HEIGHT + 1; // Random height from 1 to MAX_HEIGHT
    velocity = rand() % MAX_VEL + 1; // Random velocity from 1 to MAX_VEL
    angle = rand() % MAX_ANGLE + 1; // Random angle from 1 to MAX_ANGLE

    // Calculate distance and time
    float radians = angle * 3.14159 / 180; // Convert angle to radians
    int distance = (velocity * velocity * sin(2 * radians)) / GRAVITY; // Calculate distance
    float time = distance / (velocity * cos(radians)); // Calculate time

    // Print input values and result
    printf("Projectile simulation\n");
    printf("Starting height: %d meters\n", height);
    printf("Initial velocity: %d m/s at %d degrees\n", velocity, angle);
    printf("Distance traveled: %d meters\n", distance);

    // Simulate projectile motion
    while (y_pos >= 0) {
        time_elapsed += TIME_PER_FRAME; // Increment time
        x_pos = (int)(velocity * cos(radians) * time_elapsed); // Calculate x position
        y_pos = (int)(height + velocity * sin(radians) * time_elapsed - 0.5 * GRAVITY * time_elapsed * time_elapsed); // Calculate y position
        printf("Time elapsed: %.1f sec, x position: %d m, y position: %d m\n", time_elapsed, x_pos, y_pos);
    }

    printf("Projectile has landed after %.1f seconds\n", time_elapsed);

    return 0;
}