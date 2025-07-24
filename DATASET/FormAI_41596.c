//FormAI DATASET v1.0 Category: Interprocess communication ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void child_process(int n, int pfd[])
{
    int num;
    close(pfd[0]);
    read(pfd[1], &num, sizeof(num));
    printf("Child Process %d: Recieved %d\n", n, num);
    if(num > 1)
    {
        int new_num = num - 1;
        printf("Child Process %d: Sending %d\n", n, new_num);
        write(pfd[0], &new_num, sizeof(new_num));
        child_process(n+1, pfd);
    }
    else
    {
        printf("Child Process %d: Terminating\n", n);
        close(pfd[0]);
        close(pfd[1]);
        exit(0);
    }
}

int main()
{
    int pfd[2];
    int num = 10;

    if(pipe(pfd))
    {
        printf("Error creating pipe\n");
        exit(1);
    }

    pid_t pid = fork();

    if(pid == 0)
    {
        // Child process
        child_process(1, pfd);
    }
    else if(pid > 0)
    {
        // Parent process
        printf("Parent Process: Sending %d\n", num);
        write(pfd[1], &num, sizeof(num));
        wait(NULL);
        printf("Parent Process: Terminating\n");
        close(pfd[0]);
        close(pfd[1]);
    }
    else
    {
        printf("Error creating child process\n");
        exit(1);
    }

    return 0;
}