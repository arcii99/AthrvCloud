//FormAI DATASET v1.0 Category: Robot movement control ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Initializes random number generator to generate random movement commands.
    int x = 0, y = 0; // Robot coordinates.
    int steps = 0; // Number of steps taken by robot.

    printf("Starting at position (%d, %d).\n", x, y);

    while (steps < 10) // Robot can only take 10 steps.
    {
        int direction = rand() % 4; // Generates random number between 0 and 3 to determine direction.
        
        switch (direction)
        {
            case 0: // Move up.
                y++;
                printf("Moved up to position (%d, %d).\n", x, y);
                break;
            case 1: // Move right.
                x++;
                printf("Moved right to position (%d, %d).\n", x, y);
                break;
            case 2: // Move down.
                y--;
                printf("Moved down to position (%d, %d).\n", x, y);
                break;
            case 3: // Move left.
                x--;
                printf("Moved left to position (%d, %d).\n", x, y);
                break;
        }

        steps++;
    }

    printf("Robot has taken %d steps and ended at position (%d, %d).\n", steps, x, y);

    return 0;
}