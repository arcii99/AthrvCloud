//FormAI DATASET v1.0 Category: System administration ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    char command[100];
    printf("Enter command to execute: ");
    fgets(command, sizeof(command), stdin); // Read command from stdin

    // Replace newline character with null character
    command[strlen(command) - 1] = '\0'; 

    char *args[20];
    int argCount = 0;

    // Tokenize the command string into arguments
    char *token = strtok(command, " ");
    while (token != NULL) {
        args[argCount++] = token;
        token = strtok(NULL, " ");
    }
    args[argCount] = NULL;

    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        execvp(args[0], args);
        printf("Command not found!\n");
        exit(1);
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
        printf("Command executed successfully!\n");
    }

    return 0;
}