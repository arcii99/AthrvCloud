//FormAI DATASET v1.0 Category: System administration ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
  int status;
  pid_t pid;

  // create child process
  pid = fork();

  if (pid == -1) { // error creating process
    perror("fork");
    return 1;
  }
  else if (pid == 0) { // child process
    printf("Child process running.\n");

    // execute system command to display uptime
    char command[50] = "uptime";
    system(command);

    printf("Child process complete.\n");
    exit(0);
  }
  else { // parent process
    printf("Parent process waiting for child to complete.\n");

    // wait for child to complete
    wait(&status);

    printf("Parent process complete.\n");
  }

  return 0;
}