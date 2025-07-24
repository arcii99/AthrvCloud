//FormAI DATASET v1.0 Category: Word Count Tool ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char sentence[1000], word[100];
   int count = 0, i;

   printf("Enter a sentence: ");
   gets(sentence); //Reads input from user

   printf("Enter a word to count: ");
   gets(word); //Reads input from user

   for (i = 0; sentence[i] != '\0'; i++) {
      if (sentence[i] == word[0]) { //Checking first letter of word
         if (strstr(&sentence[i], word) == &sentence[i]) { //checking if entire word is present
            count++; //increment count if word is found
         }
      }
   }

   printf("\nWord count: %d", count); //display final count

   return 0;
}