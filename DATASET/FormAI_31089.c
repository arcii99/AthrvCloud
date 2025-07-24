//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

void execute(char **tokens) {
    pid_t pid = fork();
    if (pid == -1) {
        printf("Error: Unable to fork child process\n");
    } else if (pid == 0) {
        // Child process
        if (execvp(tokens[0], tokens) == -1) {
            printf("Error: Unable to execute command '%s'\n", tokens[0]);
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        wait(NULL);
    }
}

int main() {
    char input[MAX_INPUT_SIZE];
    char *tokens[MAX_NUM_TOKENS];
    char *token;
    int num_tokens;

    while(1) {
        printf("unix-like-shell> ");
        fgets(input, MAX_INPUT_SIZE, stdin);
        input[strcspn(input, "\n")] = 0; // Remove trailing newline character

        // Tokenize input
        num_tokens = 0;
        token = strtok(input, " ");

        while (token != NULL && num_tokens < MAX_NUM_TOKENS) {
            tokens[num_tokens] = token;
            num_tokens++;
            token = strtok(NULL, " ");
        }
        tokens[num_tokens] = NULL;

        // Handle empty input
        if (num_tokens == 0) continue;

        // Handle exit command
        if (strcmp(tokens[0], "exit") == 0) {
            exit(EXIT_SUCCESS);
        }

        // Execute command
        execute(tokens);
    }

    return 0;
}