//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: accurate
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100

void sanitizeInput(char input[]) {
  int i;
  for (i = 0; i < strlen(input); i++) {
    if (!isalnum(input[i])) { // Check if character is not alphanumeric
      input[i] = '_'; // Replace character with underscore
    }
  }
}

int main() {
  char input[MAX_LENGTH];
  printf("Enter a string: ");
  fgets(input, MAX_LENGTH, stdin); // Get user input

  sanitizeInput(input); // Sanitize user input

  printf("Sanitized input: %s\n", input); // Output sanitized input

  return 0;
}