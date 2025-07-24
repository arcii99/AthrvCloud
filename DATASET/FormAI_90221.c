//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_ARGS 10
#define MAX_CMD_LEN 100

int main() {
    char cmd[MAX_CMD_LEN+1]; // Command buffer
    char *args[MAX_CMD_ARGS+1]; // Command arguments buffer
    char *token; // Token for strtok()
    pid_t pid; // Process ID
    int status; // Status for waitpid()

    while(1) {
        // Print the prompt
        printf("$ ");

        // Get the command from user input
        fgets(cmd, MAX_CMD_LEN, stdin);

        // Remove the newline character from cmd string
        cmd[strcspn(cmd, "\n")] = '\0';

        // Tokenize the command with space delimiter
        token = strtok(cmd, " ");

        // Initialize args buffer
        for(int i=0; i<MAX_CMD_ARGS+1; i++) {
            args[i] = NULL;
        }

        // Fill in the args buffer with command tokens
        int arg_idx = 0;
        while(token != NULL) {
            args[arg_idx++] = token;
            token = strtok(NULL, " ");

            if (arg_idx >= MAX_CMD_ARGS) {
                printf("Error: too many arguments\n");
                break;
            }
        }

        // Check if user entered a command
        if (args[0] != NULL) {

            // Create a new process for the command
            pid = fork();

            if (pid == -1) {
                printf("Error: failed to fork process\n");
            }
            else if (pid == 0) {
                // Child process: execute the command

                // Replace current process image with new command image
                execvp(args[0], args);

                // Exit child process if execvp() failed
                printf("Error: failed to execute command\n");
                exit(1);
            }
            else {
                // Parent process: wait for the child process to finish
                waitpid(pid, &status, 0);
            }
        }
    }

    return 0;
}