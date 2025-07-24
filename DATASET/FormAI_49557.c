//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

void countWords(char *text) {
   int count = 0;
   char delim[] = " ,.!?:;";
   char *word;

   printf("\nText: %s\n\nWord Count:\n", text);

   // Count words
   word = strtok(text, delim);
   while (word != NULL) {
      count++;
      printf("'%s'\n", word);
      word = strtok(NULL, delim);
   }
   printf("\nTotal words: %d\n", count);
}

int main() {
   char text[1000];

   printf("Enter text (Max 1000 characters):\n");
   fgets(text, sizeof(text), stdin);
   countWords(text);

   return 0;
}