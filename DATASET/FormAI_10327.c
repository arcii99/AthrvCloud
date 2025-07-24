//FormAI DATASET v1.0 Category: System administration ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    char *command = "shutdown -r now"; // command to restart the system
    int status;

    printf("Are you sure you want to restart the system? (y/n)\n");
    char option = getchar();

    if (option == 'y') {
        printf("Restarting the system...\n");

        pid_t pid = fork();
        if (pid == 0) {
            // child process
            system(command);
        } else if (pid > 0) {
            // parent process
            wait(&status);

            if (WIFEXITED(status)) {
                printf("System restarted successfully!\n");
            } else {
                printf("Error restarting the system...\n");
            }
        } else {
            // error forking process
            printf("Error forking process...\n");
            exit(1);
        }

    } else {
        printf("System restart aborted.\n");
    }

    return 0;
}