//FormAI DATASET v1.0 Category: Syntax parsing ; Style: immersive
#include <stdio.h>

int main() {
  int count = 0;
  char c, prevC = '\0';

  printf("Enter a C program to be parsed:\n");

  while ((c = getchar()) != EOF) {
    if (c == '/' && prevC == '/') { // if a // comment
      while ((c = getchar()) != '\n' && c != EOF) {} // consume the rest of the line
    } else if (c == '*' && prevC == '/') { // if a /* comment
      while (1) {
        c = getchar();
        if (c == EOF) {
          printf("Error: unclosed comment\n");
          return 1;
        } else if (c == '*' && getchar() == '/') { // if end of comment
          break; // exit the loop
        }
      }
    } else {
      putchar(c);
    }

    prevC = c; // save the previous character
  }

  return 0;
}