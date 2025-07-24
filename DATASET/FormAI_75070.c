//FormAI DATASET v1.0 Category: Interprocess communication ; Style: introspective
/*
 * This program demonstrates interprocess communication using named pipes in C.
 * The main process creates a child process and establishes a bidirectional communication channel between them.
 * The child process then sends a message to the parent process, which echoes it back to the child.
 * The child process then sends another message to the parent process, which echoes it back to the child.
 * The child process then terminates, and the parent process cleans up the resources.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/stat.h>

#define PIPE_NAME "/tmp/my_fifo"

int main(int argc, char *argv[]) {
    int status;
    int fd;
    char buffer[BUFSIZ];
    pid_t pid;
    struct sigaction sa;

    umask(0);

    if (mkfifo(PIPE_NAME, 0666) < 0) {
        perror("mkfifo()");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid == -1) {
        perror("fork()");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        fd = open(PIPE_NAME, O_WRONLY);

        if (fd == -1) {
            perror("open()");
            exit(EXIT_FAILURE);
        }

        strncpy(buffer, "Hello, parent!", BUFSIZ);

        if (write(fd, buffer, BUFSIZ) == -1) {
            perror("write()");
            exit(EXIT_FAILURE);
        }

        strncpy(buffer, "How are you?", BUFSIZ);

        if (write(fd, buffer, BUFSIZ) == -1) {
            perror("write()");
            exit(EXIT_FAILURE);
        }

        close(fd);

        exit(EXIT_SUCCESS);
    }

    fd = open(PIPE_NAME, O_RDONLY);

    if (fd == -1) {
        perror("open()");
        exit(EXIT_FAILURE);
    }

    sa.sa_handler = SIG_IGN;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGPIPE, &sa, NULL) == -1) {
        perror("sigaction()");
        exit(EXIT_FAILURE);
    }

    if (read(fd, buffer, BUFSIZ) == -1) {
        perror("read()");
        exit(EXIT_FAILURE);
    }

    printf("Parent received message: '%s'\n", buffer);

    if (read(fd, buffer, BUFSIZ) == -1) {
        perror("read()");
        exit(EXIT_FAILURE);
    }

    printf("Parent received message: '%s'\n", buffer);

    close(fd);

    if ((status = system("rm " PIPE_NAME)) == -1) {
        perror("system()");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}