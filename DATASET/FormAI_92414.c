//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// function to check if a given string is a palindrome
int is_palindrome(char *str) {
  // Convert the string to lowercase
  for (int i = 0; str[i]; i++) {
    str[i] = tolower(str[i]);
  }

  // Define variables to keep track of start and end indices
  int len = strlen(str);
  int start = 0;
  int end = len - 1;

  // Compare characters at start and end until they meet in the middle
  while (start < end) {
    if (str[start++] != str[end--]) {
      return 0; // Not a palindrome
    }
  }

  return 1; // Palindrome
}

int main() {
  printf("Enter a string to check if it's a palindrome:\n");

  char input[100]; // Maximum input size is 100 characters
  fgets(input, sizeof(input), stdin); // Read input from user

  // Remove newline character from fgets input
  input[strcspn(input, "\n")] = '\0';

  if (is_palindrome(input)) {
    printf("The input string is a palindrome!\n");
  } else {
    printf("The input string is not a palindrome.\n");
  }

  return 0;
}