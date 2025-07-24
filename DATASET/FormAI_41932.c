//FormAI DATASET v1.0 Category: Robot movement control ; Style: authentic
#include <stdio.h>

// Define the maximum number of steps the robot can take in one direction
#define MAX_STEPS 10

// Define the robot's current position and direction
int xPos = 0;
int yPos = 0;
int direction = 0; // 0: North, 1: East, 2: South, 3: West

// Function to move the robot forward one step
void moveForward() {
    switch(direction) {
        case 0: // North
            if(yPos < MAX_STEPS) {
                yPos++;
            }
            break;
        case 1: // East
            if(xPos < MAX_STEPS) {
                xPos++;
            }
            break;
        case 2: // South
            if(yPos > -MAX_STEPS) {
                yPos--;
            }
            break;
        case 3: // West
            if(xPos > -MAX_STEPS) {
                xPos--;
            }
            break;
        default:
            printf("Invalid direction value\n");
            break;
    }
}

// Function to turn the robot left 90 degrees
void turnLeft() {
    direction--;
    if(direction < 0) {
        direction = 3;
    }
}

// Function to turn the robot right 90 degrees
void turnRight() {
    direction++;
    if(direction > 3) {
        direction = 0;
    }
}

int main() {
    // Move the robot forward 5 steps
    for(int i = 0; i < 5; i++) {
        moveForward();
    }
    
    // Turn the robot left and move forward 3 steps
    turnLeft();
    for(int i = 0; i < 3; i++) {
        moveForward();
    }
    
    // Turn the robot right and move forward 2 steps
    turnRight();
    for(int i = 0; i < 2; i++) {
        moveForward();
    }
    
    // Print the robot's final position and direction
    printf("Final position: (%d, %d)\n", xPos, yPos);
    printf("Final direction: %d\n", direction);
    
    return 0;
}