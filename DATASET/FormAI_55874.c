//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 10

int main(int argc, char **argv) {
    char command[MAX_COMMAND_LENGTH];
    char *args[MAX_ARGS];
    int status = 1;
    pid_t pid;
    int i;

    printf("Welcome to the minimalist Unix-like shell!\n");

    while (status) {
        printf("> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // Remove newline character from command
        command[strcspn(command, "\n")] = 0;

        // Parse command into separate arguments
        char *arg = strtok(command, " ");
        i = 0;
        while (arg != NULL && i < MAX_ARGS-1) {
            args[i] = arg;
            arg = strtok(NULL, " ");
            i++;
        }
        args[i] = NULL;

        // Fork process to execute command
        pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
            // Child process
            if (execvp(args[0], args) == -1) {
                perror("execvp");
                exit(EXIT_FAILURE);
            }
        } else {
            // Parent process
            if (wait(&status) == -1) {
                perror("wait");
                exit(EXIT_FAILURE);
            }
        }
    }

    return 0;
}