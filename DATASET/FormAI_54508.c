//FormAI DATASET v1.0 Category: System administration ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    int status, pid;
    char command[50];

    printf("\n========== System Administration Program ==========\n\n");

    while(1)
    {
        printf("> ");
        fgets(command, sizeof(command), stdin);

        if (strcmp(command, "exit\n") == 0)
        {
            printf("\nGoodbye!\n");
            break;
        }

        pid = fork(); // create a child process

        if (pid == -1) // fork failed
        {
            perror("Fork failed.");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0) // child process
        {
            char *split_command[50];
            int i = 0;

            split_command[0] = strtok(command, " \n");

            while (split_command[i] != NULL)
            {
                i++;
                split_command[i] = strtok(NULL, " \n");
            }

            execvp(split_command[0], split_command);

            // if execvp returns, there was an error
            perror("Execvp failed.");
            exit(EXIT_FAILURE);
        }
        else // parent process
        {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}