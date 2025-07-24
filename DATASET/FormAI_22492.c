//FormAI DATASET v1.0 Category: System administration ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int status;
    printf("Hello! I am a system administrator.\n");

    pid_t pid = fork(); // Create a child process
    if (pid < 0) { // Fork failed
        perror("fork failed");
        exit(1);
    } else if (pid == 0) { // Child process
        printf("I am the child process (PID %d).\n", getpid());
        printf("My parent process is (PID %d).\n", getppid());

        // Simulate some CPU work
        int i;
        for (i = 0; i < 1000000; i++) {}

        printf("Child process finished its work.\n");
        exit(0);
    } else { // Parent process
        printf("I am the parent process (PID %d).\n", getpid());
        printf("My child process is (PID %d).\n", pid);

        // Check CPU usage
        system("mpstat 1 1");

        // Wait for child process to finish
        waitpid(pid, &status, 0);

        // Check memory usage
        system("free -m");

        printf("Parent process finished.\n");
    }

    return 0;
}