//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_NUM_ARGUMENTS 5

void ReadCommand(char *cmd, char **params);

int main()
{
    char *command[MAX_NUM_ARGUMENTS + 1];
    char cmd[MAX_COMMAND_LENGTH];
    int status;

    while(1)
    {
        printf("shell> ");
        fflush(stdout);

        // Read command and its arguments
        ReadCommand(cmd, command);

        // Exit shell if specified
        if (strcmp(command[0], "exit") == 0)
        {
            exit(0);
        }

        // Fork to execute the command
        pid_t pid = fork();
        if (pid == 0)
        {
            //Child process

            // Execute the command
            if (execvp(command[0], command) == -1)
            {
                printf("Failed to execute command!\n");
                exit(1);
            }
        }
        else if (pid < 0)
        {
            // Fork failed
            printf("Fork failed!\n");
            exit(1);
        }
        else
        {
            // Parent process

            // Wait for child process to complete
            if (waitpid(pid, &status, 0) == -1)
            {
                printf("Error waiting for child process to complete!");
                exit(1);
            }
        }
    }

    return 0;
}

void ReadCommand(char *cmd, char **params)
{
    char *token;
    int i;

    // Read input command
    fgets(cmd, MAX_COMMAND_LENGTH, stdin);

    // Remove newline character at the end of the command
    int len = strlen(cmd);
    if (len > 0 && cmd[len-1] == '\n')
    {
        cmd[len-1] = '\0';
    }

    // Parse command and its arguments
    i = 0;
    token = strtok(cmd, " ");

    while (token != NULL && i < MAX_NUM_ARGUMENTS)
    {
        params[i] = token;
        i++;

        token = strtok(NULL, " ");
    }

    params[i] = NULL;
}