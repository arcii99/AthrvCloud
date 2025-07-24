//FormAI DATASET v1.0 Category: System administration ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid;
  int status;

  pid = fork();

  if (pid == -1) {
    printf("Error: Failed to fork a child process\n");
    exit(1);
  } else if (pid == 0) {
    printf("Child process executing command: echo 'Hello, World!'\n");
    system("echo 'Hello, World!'");
    exit(0);
  } else {
    printf("Parent process waiting for child to finish executing command...\n");
    wait(&status);
    printf("Child process has finished executing command\n");
    exit(0);
  }
}