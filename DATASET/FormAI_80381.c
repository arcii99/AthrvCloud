//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    pid_t pid;
    int status;
    int cpu_usage;
    
    while(1)
    {
        pid = fork();
        if(pid == 0)
        {
            // Child process
            exit(0);
        }
        else if(pid < 0)
        {
            // Fork failed!
            printf("Fork failed!");
            exit(1);
        }
        else
        {
            // Parent process
            waitpid(pid, &status, 0);
            cpu_usage = rand() % 100;
            printf("CPU usage: %d%%\n", cpu_usage);
            sleep(1);
        }
    }
    return 0;
}