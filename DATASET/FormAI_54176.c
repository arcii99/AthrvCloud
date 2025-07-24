//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define TOKEN_SIZE 64
#define TOKEN_DELIMITERS " \t\r\n\a"

// Function declarations
int cd_command(char **args);
int exit_command(char **args);
void execute_command(char **args);
char **parse_command(char *line);
int launch_process(char **args);

// Built-in command implementations
char *builtin_commands[] = {"cd", "exit"};

int (*builtin_functions[]) (char **) = {&cd_command, &exit_command};

int num_builtin_commands() {
    return sizeof(builtin_commands) / sizeof(char *);
}

/**
 * Implementation of cd command - changes the current directory.
 * @param args Arguments containing the target directory.
 * @return 1 to signal the shell to continue running.
 */
int cd_command(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "cd: expected argument to cd command - target directory\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("cd");
        }
    }
    return 1;
}

/**
 * Implementation of exit command - exits the shell.
 * @param args Unused.
 * @return 0 to signal the shell to exit.
 */
int exit_command(char **args) {
    return 0;
}

/**
 * Parse the user input command line into an array of command tokens.
 * @param line The command line input by the user.
 * @return An array of tokens.
 */
char **parse_command(char *line) {
    int buffer_size = BUFFER_SIZE;
    int position = 0;
    char **tokens = malloc(buffer_size * sizeof(char *));
    char *token;

    if (!tokens) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, TOKEN_DELIMITERS);
    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position >= buffer_size) {
            buffer_size += BUFFER_SIZE;
            tokens = realloc(tokens, buffer_size * sizeof(char *));
            if (!tokens) {
                fprintf(stderr, "Memory allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, TOKEN_DELIMITERS);
    }

    tokens[position] = NULL;
    return tokens;
}

/**
 * Launches a new process for a non-built-in command.
 * @param args The command arguments.
 * @return The status of the process.
 */
int launch_process(char **args) {
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("Shell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Error forking
        perror("Shell");
    } else {
        // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

/**
 * Executes the command entered by the user.
 * @param args The command arguments.
 */
void execute_command(char **args) {
    int i;
    if (args[0] == NULL) {
        // Empty command entered
        return;
    }

    // Check if the command is a built-in, and run if it is
    for (i = 0; i < num_builtin_commands(); i++) {
        if (strcmp(args[0], builtin_commands[i]) == 0) {
            (*builtin_functions[i])(args);
            return;
        }
    }

    // Otherwise launch a new process for the non-built-in command
    launch_process(args);
}

/**
 * The main shell loop. Prints the prompt and waits for user input.
 */
void shell_loop() {
    char *line;
    char **args;
    int status;

    do {
        printf("my_shell_69> ");
        line = NULL;
        ssize_t line_buffer = 0;
        getline(&line, &line_buffer, stdin);
        args = parse_command(line);
        execute_command(args);

        // Clean up allocated memory
        free(line);
        free(args);
    } while (status);
}

/**
 * Program entry point.
 * @param argc Argument count.
 * @param argv Argument vector.
 * @return Exit status.
 */
int main(int argc, char **argv) {
    // Run command loop
    shell_loop();
    return EXIT_SUCCESS;
}