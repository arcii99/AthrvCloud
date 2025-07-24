//FormAI DATASET v1.0 Category: Robot movement control ; Style: safe
#include <stdio.h>

//Function prototype
int moveRobot(int currentX, int currentY);
int turnRight(int currentDirection);
int turnLeft(int currentDirection);

int main()
{
    //Initial position and direction
    int currentX = 0;
    int currentY = 0;
    int currentDirection = 0; //0 for North, 1 for East, 2 for South, 3 for West

    printf("Starting position of Robot: (%d,%d)\n", currentX, currentY);

    //Moving the robot
    moveRobot(currentX, currentY);
    turnLeft(currentDirection);
    moveRobot(currentX, currentY);
    turnRight(currentDirection);
    moveRobot(currentX, currentY);

    printf("Final position of Robot: (%d,%d)\n", currentX, currentY);

    return 0;
}

//Function to move the robot
int moveRobot(int currentX, int currentY)
{
    int distance = 10;
    int newX = currentX + distance;
    int newY = currentY + distance;

    printf("Moving Robot to position: (%d,%d)\n", newX, newY);

    return 0;
}

//Function to turn the robot right
int turnRight(int currentDirection)
{
    int newDirection = (currentDirection + 1) % 4;

    printf("Turning Robot right. New direction: %d\n", newDirection);

    return newDirection;
}

//Function to turn the robot left
int turnLeft(int currentDirection)
{
    int newDirection = (currentDirection + 3) % 4;

    printf("Turning Robot left. New direction: %d\n", newDirection);

    return newDirection;
}