//FormAI DATASET v1.0 Category: Word Count Tool ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char sentence[1000];
   int wordCount = 0;

   printf("Enter a sentence: ");
   fgets(sentence, 1000, stdin); // read the entire sentence including spaces
   printf("Sentence: %s", sentence);

   for(int i = 0; i < strlen(sentence); i++) {
      if(sentence[i] == ' ' || sentence[i] == '\n') { // check for space or newline
         wordCount++; // increment word count
      }
   }

   printf("Word Count: %d", wordCount);

   return 0;
}