//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 100
#define MAX_ARGS 10

int main() {
    char cmd[MAX_CMD_LEN];
    char* args[MAX_ARGS];
    int status;
    pid_t pid;

    while (1) {
        // prompt user for command
        printf("myShell$ ");
        fgets(cmd, MAX_CMD_LEN, stdin);
        
        // tokenize command
        int i = 0;
        args[i] = strtok(cmd, " \n");
        while(args[i] != NULL && i < MAX_ARGS - 1) {
            i++;
            args[i] = strtok(NULL, " \n");
        }
        args[i] = NULL;

        // fork process and execute command
        pid = fork();
        if (pid < 0) {
            printf("fork error\n");
            exit(1);
        } else if (pid == 0) {
            // child process
            execvp(args[0], args);
            printf("myShell: command not found: %s\n", args[0]);
            exit(1);
        } else {
            // parent process
            wait(&status);
        }
    }

    return 0;
}