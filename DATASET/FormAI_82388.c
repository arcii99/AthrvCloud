//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: surprised
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_ARGUMENTS 64

void executeCommand(char *args[]) {
    pid_t pid = fork();
    if (pid < 0) {
        printf("Error: Unable to create a child process.\n");
    } else if (pid == 0) {
        // Child process
        if (execvp(args[0], args) < 0) {
            printf("Error: Unable to execute command %s\n", args[0]);
            exit(1);
        }
    } else {
        // Parent process
        wait(NULL); // Wait for child process to finish
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char *arguments[MAX_ARGUMENTS];

    printf("Hello there! I'm a basic Unix-like shell. Type 'quit' to exit.\n");

    while (1) {
        // Get input
        printf("> ");
        fgets(input, MAX_INPUT_LENGTH, stdin); // Read input from user

        // Remove newline character
        input[strcspn(input, "\n")] = 0;

        // Check if user wants to quit
        if (strcmp(input, "quit") == 0) {
            printf("Goodbye! Thanks for using the shell.\n");
            break;
        }

        // Tokenize input into arguments
        char *token = strtok(input, " ");
        int i = 0;
        while (token != NULL) {
            arguments[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        arguments[i] = NULL;

        // Execute command
        executeCommand(arguments);
    }
    return 0;
}