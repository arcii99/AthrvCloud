//FormAI DATASET v1.0 Category: HTML beautifier ; Style: high level of detail
#include <stdio.h>
#include <string.h>

void beautifyHTML(char html[]) {

   int i;
   int j = 0;
   int k = 0;
   int spaces = 0;
   int num_tabs = 0;
   int new_line_flag = 0;
   int bracket_flag = 0;

   for (i = 0; i < strlen(html); i++) {

      // Count number of spaces
      if (html[i] == ' ') {
         spaces++;
         k++;
      }
      
      // Count number of tabs
      else if (html[i] == '\t') {
         num_tabs++;
         k++;
      }
      
      // Add newline character after bracket and indent next line
      else if (html[i] == '<') {
         new_line_flag = 1;
         bracket_flag = 1;
         spaces = 0;
         k++;
      }
      
      // Add newline character before bracket and indent current line
      else if (html[i] == '>') {
         new_line_flag = 1;
         bracket_flag = 0;
         spaces = 0;
         k--;
      }
      
      // Add text to buffer if not inside brackets
      if (!bracket_flag) {
         putchar(html[i]);
         j++;
      }
      
      // Add newline character and indent after tag
      if (new_line_flag) {
         putchar('\n');
         for (int l = 0; l < num_tabs; l++) {
            printf("\t");
            j++;
         }
         new_line_flag = 0;
         num_tabs = k;
         for (int l = 0; l < spaces; l++) {
            printf(" ");
            j++;
         }
      }
   }

   printf("\n");

   return;
}

int main(int argc, char *argv[]) {
   char html[] = "<html><head><title>Sample Page</title><body><h1>Welcome!</h1><p>This is a sample page.</p></body></html>";
   
   beautifyHTML(html);

   return 0;
}