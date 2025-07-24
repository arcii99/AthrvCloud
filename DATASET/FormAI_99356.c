//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: enthusiastic
// Welcome to the C User Input Sanitizer Program!
// This program is designed to help keep your code secure
// by sanitizing user input before it is used in your program.

#include <stdio.h>
#include <ctype.h>

int main() {
  char input[256];

  printf("Please enter your input: ");
  fgets(input, 256, stdin);

  // Sanitize the input by removing any non-alphabetic characters
  for (int i = 0; input[i] != '\0'; i++) {
    if (!isalpha(input[i])) {
      input[i] = ' ';
    }
  }

  printf("Your sanitized input is: %s", input);

  return 0;
}