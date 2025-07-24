//FormAI DATASET v1.0 Category: System administration ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    printf("\nWelcome to my unique C system administration example program!\n");
    
    char command[100];
    printf("\nEnter a command to execute: ");
    fgets(command, sizeof(command), stdin);
    
    command[strcspn(command, "\n")] = '\0'; // remove newline character from command
    
    pid_t pid = fork();
    int status;

    if (pid == 0)
    {
        printf("\nChild process executing command: %s\n", command);
        system(command);
        printf("\nChild process exiting...\n");
        exit(0);
    }
    else if (pid > 0)
    {
        printf("\nParent process waiting for child process to finish...\n");
        waitpid(pid, &status, 0);
        printf("\nParent process exited with status %d\n", status);
    }
    else
    {
        printf("\nError creating child process!\n");
    }

    printf("\nThanks for using my program!\n");
    
    return 0;
}