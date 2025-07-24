//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_BUFFER 1024
#define MAX_ARGS 64

int main(int argc, char *argv[]) {
  char buffer[MAX_BUFFER];
  char *args[MAX_ARGS];

  while (1) {
    // Print prompt and get user input
    printf("mysh$ ");
    fgets(buffer, MAX_BUFFER, stdin);

    // Remove newline character from input buffer
    buffer[strcspn(buffer, "\n")] = 0;

    // Parse command line arguments
    char *token = strtok(buffer, " ");
    int i = 0;
    while (token != NULL) {
      args[i++] = token;
      token = strtok(NULL, " ");
    }
    args[i] = NULL;

    // Fork process and execute command
    pid_t pid = fork();
    if (pid == 0) {
      // Child process: execute command
      int status = execvp(args[0], args);
      if (status == -1) {
        printf("Unknown command: %s\n", args[0]);
      }
      exit(0);
    } else if (pid > 0) {
      // Parent process: wait for child process to exit
      waitpid(pid, NULL, 0);
    } else {
      // Failed to fork process
      printf("Failed to fork process.\n");
      exit(1);
    }
  }

  return 0;
}