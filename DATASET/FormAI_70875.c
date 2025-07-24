//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_BUF_SIZE 512
#define MAX_ARGS 16

int main() {
    char input[MAX_BUF_SIZE + 1];    // Buffer to hold command input
    char *args[MAX_ARGS];            // Array to hold parsed arguments
    int status;

    while (1) {
        printf("> ");
        fflush(stdout);

        // Read input from command line
        if (fgets(input, MAX_BUF_SIZE, stdin) == NULL) {
            printf("\n");
            exit(0);
        }

        // Parse command line arguments
        char *token = strtok(input, " \t\n");
        int i = 0;
        while (token != NULL && i < MAX_ARGS - 1) {
            args[i++] = token;
            token = strtok(NULL, " \t\n");
        }
        args[i] = NULL;

        // Run command
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            // Child process
            execvp(args[0], args);
            perror(args[0]);
            exit(1);
        } else {
            // Parent process
            wait(&status);
        }
    }

    return 0;
}