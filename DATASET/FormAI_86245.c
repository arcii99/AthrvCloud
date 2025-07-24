//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: all-encompassing
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

void sanitize_input(char* input_str) {
  // Loop through each character in input string
  for (int i = 0; i < strlen(input_str); i++) {
    // Remove any non-alphanumeric characters
    if (!isalnum(input_str[i])) {
      input_str[i] = ' ';
    }
    // Convert any uppercase letters to lowercase
    if (isupper(input_str[i])) {
      input_str[i] = tolower(input_str[i]);
    }
  }
}

int main() {
  char input[MAX_INPUT_LENGTH];

  printf("Please input a string (max length %d): ", MAX_INPUT_LENGTH);
  fgets(input, MAX_INPUT_LENGTH, stdin);

  // Remove trailing newline character
  input[strcspn(input, "\n")] = 0;

  sanitize_input(input);

  printf("Sanitized string: %s\n", input);

  return 0;
}