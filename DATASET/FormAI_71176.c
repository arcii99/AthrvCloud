//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 20

int main() {
    char command[MAX_COMMAND_LENGTH + 1];
    char *arguments[MAX_ARGUMENTS + 1];

    while (1) {
        printf("> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // remove newline character from end of command string
        if (strlen(command) > 0 && command[strlen(command) - 1] == '\n') {
            command[strlen(command) - 1] = '\0';
        }

        // split command into individual arguments
        arguments[0] = strtok(command, " ");

        for (int i = 1; i < MAX_ARGUMENTS; i++) {
            arguments[i] = strtok(NULL, " ");
            if (arguments[i] == NULL) {
                break;
            }
        }
        arguments[MAX_ARGUMENTS] = NULL;

        if (arguments[0] == NULL) {
            // no command entered
            continue;
        }

        if (strcmp(arguments[0], "exit") == 0) {
            // exit shell
            break;
        }

        int pid = fork();
        
        if (pid == -1) {
            // fork error
            perror("fork error");
            exit(1);
        } else if (pid == 0) {
            // child process
            int status = execvp(arguments[0], arguments);
            if (status == -1) {
                perror("execvp error");
                exit(1);
            }
        } else {
            // parent process
            wait(NULL);
        }
    }

    return 0;
}