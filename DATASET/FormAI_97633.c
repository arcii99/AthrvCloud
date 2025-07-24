//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Claude Shannon
/* The following program demonstrates interprocess communication using a client-server model. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function prototypes
void client(int[]);
void server(int[]);

#define BUFFER_SIZE 10

int main()
{
    // Variables declaration
    int fd[2];
    pid_t pid;

    // Creating pipe
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Creating child process
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        // Parent process (client)
        client(fd);
    } else {
        // Child process (server)
        server(fd);
    }

    return 0;
}

// Client function (sends message to server)
void client(int fd[])
{
    // Variables declaration
    char write_buffer[BUFFER_SIZE] = {'\0'};
    int n;

    // Prompt message
    printf("Enter a message to send to server: ");
    fgets(write_buffer, BUFFER_SIZE, stdin);

    // Send message to server
    close(fd[0]);
    n = strlen(write_buffer);
    if (write(fd[1], write_buffer, n) != n) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    printf("Message sent to server: %s", write_buffer);
}

// Server function (receives message from client)
void server(int fd[])
{
    // Variables declaration
    char read_buffer[BUFFER_SIZE] = {'\0'};
    int n;

    // Receive message from client
    close(fd[1]);
    n = read(fd[0], read_buffer, BUFFER_SIZE);
    if (n == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    printf("Message received from client: %s", read_buffer);
}