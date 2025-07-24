//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_LENGTH 100

void execute(char **args) {
    pid_t pid;
    int status;
    pid = fork();
    if (pid == 0) {
        execvp(args[0], args);
        perror("execvp");
        exit(1);
    } else if (pid < 0) {
        perror("fork");
    } else {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

void parseCommand(char *command, char **args) {
    int i = 0;
    args[i] = strtok(command, " ");
    while (args[i] != NULL && i < MAX_ARGS - 1) {
        args[++i] = strtok(NULL, " ");
    }
}

int main() {
    char input[MAX_LENGTH];
    char *args[MAX_ARGS];
    while (1) {
        printf("Enter command: ");
        fgets(input, MAX_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0;
        parseCommand(input, args);
        if (strcmp(args[0], "exit") == 0) {
            exit(0);
        }
        execute(args);
    }
    return 0;
}