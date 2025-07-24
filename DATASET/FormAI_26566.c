//FormAI DATASET v1.0 Category: Interprocess communication ; Style: complex
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define READ_END 0
#define WRITE_END 1

void report_error(char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    // Create pipe
    int fd[2];
    if (pipe(fd) == -1) {
        report_error("Failed to create pipe");
    }

    // Fork
    pid_t pid = fork();
    if (pid == -1) {
        report_error("Failed to fork");
    }

    if (pid == 0) {
        // Child process - write to pipe
        close(fd[READ_END]);  // Close unused read end

        // Write message to pipe
        char *msg = "Hello from child process";
        write(fd[WRITE_END], msg, strlen(msg) + 1);

        // Close write end and exit
        close(fd[WRITE_END]);
        exit(0);
    } else {
        // Parent process - read from pipe
        close(fd[WRITE_END]);  // Close unused write end

        // Read message from pipe
        char buffer[100];
        read(fd[READ_END], buffer, 100);
        printf("Parent process received message: %s\n", buffer);

        // Close read end and exit
        close(fd[READ_END]);
        exit(0);
    }

    return 0;
}