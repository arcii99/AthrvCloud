//FormAI DATASET v1.0 Category: System administration ; Style: scalable
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid1, pid2, status;

    // fork first child process
    pid1 = fork();
    if (pid1 < 0) {
        perror("Error forking first child process");
        exit(EXIT_FAILURE);
    } else if (pid1 == 0) {
        // first child process
        printf("First child process started\n");
        execl("/bin/ls", "ls", "-l", NULL);
        perror("execl failed");
        exit(EXIT_FAILURE);
    } else {
        // parent process
        printf("Parent process waiting for first child to finish\n");
        waitpid(pid1, &status, 0);
        printf("First child process finished\n");

        // fork second child process
        pid2 = fork();
        if (pid2 < 0) {
            perror("Error forking second child process");
            exit(EXIT_FAILURE);
        } else if (pid2 == 0) {
            // second child process
            printf("Second child process started\n");
            execl("/bin/ping", "ping", "google.com", NULL);
            perror("execl failed");
            exit(EXIT_FAILURE);
        } else {
            // parent process
            printf("Parent process waiting for second child to finish\n");
            waitpid(pid2, &status, 0);
            printf("Second child process finished\n");
        }
    }

    return 0;
}