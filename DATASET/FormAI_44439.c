//FormAI DATASET v1.0 Category: System administration ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {

  // Welcome message
  printf("Welcome to Grateful System Admin!\n\n");
  
  // User input
  int num_processes;
  printf("How many processes would you like to run?\n");
  scanf("%d", &num_processes);

  // Process creation loop
  int i;
  for (i = 0; i < num_processes; i++) {
    pid_t pid = fork();

    // Check for error in forking child process
    if (pid < 0) {
      printf("Error: Could not fork child process.\n");
      exit(1);
    }

    // Child process code
    if (pid == 0) {
      printf("Child process running! Process ID: %d\n", getpid());
      sleep(10);
      printf("Child process finished! Process ID: %d\n", getpid());
      exit(0);
    }

    // Parent process code
    else {
      printf("Parent process waiting for child process to finish. Process ID: %d\n", getpid());
      wait(NULL);
      printf("Child process finished! Process ID: %d\n\n", pid);
    }
  }

  // Goodbye message
  printf("Thank you for using Grateful System Admin!\n");

  return 0;
}