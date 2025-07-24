//FormAI DATASET v1.0 Category: Interprocess communication ; Style: systematic
/*

This is a C program demonstrating Interprocess communication between a parent process and a child process using pipes.

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(void) {

    char write_msg[BUFFER_SIZE];
    char read_msg[BUFFER_SIZE];
    int fd[2];
    pid_t pid;

    if (pipe(fd) == -1) { // Creating the pipe
        fprintf(stderr, "Pipe failed");
        return 1;
    }

    pid = fork(); // Creating a child process

    if (pid < 0) {
        fprintf(stderr, "Fork failed");
        return 1;
    }

    if (pid > 0) { // Parent Process

        close(fd[READ_END]); // Closing the unused read end of the pipe
        
        printf("Enter a message to write to the child process: ");
        fgets(write_msg, BUFFER_SIZE, stdin);
        
        write(fd[WRITE_END], write_msg, strlen(write_msg)+1); // Writing message to the pipe

        close(fd[WRITE_END]); // Closing the write end of the pipe

    } else { // Child Process

        close(fd[WRITE_END]); // Closing the unused write end of the pipe

        read(fd[READ_END], read_msg, BUFFER_SIZE); // Reading message from the pipe
        
        printf("Child received the message: %s", read_msg);

        close(fd[READ_END]); // Closing the read end of the pipe
    }

    return 0;
}