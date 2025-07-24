//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: surrealist
#include <stdio.h>
#include <string.h>

// Function to check if a string is a palindrome
int isPalindrome(char *str) {
   int left = 0;
   int right = strlen(str) - 1;

   while (right > left) {
      if (str[left++] != str[right--]) {
         return 0;
      }
   }
   return 1;
}

// Main function to run the program
int main() {
   char str[100];

   printf("Welcome to the surreal palindrome checker!\n");
   printf("Please enter your word(s): ");
   scanf("%[^\n]s", str);

   if (isPalindrome(str)) {
      printf("Congrats, your word is a surreal palindrome. It can be read forwards and backwards the exact same way!\n");
   } else {
      printf("Hmm, your word does not seem to be a surreal palindrome. Give it another go!\n");
   }
   return 0;
}