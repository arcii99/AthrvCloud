//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 50
#define MAX_BUFFER_LENGTH 100

int main() {
    char commands[MAX_COMMANDS][MAX_COMMAND_LENGTH];
    char buffer[MAX_BUFFER_LENGTH];

    while (1) {
        printf(">> ");
        fgets(buffer, MAX_BUFFER_LENGTH, stdin);

        // Strip newline character
        buffer[strcspn(buffer, "\n")] = 0;

        // Tokenize commands
        char *token = strtok(buffer, "|");

        // Fill commands array
        int i = 0;
        while (token != NULL) {
            if (i >= MAX_COMMANDS) {
                printf("Too many commands\n");
                break;
            }

            strcpy(commands[i++], token);
            token = strtok(NULL, "|");
        }

        if (i == 0) {
            // No commands were entered
            continue;
        }

        // Fork child process
        pid_t pid = fork();

        if (pid == 0) {
            // Child process
            int fd[2]; // File descriptors for pipe
            int prev_pipe[2] = {0}; // Keep track of previous pipe

            for (int j = 0; j < i; j++) {
                // Create pipe
                if (pipe(fd) == -1) {
                    perror("pipe");
                    exit(EXIT_FAILURE);
                }

                // Fork process
                pid_t child_pid = fork();

                if (child_pid == 0) {
                    // Child process

                    // Redirect input to previous pipe
                    if (prev_pipe[0] != 0) {
                        dup2(prev_pipe[0], STDIN_FILENO);
                        close(prev_pipe[0]);
                        close(prev_pipe[1]);
                    }

                    // Redirect output to pipe
                    if (j < i - 1) {
                        dup2(fd[1], STDOUT_FILENO);
                        close(fd[1]);
                        close(fd[0]);
                    }

                    // Execute command
                    char *args[MAX_COMMAND_LENGTH];
                    int k = 0;
                    char *token = strtok(commands[j], " ");

                    while (token != NULL) {
                        args[k++] = token;
                        token = strtok(NULL, " ");
                    }

                    args[k] = NULL;

                    execvp(args[0], args);

                    // execvp only returns if there is an error
                    perror("exec");
                    exit(EXIT_FAILURE);
                }

                // Close previous pipe
                if (prev_pipe[0] != 0) {
                    close(prev_pipe[0]);
                    close(prev_pipe[1]);
                }

                // Keep track of current pipe
                prev_pipe[0] = fd[0];
                prev_pipe[1] = fd[1];
            }

            // Close final pipe
            if (prev_pipe[0] != 0) {
                close(prev_pipe[0]);
                close(prev_pipe[1]);
            }

            // Wait for child processes to finish
            for (int j = 0; j < i; j++) {
                wait(NULL);
            }

            exit(EXIT_SUCCESS);
        } else if (pid < 0) {
            // Forking failed
            perror("fork");
        } else {
            // Parent process
            waitpid(pid, NULL, 0);
        }
    }

    return EXIT_SUCCESS;
}