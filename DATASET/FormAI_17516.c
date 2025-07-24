//FormAI DATASET v1.0 Category: Robot movement control ; Style: multivariable
#include <stdio.h>

// Function definitions
void moveForward(int distance);
void turnRight(int degrees);
void turnLeft(int degrees);
void moveBackward(int distance);

int main() {

    // Sample movement instructions
    moveForward(10);
    turnRight(90);
    moveForward(5);
    turnLeft(45);
    moveBackward(7);
    turnRight(135);
    moveForward(12);

    return 0;
}

void moveForward(int distance) {
    printf("Moving forward %d units\n", distance);
    // Code for robot to move forward
}

void turnRight(int degrees) {
    printf("Turning right %d degrees\n", degrees);
    // Code for robot to turn right
}

void turnLeft(int degrees) {
    printf("Turning left %d degrees\n", degrees);
    // Code for robot to turn left
}

void moveBackward(int distance) {
    printf("Moving backward %d units\n", distance);
    // Code for robot to move backward
}