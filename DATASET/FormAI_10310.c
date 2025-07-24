//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LENGTH 1024
#define MAX_ARGS 128

// Splits the input by space and stores each token in an array (argv)
void parse_input(char input[], char *argv[]) {
    int i = 0;
    char *tok = strtok(input, " \n");

    while (tok != NULL) {
        argv[i++] = tok;
        tok = strtok(NULL, " \n");
    }

    argv[i] = NULL;  // Last element in argv must be NULL
}

int main() {
    char input[MAX_LENGTH];
    char *argv[MAX_ARGS];
    pid_t pid;
    int status;

    while (1) {
        printf("> ");
        fgets(input, MAX_LENGTH, stdin);  // Read input from user

        if (input[0] == '\n') {
            continue;  // If input is empty, just prompt again
        }

        parse_input(input, argv);  // Parse the input by spaces

        if (strcmp(argv[0], "exit") == 0) {
            break;  // If user types "exit", exit the shell
        }

        pid = fork();  // Create a child process to execute the command

        if (pid == -1) {
            printf("Error: Failed to fork process\n");
        }
        else if (pid == 0) {
            // Child process executes the command
            if (execvp(argv[0], argv) == -1) {
                printf("Error: Failed to execute command\n");
            }

            exit(EXIT_FAILURE);
        }
        else {
            // Parent process waits for child to finish
            do {
                waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
    }

    return 0;
}