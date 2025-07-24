//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 50

int main() {
    char command[MAX_COMMAND_LENGTH];
    int x = 0, y = 0;

    printf("Welcome to C Drone Remote Control.\n");

    while(1) {
        printf("Enter command (press h for help): ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = 0; // Remove trailing newline

        if(strcmp(command, "h") == 0) {
            printf("Enter one of the following commands:\n");
            printf("f - Move forward\n");
            printf("b - Move backward\n");
            printf("l - Move left\n");
            printf("r - Move right\n");
            printf("u - Move up\n");
            printf("d - Move down\n");
            printf("x <amount> - Move along x-axis\n");
            printf("y <amount> - Move along y-axis\n");
            printf("q - Quit program\n");
        }else if(strcmp(command, "f") == 0) {
            printf("Moving drone forward...\n");
        }else if(strcmp(command, "b") == 0) {
            printf("Moving drone backward...\n");
        }else if(strcmp(command, "l") == 0) {
            printf("Moving drone left...\n");
        }else if(strcmp(command, "r") == 0) {
            printf("Moving drone right...\n");
        }else if(strcmp(command, "u") == 0) {
            printf("Moving drone up...\n");
        }else if(strcmp(command, "d") == 0) {
            printf("Moving drone down...\n");
        }else if(strncmp(command, "x ", 2) == 0) {
            int distance = atoi(command + 2);
            x += distance;
            printf("Moving drone along x-axis by %d units...\n", distance);
        }else if(strncmp(command, "y ", 2) == 0) {
            int distance = atoi(command + 2);
            y += distance;
            printf("Moving drone along y-axis by %d units...\n", distance);
        }else if(strcmp(command, "q") == 0) {
            printf("Exiting program...\n");
            break;
        }else {
            printf("Invalid command. Enter h for help.\n");
        }
    }

    return 0;
}