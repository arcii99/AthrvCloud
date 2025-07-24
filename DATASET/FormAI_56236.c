//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: dynamic
#include <stdio.h>

// Function to move the drone forward
void moveForward() {
    printf("Moving drone forward...\n");
}

// Function to move the drone backward
void moveBackward() {
    printf("Moving drone backward...\n");
}

// Function to move the drone left
void moveLeft() {
    printf("Moving drone left...\n");
}

// Function to move the drone right
void moveRight() {
    printf("Moving drone right...\n");
}

// Function to rotate the drone to the left
void rotateLeft() {
    printf("Rotating drone to the left...\n");
}

// Function to rotate the drone to the right
void rotateRight() {
    printf("Rotating drone to the right...\n");
}

int main() {
    char command;
    
    printf("*** Drone Remote Control ***\n\n");
    printf("Press 'f' to move forward\n");
    printf("Press 'b' to move backward\n");
    printf("Press 'l' to move left\n");
    printf("Press 'r' to move right\n");
    printf("Press 'L' to rotate left\n");
    printf("Press 'R' to rotate right\n\n");
    
    while (1) {
        printf("Enter command: ");
        scanf(" %c", &command);
        
        switch (command) {
            case 'f':
                moveForward();
                break;
            case 'b':
                moveBackward();
                break;
            case 'l':
                moveLeft();
                break;
            case 'r':
                moveRight();
                break;
            case 'L':
                rotateLeft();
                break;
            case 'R':
                rotateRight();
                break;
            default:
                printf("Invalid command.\n");
                break;
        }
    }
    
    return 0;
}