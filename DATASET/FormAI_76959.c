//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 80 // The maximum length of the command

int main(void)
{
    char *args[MAX_LINE / 2 + 1]; // Command line arguments
    int should_run = 1; // Flag to determine when to exit program
    char cmd[MAX_LINE + 1]; // String to hold command
    pid_t pid; // Process ID of child process
    int background = 0; // Flag to determine if process is running in background

    while (should_run)
    {
        printf("osh> "); fflush(stdout);

        /* Read in command from user */
        fgets(cmd, MAX_LINE, stdin);
        cmd[strcspn(cmd, "\n")] = '\0'; // Remove trailing newline

        char *token;
        int i = 0;

        /* Parse command into tokens */
        token = strtok(cmd, " ");
        while (token != NULL)
        {
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        args[i] = NULL;

        /* Handle empty command */
        if (args[0] == NULL)
        {
            continue;
        }

        /* Check for background process */
        if (strcmp(args[i - 1], "&") == 0)
        {
            background = 1;
            args[i - 1] = NULL;
        }
        else
        {
            background = 0;
        }

        /* Create child process */
        pid = fork();

        if (pid < 0) // Error occurred
        {
            fprintf(stderr, "Fork failed.\n");
            exit(1);
        }
        else if (pid == 0) // Child process
        {
            if (execvp(args[0], args) == -1)
            {
                fprintf(stderr, "Command not found.\n");
            }
            exit(0);
        }
        else // Parent process
        {
            /* Wait for child process if not running in background */
            if (!background)
            {
                waitpid(pid, NULL, 0);
            }
        }
    }

    return 0;
}