//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: ultraprecise
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ARGS 100
#define MAX_LENGTH 256

char *get_input(char *str) {
  printf("> ");
  return fgets(str, MAX_LENGTH, stdin);
}

void parse_input(char *input, char **args) {
  char *token;
  int i = 0;

  token = strtok(input, " \n");

  while (token != NULL) {
    args[i++] = token;
    token = strtok(NULL, " \n");
  }

  args[i] = NULL;
}

void execute_command(char **args) {
  int fd;
  int pid;
  int status;

  if ((pid = fork()) < 0) {
    perror("Error: Fork failed!");
  } else if (pid == 0) {
    if (execvp(args[0], args) < 0) {
      perror("Error: Execution failed!");
    }
    exit(0);
  } else {
    while (wait(&status) != pid) {
      ;
    }
  }
}

void output_redirect(char **args) {
  int i = 0;
  int output_fd;

  while (args[i] != NULL) {
    if (strcmp(args[i], ">") == 0) {
      output_fd = open(args[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);

      if (output_fd == -1) {
        perror("Error: Failed to create output file\n");
        exit(1);
      }

      dup2(output_fd, STDOUT_FILENO);
      close(output_fd);

      args[i] = NULL;
      break;
    }
    i++;
  }
}

void input_redirect(char **args) {
  int i = 0;
  int input_fd;

  while (args[i] != NULL) {
    if (strcmp(args[i], "<") == 0) {
      input_fd = open(args[i + 1], O_RDONLY);

      if (input_fd == -1) {
        perror("Error: Failed to open input file\n");
        exit(1);
      }

      dup2(input_fd, STDIN_FILENO);
      close(input_fd);

      args[i] = NULL;
      break;
    }
    i++;
  }
}


int main(int argc, char **argv) {
  char input[MAX_LENGTH];
  char *args[MAX_ARGS];

  while (1) {
    get_input(input);
    parse_input(input, args);

    if (args[0] != NULL) {
      if (strcmp(args[0], "cd") == 0) {
        if (chdir(args[1]) != 0) {
          perror("Error: Failed to change directory\n");
        }
      } else if (strcmp(args[0], "exit") == 0) {
        exit(0);
      } else {
        output_redirect(args);
        input_redirect(args);
        execute_command(args);
      }
    }
  }

  return 0;
}