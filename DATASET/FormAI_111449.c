//FormAI DATASET v1.0 Category: Robot movement control ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

int moveRobot(int position, int direction, int steps);

int main() {
    int startingPoint = 0;
    int direction = 1;
    int maxSteps = 5;
    int finalPosition = moveRobot(startingPoint, direction, maxSteps);
    printf("The final position of the robot is: %d\n", finalPosition);
    return 0;
}

int moveRobot(int position, int direction, int steps) {
    if (steps == 0) {
        return position;
    }
    printf("The robot is currently at position: %d\n", position);
    int maxSteps = (position >= 0) ? direction : -1 * direction;
    if (steps < abs(maxSteps)) {
        maxSteps = (steps > 0) ? steps : -1 * steps;
    }
    position += maxSteps;
    return moveRobot(position, -1 * direction, steps - abs(maxSteps));
}