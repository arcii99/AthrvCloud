//FormAI DATASET v1.0 Category: String manipulation ; Style: synchronous
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
  char string[MAX_LENGTH];

  printf("Enter a string: ");
  fgets(string, MAX_LENGTH, stdin);
  // Remove newline character from input
  string[strcspn(string, "\n")] = '\0';

  // Store the length of the string for later use
  int length = strlen(string);

  printf("Original string: %s\n", string);

  // Reverse the string
  for (int i = 0, j = length - 1; i < j; i++, j--) {
    char temp = string[i];
    string[i] = string[j];
    string[j] = temp;
  }

  printf("Reverse string: %s\n", string);

  // Convert all characters to uppercase
  for (int i = 0; i < length; i++) {
    string[i] = toupper(string[i]);
  }

  printf("Uppercase string: %s\n", string);

  // Count the number of vowels
  int vowel_count = 0;
  for (int i = 0; i < length; i++) {
    switch (string[i]) {
      case 'A':
      case 'E':
      case 'I':
      case 'O':
      case 'U':
        vowel_count++;
        break;
    }
  }

  printf("Number of vowels: %d\n", vowel_count);

  // Replace all vowels with a random number between 0 and 9
  for (int i = 0; i < length; i++) {
    switch (string[i]) {
      case 'A':
      case 'E':
      case 'I':
      case 'O':
      case 'U':
        string[i] = '0' + (rand() % 10);
        break;
    }
  }

  printf("Vowels replaced with random numbers: %s\n", string);

  return 0;
}