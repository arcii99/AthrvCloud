//FormAI DATASET v1.0 Category: System administration ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid;
    int status;

    printf("Starting admin task...\n");

    child_pid = fork();

    if (child_pid == -1) {
        perror("Error creating new process");
        exit(1);
    } else if (child_pid == 0) {
        // Child process
        printf("Running updates...\n");
        execl("/usr/bin/apt-get", "apt-get", "update", NULL);
        perror("Error running updates");
        exit(1);
    } else {
        // Parent process
        waitpid(child_pid, &status, 0);
        if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
            printf("Updates completed successfully.\n");
            printf("Checking for available upgrades...\n");
            execl("/usr/bin/apt-get", "apt-get", "upgrade", "-s", NULL);
            perror("Error checking for upgrades");
            exit(1);
        } else {
            printf("Update process failed.\n");
            exit(1);
        }
    }

    return 0;
}