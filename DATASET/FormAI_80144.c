//FormAI DATASET v1.0 Category: Robot movement control ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize random seed
    srand(time(NULL));

    int speed = 10; // Set initial speed
    int direction = 0; // Set initial direction
    int x = 0; // Set initial x-coordinate
    int y = 0; // Set initial y-coordinate

    printf("Starting position: (%d, %d)\n", x, y);

    // Move the robot randomly around
    for (int i = 1; i <= 5; i++)
    {
        printf("Move %d:\n", i);

        // Decide direction randomly
        direction = rand() % 4;

        switch(direction)
        {
            case 0:
                x += speed;
                printf("Move right %d units\n", speed);
                break;
            case 1:
                y += speed;
                printf("Move up %d units\n", speed);
                break;
            case 2:
                x -= speed;
                printf("Move left %d units\n", speed);
                break;
            case 3:
                y -= speed;
                printf("Move down %d units\n", speed);
                break;
            default:
                printf("Invalid direction\n");
        }

        printf("Current position: (%d, %d)\n\n", x, y);
    }

    return 0;
}