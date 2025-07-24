//FormAI DATASET v1.0 Category: System administration ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
  pid_t pid;
  int status;

  printf("Welcome to the Synchronous System Administration Example Program\n");

  pid = fork();
  if (pid == -1) {
    printf("Error: Fork Failed\n");
    exit(1);
  } else if (pid == 0) {
    printf("Child Process: Executing Command \"ls -l\"\n");
    char *args[] = {"ls", "-l", NULL};
    execvp(args[0], args);
    printf("Error: execvp Failed\n");
    exit(1);
  } else {
    printf("Parent Process: Waiting for Child to Terminate\n");
    wait(&status);
    if (WIFEXITED(status)) {
      printf("Parent Process: Child Terminated with Status %d\n", WEXITSTATUS(status));
    } else {
      printf("Error: Child Terminated Abnormally\n");
    }
  }

  pid = fork();
  if (pid == -1) {
    printf("Error: Fork Failed\n");
    exit(1);
  } else if (pid == 0) {
    printf("Child Process: Executing Command \"ps -e\"\n");
    char *args[] = {"ps", "-e", NULL};
    execvp(args[0], args);
    printf("Error: execvp Failed\n");
    exit(1);
  } else {
    printf("Parent Process: Waiting for Child to Terminate\n");
    wait(&status);
    if (WIFEXITED(status)) {
      printf("Parent Process: Child Terminated with Status %d\n", WEXITSTATUS(status));
    } else {
      printf("Error: Child Terminated Abnormally\n");
    }
  }

  printf("Synchronous System Administration Example Program Complete\n");

  return 0;
}