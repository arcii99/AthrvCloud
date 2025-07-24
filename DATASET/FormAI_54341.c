//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_LINE_LENGTH 100

int main(void) {
  char input[MAX_LINE_LENGTH];
  char *args[MAX_ARGS];
  int status;

  while (1) {
    printf("shell > ");
    fgets(input, MAX_LINE_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';

    char *token = strtok(input, " ");
    int i = 0;
    while (token != NULL) {
      args[i] = token;
      token = strtok(NULL, " ");
      i++;
    }
    args[i] = NULL;

    if (strcmp(args[0], "exit") == 0) {
      return 0;
    }

    pid_t pid = fork();
    if (pid == -1) {
      fprintf(stderr, "Forking failed.\n");
      exit(1);
    } else if (pid == 0) {
      execvp(args[0], args);
      fprintf(stderr, "Execution failed.\n");
      exit(1);
    } else {
      waitpid(pid, &status, 0);
    }
  }

  return 0;
}