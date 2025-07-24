//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char *html = "<!DOCTYPE html>\n<html>\n<head>\n<title>My Webpage</title>\n</head>\n<body>\n<h1>Welcome to my webpage!</h1>\n<p>This is my first webpage.</p>\n</body>\n</html>";
  int len = strlen(html);

  // Count the number of spaces per indentation level
  int indent_level = 2;
  char indent_char = ' ';

  // Beautify the HTML code
  int i = 0, indent = 0;
  while (i < len)
  {
    char c = html[i];

    if (c == '<')
    {
      if (html[i+1] == '/')
      {
        // Decrease the indentation level
        indent -= indent_level;
      }

      // Indent the current line
      int j;
      for (j = 0; j < indent; j++)
      {
        putchar(indent_char);
      }

      if (html[i+1] == '/')
      {
        // Print the closing tag
        printf("%c", c);
        i++;
      }
      else
      {
        // Increase the indentation level
        indent += indent_level;
      }
    }

    // Print the current character
    printf("%c", c);
    i++;
  }

  return 0;
}