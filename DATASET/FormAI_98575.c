//FormAI DATASET v1.0 Category: Syntax parsing ; Style: visionary
#include <stdio.h>
#include <string.h>

int main() {
  char input[100];
  printf("Enter a C program to parse:\n");
  fgets(input, 100, stdin); // Get input from user
  if (input[strlen(input)-1] == '\n') {
    input[strlen(input)-1] = '\0'; // Remove newline character
  }
  int i = 0;
  while (input[i] != '\0') {
    if (input[i] == '/') { // Check for comments
      if (input[i+1] == '/') { // Single-line comment
        printf("Single-line comment found starting at line %d\n", i);
        while (input[i] != '\n') { // Print out comment
          printf("%c", input[i]);
          i++;
        }
        printf("\n");
      } else if (input[i+1] == '*') { // Multi-line comment
        printf("Multi-line comment found starting at line %d\n", i);
        while (!(input[i] == '*' && input[i+1] == '/')) { // Loop until end of comment
          printf("%c", input[i]);
          i++;
        }
        printf("*/\n");
      }
    } else if (input[i] == '#') { // Check for preprocessor directives
      printf("Preprocessor directive found starting at line %d\n", i);
      while (input[i] != '\n') { // Print out directive
        printf("%c", input[i]);
        i++;
      }
      printf("\n");
    }
    i++;
  }
  return 0;
}