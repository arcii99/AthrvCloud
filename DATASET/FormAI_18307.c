//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

void worker(int pipefd[2])
{
    char buffer[BUFFER_SIZE];
    int nbytes;

    close(pipefd[1]);

    while ((nbytes = read(pipefd[0], buffer, BUFFER_SIZE)) > 0) {
        buffer[nbytes] = '\0';

        // Do some CPU intensive work
        // ...

        printf("Worker processed: %s\n", buffer);
    }

    close(pipefd[0]);
}

int main(int argc, char **argv)
{
    int pipefd[2];
    pid_t pid;

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // child process
        worker(pipefd);
        exit(EXIT_SUCCESS);
    } else {
        // parent process
        close(pipefd[0]);

        // Generate some data to process
        for (int i = 0; i < 10; i++) {
            char buffer[BUFFER_SIZE];
            sprintf(buffer, "data_%d", i);
            write(pipefd[1], buffer, strlen(buffer));
        }

        close(pipefd[1]);

        // Wait for the child process to finish
        wait(NULL);
    }

    return 0;
}