//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_LEN 100

int main() {
    char input[MAX_LEN];
    char *args[MAX_ARGS];
    int status, i;
    pid_t pid;

    while (1) {
        printf("shell> ");
        fgets(input, MAX_LEN, stdin);
        input[strcspn(input, "\n")] = '\0'; // remove newline character from input

        // split input into array of arguments
        i = 0;
        args[i] = strtok(input, " ");
        while (args[i] != NULL && i < MAX_ARGS-1) {
            i++;
            args[i] = strtok(NULL, " ");
        }
        args[i+1] = NULL;

        if (strcmp(args[0], "exit") == 0) {
            break;
        }

        pid = fork();
        if (pid == -1) {
            printf("Error: failed to fork process.\n");
            exit(1);
        } else if (pid == 0) {
            execvp(args[0], args);
            printf("Error: failed to execute command %s.\n", args[0]);
            exit(1);
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}