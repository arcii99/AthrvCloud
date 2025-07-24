//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

int main() {
    char command[MAX_COMMAND_LENGTH];
    char arguments[MAX_ARGUMENTS][MAX_COMMAND_LENGTH];
    int argument_count = 0;

    while (1) {
        // Print shell prompt
        printf("MyShell $ ");
        
        // Read input command
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // Remove newline character at the end of command
        command[strcspn(command, "\n")] = 0;

        // Parse command and arguments
        char *token = strtok(command, " ");
        argument_count = 0;

        while (token != NULL) {
            strcpy(arguments[argument_count], token);
            argument_count++;
            token = strtok(NULL, " ");
        }

        // Check for built-in commands
        if (strcmp(arguments[0], "exit") == 0) {
            printf("Goodbye!\n");
            exit(0);
        }

        // Fork process to execute external commands
        pid_t pid = fork();

        if (pid == 0) { // Child process
            // Execute command
            execvp(arguments[0], arguments);

            // If execvp returns, command failed
            perror("execvp");
            exit(1);
        } else if (pid > 0) { // Parent process
            // Wait for child process to finish
            int status;
            waitpid(pid, &status, 0);

            if (WIFEXITED(status)) {
                printf("Exit status: %d\n", WEXITSTATUS(status));
            }
        } else { // Fork failed
            perror("fork");
            exit(1);
        }
    }
}