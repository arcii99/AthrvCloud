//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMANDS 5
#define MAX_STRING_LENGTH 100

void executeCommand(char* args[], int backgroundExecution) {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("Error executing command");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("Error forking process");
    } else {
        // Parent process
        if (!backgroundExecution) {
            int status;
            waitpid(pid, &status, 0);
        }
    }
}

int main() {
    char* commands[MAX_COMMANDS];
    char input[MAX_STRING_LENGTH];
    int numCommands = 0;
    int backgroundExecution = 0;
    
    printf("Welcome to MyShell!\n");
    while (1) {
        printf("MyShell> ");
        fgets(input, MAX_STRING_LENGTH, stdin);
        
        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;
        
        // Split input into commands
        char* token = strtok(input, " ");
        while (token != NULL) {
            if (strcmp(token, "&") == 0) {
                backgroundExecution = 1;
            } else {
                commands[numCommands++] = token;
            }
            token = strtok(NULL, " ");
        }
        
        // Execute commands
        executeCommand(commands, backgroundExecution);
        
        // Reset variables for next input
        numCommands = 0;
        backgroundExecution = 0;
        memset(input, 0, sizeof(input));
        memset(commands, 0, sizeof(commands));
    }
    
    return 0;
}