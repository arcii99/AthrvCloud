//FormAI DATASET v1.0 Category: Syntax parsing ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
   char input[100];
   printf("Type in your code: ");
   fgets(input, 100, stdin);

   // parsing variables
   int i = 0;
   char curr;

   while (input[i] != '\0') {
      curr = input[i];

      // variables can only start with letters
      if (isalpha(curr)) {
         printf("Variable found: ");
         while (isalnum(curr)) {
            printf("%c", curr);
            i++;
            curr = input[i];
         }
         printf("\n");
      }

      // integer literals
      else if (isdigit(curr)) {
         printf("Integer found: ");
         while (isdigit(curr)) {
            printf("%c", curr);
            i++;
            curr = input[i];
         }
         printf("\n");
      }

      // operator handling
      else if (curr == '+' || curr == '-' || curr == '*' || curr == '/' || curr == '=') {
         printf("Operator found: %c\n", curr);
         i++;
      }

      // ignore all other characters
      else {
         i++;
      }
   }

   return 0;
}