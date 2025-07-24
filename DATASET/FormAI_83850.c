//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 80   // The maximum length command
#define MAX_ARGS 10   // Maximum arguments that can be passed

int main(void) {
  char *args[MAX_ARGS];  // Holds arguments for commands
  char cmd[MAX_LINE];    // Holds the command input by user
  int should_run = 1;    // Flag to determine when to exit program

  while (should_run) {
    printf("osh> ");            // Print shell prompt
    fflush(stdout);             // Flush output buffer
    fgets(cmd, MAX_LINE, stdin);   // Read input command
    cmd[strcspn(cmd, "\n")] = 0;    // Remove trailing newline

    if (strcmp(cmd, "exit") == 0) {  // Check for exit command
      should_run = 0;
      continue;
    }

    // Tokenize input command string and store in args array
    int arg_count = 0;  // Count number of arguments
    char *token = strtok(cmd, " ");
    while (token != NULL && arg_count < MAX_ARGS - 1) {
      args[arg_count] = token;
      arg_count++;
      token = strtok(NULL, " ");
    }
    args[arg_count] = NULL;   // Last argument must be a NULL pointer

    // Fork process
    pid_t pid;
    int status;
    pid = fork();

    if (pid < 0) {   // Fork failed
      printf("Fork failed\n");
      exit(EXIT_FAILURE);
    } else if (pid == 0) {   // Child process
      if (execvp(args[0], args) == -1) {   // Execute command
        printf("Command not found\n");
        exit(EXIT_FAILURE);
      }
    } else {   // Parent process
      do {
        waitpid(pid, &status, WUNTRACED);
      } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
  }

  return 0;
}