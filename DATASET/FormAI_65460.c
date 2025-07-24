//FormAI DATASET v1.0 Category: System administration ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("Welcome to the Happy System Administration program!\n");
  printf("What would you like to do?\n");
  printf("1. Check system status\n");
  printf("2. Restart server\n");
  printf("3. Update system packages\n");
  
  int choice;
  scanf("%d", &choice);

  switch(choice) {
    case 1:
      printf("System status:\n");
      system("uptime");
      break;
    case 2:
      printf("Are you sure you want to restart the server? Y/N\n");
      char response;
      scanf(" %c", &response);
      if(response == 'Y' || response == 'y') {
        printf("Restarting server...\n");
        system("reboot");
      } else {
        printf("Okay, server will not be restarted.\n");
      }
      break;
    case 3:
      printf("Updating system packages...\n");
      system("sudo apt-get update && sudo apt-get upgrade");
      printf("Update complete!\n");
      break;
    default:
      printf("Invalid input. Please choose a number from 1-3.\n");
  }
  
  return 0;
}