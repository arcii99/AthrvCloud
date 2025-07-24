//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1000
#define MAX_ARGS_LENGTH 100

int main() {
  char command[MAX_COMMAND_LENGTH];
  char* args[MAX_ARGS_LENGTH];
  char* token;
  int i, num_args;

  while (1) {
    printf(">> ");
    fgets(command, MAX_COMMAND_LENGTH, stdin);

    // Remove newline character
    command[strcspn(command, "\n")] = 0;

    // Split command into arguments
    i = 0;
    num_args = 0;
    token = strtok(command, " ");
    while (token != NULL) {
      args[i] = token;
      token = strtok(NULL, " ");
      num_args++;
      i++;
    }
    args[num_args] = NULL;

    // Execute command
    pid_t pid = fork();
    if (pid == 0) {
      // Child process
      execvp(args[0], args);
      perror("execvp");
      exit(EXIT_FAILURE);
    } else if (pid < 0) {
      perror("fork");
      exit(EXIT_FAILURE);
    } else {
      // Parent process
      wait(NULL);
    }
  }

  return 0;
}