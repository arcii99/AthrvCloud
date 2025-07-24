//FormAI DATASET v1.0 Category: HTML beautifier ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautify_html(char *html) {

  int indent = 0;
  char *token, *prev_token = NULL;

  token = strtok(html, "<>");

  while (token != NULL) {

    if (strcmp(token, "/") == 0) {
      indent--;
    }

    for (int i = 0; i < indent; i++) {
      printf("  "); // Two spaces for each level of indentation
    }

    if (prev_token != NULL && strcmp(prev_token, "/") == 0 && strcmp(token, "/") != 0) {
      indent++;
    }

    printf("%s%s", "<", token);

    if (strcmp(token, "/") != 0 && token[strlen(token) - 1] != '/') {
      printf(">\n");
    }

    prev_token = token;
    token = strtok(NULL, "<>");
  }
}

int main() {

  char html[] = "<html><head><title>My Page</title></head><body><h1>Welcome to</h1><p>My Page</p></body></html>";
  beautify_html(html);

  return 0;
}