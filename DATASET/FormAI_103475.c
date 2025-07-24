//FormAI DATASET v1.0 Category: System administration ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[]) {
    pid_t pid;
    char *commands[100]; // create array to store commands

    if (argc < 2) { // check if user has provided some input
        printf("Please provide some command to execute\n");
        exit(0);
    }

    // parse user input and store command strings in commands array
    int i;
    for (i = 1; i < argc; i++) {
        commands[i-1] = argv[i];
    }
    commands[i-1] = NULL; // mark the end of commands array with NULL

    if ((pid = fork()) < 0) { // error checking
        printf("Error in forking child process\n");
        exit(0);
    } else if (pid == 0) { // child process
        if (execvp(commands[0], commands) < 0) { // execute the command
            printf("Error: Command execution failed\n");
            exit(0);
        }
    } else {
        wait(NULL); // wait for child process to finish
    }

    return 0; // end program
}