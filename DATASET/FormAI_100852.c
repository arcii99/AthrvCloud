//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: unmistakable
#include <stdio.h>
#include <ctype.h>

/*
This program takes in user input, validates it, and sanitizes it by removing any special characters.
*/

int main() {

  char input[1000];
  int i, j = 0;

  printf("Enter your input: ");
  fgets(input, sizeof(input), stdin);

  //validation of input
  for (i = 0; input[i] != '\0'; i++) {
    if (!(isalpha(input[i])) && !(isspace(input[i]))) {
      printf("Invalid input! Only letters and spaces are allowed.\n");
      return 0;
    }
  }

  printf("Original Input: %s\n", input);

  //sanitization of input
  char sanitized[1000];

  for (i = 0; input[i] != '\0'; i++) {
    //check if character is a letter or space
    if (isalpha(input[i]) || isspace(input[i])) {
      //store the character in sanitized array
      sanitized[j] = input[i];
      j++;
    }
  }
  //add terminating null character to sanitized array
  sanitized[j] = '\0';

  printf("Sanitized Input: %s\n", sanitized);

  return 0;
}