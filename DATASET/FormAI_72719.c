//FormAI DATASET v1.0 Category: System administration ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    pid_t pid;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <command>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        execvp(argv[1], &argv[1]);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else {
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            printf("%s exited with status %d\n", argv[1], WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("%s killed by signal %d\n", argv[1], WTERMSIG(status));
        } else if (WIFSTOPPED(status)) {
            printf("%s stopped by signal %d\n", argv[1], WSTOPSIG(status));
        } else {
            printf("%s unknown error", argv[1]);
        }

        exit(EXIT_SUCCESS);
    }
}