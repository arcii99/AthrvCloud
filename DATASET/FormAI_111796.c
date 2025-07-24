//FormAI DATASET v1.0 Category: Interprocess communication ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Define the maximum length for the message
#define BUFFER_SIZE 25

// Function to handle the parent process
void parentProcess(int pipefd[]) {
    // Close the read end of the pipe
    close(pipefd[0]);
    
    // Define a message to be sent to the child process
    char message[BUFFER_SIZE] = "Hello, child!";

    // Write the message to the write end of the pipe
    write(pipefd[1], message, BUFFER_SIZE);

    // Close the write end of the pipe
    close(pipefd[1]);

    // Wait for the child process to finish
    wait(NULL);

    // Display a farewell message
    printf("Parent Process: Goodbye, child!\n");
}

// Function to handle the child process
void childProcess(int pipefd[]) {
    // Close the write end of the pipe
    close(pipefd[1]);

    // Define a buffer to store the message from the parent
    char buffer[BUFFER_SIZE];

    // Read the message from the read end of the pipe
    read(pipefd[0], buffer, BUFFER_SIZE);

    // Close the read end of the pipe
    close(pipefd[0]);
    
    // Display the message from the parent
    printf("Child Process: Message Received: %s\n", buffer);

    // Display a farewell message
    printf("Child Process: Goodbye, parent!\n");
}

int main() {
    // Define an array to hold the pipe information
    int pipefd[2];

    // Create the pipe
    if (pipe(pipefd) == -1) {
        perror("Error creating pipe");
        exit(EXIT_FAILURE);
    }

    // Create a child process
    pid_t pid = fork();

    // Check if the fork was successful
    if (pid == -1) {
        perror("Error creating child process");
        exit(EXIT_FAILURE);
    }
    // Check if the process is the parent or child
    else if (pid == 0) {
        // If it's the child process
        childProcess(pipefd);
    }
    else {
        // If it's the parent process
        parentProcess(pipefd);
    }

    return 0;
}