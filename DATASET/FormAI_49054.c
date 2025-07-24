//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

#define MAX_LENGTH 80 // Maximum length of command
#define MAX_ARGS 10 // Maximum number of arguments

int main()
{
    char command[MAX_LENGTH + 1]; // Array to store command
    char *arguments[MAX_ARGS + 1]; // Array to store arguments
    int status; // Status of child process
    pid_t pid; // Process ID of child process

    printf("Welcome to MyShell!\n\n");

    while(1) // Loop to keep shell running until exit command is entered
    {
        printf("MyShell> ");
        fgets(command, MAX_LENGTH + 1, stdin); // Get input from user

        // Check if exit command was entered
        if(strcmp(command, "exit\n") == 0)
        {
            printf("Exiting MyShell...\n");
            break;
        }

        // Parse input into separate arguments
        int i = 0;
        arguments[i] = strtok(command, " \n");
        while(arguments[i] != NULL)
        {
            i++;
            arguments[i] = strtok(NULL, " \n");
        }

        // Fork a child process
        pid = fork();
        if(pid < 0) // Error occurred
        {
            fprintf(stderr, "Fork failed!\n");
            exit(1);
        }
        else if(pid == 0) // Child process
        {
            // Execute command with arguments
            if(execvp(arguments[0], arguments) < 0)
            {
                fprintf(stderr, "Command not found!\n");
                exit(1);
            }
        }
        else // Parent process
        {
            // Wait for child process to finish execution
            wait(&status);
            printf("\n");
        }
    }

    return 0;
}