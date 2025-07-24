//FormAI DATASET v1.0 Category: System administration ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define USERS 5

int main() {
    int i, pid;
    char username[12];

    printf("System administration example program.\n\n");

    // Create child processes for each user
    for(i = 1; i <= USERS; i++) {
        sprintf(username, "user%d", i);
        pid = fork();
        if(pid == 0) {
            // Child process
            printf("Creating account for %s...\n", username);
            execl("/usr/sbin/useradd", "useradd", username, NULL);
            printf("Failed to create account for %s.\n", username);
            exit(1);
        } else if(pid < 0) {
            // Error
            printf("Failed to create child process for %s.\n", username);
        } else {
            // Parent process
            waitpid(pid, NULL, 0);
        }
    }

    // Set up home directory
    printf("\nSetting up user home directories...\n");
    for(i = 1; i <= USERS; i++) {
        sprintf(username, "user%d", i);
        pid = fork();
        if(pid == 0) {
            // Child process
            chdir("/home");
            mkdir(username, 0777);
            chown(username, 0, 0);
            chmod(username, 0777);
            printf("Created home directory for %s.\n", username);
            exit(0);
        } else if(pid < 0) {
            // Error
            printf("Failed to create child process for %s.\n", username);
        } else {
            // Parent process
            waitpid(pid, NULL, 0);
        }
    }

    printf("\nComplete.\n");

    return 0;
}