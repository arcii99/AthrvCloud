//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: synchronous
#include <stdio.h>
#include <string.h>

int isPalindrome(char str[]) {
   int i, j;
   int n = strlen(str);

   for (i = 0, j = n - 1; i < n / 2; i++, j--) {
      if (str[i] != str[j])
         return 0;
   }

   return 1;
}

int main() {
   char str[100];

   printf("Enter a string: ");
   scanf("%s", str);

   if (isPalindrome(str)) {
      printf("%s is a palindrome", str);
   } else {
      printf("%s is not a palindrome", str);
   }

   return 0;
}