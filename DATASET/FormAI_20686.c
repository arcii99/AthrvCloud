//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: high level of detail
// This is a C program for drone remote control
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 0, y = 0, z = 0; // x-axis, y-axis, z-axis
    printf("Welcome to Drone Remote Control\n\n");
    printf("Enter x-axis value: ");
    scanf("%d", &x); // read input from user

    printf("Enter y-axis value: ");
    scanf("%d", &y); // read input from user

    printf("Enter z-axis value: ");
    scanf("%d", &z); // read input from user

    printf("\nThe drone is moving to (%d,%d,%d)", x, y, z); // display the coordinates of the drone

    if (x <= 10 && y <= 10 && z <= 10) // check if the drone is within the area range
    {
        printf("\nThe drone is within the area range.\n");
    }
    else // if not within the area range
    {
        printf("\nThe drone is out of the area range.\n");
    }

    switch (z) // check z-axis and perform corresponding action
    {
    case 0:
        printf("\nThe drone has landed.\n");
        break;
    case 1:
        printf("\nThe drone is taking off.\n");
        break;
    default:
        printf("\nThe drone is in the air.\n");
        break;
    }

    return 0;
}