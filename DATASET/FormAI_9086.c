//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

int main() {
  char input[MAX_INPUT_LENGTH];
  printf("Please enter your input: ");
  fgets(input, MAX_INPUT_LENGTH, stdin);
  size_t len = strlen(input);

  // Remove any trailing newline character
  if (input[len-1] == '\n') {
    input[len-1] = '\0';
    len--;
  }

  // Check if input has any invalid characters
  for (size_t i = 0; i < len; i++) {
    if (!isalnum(input[i])) {
      printf("Invalid character '%c' detected. Program terminated.\n", input[i]);
      return 0;
    }
  }

  // If the input passed all checks, sanitize it
  char sanitized_input[MAX_INPUT_LENGTH];
  size_t j = 0;
  for (size_t i = 0; i < len; i++) {
    if (isalnum(input[i])) {
      sanitized_input[j] = tolower(input[i]);
      j++;
    }
  }
  sanitized_input[j] = '\0';

  printf("Input sanitized successfully. Result: %s\n", sanitized_input);
  return 0;
}