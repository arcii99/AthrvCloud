//FormAI DATASET v1.0 Category: HTML beautifier ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautify_html(char *html_str) {
  // Variables for tracking indent level and length of input string
  int indent_level = 0;
  int str_len = strlen(html_str);
  int curr_char = 0;
  // Buffer for storing current line and resulting beautified HTML string
  char curr_line[1024];
  char beautified_html[4096] = "";

  // Loop through each character in the input string
  while (curr_char < str_len) {
    // Check if current character is an opening tag
    if (html_str[curr_char] == '<' && html_str[curr_char + 1] != '/') {
      // Add current line to resulting beautified HTML with proper indentation
      sprintf(beautified_html + strlen(beautified_html), "%*s%s\n", 
              indent_level * 2, "", curr_line);
      // Add opening tag to current line and increment indent level
      sprintf(curr_line, "<%c", html_str[curr_char + 1]);
      indent_level++;
      curr_char += 2;
    } 
    // Check if current character is a closing tag
    else if (html_str[curr_char] == '<' && html_str[curr_char + 1] == '/') {
      // Add current line to resulting beautified HTML with proper indentation
      sprintf(beautified_html + strlen(beautified_html), "%*s%s\n", 
              indent_level * 2, "", curr_line);
      // Decrement indent level and add closing tag to current line
      indent_level--;
      sprintf(curr_line, "</%c", html_str[curr_char + 2]);
      curr_char += 3;
    }
    // Check if current character is a newline
    else if (html_str[curr_char] == '\n') {
      // Add current line to resulting beautified HTML with proper indentation
      sprintf(beautified_html + strlen(beautified_html), "%*s%s\n", 
              indent_level * 2, "", curr_line);
      // Reset current line
      memset(curr_line, 0, sizeof(curr_line));
      curr_char++;
    }
    // Add current character to current line
    else {
      strncat(curr_line, &html_str[curr_char], 1);
      curr_char++;
    }
  }
  // Add final line to resulting beautified HTML with proper indentation
  sprintf(beautified_html + strlen(beautified_html), "%*s%s\n", 
          indent_level * 2, "", curr_line);
  printf("%s", beautified_html);
}

int main() {
  char html_str[] = "<html>\n<head>\n<title>My Page</title>\n</head>\n<body>\n<h1>Welcome</h1>\n<p>This is my page.</p>\n</body>\n</html>\n";
  beautify_html(html_str);
  return 0;
}