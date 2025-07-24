//FormAI DATASET v1.0 Category: HTML beautifier ; Style: thoughtful
#include <stdio.h>

// function to check if a character is a space or not
int is_space(char c) {
  if (c == ' ' || c == '\n' || c == '\t') {
    return 1;
  }
  return 0;
}

// function to beautify HTML code
void beautify_html(char* code) {
  int space_count = 0;
  int indent_level = 0;
  int inside_tag = 0;
  char current_char = ' ';
  
  while (*code) {
    current_char = *code;
    
    // check if we are inside a tag
    if (inside_tag == 0 && current_char == '<') {
      inside_tag = 1;
      printf("%c", current_char);
      continue;
    }
    
    // check if we are outside a tag
    if (inside_tag == 1 && current_char == '>') {
      inside_tag = 0;
      printf("%c", current_char);
      if (*(code - 1) != '/') {
        indent_level++;
        printf("\n");
        for (int i = 0; i < indent_level; i++) {
          printf("  ");
        }
      }
      continue;
    }
    
    // check if we are inside a space
    if (inside_tag == 1 && is_space(current_char) && *(code - 1) != '>' && *(code + 1) != '<') {
      space_count++;
      continue;
    }
    
    // if there are spaces, print them out until we reach a non-space character
    if (space_count > 0) {
      printf("%c", ' ');
      space_count--;
    }
    
    // print out the current character
    printf("%c", current_char);
  }
}

int main() {
  char* code = "<html><head><title>My Title</title></head><body><h1>Welcome to my website!</h1><p>This is some text.</p></body></html>";
  
  beautify_html(code);
  
  return 0;
}