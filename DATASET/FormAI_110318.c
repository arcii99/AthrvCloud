//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10

int main() {
  printf("Wow, I can't believe I'm actually writing a shell program in C!\n");
  printf("I wonder what kind of crazy commands I'll be able to run...\n\n");

  while (1) {
    char input[100];
    printf("Enter a command: ");
    fgets(input, 100, stdin);

    if (strlen(input) > 1) {
      // Remove newline character from input
      input[strlen(input)-1] = '\0';

      // Parse command and arguments
      char* args[MAX_ARGS];
      char* token;
      int i = 0;

      token = strtok(input, " ");
      args[i] = token;

      while (token != NULL && i < MAX_ARGS-1) {
        i++;
        token = strtok(NULL, " ");
        args[i] = token;
      }

      // Fork and exec command
      int pid = fork();

      if (pid == -1) {
        printf("Error: fork failed\n");
      }
      else if (pid == 0) {
        execvp(args[0], args);
        printf("Error: command not found\n");
        exit(1);
      }
      else {
        // Wait for child process to complete
        int status;
        wait(&status);
      }
    }
    else {
      printf("Please enter a command\n");
    }
  }

  return 0;
}