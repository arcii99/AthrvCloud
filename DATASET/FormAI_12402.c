//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LENGTH 100 // Maximum length of a command
#define MAX_ARGS 10 // Maximum number of arguments in a command

// Function to split the given string into tokens
void tokenize(char* cmd, char** tokens) {
    char* token;
    int i = 0;
    token = strtok(cmd, " \n\t");
    while(token != NULL) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, " \n\t");
    }
    tokens[i] = NULL;
}

int main() {
    char cmd[MAX_LENGTH]; // Command input by the user
    char* tokens[MAX_ARGS]; // Arguments of a command
    int status; // Status of child process
    pid_t pid; // Process ID of child process

    while(1) {
        printf(">> ");
        fgets(cmd, MAX_LENGTH, stdin);
        
        // Remove the newline character added by fgets
        cmd[strcspn(cmd, "\n")] = '\0';

        // Split the command into tokens
        tokenize(cmd, tokens);

        // Check if the user wants to exit the shell
        if(strcmp(tokens[0], "exit") == 0) {
            printf("Exiting shell...\n");
            exit(0);
        }

        // Fork a new process to execute the command
        pid = fork();
        if(pid == -1) {
            printf("Error: Could not fork new process.\n");
            exit(1);
        } else if(pid == 0) {
            // Child process executes the command
            if(execvp(tokens[0], tokens) == -1) {
                printf("Error: Could not execute command.\n");
                exit(1);
            }
            exit(0);
        } else {
            // Parent process waits for child process to finish
            waitpid(pid, &status, 0);
            if(WIFEXITED(status)) {
                printf("Child process terminated with exit status %d.\n", WEXITSTATUS(status));
            } else if(WIFSIGNALED(status)) {
                printf("Child process terminated with signal %d.\n", WTERMSIG(status));
            }
        }
    }

    return 0;
}