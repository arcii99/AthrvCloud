//FormAI DATASET v1.0 Category: Interprocess communication ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main() {
    // Declare variables
    const char *file_path = "/tmp/ipc_example"; 
    char *msg_send = "This is a message sent from Process A to B";
    char msg_recv[256];

    // Create named pipe
    mkfifo(file_path, 0666);

    // Create child process
    pid_t pid = fork();

    // Error handling
    if (pid < 0) {
        fprintf(stderr, "Fork Failed");
        return 1;
    }

    // If child process created
    if (pid == 0) {
        // Open named pipe for read
        int fd = open(file_path, O_RDONLY);

        // Error handling
        if (fd == -1) {
            perror("open");
            return 1;
        }

        // Read message from named pipe into msg_recv
        read(fd, msg_recv, sizeof(msg_recv));

        // Close named pipe
        close(fd);

        // Print received message to stdout
        printf("Message received: %s\n", msg_recv);

        // Exit child process
        exit(0);
    } else { // Parent process
        // Open named pipe for write
        int fd = open(file_path, O_WRONLY);

        // Error handling
        if (fd == -1) {
            perror("open");
            return 1;
        }

        // Write message to named pipe
        write(fd, msg_send, strlen(msg_send) + 1);

        // Close named pipe
        close(fd);

        // Wait for child process to complete
        wait(NULL);
    }

    // Remove named pipe
    unlink(file_path);

    return 0;
}