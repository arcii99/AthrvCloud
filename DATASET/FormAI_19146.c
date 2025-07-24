//FormAI DATASET v1.0 Category: System administration ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    pid_t child_pid;
    int iteration_count = 0;

    if (argc == 1) {
        printf("Usage: %s <command> [args]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    while (1) {
        child_pid = fork();
        if (child_pid == -1) {
            perror("fork error");
            exit(EXIT_FAILURE);
        }
        else if (child_pid == 0) {
            /* Child process */
            execvp(argv[1], &argv[1]);
            /* If execvp returns, there was an error */
            perror("execvp error");
            exit(EXIT_FAILURE);
        }
        else {
            /* Parent process */
            if (wait(NULL) == -1) {
                perror("wait error");
                exit(EXIT_FAILURE);
            }
            iteration_count++;
            printf("Command execution successful, iteration count: %d\n", iteration_count);
            sleep(5);
        }
    }

    exit(EXIT_SUCCESS);
}