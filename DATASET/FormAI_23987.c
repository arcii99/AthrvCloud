//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: recursive
#include <stdio.h>

void moveForward(int distance);
void moveBackward(int distance);
void turnLeft(int angle);
void turnRight(int angle);

void moveForward(int distance)
{
    if(distance > 0)
    {
        printf("Moving forward %d meters.\n", distance);
        moveForward(distance - 1);
    }
    else
    {
        printf("Stopped moving forward.\n");
    }
}

void moveBackward(int distance)
{
    if(distance > 0)
    {
        printf("Moving backward %d meters.\n", distance);
        moveBackward(distance - 1);
    }
    else
    {
        printf("Stopped moving backward.\n");
    }
}

void turnLeft(int angle)
{
    if(angle > 0)
    {
        printf("Turning left %d degrees.\n", angle);
        turnLeft(angle - 1);
    }
    else
    {
        printf("Stopped turning left.\n");
    }
}

void turnRight(int angle)
{
    if(angle > 0)
    {
        printf("Turning right %d degrees.\n", angle);
        turnRight(angle - 1);
    }
    else
    {
        printf("Stopped turning right.\n");
    }
}

int main()
{
    moveForward(10);
    turnLeft(90);
    moveForward(5);
    turnRight(45);
    moveBackward(3);

    return 0;
}