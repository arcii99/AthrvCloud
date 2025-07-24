//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LEN 1024

void indent(int level) {
  int i;
  for (i = 0; i < level; i++) {
    printf("  "); // two spaces per level
  }
}

int main() {
  char line[MAX_LINE_LEN];
  int level = 0;
  int in_tag = 0, in_comment = 0;

  while (fgets(line, MAX_LINE_LEN, stdin) != NULL) {
    int i, len;
    len = strlen(line);

    for (i = 0; i < len; i++) {
      if (line[i] == '<') {
        in_tag = 1;
        if ((i + 1 < len) && (line[i + 1] == '!')) {
          in_comment = 1; // allow for multi-line comments
        }
        printf("\n");
        indent(level);
        putchar(line[i]);
        if ((i + 1 < len) && (line[i + 1] != '/')) { // open tag
          level++;
        }
        continue;
      }
      if (line[i] == '>') {
        in_tag = 0;
        if (in_comment == 1) {
          in_comment = 0;
          printf("\n");
          indent(level);
        }
        putchar(line[i]);
        continue;
      }
      if (in_tag == 1) {
        putchar(line[i]);
        continue;
      }
      if (in_comment == 1) {
        putchar(line[i]);
        if ((i >= 3) && (line[i - 3] == '-') && (line[i - 2] == '-') && (line[i - 1] == '>')) {
          in_comment = 0; // end of comment
        }
        continue;
      }
      if (!isspace(line[i])) {
        printf("\n");
        indent(level);
      }
      putchar(line[i]);
    }
  }

  return 0;
}