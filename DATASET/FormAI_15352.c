//FormAI DATASET v1.0 Category: Syntax parsing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int main() {
  char code[MAX_SIZE];
  int i, j, k;
  int in_comment = 0;
  int in_quote = 0;
  int in_char = 0;
  
  printf("Enter the code to parse:\n");
  fgets(code, sizeof(code), stdin);

  // remove newline from input
  code[strcspn(code, "\n")] = 0;

  for (i = 0; i < strlen(code); i++) {
    // check for comment start
    if (code[i] == '/' && code[i+1] == '*') {
      in_comment = 1;
      i++;
    }
    // check for comment end
    else if (code[i] == '*' && code[i+1] == '/') {
      in_comment = 0;
      i++;
    }
    // check for string literal
    else if (code[i] == '\"' && !in_comment && !in_char) {
      if (in_quote) {
        in_quote = 0;
      }
      else {
        in_quote = 1;
      }
    }
    // check for character literal
    else if (code[i] == '\'' && !in_comment && !in_quote) {
      if (in_char) {
        in_char = 0;
      }
      else {
        in_char = 1;
      }
    }

    // if we're not currently in a comment or string/char literal, check for syntax errors
    if (!in_comment && !in_quote && !in_char) {
      // check for missing semicolon
      if (code[i] == '\n' && code[i-1] != ';') {
        printf("Syntax error: missing semicolon.\n");
      }

      // check for mismatched braces/parens/brackets
      if (code[i] == '{' || code[i] == '(' || code[i] == '[') {
        j = i+1;
        while (code[j] == ' ') j++;
        if (code[j] == '{' || code[j] == '(' || code[j] == '[') {
          printf("Syntax error: mismatched %c%c.\n", code[i], code[j]);
          exit(1);
        }
      }

      if (code[i] == '}' || code[i] == ')' || code[i] == ']') {
        j = i-1;
        while (code[j] == ' ' || code[j] == '\n') j--;
        if (code[j] == '{' && code[i] != '}' ||
            code[j] == '(' && code[i] != ')' ||
            code[j] == '[' && code[i] != ']') {
          printf("Syntax error: mismatched %c%c.\n", code[j], code[i]);
          exit(1);
        }
      }

      // check for missing parentheses
      if (code[i] == '(') {
        j = i;
        while (code[j] != ')') {
          j++;
          if (j == strlen(code)) {
            printf("Syntax error: missing closing parenthesis.\n");
            exit(1);
          }
        }
      }

      // check for invalid characters
      if (code[i] != ' ' && code[i] != '\n' && code[i] != ';' && code[i] != '{' &&
          code[i] != '}' && code[i] != '(' && code[i] != ')' && code[i] != '[' &&
          code[i] != ']' && code[i] != '\"' && code[i] != '\'') {
        printf("Syntax error: invalid character '%c'.\n", code[i]);
        exit(1);
      }
    }
  }

  printf("Code parsed successfully.\n");

  return 0;
}