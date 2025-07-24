//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int altitude = 0; // initialize the altitude to 0
    int direction = 0; // initialize the direction to 0 (North)

    printf("Welcome to C Drone Remote Control!\n");

    while (1) // loop indefinitely until user exits
    {
        printf("Current altitude: %d meters\n", altitude);
        printf("Current direction: %s\n", (direction == 0) ? "North" : (direction == 1) ? "East" : (direction == 2) ? "South" : "West");

        printf("Enter a command:\n");
        printf("1. Increase altitude\n");
        printf("2. Decrease altitude\n");
        printf("3. Change direction\n");
        printf("4. Exit\n");

        int command;
        scanf("%d", &command);

        switch (command)
        {
            case 1: altitude++; break;
            case 2: if (altitude > 0) altitude--; break;
            case 3: direction = (direction + 1) % 4; break; // change direction to the next direction clockwise
            case 4: exit(0);
        }
    }

    return 0;
}