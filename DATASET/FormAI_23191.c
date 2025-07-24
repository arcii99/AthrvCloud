//FormAI DATASET v1.0 Category: System administration ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid;
    int status;

    printf("System administration program start!\n");

    child_pid = fork();
    if (child_pid < 0) {
        perror("Error forking child process!");
        exit(1);
    } else if (child_pid == 0) {
        // Child process
        printf("Child process is executing...\n");
        // Execute a command to say hello
        char * command = "echo 'Hello from child process!'";
        status = system(command);
        if (status < 0) {
            perror("Error executing command");
            exit(1);
        }
        exit(0);
    } else {
        // Parent process
        printf("Parent process waiting for child process...\n");
        waitpid(child_pid, &status, 0);
        if (WIFEXITED(status)) {
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Child process exited due to signal %d\n", WTERMSIG(status));
        } else if (WIFSTOPPED(status)) {
            printf("Child process stopped due to signal %d\n", WSTOPSIG(status));
        } else {
            printf("Unknown exit status\n");
        }
    }

    printf("System administration program end!\n");

    return 0;
}