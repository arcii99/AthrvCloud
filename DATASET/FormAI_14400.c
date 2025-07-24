//FormAI DATASET v1.0 Category: HTML beautifier ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

char *html_beautify(char *input) {
  char *output = (char*)malloc(sizeof(char));
  int indent_level = 0;
  int len = 0;
  int i = 0;
  int curr_char;

  while ((curr_char = input[i++]) != '\0') {
    if (curr_char == '<') {
      if (input[i] == '/') {
        indent_level--;
      }

      for (int j = 0; j < indent_level; j++) {
        strcat(output, "  ");
      }

      if (input[i] != '/') {
        indent_level++;
      }
    }

    char temp[2];
    temp[0] = curr_char;
    temp[1] = '\0';
    strcat(output, temp);

    if (curr_char == '>') {
      strcat(output, "\n");
    }
  }

  return output;
}

int main() {
  char input[500] = "<body>\n<div>\n<p>Hello, world!</p>\n</div>\n</body>\n";
  char *beautified = html_beautify(input);

  printf("%s\n", beautified);
  free(beautified);

  return 0;
}