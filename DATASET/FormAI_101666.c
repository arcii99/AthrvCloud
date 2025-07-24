//FormAI DATASET v1.0 Category: Robot movement control ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Function to recursively move the robot
void moveRobot(int position, int direction, int distance) {
    // Base case: robot has reached the destination
    if (distance == 0) {
        printf("Robot has reached the destination!\n");
        return;
    }

    // Print current position and direction
    printf("Robot is currently at position %d facing %s\n", position, (direction == 0) ? "North" : "South");

    // Check if robot is at the edge of the room
    if (position == 0 || position == 9) {
        direction = !direction; // Reverse direction
        distance--; // Reduce distance since robot will take a step in opposite direction
    }

    // Move robot one step in the current direction
    if (direction == 0) {
        // Move north
        position++;
    } else {
        // Move south
        position--;
    }

    // Recursively call the function with updated position, direction, and distance
    moveRobot(position, direction, distance);
}

int main() {
    // Initialize starting position, direction, and distance
    int startPosition = 0;
    int startDirection = 0;
    int totalDistance = 20;

    // Call the moveRobot function to move the robot recursively
    moveRobot(startPosition, startDirection, totalDistance);

    return 0;
}