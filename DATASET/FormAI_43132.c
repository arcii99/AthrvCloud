//FormAI DATASET v1.0 Category: HTML beautifier ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAB_SIZE 4

void beautify(char *html)
{
  char *buffer = malloc(strlen(html) + 1);
  int indent = 0, index = 0;
  
  while (*html != '\0') {
    if (*html == '<') {
      if (*(html + 1) == '/') {
        indent -= TAB_SIZE;
      }
      for (int i = 0; i < indent; i++) {
        buffer[index++] = ' ';
      }
      memcpy(buffer + index, html, strcspn(html, ">\n") + 1);
      index += strcspn(html, ">\n") + 1;
      if (*(html + 1) != '/') {
        indent += TAB_SIZE;
      }
      html += strcspn(html, ">\n") + 1;
    } else {
      buffer[index++] = *html;
      html++;
    }
  }
  buffer[index] = '\0';
  printf("%s\n", buffer);
  free(buffer);
}

int main()
{
  char *html = "<html><head><title>My Website</title></head><body><h1>Welcome to my website!</h1><p>This is a paragraph.</p></body></html>";
  
  beautify(html);
  
  return 0;
}