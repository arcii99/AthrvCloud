//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>

#define MAX_LENGTH 1000 // Maximum command length

int main() {
    while(1) {
        char input[MAX_LENGTH]; // stores user input
        char *args[MAX_LENGTH]; // stores arguments

        printf(">> ");
        fgets(input, MAX_LENGTH, stdin); // get input

        if(strcmp(input, "exit\n") == 0) { // check for "exit" command
            printf("Goodbye!\n");
            exit(0);
        }

        int arg_count = 0;
        char *token = strtok(input, " \n"); // tokenize input
        while(token != NULL) {
            args[arg_count] = token;
            token = strtok(NULL, " \n");
            arg_count++;
        }
        args[arg_count] = NULL; // set last argument to NULL
        
        pid_t pid = fork(); // create child process
        
        if(pid == -1) { // check for fork error
            printf("Error: Failed to fork.\n");
        } else if(pid == 0) { // child process
            execvp(args[0], args); // execute command
            printf("Error: Invalid command.\n");
            exit(0);
        } else { // parent process
            wait(NULL); // wait for child to finish
        }
    }

    return 0;
}