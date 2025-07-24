//FormAI DATASET v1.0 Category: System administration ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char username[20], password[20];
  int attempt = 3;

  printf("Welcome to the Curious System Administration Program!\n\n");

  /* Prompt for username */
  printf("Enter your username: ");
  fgets(username, 20, stdin);

  /* Prompt for password */
  printf("Enter your password: ");
  fgets(password, 20, stdin);

  /* Check if username and password are correct */
  if (strcmp(username, "curious_admin\n") == 0 && strcmp(password, "ultimate_question\n") == 0) {
    printf("\nAccess granted!\n\n");
    printf("What would you like to do?\n");
    printf("1. Display system information\n");
    printf("2. Backup files\n");
    printf("3. Restart system\n");
    printf("4. Exit program\n");

    /* Prompt for user's choice */
    int choice = 0;
    while (choice != 4) {
      printf("\nEnter your choice: ");
      scanf("%d", &choice);

      switch (choice) {
        case 1:
          printf("\n== System Information ==\n");
          system("uname -a");
          system("uptime");
          system("free -m");
          break;

        case 2:
          printf("\n== Backup Files ==\n");
          printf("Backing up files...");
          // Code to backup files goes here
          printf("Backup completed.\n");
          break;

        case 3:
          printf("\n== Restarting system ==\n");
          printf("Are you sure you want to restart the system? (Y/N) ");
          char restart_choice;
          scanf(" %c", &restart_choice);
          if (restart_choice == 'Y' || restart_choice == 'y') {
            printf("Restarting system...");
            // Code to restart system goes here
          }
          else {
            printf("Restart cancelled.\n");
          }
          break;

        case 4:
          printf("\nExiting program...\n");
          break;

        default:
          printf("Invalid choice. Please try again.\n");
          break;
      }
    }
  }
  else {
    /* Incorrect username or password */
    printf("Invalid username or password. You have %d attempt(s) remaining.\n", attempt-1);
    attempt--;

    while (attempt > 0) {
      printf("\nEnter your username: ");
      fgets(username, 20, stdin);

      printf("Enter your password: ");
      fgets(password, 20, stdin);

      if (strcmp(username, "curious_admin\n") == 0 && strcmp(password, "ultimate_question\n") == 0) {
        printf("\nAccess granted!\n\n");
        printf("What would you like to do?\n");
        printf("1. Display system information\n");
        printf("2. Backup files\n");
        printf("3. Restart system\n");
        printf("4. Exit program\n");

        /* Prompt for user's choice */
        int choice = 0;
        while (choice != 4) {
          printf("\nEnter your choice: ");
          scanf("%d", &choice);

          switch (choice) {
            case 1:
              printf("\n== System Information ==\n");
              system("uname -a");
              system("uptime");
              system("free -m");
              break;

            case 2:
              printf("\n== Backup Files ==\n");
              printf("Backing up files...");
              // Code to backup files goes here
              printf("Backup completed.\n");
              break;

            case 3:
              printf("\n== Restarting system ==\n");
              printf("Are you sure you want to restart the system? (Y/N) ");
              char restart_choice;
              scanf(" %c", &restart_choice);
              if (restart_choice == 'Y' || restart_choice == 'y') {
                printf("Restarting system...");
                // Code to restart system goes here
              }
              else {
                printf("Restart cancelled.\n");
              }
              break;

            case 4:
              printf("\nExiting program...\n");
              break;

            default:
              printf("Invalid choice. Please try again.\n");
              break;
          }
        }
        break;
      }
      else {
        printf("Invalid username or password. You have %d attempt(s) remaining.\n", attempt-1);
        attempt--;
      }
    }
    if (attempt == 0) {
      printf("Access denied. Too many attempts.\n");
    }
  }

  return 0;
}