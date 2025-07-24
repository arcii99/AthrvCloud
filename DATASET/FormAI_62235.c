//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main() {
    int fds[2];
    pid_t pid;

    char message[] = "Hello, World!\n";
    char buffer[80];

    if (pipe(fds) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        /* child process */
        close(fds[1]);

        if (read(fds[0], buffer, sizeof(buffer)) == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        printf("Child read: %s", buffer);

        close(fds[0]);
        exit(EXIT_SUCCESS);

    } else {
        /* parent process */
        close(fds[0]);

        if (write(fds[1], message, sizeof(message)) == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        printf("Parent wrote: %s", message);

        close(fds[1]);
        exit(EXIT_SUCCESS);
    }

    return 0;
}