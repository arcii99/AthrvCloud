//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10

int main() {
    char command[MAX_COMMAND_LENGTH];
    char *arguments[MAX_ARGUMENTS];

    while (1) {
        printf(">> ");

        if (!fgets(command, MAX_COMMAND_LENGTH, stdin)) {
            printf("Error: Could not read input\n");
            continue;
        }

        // Remove newline character
        command[strcspn(command, "\n")] = '\0';

        // Split command into arguments
        char *token = strtok(command, " ");
        int count = 0;

        while (token && count < MAX_ARGUMENTS - 1) {
            arguments[count] = token;
            token = strtok(NULL, " ");
            count++;
        }

        arguments[count] = NULL;

        if (count == 0) {
            continue;
        }

        // Run command
        pid_t pid = fork();

        if (pid < 0) {
            printf("Error: Failed to fork\n");
            continue;
        }

        if (pid == 0) {
            // Child process
            execvp(arguments[0], arguments);
            printf("Error: Failed to execute command\n");
            exit(1);
        }

        // Parent process
        int status;
        waitpid(pid, &status, 0);
    }

    return 0;
}