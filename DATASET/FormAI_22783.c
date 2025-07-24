//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: visionary
/*
 *  Visionary Unix-like Shell
 *  Author: Your Name
 *  Description: A simple shell implementation in C that provides core shell functionalities.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_NUM_OF_ARGUMENTS 10

void display_prompt();
int parse_command(char *command, char **arguments);
void execute_command(char **arguments);

int main(int argc, char const *argv[]) {
  char command[MAX_COMMAND_LENGTH];
  char *arguments[MAX_NUM_OF_ARGUMENTS];
  int num_of_arguments;

  while (1) {
    display_prompt();
    fgets(command, MAX_COMMAND_LENGTH, stdin);
    num_of_arguments = parse_command(command, arguments);
    execute_command(arguments);
  }

  return 0;
}

void display_prompt() {
  printf("Visionary Shell>> ");
  fflush(stdout);
}

int parse_command(char *command, char **arguments) {
  int i = 0;
  char *token;

  token = strtok(command, " \n");
  while (token != NULL) {
    arguments[i++] = token;
    token = strtok(NULL, " \n");
  }

  arguments[i] = NULL;
  return i;
}

void execute_command(char **arguments) {
  pid_t pid;
  int status;

  if (strcmp(arguments[0], "exit") == 0) {
    exit(0); // Bye Bye Message
  }

  pid = fork();
  if (pid == 0) {
    execvp(arguments[0], arguments);
    printf("Command Not Found!\n");
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    printf("Could Not fork!\n");
  } else {
    waitpid(pid, &status, 0);
  }
}