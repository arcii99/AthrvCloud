//FormAI DATASET v1.0 Category: Robot movement control ; Style: high level of detail
#include <stdio.h>

// function to move the robot forward
void moveForward(int distance) {
    printf("Moving the robot forward by %d units.\n", distance);
}

// function to move the robot backward
void moveBackward(int distance) {
    printf("Moving the robot backward by %d units.\n", distance);
}

// function to turn the robot left
void turnLeft(int angle) {
    printf("Turning the robot left by %d degrees.\n", angle);
}

// function to turn the robot right
void turnRight(int angle) {
    printf("Turning the robot right by %d degrees.\n", angle);
}

int main() {
    int choice;
    int distance, angle;
    
    printf("Welcome to the Robot Movement Control Program!\n");
    
    do {
        // display menu of options
        printf("\n\nPlease select an option:\n");
        printf("1. Move the robot forward\n");
        printf("2. Move the robot backward\n");
        printf("3. Turn the robot left\n");
        printf("4. Turn the robot right\n");
        printf("5. Exit the program\n\n");
        
        // get user input for choice
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                // get user input for distance to move forward
                printf("\nEnter the distance to move the robot forward: ");
                scanf("%d", &distance);
                
                // call moveForward function with user input as parameter
                moveForward(distance);
                break;
            case 2:
                // get user input for distance to move backward
                printf("\nEnter the distance to move the robot backward: ");
                scanf("%d", &distance);
                
                // call moveBackward function with user input as parameter
                moveBackward(distance);
                break;
            case 3:
                // get user input for angle to turn left
                printf("\nEnter the angle to turn the robot left: ");
                scanf("%d", &angle);
                
                // call turnLeft function with user input as parameter
                turnLeft(angle);
                break;
            case 4:
                // get user input for angle to turn right
                printf("\nEnter the angle to turn the robot right: ");
                scanf("%d", &angle);
                
                // call turnRight function with user input as parameter
                turnRight(angle);
                break;
            case 5:
                // exit the program
                printf("\nThank you for using the Robot Movement Control Program! Goodbye!\n");
                break;
            default:
                // invalid choice input
                printf("\nInvalid choice! Please enter a valid choice (1-5).\n");
                break;
        }
        
    } while (choice != 5);
    
    return 0;
}