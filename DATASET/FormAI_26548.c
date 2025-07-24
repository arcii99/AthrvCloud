//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUILTIN_COMMANDS 4
#define MAX_COMMAND_LENGTH 100

void parse_input(char* input, char** commands);
int execute_command(char** commands);
int check_builtin_commands(char** commands);

int main() {
    // Initialize variables
    char input[MAX_COMMAND_LENGTH];
    char* commands[MAX_COMMAND_LENGTH];

    while (1) {
        // Clear variables
        memset(input, 0, MAX_COMMAND_LENGTH);
        memset(commands, 0, MAX_COMMAND_LENGTH);
        
        printf(">> "); // Print prompt
        fgets(input, MAX_COMMAND_LENGTH, stdin); // Get user input
        input[strcspn(input, "\n")] = 0; // Remove newline character
        
        parse_input(input, commands); // Parse user input
        
        if (execute_command(commands) == 1) { // Execute command
            break; // Exit loop if command is "exit"
        }
    }
    return 0;
}

// Parse user input
void parse_input(char* input, char** commands) {
    char* token;
    token = strtok(input, " ");
    int i = 0;
    while (token != NULL) {
        commands[i] = token;
        token = strtok(NULL, " ");
        i++;
    }
}

// Execute command
int execute_command(char** commands) {
    int status;
    pid_t pid;
    
    if (check_builtin_commands(commands) == 1) {
        return 0; // Builtin command found - continue loop
    }
    
    pid = fork(); // Create child process
    
    if (pid < 0) {
        printf("Failed to create child process.\n");
        exit(-1);
    } else if (pid == 0) {
        // Child process
        if (execvp(commands[0], commands) < 0) {
            printf("Invalid command.\n");
            exit(-1);
        }
    } else {
        // Parent process
        waitpid(pid, &status, WUNTRACED); // Wait for child process to terminate
    }
    return 0; // No builtin command found - continue loop
}

// Check if command is one of the built-in commands
int check_builtin_commands(char** commands) {
    if (strcmp(commands[0], "exit") == 0) {
        printf("Exiting...\n");
        return 1;
    } else if (strcmp(commands[0], "cd") == 0) {
        chdir(commands[1]); // Change directory
        return 1;
    } else if (strcmp(commands[0], "pwd") == 0) {
        printf("%s\n", getcwd(NULL, 0)); // Print current working directory
        return 1;
    } else if (strcmp(commands[0], "echo") == 0) {
        printf("%s\n", commands[1]); // Print second argument
        return 1;
    }
    return 0; // Not a builtin command
}