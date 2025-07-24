//FormAI DATASET v1.0 Category: Interprocess communication ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

#define BUF_SIZE 256

volatile sig_atomic_t received_signal = 0;

void signal_handler(int signal) {
    received_signal = signal;
}

int send_message(int fd, char *message) {
    size_t message_len = strlen(message) + 1; // include null terminator
    if (write(fd, message, message_len) == -1) {
        perror("write");
        return -1;
    }
    return 0;
}

int receive_message(int fd, char *buffer) {
    int num_bytes = read(fd, buffer, BUF_SIZE);
    if (num_bytes == -1) {
        perror("read");
        return -1;
    } else if (num_bytes == 0) { // EOF
        return 0;
    } else {
        return 1;
    }
}

int main(void) {

    int pid1, pid2;
    int fd1[2], fd2[2], fd3[2], fd4[2];
    char buf1[BUF_SIZE], buf2[BUF_SIZE], buf3[BUF_SIZE], buf4[BUF_SIZE];
    ssize_t nread;

    // Create pipes
    if (pipe(fd1) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    if (pipe(fd2) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    if (pipe(fd3) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    if (pipe(fd4) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork first child process
    pid1 = fork();
    if (pid1 == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    // First child process writes to fd1 and reads from fd2
    if (pid1 == 0) {
        close(fd1[0]); // Close read end of fd1
        close(fd2[1]); // Close write end of fd2

        char *message1 = "I am the first child process.";
        if (send_message(fd1[1], message1) == -1) {
            exit(EXIT_FAILURE);
        }

        if (receive_message(fd2[0], buf2) == 1) {
            printf("First child process received message from second child process: %s\n", buf2);
        } else {
            exit(EXIT_FAILURE);
        }

        close(fd1[1]);
        close(fd2[0]);
        exit(EXIT_SUCCESS);
    }

    // Fork second child process
    pid2 = fork();
    if (pid2 == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    // Second child process reads from fd1 and writes to fd2
    if (pid2 == 0) {
        close(fd1[1]); // Close write end of fd1
        close(fd2[0]); // Close read end of fd2

        if (receive_message(fd1[0], buf1) == 1) {
            printf("Second child process received message from first child process: %s\n", buf1);
        } else {
            exit(EXIT_FAILURE);
        }

        char *message2 = "I am the second child process.";
        if (send_message(fd2[1], message2) == -1) {
            exit(EXIT_FAILURE);
        }

        close(fd1[0]);
        close(fd2[1]);
        exit(EXIT_SUCCESS);
    }

    // Parent process closes unused pipe endpoints
    close(fd1[1]);
    close(fd1[0]);

    close(fd2[1]);
    close(fd2[0]);

    close(fd3[1]);
    close(fd4[0]);

    // Set up signal handler
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    // Wait for child processes to finish
    int status;
    if (waitpid(pid1, &status, 0) == -1) {
        perror("waitpid");
        exit(EXIT_FAILURE);
    }

    if (waitpid(pid2, &status, 0) == -1) {
        perror("waitpid");
        exit(EXIT_FAILURE);
    }

    // Open file for reading
    int fd_input = open("input.txt", O_RDONLY);
    if (fd_input == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Open file for writing
    int fd_output = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd_output == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Read from file and write to pipe
    while ((nread = read(fd_input, buf3, BUF_SIZE)) > 0) {
        if (write(fd3[1], buf3, nread) == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }
    }

    if (nread == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    close(fd3[1]);

    // Read from pipe and write to file
    while (receive_message(fd4[0], buf4) == 1) {
        if (write(fd_output, buf4, strlen(buf4)) == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }
    }

    if (received_signal == SIGUSR1) {
        printf("Program executing in paranoid mode.\n");
    } else {
        printf("Program executing in normal mode.\n");
    }

    close(fd_input);
    close(fd_output);
    close(fd3[0]);
    close(fd4[1]);

    exit(EXIT_SUCCESS);
}