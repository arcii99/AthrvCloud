//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARGS 20

void parse_input(char* input, char** args);
void execute_command(char** args);

int main() {
    char input[1024];
    char* args[MAX_ARGS];

    while(1) {
        printf(">>> ");
        fgets(input, 1024, stdin);

        if (strlen(input) > 1) {
            parse_input(input, args);
            execute_command(args);
        }
    }

    return 0;
}

void parse_input(char* input, char** args) {
    char* token;
    int i = 0;

    token = strtok(input, " \n\t");
    while(token != NULL && i < MAX_ARGS - 1) {
        args[i] = token;
        i++;
        token = strtok(NULL, " \n\t");
    }

    args[i] = NULL;
}

void execute_command(char** args) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Error: fork failed\n");
        exit(1);
    } else if (pid == 0) {
        if (execvp(args[0], args) < 0) {
            fprintf(stderr, "Error: exec failed\n");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }
}