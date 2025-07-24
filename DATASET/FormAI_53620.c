//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT 1024
#define MAX_ARGS 64
#define MAX_ARG_LEN 16

int main() {
    // Print prompt
    printf("Unix-like Shell\n");

    // User input loop
    while (1) {
        char input[MAX_INPUT];
        char *args[MAX_ARGS];
        char *arg;
        int argn = 0;

        // Get user input
        printf("> ");
        fgets(input, MAX_INPUT, stdin);

        // Parse input into arguments
        arg = strtok(input, " \n");
        while (arg != NULL && argn < MAX_ARGS) {
            args[argn++] = arg;
            arg = strtok(NULL, " \n");
        }
        args[argn] = NULL;

        // Check for exit or empty input
        if (args[0] == NULL) {
            continue;
        }
        if (strcmp(args[0], "exit") == 0) {
            exit(0);
        }

        // Fork and execute command
        int pid = fork();
        if (pid == 0) {
            // Child process
            execvp(args[0], args);
            // If execvp returns, there was an error
            printf("Error executing command: %s\n", args[0]);
            exit(1);
        } else if (pid < 0) {
            // Fork error
            printf("Error forking process.\n");
            exit(1);
        } else {
            // Parent process
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}