//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFSIZE 1024 // buffer size
#define TOKEN_DELIM " \t\r\n\a" // token delimiters

// Function declarations
void shell_loop(void);
char *read_line(void);
char **split_line(char *line);
int execute(char **args);

int main(int argc, char **argv) {
    printf("Welcome to MyShell - the best Unix-like shell out there!\n");
    printf("Use the built-in 'help' command if you need assistance.\n\n");
    shell_loop();
    return EXIT_SUCCESS;
}

// Main shell loop
void shell_loop(void) {
    char *line;
    char **args;
    int status;

    do {
        printf("> ");
        line = read_line();
        args = split_line(line);
        status = execute(args);
        free(line);
        free(args);
    } while (status);
}

// Function that reads a line of input from the user
char *read_line(void) {
    char *line = NULL;
    ssize_t bufsize = 0; 
    getline(&line, &bufsize, stdin);
    return line;
}

// Function that splits a line into tokens
char **split_line(char *line) {
    int bufsize = BUFSIZE, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;

    if (!tokens) {
        fprintf(stderr, "Allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, TOKEN_DELIM);
    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufsize) {
            bufsize += BUFSIZE;
            tokens = realloc(tokens, bufsize * sizeof(char*));
            if (!tokens) {
                fprintf(stderr, "Allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, TOKEN_DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}

// Function that executes the built-in or external commands
int execute(char **args) {
    pid_t pid, wpid;
    int status;

    if (args[0] == NULL) {
        return 1;
    }

    if (strcmp(args[0], "exit") == 0) {
        printf("Goodbye! Thanks for using MyShell!\n");
        return 0;
    } else if (strcmp(args[0], "help") == 0) {
        printf("MyShell - The best Unix-like shell out there!\n");
        printf("Enter commands and arguments, then press enter.\n");
        printf("The following commands are built-in:\n");
        printf("  help    Display this help message\n");
        printf("  exit    Exit the shell\n");
        printf("Type 'man <command>' for detailed information on a command.\n");
        return 1;
    }

    pid = fork();
    if (pid == 0) { // Child process
        if (execvp(args[0], args) == -1) {
            perror("MyShell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) { // Error forking
        perror("MyShell");
    } else { // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return 1;
}