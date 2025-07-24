//FormAI DATASET v1.0 Category: Robot movement control ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SPEED 100    // Maximum speed of robot
#define MIN_SPEED 0      // Minimum speed of robot
#define MAX_ANGLE 180    // Maximum angle of robot's movement
#define MIN_ANGLE 0      // Minimum angle of robot's movement
#define MAX_DISTANCE 10  // Maximum distance of robot's movement
#define MIN_DISTANCE 1   // Minimum distance of robot's movement

// Function to simulate random movement of the robot
void moveRobot() {
    int speed = (rand() % (MAX_SPEED - MIN_SPEED + 1)) + MIN_SPEED;         // Generate random speed
    int angle = (rand() % (MAX_ANGLE - MIN_ANGLE + 1)) + MIN_ANGLE;         // Generate random angle
    int distance = (rand() % (MAX_DISTANCE - MIN_DISTANCE + 1)) + MIN_DISTANCE; // Generate random distance

    printf("Moving robot with speed %d, angle %d degrees, and distance %d meters.\n", speed, angle, distance);
    // TODO: Add code to move robot according to the generated values
}

int main() {
    srand(time(0));      // Set random seed
    bool isMoving = true; // Set default state to moving

    while (isMoving) {
        moveRobot();              // Move robot in random direction
        printf("Do you want to continue moving? (Y/N): ");
        char ans;
        scanf("%c", &ans);        // Get user input to continue or stop
        if (ans == 'N' || ans == 'n') {
            isMoving = false;     // Stop robot movement
        }
    }

    printf("Robot movement stopped.\n");
    return 0;
}