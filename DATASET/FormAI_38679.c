//FormAI DATASET v1.0 Category: HTML beautifier ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautify_html(char* html)
{
  int indent = 0;
  int i;

  for (i = 0; i < strlen(html); i++) {
    if (html[i] == '<' && html[i+1] != '/') {
      //opening tag
      for (int j = 0; j < indent; j++) {
        printf("  ");
      }
      printf("%c", html[i]);
      if (html[i+1] == ' ') {
        printf("%c", html[i+1]);
        i++;
      }
      printf("%s", &html[i+1]);
      printf("\n");
      indent++;
    }
    else if (html[i] == '<' && html[i+1] == '/') {
      //closing tag
      indent--;
      for (int j = 0; j < indent; j++) {
        printf("  ");
      }
      printf("%c%s\n", html[i], &html[i+1]);
      i += strlen(&html[i+1]) + 1;
    }
    else {
      //text
      for (int j = 0; j < indent; j++) {
        printf("  ");
      }
      while (html[i] != '<' && i < strlen(html)) {
        printf("%c", html[i]);
        i++;
      }
      printf("\n");
      i--;
    }
  }
}

int main()
{
  char* html = "<html><head><title>My Website</title></head><body><h1>Welcome to My Website</h1><p>This is a sample paragraph.</p></body></html>";
  beautify_html(html);
  return 0;
}