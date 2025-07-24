//FormAI DATASET v1.0 Category: Syntax parsing ; Style: all-encompassing
#include <stdio.h>

int main() {
  // Welcome message
  printf("Welcome to the C Syntax Parsing Example Program!\n\n");

  // Prompt user for input
  printf("Please enter a C program to parse:\n");
  
  // Read user input
  char program[1000];
  fgets(program, 1000, stdin);

  // Parse program
  int i = 0;
  while (program[i] != '\0') {
    if (program[i] == '{') {
      printf("{ - Start of block\n");
    } else if (program[i] == '}') {
      printf("} - End of block\n");
    } else if (program[i] == '#') {
      printf("# - Preprocessor directive\n");
      while (program[i] != '\n') {
        i++;
      }
    } else if (program[i] == '/') {
      if (program[i+1] == '/') {
        printf("// - Single-line comment\n");
        while (program[i] != '\n') {
          i++;
        }
      } else if (program[i+1] == '*') {
        printf("/* - Start of block comment\n");
        i += 2;
        while (!(program[i] == '*' && program[i+1] == '/')) {
          i++;
        }
        printf("*/ - End of block comment\n");
        i += 2;
      } else {
        printf("/ - Division operator\n");
      }
    } else if (program[i] == '\'') {
      printf("\' - Single quote character\n");
      i++;
      while (program[i] != '\'') {
        if (program[i] == '\\') {
          printf("    Escape sequence: \\%c\n", program[i+1]);
          i += 2;
        } else {
          printf("    %c\n", program[i]);
          i++;
        }
      }
      printf("\' - End of single quote character\n");
    } else if (program[i] == '\"') {
      printf("\" - Double quote string literal\n");
      i++;
      while (program[i] != '\"') {
        if (program[i] == '\\') {
          printf("    Escape sequence: \\%c\n", program[i+1]);
          i += 2;
        } else {
          printf("    %c\n", program[i]);
          i++;
        }
      }
      printf("\" - End of double quote string literal\n");
    }
    i++;
  }

  // Goodbye message
  printf("\nThanks for using the C Syntax Parsing Example Program!\n");

  return 0;
}