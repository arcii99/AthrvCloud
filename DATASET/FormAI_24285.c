//FormAI DATASET v1.0 Category: System administration ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    char command[1000];
    while(1)
    {
        printf("Enter the command you would like to run: ");
        fgets(command, sizeof(command), stdin);
        command[strlen(command)-1] = '\0';
        if(strcmp(command, "exit") == 0)
            break;
        pid_t pid = fork();
        if(pid == -1)
        {
            printf("Error: Fork failed!\n");
            exit(1);
        }
        if(pid == 0)
        {
            int ret = system(command);
            if(ret == -1)
            {
                printf("Error: Command not found!\n");
                exit(1);
            }
            exit(0);
        }
        else
        {
            int status;
            pid_t result = waitpid(pid, &status, 0);
            if(result == -1)
            {
                printf("Error: Wait failed!\n");
                exit(1);
            }
            if(WIFEXITED(status) && WEXITSTATUS(status) == 0)
                printf("Command executed successfully.\n");
            else
                printf("Error: Command execution failed!\n");
        }
    }
    return 0;
}