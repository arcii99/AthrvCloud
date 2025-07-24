//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_LINE 80 /* 80 chars per line, per command */

int main(void)
{
    char *args[MAX_LINE / 2 + 1]; /* command line arguments */
    int should_run = 1; /* flag to determine when to exit program */
    char input_buffer[MAX_LINE];
    int i, j, arg_count;
    pid_t pid;

    while (should_run)
    {
        printf("osh> ");
        fflush(stdout);

        /* read user input */
        fgets(input_buffer, MAX_LINE, stdin);

        /* Remove newline character from input */
        input_buffer[strcspn(input_buffer, "\n")] = '\0';

        /* reset arguments array */
        for (i = 0; i < MAX_LINE / 2 + 1; i++)
        {
            args[i] = NULL;
        }

        /* tokenize input into arguments */
        i = 0;
        char *token = strtok(input_buffer, " ");
        while (token != NULL)
        {
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        arg_count = i;

        /* Handle exit command */
        if (strcmp(args[0], "exit") == 0 || strcmp(args[0], "quit") == 0)
        {
            should_run = 0;
            break;
        }

        /* Handle cd command separately */
        if (strcmp(args[0], "cd") == 0)
        {
            int cd_status = chdir(args[1]);
            if (cd_status < 0)
            {
                printf("Error: Could not change directory to %s\n", args[1]);
            }
            continue;
        }

        /* Fork a new process */
        pid = fork();

        if (pid < 0) /* Error occurred */
        {
            printf("Fork failed!\n");
            return 1;
        }
        else if (pid == 0) /* Child process */
        {
            /* Execute command */
            if (execvp(args[0], args) == -1)
            {
                printf("Error: Command not found\n");
            }
            exit(0);
        }
        else /* Parent process */
        {
            /* Wait for child process to complete */
            wait(NULL);
        }
    }

    return 0;
}