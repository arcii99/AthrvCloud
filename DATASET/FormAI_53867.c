//FormAI DATASET v1.0 Category: HTML beautifier ; Style: mind-bending
#include <stdio.h>

int main() {
  char html[250]="<li><a href='#'>Home</a></li><li><a href='#'>About</a></li><li><a href='#'>Contact</a></li>";
  int indent = 0, new_line = 1;
  
  printf("Formatted HTML:\n\n");
  for (int i = 0; html[i] != '\0'; i++) {
    if (new_line) {
      for (int j = 0; j < indent; j++) {
        printf("  ");
      }
      new_line = 0;
    }
    printf("%c", html[i]);
    if (html[i] == '<') {
      new_line = 1;
      if (html[i+1] == '/') {
        indent -= 1;
      } else {
        indent += 1;
      }
    }
    if (html[i] == '>') {
      if (html[i-1] != '/') {
        printf("\n");
        new_line = 1;
      }
    }
  }
  
  return 0;
}