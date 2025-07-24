//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_ARGV_SIZE 256
#define MAX_INPUT_SIZE 512
#define MAX_PATH_SIZE 512

char **parse_input(char *input_line, char *delimiter) {
    char *token;
    char **tokens = malloc(MAX_ARGV_SIZE * sizeof(char *));
    int i = 0;

    if (!tokens) {
        perror("Allocation error");
        exit(EXIT_FAILURE);
    }

    token = strtok(input_line, delimiter);
    while (token != NULL) {
        tokens[i++] = token;
        token = strtok(NULL, delimiter);
    }
    tokens[i] = NULL;

    return tokens;
}

char *search_path(char **args, char **paths, int num_paths) {
    char *full_path = malloc(MAX_PATH_SIZE);
    if (!full_path) {
        perror("Allocation error");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < num_paths; i++) {
        sprintf(full_path, "%s/%s", paths[i], args[0]);
        if (access(full_path, X_OK) == 0) {
            return full_path;
        }
    }

    return NULL;
}

int main(int argc, char **argv) {
    char *input_line;
    char **args;
    char **paths;
    int num_paths;
    int status;
    pid_t pid;

    input_line = malloc(MAX_INPUT_SIZE);
    if (!input_line) {
        perror("Allocation error");
        exit(EXIT_FAILURE);
    }

    printf("Welcome to your Unix-like shell! Enter 'quit' to exit.\n");

    while (1) {
        printf("> ");
        fflush(stdout);

        // read input
        if (fgets(input_line, MAX_INPUT_SIZE, stdin) == NULL) {
            perror("Input error");
            exit(EXIT_FAILURE);
        }

        // remove newline character from input
        input_line[strlen(input_line)-1] = '\0';

        // check for quit command
        if (strcmp(input_line, "quit") == 0) {
            break;
        }

        // parse input
        args = parse_input(input_line, " ");

        // search for executable file in path
        char *path_var = getenv("PATH");
        num_paths = 0;
        paths = malloc(MAX_PATH_SIZE * sizeof(char *));
        if (!paths) {
            perror("Allocation error");
            exit(EXIT_FAILURE);
        }
        for (char *path = strtok(path_var, ":"); path != NULL; path = strtok(NULL, ":")) {
            paths[num_paths++] = path;
        }

        char *full_path = search_path(args, paths, num_paths);

        if (full_path == NULL) {
            printf("%s: command not found\n", args[0]);
            free(args);
            continue;
        }

        // execute command
        pid = fork();
        if (pid == -1) {
            perror("Fork error");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // child process
            execv(full_path, args);
            perror("Exec error");
            exit(EXIT_FAILURE);
        } else {
            // parent process
            waitpid(pid, &status, 0);
        }

        free(full_path);
        free(args);
    }

    free(input_line);

    return 0;
}