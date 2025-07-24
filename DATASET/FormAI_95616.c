//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64

int main() {
    char command[MAX_COMMAND_LENGTH];
    char *args[MAX_ARGUMENTS];
    int status;

    while (1) {
        printf("$ ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        if (strcmp(command, "exit\n") == 0) {
            break;
        }

        command[strcspn(command, "\n")] = 0; // remove trailing new line character

        int argIndex = 0;
        char *token = strtok(command, " ");
        while (token) {
            args[argIndex] = token;
            argIndex++;
            token = strtok(NULL, " ");
        }
        args[argIndex] = NULL;

        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
        } else if (pid == 0) {
            execvp(args[0], args);
            perror("execvp");
            exit(EXIT_FAILURE);
        } else {
            waitpid(pid, &status, 0);
        }
    }
    return 0;
}