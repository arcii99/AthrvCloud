//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARG_COUNT 10

int main() {
    char line[MAX_COMMAND_LENGTH];
    char* args[MAX_ARG_COUNT];

    while (1) {
        printf("$ ");
        fflush(stdout);

        if (!fgets(line, MAX_COMMAND_LENGTH, stdin)) break;

        if (line[strlen(line) - 1] == '\n') line[strlen(line) - 1] = '\0';

        pid_t pid = fork();
        if (pid < 0) {
            fprintf(stderr, "Fork failed\n");
        } else if (pid == 0) {
            int arg_count = 0;
            char* token = strtok(line, " ");
            while (token != NULL && arg_count < MAX_ARG_COUNT) {
                args[arg_count++] = token;
                token = strtok(NULL, " ");
            }
            args[arg_count] = NULL;

            if (execvp(args[0], args) == -1) {
                fprintf(stderr, "Execution failed\n");
            }

            exit(EXIT_FAILURE);
        } else {
            wait(NULL);
        }
    }

    return 0;
}