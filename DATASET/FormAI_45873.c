//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: imaginative
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

#define MAX_COMMAND_LENGTH 100 // Maximum length of command

int main() {
    char command[MAX_COMMAND_LENGTH]; // Command buffer
    while (1) { // Keep running the shell
        printf(">> "); // Output prompt
        fgets(command, MAX_COMMAND_LENGTH, stdin); // Read input
        if (command[strlen(command) - 1] == '\n') { // Remove trailing newline character
            command[strlen(command) - 1] = '\0';
        }
        char* args[10]; // Argument array
        int argIndex = 0;
        char* token = strtok(command, " "); // Tokenize the command
        while (token != NULL) { // Add each token as an argument
            args[argIndex] = token;
            argIndex++;
            token = strtok(NULL, " ");
        }
        args[argIndex] = NULL; // Mark end of arguments
        pid_t pid = fork(); // Fork a child process
        if (pid < 0) { // Error handling
            fprintf(stderr, "Fork failed.\n");
            exit(1);
        } else if (pid == 0) { // Child process
            if (strcmp(args[0], "cd") == 0) { // Change directory command
                if (args[1] == NULL) { // Default to home directory
                    chdir(getenv("HOME"));
                } else {
                    chdir(args[1]);
                }
                exit(0); // Exit child process
            } else { // Execute the command
                execvp(args[0], args);
                fprintf(stderr, "Command not found.\n");
                exit(1); // Exit child process with error
            }
        } else { // Parent process
            wait(NULL); // Wait for child process to finish
        }
    }
    return 0;
}