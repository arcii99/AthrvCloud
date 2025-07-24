//FormAI DATASET v1.0 Category: Syntax parsing ; Style: automated
#include <stdio.h>

int main() {
  char input[100];
  printf("Enter a C syntax statement:\n");
  fgets(input, 100, stdin);

  // Parsing the C syntax statement
  int i = 0;
  int in_quotes = 0;
  int bracket_depth = 0;
  int parens_depth = 0;

  while (input[i] != '\0') {
    if (input[i] == '\"' || input[i] == '\'') {
      in_quotes = !in_quotes;
    }

    if (!in_quotes) {
      if (input[i] == '{') {
        bracket_depth++;
      } else if (input[i] == '}') {
        bracket_depth--;
      } else if (input[i] == '(') {
        parens_depth++;
      } else if (input[i] == ')') {
        parens_depth--;
      }
    }

    i++;
  }

  if (bracket_depth != 0) {
    printf("Error: Unbalanced brackets\n");
  }

  if (parens_depth != 0) {
    printf("Error: Unbalanced parentheses\n");
  }

  if (bracket_depth == 0 && parens_depth == 0) {
    printf("C syntax statement is balanced!\n");
  }

  return 0;
}