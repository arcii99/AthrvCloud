//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Sherlock Holmes
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    pid_t pid;
    int pipe_fd[2];

    // Create the pipe
    if (pipe(pipe_fd) < 0) {
        printf("Unable to create pipe. Case closed.\n");
        return -1;
    }

    // Fork a child process
    pid = fork();

    // If the fork failed
    if (pid < 0) {
        printf("Failed to spawn child process. Case closed.\n");
        return -1;
    }

    // If we are in the child process
    if (pid == 0) {
        char *message = "The game is afoot!";
        char buffer[100];
        
        // Close the pipe's write end
        close(pipe_fd[1]);

        // Read the message from the pipe
        read(pipe_fd[0], buffer, sizeof(buffer));
        printf("Sherlock received a message: %s\n", buffer);

        // Close the pipe's read end
        close(pipe_fd[0]);
        
        // Signal the end of the investigation
        printf("Case closed. Aha!\n");

    // If we are in the parent process
    } else {
        char *message = "Watson, come at once!";
        char buffer[100];
        
        // Close the pipe's read end
        close(pipe_fd[0]);

        // Write the message to the pipe
        write(pipe_fd[1], message, sizeof(message));
        printf("Watson sends a message: %s\n", message);

        // Close the pipe's write end
        close(pipe_fd[1]);

        // Wait for the child to signal the end of the investigation
        wait(NULL);
    }

    return 0;
}