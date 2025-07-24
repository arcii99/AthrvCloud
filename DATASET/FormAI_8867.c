//FormAI DATASET v1.0 Category: Robot movement control ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to Robot Movement Control System!\n");
    printf("Please enter the movement commands for your robot.\n");
    printf("Valid commands: FORWARD [distance], TURN [direction] [angle], STOP\n");

    int distance = 0;
    char direction[10];
    int angle = 0;
    char input[100];

    while(1) {
        printf("Enter command:");
        fgets(input, 100, stdin);

        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        // Parse input into separate components
        char* token;
        token = strtok(input, " ");
        if (strcmp(token, "FORWARD") == 0) {
             distance = atoi(strtok(NULL, " "));
             printf("Moving robot FORWARD %d units.\n", distance);
             // TODO: Add code to move robot forward
        }
        else if (strcmp(token, "TURN") == 0) {
             strcpy(direction, strtok(NULL, " "));
             angle = atoi(strtok(NULL, " "));
             printf("Turning robot %s %d degrees.\n", direction, angle);
             // TODO: Add code to turn robot
        }
        else if (strcmp(token, "STOP") == 0) {
             printf("Stopping robot.\n");
             // TODO: Add code to stop robot
             break;
        }
        else {
             printf("Invalid command. Valid commands: FORWARD [distance], TURN [direction] [angle], STOP\n");
        }
    }

    printf("Program terminated.\n");

    return 0;
}