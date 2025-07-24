//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100 // Maximum length of command string
#define MAX_ARGUMENT_COUNT 10 // Maximum number of arguments allowed

int main() {
    char command[MAX_COMMAND_LENGTH]; // Command string buffer
    char* arguments[MAX_ARGUMENT_COUNT]; // Arguments array buffer
    int argument_count;
    pid_t child_pid;
    int status;

    printf("Welcome to My Shell. Type 'exit' to quit.\n\n");

    while(1) {
        // Read command input
        printf("Shell > ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // Remove trailing newline character
        command[strcspn(command, "\n")] = 0;

        // Check for exit command
        if(strcmp(command, "exit") == 0) {
            break;
        }

        // Parse arguments
        argument_count = 0;
        char* argument = strtok(command, " ");
        while(argument != NULL && argument_count < MAX_ARGUMENT_COUNT) {
            arguments[argument_count] = argument;
            argument = strtok(NULL, " ");
            argument_count++;
        }
        arguments[argument_count] = NULL; // Set last argument to NULL for execvp()

        // Fork child process
        child_pid = fork();

        if(child_pid < 0) { // Handle forking error
            perror("Forking error");
            exit(EXIT_FAILURE);
        } else if(child_pid == 0) { // Child process
            if(execvp(arguments[0], arguments) == -1) { // Execute command
                perror("Erreur occurred");
            }
            exit(EXIT_FAILURE); // Terminate child process on error
        } else if(child_pid > 0) { // Parent process
            // Wait for child process to complete
            if(waitpid(child_pid, &status, 0) == -1) {
                perror("Waiting error");
                exit(EXIT_FAILURE);
            }
            printf("Child exited with status %d\n", status);
        }
    }

    printf("Goodbye!\n");

    return 0;
}