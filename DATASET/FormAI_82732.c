//FormAI DATASET v1.0 Category: System administration ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the System Administration Example Program!\n");

  // Let's ask the user what they want to do
  char option;
  printf("What would you like to do today?\n");
  printf("a. Check Disk Space\n");
  printf("b. Change Password\n");
  printf("c. Clear System Logs\n");
  printf("Enter your choice (a/b/c): ");
  scanf("%c", &option);

  // Perform the corresponding action based on user input
  switch(option) {
    case 'a':
      printf("\nChecking Disk Space...\n");
      system("df -h"); // Runs "df -h" command in terminal to show disk space
      break;
    case 'b':
      printf("\nChanging Password...\n");
      system("passwd"); // Runs "passwd" command in terminal to change user's password
      break;
    case 'c':
      printf("\nClearing System Logs...\n");
      system("sudo truncate -s 0 /var/log/syslog"); // Runs "sudo truncate -s 0 /var/log/syslog" command in terminal to clear system logs
      break;
    default:
      printf("\nInvalid choice! Please select a valid option.\n");
      break;
  }

  printf("\nThank you for using our program!\n");
  return 0;
}