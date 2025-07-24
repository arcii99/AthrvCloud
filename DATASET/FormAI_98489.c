//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARG_LENGTH 50
#define MAX_ARGS 10

void tokenize(char *input, char **args); // Tokenize input string into argument list
int is_background(char **args); // Determine if the process should run in the background
void execute_command(char **args, int background); // Execute given command with given arguments list

int main()
{
    char input[MAX_ARG_LENGTH * MAX_ARGS]; // Buffer to hold user input
    char *args[MAX_ARGS]; // List of arguments
    int exit_status = 0; // Exit status of shell
  
    while(exit_status == 0) { // Run the shell until exit command is inputted
        putchar('$'); // Prompt character
        fgets(input, sizeof(input), stdin); // Get user input
        input[strcspn(input, "\n")] = '\0'; // Remove trailing newline character
        tokenize(input, args); // Tokenize input string into argument list
        int background = is_background(args); // Determine if the process should run in the background
        execute_command(args, background); // Execute given command with given arguments list
        int status;
        while(waitpid(-1, &status, WNOHANG) > 0); // Wait for any background processes to finish
        fflush(stdout); // Flush output buffer
    }
    return 0;
}

void tokenize(char *input, char **args)
{
    int arg_index = 0;
    char *arg = strtok(input, " "); // Tokenize string by whitespace

    while(arg != NULL && arg_index < MAX_ARGS - 1) { // Add tokens to args list
        args[arg_index++] = arg;
        arg = strtok(NULL, " ");
    }
    args[arg_index] = NULL; // Set last argument to NULL to indicate end of args list
}

int is_background(char **args)
{
    int background = 0;
    int arg_index = 0;

    while(args[arg_index] != NULL) { // Check last argument for &
        arg_index++;
    }
    arg_index--;
    if(arg_index >= 0 && strcmp(args[arg_index], "&") == 0) { // If & found, remove it from arg list and run process in background
        free(args[arg_index]);
        args[arg_index] = NULL;
        background = 1;
    }
    return background;
}

void execute_command(char **args, int background)
{
    pid_t pid = fork();
    if(pid == 0) { // Child process
        execvp(args[0], args);
        printf("Error running command.\n"); // Error occurred if reached
        exit(1);
    }
    else if (pid > 0) { // Parent process
        if(!background) {
            wait(&pid); // Wait for child process to finish
        }
    }
    else { // Fork failure
        printf("Failed to create child process.");
    }
}