//FormAI DATASET v1.0 Category: Interprocess communication ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MESSAGE_PIPE "./message_pipe"

void send_message(char* message);
void receive_message();

int main() {
    // Create a named pipe
    mkfifo(MESSAGE_PIPE, 0666);

    // Fork the process to create a child process
    pid_t pid = fork();

    // Error handling for fork
    if (pid < 0) {
        perror("Failed to fork process");
        exit(EXIT_FAILURE);
    }
    // Child process
    else if (pid == 0) {
        // Receive message from parent process
        receive_message();
    } 
    // Parent process
    else {
        // Send message to child process
        char message[] = "Hello from parent process!";
        send_message(message);

        // Wait for child process to finish
        wait(NULL);
    }

    // Remove the named pipe
    unlink(MESSAGE_PIPE);
    return 0;
}

void send_message(char* message) {
    printf("Parent process sending message: %s\n", message);
    int message_pipe = open(MESSAGE_PIPE, O_WRONLY);
    write(message_pipe, message, sizeof(message));
    close(message_pipe);
}

void receive_message() {
    // Open the named pipe for reading
    int message_pipe = open(MESSAGE_PIPE, O_RDONLY);

    // Read the message from the pipe
    char message[100];
    read(message_pipe, message, 100);
    printf("Child process received message: %s\n", message);

    // Close the pipe
    close(message_pipe);
}