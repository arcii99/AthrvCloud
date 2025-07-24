//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1000
#define MAX_TOKENS 100
#define DELIMITERS " \n\t\r"

int main() {
    char input[MAX_COMMAND_LENGTH];
    char *tokens[MAX_TOKENS];
    char *token;
    int status;

    printf("Welcome to Sherlock Holmes-like shell, Watson! Type 'exit' to close the shell.\n");

    while (1) {
        printf("Sherlock: ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        if (strcmp(input, "exit\n") == 0) {
            printf("Goodbye, Watson!\n");
            exit(0);
        }
        
        // tokenize the input
        int token_count = 0;
        token = strtok(input, DELIMITERS);
        while (token != NULL && token_count < MAX_TOKENS) {
            tokens[token_count++] = token;
            token = strtok(NULL, DELIMITERS);
        }
        tokens[token_count] = NULL;

        if (token_count == 0) {
            continue;
        }

        // check for internal commands that don't require fork
        if (strcmp(tokens[0], "cd") == 0) {
            if (token_count == 1) {
                printf("Sherlock: Please provide a directory.\n");
            } else if (chdir(tokens[1]) != 0) {
                printf("Sherlock: No such directory: %s\n", tokens[1]);
            }
            continue;
        }

        if (strcmp(tokens[0], "help") == 0) {
            printf("Sherlock: Sorry, I cannot help you yet. You are on your own!\n");
            continue;
        }

        if (strcmp(tokens[0], "who") == 0) {
            printf("Sherlock: The person who is using this shell is Watson.\n");
            continue;
        }

        // fork a new process to execute the command
        pid_t pid = fork();
        if (pid == -1) {
            printf("Sherlock: Failed to fork a process.\n");
            continue;
        } else if (pid == 0) { // child process
            execvp(tokens[0], tokens);
            printf("Sherlock: Failed to execute command: %s\n", tokens[0]);
            exit(0);
        } else { // parent process
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}