//FormAI DATASET v1.0 Category: Robot movement control ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define LEFT 0
#define RIGHT 1
#define FORWARD 2
#define BACKWARD 3

int main() {
    int robotX = 0;
    int robotY = 0;
    int robotDirection = RIGHT;

    printf("Starting position: (%d,%d)\n", robotX, robotY);
    printf("Starting direction: %d\n", robotDirection);

    // Move the robot forward 5 times
    for (int i = 0; i < 5; i++) {
        switch (robotDirection) {
            case LEFT:
                robotX--;
                break;
            case RIGHT:
                robotX++;
                break;
            case FORWARD:
                robotY--;
                break;
            case BACKWARD:
                robotY++;
                break;
        }
        printf("Moved forward to position: (%d,%d)\n", robotX, robotY);
    }

    // Change the direction to backward
    robotDirection = BACKWARD;
    printf("Changed direction to: %d\n", robotDirection);

    // Move the robot backward 3 times
    for (int i = 0; i < 3; i++) {
        switch (robotDirection) {
            case LEFT:
                robotX--;
                break;
            case RIGHT:
                robotX++;
                break;
            case FORWARD:
                robotY--;
                break;
            case BACKWARD:
                robotY++;
                break;
        }
        printf("Moved backward to position: (%d,%d)\n", robotX, robotY);
    }

    // Change the direction to left
    robotDirection = LEFT;
    printf("Changed direction to: %d\n", robotDirection);

    // Move the robot left 2 times
    for (int i = 0; i < 2; i++) {
        switch (robotDirection) {
            case LEFT:
                robotX--;
                break;
            case RIGHT:
                robotX++;
                break;
            case FORWARD:
                robotY--;
                break;
            case BACKWARD:
                robotY++;
                break;
        }
        printf("Moved left to position: (%d,%d)\n", robotX, robotY);
    }

    // Change the direction to right
    robotDirection = RIGHT;
    printf("Changed direction to: %d\n", robotDirection);

    // Move the robot right 4 times
    for (int i = 0; i < 4; i++) {
        switch (robotDirection) {
            case LEFT:
                robotX--;
                break;
            case RIGHT:
                robotX++;
                break;
            case FORWARD:
                robotY--;
                break;
            case BACKWARD:
                robotY++;
                break;
        }
        printf("Moved right to position: (%d,%d)\n", robotX, robotY);
    }

    // Spin the robot around in a circle
    robotDirection = FORWARD;
    printf("Changed direction to: %d\n", robotDirection);

    for (int i = 0; i < 4; i++) {
        robotDirection = (robotDirection + 1) % 4;
        printf("Spinning, now facing direction: %d\n", robotDirection);
    }

    return 0;
}