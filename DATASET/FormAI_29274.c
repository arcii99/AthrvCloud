//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

int main () {
   char input_str[100];
   int i, j, len;
   int is_palindrome = 1;

   printf("Enter a string: ");
   scanf("%s", input_str);

   len = strlen(input_str);
    
   for (i = 0, j = len - 1; i < len / 2; i++, j--) {
      if (input_str[i] != input_str[j]) {
         is_palindrome = 0;
         break;
      }
   }

   if (is_palindrome) {
      printf("'%s' is a palindrome", input_str);
   } else {
      printf("'%s' is not a palindrome", input_str);
   }

   return 0;
}