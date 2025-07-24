//FormAI DATASET v1.0 Category: Password management ; Style: calm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_USERNAME_LENGTH 20
#define MAX_USERS 100

/* User Struct */
typedef struct {
  char username[MAX_USERNAME_LENGTH];
  char password[MAX_PASSWORD_LENGTH];
} User;

/* Global Variables */
User users[MAX_USERS];
int numUsers = 0;

/* Function prototypes */
void printMenu();
void addUser();
void removeUser();
void changePassword();
void printAllUsers();
int searchUser(char *username);
char* getPassword();
void clearStdin();

int main() {
 int choice;
  
  do {
    printMenu();

    scanf("%d", &choice);
    clearStdin(); // Clears any remaining characters in stdin

    switch(choice) {
      case 1: 
        addUser();
        break;
      case 2:
        removeUser();
        break;
      case 3: 
        changePassword();
        break;
      case 4: 
        printAllUsers();
        break;
      case 5:
        printf("Goodbye!");
        break;
      default: 
        printf("Invalid choice. Please try again.\n");
    }
  
  } while (choice != 5);

  return 0;
}

/* Function definitions */

/* Prints the menu of options */
void printMenu() {
  printf("\nPlease choose an option:\n");
  printf("1. Add User\n");
  printf("2. Remove User\n");
  printf("3. Change Password\n");
  printf("4. Print All Users\n");
  printf("5. Exit\n");
  printf("Enter choice: ");
}

/* Adds a new user to the system */
void addUser() {
  User newUser;

  printf("\nEnter a new username (max length %d): ", MAX_USERNAME_LENGTH);
  fgets(newUser.username, MAX_USERNAME_LENGTH, stdin);
  newUser.username[strcspn(newUser.username, "\n")] = 0; // Removes newline character at end of string

  if (searchUser(newUser.username) != -1) { 
    printf("\nUsername already exists. Please try again with a different username.\n"); 
    return;
  }

  printf("\nEnter a new password (max length %d): ", MAX_PASSWORD_LENGTH);
  fgets(newUser.password, MAX_PASSWORD_LENGTH, stdin);
  newUser.password[strcspn(newUser.password, "\n")] = 0;

  // Add the new user to the users array
  users[numUsers] = newUser;
  numUsers++;

  printf("\nUser added successfully!\n");
}

/* Removes an existing user from the system */
void removeUser() {
  char inputUsername[MAX_USERNAME_LENGTH];
  int userIndex;

  printf("\nEnter the username of the user you would like to remove: ");
  fgets(inputUsername, MAX_USERNAME_LENGTH, stdin);
  inputUsername[strcspn(inputUsername, "\n")] = 0;

  userIndex = searchUser(inputUsername);

  if (userIndex == -1) {
    printf("\nUser not found. Please try again.\n");
    return;
  }

  // Shift all users after the removed user down by one index
  for (int i = userIndex; i < numUsers - 1; i++) {
    users[i] = users[i+1];
  }
  numUsers--;

  printf("\nUser removed successfully!\n");
}

/* Changes the password of an existing user */
void changePassword() {
  char inputUsername[MAX_USERNAME_LENGTH];
  char *newPassword;
  int userIndex;

  printf("\nEnter the username of the user whose password you would like to change: ");
  fgets(inputUsername, MAX_USERNAME_LENGTH, stdin);
  inputUsername[strcspn(inputUsername, "\n")] = 0;

  userIndex = searchUser(inputUsername);

  if (userIndex == -1) {
    printf("\nUser not found. Please try again.\n");
    return;
  }

  newPassword = getPassword(); // Prompts user for new password
  strncpy(users[userIndex].password, newPassword, MAX_PASSWORD_LENGTH);

  printf("\nPassword updated successfully!\n");
}

/* Prints a list of all users */
void printAllUsers() {
  printf("\nList of all users:\n");
  for (int i = 0; i < numUsers; i++) {
    printf("%d. Username: %s, Password: %s\n", i+1, users[i].username, users[i].password); 
  }
}

/* Searches for a user in the users array and returns their index if found. Returns -1 if not found. */
int searchUser(char *username) {
  for (int i = 0; i < numUsers; i++) {
    if (strcmp(users[i].username, username) == 0) {
      return i;
    }
  }
  return -1;
}

/* Prompts the user for a new password and returns it */
char* getPassword() {
  static char password[MAX_PASSWORD_LENGTH];

  printf("\nEnter the new password (max length %d): ", MAX_PASSWORD_LENGTH);
  fgets(password, MAX_PASSWORD_LENGTH, stdin);
  password[strcspn(password, "\n")] = 0;

  return password;
}

/* Clears any remaining characters in stdin */
void clearStdin() {
  while (getchar() != '\n') {}
}