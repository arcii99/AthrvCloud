//FormAI DATASET v1.0 Category: System administration ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Create a child process to run the command
    pid_t pid = fork();

    if (pid == -1) {
        // An error occurred while forking
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // In the child process, run the command
        execlp("ls", "ls", "-la", NULL);
        // If execlp returns, an error occurred
        perror("execlp failed");
        exit(EXIT_FAILURE);
    } else {
        // In the parent process, wait for the child to finish
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            printf("Command exited with status %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Command terminated by signal %d\n", WTERMSIG(status));
        } else {
            printf("Command exited for unknown reason\n");
        }
    }

    return EXIT_SUCCESS;
}