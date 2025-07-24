//FormAI DATASET v1.0 Category: Robot movement control ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Irregular Robot Movement Control Program\n\n");

    int direction, speed, distance, turn;

    srand(time(0));

    for(int i = 0; i < 5; i++)
    {
        // generate random direction (1-4)
        direction = rand() % 4 + 1;

        // generate random speed (0-10)
        speed = rand() % 11;

        // generate random distance (1-50)
        distance = rand() % 50 + 1;

        printf("Move %d:\n", i+1);

        switch(direction)
        {
            case 1:
                printf("Moving Forward ");
                break;
            case 2:
                printf("Moving Backward ");
                break;
            case 3:
                printf("Moving Left ");
                break;
            case 4:
                printf("Moving Right ");
                break;
            default:
                break;
        }

        printf("at Speed %d for Distance %d inches\n", speed, distance);

        // generate random turn angle (-90 to 90)
        turn = rand() % 181 - 90;

        if(turn < 0)
        {
            printf("Turning Left by %d degrees\n\n", abs(turn));
        }
        else if(turn > 0)
        {
            printf("Turning Right by %d degrees\n\n", turn);
        }
        else
        {
            printf("No Turn Required\n\n");
        }
    }

    printf("Program Completed");
    
    return 0;
}