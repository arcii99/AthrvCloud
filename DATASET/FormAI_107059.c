//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define constants for max length of input and max number of attempts
#define MAX_INPUT_LENGTH 50
#define MAX_ATTEMPTS 3

// function to check if user input matches password
int authenticate(char password[]) {
  char input[MAX_INPUT_LENGTH];
  int num_attempts = 0;

  while (num_attempts < MAX_ATTEMPTS) {
    printf("Enter Password: ");
    scanf("%s", input);
    if (strcmp(input, password) == 0) {
      printf("Access Granted\n");
      return 1;
    }
    else {
      printf("Incorrect Password\n");
      num_attempts++;
    }
  }

  printf("Access Denied\n");
  return 0;
}

int main() {
  char password[] = "password123"; // set password to be used for authentication
  char input[MAX_INPUT_LENGTH]; // initialize input array to store user input

  // prompt user for input and call authenticate function to check if it matches password
  printf("Enter Password to Access System: ");
  scanf("%s", input);

  if (strcmp(input, password) == 0) {
    printf("Access Granted\n");
  }
  else {
    printf("Access Denied\n");
    authenticate(password);
  }

  return 0; // exit program
}