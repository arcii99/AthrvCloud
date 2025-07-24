//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: multivariable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

#define MAX_ARGS 5 // Maximum number of arguments

int main() {
  char input[100]; // Reserve space for user input
  char* args[MAX_ARGS + 1]; // Reserve space for arguments, plus one for NULL terminator

  while (1) { // Loop infinitely for user input
    printf(">> "); // Print command prompt
    fgets(input, 100, stdin); // Get user input
    input[strcspn(input, "\n")] = 0; // Remove trailing newline character

    // If user inputs "exit", exit the shell
    if (strcmp(input, "exit") == 0) {
      printf("Exiting shell...\n");
      exit(0); // Exit the shell
    }

    // Tokenize user input into arguments
    int i = 0;
    args[i] = strtok(input, " ");
    while (args[i] != NULL && i < MAX_ARGS) {
      args[++i] = strtok(NULL, " ");
    }
    args[i] = NULL; // Set last argument to NULL for execvp

    // Create a child process to execute command
    pid_t pid = fork();
    if (pid == 0) {
      // Child process
      execvp(args[0], args);
      printf("Unknown command: %s\n", args[0]);
      exit(1); // Exit with failure
    } else if (pid < 0) {
      // Fork failed, print error message
      printf("Fork failed!\n");
      exit(1); // Exit with failure
    } else {
      // Parent process
      int status;
      waitpid(pid, &status, 0); // Wait for child process to finish
    }
  }

  return 0;
}