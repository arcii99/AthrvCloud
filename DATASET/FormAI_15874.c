//FormAI DATASET v1.0 Category: Interprocess communication ; Style: detailed
// A unique example program for Interprocess Communication in C
// This program demonstrates how two processes (parent and child) can communicate with each other using pipes.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define READ_END 0
#define WRITE_END 1

int main(int argc, char* argv[]) {

    int fd[2];
    pid_t pid;

    char write_message[100] = "Hello, child process!";
    char read_message[100];

    // Create a pipe
    if (pipe(fd) == -1) {
        fprintf(stderr, "Pipe failed");
        return 1;
    }

    // Fork a child process
    pid = fork();

    if (pid < 0) { // Error occurred
        fprintf(stderr, "Fork failed");
        return 1;
    }
    else if (pid == 0) { // Child process
        // Close the unused end of the pipe
        close(fd[WRITE_END]);
        // Read from the pipe
        read(fd[READ_END], read_message, 100);
        printf("Message from parent: %s\n", read_message);
        // Close the read end of the pipe
        close(fd[READ_END]);
    }
    else { // Parent process
        // Close the unused end of the pipe
        close(fd[READ_END]);
        // Write to the pipe
        write(fd[WRITE_END], write_message, strlen(write_message) + 1);
        // Close the write end of the pipe
        close(fd[WRITE_END]);
    }

    return 0;
}