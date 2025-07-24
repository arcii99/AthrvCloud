//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Ken Thompson
#include <stdio.h>

/*This is a program that beautifies the HTML code*/

int main() {
  int c;
  int indent = 0; //Number of spaces to indent
  
  while ((c = getchar()) != EOF) {
    if (c == '<') {
      putchar(c);
      c = getchar();
      
      if (c == '/') { //Closing tag - reduce the indent
        indent -= 2;
        for (int i = 0; i < indent; i++) { //Print the indent spaces
          putchar(' ');
        }
        putchar('/');
        putchar(getchar());
      }
      else if (c == '!') { //Comment - print as is
        for (int i = 0; i < 2; i++) { 
          putchar('<');
          putchar(c);
          c = getchar();
        }
        putchar(c);
        while (c != '>') { //Print the comment content
          c = getchar();
          putchar(c);
        }
      }
      else { //Opening tag - increase the indent
        for (int i = 0; i < indent; i++) { //Print the indent spaces
          putchar(' ');
        }
        putchar('<');
        putchar(c);
        indent += 2; //Increase the indent
        putchar(getchar());
      }
    }
    else { //Not an HTML tag - print as is
      putchar(c);
    }
  }
  return 0;
}