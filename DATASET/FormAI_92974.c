//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: synchronous
#include <stdio.h>

// Function to move the car in the forward direction
void moveForward() {
    printf("Moving forward...\n");
}

// Function to move the car in the backward direction
void moveBackward() {
    printf("Moving backward...\n");
}

// Function to turn the car to the left
void turnLeft() {
    printf("Turning left...\n");
}

// Function to turn the car to the right
void turnRight() {
    printf("Turning right...\n");
}

// Main function to simulate the remote control car
int main() {
    // Welcome message
    printf("Welcome to the remote control car simulation!\n\n");

    int option = 0;

    // Menu loop
    while (option != 5) {
        // Display menu options
        printf("1. Move forward\n");
        printf("2. Move backward\n");
        printf("3. Turn left\n");
        printf("4. Turn right\n");
        printf("5. Quit\n\n");

        // Get user input
        printf("Enter your choice: ");
        scanf("%d", &option);

        // Execute user's choice
        switch (option) {
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
                printf("Quitting the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    // Exit the program
    return 0;
}