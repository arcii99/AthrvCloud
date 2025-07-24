//FormAI DATASET v1.0 Category: Robot movement control ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function to move the robot forward
void moveForward() {
    printf("Moving forward...\n");
    // Code to move the robot forward
}

// Function to move the robot backward
void moveBackward() {
    printf("Moving backward...\n");
    // Code to move the robot backward
}

// Function to turn the robot left
void turnLeft() {
    printf("Turning left...\n");
    // Code to turn the robot left
}

// Function to turn the robot right
void turnRight() {
    printf("Turning right...\n");
    // Code to turn the robot right
}

// Function to stop the robot
void stopRobot() {
    printf("Stopping Robot...\n");
    // Code to stop the robot
}

// Main function
int main() {
    int option;
    // Loop to get input from user
    while(1) {
        printf("\nPlease enter an option:\n");
        printf("1. Move Forward\n2. Move Backward\n3. Turn Left\n4. Turn Right\n5. Stop\n6. Exit\n");
        scanf("%d", &option);
        switch(option) {
            case 1: moveForward();
                    break;
            case 2: moveBackward();
                    break;
            case 3: turnLeft();
                    break;
            case 4: turnRight();
                    break;
            case 5: stopRobot();
                    break;
            case 6: exit(0);
            default: printf("Invalid option!\n");
        }
    }
    return 0;
}