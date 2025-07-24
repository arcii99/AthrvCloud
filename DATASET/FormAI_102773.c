//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LENGTH 100

void takeOff()
{
    printf("Drone is taking off..\n");
}

void land()
{
    printf("Drone is landing..\n");
}

void flyUp(int altitude)
{
    printf("Drone is flying up to %d meters..\n", altitude);
}

void flyDown(int altitude)
{
    printf("Drone is flying down to %d meters..\n", altitude);
}

void flyLeft(int distance)
{
    printf("Drone is moving left %d meters..\n", distance);
}

void flyRight(int distance)
{
    printf("Drone is moving right %d meters..\n", distance);
}

void flyForward(int distance)
{
    printf("Drone is flying forward %d meters..\n", distance);
}

void flyBackward(int distance)
{
    printf("Drone is flying backward %d meters..\n", distance);
}

void emergencyStop()
{
    printf("Emergency stop! Drone is landing immediately..\n");
}

int main()
{
    char cmd[MAX_CMD_LENGTH];

    printf("Welcome to the C Drone Remote Control!\n");

    while (1)
    {
        printf("Enter a command (takeoff, land, up, down, left, right, forward, backward, emergency): ");
        fgets(cmd, MAX_CMD_LENGTH, stdin);

        if (strcasecmp(cmd, "takeoff\n") == 0)
        {
            takeOff();
        }
        else if (strcasecmp(cmd, "land\n") == 0)
        {
            land();
        }
        else if (strncasecmp(cmd, "up", 2) == 0)
        {
            int altitude = atoi(cmd + 3);
            flyUp(altitude);
        }
        else if (strncasecmp(cmd, "down", 4) == 0)
        {
            int altitude = atoi(cmd + 5);
            flyDown(altitude);
        }
        else if (strncasecmp(cmd, "left", 4) == 0)
        {
            int distance = atoi(cmd + 5);
            flyLeft(distance);
        }
        else if (strncasecmp(cmd, "right", 5) == 0)
        {
            int distance = atoi(cmd + 6);
            flyRight(distance);
        }
        else if (strncasecmp(cmd, "forward", 7) == 0)
        {
            int distance = atoi(cmd + 8);
            flyForward(distance);
        }
        else if (strncasecmp(cmd, "backward", 8) == 0)
        {
            int distance = atoi(cmd + 9);
            flyBackward(distance);
        }
        else if (strcasecmp(cmd, "emergency\n") == 0)
        {
            emergencyStop();
            break;
        }
        else
        {
            printf("Invalid command, please try again..\n");
        }
    }

    return 0;
}