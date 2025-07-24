//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_SIZE 1024

int main() {

    char command[MAX_COMMAND_SIZE];
    char *args[MAX_COMMAND_SIZE];

    while (1) {
        
        printf(">> ");
        fgets(command, MAX_COMMAND_SIZE, stdin);

        // Remove the trailing newline character
        command[strcspn(command, "\n")] = 0;

        // Tokenize the command string
        char *token = strtok(command, " ");
        int i = 0;

        // Parse the arguments
        while (token != NULL) {
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        args[i] = NULL;

        // Fork a child process
        pid_t pid = fork();

        if (pid < 0) {
            printf("Error: Unable to create child process!\n");
        }

        if (pid == 0) {
            // Child process

            // Execute the command
            if (execvp(args[0], args) == -1) {
                printf("%s : Command not found!\n", args[0]);
                exit(EXIT_FAILURE);
            }

        } else {
            // Parent process

            int status;
            waitpid(pid, &status, 0);
        }

    }


    return 0;
}