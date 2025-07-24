//FormAI DATASET v1.0 Category: Robot movement control ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0)); // Initializing random number generator with current time

    // Initializing position variables
    int x = 0;
    int y = 0;

    // Starting movement loop
    for(int i = 0; i < 10; i++)
    {
        int direction = rand() % 4; // Generating random number between 0 and 3

        switch(direction)
        {
            case 0: // Robot moves left
                x--;
                printf("Moved left. New position: (%d, %d)\n", x, y);
                break;
            case 1: // Robot moves right
                x++;
                printf("Moved right. New position: (%d, %d)\n", x, y);
                break;
            case 2: // Robot moves up
                y++;
                printf("Moved up. New position: (%d, %d)\n", x, y);
                break;
            case 3: // Robot moves down
                y--;
                printf("Moved down. New position: (%d, %d)\n", x, y);
                break;
            default:
                printf("Something went wrong!");
                exit(1);
        }
    }

    return 0;
}