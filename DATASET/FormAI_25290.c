//FormAI DATASET v1.0 Category: System administration ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define ARG_SIZE 10

void displayMenu();
void parseCommand(char *input, char **args);
void executeCommand(char **args);

int main() {
    char input[ARG_SIZE*MAX_ARGS];
    char *args[MAX_ARGS];

    while(1) {
        displayMenu();

        fgets(input, sizeof(input), stdin);
        parseCommand(input, args);

        executeCommand(args);
    }
}

void displayMenu() {
    printf(">> ");
}

void parseCommand(char *input, char **args) {
    int i = 0;
    char *token = strtok(input, " \n");

    while(token != NULL) {
        args[i] = token;
        token = strtok(NULL, " \n");
        i++;
    }

    args[i] = NULL;
}

void executeCommand(char **args) {
    pid_t pid = fork();

    if(pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if(pid == 0) {
        if(execvp(args[0], args) == -1) {
            perror("execvp");
        }
        exit(EXIT_FAILURE);
    }

    int status;
    if(waitpid(pid, &status, 0) == -1) {
        perror("waitpid");
        exit(EXIT_FAILURE);
    }
}

//TODO: Add puzzling features to this program!