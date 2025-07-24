//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 50

int main() {
    char input[MAX_COMMANDS * MAX_COMMAND_LENGTH];
    char *args[MAX_COMMANDS + 1];
    int i, j, k, num_commands, status;

    while (1) {
        // Print prompt
        printf("> ");

        // Read input
        fgets(input, sizeof(input), stdin);

        // Remove newline character
        input[strcspn(input, "\n")] = '\0';

        // Parse input into commands
        num_commands = 0;
        args[num_commands] = strtok(input, " ");
        while (args[num_commands] != NULL) {
            num_commands++;
            args[num_commands] = strtok(NULL, " ");
        }

        // Execute commands
        for (i = 0; i < num_commands; i += MAX_COMMANDS) {
            // Create child processes for each set of commands
            pid_t pid = fork();
            if (pid == 0) {
                // Set up arguments for execvp
                int num_args = (num_commands - i > MAX_COMMANDS) ? MAX_COMMANDS : num_commands - i;
                char *child_args[num_args + 1];
                for (j = 0, k = i; j < num_args; j++, k++) {
                    child_args[j] = args[k];
                }
                child_args[num_args] = NULL;

                // Execute command
                execvp(child_args[0], child_args);

                // Exit child process on error
                perror(child_args[0]);
                exit(1);
            } else if (pid < 0) {
                // Error creating child process
                perror("fork");
            }
        }

        // Wait for child processes to finish
        for (i = 0; i < num_commands; i += MAX_COMMANDS) {
            int num_children = (num_commands - i > MAX_COMMANDS) ? MAX_COMMANDS : num_commands - i;
            for (j = 0; j < num_children; j++) {
                wait(&status);
            }
        }
    }

    return 0;
}