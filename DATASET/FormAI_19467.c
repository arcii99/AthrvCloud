//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_LENGTH 1024 // Maximum length of command line input

int main() {
    char input[MAX_LENGTH]; // Store user input
    char* args[MAX_LENGTH/2 + 1]; // Store tokenized command input
    pid_t pid;
    int status;
    
    while (1) {
        printf("shell> ");
        fflush(stdout);
        fgets(input, MAX_LENGTH, stdin); // Get user input
        input[strcspn(input, "\n")] = 0; // Remove newline character
        
        if (strcmp(input, "exit") == 0) {
            break; // Exit the shell
        }
        
        // Tokenize command into arguments
        char* token = strtok(input, " ");
        int i = 0;
        while (token != NULL) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL; // Last argument should be NULL
        
        // Fork the process
        pid = fork();
        if (pid < 0) {
            fprintf(stderr, "Fork failed\n");
            exit(1);
        }
        else if (pid == 0) {
            // Child process
            if (execvp(args[0], args) < 0) {
                fprintf(stderr, "Command not found\n");
                exit(1);
            }
        }
        else {
            // Parent process
            wait(NULL);
        }
    }
    return 0;
}