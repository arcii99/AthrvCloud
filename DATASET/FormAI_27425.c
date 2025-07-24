//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64

int main() {
    char input[MAX_COMMAND_LENGTH]; // input buffer for shell command
    char* arguments[MAX_ARGUMENTS]; // array of pointers to strings for arguments
    char* token; // used for splitting input into tokens
    pid_t pid; // process ID for child process
    int status; // status of child process

    while (1) {
        printf(">> "); // print shell prompt
        fgets(input, MAX_COMMAND_LENGTH, stdin); // read input from user

        if (strcmp(input, "exit\n") == 0) // check if user types "exit"
            break;

        arguments[0] = strtok(input, " \n"); // get first token from input
        int i = 0;

        while (arguments[i] != NULL && i <= MAX_ARGUMENTS) { // loop through remaining tokens
            i++;
            arguments[i] = strtok(NULL, " \n"); // get next token
        }

        pid = fork(); // fork child process

        if (pid < 0) { // error in forking
            printf("ERROR: Failed to fork child process.\n");
            exit(1); // exit shell
        } else if (pid == 0) { // child process
            if (execvp(arguments[0], arguments) == -1) { // execute command
                printf("ERROR: Failed to execute command.\n");
                exit(1); // exit child process
            }
            exit(0); // exit child process
        }

        // wait for child process to finish
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 0; // exit shell
}