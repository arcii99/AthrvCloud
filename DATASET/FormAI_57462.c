//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
  char input[1024];
  char* arguments[64];
  int status;
  pid_t pid;

  printf("Welcome to the happy shell! Let's spread some joy today :)\n");

  while (1) {
    printf("happy> ");

    fgets(input, sizeof(input), stdin);

    if (strcmp(input, "exit\n") == 0) {
      printf("Hope you have a happy day! Goodbye :)\n");
      exit(0);
    }

    char* token = strtok(input, " \n");

    int i = 0;
    while (token != NULL) {
      arguments[i] = token;
      i++;
      token = strtok(NULL, " \n");
    }

    arguments[i] = NULL;

    pid = fork();
    if (pid == 0) {
      if (execvp(arguments[0], arguments) == -1) {
        printf("Oops! Something went wrong. Could not execute command.\n");
      }
      exit(0);
    } 
    else if (pid < 0) {
      printf("Oops! Something went wrong. Could not fork process.\n");
    } 
    else {
      waitpid(pid, &status, 0);
    }
  }

  return 0;
}