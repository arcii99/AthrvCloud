//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: curious
#include <stdio.h>
#include <string.h>

// function to check if a string is palindrome or not
int isPalindrome(char str[]) {
   int len = strlen(str);
   int i, j;

   // Start from both ends of the string and compare each character until midpoint is reached
   for(i = 0, j = len - 1; i <= j; i++, j--) {
      if(str[i] != str[j])
         return 0;
   }

   return 1;
}

int main() {
   char str[100];

   printf("Hello there! I am a palindrome checker.\n");
   printf("Enter a string to check if it is a palindrome (case sensitive): ");
   scanf("%s", str);

   // call the isPalindrome function and print the result
   if(isPalindrome(str))
      printf("%s is a palindrome!\n", str);
   else
      printf("%s is NOT a palindrome.\n", str);

   printf("Thanks for using me!\n");

   return 0;
}