//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: happy
#include <stdio.h>
#include <string.h>

//Function to check if a string is a palindrome
int isPalindrome(char str[]) {
   int len = strlen(str);
   for(int i = 0; i < len/2; i++) {
      if(str[i] != str[len-1-i]) {
         return 0; //return 0 if not a palindrome
      }
   }
   return 1; //return 1 if string is a palindrome
}

int main() {
   char word[100]; //define a char array to store input word
   printf("\nWelcome to the Palindrome Checker! Let's check if your word is a palindrome.\n");
   printf("Please enter a word: ");
   scanf("%s", word); //read word from user input
   if(isPalindrome(word)) { //check if input word is a palindrome
      printf("\nCongratulations! %s is a palindrome!\n", word);
   } else {
      printf("\nSorry, %s is not a palindrome. Please try again.\n", word);
   }
   return 0;
}