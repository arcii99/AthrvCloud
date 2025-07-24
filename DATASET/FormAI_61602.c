//FormAI DATASET v1.0 Category: Interprocess communication ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define READ_END 0
#define WRITE_END 1

int main(void)
{
    char write_msg[] = "Hello, child process! This is parent process!";
    char read_msg[100];
    int pipefd[2];
    pid_t pid;
    
    if (pipe(pipefd) == -1) {
        fprintf(stderr, "Pipe failed\n");
        return 1;
    }

    pid = fork(); // Creating a child process

    if (pid < 0) { // If creating child process fails
        fprintf(stderr, "Fork failed\n");
        return 1;
    } 
    
    if (pid > 0) { // Parent process
        
        close(pipefd[READ_END]); // Close the unused read end of pipe
        printf("Parent process writing message to child process...\n");
        write(pipefd[WRITE_END], write_msg, strlen(write_msg) + 1); // Writing message to child process
        printf("Parent process sent message: %s\n", write_msg);
        close(pipefd[WRITE_END]); // Close the write end of pipe
        
        // Wait for child process to complete
        wait(NULL);
        printf("Parent process waiting for child process to complete...\n");
    }
    else { // Child process
        
        close(pipefd[WRITE_END]); // Close the unused write end of pipe
        printf("Child process reading message from parent process...\n");
        read(pipefd[READ_END], read_msg, 100); // Reading message from parent process
        printf("Child process received message: %s\n", read_msg);
        close(pipefd[READ_END]); // Close the read end of pipe
        printf("Child process completed.\n");
    }
    
    return 0;
}