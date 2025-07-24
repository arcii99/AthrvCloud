//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10 // maximum number of arguments in command
#define MAX_LENGTH 100 // maximum length of input string

void displayPrompt() {
    printf("\n[FutureShell] > ");
}

void getInput(char* input) {
    fgets(input, MAX_LENGTH, stdin);
}

int tokenizeInput(char* input, char** tokens) {
    int tokenCount = 0;
    char* token = strtok(input, " ");

    while(token != NULL) {
        tokens[tokenCount] = token;
        tokenCount++;
        token = strtok(NULL, " ");

        if(tokenCount > MAX_ARGS) {
            fprintf(stderr, "Error: Too many arguments. Please input less than %d arguments.\n", MAX_ARGS);
            return -1;
        }
    }

    return tokenCount;
}

void executeCommand(char** tokens, int tokenCount) {
    pid_t pid = fork();

    if(pid < 0) {
        fprintf(stderr, "Error: Fork failed.\n");
        exit(EXIT_FAILURE);
    } else if(pid == 0) {
        // child process
        if(execvp(tokens[0], tokens) < 0) {
            fprintf(stderr, "Error: Failed to execute command.\n");
            exit(EXIT_FAILURE);
        }
    } else {
        // parent process
        int status;
        waitpid(pid, &status, 0);
    }
}

int main() {
    char input[MAX_LENGTH];
    char* tokens[MAX_ARGS];
    int tokenCount;

    while(1) {
        displayPrompt();
        getInput(input);
        tokenCount = tokenizeInput(input, tokens);

        if(tokenCount < 0) {
            continue;
        }

        if(tokenCount == 0) {
            continue;
        }

        if(strcmp(tokens[0], "exit") == 0) {
            break;
        }

        executeCommand(tokens, tokenCount);
    }

    return 0;
}