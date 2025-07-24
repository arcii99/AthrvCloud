//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARGS 100
#define MAX_COMMANDS 100

char *history[MAX_COMMANDS];

void print_prompt() {
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("%s> ", cwd);
}

void clear_history() {
    for (int i = 0; i < MAX_COMMANDS; i++) {
        history[i] = NULL;
    }
}

void add_history(char *command) {
    // Shift up history entries
    for (int i = MAX_COMMANDS - 2; i >= 0; i--) {
        history[i+1] = history[i];
    }
    // Add new entry to front
    history[0] = strdup(command);
}

void print_history() {
    printf("Command history:\n");
    for (int i = 0; i < MAX_COMMANDS && history[i] != NULL; i++) {
        printf("%d. %s\n", i+1, history[i]);
    }
}

int execute(char *args[]) {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        execvp(args[0], args);
        printf("Command not found: %s\n", args[0]);
        exit(1);
    } else if (pid > 0) {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
        return status;
    } else {
        // Fork failed
        printf("Fork failed\n");
        exit(1);
    }
}

int main() {
    clear_history();
    while (true) {
        print_prompt();
        char input[1024];
        fgets(input, 1024, stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove trailing newline
        char *args[MAX_ARGS];
        int argc = 0;
        char *token = strtok(input, " ");
        while (token != NULL) {
            args[argc] = token;
            argc++;
            token = strtok(NULL, " ");
        }
        args[argc] = NULL; // Last argument must be NULL
        if (argc > 0) {
            if (strcmp(args[0], "exit") == 0) {
                exit(0);
            } else if (strcmp(args[0], "cd") == 0) {
                if (argc == 1) {
                    chdir(getenv("HOME"));
                } else {
                    chdir(args[1]);
                }
            } else if (strcmp(args[0], "history") == 0) {
                print_history();
            } else {
                add_history(input);
                execute(args);
            }
        }
    }
    return 0;
}