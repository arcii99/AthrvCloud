//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: complex
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_LENGTH 1000

// Function to sanitize user input
void sanitize(char *input) {
  int len = strlen(input); // get length of input
  char sanitized[MAX_LENGTH]; // create sanitized string
  int j = 0;

  for (int i = 0; i < len; i++) { // iterate over each character in input string
    if (isalnum(input[i]) || input[i] == ' ') { // check if character is alphanumeric or whitespace
      sanitized[j++] = input[i]; // add character to sanitized string and increment sanitized index
    }
  }

  sanitized[j] = '\0'; // add null terminator to sanitized string
  strcpy(input, sanitized); // copy sanitized string back into original input string
}

int main() {
  char input[MAX_LENGTH]; // create input string
  printf("Enter a phrase: ");
  fgets(input, MAX_LENGTH, stdin); // read input from user

  sanitize(input); // sanitize input

  printf("Sanitized input: %s\n", input); // print sanitized input

  return 0;
}