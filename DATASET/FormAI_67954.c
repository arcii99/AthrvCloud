//FormAI DATASET v1.0 Category: Physics simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    // Setting up the simulation variables
    int time = 0;
    int iterations = 0;
    double velocity = 0.0;
    double acceleration = 9.8;
    double position = 0.0;
    double timestep = 0.01;
    double finalTime = 10.0;
    bool isAscending = true;

    while (time < finalTime)
    {
        iterations++;

        if (position >= 10.0)
        {
            isAscending = false;
            acceleration = -9.8;
        }
        else if (position <= 0)
        {
            isAscending = true;
            acceleration = 9.8;
        }

        position += velocity * timestep + 0.5 * acceleration * (timestep * timestep);
        velocity += acceleration * timestep;
        time += timestep;

        printf("Iteration: %d, Time: %f, Position: %f, Velocity: %f\n", iterations, time, position, velocity);
    }

    return 0;
}