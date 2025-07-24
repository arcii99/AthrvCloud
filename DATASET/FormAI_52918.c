//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_LENGTH 80 // maximum length of user input
#define MAX_ARGS 10 // maximum number of arguments that can be parsed from user input

int main() {
    char user_input[MAX_LENGTH + 1]; // add 1 to account for null terminator
    char* args[MAX_ARGS + 1]; // add 1 to account for NULL at end of args array
    int should_run = 1; // whether or not the shell should continue running
    pid_t pid; // process ID for forking child processes
    int status; // exit status of child process

    printf("Welcome to my Unix-like shell!\n");

    while (should_run) {
        printf(">>> "); // the Unix shell prompt

        fgets(user_input, MAX_LENGTH, stdin); // read user input from stdin

        if (strcmp(user_input, "exit\n") == 0) {
            should_run = 0; // user entered "exit", so we should shut down the shell
            continue;
        }

        // parse user input into array of arguments, separated by spaces
        char* token = strtok(user_input, " \n");
        int arg_count = 0;
        while (token != NULL && arg_count < MAX_ARGS) {
            args[arg_count] = token;
            arg_count++;
            token = strtok(NULL, " \n");
        }
        args[arg_count] = NULL; // add NULL terminator to end of args array

        pid = fork(); // create child process to execute command

        if (pid < 0) {
            printf("Error: could not fork child process\n");
            continue;
        } else if (pid == 0) {
            // child process: execute command using execvp()
            if (execvp(args[0], args) < 0) {
                printf("Error: command not found\n");
                exit(1);
            }
        } else {
            // parent process: wait for child to finish executing
            waitpid(pid, &status, 0);
        }
    }

    printf("Thanks for using my Unix-like shell!\n");
    return 0;
}