//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

int get_input(char *buf)
{
    printf("shell> ");
    return fgets(buf, MAX_INPUT_SIZE, stdin) != NULL;
}

void tokenize(char *input, char **tokens, int *num_tokens)
{
    *num_tokens = 0;
    tokens[*num_tokens] = strtok(input, " \n");
    while (tokens[*num_tokens] != NULL) {
        *num_tokens += 1;
        tokens[*num_tokens] = strtok(NULL, " \n");
    }
}

void execute(char **tokens, int num_tokens)
{
    int pid = fork();
    if (pid == 0) {
        // Child process
        execvp(tokens[0], tokens);
        fprintf(stderr, "shell: command not found: %s\n", tokens[0]);
        exit(1);
    } else {
        // Parent process
        wait(NULL);
    }
}

int main()
{
    char input[MAX_INPUT_SIZE];
    char *tokens[MAX_NUM_TOKENS];
    int num_tokens;
    while (get_input(input)) {
        tokenize(input, tokens, &num_tokens);
        if (num_tokens > 0) {
            execute(tokens, num_tokens);
        }
    }
    return 0;
}