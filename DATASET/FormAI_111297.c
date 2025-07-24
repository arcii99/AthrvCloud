//FormAI DATASET v1.0 Category: HTML beautifier ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

void beautify(char* html) {
  int len = strlen(html);
  int depth = 0;
  int i = 0;
  while(i < len) {
    if(html[i] == '<') {
      if(html[i+1] == '/') {
        depth--;
      }
      for(int j = 0; j < depth; j++) {
        printf("  ");
      }
      printf("%c", html[i]);
      depth++;
    } else if(html[i] == '>') {
      printf("%c\n", html[i]);
      depth--;
    } else {
      printf("%c", html[i]);
    }
    i++;
  }
}

int main() {
  char* html = "<html><head><title>Welcome to My Website</title></head><body><h1>This is my website!</h1><p>Thanks for visiting. Here, you will find all sorts of information about me and my interests.</p></body></html>";
  beautify(html);
  return 0;
}