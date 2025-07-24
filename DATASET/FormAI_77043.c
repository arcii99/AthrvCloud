//FormAI DATASET v1.0 Category: HTML beautifier ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {

  printf("Hello surreal world!\n");

  char *html = "<html><head><title>Surreal HTML</title></head><body><h1>Wake up in an alternate reality</h1><p>Everything is backwards and nothing makes sense</p><img src=\"https://www.iconsdb.com/icons/preview/surreal-astronaut-xl.png\" alt=\"Surreal astronaut image\"></body></html>";

  char *formatted_html = malloc(sizeof(html));

  int indent_level = 0;
  int length = strlen(html);

  for (int i = 0; i < length; i++) {
    if (html[i] == '<') {
      formatted_html = realloc(formatted_html, (strlen(formatted_html) + 2));
      formatted_html[strlen(formatted_html)] = '\n';
      for (int j = 0; j < indent_level; j++) {
        formatted_html[strlen(formatted_html)] = '\t';
      }
      indent_level++;
    }
    formatted_html = realloc(formatted_html, (strlen(formatted_html) + 1));
    formatted_html[strlen(formatted_html)] = html[i];
    if (html[i] == '>') {
      formatted_html = realloc(formatted_html, (strlen(formatted_html) + 2));
      formatted_html[strlen(formatted_html)] = '\n';
      indent_level--;
      for (int j = 0; j < indent_level; j++) {
        formatted_html[strlen(formatted_html)] = '\t';
      }
    }
  }

  printf("Here's the surreal HTML after formatting:\n%s", formatted_html);

  free(formatted_html);

  return 0;
}