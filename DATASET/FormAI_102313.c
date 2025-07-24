//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>

#define BUFSIZE 1024
#define TOKEN_DELIM " \t\r\n\a" 

void prompt_loop();
char *read_line();
char **tokenize_line(char *line);
int execute(char **args);

int main(int argc, char **argv) {
  // start the shell prompt loop
  prompt_loop();

  return EXIT_SUCCESS;
}

// main shell prompt loop
void prompt_loop() {
  char *line;
  char **args;
  int status;

  do {
    printf("> ");
    line = read_line();
    args = tokenize_line(line);
    status = execute(args);

    free(line);
    free(args);
  } while (status);
}

// read the input line from the user
char *read_line() {
  char *line = NULL;
  ssize_t bufsize = 0;

  if (getline(&line, &bufsize, stdin) == -1) {
    if (feof(stdin)) {
      exit(EXIT_SUCCESS);  // exit shell upon end-of-file (Ctrl-D)
    } else {
      perror("read_line"); // handle error while reading input line
      exit(EXIT_FAILURE);
    }
  }

  return line;
}

// tokenize the input line into an array of strings (arguments)
char **tokenize_line(char *line) {
  int bufsize = BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char *));
  char *token;

  if (!tokens) {
    perror("tokenize_line"); // handle error while allocating memory
    exit(EXIT_FAILURE);
  }

  token = strtok(line, TOKEN_DELIM);
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >= bufsize) {
      bufsize += BUFSIZE;
      tokens = realloc(tokens, bufsize * sizeof(char *));
      if (!tokens) {
        perror("tokenize_line"); // handle error while allocating memory
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, TOKEN_DELIM);
  }
  tokens[position] = NULL;

  return tokens;
}

// execute the given command using fork-exec-wait mechanism
int execute(char **args) {
  pid_t pid, wpid;
  int status;

  if (args[0] == NULL) {
    return 1;  // no command entered, continue shell prompt loop
  }

  pid = fork();
  if (pid == 0) {
    // child process
    if (execvp(args[0], args) == -1) {
      perror("execute"); // handle error while executing command
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    perror("execute"); // handle error while forking child process
  } else {
    // parent process
    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}