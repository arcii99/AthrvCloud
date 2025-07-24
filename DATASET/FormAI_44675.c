//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

int main(void) {
    char command[MAX_COMMAND_LENGTH];
    char *arguments[MAX_ARGUMENTS];
    int i, status;

    while (1) {
        printf("> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        if (strlen(command) > 1) {
            command[strlen(command) - 1] = '\0'; // Remove the newline character

            // Parse the command and its arguments
            arguments[0] = strtok(command, " ");
            for (i = 1; i < MAX_ARGUMENTS; i++) {
                arguments[i] = strtok(NULL, " ");
                if (arguments[i] == NULL) break;
            }

            if (strcmp(arguments[0], "exit") == 0) {
                printf("Exiting shell...\n");
                break;
            }

            pid_t pid = fork();
            if (pid == 0) {
                // Child process
                execvp(arguments[0], arguments);
                printf("Error running the command: %s\n", command);
                exit(1);
            } else {
                // Parent process
                waitpid(pid, &status, 0);
            }
        }
    }

    return 0;
}