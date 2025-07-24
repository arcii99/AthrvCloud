//FormAI DATASET v1.0 Category: Robot movement control ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int x_pos = 0;
    int y_pos = 0;
    int direction = 0;
    int steps = 0;
    printf("Let's move the C Robot!\n");
    while(steps < 100)
    {
        int movement = rand() % 3;
        if(movement == 0 && direction != 2) // Move up
        {
            ++y_pos;
            direction = 0;
            printf("Moved up!\n");
        }
        else if(movement == 1 && direction != 3) // Move right
        {
            ++x_pos;
            direction = 1;
            printf("Moved right!\n");
        }
        else if(movement == 2 && direction != 0) // Move down
        {
            --y_pos;
            direction = 2;
            printf("Moved down!\n");
        }
        else // Move left
        {
            --x_pos;
            direction = 3;
            printf("Moved left!\n");
        }
        ++steps;
        printf("Position: (%d,%d)\n", x_pos, y_pos);
    }
    printf("The C Robot has finished its movement.\n");
    return 0;
}