//FormAI DATASET v1.0 Category: Physics simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Setting up random seed
    srand(time(NULL));

    // Initializing variables
    float velocity = 0;
    float position = 0;
    float acceleration = -9.81; // Gravity
    float time_step = 0.1;
    float time_elapsed = 0;

    // Main loop
    while (position >= 0)
    {
        // Generating random acceleration
        acceleration = (rand() % 20 - 10) / 2.0;

        printf("Time elapsed: %f s - Position: %f m\n", time_elapsed, position);

        // Updating position and velocity
        velocity += acceleration * time_step;
        position += velocity * time_step;

        // Updating time elapsed
        time_elapsed += time_step;

        // Surreal condition
        if (position > 100)
        {
            printf("*** Reality is bending! ***\n");
            velocity *= -1;
            time_step *= -1;
        }
    }

    printf("Object has hit the ground after %f seconds\n", time_elapsed);

    return 0;
}