//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int floor = 0;
    int destination = 0;
    int direction = 1;

    printf("Welcome to Grateful Elevator Simulation!\n\n");

    while(1)
    {
        printf("You are on floor %d.\n", floor);

        if(destination > floor)
        {
            printf("The elevator is going up.\n\n");
            direction = 1;
        }
        else if(destination < floor)
        {
            printf("The elevator is going down.\n\n");
            direction = -1;
        }

        while(destination != floor)
        {
            sleep(1);
            floor += direction;
            printf("You are now on floor %d.\n", floor);
        }

        printf("\nYou have arrived at your destination on floor %d.\n\n", destination);

        printf("Enter your destination floor number (0 to quit): ");
        scanf("%d", &destination);

        if(destination == 0)
        {
            printf("\nThank you for using Grateful Elevator Simulation!\n");
            exit(0);
        }
    }
    return 0;
}