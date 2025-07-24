//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>

#define BUFFER_SIZE 32

volatile sig_atomic_t stop;

void interrupt_handler(int signum) {
    stop = 1;
}

unsigned int checksum(char *file_path) {
    int fd = open(file_path, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    unsigned int cksum = 0;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        for (ssize_t i = 0; i < bytes_read; i++) {
            cksum += (unsigned int) buffer[i];
        }
        if (stop) {
            break;
        }
    }

    if (bytes_read == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    if (close(fd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }

    return cksum;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (signal(SIGINT, interrupt_handler) == SIG_ERR) {
        perror("signal");
        return EXIT_FAILURE;
    }

    unsigned int cksum = 0;
    pid_t child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        return EXIT_FAILURE;
    }

    if (child_pid == 0) {
        // Child process
        printf("Calculating checksum...\n");
        cksum = checksum(argv[1]);
        printf("Checksum: %u\n", cksum);
    } else {
        // Parent process
        sleep(1);
        printf("Press Ctrl-C to stop\n");
        waitpid(child_pid, NULL, 0);
    }

    return EXIT_SUCCESS;
}