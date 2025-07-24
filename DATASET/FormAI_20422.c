//FormAI DATASET v1.0 Category: Syntax parsing ; Style: minimalist
#include <stdio.h>

// Function to parse the syntax
void parseSyntax(char str[]) {
  int i = 0;
  int brackets = 0;
  int parentheses = 0;
  int braces = 0;

  // Loop through the characters in the string
  while (str[i] != '\0') {
    // Check for brackets
    if (str[i] == '[') {
      brackets++;
    } else if (str[i] == ']') {
      brackets--;
    }

    // Check for parentheses
    if (str[i] == '(') {
      parentheses++;
    } else if (str[i] == ')') {
      parentheses--;
    }

    // Check for braces
    if (str[i] == '{') {
      braces++;
    } else if (str[i] == '}') {
      braces--;
    }

    i++;
  }

  // Check if there were any syntax errors
  if (brackets != 0 || parentheses != 0 || braces != 0) {
    printf("Syntax Error!\n");
  } else {
    printf("Syntax OK!\n");
  }
}

int main() {
  char str[] = "if (a > b) { a = b; }";

  // Parse the syntax of the string
  parseSyntax(str);

  return 0;
}