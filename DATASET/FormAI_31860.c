//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_ATTEMPTS 5     // maximum login attempts
#define MAX_SIZE 100       // maximum size of input buffer

int main() {

  char username[MAX_SIZE];    // buffer to store username
  char password[MAX_SIZE];    // buffer to store password
  int attempts = 0;           // counter for login attempts

  printf("Welcome to the Intrusion Detection Program.\n");

  while (attempts < MAX_ATTEMPTS) {

    printf("\nPlease enter your username: ");
    fgets(username, MAX_SIZE, stdin);    // read input from user and store in buffer

    printf("Please enter your password: ");
    fgets(password, MAX_SIZE, stdin);    // read input from user and store in buffer

    // check if login is successful
    if (strcmp(username, "admin\n") == 0 && strcmp(password, "password123\n") == 0) {
      printf("\nLogin successful. Welcome admin!\n");
      break;
    }
    else {
      printf("\nIncorrect login credentials. Please try again.\n");
      attempts++;
    }
  }

  if (attempts == MAX_ATTEMPTS) {
    printf("\nMaximum login attempts reached. Exiting program.\n");
    exit(1);
  }

  printf("\nStarting Intrusion Detection System...\n");

  // main program logic goes here

  return 0;
}