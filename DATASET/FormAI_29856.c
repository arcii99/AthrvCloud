//FormAI DATASET v1.0 Category: Password management ; Style: innovative
#include <stdio.h>
#include <string.h>

#define MAX 20

int main() {
  char password[MAX];
  int attempts = 0;
  
  // request user input
  printf("Set a password (maximum 20 characters): ");
  scanf("%s", password);
  
  // clear screen for added security
  system("cls");
  
  // loop while user input is incorrect
  while (attempts < 3) {
    char inputPass[MAX];
    printf("Enter password: ");
    scanf("%s", inputPass);
    
    // compare user input with set password
    if (strcmp(password, inputPass) == 0) {
      printf("Access granted!");
      break;
    } else {
      printf("Incorrect password. Please try again.\n");
      attempts++;
    }
  }
  
  // lock user out after three failed attempts
  if (attempts >= 3) {
    printf("Access denied. Maximum attempts exceeded.");
    // consider sending email to user with new password or unlocking instructions
  }
  
  return 0;
}