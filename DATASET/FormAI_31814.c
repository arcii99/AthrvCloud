//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: retro
/* Retro Style User Input Sanitizer Program */

#include <stdio.h>
#include <ctype.h>
#define MAX_INPUT_LENGTH 1024

int main() {
  char input[MAX_INPUT_LENGTH];
  char sanitized_input[MAX_INPUT_LENGTH];
  int i = 0, j = 0;

  printf("Enter some text to be sanitized:\n");
  fgets(input, MAX_INPUT_LENGTH, stdin);

  while (input[i] != '\0') {
    if (isalpha(input[i])) { // check if character is a letter
      sanitized_input[j] = toupper(input[i]); // convert letter to uppercase and add to new array
      j++;
    }
    else if (isdigit(input[i])) { // check if character is a digit
      sanitized_input[j] = '$'; // replace digit with dollar sign and add to new array
      j++;
    }
    i++;
  }
  sanitized_input[j] = '\0';

  printf("\nOriginal input: %s", input);
  printf("Sanitized input: %s\n", sanitized_input);

  return 0;
}