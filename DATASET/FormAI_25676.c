//FormAI DATASET v1.0 Category: Interprocess communication ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

#define MAX_BUF 1024 // Maximum buffer size for message

void sig_handler(int sig); // Signal handler

int main(int argc, char **argv)
{
    int p[2]; // File descriptors for pipe
    pid_t pid; // Process ID for child process
    char msg[MAX_BUF]; // Message buffer

    signal(SIGINT, sig_handler); // Register signal handler for SIGINT (Ctrl + C)

    if (pipe(p) == -1) // Create pipe
    {
        perror("Error creating pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork(); // Create child process

    if (pid == -1) // Error checking for fork
    {
        perror("Error forking process");
        exit(EXIT_FAILURE);
    }
    
    if (pid == 0) // Child process
    {
        close(p[1]); // Close write end of pipe
        while(1)
        {
            ssize_t r = read(p[0], msg, MAX_BUF); // Read message from parent process
            if (r > 0)
            {
                printf("Child process received message: %s", msg); // Print received message
                fflush(stdout);
            }
            else if (r == 0) // If EOF encountered, exit child process
            {
                exit(EXIT_SUCCESS);
            }
            else if (r == -1 && errno != EINTR) // Error checking for read operation
            {
                perror("Error reading message from pipe");
                exit(EXIT_FAILURE);
            }
        }
    }
    else // Parent process
    {
        close(p[0]); // Close read end of pipe
        while(1)
        {
            fgets(msg, MAX_BUF, stdin); // Get input from user
            ssize_t w = write(p[1], msg, strlen(msg) + 1); // Write message to child process
            if (w == -1) // Error checking for write operation
            {
                perror("Error writing message to pipe");
                exit(EXIT_FAILURE);
            }
            else if (strcmp(msg, "Exit\n") == 0) // If user enters "Exit", exit parent process
            {
                printf("Exiting parent process.\n");
                kill(pid, SIGINT); // Send SIGINT signal to child process
                int status;
                waitpid(pid, &status, 0); // Wait for child process to exit
                exit(EXIT_SUCCESS);
            }
        }
    }

    return 0;
}

void sig_handler(int sig)
{
    printf("\nReceived SIGINT signal.\n");
    exit(EXIT_SUCCESS);
}