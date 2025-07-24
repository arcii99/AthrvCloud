//FormAI DATASET v1.0 Category: Syntax parsing ; Style: imaginative
#include <stdio.h>

int main() {

   char input[100];
   printf("Enter a program in C syntax:\n");
   fgets(input, 100, stdin);
   printf("Parsing program...\n");

   int brackets = 0;
   int parentheses = 0;
   int quotes = 0;
   int single_quotes = 0;
   int comments = 0;

   for(int i = 0; input[i] != '\0'; i++) {

      if(input[i] == '{') {
         brackets++;
         printf("Opening bracket found at position %d\n", i);
      }
      else if(input[i] == '}') {
         brackets--;
         printf("Closing bracket found at position %d\n", i);
      }
      else if(input[i] == '(') {
         parentheses++;
         printf("Opening parentheses found at position %d\n", i);
      }
      else if(input[i] == ')') {
         parentheses--;
         printf("Closing parentheses found at position %d\n", i);
      }
      else if(input[i] == '"' && single_quotes == 0) {
         if(quotes == 0) {
            quotes++;
            printf("Opening double quotes found at position %d\n", i);
         }
         else {
            quotes--;
            printf("Closing double quotes found at position %d\n", i);
         }
      }
      else if(input[i] == '\'' && quotes == 0) {
         if(single_quotes == 0) {
            single_quotes++;
            printf("Opening single quotes found at position %d\n", i);
         }
         else {
            single_quotes--;
            printf("Closing single quotes found at position %d\n", i);
         }
      }
      else if(input[i] == '/' && input[i+1] == '/') {
         comments++;
         printf("Single-line comment found at position %d\n", i);
      }
      else if(input[i] == '/' && input[i+1] == '*') {
         comments++;
         printf("Multi-line comment found at position %d\n", i);
      }
      else if(input[i] == '*' && input[i+1] == '/') {
         comments--;
         printf("End of multi-line comment found at position %d\n", i+1);
      }

   }

   if(brackets == 0 && parentheses == 0 && quotes == 0 && single_quotes == 0 && comments == 0) {
      printf("Program successfully parsed!\n");
   }
   else {
      printf("Error: Program syntax is not correct.\n");
   }

   return 0;
}