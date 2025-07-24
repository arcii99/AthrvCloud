//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Cyberpunk
/*
    Cyberpunk style C Drone Remote Control program
    Author: AI Bot
    Date: 2099-07-23
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

int main()
{
    char command[MAX_COMMAND_LENGTH];
    int drone_distance = 0;
    int drone_speed = 0;

    printf("Initializing Cyberdrone 3000 Remote Control...\n");
    printf("Enter a command or type 'help' for a list of commands.\n\n");

    while (1)
    {
        printf("> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        strtok(command, "\n");

        if (strcmp(command, "help") == 0)
        {
            printf("COMMANDS:\n");
            printf("  fly <distance>: Fly the drone a certain distance\n");
            printf("  speed <speed>: Set the drone's speed (max 100)\n");
            printf("  info: Display the drone's current info\n");
            printf("  exit: Shut down the remote control and exit\n");
        }
        else if (strncmp(command, "fly ", 4) == 0)
        {
            int distance = atoi(command + 4);

            if (distance > 0)
            {
                printf("Cyberdrone 3000 taking off...\n");
                printf("Flying %d meters...\n", distance);
                drone_distance += distance;
            }
            else
            {
                printf("The drone cannot fly a negative distance.\n");
            }
        }
        else if (strncmp(command, "speed ", 6) == 0)
        {
            int speed = atoi(command + 6);

            if (speed > 0 && speed <= 100)
            {
                printf("Setting the drone's speed to %d...\n", speed);
                drone_speed = speed;
            }
            else
            {
                printf("The drone's speed must be between 1 and 100.\n");
            }
        }
        else if (strcmp(command, "info") == 0)
        {
            printf("DRONE INFO:\n");
            printf("  Distance flown: %d meters\n", drone_distance);
            printf("  Speed: %d\n", drone_speed);
        }
        else if (strcmp(command, "exit") == 0)
        {
            printf("Shutting down the Cyberdrone 3000 Remote Control...\n");
            return 0;
        }
        else
        {
            printf("Unknown command. Type 'help' for a list of valid commands.\n");
        }

        printf("\n");
    }
}