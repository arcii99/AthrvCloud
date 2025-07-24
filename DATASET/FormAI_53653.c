//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 100
#define MAX_LINE 1024

int main(void)
{
    char line[MAX_LINE];
    char* args[MAX_ARGS];

    while (1) {
        printf("$ ");
        fgets(line, MAX_LINE, stdin);

        // Replace newline character with null terminator
        line[strcspn(line, "\n")] = '\0';

        // Split command into individual arguments
        char* token = strtok(line, " ");
        int i = 0;
        while (token != NULL && i < MAX_ARGS) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        // Fork process and exec command
        pid_t pid;
        int status;

        if ((pid = fork()) == 0) {
            execvp(args[0], args);
            printf("%s: command not found\n", args[0]);
            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            printf("fork error\n");
            exit(EXIT_FAILURE);
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return EXIT_SUCCESS;
}