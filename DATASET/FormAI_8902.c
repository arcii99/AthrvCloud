//FormAI DATASET v1.0 Category: System administration ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAXLINE 100

void execute_command(char *command) {
    char *args[MAXLINE/2 + 1];
    char *token;
    int i = 0;

    // Parse the command into individual arguments
    token = strtok(command, " ");
    while(token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    // Execute the command
    if (execvp(args[0], args) < 0) {
        printf("Error executing command '%s'\n", command);
        exit(1);
    }
}

int main() {
    char command[MAXLINE];

    while(1) {
        printf("Enter a command: ");
        fflush(stdout);
        fgets(command, MAXLINE, stdin);

        // Remove newline character from the end of the command string
        size_t length = strlen(command);
        if (length > 0 && command[length-1] == '\n') {
            command[length-1] = '\0';
        }

        // Fork a child process to execute the command
        pid_t pid = fork();

        if (pid < 0) {
            printf("Error forking process.\n");
            exit(1);
        }
        else if (pid == 0) {
            // Child process
            execute_command(command);
        }
        else {
            // Parent process
            waitpid(pid, NULL, 0);
        }
    }

    return 0;
}