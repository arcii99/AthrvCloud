//FormAI DATASET v1.0 Category: Interprocess communication ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(int argc, char const *argv[])
{
    char write_msg[BUFFER_SIZE] = "Greetings";
    char read_msg[BUFFER_SIZE];

    // Create pipe
    int fd[2];
    pid_t pid;

    if (pipe(fd) == -1)
    {
        fprintf(stderr, "Pipe failed");
        return 1;
    }

    // Fork process
    pid = fork();

    if (pid < 0)
    {
        fprintf(stderr, "Fork failed");
        return 1;
    }

    if (pid > 0)
    {
        // Parent process

        // Close unused write end of pipe
        close(fd[WRITE_END]);

        // Read from pipe
        read(fd[READ_END], read_msg, BUFFER_SIZE);
        printf("Parent read: %s\n", read_msg);

        // Close read end of pipe
        close(fd[READ_END]);
    }
    else
    {
        // Child process

        // Close unused read end of pipe
        close(fd[READ_END]);

        // Write to pipe
        write(fd[WRITE_END], write_msg, strlen(write_msg) + 1);
        printf("Child wrote: %s\n", write_msg);

        // Close write end of pipe
        close(fd[WRITE_END]);

        // Exit child process
        exit(0);
    }

    return 0;
}