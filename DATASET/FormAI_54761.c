//FormAI DATASET v1.0 Category: Interprocess communication ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

#define PIPE_PATH "/tmp/my_pipe" // Defining pipe path

int main() {
    int fd;
    pid_t child_pid;
    const char *message = "Hello from parent process"; // Message to send

    mkfifo(PIPE_PATH, 0666); // Creating named pipe
    fd = open(PIPE_PATH, O_WRONLY); // Opening pipe for writing

    if (fd == -1) {
        perror("Failed to open pipe");
        return -1;
    }

    child_pid = fork(); // Creating child process

    if (child_pid == 0) { // Child process
        char read_message[100]; // Buffer to read message

        fd = open(PIPE_PATH, O_RDONLY); // Opening pipe for reading

        if (fd == -1) {
            perror("Failed to open pipe");
            return -1;
        }

        read(fd, read_message, strlen(message) + 1); // Reading from pipe

        printf("Child process received message: %s\n", read_message); // Printing received message
        close(fd); // Closing pipe

        return 0;
    }
    else { // Parent process
        printf("Parent process sending message: %s\n", message); // Printing message to send
        write(fd, message, strlen(message) + 1); // Writing message to pipe
        wait(NULL); // Waiting for child process to finish
        close(fd); // Closing pipe

        return 0;
    }
}