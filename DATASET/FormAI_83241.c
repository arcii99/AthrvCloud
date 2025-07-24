//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: medieval
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 100
#define MAX_ARG_LENGTH 20

int main() {
    char cmd[MAX_CMD_LENGTH];
    char *args[MAX_ARG_LENGTH];
    pid_t pid;
    int status;

    printf("Hail and well met, adventurer! What dost thy command?\n");

    while (1) {
        printf("> "); // Display prompt
        fgets(cmd, MAX_CMD_LENGTH, stdin); // Read input command

        // Remove newline character and split command into arguments
        cmd[strcspn(cmd, "\n")] = 0; 
        char *ptr = strtok(cmd, " ");
        int i = 0;
        while (ptr != NULL && i < MAX_ARG_LENGTH) {
            args[i++] = ptr;
            ptr = strtok(NULL, " ");
        }
        args[i] = NULL;

        // Execute command in child process
        pid = fork();
        if (pid == -1) {
            printf("Error: Failed to fork.\n");
            exit(1);
        } else if (pid == 0) {
            execvp(args[0], args);
            printf("Error: Failed to execute command %s.\n", args[0]);
            exit(1);
        } else {
            // Wait for child process to finish
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}