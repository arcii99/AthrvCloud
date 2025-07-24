//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 80 // Maximum characters per line supported

int main(void) {
  char *args[MAX_LINE/2 + 1]; // Command line arguments
  int should_run = 1; // Flag to determine when to exit program
  char command[MAX_LINE + 1]; // Whole command line input
  int bg = 0; // Background process flag

  while (should_run) {
    printf("mysh: "); // Print shell prompt

    fflush(stdout); // Flush buffer to print prompt

    // Read in user command line input
    fgets(command, MAX_LINE + 1, stdin);

    // Get rid of newline character at the end of the input string
    size_t input_length = strlen(command);
    if (input_length > 0 && command[input_length-1] == '\n') {
      command[input_length-1] = '\0';
    }

    // The "exit" command was entered
    if (strcmp(command, "exit") == 0) {
      should_run = 0; // Flag to exit loop
      continue; // Skip any other processing on this command
    }

    // Check if user wants to run the process in the background
    if (input_length > 2 && command[input_length-2] == '&' &&
        (command[input_length-3] == ' ' || command[input_length-3] == '\t')) {
      bg = 1; // Set background flag
      command[input_length-2] = '\0'; // Get rid of & character
    } else {
      bg = 0; // Clear background flag
    }

    // Parse the command line input into arguments
    char *token = strtok(command, " \t"); // Get first token
    int i = 0;
    while (token != NULL) {
      args[i] = token;
      i++;
      token = strtok(NULL, " \t"); // Get next token
    }
    args[i] = NULL;

    // Fork a child process
    pid_t pid;
    int status;
    pid = fork();

    if (pid < 0) { // Forking error
      fprintf(stderr, "Fork failed\n");
      continue; // Skip to next prompt
    } else if (pid == 0) { // Child process
      execvp(args[0], args);
      // The code block following execvp will only be executed if the command
      // fails to execute, since execvp replaces the current process with the
      // command process if there is no error.
      // Print an error message and exit with failure status
      fprintf(stderr, "Failed to execute command\n");
      exit(1);
    } else { // Parent process
      if (bg) { // Process is running in the background
        printf("[%d]\n", pid); // Print process ID of the background process
      } else { // Process is running in the foreground
        waitpid(pid, &status, 0); // Wait for child process to terminate
      }
    }
  }

  return 0;
}