//FormAI DATASET v1.0 Category: Syntax parsing ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

   // Initialize variables
   char input[100];
   char keyword[] = "if";
   char statement[100];
   int i, j;

   // Get input from user
   printf("Enter a C statement:\n");
   fgets(input, 100, stdin);

   // Check if input contains the keyword "if"
   for (i = 0; i < strlen(input); i++) {
      if (input[i] == 'i' && input[i+1] == 'f' && (input[i+2] == ' ' || input[i+2] == '(')) {
         printf("The input contains the keyword 'if'\n");
         break;
      }
   }

   // Extract the statement after the keyword "if"
   for (j = i+2; j < strlen(input); j++) {
      if (input[j] == '{') {
         break;
      }
      statement[j-i-2] = input[j];
   }

   // Print the extracted statement
   printf("The statement after 'if' is: %s\n", statement);

   return 0;
}