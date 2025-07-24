//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_COMMANDS 10

int main()
{
  char command[MAX_COMMAND_LENGTH];
  char *commands[MAX_COMMANDS];
  int num_commands = 0;
  
  while (1) {
    printf(">> ");

    fgets(command, MAX_COMMAND_LENGTH, stdin);
    command[strcspn(command, "\n")] = '\0'; // remove trailing newline

    if (strcmp(command, "exit") == 0) {
      exit(0);
    }

    num_commands = 0;
    char *token = strtok(command, " ");
    while (token != NULL) {
      commands[num_commands] = token;
      num_commands++;
      token = strtok(NULL, " ");
    }
    commands[num_commands] = NULL;

    pid_t pid = fork();

    if (pid == 0) { // child process
      execvp(commands[0], commands);
      printf("Command not found\n");
      exit(1);
    } else { // parent process
      int status;
      wait(&status);
    }
  }

  return 0;
}