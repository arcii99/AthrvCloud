//FormAI DATASET v1.0 Category: System administration ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Welcome message
  printf("Welcome to the Peaceful Administration Program! \n");

  // Variables declaration
  char command[100];
  int pid; 

  // User input
  printf("Enter the name of the command: ");
  scanf("%s", command);

  printf("Enter the process ID: ");
  scanf("%d", &pid);

  // Execution of user input command
  printf("Executing %s command...\n", command);
  system(command);

  // Kill process with given process ID
  printf("Killing process with ID %d...\n", pid);
  char kill_cmd[50];
  sprintf(kill_cmd, "kill -9 %d", pid);
  system(kill_cmd);

  // Check if process was successfully killed
  char check_cmd[50];
  sprintf(check_cmd, "ps -p %d", pid);
  if (system(check_cmd) == 0) {
    printf("Process %d was not successfully terminated.\n", pid);
  } else {
    printf("Process %d was successfully terminated.\n", pid);
  }

  // Exit message
  printf("Thank you for using the Peaceful Administration Program! \n");

  return 0;
}