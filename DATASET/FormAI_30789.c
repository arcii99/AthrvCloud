//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_CMD_LEN 100
#define MAX_NUM_ARGS 10

int main(void) {
    char command[MAX_CMD_LEN];
    char *args[MAX_NUM_ARGS];
    int i, numArgs;

    while (1) {
        printf("> ");
        fgets(command, MAX_CMD_LEN, stdin);
        numArgs = 0;
        args[numArgs] = strtok(command, " \n");
        while (args[numArgs] != NULL && numArgs < MAX_NUM_ARGS) {
            numArgs++;
            args[numArgs] = strtok(NULL, " \n");
        }
        if (args[0] == NULL) {
            continue;
        }
        if (strcmp(args[0], "exit") == 0) {
            exit(0);
        }
        if (fork() == 0) {
            execvp(args[0], args);
            printf("Error: invalid command\n");
            exit(1);
        }
        wait(NULL);
    }
    return 0;
}