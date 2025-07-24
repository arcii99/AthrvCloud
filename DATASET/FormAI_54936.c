//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 64

int main() {
    char command[MAX_COMMAND_LENGTH];
    char *args[MAX_ARGS];
    int status;

    while (1) {
        printf("> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // remove newline character at the end of command
        command[strcspn(command, "\n")] = 0;

        // split command into arguments
        char *arg;
        int arg_count = 0;
        arg = strtok(command, " ");

        while (arg != NULL && arg_count < MAX_ARGS - 1) {
            args[arg_count++] = arg;
            arg = strtok(NULL, " ");
        }

        // add terminating NULL argument
        args[arg_count] = NULL;

        if (arg_count == 0) {
            // empty command
            continue;
        }

        if (strcmp(args[0], "exit") == 0) {
            // exit shell
            exit(0);
        }

        pid_t pid = fork();

        if (pid == 0) {
            // child process
            execvp(args[0], args);
            perror("execvp");
            exit(1);
        } else if (pid > 0) {
            // parent process
            waitpid(pid, &status, 0);
        } else {
            // fork failed
            perror("fork");
        }
    }

    return 0;
}