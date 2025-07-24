//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 100
#define MAX_ARGS 10

int main() {
    char input[MAX_INPUT_LENGTH];
    char *args[MAX_ARGS];
    int continue_loop = 1;

    while (continue_loop) {
        // Print a prompt and read user input
        printf("> ");
        fgets(input, MAX_INPUT_LENGTH, stdin);

        // Split the input into an array of arguments
        char *token = strtok(input, " \n");
        int arg_idx = 0;
        while (token != NULL && arg_idx < MAX_ARGS) {
            args[arg_idx] = token;
            token = strtok(NULL, " \n");
            arg_idx++;
        }
        args[arg_idx] = NULL;

        // Check if the user wants to exit
        if (strcmp(args[0], "exit") == 0) {
            continue_loop = 0;
        } else {
            // Fork a process and execute the command in the child process
            pid_t pid = fork();
            if (pid == 0) {
                execvp(args[0], args);
                printf("Unknown command: %s\n", args[0]);
                exit(1);
            } else {
                wait(NULL);
            }
        }
    }

    return 0;
}