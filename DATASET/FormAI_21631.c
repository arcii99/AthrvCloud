//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

char* args[MAX_NUM_TOKENS];
char* tokens[MAX_NUM_TOKENS];

int tokenize(char* line){
    int i = 0;
    char* token = strtok(line, " ");
    while (token != NULL) {
        tokens[i++] = token;
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;
    return i;
}

void execute(char** args){
    pid_t pid = fork();
    if (pid == -1) {
        printf("Failed to fork child process\n");
    } else if (pid == 0) {
        execvp(args[0], args);
        printf("Failed to execute command\n");
        exit(EXIT_FAILURE);
    } else {
        int status;
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (WIFEXITED(status) == 0 && WIFSIGNALED(status) == 0);
    }
}

int main() {
    char input[MAX_INPUT_SIZE];
    int should_run = 1;
    while (should_run) {
        printf(">");
        fflush(stdout);
        fgets(input, MAX_INPUT_SIZE, stdin);
        int token_count = tokenize(input);
        int i, j;
        for (i = 0; i < token_count; i++) {
            args[i] = tokens[i];
        }
        args[token_count] = NULL;
        if (token_count > 0) {
            if (strcmp(args[0], "exit") == 0) {
                should_run = 0;
            } else {
                execute(args);
            }
        }
    }
    return 0;
}