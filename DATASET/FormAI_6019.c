//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

void shellPrompt() {
    printf("\n> ");
}

void executeCommand(char **args) {
    pid_t pid = fork();
    char *path = "/bin/";
    char *fullPath = malloc(strlen(path) + strlen(args[0]) + 1);
    strcpy(fullPath, path);
    strcat(fullPath, args[0]);

    if (pid == 0) {
        if (execvp(fullPath, args) == -1) {
            printf("Error: Command could not be executed.\n");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        printf("Error: Forking process failed.\n");
    } else {
        wait(NULL);
    }
    free(fullPath);
}

void parseArguments(char *input, char **args) {
    char *arg;
    int index = 0;

    arg = strtok(input," ");

    while (arg != NULL) {
        args[index] = arg;
        index++;
        arg = strtok(NULL, " ");
    }
    args[index] = NULL;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char *args[MAX_ARGUMENTS];
    int shouldRun = 1;

    while (shouldRun) {
        shellPrompt();

        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            shouldRun = 0;
        }
        else {
            parseArguments(input, args);
            executeCommand(args);
        }
    }
    return EXIT_SUCCESS;
}