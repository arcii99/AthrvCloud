//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: beginner-friendly
#include <stdio.h>

// function to move the drone up
void droneUp() {
    printf("Drone moving up\n");
}

// function to move the drone down
void droneDown() {
    printf("Drone moving down\n");
}

// function to move the drone left
void droneLeft() {
    printf("Drone moving left\n");
}

// function to move the drone right
void droneRight() {
    printf("Drone moving right\n");
}

// function to land the drone
void droneLand() {
    printf("Drone landing\n");
}

int main() {
    char command;

    printf("Drone Remote Control\n");

    while(1) {
        printf("Enter command: ");
        scanf(" %c", &command);

        // execute the respective command based on user inputs
        switch(command) {
            case 'u':
                droneUp();
                break;
            case 'd':
                droneDown();
                break;
            case 'l':
                droneLeft();
                break;
            case 'r':
                droneRight();
                break;
            case 't':
                droneLand();
                break;
            default:
                printf("Invalid command\n");
                break;
        }
    }
    return 0;
}