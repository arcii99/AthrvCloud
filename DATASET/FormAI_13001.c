//FormAI DATASET v1.0 Category: System administration ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    pid_t pid;
    int status;

    if (argc < 2) {
        printf("Usage: ./sys-admin <command>\n");
        exit(1);
    }

    pid = fork();

    if (pid == 0) {
        execvp(argv[1], &argv[1]);
        perror("execvp");
        exit(2);
    } else if (pid < 0) {
        perror("fork");
        exit(3);
    } else {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            printf("Command exited successfully\n");
        } else {
            printf("Command exited with error\n");
        }
    }
    
    return 0;
}