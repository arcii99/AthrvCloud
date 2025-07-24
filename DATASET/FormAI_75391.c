//FormAI DATASET v1.0 Category: Word Count Tool ; Style: light-weight
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 1000

int main() {

   char string[MAX_LENGTH], search[MAX_LENGTH];
   int count = 0, i, j, flag;

   // ask user for input string
   printf("Enter a string: ");
   fgets(string, MAX_LENGTH, stdin);

   // removing newline character from string
   string[strcspn(string, "\n")] = 0;

   // ask user for search word
   printf("Enter a word to count: ");
   fgets(search, MAX_LENGTH, stdin);

   // removing newline character from search word
   search[strcspn(search, "\n")] = 0;

   // check if input string and search word is not empty
   if(strlen(string) > 0 && strlen(search) > 0) {

      // loop through each character in string
      for(i = 0; i < strlen(string); i++) {

         flag = 1;

         // check if search word matches with current character
         for(j = 0; j < strlen(search); j++) {
            if(string[i+j] != search[j]) {
               flag = 0;
               break;
            }
         }

         // increment count if search word matches with current character
         if(flag == 1) {
            count++;
         }
      }

      // display result
      printf("The word '%s' appears %d times in the entered string.", search, count);

   } else {
      printf("Input string and search word should not be empty.");
   }

   return 0;
}