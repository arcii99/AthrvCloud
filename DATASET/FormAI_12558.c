//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100   // Maximum length of command
#define MAX_ARGUMENTS 10         // Maximum number of arguments

void handle_command(char *command, char *arguments[]) {
    pid_t pid = fork();
    if (pid == -1) {
        printf("Fork failed\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        execvp(command, arguments);
        printf("Command not found\n");
        exit(1);
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH + 1];     // Command inputted by the user
    char *arguments[MAX_ARGUMENTS + 1];     // Arguments to pass to the command
    int argument_index = 0;                 // Counter for arguments
    while (1) {
        printf(">> ");
        fflush(stdout);
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        // Remove end of line character from input
        input[strcspn(input, "\n")] = 0;
        // Parse arguments from input
        argument_index = 0;
        arguments[argument_index] = strtok(input, " ");
        while (arguments[argument_index] != NULL && argument_index < MAX_ARGUMENTS) {
            argument_index++;
            arguments[argument_index] = strtok(NULL, " ");
        }
        if (arguments[0] != NULL) {
            // Handle command
            handle_command(arguments[0], arguments);
        }
    }
    return 0;
}