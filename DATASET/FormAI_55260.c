//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: grateful
#include <stdio.h>
#include <string.h>

int main() {

   char word[100];
   int length = 0, flag = 0;

   // Greeting the user
   printf("Hello! Welcome to the Palindrome Checker.\n");

   // Asking the user for input
   printf("Please enter a word you would like to check: ");
   scanf("%s", word);

   length = strlen(word);

   // Checking if word is palindrome
   for(int i=0; i<length; i++){
      if(word[i] != word[length-i-1]){
         flag = 1;
         break;
      }
   }

   // Printing result
   if(flag) {
      printf("\nSorry, %s is not a palindrome.\n", word);
   }    
   else {
      printf("\nCongratulations! %s is a palindrome!\n", word);
   }

   // Saying thank you to the user and ending program
   printf("\nThank you for using the Palindrome Checker.\n");
   return 0;
}