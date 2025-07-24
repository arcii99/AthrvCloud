//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: brave
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MAX_LEN 1024
#define MAX_ARGS 64

int main()
{
    char input[MAX_LEN];
    char* tokenizedArgs[MAX_ARGS];
    int status;

    while(1)
    {
        printf("myshell> ");
        fgets(input, MAX_LEN, stdin);

        if(strcmp(input, "exit\n") == 0)
        {
            printf("Goodbye!\n");
            return 0;
        }

        // Split input into tokens
        char* token = strtok(input, " \n");
        int i = 0;
        while(token != NULL)
        {
            tokenizedArgs[i] = token;
            token = strtok(NULL, " \n");
            i++;
        }
        tokenizedArgs[i] = NULL;

        // Create child process
        pid_t pid = fork();

        if(pid == 0)
        {
            // Child process
            execvp(tokenizedArgs[0], tokenizedArgs);
            perror("execvp() failed");
            exit(1);
        }
        else if(pid < 0)
        {
            // Error creating child process
            perror("fork() failed");
            exit(1);
        }
        else
        {
            // Parent process
            waitpid(pid, &status, 0);
        }
    }
    return 0;
}