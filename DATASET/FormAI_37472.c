//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_ARGS 10 // maximum number of arguments that can be passed to a command
#define MAX_CMD_LENGTH 100 // maximum length of a command

int main(int argc, char *argv[]) {
    char cmd[MAX_CMD_LENGTH]; // buffer to hold the command
    char *cmd_args[MAX_ARGS]; // array to hold the command and its arguments
    pid_t pid; // process ID variable
    int status; // status variable for waitpid()

    while (1) { // loop infinitely until user enters "exit" command
        printf(">>> "); // prompt the user for a command
        fgets(cmd, MAX_CMD_LENGTH, stdin); // read in user input

        if (strcmp(cmd, "exit\n") == 0) { // check for exit command
            break; // exit the loop and terminate the program
        }

        char *token = strtok(cmd, " \n"); // break the command into tokens
        int i = 0; // initialize the counter for the cmd_args array

        while (token != NULL && i < MAX_ARGS) { // loop through the tokens
            cmd_args[i++] = token; // add the token to the cmd_args array
            token = strtok(NULL, " \n"); // move to the next token
        }

        cmd_args[i] = NULL; // add a NULL entry to the cmd_args array to terminate it

        pid = fork(); // create a child process

        if (pid < 0) { // check for fork() error
            perror("Error forking process"); // print error message
            exit(EXIT_FAILURE); // exit the child process with failure status
        } else if (pid == 0) { // child process
            execvp(cmd_args[0], cmd_args); // execute the command and its arguments
            perror("Error executing command"); // print error message if command execution fails
            exit(EXIT_FAILURE); // terminate the child process with failure status
        } else { // parent process
            do {
                waitpid(pid, &status, WUNTRACED); // wait for the child process to terminate
            } while (!WIFEXITED(status) && !WIFSIGNALED(status)); // exit the loop when child process terminates normally or with a signal
        }
    }

    return 0; // exit the program with success status
}