//FormAI DATASET v1.0 Category: HTML beautifier ; Style: shocked
#include <stdio.h>
#include <ctype.h>

int main() {
  int c;
  int indent = 0;
  int new_line = 1;

  while ((c = getchar()) != EOF) {
    if (new_line) {
      for (int i = 0; i < indent; i++) {
        putchar(' ');
      }
      new_line = 0;
    }

    if (c == '<') {
      putchar(c);
      if (getchar() == '/') {
        indent -= 2;
      } else {
        indent += 2;
      }
    } else if (c == '>') {
      putchar(c);
      putchar('\n');
      new_line = 1;
    } else {
      putchar(c);
    }
  }

  return 0;
}