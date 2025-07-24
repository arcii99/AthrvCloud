//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: ultraprecise
//This program simulates a basic Unix-like shell interface.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 50
#define MAX_ARGS 10

//Function to tokenize the user input command.
void tokenize(char *input, char **args) {
  int i = 0;
  args[i] = strtok(input, " \n\t");
  while ((args[++i] = strtok(NULL, " \n\t")) && i < MAX_ARGS-1);
  args[i] = NULL;
}

int main() {
  char input[MAX_CMD_LENGTH + 1], *args[MAX_ARGS + 1];
  int status;

  while (1) {
    //Print the shell prompt.
    printf("$ ");

    //Read the user input command.
    if (fgets(input, MAX_CMD_LENGTH + 1, stdin) == NULL) {
      printf("\n");
      break;
    }

    //Tokenize the user input command.
    tokenize(input, args);

    //Execute the command.
    if (args[0] != NULL) {
      pid_t pid = fork();

      if (pid == -1) {
        perror("fork");
      } else if (pid == 0) {
        execvp(args[0], args);
        perror("execvp");
        exit(EXIT_FAILURE);
      } else {
        wait(&status);

        if (WIFEXITED(status)) {
          printf("Child exited with status %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
          printf("Child terminated due to signal %d\n", WTERMSIG(status));
        } else if (WIFSTOPPED(status)) {
          printf("Child stopped due to signal %d\n", WSTOPSIG(status));
        }
      }
    }
  }

  return 0;
}