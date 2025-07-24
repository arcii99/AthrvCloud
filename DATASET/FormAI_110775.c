//FormAI DATASET v1.0 Category: System administration ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char cmd[100];
  char* username = getenv("USER"); // Get the current user's username

  printf("Welcome %s, please enter a command: ", username);

  // Prompt the user for a command to execute
  fgets(cmd, sizeof(cmd), stdin);

  if (strcmp(cmd, "reboot\n") == 0) {
    printf("Are you sure you want to reboot the system? (y/n): ");
    char confirm[2];
    fgets(confirm, sizeof(confirm), stdin);
    if (strcmp(confirm, "y\n") == 0) {
      printf("Rebooting...\n");
      // Execute the reboot command
      system("sudo reboot");
    } else {
      printf("Cancelling reboot\n");
    }
  } else if (strcmp(cmd, "shutdown\n") == 0) {
    printf("Are you sure you want to shutdown the system? (y/n): ");
    char confirm[2];
    fgets(confirm, sizeof(confirm), stdin);
    if (strcmp(confirm, "y\n") == 0) {
      printf("Shutting down...\n");
      // Execute the shutdown command
      system("sudo shutdown -h now");
    } else {
      printf("Cancelling shutdown\n");
    }
  } else if (strcmp(cmd, "update\n") == 0) {
    printf("Updating system...\n");
    // Execute the update command
    system("sudo apt-get update && sudo apt-get upgrade");
  } else if (strcmp(cmd, "users\n") == 0) {
    printf("Current users on system:\n");
    // Execute the users command
    system("users");
  } else {
    printf("Command not recognized, please try again.\n");
  }

  return 0;
}