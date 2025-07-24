//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    char input[100];   // buffer to hold user input
    char *args[20];    // array of arguments to be passed to execvp()
    int pid, status;

    while(1) {
        printf("genius-shell> ");
        fgets(input, sizeof(input), stdin);  // read user input
        input[strlen(input) - 1] = '\0';     // remove newline character from input
        
        // tokenize input and store arguments in args array
        char *token;
        int i = 0;
        token = strtok(input, " ");
        while(token != NULL) {
            args[i] = token;
            i++;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;   // set last element of args to NULL (required by execvp())

        if(strcmp(args[0], "exit") == 0) {   // exit shell if user inputs 'exit'
            exit(0);
        }

        pid = fork();   // create new process

        if(pid < 0) {   // check for error in fork()
            printf("Error creating child process\n");
        }
        else if(pid == 0) {  // child process
            if(execvp(args[0], args) == -1) {   // execute command specified by user
                printf("Error executing command\n");
            }
            exit(0);   // exit child process
        }
        else {   // parent process
            wait(&status);   // wait for child process to finish executing
        }
    }
    return 0;
}