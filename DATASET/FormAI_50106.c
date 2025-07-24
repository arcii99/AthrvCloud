//FormAI DATASET v1.0 Category: Recursive ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#define MAX 10

void recursive(int count);

int main(void)
{
    recursive(0);

    return 0;
}

void recursive(int count)
{
    if(count == MAX)
        return; // Base case

    printf("Iteration %d\n", count+1);

    // Async call to recursive function
    pid_t pid = fork();

    if(pid == 0)
    {
        recursive(count+1); // Child process
        exit(0);
    }
    else if(pid == -1)
    {
        perror("fork()");
        exit(1);
    }
    else
    {
        assert(waitpid(pid, NULL, 0) == pid); // Parent process
        printf("Child process finished, pid = %d\n", pid);
    }
}