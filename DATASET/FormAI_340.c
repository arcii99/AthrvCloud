//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 256

int main() {
    char input[BUFFER_SIZE];
    char *arguments[BUFFER_SIZE];
    int i, background, status;

    printf("Welcome to MyShell!\n");
    printf("Type 'exit' to quit.\n");

    while (1) {
        printf("MyShell> ");

        if (fgets(input, BUFFER_SIZE, stdin) == NULL)
            continue;

        if (strcmp(input, "exit\n") == 0)
            break;

        // tokenize input into arguments
        i = 0;
        arguments[i] = strtok(input, " \t\n");
        while (arguments[i] != NULL) {
            i++;
            arguments[i] = strtok(NULL, " \t\n");
        }

        if (i == 0)
            continue;

        // check if command should be run in background
        if (strcmp(arguments[i-1], "&") == 0) {
            background = 1;
            arguments[i-1] = NULL; // remove "&" from arguments
        }
        else
            background = 0;

        // fork child process
        pid_t child_pid = fork();

        if (child_pid < 0) {
            perror("fork error");
            exit(1);
        }
        else if (child_pid == 0) {
            // child process
            if (execvp(arguments[0], arguments) == -1) {
                perror("execvp error");
                exit(1);
            }
        }
        else {
            // parent process
            if (background == 0) {
                waitpid(child_pid, &status, 0);
            }
            else {
                printf("Process %d running in background.\n", child_pid);
            }
        }
    }

    printf("Goodbye!\n");
    return 0;
}