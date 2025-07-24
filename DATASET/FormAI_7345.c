//FormAI DATASET v1.0 Category: System administration ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    int status;

    // Fork a child process
    pid = fork();

    if (pid < 0)
    {
        // If failed to fork
        fprintf(stderr, "Fork failed!");
        exit(1);
    }
    else if (pid == 0)
    {
        // If child process
        printf("[Child] Process ID: %d\n", getpid());

        // Set the user ID to root
        setuid(0);

        // Execute the desired system command
        system("apt-get update");

        _exit(0);
    }
    else
    {
        // If parent process
        printf("[Parent] Process ID: %d\n", getpid());

        // Wait for child process to terminate
        wait(&status);

        if (WIFEXITED(status))
            printf("Child process exited with status: %d\n", WEXITSTATUS(status));
        else if (WIFSIGNALED(status))
            printf("Child process terminated by signal: %d\n", WTERMSIG(status));
        else if (WIFSTOPPED(status))
            printf("Child process stopped by signal: %d\n", WSTOPSIG(status));
    }

    return 0;
}