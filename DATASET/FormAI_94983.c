//FormAI DATASET v1.0 Category: Data validation ; Style: energetic
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main() {

  // Welcome message
  printf("Welcome to the Data Validation Program! Let's make sure your input is valid.\n\n");

  // Prompt user for input
  printf("Please enter your name (letters only): ");

  // Get user input
  char name[50];
  fgets(name, sizeof(name), stdin);

  // Remove newline character from input
  name[strcspn(name, "\n")] = 0;

  // Validate input - ensure input contains only letters
  bool validInput = true;
  for (int i = 0; i < strlen(name); i++) {
    if (!isalpha(name[i])) {
      validInput = false;
      break;
    }
  }

  // Output validation result
  if (validInput) {
    printf("\nCongratulations, your name is valid!\n");
  } else {
    printf("\nSorry, your name is invalid. Please enter a name containing letters only.\n");
  }

  // Prompt user to exit program
  printf("\nPress Enter to exit the program...");
  getchar();

  return 0;

}