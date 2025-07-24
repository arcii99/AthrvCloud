//FormAI DATASET v1.0 Category: System administration ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("Hello and welcome to the cheerful System Administration Program!\n");
  printf("What would you like to do?\n");
  printf("1. Check Disk Space\n");
  printf("2. List Running Processes\n");
  printf("3. Check Memory Usage\n");
  printf("Enter your choice: ");

  int choice;
  scanf("%d", &choice);

  switch(choice) {
    case 1:
      system("df -h");
      break;
    case 2:
      system("ps -aux");
      break;
    case 3:
      system("free -m");
      break;
    default:
      printf("Invalid choice, please choose 1-3.\n");
      break;
  }

  char hostname[100];
  gethostname(hostname, sizeof(hostname));
  printf("\n\nThank you for using this cheerful program! You were working on the machine: %s\n\n", hostname);

  return 0;
}