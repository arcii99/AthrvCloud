//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: careful
#include <stdio.h>
#include <string.h>

/*
This program demonstrates a user input sanitizer that removes all non-alphanumeric characters from
a given string. The sanitized string is then displayed back to the user.
*/

int main() {
  char input[1000], sanitized_string[1000];
  int i, j;

  printf("Enter a string: ");
  fgets(input, sizeof(input), stdin);

  // loop over each character in the input string
  j = 0;
  for (i = 0; i < strlen(input); i++) {
    if (isalnum(input[i])) {
      // if the character is alphanumeric, add it to the sanitized string
      sanitized_string[j++] = input[i];
    }
  }

  // terminate the sanitized string
  sanitized_string[j] = '\0';

  printf("The sanitized string is: %s\n", sanitized_string);

  return 0;
}