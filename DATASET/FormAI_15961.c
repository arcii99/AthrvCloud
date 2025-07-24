//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: curious
#include <stdio.h>
#include <string.h>

/* Check if a string is Palindrome */
int isPalindrome(char str[]) {
   int len = strlen(str);
   for (int i = 0; i < len/2; i++) {
      if (str[i] != str[len-i-1]) {
         return 0;
      }
   }
   return 1;
}

/* Main function */
int main() {

   /* Greet the user */
   printf("Hello, I am a Palindrome Checker!\n");
   printf("Please enter a string (max 100 characters): ");

   /* Read the input string from the user */
   char str[100];
   fgets(str, 100, stdin);
   str[strcspn(str, "\n")] = 0; // Remove the newline character from the input string

   /* Check if the string is a Palindrome and give feedback to the user */
   if (isPalindrome(str)) {
      printf("Congratulations! \"%s\" is a Palindrome.\n", str);
   } else {
      printf("Sorry, \"%s\" is not a Palindrome.\n", str);
   }

   /* Say goodbye to the user */
   printf("Thanks for using Palindrome Checker. Goodbye!\n");

   return 0;
}