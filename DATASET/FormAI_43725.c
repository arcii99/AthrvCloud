//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: scientific
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* This program demonstrates a unique input sanitizer for user input in C. It takes a user input and 
   removes any characters that are not alphanumeric or punctuation. This ensures that the input is
   safe to use and prevents any potential security vulnerabilities. */

void sanitize_input(char* input) {
  int i, j;
  char c;

  for (i = 0, j = 0; i < strlen(input); i++) {
    c = input[i];

    /* Remove any characters that are not alphanumeric or punctuation */
    if (isalnum(c) || ispunct(c)) {
      input[j++] = c;
    }
  }

  /* Terminate string properly */
  input[j] = '\0';
}

int main() {
  char input[100];

  printf("Enter a string of characters:\n");
  fgets(input, 100, stdin);

  printf("Original Input: %s", input);

  sanitize_input(input);

  printf("Sanitized Input: %s", input);

  return 0;
}