//FormAI DATASET v1.0 Category: System administration ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void sigint_handler(int signum) {
    printf("Received signal %d, exiting...\n", signum);
    exit(signum);
}

void child_process() {
    printf("I am the child process with ID %d\n", getpid());
    sleep(10);
    printf("Child process completed.\n");
}

void parent_process(pid_t child_pid) {
    printf("I am the parent process with ID %d and my child has id %d\n", getpid(), child_pid);
    sleep(5);
    printf("Parent process completed.\n");
}

int main() {
    pid_t child_pid;
    int status;
    printf("Starting program...\n");
    signal(SIGINT, sigint_handler);
    child_pid = fork();
    if (child_pid == -1) {
        printf("Error forking child process\n");
        return 1;
    } else if (child_pid == 0) {
        // Child process
        child_process();
        exit(0);
    } else {
        // Parent process
        parent_process(child_pid);
        waitpid(child_pid, &status, 0);
        if (WIFSIGNALED(status)) {
            printf("Child process terminated by signal %d\n", WTERMSIG(status));
        } else {
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        }
        return 0;
    }
}