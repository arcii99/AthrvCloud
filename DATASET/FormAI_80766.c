//FormAI DATASET v1.0 Category: Robot movement control ; Style: cheerful
#include <stdio.h>

// Function to move forward
void moveForward() {
    printf("Moving Forward...\n");
}

// Function to move backward
void moveBackward() {
    printf("Moving Backward...\n");
}

// Function to turn left
void turnLeft() {
    printf("Turning Left...\n");
}

// Function to turn right
void turnRight() {
    printf("Turning Right...\n");
}

// Main function to control robot movement
int main() {
    int input;
    
    printf("\nHello there! Let's Control the Robot!\n");
    printf("Enter 1 to move Forward\n");
    printf("Enter 2 to move Backward\n");
    printf("Enter 3 to turn Left\n");
    printf("Enter 4 to turn Right\n");
    printf("Enter 5 to stop the Robot\n\n");
    
    while(1) {
        printf("Enter your choice: ");
        scanf("%d", &input);
        
        // Control Statements to move the robot based on input
        switch(input) {
            case 1:
                moveForward();
                break;
            case 2:
                moveBackward();
                break;
            case 3:
                turnLeft();
                break;
            case 4:
                turnRight();
                break;
            case 5:
                printf("\nStopping the Robot...\n\n");
                return 0;
            default:
                printf("\nInvalid Input! Try Again...\n\n");
        }
    }
    return 0;
}