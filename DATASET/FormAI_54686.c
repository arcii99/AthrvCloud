//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: modular
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 50

char sanitizeChar(char c) {
  // Map lowercase to uppercase
  if(islower(c)) {
    return toupper(c);
  }

  // Remove non-alphabetic characters
  if(!isalpha(c)) {
    return '\0';
  }

  return c;
}

void sanitizeInput(char* input, size_t length) {
  size_t i;
  for(i = 0; i < length; i++) {
    input[i] = sanitizeChar(input[i]);
  }
}

int main() {
  char input[MAX_INPUT_LENGTH];
  printf("Enter input to sanitize: ");
  fgets(input, MAX_INPUT_LENGTH, stdin);

  // Replace newline character with null terminator
  input[strcspn(input, "\n")] = '\0';

  printf("Original input: %s\n", input);

  sanitizeInput(input, strlen(input));

  printf("Sanitized input: %s\n", input);

  return 0;
}