//FormAI DATASET v1.0 Category: System administration ; Style: intelligent
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t pid;

    // Fork a child process
    pid = fork();

    // If the pid is negative, an error occurred
    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(-1);
    }

    // If the pid is 0, this is the child process
    // This example will display the current system date
    if (pid == 0) {
        printf("This is the child process\n");

        // Run the command to display the date
        execl("/bin/date", "date", NULL);

        // If execl returns, it failed
        fprintf(stderr, "Failed to execute date command\n");
        exit(-1);
    }

    // If the pid is positive, this is the parent process
    // Wait for the child to terminate
    if (pid > 0) {
        printf("This is the parent process\n");

        // Wait for the child to terminate
        wait(NULL);

        printf("Child process completed\n");
        exit(0);
    }

    return 0;
}