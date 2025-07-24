//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_BUFFER 1024
#define MAX_ARGS 64

int main(int argc, char *argv[]) {
    char *buffer = malloc(MAX_BUFFER * sizeof(char));
    int status;

    while (1) {
        printf("> ");
        fgets(buffer, MAX_BUFFER, stdin);

        // Remove newline character
        buffer[strcspn(buffer, "\n")] = 0;

        // Split command and arguments
        char *args[MAX_ARGS];
        args[0] = strtok(buffer, " ");
        int i = 1;
        do {
            char *arg = strtok(NULL, " ");
            if (arg != NULL) {
                args[i++] = arg;
            }
        } while (i < MAX_ARGS && args[i-1] != NULL);

        // Fork and execute command
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
        }
        else if (pid == 0) {
            execvp(args[0], args);
            perror(args[0]);
            _exit(EXIT_FAILURE);
        }
        else {
            waitpid(pid, &status, 0);
        }
    }

    return EXIT_SUCCESS;
}