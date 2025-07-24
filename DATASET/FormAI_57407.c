//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: protected
/* A basic Unix-like shell program in protected style */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 100
#define MAX_ARGS 10

int parse_command(char *cmd, char *args[])
{
    int num_args = 0;
    args[num_args] = strtok(cmd, " ");
    while (args[num_args] != NULL && num_args < MAX_ARGS)
    {
        num_args++;
        args[num_args] = strtok(NULL, " ");
    }
    return num_args;
}

int execute_command(char *cmd)
{
    char *args[MAX_ARGS + 1]; // +1 for NULL terminator
    int num_args = parse_command(cmd, args);

    int pid = fork();
    if (pid == -1) // Error in forking process
    {
        perror("fork");
        return -1;
    }
    else if (pid == 0) // Child process
    {
        execvp(args[0], args);
        perror("execvp");
        exit(EXIT_FAILURE);
    }
    else // Parent process
    {
        int status;
        waitpid(pid, &status, 0);
        return WIFEXITED(status) ? WEXITSTATUS(status) : -1;
    }
}

int main()
{
    char cmd[MAX_CMD_LEN + 1];
    int exit_shell = 0;

    printf("Protected Unix-like shell\n");
    while (!exit_shell)
    {
        printf("> ");
        if (fgets(cmd, MAX_CMD_LEN, stdin) == NULL)
        {
            printf("\n");
            exit_shell = 1;
        }
        else
        {
            cmd[strcspn(cmd, "\n")] = '\0'; // Remove newline character
            if (strcasecmp(cmd, "exit") == 0)
            {
                exit_shell = 1;
            }
            else
            {
                int exit_code = execute_command(cmd);
                if (exit_code != -1)
                {
                    printf("Process exited with status %d\n", exit_code);
                }
            }
        }
    }

    printf("Exiting shell...\n");
    return 0;
}