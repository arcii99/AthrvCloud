//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define CMDMAX 1024

void prompt() {
    printf("peaceful_shell> ");
}

int main() {
    char command[CMDMAX];

    while (1) {
        prompt();
        fgets(command, CMDMAX, stdin);
        command[strcspn(command, "\n")] = '\0'; // remove newline character from user input

        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
        } else if (pid == 0) {
            // child process
            char* args[CMDMAX] = { NULL };

            char* arg = strtok(command, " ");
            int idx = 0;
            while (arg != NULL) {
                args[idx++] = arg;
                arg = strtok(NULL, " ");
            }

            if (execvp(args[0], args) == -1) {
                perror("exec");
                exit(EXIT_FAILURE);
            }
        } else {
            // parent process
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return EXIT_SUCCESS;
}