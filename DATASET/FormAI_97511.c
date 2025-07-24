//FormAI DATASET v1.0 Category: Word Count Tool ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
   int character, new_word = 1, word_count = 0, char_count = 0;
   
   printf("Please enter your text:\n");

   while((character = getchar()) != EOF) {
      if(isspace(character) && !new_word) {
         new_word = 1; 
         word_count++;
      }
      else if(!isspace(character)) {
         new_word = 0;
         char_count++;
      }
   }
   printf("Word count: %d\n", word_count);
   printf("Character count: %d\n", char_count);
   
   return 0;
}