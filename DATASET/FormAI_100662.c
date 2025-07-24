//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    char input[1000];
    char *args[100];

    printf("Hello! Welcome to the Happy Shell!\n"); // Cheerful greeting
    while(1) { // Loop forever
        printf("\033[1;33m"); // Set text color to yellow
        printf("happy-sh> "); // Cheerful command prompt
        printf("\033[0m"); // Reset text color
        fgets(input, 1000, stdin); // Get user input
        input[strlen(input) - 1] = '\0'; // Remove newline
        if(strcmp(input, "exit") == 0) { // Exit command
            printf("Goodbye! Have a happy day!\n"); // Cheerful goodbye
            exit(0);
        }
        int i = 0;
        args[i] = strtok(input, " "); // Tokenize the input
        while(args[i] != NULL) {
            i++;
            args[i] = strtok(NULL, " ");
        }
        pid_t pid = fork(); // Create a child process
        if(pid == 0) { // Child process
            if(execvp(args[0], args) == -1) { // Run the command
                printf("\033[1;31m"); // Set text color to red
                printf("Command not found: %s\n", args[0]); // Cheerful error message
                printf("\033[0m"); // Reset text color
            }
            exit(0);
        } else if(pid > 0) { // Parent process
            wait(NULL); // Wait for the child to finish
        } else { // Error
            printf("\033[1;31m"); // Set text color to red
            printf("An error occurred.\n"); // Cheerful error message
            printf("\033[0m"); // Reset text color
        }
    }
    return 0;
}