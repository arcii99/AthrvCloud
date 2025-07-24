//FormAI DATASET v1.0 Category: System administration ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
  char command[BUFFER_SIZE];

  printf("Welcome to the System Administration Example Program!\n");
  printf("Enter a command to execute: ");

  while (fgets(command, BUFFER_SIZE, stdin)) {
    if (strlen(command) == 1 && command[0] == '\n') {
      printf("Enter a command to execute: ");
      continue;
    }

    command[strcspn(command, "\n")] = 0;

    pid_t pid = fork();

    if (pid < 0) {
      perror("Fork failed");
      exit(EXIT_FAILURE);
    } else if (pid == 0) { // Child process
      char *args[] = { "/bin/sh", "-c", command, NULL };
      execvp(args[0], args);

      perror("Execvp failed");
      exit(EXIT_FAILURE);
    } else { // Parent process
      int status;
      waitpid(pid, &status, 0);

      if (WIFEXITED(status) && !WEXITSTATUS(status)) {
        printf("Command executed successfully\n");
      } else {
        printf("Command failed to execute\n");
      }

      printf("Enter a command to execute: ");
    }
  }
  return 0;
}