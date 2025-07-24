//FormAI DATASET v1.0 Category: Interprocess communication ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_MSG_LENGTH 100

int main() {
    // Create two pipes for two-way communication
    int pipe1[2], pipe2[2];
    
    if(pipe(pipe1) == -1) {
        perror("Pipe 1 creation failed");
        exit(1);
    }
    
    if(pipe(pipe2) == -1) {
        perror("Pipe 2 creation failed");
        exit(1);
    }
    
    // Create a child process
    pid_t pid = fork();
    if(pid == -1) {
        perror("Fork failed");
        exit(1);
    }
    
    if(pid == 0) {
        // Child process reads message from parent process through pipe 1
        char message[MAX_MSG_LENGTH];
        close(pipe1[1]); // Close write end of pipe 1
        
        int nbytes = read(pipe1[0], message, MAX_MSG_LENGTH);
        if(nbytes == -1) {
            perror("Read failed");
            exit(1);
        }
        close(pipe1[0]); // Close read end of pipe 1
        
        printf("Child process received message: %s\n", message);
        
        // Child process sends message to parent process through pipe 2
        char reply[] = "Hello parent, this is your child!";
        close(pipe2[0]); // Close read end of pipe 2
        
        if(write(pipe2[1], reply, strlen(reply) + 1) == -1) {
            perror("Write failed");
            exit(1);
        }
        close(pipe2[1]); // Close write end of pipe 2
        
        exit(0);
    } else {
        // Parent process sends message to child process through pipe 1
        char message[] = "Hello child, this is your parent!";
        close(pipe1[0]); // Close read end of pipe 1
        
        if(write(pipe1[1], message, strlen(message) + 1) == -1) {
            perror("Write failed");
            exit(1);
        }
        close(pipe1[1]); // Close write end of pipe 1
        
        // Parent process reads message from child process through pipe 2
        char reply[MAX_MSG_LENGTH];
        close(pipe2[1]); // Close write end of pipe 2
        
        int nbytes = read(pipe2[0], reply, MAX_MSG_LENGTH);
        if(nbytes == -1) {
            perror("Read failed");
            exit(1);
        }
        close(pipe2[0]); // Close read end of pipe 2
        
        printf("Parent process received message: %s\n", reply);
        
        // Wait for child process to finish
        int status;
        wait(&status);
        if(WIFEXITED(status)) {
            printf("Child process exited with status: %d\n", WEXITSTATUS(status));
        } else if(WIFSIGNALED(status)) {
            printf("Child process exited due to signal: %d\n", WTERMSIG(status));
        }
    }
    
    return 0;
}