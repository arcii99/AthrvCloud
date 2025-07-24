//FormAI DATASET v1.0 Category: Syntax parsing ; Style: artistic
//***********************************************
//*                                             *
//*     "The Artistic C Syntax Parsing Demo"    *
//*                                             *
//*              by ChatbotArt                 *
//*                                             *
//***********************************************

#include <stdio.h>

int main() {
  char *keywords[] = {"if", "else", "for", "while", "switch"};
  int i, j, k;
  char input_string[100];
  printf("Welcome to the Artistic C Syntax Parsing Demo!\n");
  printf("Enter a C code block to parse:\n");

  // Read the input string
  fgets(input_string, 100, stdin);

  // Parse the input string
  printf("Parsing the input string...\n\n");
  printf("Identified tokens:\n");

  for (i = 0; input_string[i] != '\0'; i++) {
    // Eliminate whitespace
    if (input_string[i] == ' ')
      continue;

    // Check for keywords
    for (j = 0; j < 5; j++) {
      k = 0;

      while (input_string[i] == keywords[j][k]) {
        i++;
        k++;

        if (keywords[j][k] == '\0') {
          printf("keyword: %s\n", keywords[j]);
          break;
        }
      }
    }

    // Check for identifiers
    if ((input_string[i] >= 'a' && input_string[i] <= 'z') ||
        (input_string[i] >= 'A' && input_string[i] <= 'Z')) {
      printf("identifier: ");
      while ((input_string[i] >= 'a' && input_string[i] <= 'z') ||
             (input_string[i] >= 'A' && input_string[i] <= 'Z')) {
        printf("%c", input_string[i]);
        i++;
      }
      printf("\n");
    }

    // Check for numerical values
    if (input_string[i] >= '0' && input_string[i] <= '9') {
      printf("number: ");
      while (input_string[i] >= '0' && input_string[i] <= '9') {
        printf("%c", input_string[i]);
        i++;
      }
      printf("\n");
    }

    // Check for operators
    if (input_string[i] == '+' || input_string[i] == '-' ||
        input_string[i] == '*' || input_string[i] == '/' ||
        input_string[i] == '=' || input_string[i] == '<' ||
        input_string[i] == '>' || input_string[i] == '&' ||
        input_string[i] == '|' || input_string[i] == '!') {
      printf("operator: %c\n", input_string[i]);
    }

    // Check for punctuation
    if (input_string[i] == '(' || input_string[i] == ')' ||
        input_string[i] == '{' || input_string[i] == '}' ||
        input_string[i] == '[' || input_string[i] == ']') {
      printf("punctuation: %c\n", input_string[i]);
    }
  }

  printf("\nThe C code block has been successfully parsed!");
  return 0;
}