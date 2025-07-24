//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: happy
#include <stdio.h>

int main() {
  printf("Hello! This is an Intrusion Detection System program.\n");
  printf("Please enter the password to continue: ");
  // Initializing variables
  char password[21];
  int attempts = 0;
  
  // Loop to allow for multiple attempts
  while (attempts < 3) {
    scanf("%s", password);
    
    // If password is correct, exit program
    if (strcmp(password, "MyHappyPassword123") == 0) {
      printf("Welcome to the system!\n");
      return 0;
    } 
    // If password is incorrect, prompt user to try again
    else {
      attempts++;
      printf("Invalid password. Please try again: ");
    }
  }
  
  // If all attempts are used up, exit program with an error message
  printf("Sorry, you have been locked out of the system. Please contact the administrator for assistance.\n");
  return 1;
}