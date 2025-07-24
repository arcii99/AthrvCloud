//FormAI DATASET v1.0 Category: String manipulation ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

int main() {

  char string[100];
  int length;

  // Get user input
  printf("Enter a string (maximum length 100 characters):\n");
  fgets(string, 100, stdin);

  // Remove any newline character
  length = strlen(string);
  if (string[length - 1] == '\n') {
    string[length - 1] = '\0';
  }

  // Make all characters uppercase
  for (int i = 0; i < length; i++) {
    if (string[i] >= 'a' && string[i] <= 'z') {
      string[i] -= 32; // ASCII code for lowercase letters is 32 greater than uppercase letters
    }
  }

  // Replace spaces with underscores
  for (int i = 0; i < length; i++) {
    if (string[i] == ' ') {
      string[i] = '_';
    }
  }

  // Output the new string
  printf("Your new string is: %s\n", string);

  return 0;
}