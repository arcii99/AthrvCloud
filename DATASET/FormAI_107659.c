//FormAI DATASET v1.0 Category: System administration ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int main() {
    pid_t pid, child;
    int status;

    pid = fork();

    if (pid == -1) {
        printf("Error: Could not create child process.\n");
        exit(1);
    }
    else if (pid == 0) {
        // Child process
    
        printf("The child process (PID %d) is starting.\n", getpid());

        // Set up signal handling
        struct sigaction new_handler;
        new_handler.sa_handler = SIG_IGN;
        sigemptyset(&new_handler.sa_mask);
        new_handler.sa_flags = 0;
        sigaction(SIGINT, &new_handler, NULL);

        printf("The child process (PID %d) is running.\n", getpid());

        // Simulate work
        sleep(10);

        printf("The child process (PID %d) is terminating.\n", getpid());
        exit(0);
    }

    // Parent process
    printf("The parent process (PID %d) is waiting for child process to finish.\n", getpid());

    child = wait(&status);

    if (child == -1) {
        printf("Error: Could not wait for child process.\n");
        exit(1);
    }

    if (WIFEXITED(status)) {
        printf("The child process (PID %d) exited normally with status %d.\n", pid, WEXITSTATUS(status));
    }
    else if (WIFSIGNALED(status)) {
        int sig = WTERMSIG(status);
        printf("The child process (PID %d) was terminated by signal %d (%s).\n", pid, sig, strsignal(sig));
    }
    else {
        printf("The child process (PID %d) exited abnormally.\n", pid);
    }

    return 0;
}