//FormAI DATASET v1.0 Category: Robot movement control ; Style: inquisitive
#include <stdio.h>

// Function to move the robot forward
void move_forward(int distance) {
    printf("Moving robot forward %d meters..\n", distance);
    // Code to control robot movement goes here
}

// Function to move the robot backward
void move_backward(int distance) {
    printf("Moving robot backward %d meters..\n", distance);
    // Code to control robot movement goes here
}

// Function to turn the robot left
void turn_left(int degrees) {
    printf("Turning robot left %d degrees..\n", degrees);
    // Code to control robot movement goes here
}

// Function to turn the robot right
void turn_right(int degrees) {
    printf("Turning robot right %d degrees..\n", degrees);
    // Code to control robot movement goes here
}

int main() {
    int choice;
    int distance;
    int degrees;
    
    printf("Welcome to Robot Movement Control Program!\n");
    
    while(1) {
        // Display menu
        printf("\nPlease select an option:\n");
        printf("1. Move forward\n");
        printf("2. Move backward\n");
        printf("3. Turn left\n");
        printf("4. Turn right\n");
        printf("5. Exit program\n");
        
        // Read user choice
        scanf("%d", &choice);
        
        // Process user choice
        switch(choice) {
            case 1:
                printf("Enter distance to move forward (in meters): ");
                scanf("%d", &distance);
                move_forward(distance);
                break;
            case 2:
                printf("Enter distance to move backward (in meters): ");
                scanf("%d", &distance);
                move_backward(distance);
                break;
            case 3:
                printf("Enter degrees to turn left: ");
                scanf("%d", &degrees);
                turn_left(degrees);
                break;
            case 4:
                printf("Enter degrees to turn right: ");
                scanf("%d", &degrees);
                turn_right(degrees);
                break;
            case 5:
                printf("Exiting program..\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}