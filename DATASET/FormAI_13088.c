//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_ARGS 10 // Maximum number of arguments for a command
#define MAX_CMD_LENGTH 100 // Maximum length of a command

int main() {
    char input_str[MAX_CMD_LENGTH]; // Holds the input string entered by the user

    while(1) {
        printf(">> ");
        fgets(input_str, MAX_CMD_LENGTH, stdin); // Read the input string from the user

        // Remove the trailing newline character from the input string
        input_str[strcspn(input_str, "\n")] = 0;

        // Split the input string into individual segments (arguments) based on the ' ' delimiter
        char* token;
        char* args[MAX_ARGS];
        int i = 0;
        token = strtok(input_str, " ");

        while(token != NULL) {
            args[i] = token;
            i++;

            if(i >= MAX_ARGS) {
                printf("Error: too many arguments\n");
                break;
            }

            token = strtok(NULL, " ");
        }
        args[i] = NULL; // The command must be terminated with NULL

        // Create a child process to execute the command
        pid_t pid = fork();

        if(pid == -1) {
            printf("Error: fork failed\n");
            exit(1);
        }
        else if(pid == 0) {
            // This code block is executed by the child process

            // Replace the child process with the specified command
            if(execvp(args[0], args) == -1) {
                printf("Error: failed to execute command: %s\n", args[0]);
                exit(1);
            }

            exit(0);
        }
        else {
            // This code block is executed by the parent process

            // Wait for the child process to complete
            int status;
            if(waitpid(pid, &status, 0) == -1) {
                printf("Error: waitpid failed\n");
                exit(1);
            }

            if(WIFEXITED(status)) {
                // If the child process completed normally, display its exit status
                printf("Command exited with status: %d\n", WEXITSTATUS(status));
            }
        }
    }

    return 0;
}