//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_TOKENS 64

void read_cmd(char *cmd, char** tokens, int *background);
void execute_cmd(char **tokens, int background);

int main() {
    char cmd[MAX_CMD_LEN];
    char *tokens[MAX_TOKENS];
    int background = 0;

    while(1) {
        printf("Mind-Bending Unix-like shell > ");
        fflush(stdout);
        read_cmd(cmd, tokens, &background);
        execute_cmd(tokens, background);
    }

    return 0;
}

void read_cmd(char *cmd, char** tokens, int *background) {
    char *token = strtok(cmd, " \n\t");
    int i = 0;
    
    // Initialize tokens
    for (i = 0; i < MAX_TOKENS; i++) {
        tokens[i] = NULL;
    }

    // Read the command
    if (fgets(cmd, MAX_CMD_LEN, stdin) == NULL) {
        exit(0);
    }

    // Parse the command and tokens
    while (token != NULL && i < MAX_TOKENS - 1) {
        if (strcmp(token, "&") == 0) {
            *background = 1;
            token = strtok(NULL, " \n\t");
            continue;
        }
        tokens[i++] = token;
        token = strtok(NULL, " \n\t");
    }
}

void execute_cmd(char **tokens, int background) {
    int status;
    pid_t pid;

    // Exit command
    if (tokens[0] != NULL && strcmp(tokens[0], "exit") == 0) {
        exit(0);
    }

    // Fork a child process
    pid = fork();

    if (pid == 0) {
        // Child process executes
        if (execvp(tokens[0], tokens) == -1) {
            perror("execute_cmd");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("execute_cmd");
    } else {
        // Parent process waits for child
        if (!background) {
            do {
                waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
    }
}