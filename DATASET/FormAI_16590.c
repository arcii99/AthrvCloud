//FormAI DATASET v1.0 Category: Physics simulation ; Style: cheerful
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define GRAVITY -9.81
#define BOUNCE_FACTOR 0.8
#define TIME_STEP 0.1

// Function declarations
void simulate_bounce(double height, double velocity);

int main() {
    // Random seed for initial velocity
    srand(time(0));

    // Simulate 10 bounces
    for (int i = 1; i <= 10; i++) {
        double height = 10.0; // Starting height
        double velocity = (double) rand() / (double) RAND_MAX * 10.0; // Random initial velocity
        simulate_bounce(height, velocity);
    }

    return 0;
}

void simulate_bounce(double height, double velocity) {
    double time = 0.0;
    double position = height;

    // Simulate until the ball hits the ground
    while (position > 0.0) {
        // Update position and velocity
        position = height + velocity * time + 0.5 * GRAVITY * pow(time, 2.0);
        velocity = velocity + GRAVITY * time;

        // If the ball hits the ground, bounce it back up
        if (position < 0.0) {
            printf("Bounce!\n");
            velocity = -velocity * BOUNCE_FACTOR;
            position = 0.0;
        }

        // Print current position and time
        printf("Time: %.2f seconds, Position: %.2f meters\n", time, position);

        // Increment time by TIME_STEP
        time += TIME_STEP;
    }

    printf("The ball bounced for %.2f seconds.\n", time);
}