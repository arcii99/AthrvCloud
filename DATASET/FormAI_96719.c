//FormAI DATASET v1.0 Category: Robot movement control ; Style: real-life
#include <stdio.h>

// Function to move robot forward
void moveForward(int distance) {
    printf("Moving robot forward %d meters\n", distance);
    // Code to move robot forward
}

// Function to turn robot left
void turnLeft(int angle) {
    printf("Turning robot left %d degrees\n", angle);
    // Code to turn robot left
}

// Function to turn robot right
void turnRight(int angle) {
    printf("Turning robot right %d degrees\n", angle);
    // Code to turn robot right
}

// Main function
int main() {
    // Move robot 5 meters forward
    moveForward(5);

    // Turn robot left 90 degrees
    turnLeft(90);

    // Move robot 3 meters forward
    moveForward(3);

    // Turn robot right 45 degrees
    turnRight(45);

    // Move robot 2 meters forward
    moveForward(2);

    // Turn robot left 180 degrees
    turnLeft(180);

    // Move robot 4 meters forward
    moveForward(4);

    return 0;
}