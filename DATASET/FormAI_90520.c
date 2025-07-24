//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: lively
#include <stdio.h>
#include <string.h>

// Function to check if a character is a digit
int isDigit(char c) {
  return (c >= '0' && c <= '9');
}

// Function to check if a character is an alphabet (uppercase or lowercase)
int isAlphabet(char c) {
  return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// Function to check if a character is a symbol
int isSymbol(char c) {
  return ((c >= '!' && c <= '/') || (c >= ':' && c <= '@') || (c >= '[' && c <= '`') || (c >= '{' && c <= '~'));
}

// Function to sanitize user input
void sanitizeInput(char input[]) {
  int i = 0, j = 0;
  while (input[i]) {
    // Check if character is a digit, alphabet, or symbol
    if (isDigit(input[i]) || isAlphabet(input[i]) || isSymbol(input[i])) {
      input[j++] = input[i];
    }
    i++;
  }
  // Add null character at the end of the sanitized input
  input[j] = '\0';
}

int main() {
  char input[100];

  printf("Please enter your input:\n");
  fgets(input, 100, stdin);
  
  // Sanitize user input
  sanitizeInput(input);

  printf("Sanitized input: %s\n", input);

  return 0;
}