//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMDS 10
#define MAX_ARGS 20

int main() {
    char input[100];
    char* cmd_list[MAX_CMDS][MAX_ARGS + 1];
    int num_cmds = 0;

    while (1) {
        // Prompt for input and parse into commands
        printf("> ");
        fgets(input, 100, stdin);

        cmd_list[num_cmds][0] = strtok(input, " \n");
        int i = 1;
        while (cmd_list[num_cmds][i] = strtok(NULL, " \n")) {
            i++;
        }
        num_cmds++;

        // Execute commands in parallel
        int status;
        int pid;
        for (int i = 0; i < num_cmds; i++) {
            pid = fork();
            if (pid == -1) {
                printf("Failed to fork process.\n");
                exit(1);
            } else if (pid == 0) {
                // Child process: execute command
                execvp(cmd_list[i][0], cmd_list[i]);
                printf("Command not found.\n");
                exit(1);
            }
        }

        // Wait for all child processes to finish
        while (num_cmds > 0) {
            pid = wait(&status);
            printf("Process %d exited with status %d.\n", pid, status);
            num_cmds--;
        }
    }

    return 0;
}