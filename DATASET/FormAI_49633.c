//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_SIZE 100

int main()
{
    char command[MAX_COMMAND_SIZE];
    int altitude = 0;
    int speed = 0;
    int battery = 100;
    int crashed = 0;

    printf("Welcome to the C Drone Remote Control program!\n");

    while(!crashed && battery > 0)
    {
        printf("Enter a command (fly, land, move up, move down, move left, move right, battery): ");
        fgets(command, MAX_COMMAND_SIZE, stdin);
        command[strcspn(command, "\r\n")] = '\0';

        if(strcmp(command, "fly") == 0)
        {
            if(altitude == 0)
            {
                printf("Taking off...\n");
                altitude = 20;
                speed = 10;
            }
            else
            {
                printf("Already in flight!\n");
            }
        }
        else if(strcmp(command, "land") == 0)
        {
            if(altitude == 0)
            {
                printf("Already on the ground!\n");
            }
            else
            {
                printf("Landing...\n");
                altitude = 0;
                speed = 0;
            }
        }
        else if(strcmp(command, "move up") == 0)
        {
            if(altitude == 0)
            {
                printf("The drone is on the ground, can't move up!\n");
            }
            else
            {
                altitude += 10;
                printf("Moving up...\n");
            }
        }
        else if(strcmp(command, "move down") == 0)
        {
            if(altitude == 0)
            {
                printf("The drone is already on the ground!\n");
            }
            else
            {
                altitude -= 10;
                printf("Moving down...\n");
            }
        }
        else if(strcmp(command, "move left") == 0)
        {
            if(speed == 0)
            {
                printf("The drone is stationary, can't move left or right!\n");
            }
            else
            {
                printf("Moving left...\n");
            }
        }
        else if(strcmp(command, "move right") == 0)
        {
            if(speed == 0)
            {
                printf("The drone is stationary, can't move left or right!\n");
            }
            else
            {
                printf("Moving right...\n");
            }
        }
        else if(strcmp(command, "battery") == 0)
        {
            printf("Battery: %d%%\n", battery);
        }
        else
        {
            printf("Invalid command!\n");
        }

        if(altitude > 0)
        {
            battery -= 5;
        }

        if(battery <= 0)
        {
            printf("Battery depleted, drone crashed!\n");
            crashed = 1;
        }
    }

    printf("Exiting program...\n");

    return 0;
}