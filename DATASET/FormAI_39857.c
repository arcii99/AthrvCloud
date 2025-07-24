//FormAI DATASET v1.0 Category: System administration ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  pid_t pid;
  int status;

  if (argc != 2) {
    printf("Usage: %s [num-arguments]\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Fork a child process
  pid = fork();

  if (pid < 0) {
    perror("fork error");
    exit(EXIT_FAILURE);
  } else if (pid == 0) {
    // Child process
    char *new_argv[] = {"./my_program", argv[1], NULL};
    execvp(new_argv[0], new_argv);
    perror("execvp error");
    exit(EXIT_FAILURE);
  } else {
    // Parent process
    waitpid(pid, &status, 0);
    if (WIFEXITED(status)) {
      printf("Child process exited with status %d\n", WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
      printf("Child process terminated with signal %d\n", WTERMSIG(status));
    }
  }

  return 0;
}