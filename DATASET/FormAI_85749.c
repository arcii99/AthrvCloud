//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

char *read_input(void);
char **tokenize(char *line);
void execute(char **tokens);

int main(int argc, char **argv) {
    // Start the shell and prompt the user for input
    while (1) {
        char *line = read_input();
        char **tokens = tokenize(line);
        execute(tokens);

        // Free memory used for input and tokens array
        free(line);
        free(tokens);
    }

    return 0;
}

char *read_input(void) {
    char *line = NULL;
    size_t bufsize = 0;
    
    // Read input from user
    getline(&line, &bufsize, stdin);
    return line;
}

char **tokenize(char *line) {
    int token_count = 0;
    char **tokens = malloc(MAX_NUM_TOKENS * sizeof(char *));
    char *token = strtok(line, " \t\r\n\a");

    // Split input into tokens
    while (token != NULL && token_count < MAX_NUM_TOKENS) {
        tokens[token_count] = token;
        token_count++;
        token = strtok(NULL, " \t\r\n\a");
    }
    tokens[token_count] = NULL;
    return tokens;
}

void execute(char **tokens) {
    pid_t pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Error creating child process\n");
        return;
    } else if (pid == 0) {
        // Child process executing the command provided
        execvp(tokens[0], tokens);
        fprintf(stderr, "Error executing command\n");
        exit(EXIT_FAILURE);
    } else {
        // Parent process waiting for child process to complete
        int status;
        waitpid(pid, &status, 0);
    }
}