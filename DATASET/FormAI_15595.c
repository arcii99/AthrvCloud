//FormAI DATASET v1.0 Category: System administration ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    char command[100];
    printf("Enter the command you want to execute: ");
    fgets(command, 100, stdin);

    // Remove the newline character at the end of the command string
    command[strcspn(command, "\n")] = 0;

    pid_t pid = fork();

    if (pid == -1) {
        printf("Error: Failed to fork process.\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Executing Command: %s\n", command);
        execlp(command, command, NULL);
        printf("Error: Failed to execute command.\n");
        exit(1);
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
        printf("Command has finished executing.\n");
    }

    return 0;
}