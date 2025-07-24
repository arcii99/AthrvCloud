//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if the given character is an alphabet or not
int isAlphabet(char ch) {
  return isalpha(ch);
}

// Function to check if the given character is a numeric digit or not
int isDigit(char ch) {
  return isdigit(ch);
}

// Function to check if the given character is a whitespace or not
int isWhitespace(char ch) {
  return isspace(ch);
}

// Function to convert a character to lowercase
char toLower(char ch) {
  if (isAlphabet(ch)) {
    return tolower(ch);
  }
  return ch;
}

// Function to check if the given string is a palindrome or not
int isPalindrome(char string[]) {
  int left, right;
  int length = strlen(string);

  left = 0;
  right = length - 1;

  while (left < right) {
    // Ignore whitespace and non-alphanumeric characters
    while (!isAlphabet(string[left]) && !isDigit(string[left])) {
      left++;
    }
    while (!isAlphabet(string[right]) && !isDigit(string[right])) {
      right--;
    }

    // Convert both characters to lowercase and compare them
    if (toLower(string[left]) != toLower(string[right])) {
      return 0; // Not a palindrome
    }

    left++;
    right--;
  }

  return 1; // Palindrome
}

void main() {
  char string[100];

  printf("Enter a string: ");
  fgets(string, sizeof(string), stdin);

  // Remove trailing newline character
  if (string[strlen(string) - 1] == '\n') {
    string[strlen(string) - 1] = '\0';
  }

  if (isPalindrome(string)) {
    printf("%s is a palindrome.\n", string);
  }
  else {
    printf("%s is not a palindrome.\n", string);
  }
}