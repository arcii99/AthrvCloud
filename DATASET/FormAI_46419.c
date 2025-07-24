//FormAI DATASET v1.0 Category: System administration ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int user_input, password_input;

  printf("Please enter your username: ");
  scanf("%d", &user_input);
  printf("Please enter your password: ");
  scanf("%d", &password_input);

  if (user_input == 1234 && password_input == 4321) {
    printf("Welcome, admin!\n");
    printf("What would you like to do?\n");
    printf("1. Check system status\n");
    printf("2. Update software\n");
    printf("3. Restart server\n");
    printf("4. Exit\n");
    printf("Selection: ");
    scanf("%d", &user_input);

    switch(user_input) {
    case 1:
      system("top");
      break;
    case 2:
      system("sudo apt-get update");
      system("sudo apt-get upgrade");
      break;
    case 3:
      printf("Are you sure you want to restart the server? (y/n)\n");
      char c = getchar();
      if (c == 'y') {
        system("sudo reboot");
      }
      break;
    case 4:
      printf("Exiting...\n");
      exit(0);
    default:
      printf("Invalid selection.\n");
      break;
    }
  } else {
    printf("Invalid username or password.\n");
  }

  return 0;
}