//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Ken Thompson
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_INPUT_LENGTH 50

// function declarations
void takeOff();
void land();
void moveForward(int distance);
void moveBackward(int distance);
void moveLeft(int distance);
void moveRight(int distance);
void moveUp(int distance);
void moveDown(int distance);
void turnLeft(int angle);
void turnRight(int angle);
void displayHelp();

int main() {
    char input[MAX_INPUT_LENGTH];

    // display welcome message
    printf("Welcome to the Drone Remote Control!\n");
    displayHelp();

    // keep accepting commands until the user quits
    while (true) {
        // get user input
        printf("Enter command: ");
        fgets(input, MAX_INPUT_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        // execute the command
        if (strcmp(input, "takeoff") == 0) {
            takeOff();
        } else if (strcmp(input, "land") == 0) {
            land();
        } else if (strncmp(input, "forward", 7) == 0) {
            int distance = atoi(input + 8);
            moveForward(distance);
        } else if (strncmp(input, "backward", 8) == 0) {
            int distance = atoi(input + 9);
            moveBackward(distance);
        } else if (strncmp(input, "left", 4) == 0) {
            int distance = atoi(input + 5);
            moveLeft(distance);
        } else if (strncmp(input, "right", 5) == 0) {
            int distance = atoi(input + 6);
            moveRight(distance);
        } else if (strncmp(input, "up", 2) == 0) {
            int distance = atoi(input + 3);
            moveUp(distance);
        } else if (strncmp(input, "down", 4) == 0) {
            int distance = atoi(input + 5);
            moveDown(distance);
        } else if (strncmp(input, "turnleft", 8) == 0) {
            int angle = atoi(input + 9);
            turnLeft(angle);
        } else if (strncmp(input, "turnright", 9) == 0) {
            int angle = atoi(input + 10);
            turnRight(angle);
        } else if (strcmp(input, "help") == 0) {
            displayHelp();
        } else if (strcmp(input, "quit") == 0) {
            break;
        } else {
            printf("Invalid command. Type 'help' for a list of commands.\n");
        }
    }

    return 0;
}

void takeOff() {
    printf(">Taking off...\n");
}

void land() {
    printf(">Landing...\n");
}

void moveForward(int distance) {
    printf(">Moving forward %d meters...\n", distance);
}

void moveBackward(int distance) {
    printf(">Moving backward %d meters...\n", distance);
}

void moveLeft(int distance) {
    printf(">Moving left %d meters...\n", distance);
}

void moveRight(int distance) {
    printf(">Moving right %d meters...\n", distance);
}

void moveUp(int distance) {
    printf(">Moving up %d meters...\n", distance);
}

void moveDown(int distance) {
    printf(">Moving down %d meters...\n", distance);
}

void turnLeft(int angle) {
    printf(">Turning left %d degrees...\n", angle);
}

void turnRight(int angle) {
    printf(">Turning right %d degrees...\n", angle);
}

void displayHelp() {
    printf("Commands:\n");
    printf("  takeoff\n");
    printf("  land\n");
    printf("  forward <distance in meters>\n");
    printf("  backward <distance in meters>\n");
    printf("  left <distance in meters>\n");
    printf("  right <distance in meters>\n");
    printf("  up <distance in meters>\n");
    printf("  down <distance in meters>\n");
    printf("  turnleft <angle in degrees>\n");
    printf("  turnright <angle in degrees>\n");
    printf("  help\n");
    printf("  quit\n");
}