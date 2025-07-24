//FormAI DATASET v1.0 Category: File handling ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <stdbool.h>

// Callback function to handle asynchronous file read completion
void read_cb(int signum) {
    printf("File read completed\n");
}

int main() {
    int fd, n;
    char buf[1024];

    // Open the file for reading only
    fd = open("example.txt", O_RDONLY);

    // Check if the file was successfully opened
    if (fd == -1) {
        perror("open()");
        exit(1);
    }

    // Register the signal handler for SIGIO signal
    struct sigaction sa;
    sa.sa_handler = read_cb;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    if (sigaction(SIGIO, &sa, NULL) == -1) {
        perror("sigaction()");
        exit(1);
    }

    // Enable asynchronous file access using F_SETOWN and F_SETFL fcntl calls
    if (fcntl(fd, F_SETOWN, getpid()) == -1) {
        perror("fcntl()");
        exit(1);
    }
    if (fcntl(fd, F_SETFL, O_ASYNC | O_NONBLOCK) == -1) {
        perror("fcntl()");
        exit(1);
    }

    // Issue asynchronous read on the file
    n = read(fd, buf, 1024);

    // Check if the read was successful
    if (n == -1 && errno != EAGAIN) {
        perror("read()");
        exit(1);
    }

    // Keep waiting for the SIGIO signal until it arrives
    bool sigio_received = false;
    while (!sigio_received) {
        pause();
        sigio_received = true;
    }

    // Print the content of file that was read asynchronously
    printf("File content:\n%s\n", buf);

    // Close the file
    if (close(fd) == -1) {
        perror("close()");
        exit(1);
    }

    return 0;
}