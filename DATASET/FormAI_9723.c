//FormAI DATASET v1.0 Category: Password management ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PASSWORD_SIZE 10 // Max password length
#define MAX_ATTEMPTS 3 // Maximum allowed attempts to enter password

char password[PASSWORD_SIZE + 1]; // Memory to store password (add additional byte for '\0')

// Function to initialize password variable
void initPassword() {
  srand(time(NULL)); // Seed the random number generator
  for(int i = 0; i < PASSWORD_SIZE; i++) {
    password[i] = rand() % 26 + 'a'; // Generate random lowercase letters
  }
  password[PASSWORD_SIZE] = '\0'; // Add null character at the end
}

// Function to check if entered password is correct
int checkPassword(char* attempt) {
  return strcmp(password, attempt) == 0;
}

int main() {
  initPassword(); // Initialize password variable

  printf("Welcome to password protected program\n");

  for(int i = 0; i < MAX_ATTEMPTS; i++) {
    printf("Please enter the password: ");

    char attempt[PASSWORD_SIZE + 1]; // Temporary memory to store password attempt
    fgets(attempt, PASSWORD_SIZE + 1, stdin); // Read input from console
    attempt[strcspn(attempt, "\n")] = '\0'; // Remove newline character

    if(checkPassword(attempt)) {
      printf("Password accepted\n");
      break;
    } else {
      printf("Incorrect password\n");
      if(i < MAX_ATTEMPTS - 1) {
        printf("You have %d attempts left\n", MAX_ATTEMPTS - i - 1);
      } else {
        printf("You have run out of attempts\n");
      }
    }
  }

  // Rest of the program code goes here

  return 0;
}