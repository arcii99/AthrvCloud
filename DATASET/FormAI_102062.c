//FormAI DATASET v1.0 Category: System administration ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int pid = fork();

    if (pid == 0) // child process
    {
        char* childArgs[] = {"ls", "-a", NULL};
        execvp(childArgs[0], childArgs);
    }
    else if (pid > 0) // parent process
    {
        printf("Child process started with PID %d\n", pid);
        waitpid(pid, NULL, 0);
        printf("Child process completed\n");
    }
    else // error occurred
    {
        perror("fork() failed");
        exit(-1);
    }

    // More system administration tasks can be added here
    
    return 0;
}