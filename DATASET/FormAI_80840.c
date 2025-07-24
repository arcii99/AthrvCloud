//FormAI DATASET v1.0 Category: Robot movement control ; Style: portable
#include <stdio.h>

// Declare a constant for maximum movement steps
#define MAX_STEPS 10

// Declare a struct for Robot movement
typedef struct {
    int x;
    int y;
} Movement;

// Function to move the Robot
Movement moveRobot(Movement currentMov, int x, int y) {
    Movement newMov = currentMov;

    // Check if the movement is within the bounds
    if (currentMov.x + x >= 0 && currentMov.x + x <= MAX_STEPS) {
        newMov.x += x;
    }

    if (currentMov.y + y >= 0 && currentMov.y + y <= MAX_STEPS) {
        newMov.y += y;
    }

    // Return the new movement coordinates
    return newMov;
}

int main() {
    // Define Robot initial position
    Movement currentMov = {0, 0};

    // Move the Robot by (1, 2) steps
    currentMov = moveRobot(currentMov, 1, 2);
    printf("New Robot position: (%d, %d)\n", currentMov.x, currentMov.y);

    // Move the Robot by (-1, -4) steps
    currentMov = moveRobot(currentMov, -1, -4);
    printf("New Robot position: (%d, %d)\n", currentMov.x, currentMov.y);

    // Move the Robot by (2, -3) steps
    currentMov = moveRobot(currentMov, 2, -3);
    printf("New Robot position: (%d, %d)\n", currentMov.x, currentMov.y);

    return 0;
}