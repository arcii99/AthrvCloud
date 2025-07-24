//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  while (1) {
    printf("> ");

    char input[1024];
    fgets(input, 1024, stdin);

    char *args[64];
    char *tok;

    int i = 0;
    tok = strtok(input, " \n");

    while (tok != NULL) {
      args[i++] = tok;
      tok = strtok(NULL, " \n");
    }

    args[i] = NULL;

    if (args[0] == NULL) {
      continue;
    }

    if (strcmp(args[0], "exit") == 0) {
      printf("Exiting...\n");
      break;
    }

    pid_t pid = fork();

    if (pid < 0) {
      printf("Error forking process!\n");
    } else if (pid == 0) {
      execvp(args[0], args);
      printf("Command not found! Use 'exit' to quit.\n");
      exit(0);
    } else {
      wait(NULL);
    }
  }

  return 0;
}