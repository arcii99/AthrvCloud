//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_ARG_LENGTH 64
#define MAX_NUM_ARGS 64

int main() {
    char input[MAX_INPUT_LENGTH]; // buffer to store user input
    char* args[MAX_NUM_ARGS]; // array to store parsed arguments

    // main shell loop
    while (1) {
        // print prompt
        printf("$ ");

        // read user input
        fgets(input, MAX_INPUT_LENGTH, stdin);

        // remove newline character from input
        int input_len = strlen(input);
        if (input_len > 0 && input[input_len-1] == '\n') {
            input[input_len-1] = '\0';
        }

        // check for exit command
        if (strcmp(input, "exit") == 0) {
            return 0;
        }

        // tokenize input into arguments
        char* token = strtok(input, " ");
        int num_args = 0;
        while (token != NULL && num_args < MAX_NUM_ARGS) {
            args[num_args] = token;
            num_args++;
            token = strtok(NULL, " ");
        }
        args[num_args] = NULL; // set last argument to NULL for execvp

        // fork and execute command
        pid_t pid = fork();
        if (pid == 0) { // child process
            execvp(args[0], args);
            printf("Command not found\n"); // this line is only reached if execvp fails
            exit(1);
        } else if (pid > 0) { // parent process
            wait(NULL); // wait for child process to complete
        } else { // fork failed
            printf("Could not fork process\n");
            exit(1);
        }
    }

    return 0;
}