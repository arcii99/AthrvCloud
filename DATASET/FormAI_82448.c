//FormAI DATASET v1.0 Category: Robot movement control ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

// Define constants for the robot
#define FORWARD 1
#define BACKWARD -1
#define LEFT -1
#define RIGHT 1

// Define the function for the robot to move forward or backward
void move(int direction, int steps) {
    int i;
    for (i = 0; i < steps; i++) {
        printf("Moving %d step(s) %s\n", abs(i), (direction == FORWARD ? "forward" : "backward"));
    }
}

// Define the function for the robot to turn left or right
void turn(int direction, int angle) {
    printf("Turning %d degrees %s\n", angle, (direction == LEFT ? "left" : "right"));
}

int main() {
    int steps = 5;
    int angle = 90;
    int direction = FORWARD;

    // Move the robot forward
    move(direction, steps);

    // Turn the robot left
    turn(LEFT, angle);

    // Move the robot forward
    move(direction, steps);

    // Turn the robot right
    turn(RIGHT, angle);

    // Move the robot backward
    direction = BACKWARD;
    move(direction, steps);

    return 0;
}