//FormAI DATASET v1.0 Category: System administration ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    printf("Welcome to this amazing system administration program!\n");
    printf("I'm your faithful friend and helper, Sys-Bot-9000!\n");

    printf("\n");

    pid_t pid;
    pid = fork();

    if (pid < 0)
    {
        printf("Oops, the fork failed!");
        exit(1);
    }
    else if (pid == 0)
    {
        printf("I am the child process %d and I'm here to assist!\n", getpid());
        printf("My parent process ID is %d.\n", getppid());
        printf("I'm going to run a cool command now. Wait for it...\n");
        sleep(3);
        printf("Here it is: ls!\n");
        printf("Running command...\n");
        execlp("/bin/ls", "ls", NULL);
        printf("Welp, that didn't work. Oh well, time to go back to sleep.\n");
        exit(0);
    }
    else
    {
        printf("I am the parent process %d and I'm in charge around here!\n", getpid());
        printf("My child process ID is %d.\n", pid);
        printf("I'm going to wait for my child process to finish running its command...\n");
        int status;
        waitpid(pid, &status, 0);
        printf("Alright, my child process is done and returned status %d.\n", status);
        printf("Good job, Sys-Bot-9000! Until next time, keep on keepin' on!\n");

        return 0;
    }
}