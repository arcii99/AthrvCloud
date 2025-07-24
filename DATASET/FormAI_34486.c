//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define TOKEN_DELIMITER " \t\r\n\a"

char* read_input(void) {
  char* input = NULL;
  ssize_t buffer_size = 0;
  getline(&input, &buffer_size, stdin);
  return input;
}

char** split_input(char* input) {
  int buffer_size = BUFFER_SIZE;
  char** tokens = malloc(buffer_size * sizeof(char*));
  int position = 0;
  char* token;

  if (!tokens) {
    fprintf(stderr, "Error: Failed to allocate memory\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(input, TOKEN_DELIMITER);
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >= buffer_size) {
      buffer_size += BUFFER_SIZE;
      tokens = realloc(tokens, buffer_size * sizeof(char*));
      if (!tokens) {
        fprintf(stderr, "Error: Failed to allocate memory\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, TOKEN_DELIMITER);
  }
  tokens[position] = NULL;
  return tokens;
}

int execute_command(char** args) {
  pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid == 0) {
    if (execvp(args[0], args) == -1) {
      perror("Error");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    perror("Error");
  } else {
    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }
  return 1;
}

int main(void) {
  char* input;
  char** args;
  int status;

  do {
    printf("> ");
    input = read_input();
    args = split_input(input);
    status = execute_command(args);

    free(input);
    free(args);
  } while (status);

  return EXIT_SUCCESS;
}