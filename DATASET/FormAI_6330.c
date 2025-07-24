//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

//Declaration of function to move the remote control vehicle
void move_vehicle(int direction);

int main()
{
    int choice;
    printf("Welcome to Remote Control Vehicle Simulation\n");
    printf("Please select a direction to move the vehicle:\n");
    printf("1. Forward\n");
    printf("2. Backward\n");
    printf("3. Left\n");
    printf("4. Right\n");

    //Reading user input
    scanf("%d", &choice);

    //Calling function to move vehicle in the selected direction
    move_vehicle(choice);

    return 0;
}

//Function to move vehicle in the selected direction
void move_vehicle(int direction)
{
    switch(direction)
    {
        case 1:
            printf("Vehicle moving forward\n");
            break;
        case 2:
            printf("Vehicle moving backward\n");
            break;
        case 3:
            printf("Vehicle turning left\n");
            break;
        case 4:
            printf("Vehicle turning right\n");
            break;
        default:
            printf("Invalid direction selected\n");
            break;
    }
}