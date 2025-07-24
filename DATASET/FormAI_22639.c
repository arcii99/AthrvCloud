//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define DELIMITER " \n\t"

int main(int argc, char *argv[]) {
    char input[BUFFER_SIZE];
    char *tokens[BUFFER_SIZE / 2 + 1];
    int token_count;
    int should_run = 1;

    while (should_run) {
        printf("mysh > ");
        fflush(stdout);

        // Read user input
        fgets(input, BUFFER_SIZE, stdin);

        // Parse input into tokens
        token_count = 0;
        tokens[token_count] = strtok(input, DELIMITER);
        while (tokens[token_count] != NULL && token_count < BUFFER_SIZE / 2) {
            token_count++;
            tokens[token_count] = strtok(NULL, DELIMITER);
        }
        tokens[token_count] = NULL;

        // Execute command
        pid_t pid = fork();
        if (pid == -1) {
            printf("mysh: error while forking\n");
            exit(1);
        } else if (pid == 0) {
            execvp(tokens[0], tokens);
            printf("mysh: command not found or failed to execute\n");
            exit(1);
        } else {
            waitpid(pid, NULL, 0);
        }
    }
    return 0;
}