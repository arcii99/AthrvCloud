//FormAI DATASET v1.0 Category: System administration ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    pid_t pid;

    // Fork a child process
    pid = fork();

    if (pid < 0) {
        // Error occurred during forking
        fprintf(stderr, "Fork failed\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        char *args[] = {"/bin/date", NULL};
        execvp(args[0], args);
    } else {
        // Parent process
        // Wait for child to complete
        wait(NULL);
        printf("Child completed\n");
    }

    return 0;
}