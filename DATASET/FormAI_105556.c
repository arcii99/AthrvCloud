//FormAI DATASET v1.0 Category: System administration ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 256
#define MAX_ARGS 10

int parse_args(char *line, char **args) {
    int num_args = 0;
    char *token = strtok(line, " \t\n");
    while (token != NULL && num_args < MAX_ARGS-1) {
        args[num_args++] = token;
        token = strtok(NULL, " \t\n");
    }
    args[num_args] = NULL;
    return num_args;
}

int execute_command(char **args) {
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        if (execvp(args[0], args) < 0) {
            perror("Command execution failed");
            exit(EXIT_FAILURE);
        }
    } else {
        int status;
        if (waitpid(pid, &status, 0) < 1) {
            perror("Wait failed");
            exit(EXIT_FAILURE);
        }
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            return -1;
        }
    }
}

int main() {
    char buffer[BUFFER_SIZE];
    while (1) {
        printf(">> ");
        if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
            break;
        }
        char *args[MAX_ARGS];
        int num_args = parse_args(buffer, args);
        if (num_args == 0) {
            continue;
        }
        int status = execute_command(args);
        if (status == -1) {
            printf("Command execution failed\n");
        } else {
            printf("Exit status: %d\n", status);
        }
    }
    return 0;
}