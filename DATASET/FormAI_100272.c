//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: calm
#include <stdio.h>
#include <string.h>

void check_palindrome(char str[]);

int main() {
   char str[100];

   printf("Enter the string: ");
   scanf("%s", str);

   check_palindrome(str);

   return 0;
}

void check_palindrome(char str[]) {
   int i = 0, j = strlen(str) - 1;

   while (j > i) {
      if (str[i++] != str[j--]) {
         printf("%s is not a palindrome\n", str);
         return;
      }
   }
   printf("%s is a palindrome\n", str);
}