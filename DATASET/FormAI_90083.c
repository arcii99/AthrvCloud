//FormAI DATASET v1.0 Category: System administration ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s command\n", argv[0]);
    return 1;
  }

  int pid = fork();

  if (pid == 0) {
    // child process
    char *args[argc];
    for (int i = 1; i < argc; i++) {
      args[i - 1] = argv[i];
    }
    args[argc - 1] = NULL;

    execvp(args[0], args);
    perror("execvp");
    return 1;
  } else if (pid > 0) {
    // parent process
    int status;
    waitpid(pid, &status, 0);
    if (WIFEXITED(status)) {
      printf("Command exited with status code %d\n", WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
      printf("Command terminated by signal %d\n", WTERMSIG(status));
    }
  } else {
    // fork error
    perror("fork");
    return 1;
  }

  return 0;
}