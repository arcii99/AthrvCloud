//FormAI DATASET v1.0 Category: Syntax parsing ; Style: shocked
#include <stdio.h>

int main() {
   char input[1000];
   int openingBrackets = 0, closingBrackets = 0, openingBraces = 0, closingBraces = 0, openingParentheses = 0, closingParentheses = 0;
   printf("Enter a C program:\n");
   fgets(input, 1000, stdin);

   for (int i = 0; input[i] != '\0'; i++) {
      if (input[i] == '{') {
         openingBraces++;
      } else if (input[i] == '}') {
         closingBraces++;
      } else if (input[i] == '(') {
         openingParentheses++;
      } else if (input[i] == ')') {
         closingParentheses++;
      } else if (input[i] == '[') {
         openingBrackets++;
      } else if (input[i] == ']') {
         closingBrackets++;
      } 
   }

   if (openingBraces != closingBraces) {
      printf("Error: Unequal number of opening and closing braces.");
   }

   if (openingParentheses != closingParentheses) {
      printf("Error: Unequal number of opening and closing parentheses.");
   }

   if (openingBrackets != closingBrackets) {
      printf("Error: Unequal number of opening and closing brackets.");
   }

   return 0;
}