//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: accurate
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define BUFSIZE 1024
#define TOK_DELIM " \t\r\n\a"

/* Function Declarations */
char *read_line(void);
char **split_line(char *line);
int launch_process(char **args);
int execute(char **args);

/* Main Loop */
int main() {
    char *line;
    char **args;
    int status;

    do {
        printf("$ ");
        line = read_line();         // Read the command line
        args = split_line(line);    // Split the line into arguments
        status = execute(args);     // Execute the command and get status
        free(line);                 // Free the command line
        free(args);                 // free the arguments
    } while (status);               // Repeat until status is true
    return 0;
}

/* Read a line from user input */
char *read_line() {
    char *line = NULL;
    ssize_t bufsize = 0;    // In order for getline to allocate its own buffer
    getline(&line, &bufsize, stdin);    // Read in user input
    return line;
}

/* Split the line into arguments */
char **split_line(char *line) {
    int bufsize = BUFSIZE, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;

    // Handle memory allocation error
    if (!tokens) {
        fprintf(stderr, "Memory Allocation Error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, TOK_DELIM);
    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufsize) {
            bufsize += BUFSIZE;
            tokens = realloc(tokens, bufsize * sizeof(char*));
            if (!tokens) {
                fprintf(stderr, "Memory Allocation Error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, TOK_DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}

/* Create a process and execute the command */
int launch_process(char **args) {
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) {
        // Child Process
        if (execvp(args[0], args) == -1) {
            perror("Shell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Error Forking
        perror("Shell");
    } else {
        // Parent Process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return 1;
}

/* Execute the command */
int execute(char **args) {
    if (args[0] == NULL) {
        // Empty Command
        return 1;
    }

    // Check and run built-in commands
    if (strcmp(args[0], "exit") == 0) {
        return 0;
    }

    // Launch the process and execute command
    return launch_process(args);
}