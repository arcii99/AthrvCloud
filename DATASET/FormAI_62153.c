//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_NUM_ARGUMENTS 64

int main()
{
    char input[MAX_INPUT_SIZE];

    while (1) {
        printf(">> ");

        if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
            break;
        }

        // Parse input string into arguments
        char *arguments[MAX_NUM_ARGUMENTS];
        int argc = 0;

        char *token = strtok(input, " \t\n");

        while (token != NULL && argc < MAX_NUM_ARGUMENTS) {
            arguments[argc] = token;
            argc++;
            token = strtok(NULL, " \t\n");
        }

        if (argc == 0) {
            continue;
        }

        if (strcmp(arguments[0], "exit") == 0) {
            // Exit the program
            break;
        }

        pid_t pid = fork();

        if (pid == 0) {
            // Child process
            if (execvp(arguments[0], arguments) == -1) {
                perror("execvp");
            }

            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            // Fork error
            perror("fork");
        } else {
            // Parent process
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}