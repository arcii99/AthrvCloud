//FormAI DATASET v1.0 Category: HTML beautifier ; Style: curious
#include <stdio.h>
#define MAXSIZE 1000000

int main() {
   char input[MAXSIZE], output[MAXSIZE];
   int i, j, indent = 0;

   printf("Enter HTML code:\n");

   while((input[i] = getchar()) != EOF) {
      if (input[i] == '<') {
         if (input[i+1] == '/') {
            indent -= 2;
         }
         for (j = 0; j < indent; j++) {
            output[i+j] = ' ';
         } 
         indent += 2;
      }
      output[i] = input[i];
      i++;
   }

   output[i] = '\0';

   printf("\nBeautified HTML code:\n%s\n", output);

   return 0;
}