//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Ken Thompson
#include <stdio.h>
#include <ctype.h>

int main() {
   char c;
   int parentheses = 0, brackets = 0, braces = 0;

   while ((c = getchar()) != EOF) {
      if (c == '(') {
         parentheses++;
      } else if (c == ')') {
         parentheses--;
      } else if (c == '[') {
         brackets++;
      } else if (c == ']') {
         brackets--;
      } else if (c == '{') {
         braces++;
      } else if (c == '}') {
         braces--;
      }

      if (parentheses < 0) {
         printf("Unmatched )\n");
      }

      if (brackets < 0) {
         printf("Unmatched ]\n");
      }

      if (braces < 0) {
         printf("Unmatched }\n");
      }
   }

   if (parentheses > 0) {
      printf("Unmatched (\n");
   }

   if (brackets > 0) {
      printf("Unmatched [\n");
   }

   if (braces > 0) {
      printf("Unmatched {\n");
   }

   return 0;
}