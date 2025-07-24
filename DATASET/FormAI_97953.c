//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_LENGTH 80
#define MAX_ARGS 10

int main()
{
    char command[MAX_LENGTH];
    char *args[MAX_ARGS];
    char *token;
    int status;
    
    while(1)
    {
        printf(">> ");
        fgets(command, MAX_LENGTH, stdin);
        command[strcspn(command, "\n")] = 0;
        
        if(strcmp(command, "exit") == 0)
            break;
        
        int arg_count = 0;
        token = strtok(command, " ");
        
        while(token != NULL)
        {
            args[arg_count] = token;
            arg_count++;
            token = strtok(NULL, " ");
        }
        
        args[arg_count] = NULL;
        
        pid_t pid = fork();
        
        if(pid < 0)
        {
            printf("Fork failed.\n");
            exit(1);
        }
        else if(pid == 0)
        {
            execvp(args[0], args);
            printf("Command not found.\n");
            exit(1);
        }
        else
        {
            waitpid(pid, &status, 0);
        }
    }
    
    printf("Exiting shell...\n");
    
    return 0;
}