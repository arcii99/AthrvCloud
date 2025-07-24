//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

char** tokenizeInput(char* input) {
    int index = 0;
    char** tokens = malloc(sizeof(char*) * MAX_ARGUMENTS);
    char* token = strtok(input, " ");

    while (token != NULL) {
        tokens[index++] = token;
        token = strtok(NULL, " ");
    }

    tokens[index] = NULL;
    return tokens;
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    while(1) {
        printf("myshell$ ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        strtok(command, "\n");

        if (strcmp(command, "exit") == 0) {
            exit(0);
        }

        pid_t pid = fork();
        if (pid == 0) {
            char** args = tokenizeInput(command);
            if (execvp(args[0], args) < 0) {
                printf("Command not found.\n");
            }
        }
        else {
            wait(NULL);
        }
    }

    return 0;
}