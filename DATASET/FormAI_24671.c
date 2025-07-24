//FormAI DATASET v1.0 Category: System administration ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <command>\n", argv[0]);
    return 1;
  }

  int i, pid, status;
  char *command = strtok(argv[1], " ");

  char *args[argc];
  args[0] = command;

  for (i = 1; i < argc; i++) {
    args[i] = strtok(NULL, " ");
  }

  args[argc] = NULL;

  switch (pid = fork()) {
    case -1:
      perror("Error while forking");
      return 1;
    case 0:
      execvp(command, args);
      perror("Error in execvp");
      _exit(1);
    default:
      waitpid(pid, &status, 0);
      printf("Exit status: %d\n", WEXITSTATUS(status));
  }

  return 0;
}