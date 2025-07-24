//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

void clearBuffer(char* buffer, int size) {
    for (int i = 0; i < size; i++) {
        buffer[i] = '\0';
    }
}

int main() {
    char* tokens[MAX_NUM_TOKENS];
    char* token;
    char buffer[MAX_INPUT_SIZE];
    pid_t pid;
    int status, tokenCount;

    while (1) {
        printf(">> ");
        fgets(buffer, MAX_INPUT_SIZE, stdin);

        tokenCount = 0;
        token = strtok(buffer, " \t\n");
        while (token != NULL && tokenCount < MAX_NUM_TOKENS) {
            tokens[tokenCount] = token;
            tokenCount++;
            token = strtok(NULL, " \t\n");
        }
        tokens[tokenCount] = NULL;

        if (tokenCount == 0) {
            continue;
        }

        if (strcmp(tokens[0], "exit") == 0) {
            return 0;
        }

        pid = fork();
        if (pid == 0) {
            execvp(tokens[0], tokens);
            printf("%s: %s\n", tokens[0], strerror(errno));
            return 1;
        } else if (pid > 0) {
            waitpid(pid, &status, 0);
        } else {
            printf("fork(): %s\n", strerror(errno));
        }

        clearBuffer(buffer, MAX_INPUT_SIZE);
    }

    return 0;
}