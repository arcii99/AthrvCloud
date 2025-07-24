//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int command;

    printf("Welcome to the drone remote control system!\n\n");
    printf("Please choose a command:\n");
    printf("1 - Take off\n");
    printf("2 - Land\n");
    printf("3 - Move up\n");
    printf("4 - Move down\n");
    printf("5 - Move forward\n");
    printf("6 - Move backward\n");
    printf("7 - Move to the left\n");
    printf("8 - Move to the right\n");
    printf("9 - Rotate to the left\n");
    printf("10 - Rotate to the right\n\n");

    while(1)
    {
        printf("Enter command: ");
        scanf("%d", &command);

        switch(command)
        {
            case 1:
                printf("Taking off...\n\n");
                break;
            case 2:
                printf("Landing...\n\n");
                break;
            case 3:
                printf("Moving up...\n\n");
                break;
            case 4:
                printf("Moving down...\n\n");
                break;
            case 5:
                printf("Moving forward...\n\n");
                break;
            case 6:
                printf("Moving backward...\n\n");
                break;
            case 7:
                printf("Moving to the left...\n\n");
                break;
            case 8:
                printf("Moving to the right...\n\n");
                break;
            case 9:
                printf("Rotating to the left...\n\n");
                break;
            case 10:
                printf("Rotating to the right...\n\n");
                break;
            default:
                printf("Invalid command!\n\n");
        }
    }

    return 0;
}