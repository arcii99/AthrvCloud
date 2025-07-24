//FormAI DATASET v1.0 Category: Interprocess communication ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MESSAGE "Hello, Interprocess Communication!"

int main(int argc, char *argv[]) {
    pid_t pid;
    int pipefd[2];
    char buffer[BUFFER_SIZE];
    int nbytes;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {  /* Child reads from pipe */
        close(pipefd[1]); /* Close unused write end */

        while ((nbytes = read(pipefd[0], buffer, BUFFER_SIZE)) > 0) {
            if (write(STDOUT_FILENO, buffer, nbytes) != nbytes) {
                fprintf(stderr, "child: write error: %s\n", strerror(errno));
                exit(EXIT_FAILURE);
            }
        }

        if (nbytes == -1) {
            fprintf(stderr, "child: read error: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }

        write(STDOUT_FILENO, "\n", 1);
        close(pipefd[0]);
        _exit(EXIT_SUCCESS);

    } else { /* Parent writes MESSAGE to pipe */
        close(pipefd[0]); /* Close unused read end */

        ssize_t size = write(pipefd[1], MESSAGE, strlen(MESSAGE));
        if (size == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        printf("Wrote %ld bytes to pipe.\n", size);
        close(pipefd[1]); /* Reader will see EOF */
        wait(NULL);
        exit(EXIT_SUCCESS);
    }
}