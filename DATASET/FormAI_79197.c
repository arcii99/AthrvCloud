//FormAI DATASET v1.0 Category: Interprocess communication ; Style: detailed
/*
 * This is a program demonstrating how to use Interprocess Communication (IPC) in C using pipes.
 * The program creates a child process which writes a string to a pipe. 
 * The parent process then reads the string from the pipe and outputs it to the console.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 25

int main(void)
{
    int fd[2];
    pid_t pid;
    char string[] = "Hello, world!";
    char buffer[BUFFER_SIZE];

    // create the pipe
    if (pipe(fd) == -1) {
        fprintf(stderr, "Pipe failed");
        return 1;
    }

    // fork a child process
    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed");
        return 1;
    } else if (pid > 0) { // parent process
        close(fd[1]); // close the write end of the pipe

        // read from the pipe
        if (read(fd[0], buffer, BUFFER_SIZE) == -1) {
            fprintf(stderr, "Read failed");
            return 1;
        }

        printf("Message received: %s\n", buffer);

        close(fd[0]); // close the read end of the pipe
    } else { // child process
        close(fd[0]); // close the read end of the pipe

        // write to the pipe
        if (write(fd[1], string, strlen(string)+1) == -1) {
            fprintf(stderr, "Write failed");
            return 1;
        }

        printf("Message sent: %s\n", string);

        close(fd[1]); // close the write end of the pipe
    }

    return 0;
}