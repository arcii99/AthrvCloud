//FormAI DATASET v1.0 Category: String manipulation ; Style: thoughtful
#include <stdio.h>
#include <string.h>

int main() {
  char str[] = "Hello, world!"; // Declare and initialize a C string
  char reversedStr[strlen(str) + 1]; // Declare a new char array for the reversed string
  int i, j;

  printf("Original string: %s\n", str);

  // Reverse the string
  j = 0;
  for (i = strlen(str) - 1; i >= 0; i--) {
    reversedStr[j++] = str[i];
  }
  reversedStr[j] = '\0'; // Add null terminator to the end of the reversed string

  printf("Reversed string: %s\n", reversedStr);

  // Replace all 'o' characters with 'e' characters
  for (i = 0; i < strlen(str); i++) {
    if (str[i] == 'o') {
      str[i] = 'e';
    }
  }

  printf("Replaced string: %s\n", str);

  // Remove all spaces from the string
  j = 0;
  for (i = 0; i < strlen(str); i++) {
    if (str[i] != ' ') {
      str[j++] = str[i];
    }
  }
  str[j] = '\0'; // Add null terminator to the end of the modified string

  printf("Modified string: %s\n", str);

  return 0;
}