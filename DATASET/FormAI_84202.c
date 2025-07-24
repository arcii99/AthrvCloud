//FormAI DATASET v1.0 Category: HTML beautifier ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

void beautify(char* code) {
  int i, j;
  char buffer[1000];
  int indent_level = 0;
  int indent_size = 2;

  for (i = 0, j = 0; code[i] != '\0'; i++, j++) {
    if (code[i] == '<') {
      if (code[i + 1] == '/') {
        indent_level -= indent_size;
      }
      for (int k = 0; k < indent_level; k++) {
        buffer[j++] = ' ';
      }
      if (code[i + 1] != '/') {
        indent_level += indent_size;
      }
    }
    buffer[j] = code[i];
  }
  buffer[j] = '\0';
  printf("%s\n", buffer);
}

int main() {
  char code[] = "<html>\n<head>\n<title>Hello, World!</title>\n</head>\n<body>\n<h1>Welcome to my website</h1>\n<p>Some text goes here</p>\n</body>\n</html>";
  beautify(code);
  return 0;
}