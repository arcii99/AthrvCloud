//FormAI DATASET v1.0 Category: Robot movement control ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

// Function to move the robot forward by n units
void move_forward(int n) {
    printf("Moving forward by %d units.\n", n);
    // Code to move the robot forward by n units
}

// Function to move the robot backward by n units
void move_backward(int n) {
    printf("Moving backward by %d units.\n", n);
    // Code to move the robot backward by n units
}

// Function to turn the robot left by n degrees
void turn_left(int n) {
    printf("Turning left by %d degrees.\n", n);
    // Code to turn the robot left by n degrees
}

// Function to turn the robot right by n degrees
void turn_right(int n) {
    printf("Turning right by %d degrees.\n", n);
    // Code to turn the robot right by n degrees
}

int main() {
    int choice, n, angle;
    do {
        // Display menu to the user
        printf("\n**********************\n");
        printf("1. Move forward\n");
        printf("2. Move backward\n");
        printf("3. Turn left\n");
        printf("4. Turn right\n");
        printf("5. Exit\n");
        printf("**********************\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Switch statement to execute the selected operation
        switch(choice) {
            case 1:
                printf("Enter distance to move forward: ");
                scanf("%d", &n);
                move_forward(n);
                break;
            case 2:
                printf("Enter distance to move backward: ");
                scanf("%d", &n);
                move_backward(n);
                break;
            case 3:
                printf("Enter angle to turn left: ");
                scanf("%d", &angle);
                turn_left(angle);
                break;
            case 4:
                printf("Enter angle to turn right: ");
                scanf("%d", &angle);
                turn_right(angle);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice != 5);

    return 0;
}