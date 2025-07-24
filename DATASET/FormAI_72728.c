//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_RESPONSE_LENGTH 500

void execute_command(char* command, char* response) {
    // Your code to execute the command goes here
    strcpy(response, "Command executed successfully");
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    char response[MAX_RESPONSE_LENGTH];

    while (1) {
        printf("Enter command: ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        if (strcmp(command, "exit\n") == 0) {
            break;
        }

        execute_command(command, response);
        printf("Response: %s\n", response);
    }

    return 0;
}