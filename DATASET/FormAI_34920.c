//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

// Function to execute the command
void executeCommand(char **args) {
    pid_t pid = fork();

    // Child process
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("Error executing command");
            exit(EXIT_FAILURE);
        }
    } // Parent process
    else if (pid > 0) {
        int status;
        waitpid(pid, &status, 0);
    } // Error occured
    else {
        perror("Error forking");
        exit(EXIT_FAILURE);
    }
}

int main() {
    char inputBuffer[BUFFER_SIZE];
    char *args[100];
    int position = 0;

    while (1) {
        printf(">");
        fgets(inputBuffer, BUFFER_SIZE, stdin);

        char *token = strtok(inputBuffer, " \n");
        while (token != NULL) {
            args[position] = token;
            position++;
            token = strtok(NULL, " \n");
        }
        args[position] = NULL;

        executeCommand(args);

        // Reset the input buffer and argument position
        memset(inputBuffer, 0, BUFFER_SIZE);
        position = 0;
    }

    return 0;
}