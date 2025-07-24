//FormAI DATASET v1.0 Category: Robot movement control ; Style: systematic
// This program is an example of how to control the movement of a robot using C programming language

#include <stdio.h>
#include <stdlib.h>

// Initialize robot movements
int moveForward(int distance) {
    printf("Moved forward by %d cm.\n", distance);
    return distance;
}

int moveBackward(int distance) {
    printf("Moved backward by %d cm.\n", distance);
    return -distance;
}

int turnLeft(int angle) {
    printf("Turned left by %d degrees.\n", angle);
    return -angle;
}

int turnRight(int angle) {
    printf("Turned right by %d degrees.\n", angle);
    return angle;
}

// Main function
int main() {

    // Initial robot position
    int x_pos = 0;
    int y_pos = 0;

    // Move robot forward by 10 cm
    int forward_distance = moveForward(10);
    x_pos += forward_distance;

    // Turn robot left by 90 degrees
    int angle = turnLeft(90);

    // Move robot forward by 5 cm
    forward_distance = moveForward(5);
    x_pos += forward_distance;

    // Turn robot right by 45 degrees
    angle = turnRight(45);

    // Move robot backward by 3 cm
    int backward_distance = moveBackward(3);
    x_pos += backward_distance;

    // Output final robot position
    printf("\nFinal robot position:\n");
    printf("X position: %d cm\n", x_pos);
    printf("Y position: %d cm\n", y_pos);

    return 0;
}