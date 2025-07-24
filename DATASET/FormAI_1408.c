//FormAI DATASET v1.0 Category: Syntax parsing ; Style: relaxed
#include<stdio.h>

int main() {
  // Welcome message
  printf("Welcome to the C Syntax parsing program!\n");
  printf("Enter a line of code to parse:\n");

  // Read input from user
  char input[100];
  fgets(input, 100, stdin);

  // Count number of braces and brackets
  int brace_count = 0;
  int bracket_count = 0;
  int i = 0;
  while (input[i] != '\0') {
    if (input[i] == '{') {
      brace_count++;
    }
    else if (input[i] == '}') {
      brace_count--;
    }
    else if (input[i] == '(') {
      bracket_count++;
    }
    else if (input[i] == ')') {
      bracket_count--;
    }
    i++;
  }

  // Check if syntax is correct
  if (brace_count == 0 && bracket_count == 0) {
    printf("Syntax is correct!\n");
  }
  else {
    // Error messages
    if (brace_count > 0) {
      printf("Error: %d unmatched braces\n", brace_count);
    }
    if (bracket_count > 0) {
      printf("Error: %d unmatched brackets\n", bracket_count);
    }
    if (brace_count < 0) {
      printf("Error: %d too many closing braces\n", -brace_count);
    }
    if (bracket_count < 0) {
      printf("Error: %d too many closing brackets\n", -bracket_count);
    }
  }

  return 0;
}