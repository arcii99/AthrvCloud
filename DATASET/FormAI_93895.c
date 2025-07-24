//FormAI DATASET v1.0 Category: Physics simulation ; Style: visionary
#include <stdio.h>
#include <math.h>

int main() {
    float initial_position, initial_velocity, acceleration;
    float position, velocity;
    float time_interval = 0.1; // Time interval of 0.1 seconds

    printf("Enter the initial position (in meters): ");
    scanf("%f", &initial_position);

    printf("Enter the initial velocity (in meters per second): ");
    scanf("%f", &initial_velocity);

    printf("Enter the acceleration (in meters per second squared): ");
    scanf("%f", &acceleration);

    // Initialize position and velocity
    position = initial_position;
    velocity = initial_velocity;

    for(int t=0; t<10; t++) { // Simulate for 10 seconds
        printf("At time %.1f seconds, position is %.2f meters and velocity is %.2f meters per second\n", t*time_interval, position, velocity);

        position += velocity * time_interval + 0.5 * acceleration * pow(time_interval, 2);
        velocity += acceleration * time_interval;
    }

    return 0;
}