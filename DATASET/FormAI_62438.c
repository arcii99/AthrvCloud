//FormAI DATASET v1.0 Category: System administration ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    // create child process
    pid_t pid = fork();

    if (pid == -1) {
        // fork failed
        fprintf(stderr, "Error: failed to create child process.\n");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // child process
        printf("Child process is running (PID %d)\n", getpid());

        // execute system command to get CPU information
        char* command = "cat /proc/cpuinfo";
        system(command);

        exit(EXIT_SUCCESS);
    } else {
        // parent process
        printf("Parent process is waiting for child process to finish.\n");

        // wait for child process to finish
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            // child process exited normally
            printf("Child process exited with status %d.\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            // child process terminated by a signal
            printf("Child process terminated by signal %d.\n", WTERMSIG(status));
        } else {
            fprintf(stderr, "Error: unknown child process status.\n");
        }
    }

    return 0;
}