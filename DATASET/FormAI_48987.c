//FormAI DATASET v1.0 Category: Interprocess communication ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    int pipe_fd[2];
    pid_t pid;

    char buf[256];
    int nbytes;
    
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    // parent process
    if (pid > 0) {
        close(pipe_fd[0]);

        // write message to child process
        char message[] = "Hello from parent process.\n";
        write(pipe_fd[1], message, strlen(message));
        close(pipe_fd[1]);

        wait(NULL);
        exit(EXIT_SUCCESS);
    }

    // child process
    if (pid == 0) {
        close(pipe_fd[1]);

        // read message from parent process
        nbytes = read(pipe_fd[0], buf, sizeof(buf));
        printf("Received message from parent process: %s", buf);
        close(pipe_fd[0]);

        exit(EXIT_SUCCESS);
    }
}