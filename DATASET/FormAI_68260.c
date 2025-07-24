//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

int main() {
   char word[100];
   char reverseWord[100];
   int length = 0;
   int i, j;
   
   printf("Enter a word to check if it is a palindrome: ");
   scanf("%s", word);
   
   length = strlen(word);
   
   // Reverse the word
   for(i = length - 1, j = 0; i >= 0; i--, j++) {
      reverseWord[j] = word[i];
   }
   
   // Check if the word is a palindrome
   for(i = 0; i < length; i++) {
      if(word[i] != reverseWord[i]) {
         printf("\n%s is not a palindrome\n", word);
         return 1; // Exit the program
      }
   }
   
   printf("\n%s is a palindrome\n", word);
   return 0; // Exit the program
}