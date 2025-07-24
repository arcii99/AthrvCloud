//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 16
#define MAX_ARG_LEN 32
#define MAX_LINE_LEN 256

int main() {
  char line[MAX_LINE_LEN];
  char *args[MAX_ARGS + 1];
  char *arg;
  pid_t pid;
  int status;
  
  while (1) {
    // Print a prompt
    printf("> ");
    
    // Read a line of input
    if (fgets(line, MAX_LINE_LEN, stdin) == NULL) {
      break;
    }
    
    // Remove newline character
    line[strcspn(line, "\n")] = '\0';
    
    // Tokenize input into arguments
    int i = 0;
    arg = strtok(line, " ");
    while (arg != NULL && i < MAX_ARGS) {
      args[i] = arg;
      arg = strtok(NULL, " ");
      i++;
    }
    args[i] = NULL;
    
    // Handle empty input
    if (i == 0) {
      continue;
    }
    
    // Handle built-in commands
    if (strcmp(args[0], "cd") == 0) {
      if (args[1] == NULL) {
        chdir(getenv("HOME"));
      } else {
        chdir(args[1]);
      }
      continue;
    }
    if (strcmp(args[0], "exit") == 0) {
      break;
    }
    
    // Fork a new process to execute the command
    pid = fork();
    if (pid == -1) {
      perror("fork");
      exit(1);
    } else if (pid == 0) {
      // Child process
      execvp(args[0], args);
      perror("execvp");
      exit(1);
    } else {
      // Parent process
      waitpid(pid, &status, 0);
    }
  }
  
  return 0;
}