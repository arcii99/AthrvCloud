//FormAI DATASET v1.0 Category: Robot movement control ; Style: future-proof
#include <stdio.h>

// Define robot movement directions
#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4

// Define function to move robot in desired direction
void moveRobot(int direction, int distance) {
    // Code to control robot movement goes here
    printf("Moving robot %d meters %s\n", distance, (direction == FORWARD) ? "forward" : (direction == BACKWARD) ? "backward" : (direction == LEFT) ? "left" : "right");
}

// Define function to turn robot in desired direction
void turnRobot(int direction) {
    // Code to control robot turning goes here
    printf("Turning robot %s\n", (direction == LEFT) ? "left" : "right");
}

int main() {
    // Test robot movements
    moveRobot(FORWARD, 5);
    moveRobot(BACKWARD, 3);
    turnRobot(LEFT);
    moveRobot(FORWARD, 2);
    turnRobot(RIGHT);
    moveRobot(FORWARD, 4);

    return 0;
}