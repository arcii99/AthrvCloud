//FormAI DATASET v1.0 Category: Interprocess communication ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

// Function to spawn child process
void spawn_child_process(int *, int *);

int main() {
    // Declare pipe file descriptors
    int pipefd[2];

    // Initialize pipe
    if (pipe(pipefd) == -1) {
        fprintf(stderr, "Pipe failed");
        return 1;
    }

    // Spawn child process
    spawn_child_process(&pipefd[0], &pipefd[1]);

    // Declare buffer and message to be sent
    char buffer[100];
    char message[] = "Hello from parent process!";

    // Write message to pipe
    write(pipefd[1], message, strlen(message));
    printf("Parent: Sent message to child process\n");

    // Read message from pipe
    read(pipefd[0], buffer, sizeof(buffer));
    printf("Parent: Received message from child process: %s\n", buffer);

    // Close pipe file descriptors
    close(pipefd[0]);
    close(pipefd[1]);

    return 0;
}

void spawn_child_process(int *read_fd, int *write_fd) {
    // Declare pipe file descriptors
    int child_pipefd[2];

    // Initialize pipe
    if (pipe(child_pipefd) == -1) {
        fprintf(stderr, "Pipe failed");
        exit(1);
    }

    // Fork process
    pid_t pid = fork();

    // Handle fork error
    if (pid == -1) {
        fprintf(stderr, "Fork failed");
        exit(1);
    }

    // Child process
    if (pid == 0) {
        // Close unused pipe file descriptors
        close(child_pipefd[1]);
        close(*read_fd);

        // Declare buffer and message to be sent
        char buffer[100];
        char message[] = "Hello from child process!";

        // Read message from parent process
        read(child_pipefd[0], buffer, sizeof(buffer));
        printf("Child: Received message from parent process: %s\n", buffer);

        // Write message to parent process
        write(*write_fd, message, strlen(message));
        printf("Child: Sent message to parent process\n");

        // Close pipe file descriptors
        close(child_pipefd[0]);
        close(*write_fd);

        // Exit child process
        exit(0);
    }
    else { // Parent process
        // Close unused pipe file descriptors
        close(child_pipefd[0]);
        close(*write_fd);

        // Pass child pipe file descriptor to parent
        *read_fd = child_pipefd[1];
    }
}