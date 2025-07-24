//FormAI DATASET v1.0 Category: Interprocess communication ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    pid_t pid;
    char buf[256];

    if(pipe(pipefd) != 0) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if(pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if(pid == 0) {
        // Child process
        close(pipefd[0]); // Close reading end
        char *message = "Hello Parent Process!";
        write(pipefd[1], message, sizeof(message));
        exit(EXIT_SUCCESS);

    } else {
        // Parent process
        close(pipefd[1]); // Close writing end
        wait(NULL); // Wait for child process to complete

        read(pipefd[0], buf, 256);
        printf("Child says: %s", buf);

        close(pipefd[0]);
        exit(EXIT_SUCCESS);
    }

    return 0;
}