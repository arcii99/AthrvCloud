//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXLEN 1000 // Maximum length of input

int main() {
  char input[MAXLEN]; // Input string
  int i, j, len;
  
  printf("Enter a C syntax: ");
  fgets(input, MAXLEN, stdin); // Get input from user
  
  len = strlen(input); // Get length of input
  
  // Check for valid syntax
  for (i = 0; i < len; i++) {
    // Check for keywords and identifiers
    if (isalpha(input[i]) || input[i] == '_') {
      for (j = i + 1; j < len; j++) {
        if (!isalnum(input[j]) && input[j] != '_') {
          break;
        }
      }
      printf("Identifier found: %.*s\n", j - i, &input[i]);
      i = j; // Move to next character after identifier
    }
    
    // Check for integers and floats
    if (isdigit(input[i])) {
      for (j = i + 1; j < len; j++) {
        if (!isdigit(input[j]) && input[j] != '.') {
          break;
        }
      }
      printf("Number found: %.*s\n", j-i, &input[i]);
      i = j; // Move to next character after number
    }
    
    // Check for operators and punctuation
    if (ispunct(input[i])) {
      printf("Operator/Punctuation found: %c\n", input[i]);
    }
  }
  
  return 0;
}