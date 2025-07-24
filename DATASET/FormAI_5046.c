//FormAI DATASET v1.0 Category: System administration ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
  char input[100];
  char *command[10];
  pid_t pid;
  int status, i;

  while(1) {
    printf("Enter a command: ");
    fgets(input, 100, stdin);

    i = 0;
    command[i] = strtok(input, " \n");
    while(command[i] != NULL) {
      i++;
      command[i] = strtok(NULL, " \n");
    }
    command[i] = NULL;

    if(strcmp(command[0], "quit") == 0) {
      break;
    }

    pid = fork();

    if(pid < 0) {
      printf("Error occurred while forking.");
      exit(1);
    }

    if(pid == 0) {
      execvp(command[0], command);
      printf("Error occurred while executing command.\n");
      exit(1);
    } else {
      waitpid(pid, &status, 0);
    }
  }

  return 0;
}