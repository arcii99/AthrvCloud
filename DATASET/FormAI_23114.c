//FormAI DATASET v1.0 Category: System administration ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    int pid, status;
    char cmd[100], buffer[1000];

    printf("Enter a command to execute: ");
    fgets(cmd, sizeof(cmd), stdin);

    // Remove newline character
    if (cmd[strlen(cmd)-1] == '\n') {
        cmd[strlen(cmd)-1] = '\0';
    }

    // Fork the process to execute the command
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        if (execlp(cmd, cmd, (char*)NULL) < 0) {
            perror("execlp");
            exit(1);
        }
    } else {
        // Parent process
        wait(&status);

        if (WIFEXITED(status)) {
            printf("Command execution successful.\n");
        } else {
            printf("Command execution failed.\n");
        }
    }

    return 0;
}