//FormAI DATASET v1.0 Category: System administration ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
  pid_t pid;
  int status;

  printf("Welcome to System Administration Example Program!\n\n");

  pid = fork();

  if (pid < 0) {
    fprintf(stderr, "Error: Unable to create child process\n");
    exit(1);
  } else if (pid == 0) {
    // Child process executes these commands
    printf("Child process executing command: uname -a\n");
    system("uname -a");
    printf("\nChild process executing command: df -h\n");
    system("df -h");
  } else {
    // Parent process waits for child to finish
    waitpid(pid, &status, 0);

    printf("\nParent process executing command: ps -ef\n");
    system("ps -ef");

    printf("\nSystem Administration Example Program is complete.\n");
  }

  return 0;
}