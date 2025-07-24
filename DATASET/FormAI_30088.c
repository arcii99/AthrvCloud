//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Ken Thompson
#include <stdio.h>

int main() {
   char html[1000], c;
   int i = 0;
   int tab = 0;
   
   printf("Enter HTML code to beautify:\n");
   
   // Read input HTML
   while ((c = getchar()) != EOF) {
      html[i++] = c;
   }
   
   html[i] = '\0';

   // Beautify HTML
   for (i = 0; html[i] != '\0'; i++) {
      if (html[i] == '<') {
         // Increase tab
         printf("\n");
         for (int j = 1; j <= tab; j++) {
            printf("    ");
         }
         putchar(html[i]);
         
         if (html[i + 1] == '/') {
            // Decrease tab
            tab--;
            i++;
            for (int j = 1; j <= tab; j++) {
               printf("    ");
            }
         }
         else {
            // Increase tab
            tab++;
         }
      }
      else if (html[i] == '>') {
         putchar(html[i]);
         printf("\n");
      }
      else {
         putchar(html[i]);
      }
   }

   return 0;
}