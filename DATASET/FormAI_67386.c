//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

int main() {

   char sentence[1000];
   int wordCount = 1;
   int i;

   printf("Welcome to the C Word Count Tool!\n");
   printf("Please enter a sentence: \n");
   
   fgets(sentence, 1000, stdin);

   for (i = 0; i < strlen(sentence); i++) {
      if (sentence[i] == ' ' || sentence[i] == '\n' || sentence[i] == '\t') {
         wordCount++;
      }
   }

   printf("The number of words in your sentence is: %d\n", wordCount);

   return 0;
}