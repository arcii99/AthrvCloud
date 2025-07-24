//FormAI DATASET v1.0 Category: System boot optimizer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAXLINE 256

int main(int argc, char *argv[]) {

    int opt;
    int verbose = 0;

    while ((opt = getopt(argc, argv, "v")) != -1) {
        switch (opt) {
            case 'v':
                verbose = 1;
                break;
            default:
                fprintf(stderr, "Usage: %s [-v]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        if (verbose) {
            printf("Optimizing system boot sequence...\n");
        }
        // Open file for writing system boot sequence
        int fd = open("/etc/systemd/system.conf", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }
        // Write optimized settings to file
        char buf[MAXLINE];
        int n = sprintf(buf, "DefaultTimeoutStartSec=10\nDefaultTimeoutStopSec=10\n");
        int m = write(fd, buf, n);
        if (m == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }
        close(fd);
        // Exit child process
        _exit(EXIT_SUCCESS);
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
        if (verbose) {
            printf("System boot sequence optimized successfully!\n");
        }
        exit(EXIT_SUCCESS);
    }
}