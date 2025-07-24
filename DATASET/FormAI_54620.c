//FormAI DATASET v1.0 Category: Robot movement control ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// function to move the robot forward
void moveForward(int distance) {
    printf("Moving forward %d feet.\n", distance);
}

// function to move the robot backward
void moveBackward(int distance) {
    printf("Moving backward %d feet.\n", distance);
}

// function to turn the robot left
void turnLeft(int degrees) {
    printf("Turning left %d degrees.\n", degrees);
}

// function to turn the robot right
void turnRight(int degrees) {
    printf("Turning right %d degrees.\n", degrees);
}

int main() {
    int x, y;
    x = 0;
    y = 0;

    // print starting coordinates
    printf("Starting point: (%d, %d)\n\n", x, y);

    // move the robot forward 5 feet
    moveForward(5);
    x += 5;

    // turn the robot left 90 degrees
    turnLeft(90);

    // move the robot forward 10 feet
    moveForward(10);
    y += 10;

    // turn the robot right 45 degrees
    turnRight(45);

    // move the robot backward 2 feet
    moveBackward(2);
    y -= 2;

    // turn the robot left 180 degrees
    turnLeft(180);

    // move the robot forward 8 feet
    moveForward(8);
    x += 8;

    // print final coordinates
    printf("\nFinal point: (%d, %d)\n", x, y);

    return 0;
}