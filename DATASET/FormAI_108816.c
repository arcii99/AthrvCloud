//FormAI DATASET v1.0 Category: Robot movement control ; Style: realistic
#include <stdio.h>

// function to move robot forward with given distance
void move_forward(int distance) {
    printf("Robot moving forward %d meters...\n", distance);
    // code to control robot movement forward
}

// function to move robot backward with given distance
void move_backward(int distance) {
    printf("Robot moving backward %d meters...\n", distance);
    // code to control robot movement backward
}

// function to turn robot left with given degrees
void turn_left(int degrees) {
    printf("Robot turning left %d degrees...\n", degrees);
    // code to control robot turn left
}

// function to turn robot right with given degrees
void turn_right(int degrees) {
    printf("Robot turning right %d degrees...\n", degrees);
    // code to control robot turn right
}

int main() {
    int choice, distance, degrees;
    printf("Welcome to robot control program!\n");

    do {
        printf("\nPlease select an option:\n");
        printf("1. Move Forward\n");
        printf("2. Move Backward\n");
        printf("3. Turn Left\n");
        printf("4. Turn Right\n");
        printf("5. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
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
                printf("Exiting robot control program...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}