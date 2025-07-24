//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define COMMAND_LENGTH 1024
#define ARGUMENTS_NUMBER 64

void run_shell();
void read_command(char* command);
void parse_command(char* command, char** arguments);
void execute_command(char** arguments, int pipe, int input, int output);
void handle_pipes(char** arguments, int input, int output);

int main() 
{
    run_shell();
    return 0;
}

void run_shell() 
{
    char command[COMMAND_LENGTH];
    char* arguments[ARGUMENTS_NUMBER];

    while (1) 
    {
        printf("> ");
        fflush(stdout);

        read_command(command);
        if (strcmp(command, "exit") == 0) 
        {
            break;
        }

        parse_command(command, arguments);
        execute_command(arguments, 0, 0, 1);
    }
}

void read_command(char* command) 
{
    fgets(command, COMMAND_LENGTH, stdin);
    command[strcspn(command, "\n")] = '\0'; // Removes the \n at the end of the input
}

void parse_command(char* command, char** arguments) 
{
    char* token;
    int i = 0;

    token = strtok(command, " ");
    while (token != NULL) 
    {
        arguments[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    arguments[i] = NULL; // Marks the end of the arguments array with a NULL pointer
}

void execute_command(char** arguments, int pipe, int input, int output) 
{
    pid_t pid;

    if (arguments[0] == NULL) 
    {
        return; // No arguments
    }
    if (strcmp(arguments[0], "cd") == 0) 
    {
        chdir(arguments[1]);
        return;
    }
    if (strcmp(arguments[0], "ps") == 0) 
    {
        pid = fork();

        if (pid == 0) 
        {
            if (pipe) 
            {
                dup2(input, STDIN_FILENO);
                close(input);
            }
            if (output) 
            {
                dup2(output, STDOUT_FILENO);
                close(output);
            }
            execlp(arguments[0], arguments[0], arguments[1], NULL);
        }
        else 
        {
            wait(NULL);
        }
    }
    else 
    {
        handle_pipes(arguments, input, output);
    }
}

void handle_pipes(char** arguments, int input, int output) 
{
    int pipefd[2];
    pid_t pid;

    if (pipe(pipefd) == -1) 
    {
        printf("Error creating pipe\n");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid == 0) 
    {
        close(pipefd[0]);
        dup2(input, STDIN_FILENO);
        if (output) 
        {
            dup2(output, STDOUT_FILENO);
        }
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);

        if (execvp(arguments[0], arguments) == -1) 
        {
            printf("Error executing command\n");
            exit(EXIT_FAILURE);
        }
    }
    else if (pid > 0) 
    {
        close(pipefd[1]);
        if (input) 
        {
            close(input);
        }
        execute_command(&arguments[1], 1, pipefd[0], output);
        close(pipefd[0]);
        wait(NULL);
    }
    else 
    {
        printf("Error forking process\n");
        exit(EXIT_FAILURE);
    }
}