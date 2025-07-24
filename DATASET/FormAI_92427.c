//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: scientific
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/wait.h> 

#define BUFFER_SIZE 1024 

int main(int argc, char *argv[]) { 
    char input[BUFFER_SIZE]; 
    char *args[100]; // command-line arguments 
    int should_run = 1; // flag to determine when to exit the program 

    while (should_run) { 
        printf("unix-like-shell> "); // prompt for user input 
        fgets(input, BUFFER_SIZE, stdin); 

        // parse input into separate arguments 
        int arg_count = 0; 
        char *token = strtok(input, " \n"); 
        while (token != NULL) { 
            args[arg_count] = token; 
            arg_count++; 
            token = strtok(NULL, " \n"); 
        } 
        args[arg_count] = NULL; // terminate argument array with NULL 

        if (strcmp(args[0], "exit") == 0) { // check for "exit" command 
            should_run = 0; 
        } else { 
            pid_t pid = fork(); 
            if (pid == 0) { // child process 
                execvp(args[0], args); // execute command 
                printf("unknown command: %s\n", args[0]); // handle execvp error 
                exit(EXIT_FAILURE); 
            } else if (pid < 0) { // error 
                printf("fork failed\n"); 
            } else { // parent process 
                wait(NULL); // wait for child process to complete 
            } 
        } 
    } 

    return 0; 
}