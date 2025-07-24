//FormAI DATASET v1.0 Category: Syntax parsing ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

int main() {
  char input[1000];
  printf("Enter a C syntax code: ");
  fgets(input, 1000, stdin); // Reading input from user

  // Flagging certain characters to parse the input string
  int angle_brackets = 0, curly_braces = 0, square_brackets = 0,
    parentheses = 0, double_quotes = 0, single_quotes = 0;

  for (int i = 0; input[i] != '\0'; i++) {
    if (input[i] == '<' || input[i] == '>') {
      angle_brackets++;
    } else if (input[i] == '{' || input[i] == '}') {
      curly_braces++;
    } else if (input[i] == '[' || input[i] == ']') {
      square_brackets++;
    } else if (input[i] == '(' || input[i] == ')') {
      parentheses++;
    } else if (input[i] == '"') {
      double_quotes++;
    } else if (input[i] == '\'') {
      single_quotes++;
    }
  }

  // Checking for matching characters
  if (angle_brackets % 2 == 0 && curly_braces % 2 == 0 &&
      square_brackets % 2 == 0 && parentheses % 2 == 0 &&
      double_quotes % 2 == 0 && single_quotes % 2 == 0) {
    printf("Input syntax is correct.\n");
  } else {
    printf("Syntax error in the input.\n");
  }

  return 0;
}