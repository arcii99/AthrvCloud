//FormAI DATASET v1.0 Category: Interprocess communication ; Style: portable
// This is a simple example of interprocess communication between two processes using pipes in C.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main()
{
    int fd[2]; // array to hold the file descriptors for the read and write ends of the pipe

    if (pipe(fd) == -1) // create the pipe
    {
        perror("pipe"); // print an error message if pipe creation failed
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork(); // create a child process

    if (pid == -1) // check if fork failed
    {
        perror("fork"); // print an error message if fork failed
        exit(EXIT_FAILURE);
    }

    if (pid == 0) // code for the child process
    {
        close(fd[0]); // close the read end of the pipe

        char message[] = "Hello parent process!"; // message to be sent to the parent process
        if (write(fd[1], message, strlen(message) + 1) == -1) // write the message to the pipe
        {
            perror("write"); // print an error message if write failed
            exit(EXIT_FAILURE);
        }

        close(fd[1]); // close the write end of the pipe
        exit(EXIT_SUCCESS);
    }
    else // code for the parent process
    {
        close(fd[1]); // close the write end of the pipe

        char buffer[100]; // buffer to hold the received message
        if (read(fd[0], buffer, sizeof(buffer)) == -1) // read the message from the pipe
        {
            perror("read"); // print an error message if read failed
            exit(EXIT_FAILURE);
        }

        printf("Message received from child process: %s\n", buffer); // print the received message

        close(fd[0]); // close the read end of the pipe
        exit(EXIT_SUCCESS);
    }
}