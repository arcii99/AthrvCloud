//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_COMMAND_LENGTH 50

// Function to validate the input command from the user
bool validateCommand(char *command) {
    if (strlen(command) > MAX_COMMAND_LENGTH) {
        return false;
    }

    return true;
}

// Function to execute the input command
void executeCommand(char *command) {
    // Your code to execute the command goes here
    printf("Executing command: %s\n", command);
}

int main() {
    char command[MAX_COMMAND_LENGTH];

    printf("Welcome to the C Drone Remote Control Program!\n");

    while (true) {
        printf("Enter your command: ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // Remove the newline character from the input command
        command[strcspn(command, "\n")] = 0;

        // Validate the input command
        if (!validateCommand(command)) {
            printf("Invalid command length! Maximum command length is %d.\n", MAX_COMMAND_LENGTH);
            continue;
        }

        // Execute the input command
        executeCommand(command);
    }

    return 0;
}