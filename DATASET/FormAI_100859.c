//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_ARGS 64

int main(int argc, char *argv[]) {
    char buffer[MAX_BUFFER_SIZE];
    char *args[MAX_ARGS];
    int status;

    while (1) {
        printf("myshell$ ");

        // Read input from user
        fgets(buffer, MAX_BUFFER_SIZE, stdin);

        // Remove newline at the end of input
        buffer[strcspn(buffer, "\n")] = 0;

        // Parse input into arguments array
        char *arg = strtok(buffer, " ");
        int i = 0;
        while (arg != NULL && i < MAX_ARGS - 1) {
            args[i++] = arg;
            arg = strtok(NULL, " ");
        }
        args[i] = NULL;

        // Check if user entered a command
        if (args[0] == NULL) {
            continue; // Empty input, prompt again
        }

        // Check if user wants to exit shell
        if (strcmp(args[0], "exit") == 0) {
            return 0;
        }

        // Execute command in child process
        pid_t pid = fork();
        if (pid == 0) {
            execvp(args[0], args);
            printf("%s: command not found\n", args[0]);
            exit(1);
        }

        // Wait for child process to finish
        waitpid(pid, &status, 0);
    }

    return 0;
}