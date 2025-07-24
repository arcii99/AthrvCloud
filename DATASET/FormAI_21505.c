//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_LEN 128

void print_prompt() {
    printf("$ ");
}

int split_string(char* input, char** args, int max_args) {
    int argc = 0;
    args[argc] = strtok(input, " \t\n");

    while (args[argc] != NULL && argc < max_args) {
        argc++;
        args[argc] = strtok(NULL, " \t\n");
    }

    return argc;
}

int main() {
    char input[MAX_LEN];
    char* args[MAX_ARGS];

    while (1) {
        print_prompt();

        // Read input
        if (fgets(input, MAX_LEN, stdin) == NULL) {
            continue;
        }

        // Remove newline character
        input[strcspn(input, "\n")] = '\0';

        // Split input into arguments
        int argc = split_string(input, args, MAX_ARGS);

        // Exit shell if "quit" or "exit" is entered
        if (strcmp(args[0], "quit") == 0 || strcmp(args[0], "exit") == 0) {
            break;
        }

        // Create child process
        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
            continue;
        }

        if (pid == 0) {
            // Child process
            if (execvp(args[0], args) == -1) {
                perror("execvp");
                exit(EXIT_FAILURE);
            }
        } else {
            // Parent process
            int status;
            if (waitpid(pid, &status, 0) == -1) {
                perror("waitpid");
                continue;
            }
        }
    }

    return 0;
}