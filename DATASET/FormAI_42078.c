//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    char *args[100];
    char line[1024];
    char *token;
    int status;
    printf("Welcome to my Unix-like Shell!\n");

    while (1) {
        printf("> ");
        fgets(line, 1024, stdin);
        token = strtok(line, " \n");
        int i = 0;
        while (token != NULL) {
            args[i] = token;
            i++;
            token = strtok(NULL, " \n");
        }
        args[i] = NULL;

        if (args[0] == NULL) {
            continue;
        } else if (strcmp(args[0], "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            if (execvp(args[0], args) == -1) {
                printf("Error: Command not found.\n");
            }
            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            // Forking error
            printf("Forking error.");
        } else {
            // Parent process
            waitpid(pid, &status, WUNTRACED);
        }
    }
    return 0;
}