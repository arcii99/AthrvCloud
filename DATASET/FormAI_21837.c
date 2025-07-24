//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMANDS 10
#define MAX_ARGS 10
#define MAX_INPUT 1000

void read_input(char* input) {
    printf("my_shell> ");
    fgets(input, MAX_INPUT, stdin);

    // Remove trailing newline character
    input[strcspn(input, "\n")] = 0;
}

void parse_input(char* input, char** commands, int* num_commands) {
    char* command = strtok(input, "|");
    *num_commands = 0;

    while (command != NULL && *num_commands < MAX_COMMANDS) {
        commands[*num_commands] = command;
        (*num_commands)++;
        command = strtok(NULL, "|");
    }
}

int execute_command(char** args) {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        execvp(args[0], args);
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Error
        perror("fork() error:");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
        return WIFEXITED(status) ? WEXITSTATUS(status) : -1;
    }
}

void pipe_commands(char** commands, int num_commands) {
    // Create pipes
    int pipes[num_commands - 1][2];

    for (int i = 0; i < num_commands - 1; i++) {
        if (pipe(pipes[i]) < 0) {
            perror("pipe() error:");
            exit(EXIT_FAILURE);
        }
    }

    // Create child processes and execute commands
    for (int i = 0; i < num_commands; i++) {
        pid_t pid = fork();

        if (pid == 0) {
            // Child process
            if (i > 0) {
                dup2(pipes[i - 1][0], STDIN_FILENO);
                close(pipes[i - 1][1]);
            }

            if (i < num_commands - 1) {
                dup2(pipes[i][1], STDOUT_FILENO);
                close(pipes[i][0]);
            }

            char* args[MAX_ARGS];
            int num_args = 0;
            char* arg = strtok(commands[i], " ");

            while (arg != NULL && num_args < MAX_ARGS) {
                args[num_args] = arg;
                num_args++;
                arg = strtok(NULL, " ");
            }

            args[num_args] = NULL;
            execvp(args[0], args);
            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            // Error
            perror("fork() error:");
            exit(EXIT_FAILURE);
        }
    }

    // Close pipes
    for (int i = 0; i < num_commands - 1; i++) {
        close(pipes[i][0]);
        close(pipes[i][1]);
    }

    // Wait for child processes to finish
    for (int i = 0; i < num_commands; i++) {
        int status;
        wait(&status);
    }
}

int main() {
    char input[MAX_INPUT];
    char* commands[MAX_COMMANDS];
    int num_commands;

    while (1) {
        read_input(input);
        parse_input(input, commands, &num_commands);

        if (num_commands > 1) {
            pipe_commands(commands, num_commands);
        } else if (num_commands == 1) {
            char* args[MAX_ARGS];
            int num_args = 0;
            char* arg = strtok(commands[0], " ");

            while (arg != NULL && num_args < MAX_ARGS) {
                args[num_args] = arg;
                num_args++;
                arg = strtok(NULL, " ");
            }

            args[num_args] = NULL;
            execute_command(args);
        }
    }

    return 0;
}