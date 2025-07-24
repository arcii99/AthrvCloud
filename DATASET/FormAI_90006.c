//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: ultraprecise
#include <stdio.h>

int main()
{
    int total_floors = 10, current_floor = 1, target_floor;
    char direction = 'u';

    printf("Welcome to Elevator Simulation\n");
    printf("Please enter your target floor (1-%d): ", total_floors);
    scanf("%d", &target_floor);

    while (current_floor != target_floor)
    {
        if (direction == 'u')
        {
            printf("Going up...");
            current_floor++;
        }
        else
        {
            printf("Going down...");
            current_floor--;
        }

        // Print the current floor
        printf(" Current floor: %d\n", current_floor);

        // Change direction if we reach the top or bottom floor
        if (current_floor == total_floors)
        {
            printf("Reached top floor, changing direction\n");
            direction = 'd';
        }
        else if (current_floor == 1)
        {
            printf("Reached bottom floor, changing direction\n");
            direction = 'u';
        }
    }

    printf("You have reached your destination at floor %d\n", target_floor);

    return 0;
}