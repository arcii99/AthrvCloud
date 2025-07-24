//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: peaceful
#include<stdio.h>
#include<string.h>

void check_palindrome(char str[]) {
   int i = 0, j = strlen(str) - 1;

   while (j > i) {
      if (str[i++] != str[j--]) {
         printf("The given string is not a palindrome.\n");
         return;
      }
   }

   printf("The given string is a palindrome.\n");
}

int main() {
   char str[100];

   printf("Enter a string: ");
   fgets(str, 100, stdin);

   // Replace the newline character with a null character to remove it from the string.
   str[strcspn(str, "\n")] = '\0';

   check_palindrome(str);

   return 0;
}