//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

int main() {

    char *input;
    char *tokens[MAX_NUM_TOKENS];
    char *prompt = "$ ";

    while(1) {
        input = calloc(MAX_INPUT_SIZE, sizeof(char));
        printf("%s", prompt);
        fgets(input, MAX_INPUT_SIZE, stdin);
        if(strcmp(input, "exit\n") == 0 || strcmp(input, "quit\n") == 0)
            break;

        char *token = strtok(input, " ");
        int token_count = 0;
        while(token != NULL && token_count < MAX_NUM_TOKENS) {
            tokens[token_count] = token;
            token_count++;
            token = strtok(NULL, " ");
        }
        tokens[token_count] = NULL;

        pid_t pid = fork();
        if(pid == 0) {
            execvp(tokens[0], tokens);
            printf("Unrecognized command: %s\n", tokens[0]);
            exit(0);
        } else {
            waitpid(pid, NULL, 0);
        }

        free(input);
    }

    return 0;
}