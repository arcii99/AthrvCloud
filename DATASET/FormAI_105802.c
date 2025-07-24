//FormAI DATASET v1.0 Category: System administration ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100

struct User {
  char name[MAXLEN];
  char password[MAXLEN];
  char role[MAXLEN];
};

typedef struct User User;

int main() {
  User currentUser = {"", "", ""};
  int choice;

  while (1) {
    printf("Welcome to the System Administration Program.\n");
    printf("1. Create Account\n");
    printf("2. Login\n");
    printf("3. View Account Info\n");
    printf("4. Exit Program\n");
    printf("Please enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        createUser();
        break;
      case 2:
        loginUser(&currentUser);
        break;
      case 3:
        viewAccount(&currentUser);
        break;
      case 4:
        printf("Exiting program...\n");
        exit(0);
      default:
        printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}

void createUser() {
  User newUser;
  printf("Please enter your name: ");
  scanf("%s", newUser.name);

  while (1) {
    printf("Please enter a password (8-16 characters): ");
    scanf("%s", newUser.password);

    if (strlen(newUser.password) < 8 || strlen(newUser.password) > 16) {
      printf("Password must be between 8 and 16 characters long.\n");
      continue;
    }

    break;
  }

  printf("Please enter your role (admin/user): ");
  scanf("%s", newUser.role);

  FILE* fp;
  fp = fopen("users.txt", "a");

  if (fp != NULL) {
    fprintf(fp, "%s:%s:%s\n", newUser.name, newUser.password, newUser.role);
    printf("Account created successfully.\n");
    fclose(fp);
  } else {
    printf("Error creating account. Please try again.\n");
  }
}

void loginUser(User* currentUser) {
  char name[MAXLEN];
  char password[MAXLEN];
  char role[MAXLEN];

  printf("Please enter your name: ");
  scanf("%s", name);
  printf("Please enter your password: ");
  scanf("%s", password);

  FILE* fp;
  fp = fopen("users.txt", "r");

  if (fp != NULL) {
    char buffer[MAXLEN];
    char* token;

    while (fgets(buffer, MAXLEN, fp)) {
      token = strtok(buffer, ":");
      strcpy(name, token);
      token = strtok(NULL, ":");
      strcpy(password, token);
      token = strtok(NULL, ":");
      strcpy(role, token);

      if (strcmp(currentUser->name, name) == 0 && strcmp(currentUser->password, password) == 0) {
        printf("Login successful. Welcome %s!\n", currentUser->name);
        strcpy(currentUser->role, role);
        fclose(fp);
        return;
      }
    }

    printf("Invalid login credentials. Please try again.\n");
    fclose(fp);
    return;
  }

  printf("Error logging in. Please try again later.\n");
}

void viewAccount(User* currentUser) {
  if (strcmp(currentUser->name, "") == 0 || strcmp(currentUser->password, "") == 0) {
    printf("Please login first.\n");
    return;
  }

  printf("Account Information:\n");
  printf("Name: %s\n", currentUser->name);
  printf("Password: %s\n", currentUser->password);
  printf("Role: %s\n", currentUser->role);
}