//FormAI DATASET v1.0 Category: Robot movement control ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* Define the possible robot movements */
#define FORWARD "Forward"
#define BACKWARD "Backward"
#define LEFT "Left"
#define RIGHT "Right"

/* Define the maximum size of the movement buffer */
#define MAX_BUFFER_SIZE 100

/* Declare the functions */
void moveForward();
void moveBackward();
void moveLeft();
void moveRight();

/* The main function*/
int main() {
    char movementBuffer[MAX_BUFFER_SIZE];

    /* Loop forever */
    while (true) {
        printf("Enter your robot movement command: ");
        fgets(movementBuffer, MAX_BUFFER_SIZE, stdin);

        /* Check the commands and perform the appropriate actions */
        if (strcmp(movementBuffer, FORWARD) == 0) {
            moveForward();
        }
        else if (strcmp(movementBuffer, BACKWARD) == 0) {
            moveBackward();
        }
        else if (strcmp(movementBuffer, LEFT) == 0) {
            moveLeft();
        }
        else if (strcmp(movementBuffer, RIGHT) == 0) {
            moveRight();
        }
        else {
            printf("Invalid movement command. Please try again.\n");
        }
    }
    return 0;
}

/* Define the movement functions */
void moveForward() {
    printf("Moving Forward.\n");
}

void moveBackward() {
    printf("Moving Backward.\n");
}

void moveLeft() {
    printf("Moving Left.\n");
}

void moveRight() {
    printf("Moving Right.\n");
}