//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 80 /* The maximum length command */

int main(void)
{
    char *args[MAX_LINE / 2 + 1]; /* command line arguments */
    int should_run = 1; /* flag to determine when to exit program */
    char command[MAX_LINE]; /* user input command */
    int num_args; /* number of arguments */
    pid_t pid; /* process ID variable */
    int status; /* process status variable */

    while (should_run)
    {
        printf("osh> ");
        fflush(stdout); /* flush stdout buffer */

        fgets(command, MAX_LINE, stdin); /* read user input */
        command[strcspn(command, "\n")] = 0; /* remove trailing '\n' character */

        /* split command into arguments */
        char *token = strtok(command, " ");
        num_args = 0;
        while (token != NULL)
        {
            args[num_args] = token;
            num_args++;
            token = strtok(NULL, " ");
        }
        args[num_args] = NULL; /* set last argument to NULL */

        /* execute command */
        pid = fork();
        if (pid == 0) /* child process */
        {
            execvp(args[0], args);
            perror("execvp"); /* print an error message if execvp fails */
            exit(EXIT_FAILURE);
        }
        else if (pid > 0) /* parent process */
        {
            waitpid(pid, &status, 0);
        }
        else /* fork() failed */
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        /* check for exit command */
        if (strcmp(command, "exit") == 0)
        {
            should_run = 0;
        }
    }

    return 0;
}