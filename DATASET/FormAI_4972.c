//FormAI DATASET v1.0 Category: Robot movement control ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // initialize random number generator
    srand(time(NULL));

    // define variables for robot position and movement
    int x = 0, y = 0, moveX, moveY;

    // generate random movement values for x and y
    moveX = rand() % 10 + 1;
    moveY = rand() % 10 + 1;

    // print initial position and movement
    printf("Starting position: (%d, %d)\n", x, y);
    printf("Moving %d units to the right and %d units up\n", moveX, moveY);

    // move the robot
    for (int i = 0; i < moveX; i++)
    {
        x++;
        printf("Robot moves to the right, new position: (%d, %d)\n", x, y);
    }
    for (int i = 0; i < moveY; i++)
    {
        y++;
        printf("Robot moves up, new position: (%d, %d)\n", x, y);
    }

    // generate final movement values for x and y
    moveX = rand() % 10 + 1;
    moveY = rand() % 10 + 1;

    // print final movement values and new position
    printf("Moving %d units to the left and %d units down\n", moveX, moveY);
    for (int i = 0; i < moveX; i++)
    {
        x--;
        printf("Robot moves to the left, new position: (%d, %d)\n", x, y);
    }
    for (int i = 0; i < moveY; i++)
    {
        y--;
        printf("Robot moves down, new position: (%d, %d)\n", x, y);
    }

    // print final position
    printf("Final position: (%d, %d)\n", x, y);

    return 0;
}