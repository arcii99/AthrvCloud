//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100 /* maximum command length */
#define MAX_ARGUMENTS 10 /* maximum number of arguments in a command */

void execute(char **arguments) {
    pid_t pid = fork();

    if (pid == 0) {
        /* child process */
        execvp(arguments[0], arguments);
        perror("Error executing command");
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("Error forking process");
    } else {
        /* parent process */
        waitpid(pid, NULL, 0);
    }
}

int parseInput(char *input, char **arguments) {
    int count_arguments = 0;
    char *token = strtok(input, " ");

    while (token != NULL && count_arguments < MAX_ARGUMENTS) {
        arguments[count_arguments] = token;
        count_arguments++;
        token = strtok(NULL, " ");
    }
    arguments[count_arguments] = NULL;

    return count_arguments;
}

int main(void) {
    char command[MAX_COMMAND_LENGTH];
    char *arguments[MAX_ARGUMENTS];

    while (1) {
        /* prompt user for input */
        printf("dsshell> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        /* remove newline character from command string */
        if (strchr(command, '\n') != NULL) {
            *strchr(command, '\n') = '\0';
        }

        /* exit shell if command is "exit" */
        if (strcmp(command, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        /* execute command */
        int nargs = parseInput(command, arguments);
        if (nargs > 0) {
            execute(arguments);
        }
    }

    return EXIT_SUCCESS;
}