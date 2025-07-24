//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

int main()
{
    char command[MAX_COMMAND_LENGTH];
    char *arguments[MAX_ARGUMENTS];
    int background = 0;
    
    printf("Welcome to the Puzzling Shell!\n");
    printf("Enter your command: ");
    fgets(command, MAX_COMMAND_LENGTH, stdin);

    while (strlen(command) > 1)
    {
        // Remove newline character from command
        command[strcspn(command, "\n")] = '\0';

        // Tokenize the command into its individual arguments
        char *token = strtok(command, " ");
        int argument_count = 0;
        while (token != NULL && argument_count < MAX_ARGUMENTS - 1)
        {
            arguments[argument_count++] = token;
            token = strtok(NULL, " ");
        }
        arguments[argument_count] = NULL;
        
        // Check if the command should be run in the background
        if (argument_count > 0 && strcmp(arguments[argument_count - 1], "&") == 0)
        {
            background = 1;
            arguments[argument_count - 1] = NULL;
        }
        
        // Fork a new process to execute the command
        pid_t pid = fork();
        if (pid == -1)
        {
            printf("Error: Unable to fork process.");
            exit(1);
        }
        else if (pid == 0)
        {
            // Child process
            execvp(arguments[0], arguments);
            printf("Error: Unable to execute command.\n");
            exit(1);
        }

        // Wait for the child process to complete unless it's in the background
        if (!background)
        {
            int status;
            waitpid(pid, &status, 0);
        }

        // Reset variables for next command
        background = 0;
        argument_count = 0;

        // Get the next command from the user
        printf("\nEnter your command: ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
    }
    
    return 0;
}