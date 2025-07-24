//FormAI DATASET v1.0 Category: Log analysis ; Style: interoperable
// Example program for analyzing log files
// Interoperable style using POSIX functions

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int fd, n;
    char buffer[BUF_SIZE];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <logfile>\n", argv[0]);
        return EXIT_FAILURE;
    }

    fd = open(argv[1], O_RDONLY);

    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    // Read log file line by line
    while ((n = read(fd, buffer, BUF_SIZE)) > 0) {
        for (int i = 0; i < n; i++) {
            if (buffer[i] == '\n') {
                printf("Found a line: ");
                write(STDOUT_FILENO, buffer, i + 1);  // Write line to stdout
            }
        }
    }

    if (n == -1) {
        perror("read");
        return EXIT_FAILURE;
    }

    if (close(fd) == -1) {
        perror("close");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}