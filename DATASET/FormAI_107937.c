//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define COMMAND_LENGTH 1024
#define MAX_NUMBER_OF_ARGUMENTS 32

// Function to parse the user input to individual arguments
void parse_arguments(char *input, char **arguments) {
    char *token = strtok(input, " ");
    int i = 0;

    while (token != NULL) {
        arguments[i] = token;
        i++;
        token = strtok(NULL, " ");
    }

    arguments[i] = NULL;
}

// Function to execute the user command
void execute_command(char **arguments) {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        if (execvp(arguments[0], arguments) < 0) {
            printf("Error executing command.\n");
        }
        exit(1);
    } else if (pid < 0) {
        // Error forking
        printf("Error forking.\n");
    } else {
        // Parent process
        wait(NULL);
    }
}

// Main function to accept user input and execute commands
int main(void) {
    char input[COMMAND_LENGTH];
    char *arguments[MAX_NUMBER_OF_ARGUMENTS];

    while (1) {
        printf(">> ");
        fgets(input, COMMAND_LENGTH, stdin);

        // Remove trailing newline character
        input[strcspn(input, "\n")] = 0;

        // Parse arguments
        parse_arguments(input, arguments);

        // Exit condition
        if(strcmp(arguments[0], "exit") == 0 || strcmp(arguments[0], "quit") == 0) {
            printf("Exiting shell.\n");
            break;
        }

        // Execute command
        execute_command(arguments);
    }

    return 0;
}