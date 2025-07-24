//FormAI DATASET v1.0 Category: HTML beautifier ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the HTML Beautifier program!\n");
  printf("Enter your HTML code for beautification:\n");

  // Read in the user input
  char code[10000]; // assuming max code length of 10,000 characters
  fgets(code, 10000, stdin);

  // Loop through each character in the code string
  int i, indent = 0;
  for (i = 0; code[i] != '\0'; ++i) {
    if (code[i] == '<') {
      printf("\n"); // start a new line before the tag
      // Add indentation spaces based on depth of tag nesting
      for (int j = 0; j < indent; j++) {
        printf("  ");
      }
      indent++; // increase the indentation for nested tags
    }
    putchar(code[i]); // print the current character
    if (code[i] == '>') {
      indent--; // decrease the indentation when the tag ends
    }
  }

  printf("\n\nBeautification complete! Did you feel that? I just made your HTML code beautiful! :O\n");
  return 0;
}