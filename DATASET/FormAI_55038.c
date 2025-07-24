//FormAI DATASET v1.0 Category: HTML beautifier ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// function to check if the current character is a space character
int isSpaceChar(char c) {
   if (c == ' ' || c == '\t' || c == '\n') {
      return 1;
   }
   return 0;
}

// function to print each indented line of the HTML string
void printLine(char *line, int indent) {
   int i;
   for (i = 0; i < indent; i++) {
      putchar(' ');
   }
   printf("%s\n", line);
}

// function to beautify the HTML string
void beautifyHTML(char *htmlStr) {
   int indent = 0;
   char *cursor = htmlStr;
   char *lineStart = htmlStr;

   while (*cursor != '\0') {
      if (*cursor == '<') {
         // print the current line and indent next line if current line
         // is not empty
         if (cursor > lineStart) {
            printLine(lineStart, indent);
         }

         // increase indent if current tag is opening tag
         if (*(cursor + 1) != '/') {
            indent += 2;
         }
         lineStart = cursor;
      } else if (*cursor == '>') {
         // decrease indent if current tag is closing tag
         if (*(cursor - 1) == '/') {
            printLine(lineStart, indent);
         } else {
            indent -= 2;
            printLine(lineStart, indent);
         }
         lineStart = cursor + 1;
      }
      cursor++;
   }

   // print the last line
   printLine(lineStart, indent);
}

int main() {
   // sample HTML string to beautify
   char *htmlStr = "<html><head><title>Sample Page</title></head><body><h1>Welcome to my page</h1><p>This is a sample paragraph.</p></body></html>";

   // beautify the HTML string and print it
   beautifyHTML(htmlStr);

   return 0;
}