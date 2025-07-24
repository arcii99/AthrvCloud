//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

#define MAX_LENGTH 1024 // Maximum number of characters allowed for input
#define MAX_ARGUMENTS 10 // Maximum number of arguments allowed
#define PROMPT "MyShell> " // Define the prompt for the shell

// This function reads the input provided by the user
int read_input(char **arguments)
{
    char *line = NULL; // Pointer for the input
    size_t bufsize = 0; // Size of the input buffer
    getline(&line, &bufsize, stdin); // Read the input
    
    int i = 0;
    char *token; // Pointer for the token obtained from input

    token = strtok(line, " "); // First token
    while(token != NULL && i < MAX_ARGUMENTS) // If token is empty or maximum arguments already obtained
    {
        arguments[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    arguments[i] = NULL; // End of arguments
    return i; // Return the number of arguments obtained
}

// This function executes the command using execvp system call
void execute_command(char **arguments)
{
    pid_t pid; // Process ID
    int status;
    pid = fork(); // Create a child process

    if(pid < 0) // If fork unsuccessful
    {
        printf("Execution failed. Please try again.\n");
        exit(EXIT_FAILURE);
    }
    else if(pid == 0) // Child process
    {
        if(execvp(arguments[0], arguments) < 0) // Execute the command
        {
            printf("Execution failed. Please try again.\n");
            exit(EXIT_FAILURE);
        }
    }
    else // Parent process
    {
        waitpid(pid, &status, WUNTRACED); // Wait for child process to finish
    }
}

int main()
{
    char *input[MAX_ARGUMENTS]; // Array of command line arguments

    while(1) // Loop while the shell is running
    {
        printf("%s", PROMPT); // Display the prompt
        fflush(stdout); // Clear the output buffer

        int argument_count = read_input(input); // Read input arguments

        if(argument_count == 0) // If no input provided
        {
            continue;
        }
        if(strcmp(input[0], "exit\n") == 0) // If user wants to exit shell
        {
            break;
        }

        execute_command(input); // Execute the command
    }

    return 0;
}