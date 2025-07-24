//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_ARGUMENTS 64
#define DELIMITER " \t\r\n\a"

int main() {

    printf("Welcome to my Unix-like shell! Let's get started!\n");

    char input[MAX_INPUT_LENGTH];
    char *arguments[MAX_ARGUMENTS];

    while (1) {
        printf("basic-sh@: ");
        fgets(input, MAX_INPUT_LENGTH, stdin); // Read user input

        int position = 0;
        char *token = strtok(input, DELIMITER);

        while (token != NULL) {
            arguments[position] = token;
            position++;
            token = strtok(NULL, DELIMITER);
        }

        arguments[position] = NULL; // Set last argument to NULL for execvp

        pid_t pid = fork(); // Create child process

        if (pid == 0) { // Child process
            if (execvp(arguments[0], arguments) == -1) {
                printf("basic-sh: Invalid command \n");
            }
            exit(EXIT_FAILURE);
        } 
        else if (pid < 0) { // Error forking
            printf("basic-sh: Error forking \n");
        } 
        else { // Parent process
            wait(NULL);
        }
    }

    return 0;
}