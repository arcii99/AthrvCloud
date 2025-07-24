//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10 // Maximum number of arguments in a single command
#define MAX_CMD_LENGTH 100 // Maximum length of each command

void parse_command(char* command, char** args) {
    /* Tokenize the command string by space and store it in args array */
    int i = 0;
    args[i] = strtok(command, " \n");
    while (args[i] != NULL && i < MAX_ARGS) {
        args[++i] = strtok(NULL, " \n");
    }
}

int execute_command(char** args) {
    /* Fork a child process to execute the given command */
    pid_t pid = fork();

    if (pid == 0) {
        /* This is the child process */
        if (execvp(args[0], args) == -1) {
            perror("Shell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        /* Forking failed */
        perror("Shell");
    } else {
        /* This is the parent process */
        int status;
        if (waitpid(pid, &status, 0) == -1) {
            perror("Shell");
        }
        return 1;
    }
    return 0;
}

int main() {
    char command[MAX_CMD_LENGTH];
    char* args[MAX_ARGS];

    while (1) {
        /* Print the prompt and read the command */
        printf("> ");
        if (fgets(command, MAX_CMD_LENGTH, stdin) == NULL) {
            continue;
        }

        /* Parse the command string and execute the command */
        parse_command(command, args);
        if (args[0] != NULL) {
            execute_command(args);
        }
    }

    return 0;
}