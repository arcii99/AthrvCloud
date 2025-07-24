//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 80 // Maximum length command line
#define MAX_ARGS 10 // Maximum number of arguments

int main(void)
{
    char *args[MAX_ARGS]; // arguments
    char command[MAX_LINE]; // user input command
    int should_run = 1; // flag to determine when to exit program
    pid_t pid; // fork process id

    while (should_run)
    {
        printf("myshell> ");
        fflush(stdout);

        // Read user input
        fgets(command, MAX_LINE, stdin);

        // Parse input by spaces
        int i = 0;
        char *token = strtok(command, " ");
        while (token != NULL && i < MAX_ARGS - 1) // last argument must be a NULL pointer
        {
            args[i] = token;
            i++;
            token = strtok(NULL, " ");
        }
        args[i] = NULL; // set last argument as NULL pointer

        // If input is empty or only a newline, restart loop
        if (args[0] == NULL || strcmp(args[0], "\n") == 0)
        {
            continue;
        }

        // Exit shell command
        if (strcmp(args[0], "exit") == 0)
        {
            should_run = 0;
            continue;
        }

        // Fork and execute command
        pid = fork();
        if (pid == 0) // child process
        {
            if (execvp(args[0], args) == -1) // error occurred
            {
                printf("myshell: %s: command not found\n", args[0]); // print error message
                exit(EXIT_FAILURE); // exit child process
            }
        }
        else if (pid > 0) // parent process
        {
            int status;
            wait(&status); // wait for child process to complete
        }
        else // fork() error occurred
        {
            printf("myshell: fork error occurred\n"); // print error message
        }
    }
    
    return 0;
}