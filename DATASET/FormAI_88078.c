//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: genious
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 255
#define MAX_ARGS 10

int main() {
    char command[MAX_COMMAND_LENGTH+1];
    char* argv[MAX_ARGS+1];

    printf("********** Welcome to GeniOS Shell **********\n");

    while (1) {
        // print the prompt
        printf("GeniOS > ");
        fflush(stdout);

        // read in the command
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // replace newline character with null terminator
        command[strcspn(command, "\n")] = '\0';

        // exit if command is "exit"
        if (strcmp(command, "exit") == 0) {
            printf("Exiting GeniOS Shell...\n");
            break;
        }

        // tokenize the command into arguments
        int i = 0;
        char* token = strtok(command, " ");
        while (token != NULL) {
            argv[i++] = token;
            token = strtok(NULL, " ");
        }
        argv[i] = NULL;

        // fork a child process
        pid_t pid = fork();

        if (pid == -1) {
            printf("Error: failed to fork\n");
            continue;
        } else if (pid == 0) {
            // child process

            // execute the command
            int ret = execvp(argv[0], argv);

            // only reaches here if execvp fails
            printf("Error: failed to execute command\n");
            exit(ret);
        } else {
            // parent process

            // wait for child process to finish
            int status;
            pid_t child_pid = waitpid(pid, &status, 0);

            if (child_pid == -1) {
                printf("Error: failed to wait for child\n");
            } else {
                // check if child process exited normally
                if (WIFEXITED(status)) {
                    int exit_status = WEXITSTATUS(status);
                    if (exit_status != 0) {
                        printf("Error: command exited with status %d\n", exit_status);
                    }
                }
            }
        }
    }

    return 0;
}