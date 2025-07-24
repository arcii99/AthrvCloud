//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

int main() {
  char command[MAX_COMMAND_LENGTH];
  pid_t pid;
  int status;
  
  while(1) {
    printf("Enter a command: ");
    fgets(command, MAX_COMMAND_LENGTH, stdin);
    command[strcspn(command, "\n")] = 0; // remove trailing newline
    
    pid = fork();
    
    if (pid == 0) { // child process
      char *argv[] = {"/bin/sh", "-c", command, NULL};
      execvp(argv[0], argv);
      perror("execvp failed");
      exit(EXIT_FAILURE);
    }
    else if (pid < 0) { // error
      perror("fork failed");
      exit(EXIT_FAILURE);
    }
    else { // parent process
      waitpid(pid, &status, 0);
      if (WIFEXITED(status)) {
        printf("Command exited with status %d\n", WEXITSTATUS(status));
      }
    }
  }
  
  return EXIT_SUCCESS;
}