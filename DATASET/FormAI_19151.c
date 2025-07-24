//FormAI DATASET v1.0 Category: Interprocess communication ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
    pid_t pid;
    char msg1[] = "Hello!";
    char msg2[] = "How are you?";
    char read_msg[50];

    int p[2]; // This is the pipe.

    if (pipe(p) < 0) // Error checking for pipe.
    {
        printf("Pipe creation error!\n");
        exit(1);
    }

    pid = fork();

    if (pid < 0) // Error checking for fork.
    {
        printf("Fork error!\n");
        exit(1);
    }

    if (pid > 0) // Parent process.
    {
        close(p[0]); // Closing reading end of pipe for parent.

        write(p[1], msg1, strlen(msg1)+1); // Writing to the pipe.
        printf("\nParent: Sent message - %s\n", msg1);

        wait(NULL); // Waiting for child to complete.

        read(p[0], read_msg, sizeof(read_msg)); // Reading from the pipe.
        printf("\nParent: Received message - %s\n", read_msg);

        close(p[1]); // Closing writing end of pipe for parent.
    }

    else // Child process.
    {
        close(p[1]); // Closing writing end of pipe for child.

        read(p[0], read_msg, sizeof(read_msg)); // Reading from the pipe.
        printf("\nChild: Received message - %s\n", read_msg);

        write(p[1], msg2, strlen(msg2)+1); // Writing to the pipe.
        printf("\nChild: Sent message - %s\n", msg2);

        close(p[0]); // Closing reading end of pipe for child.
    }

    return 0;
}