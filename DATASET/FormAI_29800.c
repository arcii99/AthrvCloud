//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
  // Declare variables
  char userInput[1000], sanitizedInput[1000];
  int i, j;

  // Get user input
  printf("Enter your input: ");
  fgets(userInput, sizeof(userInput), stdin);

  // Sanitize user input
  for (i = 0, j = 0; i < strlen(userInput); i++) {
    if (isalpha(userInput[i])) {
      sanitizedInput[j] = tolower(userInput[i]);
      j++;
    } else if (isspace(userInput[i]) || isdigit(userInput[i])) {
      // ignore spaces and digits
    } else {
      sanitizedInput[j] = '_';
      j++;
    }
  }
  sanitizedInput[j] = '\0';

  // Print sanitized input
  printf("Sanitized input: %s\n", sanitizedInput);

  return 0;
}