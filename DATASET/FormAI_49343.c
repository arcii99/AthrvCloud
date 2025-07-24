//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: secure
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARGS 256
#define BUFSIZE 256

void execute(char **args) {
  pid_t pid = fork();
  if (pid == -1) {
    perror("fork");
    exit(EXIT_FAILURE);
  } else if (pid == 0) {
    if (execvp(args[0], args) == -1) {
      perror("execvp");
      exit(EXIT_FAILURE);
    }
  } else {
    int status;
    if (waitpid(pid, &status, 0) == -1) {
      perror("waitpid");
      exit(EXIT_FAILURE);
    }
  }
}

void parse_args(const char *cmdline, char **args, size_t args_size, 
                size_t *nargs) {
  char *buf = strdup(cmdline);
  if (buf != NULL) {
    size_t argindex = 0;
    char *delim = " \n\t";
    char *arg = strtok(buf, delim);
    while (arg != NULL) {
      if (argindex < args_size) {
        args[argindex++] = arg;
      }
      arg = strtok(NULL, delim);
    }
    *nargs = argindex;
    args[argindex++] = NULL;
  } else {
    perror("strdup");
    exit(EXIT_FAILURE);
  }
  free(buf);
}

int main(int argc, char **argv) {
  char cmdline[BUFSIZE];
  char *args[MAX_ARGS];
  size_t nargs;
  while (1) {
    printf("> ");
    if (fgets(cmdline, BUFSIZE, stdin) == NULL) {
      perror("fgets");
      exit(EXIT_FAILURE);
    } else {
      cmdline[strcspn(cmdline, "\n")] = '\0';
      parse_args(cmdline, args, MAX_ARGS, &nargs);
      if (nargs > 0) {
        execute(args);
      }
    }
  }
  return 0;
}