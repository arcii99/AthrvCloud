//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: romantic
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 100

int main(void) {
    char cmd[MAX_CMD_LENGTH];

    while(1) {
        printf("$ ");
        fgets(cmd, MAX_CMD_LENGTH, stdin);
        cmd[strcspn(cmd, "\n")] = '\0';

        if(strcmp(cmd, "exit") == 0) {
            printf("Goodbye!\n");
            exit(0);
        }

        pid_t pid = fork();

        if(pid == -1) {
            perror("fork() failed");
            exit(1);
        } else if(pid == 0) {
            char* const argv[] = {"/bin/sh", "-c", cmd, NULL};
            execv("/bin/sh", argv);
            perror("execv() failed");
            exit(1);
        } else {
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}