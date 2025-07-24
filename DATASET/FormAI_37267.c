//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_NUMBER_OF_ARGUMENTS 10

void printPrompt();
void parseCommand(char* commandString, char** arguments);
void executeCommand(char** arguments);

int main() {
    char commandString[MAX_COMMAND_LENGTH];
    char* arguments[MAX_NUMBER_OF_ARGUMENTS + 1];  // + 1 for the terminating NULL pointer

    while (1) {
        printPrompt();
        fgets(commandString, MAX_COMMAND_LENGTH, stdin);
        parseCommand(commandString, arguments);
        executeCommand(arguments);
    }

    return 0;
}

void printPrompt() {
    printf("myShell> ");
}

void parseCommand(char* commandString, char** arguments) {
    int argumentCount = 0;
    char* token = strtok(commandString, " \n");

    while (token != NULL && argumentCount < MAX_NUMBER_OF_ARGUMENTS) {
        arguments[argumentCount] = token;
        argumentCount++;
        token = strtok(NULL, " \n");
    }

    arguments[argumentCount] = NULL;  // Add a terminating NULL pointer
}

void executeCommand(char** arguments) {
    pid_t pid = fork();  // Create a child process

    if (pid == -1) {
        perror("fork");  // Failed to create a child process
    } else if (pid == 0) {
        // Child process
        if (execvp(arguments[0], arguments) == -1) {
            // The specified command doesn't exist or failed to execute
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
    }
}