//FormAI DATASET v1.0 Category: Robot movement control ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int xPos = 0; // current x position of robot
    int yPos = 0; // current y position of robot
    int direction = 0; // direction robot is facing (0 = North, 1 = East, 2 = South, 3 = West)

    srand(time(NULL)); // seed random number generator

    printf("Starting position: (%d,%d)\n", xPos, yPos);

    for(int i = 0; i < 50; i++) { // move robot 50 times
        int moveAmount = rand() % 5 + 1; // generate random move amount between 1 and 5

        switch(direction) { // check direction robot is facing
            case 0: // facing North
                yPos += moveAmount; // move up (positive y direction)
                break;
            case 1: // facing East
                xPos += moveAmount; // move right (positive x direction)
                break;
            case 2: // facing South
                yPos -= moveAmount; // move down (negative y direction)
                break;
            case 3: // facing West
                xPos -= moveAmount; // move left (negative x direction)
                break;
        }

        printf("Moved %d units in direction %d. New position: (%d,%d)\n", moveAmount, direction, xPos, yPos);

        direction = (rand() % 3 + 1 + direction) % 4; // generate random direction to turn (could also turn 90, 180, or 270 degrees)
    }

    printf("Final position: (%d,%d)\n", xPos, yPos);

    return 0;
}