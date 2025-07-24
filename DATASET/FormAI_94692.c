//FormAI DATASET v1.0 Category: System administration ; Style: curious
#include <stdio.h>

int main() {

  int choice;
  
  printf("Welcome to the Curious System Admin program.\n");
  printf("What would you like to do today?\n");
  printf("1. Check disk space\n");
  printf("2. Check memory usage\n");
  printf("3. Check running processes\n");
  printf("4. Quit program\n");

  while (1) {

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {

      case 1:
        printf("Checking disk space...\n");

        // insert code here to check disk space

        printf("Disk space checked successfully.\n");
        break;

      case 2:
        printf("Checking memory usage...\n");

        // insert code here to check memory usage

        printf("Memory usage checked successfully.\n");
        break;

      case 3:
        printf("Checking running processes...\n");

        // insert code here to check running processes

        printf("Running processes checked successfully.\n");
        break;

      case 4:
        printf("Thank you for using the Curious System Admin program.\n");
        return 0; // exit program

      default:
        printf("Invalid choice. Please try again.\n");
        break;

    }

  }

  return 0;

}