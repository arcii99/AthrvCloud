//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100 // Maximum length of a command

void print_shell_prompt() {
    printf("unixshell> "); // Display shell prompt
}

void read_command(char *command) {
    fgets(command, MAX_COMMAND_LENGTH, stdin); // Read user input
    strtok(command, "\n"); // Remove trailing newline character
}

void execute_command(char *command) {
    char *args[MAX_COMMAND_LENGTH];
    int arg_count = 0;

    args[arg_count++] = strtok(command, " "); // Split command into arguments

    while (args[arg_count - 1] != NULL && arg_count < MAX_COMMAND_LENGTH) {
        args[arg_count++] = strtok(NULL, " "); // Continue splitting command into arguments
    }

    args[arg_count] = NULL; // Set the last argument to NULL

    pid_t pid = fork(); // Fork a new process

    if (pid < 0) {
        printf("Failed to fork process.\n");
        exit(1); // Exit with error status
    } else if (pid == 0) {
        // Child process
        execvp(args[0], args); // Execute the command
        printf("Failed to execute command.\n"); // This line should not be reached
        exit(1); // Exit with error status
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0); // Wait for child process to finish
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        print_shell_prompt(); // Display shell prompt
        read_command(command); // Read user command
        execute_command(command); // Execute user command
    }

    return 0;
}