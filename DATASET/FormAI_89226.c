//FormAI DATASET v1.0 Category: Physics simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // A simple simulation of bouncing balls in a box
    // The following code uses basic physics equations to calculate the velocity and position of the balls

    srand(time(NULL)); // Seed the random number generator

    int num_balls = 10;
    int box_width = 50;
    int box_height = 20;
    int ball_radius = 2;
    int max_velocity = 10;

    int x[num_balls];
    int y[num_balls];
    int vx[num_balls];
    int vy[num_balls];

    // Initialize the position and velocity of each ball
    for (int i = 0; i < num_balls; i++)
    {
        x[i] = rand() % (box_width - 2*ball_radius) + ball_radius;
        y[i] = rand() % (box_height - 2*ball_radius) + ball_radius;
        vx[i] = (rand() % (2*max_velocity)) - max_velocity;
        vy[i] = (rand() % (2*max_velocity)) - max_velocity;
    }

    // Simulate the motion of the balls for 100 iterations
    for (int i = 0; i < 100; i++)
    {
        // Update the position of each ball based on its velocity
        for (int j = 0; j < num_balls; j++)
        {
            x[j] += vx[j];
            y[j] += vy[j];

            // Check if the ball has collided with the walls of the box
            if (x[j] <= ball_radius || x[j] >= box_width - ball_radius)
            {
                vx[j] *= -1;
            }
            if (y[j] <= ball_radius || y[j] >= box_height - ball_radius)
            {
                vy[j] *= -1;
            }
        }

        // Print the current state of the simulation
        printf("Iteration %d:\n", i+1);
        for (int j = 0; j < num_balls; j++)
        {
            printf("Ball %d: (%d,%d)\n", j+1, x[j], y[j]);
        }
        printf("\n");
    }

    return 0;
}