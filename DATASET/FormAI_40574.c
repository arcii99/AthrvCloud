//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1000
#define MAX_NUM_ARGUMENTS 10

/* Function to display shell prompt */
void display_shell_prompt() {
    char current_dir[1024];
    getcwd(current_dir, sizeof(current_dir));
    printf("myshell [%s]> ", current_dir);
}

/* Function to split input command into tokens */
void tokenize_input_command(char* input_command, char** tokens) {
    char* token;
    token = strtok(input_command, " \t\n\r");
    int index = 0;
    while (token != NULL) {
        tokens[index] = token;
        index++;
        token = strtok(NULL, " \t\n\r");
    }
    tokens[index] = NULL;
}

/* Function to execute shell command */
void execute_shell_command(char** tokens) {
    pid_t pid = fork();
    if (pid == -1) {
        printf("Fork failed\n");
        return;
    }
    else if (pid == 0) {
        if (execvp(tokens[0], tokens) == -1) {
            printf("Error executing shell command\n");
        }
        exit(EXIT_FAILURE);
    }
    else {
        wait(NULL);
    }
}

/* Main shell program */
int main(int argc, char *argv[]) {
    char input_command[MAX_COMMAND_LENGTH];
    char* tokens[MAX_NUM_ARGUMENTS];
    int status = 1;
    while (status) {
        display_shell_prompt();
        if (fgets(input_command, MAX_COMMAND_LENGTH, stdin) == NULL) {
            return 0;
        }
        tokenize_input_command(input_command, tokens);
        if (tokens[0] != NULL) {
            if (strcmp(tokens[0], "exit") == 0) {
                status = 0;
            }
            else {
                execute_shell_command(tokens);
            }
        }
    }
    return 0;
}