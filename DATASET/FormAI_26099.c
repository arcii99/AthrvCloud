//FormAI DATASET v1.0 Category: Interprocess communication ; Style: peaceful
// Peaceful Interprocess Communication Example Program

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 100

int main() {
    int fd1, fd2;
    char *input_pipe = "/tmp/input_pipe";
    char *output_pipe = "/tmp/output_pipe";
    char buffer[BUFFER_SIZE];
    pid_t pid;

    // Create named pipes for input and output
    mkfifo(input_pipe, 0666);
    mkfifo(output_pipe, 0666);

    // Fork a child process for handling input
    pid = fork();

    if (pid < 0) {
        printf("Error creating child process\n");
        return 1;
    }

    if (pid == 0) {
        // Child process for handling input
        fd1 = open(input_pipe, O_RDONLY);
        read(fd1, buffer, BUFFER_SIZE);
        printf("Received input: %s\n", buffer);
        close(fd1);
        exit(0);
    }
    else {
        // Parent process for handling output
        fd2 = open(output_pipe, O_WRONLY);
        printf("Enter input: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        write(fd2, buffer, BUFFER_SIZE);
        wait(NULL);
        close(fd2);
        printf("Data sent to child process.\n");
    }

    // Remove named pipes
    unlink(input_pipe);
    unlink(output_pipe);

    return 0;
}