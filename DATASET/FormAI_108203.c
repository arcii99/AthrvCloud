//FormAI DATASET v1.0 Category: HTML beautifier ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *html = "<!DOCTYPE html><html><head><title>My Website</title></head><body><h1>Welcome to my website!</h1><p>Here you will find all kinds of interesting things.</p></body></html>";
  int indent_size = 2;
  int i, j, k, n = strlen(html);
  char current_char;
  
  // Loop through the HTML string
  for (i = 0; i < n; i++) {
    current_char = html[i];
    
    // If we find the opening angle bracket of a tag
    if (current_char == '<') {
      // Print the tag up to the closing angle bracket
      while (html[i] != '>') {
        printf("%c", html[i]);
        i++;
      }
      printf("%c", html[i]);

      // If the tag is not self-closing, add a newline and indent the content
      if (html[i-1] != '/') {
        printf("\n");
        for (k = 0; k < indent_size; k++) {
          printf(" ");
        }
      }
    } else {
      // Print the current character
      printf("%c", current_char);
      
      // If we find a closing angle bracket, add a newline and indent the next line
      if (current_char == '>') {
        printf("\n");
        for (j = 0; j < indent_size; j++) {
          printf(" ");
        }
      }
    }
  }
  
  return 0;
}