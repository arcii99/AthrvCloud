//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define TOKEN_SIZE 64
#define TOKEN_DELIMITER " \t\r\n\a"

void shell_loop();

char *read_line();
char **split_line(char *line);

int shell_cd(char **args);
int shell_help(char **args);
int shell_exit(char **args);

char *built_in_commands[] = {
    "cd",
    "help",
    "exit"
};

int (*built_in_functions[]) (char **) = {
    &shell_cd,
    &shell_help,
    &shell_exit
};

int num_built_in_commands() {
    return sizeof(built_in_commands) / sizeof(char *);
}

int shell_launch(char **args) {
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("shell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("shell");
    } else {
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

int shell_execute(char **args) {
    int i;

    if (args[0] == NULL) {
        return 1;
    }

    for (i = 0; i < num_built_in_commands(); i++) {
        if (strcmp(args[0], built_in_commands[i]) == 0) {
            return (*built_in_functions[i])(args);
        }
    }

    return shell_launch(args);
}

int shell_cd(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "shell: expected argument to \"cd\"\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("shell");
        }
    }
    return 1;
}

int shell_help(char **args) {
    int i;
    printf("Available commands:\n");
    for (i = 0; i < num_built_in_commands(); i++) {
        printf("  %s\n", built_in_commands[i]);
    }
    return 1;
}

int shell_exit(char **args) {
    return 0;
}

char *read_line() {
    char *line = NULL;
    size_t buffer_size = 0;
    getline(&line, &buffer_size, stdin);
    return line;
}

char **split_line(char *line) {
    int buffer_size = TOKEN_SIZE, position = 0;
    char **tokens = malloc(buffer_size * sizeof(char *));
    char *token;

    if (!tokens) {
        fprintf(stderr, "shell: allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, TOKEN_DELIMITER);
    while (token != NULL) {
        tokens[position++] = token;

        if (position >= buffer_size) {
            buffer_size += TOKEN_SIZE;
            tokens = realloc(tokens, buffer_size * sizeof(char *));
            if (!tokens) {
                fprintf(stderr, "shell: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, TOKEN_DELIMITER);
    }
    tokens[position] = NULL;
    return tokens;
}

void shell_loop() {
    char *line;
    char **args;
    int status;

    do {
        printf("> ");
        line = read_line();
        args = split_line(line);
        status = shell_execute(args);

        free(line);
        free(args);
    } while (status);
}

int main(int argc, char **argv) {
    shell_loop();
    return EXIT_SUCCESS;
}