//FormAI DATASET v1.0 Category: System administration ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int n = atoi(argv[1]);
  pid_t pid;
  
  printf("Creating %d child processes...\n", n);
  
  for (int i = 0; i < n; i++) {
    pid = fork();

    if (pid < 0) {
      perror("Error forking child process");
      exit(EXIT_FAILURE);
    } else if (pid == 0) {
      char *child_args[] = {"gnome-terminal", NULL};
      execvp(child_args[0], child_args);
      // This line doesn't execute because execvp replaces the
      // current process image with the new process
      perror("Error executing child process");
      exit(EXIT_FAILURE);
    } else {
      printf("Child process %d created with PID = %d\n", i+1, pid);
    }
  }
  
  printf("Waiting for child processes to complete...\n");
  
  for (int i = 0; i < n; i++) {
    int status;
    pid_t wpid = wait(&status);
    printf("Child process with PID %d has completed with status %d\n", wpid, status);
  }
  
  printf("All child processes have completed.\n");
  
  return 0;
}