//FormAI DATASET v1.0 Category: System administration ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define PASSWORD "password123" // Set the password for the system administration
#define MAX_ATTEMPTS 3 // Maximum number of attempts to log in before the program exits

int main() {
  char input[100]; // Declare an input buffer
  int attempts = 0; // Initialize the number of login attempts to 0
  
  printf("Welcome to the System Administration Program!\n");
  printf("Please enter the password to continue...\n");

  while (attempts < MAX_ATTEMPTS) { // Loop until all login attempts are used
    printf("Password: ");
    scanf("%s", input); // Read the input from the user
    
    if (strcmp(input, PASSWORD) == 0) { // Compare the input to the password
      printf("Password accepted. Access granted!\n");
      // Do the system administration tasks here
      
      printf("System administration tasks completed.\n");
      printf("Exiting program...\n");
      return 0; // Exit the program
    } else {
      printf("Password incorrect. Please try again.\n");
      attempts++; // Increment the number of login attempts
    }
  }
  
  printf("Maximum number of login attempts reached. Exiting program...\n");
  return 0; // Exit the program after too many failed attempts
}