//FormAI DATASET v1.0 Category: Robot movement control ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

/* Defining constants */
#define LEFT 'L'
#define RIGHT 'R'
#define FORWARD 'F'
#define BACKWARD 'B'

/* Defining function prototypes */
void moveForward();
void moveBackward();
void turnLeft();
void turnRight();
void performAction(char action, int steps);

/* Defining global variables */
int x_pos = 0;
int y_pos = 0;
char orientation = 'N';

int main()
{
    char actions[] = {'F', 'R', 'F', 'L', 'B'};
    int steps[] = {3, 1, 2, 2, 1};
    int numActions = sizeof(actions) / sizeof(actions[0]);

    for (int i = 0; i < numActions; i++)
    {
        performAction(actions[i], steps[i]);
    }

    printf("Final Position: (%d, %d)\n", x_pos, y_pos);
    printf("Final Orientation: %c\n", orientation);
    return 0;
}

void moveForward()
{
    switch (orientation)
    {
    case 'N':
        y_pos++;
        break;
    case 'E':
        x_pos++;
        break;
    case 'S':
        y_pos--;
        break;
    case 'W':
        x_pos--;
        break;
    }
}

void moveBackward()
{
    switch (orientation)
    {
    case 'N':
        y_pos--;
        break;
    case 'E':
        x_pos--;
        break;
    case 'S':
        y_pos++;
        break;
    case 'W':
        x_pos++;
        break;
    }
}

void turnLeft()
{
    switch (orientation)
    {
    case 'N':
        orientation = 'W';
        break;
    case 'E':
        orientation = 'N';
        break;
    case 'S':
        orientation = 'E';
        break;
    case 'W':
        orientation = 'S';
        break;
    }
}

void turnRight()
{
    switch (orientation)
    {
    case 'N':
        orientation = 'E';
        break;
    case 'E':
        orientation = 'S';
        break;
    case 'S':
        orientation = 'W';
        break;
    case 'W':
        orientation = 'N';
        break;
    }
}

void performAction(char action, int steps)
{
    printf("Performing action: %c for %d steps\n", action, steps);
    for (int i = 0; i < steps; i++)
    {
        switch (action)
        {
        case FORWARD:
            moveForward();
            break;
        case BACKWARD:
            moveBackward();
            break;
        case LEFT:
            turnLeft();
            break;
        case RIGHT:
            turnRight();
            break;
        }
        printf("Current Position: (%d, %d)\n", x_pos, y_pos);
        printf("Current Orientation: %c\n", orientation);
    }
}