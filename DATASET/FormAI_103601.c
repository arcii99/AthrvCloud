//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD "myPassword"

int main() {
  char userInput[50];

  for(int i = 0; i < 3; i++) {
    printf("Enter password:\n");
    fgets(userInput, 50, stdin);

    // Remove newline character from input
    userInput[strcspn(userInput, "\n")] = '\0';

    // Check if password is correct
    if(strcmp(userInput, PASSWORD) == 0) {
      printf("Password correct.\n");
      // Allow access to remote control
      printf("Remote controlling drone...\n");
      // Drone control code would go here
      return 0;
    } else {
      printf("Incorrect password, please try again.\n");
    }
  }

  // If loop finishes, too many incorrect attempts
  printf("Too many incorrect attempts, exiting program.\n");
  return 1;
}