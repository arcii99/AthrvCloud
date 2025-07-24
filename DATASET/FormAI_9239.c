//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main() {
  char buffer[BUFFER_SIZE];
  char *args[100];
  pid_t pid;
  int status;
  
  while (1) {
    printf("unix-like-shell> ");
    fgets(buffer, BUFFER_SIZE, stdin);
    int argc = 0;
    args[argc] = strtok(buffer, " \n");
    while (args[argc] != NULL) {
      argc++;
      args[argc] = strtok(NULL, " \n");
    }
    args[argc] = NULL;
    
    pid = fork();
    if (pid == 0) {
      // Child process
      if (execvp(args[0], args) == -1) {
        printf("Invalid command\n");
      }
      exit(EXIT_FAILURE);
    } else if (pid < 0) {
      printf("Fork failed\n");
    } else {
      // Parent process
      waitpid(pid, &status, 0);
    }
  }
  
  return 0;
}