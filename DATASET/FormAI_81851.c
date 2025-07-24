//FormAI DATASET v1.0 Category: System administration ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
  pid_t pid;
  char *args[] = {"/bin/ls", "-l", NULL};
  int status;
  
  printf("Starting system administration program...\n");
  
  pid = fork();
  
  if (pid < 0) {
    printf("Error: Fork failed.\n");
    exit(1);
  }
  else if (pid == 0) {
    printf("Child process created with PID: %d\n", getpid());
    printf("Running command: %s\n", args[0]);
    execvp(args[0], args);
    printf("Error: Execvp failed.\n");
    exit(1);
  }
  else {
    printf("Parent process running with PID: %d\n", getpid());
    printf("Waiting for child process...\n");
    waitpid(pid, &status, 0);
    printf("Child process exited with status %d\n", status);
  }
  
  printf("System administration program complete.\n");
  
  return 0;
}