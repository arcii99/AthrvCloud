//FormAI DATASET v1.0 Category: System administration ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler(int sig)
{
    // handle the signal
    printf("Caught signal %d\n", sig);
    // exit the program
    exit(1);
}

int main()
{
    // set up the signal handler
    signal(SIGINT, handler);

    // start the asynchronous process
    pid_t pid = fork();

    if (pid == -1)
    {
        // handle error
        perror("Fork failed");
        exit(1);
    }
    else if (pid == 0)
    {
        // this is the child process
        // execute the system command asynchronously
        char* command[] = {"ls", "-l", NULL};
        execvp(command[0], command);
    }
    else
    {
        // this is the parent process
        // wait for the child process to finish
        wait(NULL);
    }

    return 0;
}