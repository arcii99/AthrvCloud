//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Dennis Ritchie
#include <stdio.h>

int main() {
   char input[1000];

   printf("Enter C Syntax code: ");
   fgets(input, 1000, stdin);

   int i, open_bracket = 0, close_bracket = 0;
   char last_char = '\0';

   for(i = 0; input[i] != '\0'; i++) {
      if(input[i] == '{') {
         open_bracket++;
         last_char = '{';
      }
      else if(input[i] == '}') {
         close_bracket++;
         last_char = '}';
      }
   }

   if(open_bracket != close_bracket) {
      printf("Syntax Error: Uneven number of opening and closing brackets.\n");
      if(open_bracket > close_bracket)
         printf("Missing a closing bracket '%c'.\n", last_char);
      else
         printf("Unexpected closing bracket '%c'.\n", last_char);
   }
   else {
      printf("Syntax is correct.\n");
   }

   return 0;
}