//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UP 1
#define DOWN -1
#define LEFT -1
#define RIGHT 1

// Function to generate a random number within a given range
int generate_random_number(int lower, int upper)
{
    return (rand() % (upper - lower + 1)) + lower;
}

// Function to move the vehicle in a given direction
void move_vehicle(int *x, int *y, int direction_x, int direction_y)
{
    *x += direction_x;
    *y += direction_y;
}

int main()
{
    // Initialize the vehicle's position and direction
    int x = 0, y = 0, direction_x = RIGHT, direction_y = UP;

    // Initialize the seed for the random number generator
    srand(time(NULL));

    // Run the simulation for a given number of iterations
    int iterations = 10;
    for (int i = 0; i < iterations; i++)
    {
        // Generate a random number to decide the next movement
        int movement = generate_random_number(0, 3);

        // Check the movement and update the vehicle's position accordingly
        switch (movement)
        {
            case 0:
                move_vehicle(&x, &y, direction_x, direction_y);
                break;
            case 1:
                move_vehicle(&x, &y, direction_x, 0);
                break;
            case 2:
                move_vehicle(&x, &y, 0, direction_y);
                break;
            case 3:
                direction_x = -1 * direction_x;
                direction_y = -1 * direction_y;
                break;
            default:
                printf("Invalid movement.\n");
                break;
        }

        // Print the current position and direction of the vehicle
        printf("Iteration %d: (%d, %d), direction: (%d, %d)\n", i+1, x, y, direction_x, direction_y);
    }

    return 0;
}