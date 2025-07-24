//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: funny
#include <stdio.h>
#include <ctype.h>

int main() {
  char userInput[50]; // declare array to hold user input
  char sanitizedInput[50]; // declare array to hold sanitized user input
  int i = 0; // declare counter variable for loops

  printf("Welcome to the User Input Sanitizer!\n");
  printf("Please type in what you want to sanitize (max 49 characters):\n");
  fgets(userInput, 50, stdin); // get user input

  // loop through userInput and sanitize any non-alphabetic characters
  for (i = 0; userInput[i] != '\0'; i++) {
    if (isalpha(userInput[i])) { // if alphabetic character is found
      sanitizedInput[i] = userInput[i]; // copy it to sanitized array
    } else { // if non-alphabetic character is found
      sanitizedInput[i] = '_'; // replace it with an underscore
    }
  }

  sanitizedInput[i] = '\0'; // add null terminator to sanitized array

  printf("You typed: \"%s\"\n", userInput);
  printf("Sanitized input: \"%s\"\n", sanitizedInput);

  return 0;
}