//FormAI DATASET v1.0 Category: HTML beautifier ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautify_html(char *html) { 
  int size = strlen(html);
  char *new_html = malloc(size * sizeof(char));
  int indent_level = 0;
  int i = 0;
  int j = 0;
  
  while (i < size) {
    if (html[i] == '<') {
      if (html[i+1] == '/') {
        // End tag
        indent_level--;
      }
      for (int n = 0; n < indent_level; n++) {
        new_html[j++] = ' ';
        new_html[j++] = ' ';
      }
      indent_level++;
    }
    new_html[j++] = html[i++];
    if (html[i-1] == '>' && html[i] != '<') {
      new_html[j++] = '\n';
      for (int n = 0; n < indent_level; n++) {
        new_html[j++] = ' ';
        new_html[j++] = ' ';
      }
    }
  }
  new_html[j] = '\0';
  printf("%s\n", new_html);
  free(new_html);
}

int main() {
  char html[] = "<html><head><title>Example</title></head><body><h1>Hello, world!</h1><p>This is an example.</p></body></html>";
  beautify_html(html);
  return 0;
}