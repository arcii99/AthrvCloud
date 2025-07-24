//FormAI DATASET v1.0 Category: HTML beautifier ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
  char c;
  int indent = 0; // initialize indentation variable

  // read HTML code from file
  FILE *file = fopen("input.html", "r");
  if (file) {
    while ((c = getc(file)) != EOF) {
      if (c == '<') { // beginning of tag
        printf("%c\n", c);
        indent++; // increase indentation level
        for (int i = 0; i < indent; i++) {
          printf("  "); // print spaces to indent
        }
      } else if (c == '>') { // end of tag
        printf(">\n");
      } else if (c == '/') { // self-closing tag
        printf("/>\n");
      } else if (c == '\n') { // ignore newlines
        continue;
      } else { // text content
        printf("%c", c);
      }
    }
    fclose(file); // close the file
  } else { // error opening file
    printf("Error opening file.");
    return 1;
  }

  return 0; // program exits successfully!
}