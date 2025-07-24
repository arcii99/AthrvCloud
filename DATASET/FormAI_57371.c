//FormAI DATASET v1.0 Category: System administration ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_COMMANDS 5
#define MAX_CHARS 100

void addUser(char users[][MAX_CHARS], int* userCount);
void deleteUser(char users[][MAX_CHARS], int* userCount);
void listUsers(char users[][MAX_CHARS], int* userCount);
void executeCommand(char commands[][MAX_CHARS], int* commandCount);

int main() {
  char users[MAX_USERS][MAX_CHARS];
  char commands[MAX_COMMANDS][MAX_CHARS] = {"adduser", "deluser", "listusers", "execute", "exit"};

  int userCount = 0;
  int commandCount = 5;
  char input[MAX_CHARS];

  // Welcome message
  printf("Welcome to the System Administration program.\n\n");

  while (1) {
    // Ask for user input
    printf("\nEnter a command: ");
    fgets(input, MAX_CHARS, stdin);
    strtok(input, "\n"); // remove newline character

    // Determine command and execute
    if (strcmp(input, commands[0]) == 0) {
      addUser(users, &userCount);
    } else if (strcmp(input, commands[1]) == 0) {
      deleteUser(users, &userCount);
    } else if (strcmp(input, commands[2]) == 0) {
      listUsers(users, &userCount);
    } else if (strcmp(input, commands[3]) == 0) {
      executeCommand(commands, &commandCount);
    } else if (strcmp(input, commands[4]) == 0) {
      printf("Exiting program...\n");
      exit(0);
    } else {
      printf("Invalid command. Try again.\n");
    }
  }

  return 0;
}

void addUser(char users[][MAX_CHARS], int* userCount) {
  // Check if maximum number of users has been reached
  if (*userCount == MAX_USERS) {
    printf("Maximum number of users reached.\n");
    return;
  }

  // Ask for username
  printf("\nEnter username: ");
  fgets(users[*userCount], MAX_CHARS, stdin);
  strtok(users[*userCount], "\n"); // remove newline character

  printf("User %s added.\n", users[*userCount]);
  (*userCount)++;
}

void deleteUser(char users[][MAX_CHARS], int* userCount) {
  if (*userCount == 0) {
    printf("No users to delete.\n");
    return;
  }

  // Ask for username
  printf("\nEnter username to delete: ");
  char input[MAX_CHARS];
  fgets(input, MAX_CHARS, stdin);
  strtok(input, "\n"); // remove newline character

  // Find username
  int index = -1;
  for (int i = 0; i < *userCount; i++) {
    if (strcmp(users[i], input) == 0) {
      index = i;
      break;
    }
  }

  // Delete user if found
  if (index != -1) {
    for (int i = index; i < *userCount - 1; i++) {
      strcpy(users[i], users[i+1]);
    }
    (*userCount)--;
    printf("User %s deleted.\n", input);
  } else {
    printf("User not found.\n");
  }
}

void listUsers(char users[][MAX_CHARS], int* userCount) {
  printf("\nCurrent users:\n");
  for (int i = 0; i < *userCount; i++) {
    printf("- %s\n", users[i]);
  }
}

void executeCommand(char commands[][MAX_CHARS], int* commandCount) {
  printf("\nEnter command to execute: ");
  char input[MAX_CHARS];
  fgets(input, MAX_CHARS, stdin);
  strtok(input, "\n"); // remove newline character

  // Check if valid command
  int valid = 0;
  for (int i = 0; i < *commandCount; i++) {
    if (strcmp(input, commands[i]) == 0) {
      printf("Executing command %s...\n", input);
      valid = 1;
      break;
    }
  }
  if (!valid) {
    printf("Invalid command.\n");
  }
}