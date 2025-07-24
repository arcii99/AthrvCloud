//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: accurate
//This is a Unix-like Shell program implemented in C language.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

#define MAX_ARGS 100 //maximum arguments to be accepted
#define MAX_LENGTH 500 //maximum length of the command to be accepted

void execute_command(char** commands, int num_args) {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        execvp(commands[0], commands);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Error forking
        perror("fork");
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
    }
}

int main() {
    char input[MAX_LENGTH];
    char *token;
    char *commands[MAX_ARGS];
    int num_args;

    while (1) {
        num_args = 0;
        printf("> ");
        fgets(input, MAX_LENGTH, stdin);
        token = strtok(input, " \n");
        while (token != NULL) {
            commands[num_args++] = token;
            token = strtok(NULL, " \n");
        }
        if (num_args > 0) {
            // Execute the command
            commands[num_args] = NULL;
            execute_command(commands, num_args);
        }
    }
    return 0;
}