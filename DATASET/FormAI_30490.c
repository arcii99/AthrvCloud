//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: surrealist
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 1000

// Function to check for palindromes and return either "yes" or "no"
char* palindromeChecker(char word[]) {
   int i, len = strlen(word);
   for (i = 0; i < len/2; i++) {
      if (word[i] != word[len-i-1])
         return "no";
   }
   return "yes";
}

int main() {
   char word[MAX_LENGTH];
   printf("Hello! I am a surrealist palindrome checker.\n\n");
   printf("Enter a word or phrase (up to 1000 characters):\n");
   fgets(word, MAX_LENGTH, stdin); // get user input
   // check if the input word or phrase is a palindrome
   char* result = palindromeChecker(word);
   if (strcmp(result, "yes") == 0) {
      printf("\nYou have entered a palindrome!\n");
      printf("The word or phrase is: %s\n", word);
      printf("\nYou have unlocked the secrets of the universe!\n");
      printf("You are now granted access to the portal of limitless possibilities!\n");
   } else {
      printf("\nSorry, that is not a palindrome.\n");
      printf("The word or phrase is: %s\n", word);
      printf("\nYou have been cast into the void of obscurity.\n");
      printf("You may try again, but you will never achieve transcendence.\n");
   }
   return 0;
}