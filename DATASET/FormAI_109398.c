//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFF_SIZE 1024
#define TOK_DELIM " \t\r\n\a"

void shell_loop();
char *read_line();
char **parse_command(char *line);
int execute_command(char **args);

int main() {
    printf("Welcome to the secure Unix-like shell!\n");
    shell_loop();
    return 0;
}

void shell_loop() {
    char *line;
    char **args;
    int status;

    do {
        printf("> ");
        line = read_line();
        args = parse_command(line);
        status = execute_command(args);

        free(line);
        free(args);
    } while (status);
}

char *read_line() {
    char *line = NULL;
    size_t size = 0;
    getline(&line, &size, stdin);
    return line;
}

char **parse_command(char *line) {
    int buff_size = BUFF_SIZE;
    int pos = 0;
    char *token;
    char **tokens = malloc(buff_size * sizeof(char *));

    if (!tokens) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, TOK_DELIM);
    while (token != NULL) {
        tokens[pos] = token;
        pos++;

        if (pos >= buff_size) {
            buff_size += BUFF_SIZE;
            tokens = realloc(tokens, buff_size * sizeof(char *));
            if (!tokens) {
                fprintf(stderr, "Error: Memory allocation failed.\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, TOK_DELIM);
    }

    tokens[pos] = NULL;
    return tokens;
}

int execute_command(char **args) {
    int pid, status;

    if (args[0] == NULL) {
        return 1;
    }

    if (strcmp(args[0], "exit") == 0) {
        return 0;
    }

    pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Error: Unknown command.\n");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        fprintf(stderr, "Error: Fork failed.\n");
    } else {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}