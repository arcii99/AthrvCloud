//FormAI DATASET v1.0 Category: Physics simulation ; Style: synchronous
#include <stdio.h>

#define TIME_STEP 0.1 // time step (in seconds)
#define NUM_STEPS 100 // number of time steps to simulate
#define MASS 10.0 // mass of the object (in kg)
#define GRAVITY 9.81 // acceleration due to gravity (in m/s^2)

int main() {
    double velocity = 0.0;
    double position = 0.0;

    // simulate motion
    for (int i = 0; i < NUM_STEPS; i++) {
        double acceleration = GRAVITY; // constant acceleration
        velocity += acceleration * TIME_STEP;
        position += velocity * TIME_STEP;

        // print position at each time step
        printf("Time step %d: Position = %.2f m\n", i+1, position);
    }

    return 0;
}