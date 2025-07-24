//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 512
#define COMMAND_DELIMITER " \t\r\n\a"

char *read_command_line();
char **parse_command(char *command_line);
int execute_command(char **args);

int main() {
    char *command_line;
    char **args;
    int status;

    do {
        printf("shell$ ");
        command_line = read_command_line();
        args = parse_command(command_line);
        status = execute_command(args);

        free(command_line);
        free(args);
    } while (status);

    return EXIT_SUCCESS;
}

char *read_command_line() {
    char *buffer = NULL;
    size_t buffer_size = 0;

    if (getline(&buffer, &buffer_size, stdin) == -1) {
        perror("read_command_line");
        exit(EXIT_FAILURE);
    }

    return buffer;
}

char **parse_command(char *command_line) {
    int buffer_size = BUFFER_SIZE, position = 0;
    char **tokens = malloc(buffer_size * sizeof(char *));
    char *token;

    if (!tokens) {
        fprintf(stderr, "parse_command: allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(command_line, COMMAND_DELIMITER);
    while (token != NULL) {
        tokens[position++] = token;

        if (position >= buffer_size) {
            buffer_size += BUFFER_SIZE;
            tokens = realloc(tokens, buffer_size * sizeof(char *));
            if (!tokens) {
                fprintf(stderr, "parse_command: reallocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, COMMAND_DELIMITER);
    }
    tokens[position] = NULL;

    return tokens;
}

int execute_command(char **args) {
    pid_t pid, wpid;
    int status;

    if (args[0] == NULL) {
        return 1;
    }

    pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execute_command");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("execute_command");
    } else {
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}