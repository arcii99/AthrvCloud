//FormAI DATASET v1.0 Category: System administration ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {

  // Begin by prompting the user for a command
  char command[1000];
  printf("Enter a command: ");
  fgets(command, 1000, stdin);

  // Create a child process to execute the command
  pid_t pid = fork();

  if(pid == -1) {
    // An error occured with forking
    printf("Could not create child process.\n");
    exit(1);
  }
  else if(pid == 0) {
    // We are the child process, execute the command
    system(command);
    exit(0);
  }
  else {
    // We are the parent process, wait for the child to finish
    int status;
    waitpid(pid, &status, 0);

    if(WIFEXITED(status)) {
      // The child process exited normally
      int exit_status = WEXITSTATUS(status);
      printf("Command exited with status code %d\n", exit_status);
    }
    else if(WIFSIGNALED(status)) {
      // The child process was terminated by a signal
      int signal_num = WTERMSIG(status);
      printf("Command was terminated by signal %d\n", signal_num);
    }
    else {
      printf("Command did not exit normally\n");
    }
  }

  return 0;
}