//FormAI DATASET v1.0 Category: Syntax parsing ; Style: thoughtful
#include <stdio.h>

int main() {
  char input[1000];
  printf("Enter a C Syntax code snippet:\n");
  fgets(input, 1000, stdin);

  int braces = 0;
  int parenthesis = 0;
  int brackets = 0;

  for (int i = 0; input[i] != '\0'; i++) {
    if (input[i] == '{') {
      braces++;
    } else if (input[i] == '}') {
      braces--;
    } else if (input[i] == '(') {
      parenthesis++;
    } else if (input[i] == ')') {
      parenthesis--;
    } else if (input[i] == '[') {
      brackets++;
    } else if (input[i] == ']') {
      brackets--;
    }
  }

  if (braces == 0 && parenthesis == 0 && brackets == 0) {
    printf("The code is syntactically correct!\n");
  } else {
    printf("There are syntax errors in the code:\n");
    if (braces != 0) {
      printf("Missing %d '}' characters\n", braces);
    }
    if (parenthesis != 0) {
      printf("Missing %d ')' characters\n", parenthesis);
    }
    if (brackets != 0) {
      printf("Missing %d ']' characters\n", brackets);
    }
  }

  return 0;
}