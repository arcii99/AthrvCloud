//FormAI DATASET v1.0 Category: System administration ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid;
    int status;

    /* Create child process */
    child_pid = fork();

    if(child_pid == 0) {
        /* This is the child process */
        printf("Executing command as root user...\n");
        execl("/usr/bin/sudo", "sudo", "apt-get", "update", NULL);
    } else if(child_pid > 0) {
        /* This is the parent process */
        waitpid(child_pid, &status, 0);
        if(WIFEXITED(status)) {
            printf("Command executed successfully!\n");
        } else {
            printf("Error: Command did not execute successfully. Please try again.\n");
        }
    } else {
        /* Error forking */
        printf("Error: Unable to fork child process. Please try again.\n");
        exit(1);
    }

    return 0;
}