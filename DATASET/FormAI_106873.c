//FormAI DATASET v1.0 Category: System administration ; Style: peaceful
#include <stdio.h>

int main() {
  printf("Welcome to the System Administration program.\n");
  printf("What would you like to do today?\n");

  while(1) {
    char option;
    printf("Choose an option:\n");
    printf("a: View system information\n");
    printf("b: Manage users\n");
    printf("c: Manage disk space\n");
    printf("d: Exit\n");

    scanf(" %c", &option);

    if (option == 'a') {
      printf("System information:\n");
      system("uname -a");
    } else if (option == 'b') {
      printf("Enter username:\n");
      char username[100];
      scanf(" %[^\n]%*c", username);
      char command[200];
      sprintf(command, "sudo useradd %s", username);
      system(command);
      printf("User %s added.\n", username);
    } else if (option == 'c') {
      printf("Enter directory path:\n");
      char path[200];
      scanf(" %[^\n]%*c", path);
      char command[250];
      sprintf(command, "sudo du -sh %s", path);
      system(command);
    } else if (option == 'd') {
      printf("Exiting program.\n");
      break;
    } else {
      printf("Invalid option. Try again.\n");
    }
  }

  return 0;
}