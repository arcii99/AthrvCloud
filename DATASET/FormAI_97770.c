//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

int main() {
  char input[MAX_INPUT_LENGTH];
  char sanitized_input[MAX_INPUT_LENGTH];
  int i, j;

  printf("Please enter some input: ");
  fgets(input, MAX_INPUT_LENGTH, stdin);
  
  // Remove any trailing newline character from the input
  input[strcspn(input, "\n")] = '\0';

  // Sanitize the input by removing any non-alphabetic characters and converting to lowercase
  for (i = 0, j = 0; i < strlen(input); i++) {
    if (isalpha(input[i])) {
      sanitized_input[j++] = tolower(input[i]);
    }
  }

  // Null-terminate the sanitized input
  sanitized_input[j] = '\0';

  printf("Sanitized input: %s\n", sanitized_input);

  return 0;
}