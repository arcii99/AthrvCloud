//FormAI DATASET v1.0 Category: System administration ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid, wpid;
    int status;

    // Fork a child process
    pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child process running...\n");
        execl("/bin/ls", "ls", "-la", NULL);
        perror("exec");
        exit(1);
    } else if (pid < 0) {
        // Fork failed
        perror("fork");
        exit(1);
    } else {
        // Parent process
        printf("Parent process waiting for child...\n");
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
            if (wpid == -1) {
                perror("waitpid");
                exit(1);
            }
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        printf("Parent process exiting...\n");
    }

    return 0;
}