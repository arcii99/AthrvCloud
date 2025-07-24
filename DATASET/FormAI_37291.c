//FormAI DATASET v1.0 Category: System administration ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {

  pid_t pid = fork(); // Create a new child process

  if (pid == -1) {
    printf("Oh no! Something went wrong with process creation.\n");
    exit(1);
  }
  else if (pid == 0) { // Child process code goes here
    printf("I am the child! My PID is %d and my parent's PID is %d.\n", getpid(), getppid());
    char* args[] = {"ls", "-la", NULL}; // Command-line arguments for `ls -la`
    execvp(args[0], args); // Execute the command
  }
  else { // Parent process code goes here
    printf("I am the parent! My PID is %d and my child's PID is %d.\n", getpid(), pid);
    wait(NULL); // Wait for the child process to finish
    printf("Child process has finished!\n");
  }

  return 0;
}