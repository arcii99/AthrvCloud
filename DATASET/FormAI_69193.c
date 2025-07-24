//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10

int get_args(char* line, char* args[]) {
    int i = 0;
    char* token = strtok(line, " \t\n");
    while (token != NULL && i < MAX_ARGS - 1) {
        args[i] = token;
        i++;
        token = strtok(NULL, " \t\n");
    }
    args[i] = NULL;
    return i;
}

int main() {
    char line[256];
    char* args[MAX_ARGS];
    while (1) {
        printf("my-shell> ");
        fflush(stdout);
        if (fgets(line, sizeof(line), stdin) == NULL) {
            perror("fgets");
            exit(EXIT_FAILURE);
        }
        int n_args = get_args(line, args);
        if (n_args > 0) {
            if (strcmp(args[0], "exit") == 0) {
                exit(EXIT_SUCCESS);
            }
            pid_t child_pid = fork();
            if (child_pid < 0) {
                perror("fork");
                exit(EXIT_FAILURE);
            } else if (child_pid == 0) {
                if (execvp(args[0], args) < 0) {
                    perror(args[0]);
                    exit(EXIT_FAILURE);
                }
            } else {
                int status;
                waitpid(child_pid, &status, 0);
                if (WIFEXITED(status)) {
                    printf("Child process exited with status %d\n", WEXITSTATUS(status));
                }
            }
        }
    }
    return 0;
}