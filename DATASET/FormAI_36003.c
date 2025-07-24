//FormAI DATASET v1.0 Category: Data validation ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

  /*
    This program takes user input and validates it according to specific criteria.
    The criteria tested include: length, alphanumeric characters, and specific starting letters. 
    The user is prompted to enter a string of maximum length 50 characters.
  */

  char input[51];
  printf("Please enter a string of up to 50 characters: ");
  fgets(input, 51, stdin);

  // Remove new line character from input, if any
  if(input[strlen(input)-1] == '\n') {
    input[strlen(input)-1] = '\0';
  }

  // Check length of input
  if(strlen(input) > 50) {
    printf("The string entered is too long. Please try again.\n");
    return 0;
  }

  // Check if input contains only alphanumeric characters
  int i;
  for(i = 0; i < strlen(input); i++) {
    if(!isalnum(input[i])) {
      printf("The string entered contains non-alphanumeric characters. Please try again.\n");
      return 0;
    }
  }

  // Check if input starts with specific letters
  if(input[0] != 'a' && input[0] != 'b' && input[0]!= 'c' ) {
    printf("The string entered does not start with the correct letters. Please try again.\n");
    return 0;
  }

  // If all tests pass, output success message and return
  printf("The input is valid. Thank you!\n");
  return 0;

}