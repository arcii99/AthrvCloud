//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1000
#define MAX_ARGS 100

void parseCommand(char* command, char** args)
{
    int i = 0;
    char* token = strtok(command, " ");
    while (token != NULL)
    {
        args[i] = token;
        token = strtok(NULL, " ");
        i++;
    }
    args[i] = NULL;
}

void executeCommand(char** args)
{
    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        // child process
        execvp(args[0], args);
        printf("Command not found: %s\n", args[0]);
        exit(EXIT_FAILURE);
    }
    else
    {
        // parent process
        int status;
        waitpid(pid, &status, 0);
    }
}

int main()
{
    char command[MAX_COMMAND_LENGTH];
    char* args[MAX_ARGS];
    while (true)
    {
        printf("myShell> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        if ((strlen(command) > 0) && (command[strlen(command) - 1] == '\n'))
        {
            command[strlen(command) - 1] = '\0';
        }
        parseCommand(command, args);
        executeCommand(args);
    }
    return 0;
}