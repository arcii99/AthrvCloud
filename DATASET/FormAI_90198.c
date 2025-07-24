//FormAI DATASET v1.0 Category: Interprocess communication ; Style: careful
// Example program showcasing Interprocess Communication in C using pipes

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define MSG_SIZE 50 // Define the maximum message size

int main() {
    int pipe_fd[2]; // Declare an array to hold the pipe file descriptors
    char buffer[MSG_SIZE]; // Initialize a buffer to hold data to be written and read from pipes

    if (pipe(pipe_fd) == -1) { // Create the pipe and check for errors during creation
        perror("pipe creation failed"); // print the error message
        exit(EXIT_FAILURE); // Exit the program with a failure status code
    }

    int child_pid = fork(); // Create a child process by calling fork()

    if (child_pid == -1) { // Check for errors during forking
        perror("fork() failed"); // print the error message
        exit(EXIT_FAILURE); // Exit the program with a failure status code
    } else if (child_pid == 0) { // Child process code

        // Close the write end of the pipe since the child will only read from the pipe
        close(pipe_fd[1]);
        printf("Child process: Waiting for a message from parent process...\n");

        // Read the data from the pipe and print it to stdout
        read(pipe_fd[0], buffer, MSG_SIZE);
        
        printf("Child process: From parent process: %s\n", buffer);
        
        // Close the read end of the pipe
        close(pipe_fd[0]);

    } else { // Parent process code
    
        // Close the read end of the pipe since the parent will only write to the pipe
        close(pipe_fd[0]);
        printf("Parent process: Sending a message to child process...\n");

        // Write the data to the pipe
        write(pipe_fd[1], "Hello child process!", MSG_SIZE);
        
        // Close the write end of the pipe
        close(pipe_fd[1]);

        // wait for the child process to finish execution
        int status;
        waitpid(child_pid, &status, 0);
        printf("Parent process: Child process terminated with %d status.\n", WEXITSTATUS(status));
    }

    return 0; // Exit the program with a success status code
}