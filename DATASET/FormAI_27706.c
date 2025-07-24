//FormAI DATASET v1.0 Category: HTML beautifier ; Style: artistic
#include <stdio.h>
#include <stdbool.h>

int main() {
  // Initialize variables
  char c, p = '\0';  // Current and previous character
  int indent = 0;  // Number of spaces to indent current line
  bool in_tag = false;  // Whether currently inside an HTML tag

  // Loop through input characters
  while ((c = getchar()) != EOF) {
    // Check for opening tag
    if (!in_tag && c == '<') {
      in_tag = true;
      putchar(c);
      continue;
    }

    // Check for closing tag
    if (in_tag && c == '>') {
      in_tag = false;
      putchar(c);
      putchar('\n');
      continue;
    }

    // Handle newline character
    if (c == '\n') {
      putchar(c);
      p = c;
      continue;
    }

    // Count number of spaces to indent current line
    if (p == '\n') {
      indent = 0;
      while ((c = getchar()) == ' ') {
        indent++;
      }
      if (c == EOF) {
        break;
      }
      putchar(' ');
    }

    // Print current character and adjust indentation
    putchar(c);
    if (!in_tag && c == '\n') {
      for (int i = 0; i < indent; i++) {
        putchar(' ');
      }
    }

    // Update previous character
    p = c;
  }
  
  return 0;
}