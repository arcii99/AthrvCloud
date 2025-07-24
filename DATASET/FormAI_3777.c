//FormAI DATASET v1.0 Category: Robot movement control ; Style: standalone
#include <stdio.h>

#define MOVE_UP 0
#define MOVE_DOWN 1
#define MOVE_LEFT 2
#define MOVE_RIGHT 3

int xPos = 0;
int yPos = 0;

void printPosition()
{
    printf("Current Position: (%d, %d)\n", xPos, yPos);
}

void move(int direction, int steps)
{
    switch (direction)
    {
        case MOVE_UP:
            yPos += steps;
            break;
        case MOVE_DOWN:
            yPos -= steps;
            break;
        case MOVE_LEFT:
            xPos -= steps;
            break;
        case MOVE_RIGHT:
            xPos += steps;
            break;
        default:
            break;
    }
    printPosition();
}

int main()
{
    printPosition();
    move(MOVE_UP, 5);
    move(MOVE_LEFT, 2);
    move(MOVE_DOWN, 3);
    move(MOVE_RIGHT, 4);
    move(MOVE_UP, 2);

    return 0;
}