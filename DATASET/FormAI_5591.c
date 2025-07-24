//FormAI DATASET v1.0 Category: Syntax parsing ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

int main() {
  char input_str[MAX_LEN], output_str[MAX_LEN];
  int output_str_len = 0, num_open_parens = 0;

  printf("Enter a C function declaration:\n");
  fgets(input_str, MAX_LEN, stdin);

  // Parse input_str and validate syntax
  for (int i = 0; i < strlen(input_str); i++) {
    char c = input_str[i];

    // Skip whitespace
    if (c == ' ' || c == '\t' || c == '\n') {
      continue;
    }

    // Check for return type
    if (c == 'v' || c == 'b' || c == 's' || c == 'i' || c == 'c') {
      if (i + 1 < strlen(input_str) && input_str[i + 1] == 'o' &&
          i + 2 < strlen(input_str) && input_str[i + 2] == 'i' &&
          i + 3 < strlen(input_str) && input_str[i + 3] == 'd') {
        output_str[output_str_len++] = c;
        output_str[output_str_len++] = 'o';
        output_str[output_str_len++] = 'i';
        output_str[output_str_len++] = 'd';
        i += 3;
      } else {
        printf("Syntax error: unexpected character '%c' after return type\n", input_str[i]);
        return EXIT_FAILURE;
      }
    }

    // Check for function name
    else if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || c == '_') {
      while (i < strlen(input_str) &&
             (input_str[i] == '_' || ('0' <= input_str[i] && input_str[i] <= '9') ||
              ('a' <= input_str[i] && input_str[i] <= 'z') || ('A' <= input_str[i] && input_str[i] <= 'Z'))) {
        output_str[output_str_len++] = input_str[i];
        i++;
      }
      i--; // Backtrack one character since the while loop increments i one extra time
    }

    // Check for open paren
    else if (c == '(') {
      output_str[output_str_len++] = '(';
      num_open_parens++;
    }

    // Check for close paren
    else if (c == ')') {
      output_str[output_str_len++] = ')';
      num_open_parens--;
      if (num_open_parens < 0) {
        printf("Syntax error: too many close parentheses\n");
        return EXIT_FAILURE;
      }
    }

    // Check for comma between parameters
    else if (c == ',') {
      output_str[output_str_len++] = ',';
      if (num_open_parens == 1) {
        output_str[output_str_len++] = ' ';
      } else if (num_open_parens == 0) {
        printf("Syntax error: unexpected comma outside of parameter list\n");
        return EXIT_FAILURE;
      }
    }

    // Invalid character
    else {
      printf("Syntax error: unexpected character '%c'\n", input_str[i]);
      return EXIT_FAILURE;
    }
  }

  // Final checks
  if (num_open_parens > 0) {
    printf("Syntax error: missing close paren\n");
    return EXIT_FAILURE;
  } else if (output_str_len == 0) {
    printf("Syntax error: empty function declaration\n");
    return EXIT_FAILURE;
  }

  output_str[output_str_len] = '\0'; // Terminate output string

  printf("Parsed declaration:\n%s\n", output_str);

  return EXIT_SUCCESS;
}