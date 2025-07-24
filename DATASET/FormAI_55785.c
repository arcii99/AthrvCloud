//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: synchronous
#include <stdio.h>
#include <string.h>

int main() {
   char string[100];
   int length, mid, i, j, flag = 0;

   printf("Enter a string: ");
   scanf("%s", string);

   length = strlen(string);

   mid = length / 2;

   for (i = 0, j = length - 1; i < mid; i++, j--) {
      if (string[i] != string[j]) {
         flag = 1;
         break;
      }
   }

   if (flag == 1) {
      printf("%s is not a palindrome", string);
   } else {
      printf("%s is a palindrome", string);
   }

   return 0;
}