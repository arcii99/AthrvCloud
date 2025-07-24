//FormAI DATASET v1.0 Category: System administration ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_ARGS 16
#define MAX_ARG_LEN 256

void print_prompt();
void tokenize_args(char* input, char** args);
void execute(char** args);
void cleanup(char** args);

int main() {
    char input[MAX_ARG_LEN];
    char* args[MAX_ARGS];
    int should_run = 1;
    
    while (should_run == 1) {
        print_prompt();
        fgets(input, MAX_ARG_LEN, stdin);
        tokenize_args(input, args);
        execute(args);
        cleanup(args);
    }
    return 0;
}

void print_prompt() {
    printf("$ ");
}

void tokenize_args(char* input, char** args) {
    char* token = strtok(input, " \n");
    int i = 0;

    while (token != NULL && i < MAX_ARGS) {
        args[i] = token;
        token = strtok(NULL, " \n");
        i++;
    }
    args[i] = NULL;
}

void execute(char** args) {
    pid_t pid = fork();
    int status;

    if (pid < 0) {
        printf("Error: Fork failed\n");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            printf("Error: Exec failed\n");
            exit(EXIT_FAILURE);
        }
    }
    else {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

void cleanup(char** args) {
    int i;

    for (i = 0; i < MAX_ARGS; i++) {
        args[i] = NULL;
    }
}