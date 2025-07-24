//FormAI DATASET v1.0 Category: Robot movement control ; Style: high level of detail
#include <stdio.h>

// Function to move robot forward
void moveForward() {
    printf("Robot moves forward\n");
}

// Function to move robot backward
void moveBackward() {
    printf("Robot moves backward\n");
}

// Function to turn robot left
void turnLeft() {
    printf("Robot turns left\n");
}

// Function to turn robot right
void turnRight() {
    printf("Robot turns right\n");
}

// Function to stop robot
void stopRobot() {
    printf("Robot stops\n");
}

int main() {
    char direction;
    int distance;

    // User input for direction and distance
    printf("Enter direction (F for forward, B for backward, L for left, R for right): ");
    scanf("%c", &direction);
    printf("Enter distance: ");
    scanf("%d", &distance);

    // Switch statement to perform action based on direction
    switch(direction) {
        case 'F':
            moveForward();
            break;
        case 'B':
            moveBackward();
            break;
        case 'L':
            turnLeft();
            break;
        case 'R':
            turnRight();
            break;
        default:
            printf("Invalid direction\n");
            break;
    }

    // Print distance traveled
    printf("Distance traveled: %d units\n", distance);

    stopRobot();

    return 0;
}