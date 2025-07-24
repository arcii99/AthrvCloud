//FormAI DATASET v1.0 Category: System administration ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

    int cpid = fork();
    if (cpid == -1) {
        perror("error in fork");
        exit(EXIT_FAILURE);
    }
    if (cpid == 0) {
        printf("Child process with PID: %d\n", getpid());
        printf("Setting up environment variables...\n");
        char *args[] = {"ls", "-la", NULL};
        if (execvp(args[0], args) < 0) {
            perror("error in exec");
            exit(EXIT_FAILURE);
        }
    } else {
        printf("Parent process with PID: %d\n", getpid());
        printf("Waiting for child process with PID: %d\n", cpid);
        int status;
        waitpid(cpid, &status, 0);
        if(WIFEXITED(status)) {
            printf("Child process exited with status: %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Child process killed by signal: %d\n", WTERMSIG(status));
        }
    }
    return 0;
}