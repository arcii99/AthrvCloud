//FormAI DATASET v1.0 Category: Password management ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
  char platform[50];
  char username[50];
  char password[50];
};

void printAccount(struct Account account) {
  printf("Platform: %s\n", account.platform);
  printf("Username: %s\n", account.username);
  printf("Password: %s\n\n", account.password);
}

int main() {
  char choice[5];
  struct Account accounts[100];
  int count = 0;
  int i;

  while (1) {
    printf("Please select an option:\n");
    printf("1. Add new account\n");
    printf("2. Print all accounts\n");
    printf("3. Search for an account\n");
    printf("4. Delete an account\n");
    printf("5. Quit\n");

    fgets(choice, 5, stdin);

    if (strcmp(choice, "1\n") == 0) {
      printf("Enter platform name: ");
      fgets(accounts[count].platform, 50, stdin);

      printf("Enter username: ");
      fgets(accounts[count].username, 50, stdin);

      printf("Enter password: ");
      fgets(accounts[count].password, 50, stdin);

      count++;
    } else if (strcmp(choice, "2\n") == 0) {
      for (i = 0; i < count; i++) {
        printAccount(accounts[i]);
      }
    } else if (strcmp(choice, "3\n") == 0) {
      char search[50];
      int found = 0;

      printf("Enter search query: ");
      fgets(search, 50, stdin);

      for (i = 0; i < count; i++) {
        if (strstr(accounts[i].platform, search) ||
            strstr(accounts[i].username, search) ||
            strstr(accounts[i].password, search)) {
          printAccount(accounts[i]);
          found = 1;
        }
      }

      if (!found) {
        printf("No accounts found.\n");
      }
    } else if (strcmp(choice, "4\n") == 0) {
      char search[50];
      int found = 0;

      printf("Enter platform name: ");
      fgets(search, 50, stdin);

      for (i = 0; i < count; i++) {
        if (strcmp(accounts[i].platform, search) == 0) {
          found = 1;
          printf("Account deleted: ");
          printAccount(accounts[i]);
          memmove(accounts + i, accounts + i + 1, (count - i - 1) * sizeof(struct Account));
          count--;
        }
      }

      if (!found) {
        printf("Account not found.\n");
      }
    } else if (strcmp(choice, "5\n") == 0) {
      break;
    } else {
      printf("Invalid choice\n");
    }
  }

  return 0;
}