//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1000
#define MAX_ARGUMENTS 100

int main() {

  int status;
  char command[MAX_COMMAND_LENGTH];

  while (1) {

    printf("$ ");

    fgets(command, MAX_COMMAND_LENGTH, stdin);
    command[strcspn(command, "\n")] = 0;

    char *arguments[MAX_ARGUMENTS];
    char *token = strtok(command, " ");

    int i = 0;
    while (token != NULL) {
      arguments[i++] = token;
      token = strtok(NULL, " ");
    }
    arguments[i] = NULL;

    if (arguments[0] == NULL) {
      continue;
    }

    if (strcmp(arguments[0], "exit") == 0) {
      exit(0);
    }

    pid_t pid = fork();

    if (pid == 0) {
      execvp(arguments[0], arguments);
      printf("Command not found.\n");
      exit(0);
    }
    else {
      waitpid(pid, &status, 0);
    }

  }

  return 0;
}