//FormAI DATASET v1.0 Category: Robot movement control ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define LEFT 0
#define RIGHT 1
#define FORWARD 2
#define BACKWARD 3

// function to move robot left
void moveLeft() {
    printf("Moving left...\n");
    // code to move robot left
}

// function to move robot right
void moveRight() {
    printf("Moving right...\n");
    // code to move robot right
}

// function to move robot forward
void moveForward() {
    printf("Moving forward...\n");
    // code to move robot forward
}

// function to move robot backward
void moveBackward() {
    printf("Moving backward...\n");
    // code to move robot backward
}

int main() {
    int movement;

    // loop until user wants to exit
    while(1) {
        printf("Which direction do you want to move the robot in? (0 for left, 1 for right, 2 for forward, 3 for backward): ");
        scanf("%d", &movement);

        // check user input and call appropriate function to move robot
        switch(movement) {
            case LEFT:
                moveLeft();
                break;
            case RIGHT:
                moveRight();
                break;
            case FORWARD:
                moveForward();
                break;
            case BACKWARD:
                moveBackward();
                break;
            default:
                printf("Invalid input, please try again\n");
                break;
        }
    }
    return 0;
}