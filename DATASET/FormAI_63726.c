//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

int main() {
   char word[MAX_WORD_LENGTH];
   int c;
   int word_count = 0;
   int in_word = 0;

   while ((c = getchar()) != EOF) {
       if (isalpha(c)) {
           if (!in_word) {
               in_word = 1;
               ++word_count;
           }
           if (MAX_WORD_LENGTH > strlen(word)) {
               word[strlen(word)] = c;
           }
       } else {
           in_word = 0;
           word[0] = '\0';
       }
   }

   printf("Word count: %d\n", word_count);
   return 0;
}